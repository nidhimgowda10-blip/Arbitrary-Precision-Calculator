#include "apc.h"

void division(Dlist *head1, Dlist *tail1,
              Dlist *head2, Dlist *tail2,
              Dlist **headQ, Dlist **tailQ,
              Dlist **headRem, Dlist **tailRem)

{
    // Division by zero check
    if(head2 == NULL || (head2->data == 0 && head2->next == NULL))
    {
        printf("Division by zero is not possible\n");

        *headQ = NULL;
        *tailQ = NULL;
        *headRem = NULL;
        *tailRem = NULL;

        return;
    }

    // If dividend < divisor
    if(compare_list(head1, head2) < 0)
    {
        insert_last(headQ, tailQ, 0);

        /* Remainder = Dividend */
        *headRem = head1;
        *tailRem = tail1;
        return;
    }

    Dlist *tempHead = NULL;
    Dlist *tempTail = NULL;

    Dlist *quotientHead = NULL;
    Dlist *quotientTail = NULL;

    Dlist *temp1 = head1;


    while(temp1 != NULL)
    {
        // Bring down next digit
        insert_last(&tempHead, &tempTail, temp1->data);

        int count = 0;

        // Find quotient digit by repeated subtraction
        while(compare_list(tempHead, head2) >= 0)
        {
            Dlist *subHead = NULL;
            Dlist *subTail = NULL;

            subtraction(tempTail, tail2, &subHead, &subTail);

            delete_list(&tempHead, &tempTail);

            tempHead = subHead;
            tempTail = subTail;

            count++;
        }

        // Store quotient digit
        insert_last(&quotientHead, &quotientTail, count);

        temp1 = temp1->next;
    }


    // Remove leading zeros
    remove_pre_zeros(&quotientHead);
    remove_pre_zeros(&tempHead);

    *headQ = quotientHead;
    *tailQ = quotientTail;

    *headRem = tempHead;
    *tailRem = tempTail;
}
