#include "apc.h"

void subtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    int borrow = 0;

    while(tail1 != NULL)
    {
        int data1 = tail1->data;
        int data2 = 0;

        if(tail2 != NULL)
        {
            data2 = tail2->data;
            tail2 = tail2->prev;
        }

        data1 = data1 - borrow;

        if(data1 < data2)
        {
            data1 = data1 + 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }

        insert_first(headR, tailR, data1 - data2);

        tail1 = tail1->prev;
    }

    remove_pre_zeros(headR);
}