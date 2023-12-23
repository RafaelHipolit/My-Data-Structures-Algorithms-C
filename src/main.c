#include <stdio.h>
#include "linkedList.c"
#include "linkedList.c"

int main(){
    printf("Hello world!\n");

    linkedList_t* list = newLinkedList();
    addEnd(list, 5);
    addEnd(list, 10);

    printList(list);
    

    return 0;
}