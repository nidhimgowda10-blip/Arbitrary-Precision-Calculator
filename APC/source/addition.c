#include "apc.h"

void addition(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    int carry = 0;
    int sum;

    while(tail1 != NULL || tail2 != NULL)
    {
        int data1 = 0;
        int data2 = 0;

        if(tail1 != NULL)
        {
            data1 = tail1->data;
            tail1 = tail1->prev;
        }

        if(tail2 != NULL)
        {
            data2 = tail2->data;
            tail2 = tail2->prev;
        }

        sum = data1 + data2 + carry;

        carry = sum / 10; //carry for next digit

        insert_first(headR, tailR, sum % 10); //current digit
    }

    if(carry)
    {
        insert_first(headR, tailR, carry);
    }
}