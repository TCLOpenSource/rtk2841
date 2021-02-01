/*
 * User-space helper to sort the output of /sys/kernel/debug/page_owner
 *
 * Example use:
 * cat /sys/kernel/debug/page_owner > page_owner_full.txt
 * ./page_owner_parser page_owner_full.txt sorted_page_owner.txt 1 -s
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define TOKEN_ZONE_LENGTH 8
#define TOKEN_MT_LENGTH 4
#define TOKEN_TASK_LENGTH 16
#define TOKEN_LENGTH 16
#define TOKEN_NUMBER 16

/*
Page size 8192, mask 0x8, type [C], zone Normal, pid 1, swapper/0
*/
enum {
	TOKEN_INDEX_SIZE = 1,
	TOKEN_INDEX_SIZE_VALUE,
	TOKEN_INDEX_MASK,
	TOKEN_INDEX_MASK_VALUE,
	TOKEN_INDEX_TYPE,
	TOKEN_INDEX_TYPE_VALUE,
	TOKEN_INDEX_ZONE,
	TOKEN_INDEX_ZONE_VALUE,
	TOKEN_INDEX_PID,
	TOKEN_INDEX_PID_VALUE,
	TOKEN_INDEX_TASK_NAME,
	TOKEN_INDEX
};

static int list_mode;

/*
 * List Mode.
 */
typedef enum Mode {
	kModeSummary = 1,
	kModeDetails
} Mode;

/*
 * Options we can Sort.
 */
typedef enum Option {
	kOptionSortByPageSize = 0,
	kOptionSortByAllocTimes,
	kOptionSortByMigrateType,
	kOptionSortByPID,
	kOptionSortByMemoryAmount,
	kOptionSummarySortByPID
} Option;

struct block_list {
	char *txt;
	int is_CMA;
	int is_Slab;
	int is_SwapCache;
	char zone[TOKEN_ZONE_LENGTH];
	unsigned int page_size;
	char migrate_type[TOKEN_MT_LENGTH];
	unsigned int pid;
	char task_name[TOKEN_TASK_LENGTH];
	int len;
	int num;
};

struct pid_memory_usage_list {
	unsigned int pid;
	unsigned int total_memory;
	int count;
	int list2_index;
};

static struct block_list *list;
static int list_size;
static int max_size;

struct block_list *block_head;

int read_block(char *buf, int buf_size, FILE *fin)
{
	char *curr = buf, *const buf_end = buf + buf_size;

	while (buf_end - curr > 1 && fgets(curr, buf_end - curr, fin)) {
		if (*curr == '\n') /* empty line */
			return curr - buf;
		curr += strlen(curr);
	}

	return -1; /* EOF or no space left in buf. */
}

static void removeChar(char *str, char garbage)
{
	char *src, *dst;
	for (src = dst= str; *src != '\0'; src++) {
		*dst = *src;
		if (*dst != garbage) dst++;
	}
	*dst = '\0';
}

static int compare_txt_by_size(const void *p1, const void *p2)
{
	const struct block_list *l1 = p1, *l2 = p2;
	int cmp;
	int ret;

	cmp = (l1->is_CMA) - (l2->is_CMA);
	if (cmp == 0) {
		cmp = (l1->is_Slab) - (l2->is_Slab);
		if (cmp == 0) {
			cmp = strcmp(l2->zone, l1->zone);
			if (cmp == 0) {
				cmp = (l2->page_size) - (l1->page_size); //compare Page Size
				if (cmp == 0) {
					cmp = strcmp((char*)l2->migrate_type, (char*)l1->migrate_type); // then compare Migrate Type
					if ((cmp == 0) && (list_mode == kModeDetails)) {
						cmp = (l1->pid) - (l2->pid); // last compare PID
					}
				}
			}
		}
	}

	if (cmp == 0) {
		ret = 0;
	} else if (cmp > 0){
		ret = 1;
	} else {
		ret = -1;
	}

	return ret;
}

static int compare_txt_by_mt(const void *p1, const void *p2)
{
	const struct block_list *l1 = p1, *l2 = p2;
	int cmp;
	int ret;

	cmp = (l1->is_CMA) - (l2->is_CMA);
	if (cmp == 0) {
		cmp = (l1->is_Slab) - (l2->is_Slab);
		if (cmp == 0) {
			cmp = strcmp(l2->zone, l1->zone);
			if (cmp == 0) {
				cmp = strcmp((char*)l2->migrate_type, (char*)l1->migrate_type); // compare Migrate Type
				if (cmp == 0) {
					cmp = (l2->page_size) - (l1->page_size); //then compare Page Size
					if ((cmp == 0) && (list_mode == kModeDetails)) {
						cmp = (l1->pid) - (l2->pid); // last compare PID
					}
				}
			}
		}
	}

	if (cmp == 0) {
		ret = 0;
	} else if (cmp > 0){
		ret = 1;
	} else {
		ret = -1;
	}

	return ret;
}

static int compare_txt_by_pid(const void *p1, const void *p2)
{
	const struct block_list *l1 = p1, *l2 = p2;
	int cmp;
	int ret;

	cmp = (l1->pid) - (l2->pid); // compare PID
	if (cmp == 0) {
		cmp = (l1->is_CMA) - (l2->is_CMA);
		if (cmp == 0) {
			cmp = (l1->is_Slab) - (l2->is_Slab);
			if (cmp == 0) {
				cmp = strcmp(l2->zone, l1->zone);
				if (cmp == 0) {
					cmp = (l2->page_size) - (l1->page_size);
					if (cmp == 0) {
						cmp = strcmp((char*)l2->migrate_type, (char*)l1->migrate_type);
					}
				}
			}
		}
	}

	if (cmp == 0) {
		ret = 0;
	} else if (cmp > 0){
		ret = 1;
	} else {
		ret = -1;
	}

	return ret;
}

static int compare_num_by_times(const void *p1, const void *p2)
{
	const struct block_list *l1 = p1, *l2 = p2;
	int cmp;
	int ret;

	cmp = (l1->is_CMA) - (l2->is_CMA);
	if (cmp == 0) {
		cmp = (l1->is_Slab) - (l2->is_Slab);
		if (cmp == 0) {
			cmp = strcmp(l2->zone, l1->zone);
			if (cmp == 0) {
				cmp = (l2->num) - (l1->num); // compare alloc times
			}
		}
	}

	if (cmp == 0) {
		ret = 0;
	} else if (cmp > 0){
		ret = 1;
	} else {
		ret = -1;
	}

	return ret;

}

static int compare_num_by_amount(const void *p1, const void *p2)
{
	const struct block_list *l1 = p1, *l2 = p2;
	int cmp;
	int ret;

	cmp = (l1->is_CMA) - (l2->is_CMA);
	if (cmp == 0) {
		cmp = (l1->is_Slab) - (l2->is_Slab);
		if (cmp == 0) {
			cmp = strcmp(l2->zone, l1->zone);
			if (cmp == 0) {
				cmp = (l2->num * l2->page_size) - (l1->num * l1->page_size); // compare memory amount
			}
		}
	}

	if (cmp == 0) {
		ret = 0;
	} else if (cmp > 0){
		ret = 1;
	} else {
		ret = -1;
	}

	return ret;

}

static int compare_num_by_pid(const void *p1, const void *p2)
{
	const struct block_list *l1 = p1, *l2 = p2;
	int cmp;
	int ret;

	cmp = (l1->pid) - (l2->pid); // compare PID
	if (cmp == 0) {
		cmp = (l1->is_CMA) - (l2->is_CMA); // compare is CMA or not
		if (cmp == 0) {
			cmp = (l2->num * l2->page_size) - (l1->num * l1->page_size); // compare memory amount
		}
	}

	if (cmp == 0) {
		ret = 0;
	} else if (cmp > 0){
		ret = 1;
	} else {
		ret = -1;
	}

	return ret;
}

static int compare_sum_by_pid(const void *p1, const void *p2)
{
	const struct pid_memory_usage_list *l1 = p1, *l2 = p2;
	int cmp;
	int ret;

	cmp = (l2->total_memory) - (l1->total_memory); // compare total memory
	if (cmp == 0) {
		cmp = (l1->pid) - (l2->pid); // compare PID
	}

	if (cmp == 0) {
		ret = 0;
	} else if (cmp > 0){
		ret = 1;
	} else {
		ret = -1;
	}

	return ret;
}

static void add_list(char *buf, int len)
{
	char *token;
	int idx = 0;
	char pch[TOKEN_NUMBER][TOKEN_LENGTH];
	int i = 0;
	unsigned long gfp_mask;

	if (list_size != 0 &&
	    len == list[list_size-1].len &&
	    memcmp(buf, list[list_size-1].txt, len) == 0) {
		list[list_size-1].num++;
		return;
	}
	if (list_size == max_size) {
		printf("max_size too small??\n");
		exit(1);
	}
	list[list_size].txt = malloc(len+1);
	list[list_size].len = len;
	list[list_size].num = 1;
	memcpy(list[list_size].txt, buf, len);
	list[list_size].txt[len] = 0;

	if (strstr(list[list_size].txt, "PageSlab"))
		list[list_size].is_Slab = 1;
	else
		list[list_size].is_Slab = 0;

	if (strstr(list[list_size].txt, "PageSwapCache"))
		list[list_size].is_SwapCache = 1;
	else
		list[list_size].is_SwapCache = 0;

	for (i = 0; i < (int)(strlen(list[list_size].txt)); i++) {
		if (list[list_size].txt[i] == '\n')
			list[list_size].txt[i] = '\0';
	}
	removeChar(list[list_size].txt, ',');
	token = strtok(list[list_size].txt, " ");
	while (token != NULL) {
		strcpy(pch[idx], token);
		idx++;
		token = strtok(NULL, " ");
	}

	gfp_mask = (unsigned long)strtol(pch[TOKEN_INDEX_MASK_VALUE], NULL, 16);
	if (gfp_mask & 0x4000000u/*__GFP_DMA_ALLOC_CONTIG*/) {
		list[list_size].is_CMA = 1;
	} else {
		list[list_size].is_CMA = 0;
	}
	strncpy(list[list_size].zone, pch[TOKEN_INDEX_ZONE_VALUE], sizeof(list[list_size].zone));
	list[list_size].page_size = (int)strtol(pch[TOKEN_INDEX_SIZE_VALUE], NULL, 10);
	strncpy(list[list_size].migrate_type, pch[TOKEN_INDEX_TYPE_VALUE], sizeof(list[list_size].migrate_type));
	list[list_size].pid = (int)strtol(pch[TOKEN_INDEX_PID_VALUE], NULL, 10);
	strncpy(list[list_size].task_name, pch[TOKEN_INDEX_TASK_NAME], sizeof(list[list_size].task_name));

	list_size++;
	if (list_size % 1000 == 0) {
		printf("loaded %d\r", list_size);
		fflush(stdout);
	}
}

#define BUF_SIZE	1024

int main(int argc, char **argv)
{
	FILE *fin, *fout;
	char buf[BUF_SIZE];
	int ret, i, count;
	struct block_list *list2;
	struct stat st;
	int sort_option;
	unsigned long total_CMA_usage = 0;
	unsigned long total_nonCMA_usage = 0;
	unsigned long total_Slab_usage = 0;
	struct pid_memory_usage_list *list_pid_mem;
	int list_pid_mem_count;

	if (argc < 5) {
		printf("Usage: ./program <input> <output> <list-mode> <sort-option>\n"
			"\t<list-mode>:\n"
			"\t   1 : Summary mode\n"
			"\t   2 : Details mode\n"
			"\t<sort-option>:\n"
			"\t  -s : sort by page size\n"
			"\t  -t : sort by alloc times\n"
			"\t  -m : sort by migrate type\n"
			"\t  -p : sort by PID\n"
			"\t  -a : sort by memory amount\n"
			"\tEx: ./page_owner_parser page_owner_full.txt sorted_page_owner.txt 1 -s\n");
		//perror("open: ");
		exit(1);
	}

	fin = fopen(argv[1], "r");
	fout = fopen(argv[2], "w");
	if (!fin || !fout) {
		printf("Usage: ./program <input> <output> <list-mode> <sort-option>\n"
			"\t<list-mode>:\n"
			"\t   1 : Summary mode\n"
			"\t   2 : Details mode\n"
			"\t<sort-option>:\n"
			"\t  -s : sort by page size\n"
			"\t  -t : sort by alloc times\n"
			"\t  -m : sort by migrate type\n"
			"\t  -p : sort by PID\n"
			"\t  -a : sort by memory amount\n"
			"\tEx: ./page_owner_parser page_owner_full.txt sorted_page_owner.txt 1 -s\n");
		//perror("open: ");
		exit(1);
	}

	if (atoi(argv[3]) == 1)
		list_mode = kModeSummary;
	else if (atoi(argv[3]) == 2)
		list_mode = kModeDetails;
	else {
		printf("Unknown list mode, list summary as default\n");
		list_mode = kModeSummary;
	}

	if (!strcmp(argv[4], "-s")) {
		sort_option = kOptionSortByPageSize;
	} else if (!strcmp(argv[4], "-t")) {
		sort_option = kOptionSortByAllocTimes;
	} else if (!strcmp(argv[4], "-m")) {
		sort_option = kOptionSortByMigrateType;
	} else if (!strcmp(argv[4], "-p")) {
		if (list_mode == kModeSummary) {
			sort_option = kOptionSummarySortByPID;
		} else {
			sort_option = kOptionSortByPID;
		}
	} else if (!strcmp(argv[4], "-a")) {
		sort_option = kOptionSortByMemoryAmount;
	} else {
		printf("Unknown sort option, sort by page count as default\n");
		sort_option = kOptionSortByPageSize;
	}

	fstat(fileno(fin), &st);
	max_size = st.st_size / 100; /* hack ... */

	list = malloc(max_size * sizeof(*list));

	for ( ; ; ) {
		ret = read_block(buf, BUF_SIZE, fin);
		if (ret < 0)
			break;

		add_list(buf, ret);
	}

	printf("loaded %d\n", list_size);

	switch (sort_option) {
		case kOptionSortByPageSize:
			printf("sorting by Page Size....\n");
			qsort(list, list_size, sizeof(list[0]), compare_txt_by_size);
			break;

		case kOptionSortByAllocTimes:
			printf("sorting by Alloc Times....\n");
			qsort(list, list_size, sizeof(list[0]), compare_txt_by_size);
			break;

		case kOptionSortByMigrateType:
			printf("sorting by Migrate Type....\n");
			qsort(list, list_size, sizeof(list[0]), compare_txt_by_mt);
			break;

		case kOptionSortByPID:
		case kOptionSummarySortByPID:
			printf("sorting by PID....\n");
			qsort(list, list_size, sizeof(list[0]), compare_txt_by_pid);
			break;

		case kOptionSortByMemoryAmount:
			printf("sorting by Memory Amount....\n");
			qsort(list, list_size, sizeof(list[0]), compare_txt_by_size);
			break;

		default:
			printf("Unknown sorting option, should not be happened!\n");
			break;
	}

	list2 = malloc(sizeof(*list) * list_size);

	printf("culling\n");

	if ((list_mode == kModeSummary) && (sort_option != kOptionSummarySortByPID)) {
		for (i = count = 0; i < list_size; i++) {
			if (count == 0 || (list2[count-1].is_CMA != list[i].is_CMA) || (list2[count-1].is_Slab != list[i].is_Slab)
					|| strcmp(list2[count-1].zone, list[i].zone) || (list2[count-1].page_size != list[i].page_size) || strcmp(list2[count-1].migrate_type, list[i].migrate_type)) {
				list2[count] = list[i];
				count++;
			} else {
				list2[count-1].num += list[i].num;
			}
		}
	} else {
		for (i = count = 0; i < list_size; i++) {
			if (count == 0 || (list2[count-1].is_CMA != list[i].is_CMA) || (list2[count-1].is_Slab != list[i].is_Slab)
					|| strcmp(list2[count-1].zone, list[i].zone) || (list2[count-1].page_size != list[i].page_size) || strcmp(list2[count-1].migrate_type, list[i].migrate_type)
					|| (list2[count-1].pid != list[i].pid)) {
				list2[count] = list[i];
				count++;
			} else {
				list2[count-1].num += list[i].num;
			}
		}
	}

	switch (sort_option) {
		case kOptionSortByPageSize:
		case kOptionSortByMigrateType:
		case kOptionSortByPID:
			break;

		case kOptionSortByAllocTimes:
			qsort(list2, count, sizeof(list[0]), compare_num_by_times);
			break;

		case kOptionSortByMemoryAmount:
			qsort(list2, count, sizeof(list[0]), compare_num_by_amount);
			break;

		case kOptionSummarySortByPID:
			qsort(list2, count, sizeof(list[0]), compare_num_by_pid);
			break;

		default:
			printf("Unknown sorting option, should not be happened!\n");
			break;
	}

	if (list_mode == kModeSummary) {
		for (i = 0; i < count; i++) {
			if (sort_option != kOptionSummarySortByPID) {
				printf("%8s%3s%8s: %6d KB (0x%07x) x%6d = %6d KB %s\n",
					list2[i].is_CMA ? "CMA" : "Non-CMA", list2[i].is_Slab ? "(S)" : "",
					list2[i].zone, list2[i].page_size, list2[i].page_size * 1024,
					list2[i].num, list2[i].page_size * list2[i].num, list2[i].migrate_type);
				fprintf(fout, "%8s%3s%8s: %6d KB (0x%07x) x%6d = %6d KB %s\n",
					list2[i].is_CMA ? "CMA" : "Non-CMA", list2[i].is_Slab ? "(S)" : "",
					list2[i].zone, list2[i].page_size, list2[i].page_size * 1024,
					list2[i].num, list2[i].page_size * list2[i].num, list2[i].migrate_type);
			}
			if (list2[i].is_CMA) {
				total_CMA_usage += list2[i].page_size * list2[i].num;
			} else {
				total_nonCMA_usage += list2[i].page_size * list2[i].num;
				if (list2[i].is_Slab) {
					total_Slab_usage += list2[i].page_size * list2[i].num;
				}
			}
		}
	} else {
		for (i = 0; i < count; i++) {
			printf("%8s%3s%8s: %6d KB (0x%07x) x%6d = %6d KB %s PID%5d %s\n",
				list2[i].is_CMA ? "CMA" : "Non-CMA", list2[i].is_Slab ? "(S)" : " ",
				list2[i].zone, list2[i].page_size, list2[i].page_size * 1024,
				list2[i].num, list2[i].page_size * list2[i].num, list2[i].migrate_type,
				list2[i].pid, list2[i].task_name);
			fprintf(fout, "%8s%3s%8s: %6d KB (0x%07x) x%6d = %6d KB %s PID%5d %s\n",
				list2[i].is_CMA ? "CMA" : "Non-CMA", list2[i].is_Slab ? "(S)" : " ",
				list2[i].zone, list2[i].page_size, list2[i].page_size * 1024,
				list2[i].num, list2[i].page_size * list2[i].num, list2[i].migrate_type,
				list2[i].pid, list2[i].task_name);
		}
	}

	if (sort_option == kOptionSummarySortByPID) {
		int i = 0, j = 0;
		list_pid_mem = malloc(sizeof(*list_pid_mem) * count);

		for (i = list_pid_mem_count = 0; i < count; i++) {
			if (list_pid_mem_count == 0 || (list_pid_mem[list_pid_mem_count-1].pid != list2[i].pid)) {
				list_pid_mem[list_pid_mem_count].pid = list2[i].pid;
				list_pid_mem[list_pid_mem_count].total_memory = list2[i].page_size * list2[i].num;
				list_pid_mem[list_pid_mem_count].count = 1;
				list_pid_mem[list_pid_mem_count].list2_index = i;
				list_pid_mem_count++;
			} else {
				list_pid_mem[list_pid_mem_count-1].total_memory += list2[i].page_size * list2[i].num;
				list_pid_mem[list_pid_mem_count-1].count++;
			}
		}

		qsort(list_pid_mem, list_pid_mem_count, sizeof(list_pid_mem[0]), compare_sum_by_pid);

		for (i = 0; i < list_pid_mem_count; i++) {
			printf("PID%5d alloc %6d KB\n", list_pid_mem[i].pid, list_pid_mem[i].total_memory);
			fprintf(fout, "PID%5d alloc %6d KB\n", list_pid_mem[i].pid, list_pid_mem[i].total_memory);

			int index = list_pid_mem[i].list2_index;
			for (j = index; j < index + list_pid_mem[i].count; j++) {
				printf("    %8s%3s%8s: %6d KB (0x%07x) x%6d = %6d KB %s PID%5d %s\n",
					list2[j].is_CMA ? "CMA" : "Non-CMA", list2[j].is_Slab ? "(S)" : " ",
					list2[j].zone, list2[j].page_size, list2[j].page_size * 1024,
					list2[j].num, list2[j].page_size * list2[j].num, list2[j].migrate_type,
					list2[j].pid, list2[j].task_name);
				fprintf(fout, "    %8s%3s%8s: %6d KB (0x%07x) x%6d = %6d KB %s PID%5d %s\n",
					list2[j].is_CMA ? "CMA" : "Non-CMA", list2[j].is_Slab ? "(S)" : " ",
					list2[j].zone, list2[j].page_size, list2[j].page_size * 1024,
					list2[j].num, list2[j].page_size * list2[j].num, list2[j].migrate_type,
					list2[j].pid, list2[j].task_name);
			}
		}
	}

	if (list_mode == kModeSummary) {
		printf("Total memory used \t= %7ld KB\n", total_CMA_usage + total_nonCMA_usage);
		printf("  CMA memory used \t= %7ld KB\n", total_CMA_usage);
		printf("  Non-CMA memory used \t= %7ld KB\n", total_nonCMA_usage);
		printf("  SLAB memory used \t= %7ld KB\n", total_Slab_usage);

		fprintf(fout, "Total memory used \t= %7ld KB\n", total_CMA_usage + total_nonCMA_usage);
		fprintf(fout, "  CMA memory used \t= %7ld KB\n", total_CMA_usage);
		fprintf(fout, "  Non-CMA memory used \t= %7ld KB\n", total_nonCMA_usage);
		fprintf(fout, "  SLAB memory used \t= %7ld KB\n", total_Slab_usage);
	}

	return 0;
}
