#include <stdbool.h>



//Stack
struct stack_entry {
    int num;
    struct stack_entry* next;
};
typedef struct stack_entry stack_entry_t;

stack_entry_t* create_node(int num);
void push(int num, stack_entry_t** head);
int pop(stack_entry_t** head);
int stacklen(stack_entry_t** head);
void print_stack(stack_entry_t** head);



//Hash_table
#define TABLE_SIZE 256
#define MAX_WORD_LEN 64

typedef struct hash_entry {
    char string[MAX_WORD_LEN];
    struct hash_entry *next;
} hash_entry;

unsigned int hash_function(char *word);
void init_hash_table(hash_entry * hash_table[]);
bool insert_hash_table(hash_entry* p, hash_entry* table[]);
hash_entry* hash_table_lookup(char* word, hash_entry* table[]);
hash_entry* create_hash_entry(char *word);
void print_hash_table(hash_entry* hash_table[]);


