#include "apc.h"

void multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR)
{
    Dlist *temp2 = tail2;

    Dlist *headTemp = NULL;
    Dlist *tailTemp = NULL;

    Dlist *headAns = NULL;
    Dlist *tailAns = NULL;

    int carry = 0;
    int count = 0;

    // Initialize result as 0
    insert_last(headR, tailR, 0);

    while(temp2 != NULL)
    {
        Dlist *temp1 = tail1;

        headTemp = NULL;
        tailTemp = NULL;

        carry = 0;

        // Multiply first number with one digit
        while(temp1 != NULL)
        {
            int mul = (temp1->data * temp2->data) + carry;

            insert_first(&headTemp, &tailTemp, mul % 10);

            carry = mul / 10;

            temp1 = temp1->prev;
        }

        if(carry)
        {
            insert_first(&headTemp, &tailTemp, carry);
        }

        // Add zeros according to position
        for(int i = 0; i < count; i++)
        {
            insert_last(&headTemp, &tailTemp, 0);
        }

        // Add partial result
        addition(*tailR, tailTemp, &headAns, &tailAns);

        delete_list(headR, tailR);

        *headR = headAns;
        *tailR = tailAns;

        headAns = NULL;
        tailAns = NULL;

        temp2 = temp2->prev;

        count++;
    }

    remove_pre_zeros(headR);
}