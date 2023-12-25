#include <stdio.h>
#include "linkedList.c"
#include "linkedList.c"

void testList(){
    linkedList_t* list = newLinkedList();
    listAddEnd(list, 5);
    listAddEnd(list, 10);
    listAddEnd(list, 2);
    ListPrint(list);

    listAddAtPosition(list, 84, 0);
    ListPrint(list);

    listAddAtPosition(list, 84, 1);
    ListPrint(list);

    listAddAtPosition(list, 84, 3);
    ListPrint(list);

    listAddAtPosition(list, 84, 5);
    ListPrint(list);

    listAddAtPosition(list, 84, 7);
    ListPrint(list);

    listRemoveAtPosition(list, 0);
    ListPrint(list);

    printf("%d\n",listRemoveAtPosition(list, 3));
    ListPrint(list);

    printf("%d\n",listRemoveAtPosition(list, 4));
    ListPrint(list);

    printf("%d\n",listRemoveAtPosition(list, 4));
    ListPrint(list);
}

int main(){
    printf("Hello world!\n");

    

    return 0;
}