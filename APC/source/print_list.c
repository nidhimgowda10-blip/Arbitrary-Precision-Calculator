#include "apc.h"

void print_list(Dlist *head, Dlist *tail)
{
    if(head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while(head != NULL)
    {
        printf("%d", head->data);
        head = head->next;
    }

    printf("\n");
}