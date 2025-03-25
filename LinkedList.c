#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node
{
    struct node * head;
    int value;
    struct node * next;

} node_t;

typedef struct length{
    int length;
    node_t * last_node;
}length_t;


//
//length
//



length_t * length (node_t * head){

    node_t * current_node = head;
    bool not_last_node = true;
    int count = 1;
    while(not_last_node){
        if (current_node -> next != NULL){
            current_node = current_node -> next;
            count++;
        }
        if (current_node -> next == NULL){
            not_last_node = false;
        } 
    }
    length_t * lp = (length_t*) malloc(sizeof(length_t));
    lp->length = count;
    lp->last_node= current_node;
    

    return lp;
}


//
//Append a node on the  array
//


node_t * append_array_from_last_node(node_t * last_node, int value){

    node_t *  append_node =  last_node -> next = (node_t*) malloc(sizeof(node_t));
    append_node -> head = last_node->head;
    append_node -> value = value;
    append_node -> next = NULL;


    return append_node;
}


node_t * append_array(node_t* head, int value){

    length_t * lp =length(head);
    node_t * last_node = lp -> last_node;
    node_t* append_node = last_node -> next = (node_t*) malloc(sizeof(node_t));
    append_node -> head = head;
    append_node -> value = value;
    append_node -> next = NULL;

    return append_node;
}


void print_list(node_t * head){
    node_t * current_node = head;
    while (current_node -> next != NULL){
        printf("%d ", current_node -> value);
        current_node = current_node -> next;
    }
    printf("%d", current_node -> value);
}



node_t * get_index(node_t* head, int index){
    node_t * current_node = head;
    int count = 0;
    while (current_node != NULL) {
        if (count == index ){
            return current_node;
        }
        if (current_node -> next == NULL ){
            current_node = NULL;
            return current_node;
        }
        count++;
        current_node = current_node -> next;
    }
}




node_t * create_array(int * initialNumbers, int len){
    
    node_t * head = (node_t*) malloc(sizeof(node_t));
    head -> head = head;
    head -> value = (int) initialNumbers[0];
    node_t * last_node = head;
    for(int i = 1; i < len ; i++){
        int append_number  = (int) initialNumbers[i]; 
        last_node = append_array_from_last_node(last_node,append_number);
    };


    return head;
}






int main(){

    int numbers[5] = {1,2,3,4,5};
    node_t *  head =create_array(numbers, 5);
    print_list(head);

    append_array(head, 6);
    print_list(head);
    length_t* teste = length(head);
    printf("%d", teste->length);

    return 0;
}