#include "apc.h"

int insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *new = malloc(sizeof(Dlist));

    if(new == NULL)
    {
        return FAILURE;
    }

    new->data = data;
    new->prev = NULL;
    new->next = NULL;

    if(*head == NULL)   // List is empty, add first node
    {
        *head = new;
        *tail = new;
    }
    else                // List is not empty, add node at the end
    {
        new->prev = *tail;
        (*tail)->next = new;
        *tail = new;
    }

    return SUCCESS;
}