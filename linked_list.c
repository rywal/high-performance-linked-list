#include <stdio.h>
#include "linked_list.h"

char * Init (int M, int b){
    // allocate memory, given by M
    memory_pool = M;
    node_size = b;
    head_pointer = malloc(M);
    free_pointer = head_pointer;
}

void Destroy (){
    free(head_pointer);
}

int Insert (int key, char * value_ptr, int value_len){
    // Create new node beginning at free_pointer location
    struct node *new_node = free_pointer;
    node->key = key;
    node->next = free_pointer + node_size;
    node->value_len = value_len;
    memcpy(((char*) new_node) + sizeof(new_node), value_ptr, value_len);
    free_pointer = free_pointer + node_size;
}

int Delete (int key){}

char* Lookup (int key){return NULL;}

void PrintList (){}