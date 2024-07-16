#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructures.h"

int main(){
    stack_entry_t* stack_head = NULL;
    hash_entry* hash_table[TABLE_SIZE];
    init_hash_table(hash_table);



    //adding data to stack
    for (int i = 0; i < 5; i++){
        push(i, &stack_head);
    }
    //printing the stack, removing a couple entries, printing again.
    print_stack(&stack_head);
    pop(&stack_head);
    pop(&stack_head);
    printf("\n");
    print_stack(&stack_head);


    //inserting into hash table, then printing
    insert_hash_table(create_hash_entry("Billy"), hash_table);
    insert_hash_table(create_hash_entry("John"), hash_table);
    insert_hash_table(create_hash_entry("Pizza"), hash_table);
    insert_hash_table(create_hash_entry("Pizza"), hash_table);

    print_hash_table(hash_table);
    





    return 0;
}