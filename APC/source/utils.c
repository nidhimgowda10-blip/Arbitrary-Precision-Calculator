#include "apc.h"

int cla_validation(int argc, char *argv[])
{
    if(argc != 4)
    {
        return FAILURE;
    }

    return SUCCESS;
}


void remove_pre_zeros(Dlist **head)
{
    Dlist *temp = *head;

    while(temp != NULL && temp->data == 0 && temp->next != NULL)
    {
        *head = temp->next;
        (*head)->prev = NULL;

        free(temp);

        temp = *head;
    }
}

int list_len(Dlist *head)
{
    int count = 0;

    while(head != NULL)
    {
        count++;
        head = head->next;
    }

    return count;
}