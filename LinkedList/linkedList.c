#include <stdio.h>
#include <stdlib.h>
#include "linkedList.h"

LinkedList createLinkedList(){
    LinkedList list = { NULL, 0 };
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
    Node *node = createNode(data);

    if(list->len)
        createNodeWithNextNode(data, list->head);
    else
        list->head = node;
    
    list->len++;
}

void appendNode(LinkedList *list, int data){
    Node *lastNode = getLastNode(list);
    Node *node = createNode(data);
    setNextNode(lastNode, node);
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
    return getNode(list, list->len);
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

