/**
	Writing Rules of rpc scripts.
	
	Author: Right Sun.
 */
 
1. NOT to use "//"., rpcgen don't know it. plz use " /*.... */".
2. MUST use ";" after any structure definition.
3. MUST write your functions insinde 
	"program { version { HERE } = 0 } =300;"
4. NOT to put your structure definition inside 
	"program { version { HERE } = 0 } =300;"
5. MUST use "unsigned long" to represent a pointer definition.
	 Not to use "long *", or "struct ABC*" to define a variable.
	 The ROS versioned rpcgen can't handle it well.
6. define a enumerator with full description. It should be like:
	 enum number_set
	 {
	 	FIRST = 1,
	 	SECOND,
	 	...
	 	...
	 } ;
	 Not to use only "enum number_set ;" rpcgen needs 
	 to handle the symbol, such as FIRST, SECOND, etc.
	 