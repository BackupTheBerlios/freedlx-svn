#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include "core.h"

dlx_mem *memory = NULL;

void errorhandler() {
	printf("%s\n", strerror(errno));
	exit(1);
}

void set_mem_at_addr(dlx_word addr, dlx_word data) {
	dlx_mem *aktuell,*new;
	aktuell = memory;
	while (aktuell != NULL) {
		if (aktuell->addr == addr) {
			aktuell->data = data;
			return;
		}
		else {
			aktuell = aktuell->next;
		}
	}
	new = (dlx_mem *) malloc( sizeof(dlx_mem) );
	if (new == NULL) {
		errorhandler();
	}
	else {
		new->next = memory;
		new->addr = addr;
		new->data = data;
		memory = new;
	}
}

dlx_word get_mem_at_addr(dlx_word addr) {
	dlx_mem *aktuell = memory;
	while (aktuell != NULL) {
		if (aktuell->addr == addr) {
			return(aktuell->data);
		}
		else {
			aktuell = aktuell->next;
		}
	}
	/* Wooha! The program tried to read memory it never wrote two.
	 * How should we deal with that? For now let's return 0 */
	return(0);
}

