#include <stdio.h>
#include "linkedList.c"
#include "linkedList.c"

int main(){
    printf("Hello world!\n");

    linkedList_t* list = newLinkedList();
    listAddEnd(list, 5);
    listAddEnd(list, 10);
    listAddEnd(list, 2);
    ListPrint(list);

    printf("remove %d\n", listRemoveEnd(list));
    ListPrint(list);

    printf("remove %d\n", listRemoveEnd(list));
    ListPrint(list);

    printf("remove %d\n", listRemoveEnd(list));
    ListPrint(list);

    printf("remove %d\n", listRemoveEnd(list));
    ListPrint(list);
    //printf("%d\n",list->size);

    return 0;
}