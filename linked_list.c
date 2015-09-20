#include <stdio.h>
#include "linked_list.h"

void Init (int M, int b){
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
    new_node->key = key;
    new_node->next = free_pointer + node_size;
    new_node->value_len = value_len;
    memcpy(((char*) new_node) + sizeof(new_node), value_ptr, value_len);
    free_pointer = free_pointer + node_size;
    return key;
}

int Delete (int key){}

char* Lookup (int key){return NULL;}

void PrintList (){
    struct node* current_node = head_pointer;
    while(current_node){
        printf ("Key = %d, Value Len = %d\n", current_node->key, current_node->value_len);
        current_node = current_node->next;
    }
}