#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datastructures.h"

int main(){
    int flag = 0;
    
    printf("What data structure would you like to demonstrate?\n");
    printf("Type 1 for stack, 2 for hash table, 3 for tree.\n");
    scanf("%d", &flag);

    switch (flag){
    case 1:
        stack_entry_t* stack_head = NULL;

        //adding data to stack
        for (int i = 0; i < 5; i++){
            printf("pushing %d to the stack\n", i);
            push(i, &stack_head);
        }
        //printing the stack, removing a couple entries, printing again. Posistion 1 is top of the stack.
        printf("\n");
        print_stack(&stack_head);
        printf("\n");
        printf("popping %d off the stack\n", pop(&stack_head));
        printf("popping %d off the stack\n", pop(&stack_head));
        printf("\n");
        print_stack(&stack_head);
        break;

    case 2:
        hash_entry* hash_table[TABLE_SIZE];
        init_hash_table(hash_table);


        //inserting into hash table, then printing
        insert_hash_table(create_hash_entry("Billy"), hash_table);
        insert_hash_table(create_hash_entry("John"), hash_table);
        insert_hash_table(create_hash_entry("Pizza"), hash_table);
        insert_hash_table(create_hash_entry("Fred"), hash_table);
        insert_hash_table(create_hash_entry("Alabama"), hash_table);
        insert_hash_table(create_hash_entry("Apples"), hash_table);

        print_hash_table(hash_table);
        break;
    

    case 3:
        treenode *root = NULL;

        printf("inserting 14\n");
        tree_insertnumber(&root, 14);

        printf("inserting 3\n");
        tree_insertnumber(&root, 3);

        printf("inserting 20\n");
        tree_insertnumber(&root, 20);

        printf("inserting 8\n");
        tree_insertnumber(&root, 8);

        printf("inserting 16\n");
        tree_insertnumber(&root, 16);

        printf("inserting 25\n");
        tree_insertnumber(&root, 25);

        printtree(root);
        printf("\n");
        //tree_findnumber returns 1 if it exists in the tree, 0 if not.
        int array[6] = {20, 8, 16, 125, 1, 2};

        for (int i = 0; i < 6; i++){
            if(tree_findnumber(root, array[i])){
                printf("%d is in the tree!\n", array[i]);
            } else {
                printf("%d is not in the tree\n", array[i]);
            }
        }
        

        break;

    default:
        break;
    }

    return 0;
}