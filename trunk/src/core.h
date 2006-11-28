#include <stdint.h>

/* A dlx_word should contain 32 Bits */
typedef int32_t dlx_word;

/* Memory is implemented as single linked list */
struct memcell {
	dlx_word addr;
	dlx_word data;
	struct memcell *next;
};
typedef struct memcell dlx_mem;

/* Prototypes for the "core" */
char *decode_instruction(dlx_word instr);
dlx_word encode_instruction(char *instr);
dlx_word get_mem_at_addr(dlx_word addr);
void set_mem_at_addr(dlx_word addr, dlx_word data);
dlx_word get_pipline_stage(int stage);
int clock_tick();
int enable_forwarding();
int disable_forwarding();
int set_logfile(int fd);
int enable_logging();
int set_verbosity(int verbosity);
int disable_logging();
int load_program(int fd);
void errorhandler();

