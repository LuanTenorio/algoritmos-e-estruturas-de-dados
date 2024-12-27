#include <stdio.h>
#include "linkedList.h"

int main(){

    LinkedList *list = createLinkedList();
    
    showList(list);

    for(int i = 0; i < 10; i++)
        appendNode(list, i);

    printf("appendNode\n");

    showList(list);

    for(int i = 10; i > 0; i--)
        deleteNode(list, i-1);

    showList(list);

    printf("deleteNode\n");

    for(int i = 0; i < 10; i++)
        addNode(list, i, 0);
    

    printf("Add node at the beginning\n");
    showList(list);

    for(int i = 0; i < 10; i++){
        deleteNode(list, 0);
    }

    printf("delete node at the beginning\n");
    showList(list);

    appendNode(list, 0);

    for(int i = 1; i < 10; i++)
        addNode(list, i, 1);
    

    printf("add the node in the first position\n");
    showList(list);


    for(int i = 0; i < 10; i++){
        deleteNode(list, 1);
    }

    printf("delete the node in the first position\n");

    showList(list);

    deleteLinkedList(list);

    return 0;
}