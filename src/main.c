#include <stdio.h>
#include "linkedList.c"
#include "linkedList.c"

int main(){
    printf("Hello world!\n");

    linkedList_t* list = newLinkedList();
    addEnd(list, 5);
    addEnd(list, 10);
    addEnd(list, 2);
    addEnd(list, 22);
    addEnd(list, 1);
    addEnd(list, 8);
    //printf("%d\n",list->size);

    printList(list);
    

    return 0;
}