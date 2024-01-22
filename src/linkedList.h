#ifndef LINKED_LIST_H
#define LINKED_LIST_H 1

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct node{
    struct node* previous;
    int val;
    struct node* next;
}node_t;

typedef struct list {
    node_t* head;
    unsigned int size;
    node_t* tail;
} list_t;

void get_list(list_t*, int*, int);
void replace_in_list(list_t*, int, int);
void add_to_list(list_t*, int);
void remove_from_list(list_t*);
void push_to_list(list_t*, int);
void pop_from_list(list_t*);
void insert_to_list(list_t*, int, int);
void concatenate_list(list_t*, list_t*);
void clear_list(list_t*);
list_t init_list(int*, int);
void print_list(list_t*);
void print_list_reverse(list_t*);


void get_list(list_t* pList, int* value, int index){
    if(index >= 0){
        node_t* current = pList -> head;
        for(int i = 0; i < index; i++){
            current = current -> next;
        }
        *value = current -> val;
    }else{
        node_t* current = pList -> tail;
        for(int i = -1; i > index; i--){
            current = current -> previous;
        }
        *value = current->val;
    }
    return;
};

void replace_in_list(list_t* pList, int value, int index){
    if(index >= 0){
        node_t* current = pList -> head;
        for(int i = 0; i < index; i++){
            current = current -> next;
        }
        current -> val = value;
    }else{
        node_t* current = pList -> tail;
        for(int i = -1; i > index; i--){
            current = current -> previous;
        }
        current->val = value;
    }
    return;
};

void add_to_list(list_t* pList, int value){
    if(pList -> head == NULL){
        node_t node = {NULL, value, NULL};
        node_t* p = (node_t*)malloc(sizeof(node_t));
        memcpy(p, &node, sizeof(node_t));
        pList -> size++;
        pList -> head = p;
        pList -> tail = p; 
    }else{        
        node_t node = {pList -> tail, value, NULL};
        node_t* p = (node_t*)malloc(sizeof(node_t));
        memcpy(p, &node, sizeof(node_t));
        pList -> size++;
        pList -> tail -> next = p;
        pList -> tail = p;
    }
    return;
}

void remove_from_list(list_t* pList){
    if(pList -> tail == NULL){
        return;
    }else if(pList -> size == 1){
        free(pList -> head);
        pList->size--;
        pList->head = NULL;
        pList->tail = NULL;
    }else{
        pList -> tail = pList -> tail -> previous;
        free(pList -> tail -> next);
        pList -> tail -> next = NULL;
        pList -> size--;
    }
    return;
}

void push_to_list(list_t* pList, int value){
    if(pList -> head == NULL){
        node_t node = {NULL, value, NULL};
        node_t* p = (node_t*)malloc(sizeof(node_t));
        memcpy(p, &node, sizeof(node_t));
        pList -> size++;
        pList -> head = p;
        pList -> tail = p;
    }else{
        node_t node = {NULL, value, pList -> head};
        node_t* p = (node_t*)malloc(sizeof(node_t));
        memcpy(p, &node, sizeof(node_t));
        pList -> size++;
        pList -> head -> previous = p;
        pList -> head = p;
    }
    return;
}

void pop_from_list(list_t* pList){
    if(pList -> head == NULL){
        return;
    } else if(pList -> size == 1){
        free(pList -> head);
        pList -> size--;
        pList -> head = NULL;
        pList -> tail = NULL;
    }else{
        free(pList -> head);
        pList -> size--;
        pList -> head = pList -> head -> next;
        pList -> head -> previous = NULL;
    }
    return;
}

void insert_to_list(list_t* pList, int value, int index){
    if(pList -> head == NULL){
        node_t node = {NULL, value, NULL};
        node_t* p = (node_t*)malloc(sizeof(node_t));
        memcpy(p, &node, sizeof(node_t));
        pList -> size++;
        pList -> head = p;
        pList -> tail = p;
        return;
    }else{
        node_t* current = pList->head;
        for(int i = 0; i < index; i++){
            if(current -> next == NULL){
                add_to_list(pList, value);
                return;
            }else{
                current = current -> next;
            }
        }

        if(current -> previous == NULL){
            push_to_list(pList, value);
        }else{
            node_t node = {current -> previous, value, current};
            node_t* p = (node_t*)malloc(sizeof(node_t));
            memcpy(p, &node, sizeof(node_t));
            pList -> size++;
            current -> previous -> next = p;
            current -> previous = p;
        }

        return;
    }
}

void concatenate_list(list_t* pList1, list_t* pList2){
    if(pList1 -> head == NULL){
        pList1->head = pList2->head;
        pList1->tail = pList2->tail;
        list_t empty = {NULL, 0, NULL};
        *pList2 = empty;
    }else{
        pList1->tail->next = pList2->head;
        pList2->head->previous = pList1->tail;
        pList1->tail = pList2->tail;
        pList1->size += pList2->size;
        list_t empty = {NULL, 0, NULL};
        *pList2 = empty;
    }
}

void clear_list(list_t* pList){
    while (pList -> head != 0)
    {
        remove_from_list(pList);
    }
    return;
}

void print_list(list_t* pList){
    node_t* curentNode = pList -> head;
    while (curentNode != NULL)
    {
        printf("%d, ", curentNode->val);
        curentNode = curentNode->next;
    }
    puts("");
    return;
}

void print_list_reverse(list_t* pList){
    node_t* curentNode = pList -> tail;
    while (curentNode != NULL)
    {
        printf("%d, ", curentNode->val);
        curentNode = curentNode->previous;
    }
    puts("");
    return;
}

list_t init_list(int* arr, int size){
    list_t newList = {NULL, 0, NULL};
    
    for(int i = 0; i < size; i++){
        add_to_list(&newList, arr[i]);
    }

    return newList;
}

#endif