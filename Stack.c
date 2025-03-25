#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


typedef struct node{
    struct node * previous;
    int value;
    struct node * next;
}node_t;

node_t * create_stack(int value){
    node_t * head = (node_t*) malloc(sizeof(node_t));
    head -> previous = NULL;
    head -> value = value;
    head -> next = (node_t*) malloc(sizeof(node_t));
    return head;
}

node_t * push(node_t* top, int value){

    node_t * current_node =top;
    current_node = current_node -> next = (node_t*) malloc(sizeof(node_t));
    current_node -> previous = top;
    current_node -> value = value;
    current_node ->next = NULL;

    return current_node;
}



node_t * pop(node_t * top){
    while (true)
    {
        if (top -> next == NULL){
            node_t * new_top = top -> previous;
            new_top -> next = NULL;
            printf("%d \n",top -> value);
            free(top);
            return new_top;
        }
        top = top -> next;
    }
}

void print_stack(node_t * top){
    node_t * current_node = top;
    while (current_node -> previous != NULL){
        printf("%d", current_node -> value);
        current_node = current_node -> previous;
    }
    printf("%d", current_node -> value);
    
}


int main (){

    node_t* top = create_stack(3);
    top = push(top,8);
    top = push(top,4);



    print_stack(top);
}
