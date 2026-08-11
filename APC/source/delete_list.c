#include "apc.h"

int delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    if(*head == NULL)
    {
        return FAILURE;
    }

    while(*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    *tail = NULL;
    return SUCCESS;
}