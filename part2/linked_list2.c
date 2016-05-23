#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "linked_list2.h"

//
// Machine Problem 2
// CSCE 313-501
// Base code provided by Texas A&M University
// Edited by Ryan Walters and Garrett Haynes
// September 20, 2015
//
const int INT_MAX = 2147483647;

int tier_assignment(int key){
//    for(int i = 1; i <= tiers; i++){
//        if(key >= (INT_MAX/tiers)*(i-1) && key < (INT_MAX/tiers) * i){
//            return i;
//        }
//        if(key == INT_MAX)  return tiers;
//    }
    int ratio = INT_MAX/tiers;
    int t = key/ratio;
    if(t == tiers)  t--;
    
    return t;
}

void Init (int M, int b, int t){
    memory_pool = M;
    memory_pool_tier = M/t;
    tiers = t;
    node_size = b;
    head_pointers = malloc(sizeof(struct node*)*t);
    free_pointers = malloc(sizeof(struct node*)*t);
    num_nodes = malloc(sizeof(int)*t);
    
    for(int i = 0; i < tiers; i++){
        head_pointers[i] = (struct node*)malloc(memory_pool_tier);
        free_pointers[i] = (char*)head_pointers[i];
        num_nodes[i] = 0;
    }
}

void Destroy (){
    for(int i = 0; i < tiers; i++){
        head_pointers[i] = NULL;
        free_pointers[i] = NULL;
        num_nodes[i] = 0;
    }
}

int Insert (int key,char * value_ptr, int value_len){
    int tier = tier_assignment(key);
    
    // Check if there is enough space to insert a new node
    if(num_nodes[tier] >= memory_pool_tier / node_size){
        printf("ERROR: Not enough space in tier %i to add node with key: %d\n", tier, key);
        return -1;
    }
    
    // Make sure we can fit the value given
    if(value_len > node_size - (sizeof(key)+sizeof(value_len)+sizeof(free_pointers[tier]))){
        printf("ERROR: Insertion aborted because size of the value given is too large\n");
        return -1;
    }
    
    // Create new node beginning at free_pointer location
    struct node *new_node = (struct node*)free_pointers[tier];
    new_node->key = key;
    new_node->next = (struct node*)(free_pointers[tier] + node_size);
    new_node->value_len = value_len;
    
    memcpy((free_pointers[tier] + sizeof(struct node)), value_ptr, value_len);
    free_pointers[tier] = free_pointers[tier] + node_size;
    
    num_nodes[tier]++;
        printf ("Inserted: Tier = %i, Key = %i, Value Len = %i\n", tier, new_node->key, new_node->value_len);
    return key;
}

int Delete (int key){
    int t = tier_assignment(key);
    int deleted = 0;
    
    struct node* current_node = head_pointers[t];
    struct node* previous_node = NULL;
    
    for(int j = 1; j <= num_nodes[t]; j++){
        if (current_node->key == key && deleted != 1) {
            if (previous_node != NULL) {
                previous_node->next = current_node->next;
            } else {
                head_pointers[t] = current_node->next;
            }
            num_nodes[t]--;
            printf("\nDeleted: Node with key: %d from tier %i\n", key, t);
            deleted = 1;
        }
        previous_node = current_node;
        current_node = current_node->next;
    }
    
    if(deleted == 1) {
        return key;
    } else {
        printf("\nERROR: Failed to find a node with key: %d\n", key);
        return -1;
    }
}

char* Lookup (int key){
    int t = tier_assignment(key);
    
    struct node* current_node = head_pointers[t];
    
    for(int j = 1; j <= num_nodes[t]; j++){
        if (current_node->key == key) {
            char* location = (char*) current_node + sizeof(struct node*);
            return location;
        }
        current_node = current_node->next;
    }

    return NULL;
}

void PrintList (){
    for(int i = 0; i < tiers; i++){
        if(num_nodes[i] > 0){
            struct node* current_node = head_pointers[i];
            for(int j = 1; j <= num_nodes[i]; j++){
                printf ("Tier: %i, Key = %i, Value Len = %i\n", i, current_node->key, current_node->value_len);
                current_node = current_node->next;
            }
        }
    }
}
