#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList *createLinkedList(){
    LinkedList *list = malloc(sizeof(LinkedList));
    list->head = NULL;
    list->len = 0;
    return list;
}

Node *createNode(int data){
    Node *node = malloc(sizeof(Node));
    node->data = data;

    return node;
}

void setNextNode(Node *node, Node *next){
    node->nextNode = next;
}

Node *createNodeWithNextNode(int data, Node *next){
    Node *node = malloc(sizeof(Node));
    node->data = data;
    node->nextNode = next;
    
    return node;
}

void AddNodeAtBegin(LinkedList *list, int data){
    Node *node;

    if(list->len)
        node = createNodeWithNextNode(data, list->head);
    else
        node = createNode(data);
    
    list->head = node;
    
    list->len++;
}

void appendNode(LinkedList *list, int data){
    Node *lastNode = getLastNode(list);
    Node *node = createNode(data);

    if(lastNode)
        setNextNode(lastNode, node);
    else
        list->head = node;
    
    list->len++;
}

Node *getNode(LinkedList *list, unsigned int index){
    if(index < list->len){
        Node *curNode = list->head;
        
        for (int i = 0; i < index; i++){
            curNode = curNode->nextNode;
        }

        return curNode;
    }
}

Node *getLastNode(LinkedList *list){
    return getNode(list, list->len -1);
}

// depends on addNode checking
void insertNode(LinkedList *list, int data, unsigned int index){
    Node *previousNode = getNode(list, index-1);
    Node *curNode = previousNode->nextNode;
    Node *insertedNode = createNodeWithNextNode(data, curNode);

    setNextNode(previousNode, insertedNode);

    list->len++;
}

void addNode(LinkedList *list, int data, unsigned int index){
    if(index == 0)
        AddNodeAtBegin(list, data);
    else if(index == list->len)
        appendNode(list, data);
    else
        insertNode(list, data, index);
}

void showList(LinkedList *list){
    printf("[");

    if(!list->len){
        printf("]\n");
        return;
    }

    Node *node = list->head;

    while(node){
        printf("%d,", node->data);
        node = node->nextNode;
    }

    printf("]\n");
}

Node *selectNodeForDelete(LinkedList *list, unsigned int index){
    if(index == 0){
         return getNode(list, index);
    }

    Node *previousNode = getNode(list, index-1);
    Node *node = previousNode->nextNode;
    if(index != list->len -1){
        setNextNode(previousNode, node->nextNode); 
    }else{
        previousNode->nextNode = NULL;
    }

    return node;
}

void deleteNode(LinkedList *list, unsigned int index){
    if(index+1 > list->len) return;

    Node *node = selectNodeForDelete(list, index);

    if(!node) return;

    if(index == 0 && node->nextNode)
        list->head = node->nextNode;

    list->len--;
    free(node);
}

void pop(LinkedList *list){
    deleteNode(list, list->len-1);
}

void deleteAllNodes(LinkedList *list){
    Node *node = list->head;

    while(node){
        Node *next = node->nextNode;

        free(node);

        node = next;
    }
}

void deleteLinkedList(LinkedList *list){
    deleteAllNodes(list);

    free(list);
}
