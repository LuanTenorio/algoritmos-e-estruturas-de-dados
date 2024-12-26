#include <stdio.h>
#include "linkedList.h"

int main(){

    LinkedList *list = createLinkedList();
    
    showList(list);

    for(int i = 0; i < 10; i++){
        appendNode(list, (i + 4)*23);
        showList(list);
    }

    return 0;
}