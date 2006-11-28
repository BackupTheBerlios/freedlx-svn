#include <stdlib.h>
#include <stdio.h>
#include "core.h"

int i;
int addr[100];
int values[100];
int passed;
int failed;

int main() {
	printf("Initiating test sequence...\n");
	
	/* test1 - write some data at various mem locations and read it */
	passed = 1;
	for (i=0;i<100;i++) {
		addr[i] = (dlx_word) rand();
		values[i] = (dlx_word) rand();
		set_mem_at_addr(addr[i], values[i]);
	}
	for (i=0;i<100;i++) {
		if (get_mem_at_addr(addr[i]) != values[i]) {passed = 0;}
	}
	if (passed) {printf("test1 .. ok\n");}
	else {printf("test1 .. not ok\n"); failed++;}
	passed = 1;
	/* end of test1 */

	exit(0);
}

