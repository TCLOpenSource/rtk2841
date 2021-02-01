#include "system.h"
void diag_pass() {
      ((void(*)())(TEST_PASS))();
}

void diag_fail() {
      ((void(*)())(TEST_FAIL))();
}


