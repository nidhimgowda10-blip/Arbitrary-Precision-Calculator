#include "apc.h"

void create_list(Dlist **head, Dlist **tail, char *str)
{
    int i = 0;

    while(str[i] != '\0')
    {
        insert_last(head, tail, str[i] - '0');
        i++;
    }
}