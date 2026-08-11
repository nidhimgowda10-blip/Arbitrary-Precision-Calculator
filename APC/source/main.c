#include "apc.h"

int main(int argc, char *argv[])
{
    /* Operand lists */
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;

    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;

    Dlist *headR =NULL;
    Dlist *tailR = NULL;

    Dlist *headRem = NULL;
    Dlist *tailRem = NULL;

    /* Command Line Argument Validation */
    if (cla_validation(argc, argv) == FAILURE)
    {
        printf("Invalid Input\n");
        printf("Usage: ./a.out <operand1> <operator> <operand2>\n");
        printf("For multiplication, use quotes: ./a.out 123 \"*\" 456\n");
        return FAILURE;
    }

    /* Create linked list for operands */
    create_list(&head1, &tail1, argv[OPERAND1]);
    create_list(&head2, &tail2, argv[OPERAND2]);

    /* Print the linked lists */
    printf("Operand 1: ");
    print_list(head1, tail1);   

    printf("Operand 2: ");
    print_list(head2, tail2);  
    
    /* Perform addition */
    if(strcmp(argv[OPERATOR], "+") == 0)
{
    addition(tail1, tail2, &headR, &tailR);

    printf("Addition Result: ");
    print_list(headR, tailR);
}
    /* Perform subtraction */
    else if(strcmp(argv[OPERATOR], "-") == 0)
{
    //printf("Compare = %d\n", compare_list(head1, head2));

    int result = compare_list(head1, head2);

    if(result >= 0)
    {
        subtraction(tail1, tail2, &headR, &tailR);

        printf("Subtraction Result: ");
        print_list(headR, tailR);
    }
    else
    {
        printf("Subtraction Result: -");

        subtraction(tail2, tail1, &headR, &tailR);

        print_list(headR, tailR);
    }
}
    /* Perform multiplication */
    else if(strcmp(argv[OPERATOR], "*") == 0)
{
    multiplication(tail1, tail2, &headR, &tailR);

    printf("Multiplication Result: ");
    print_list(headR, tailR);
}
    /* Perform division */
    else if(strcmp(argv[OPERATOR], "/") == 0)
{
    division(head1, tail1, head2, tail2, &headR, &tailR, &headRem, &tailRem);

    printf("Division Result: ");
    print_list(headR, tailR);
}
    /* Perform Modulus */
else if (strcmp(argv[OPERATOR], "%") == 0)
{
    division(head1, tail1,
             head2, tail2,
             &headR, &tailR,
             &headRem, &tailRem);

    printf("Modulus Result: ");
    print_list(headRem, tailRem);
}

    return SUCCESS;
}