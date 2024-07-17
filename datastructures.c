#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "datastructures.h"

//This doc is a collection of data structures and utility functions i've written and used in C.
//Refer to datastructures.h for struct definitions

//-----------------------------
//------------Stack------------
//-----------------------------

//Creates a struct on the heap using malloc, fills struct with passed data, returns pointer to that struct.
stack_entry_t* create_stack_node(int num){
    stack_entry_t* result = malloc(sizeof(stack_entry_t));
    result->num = num;
    result->next = NULL;
    return result;

}

//creates a node, assigns it to head if it is the first on the stack, otherwise points next value to current head beforehand.
void push(int num, stack_entry_t** head){
    stack_entry_t* temp = create_stack_node(num);
    if(head == NULL){
        *head = temp;

    }
    else {
        temp->next = *head;
        *head = temp;

    }
    return;
}

//points head one down on the stack, then frees the old head. Returns the value head contained.
int pop(stack_entry_t** head){
    stack_entry_t* temphead = *head;
    int returnvalue = (*head)->num;
    *head = (*head)->next;
    free(temphead);
    
    return returnvalue;
}

//traverses down the stack, returns number of entries in the stack.
int stacklen(stack_entry_t** head){
    int len = 0;
    stack_entry_t* temp = *head;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;
}

//traverses down the stack, printing the value at each position. Position 1 is the top of the stack.
void print_stack(stack_entry_t** head){
    int pos = 1;
    stack_entry_t* temp = *head;
    while(temp != NULL){
        printf("Stack has value: %d at position: %d\n", temp->num, pos);
        temp = temp->next;
        pos++;
    }
    return;
}


//-----------------------------
//---------Hash Table----------
//-----------------------------
//Functions for creating a hash table, in this case it stores strings. Hash function will need changed based on needs. 
//Collisions are handled using a linked list. When a collision occurs a new entry is added at the end of the linked list.

//Does math based on input word, returns index for hash table.
unsigned int hash_function(char *word){
    unsigned int a = 0;
    int length = strnlen(word, MAX_WORD_LEN);
    for (int i = 0; i < length; i++){
        a += word[i];
        a = (a * word[i]) % TABLE_SIZE;

    }
    
    return a;
}

//sets every index of hash table to NULL
void init_hash_table(hash_entry * hash_table[]){
    for (int i = 0; i < TABLE_SIZE; i++){
        hash_table[i] = NULL;
    }

}

//inserts data into hash table
bool insert_hash_table(hash_entry* p, hash_entry* table[]){
    if (p == NULL) {
        return false;
    }
    int index = hash_function(p->string);
    hash_entry* tmp = table[index];
    //if no data at index, insert struct
    if (tmp == NULL){
        table[index] = p;
        return true;
    }
    //traverse down linked list if there is a collision, insert data at the end.
    while (tmp != NULL && tmp->next != NULL){
        tmp = tmp->next;
    }
    tmp->next = p;
    return true;

}

//returns a pointer to the location of struct with input string.
hash_entry* hash_table_lookup(char* word, hash_entry* table[]){
    int index = hash_function(word);
    hash_entry* tmp = table[index];
    while (tmp != NULL && strncmp(tmp->string, word, MAX_WORD_LEN != 0)){
        tmp = tmp->next;
    }
    return tmp;
}

//mallocs space for struct, fills in data, returns pointer to it.
hash_entry* create_hash_entry(char* word){
    hash_entry* result = malloc(sizeof(hash_entry));
    strncpy(result->string, word, strlen(word));
    result->next = NULL;
    return result;
}

//prints out each index of hash table, if there is collisions, traverse linked list and print each entry.
void print_hash_table(hash_entry* hash_table[]){

    for(int i = 0; i < TABLE_SIZE; i++){
        hash_entry *tmp = hash_table[i];
        if (hash_table[i] == NULL){
            printf("%i\t---\n", i);
        } else {
            printf("%i\t", i);
            while(tmp != NULL) {
                printf("word: '%s' \t", tmp->string);
                tmp = tmp->next;
            }
            printf("\n");
        }
    }
    printf("\n");

}


//------------------------
//----------Tree----------
//------------------------

//mallocs a tree struct, adds data and sets left/right to null
treenode* createtreenode(int value){
    treenode* result = malloc(sizeof(treenode));
    if(result !=NULL){
        result->value = value;
        result->left = NULL;
        result->right = NULL;
    }
    return result;
}

//recursively checks for space on the tree, moving left if value is less, right otherwise
bool tree_insertnumber(treenode **rootptr, int value){
    treenode *root = *rootptr;
    if(root == NULL){
        //tree is empty
        (*rootptr) = createtreenode(value);
        return true;
    }
    if(value == root->value){
        //already in tree, do nothing
        return false;
    }
    if(value < root->value){
        return tree_insertnumber(&(root->left), value);
    } else {
        return tree_insertnumber(&(root->right), value);
    }

}

//recursively steps through the tree, going left if value is less, right otherwise. Returns true if value is found within the tree.
bool tree_findnumber(treenode *root, int value){
    if(root == NULL){
        return false;
    }

    if(root->value == value){
        return true;
    }

    if(value < root->value){
        return tree_findnumber(root->left, value);
    } else {
        return tree_findnumber(root->right, value);
    }

}

//prints left and right values of root, if there is no data prints empty. Indent based on how many recursions deep we are.
void printtree_rec(treenode *root, int level){
    if(root == NULL){
        printtabs(level);
        printf("---empty---\n");
        return;
    }
    printtabs(level);
    printf("value = %d\n", root->value);

    printtabs(level);
    printf("left\n");
    printtree_rec(root->left, level+1);

    printtabs(level);
    printf("right\n");
    printtree_rec(root->right, level+1);

    printtabs(level);
    printf("done\n");

    return;
}

//initial call of recursive printtree function. Notably it passes the initial indent level.
void printtree(treenode *root){
    printtree_rec(root, 0);
}




//------------------------
//----------Misc----------
//------------------------

//converts a double into a string with trailing zeroes removed. Returns pointer to converted string.
char* dtos(double num){
    char buffer[100] = {'\0'};
    char* output = malloc(100 * sizeof(char));
    for(int i = 0; i < 100; i++){
        output[i] = '\0';
    }
    int chop = 0;
    snprintf(buffer, 100, "%f", num);

    for(int i = strlen(buffer); i > 0; i--){
        if(buffer[i] > 48 && buffer[i] < 58){
            chop = i+1;
            break;
        }
        if(buffer[i] == '.'){
            chop = i;
            break;
        }
    }

    strncpy(output, buffer, chop);
    return output;
}

//Prints desired number of tabs
void printtabs(int numtabs){
    for(int i = 0; i < numtabs; i++){
        printf("\t");
    }

    return;
}