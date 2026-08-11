#ifndef APC_H
#define APC_H

/* Header Files */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Command Line Argument Index */
#define PROG_NAME   0
#define OPERAND1    1
#define OPERATOR    2
#define OPERAND2    3

/* Status */
#define SUCCESS     0
#define FAILURE    -1

/* Doubly Linked List Node */
typedef struct node
{
    int data;
    struct node *next;
    struct node *prev;
} Dlist;

/* Function Prototypes */

/* List Creation */
void create_list(Dlist **head, Dlist **tail, char * str);

/* List Operations */
int insert_first(Dlist **head, Dlist **tail, int data);
int insert_last(Dlist **head, Dlist **tail, int data);
int delete_list(Dlist **head, Dlist **tail);
void print_list(Dlist *head, Dlist *tail);
int compare_list(Dlist *head1, Dlist *head2);

/* Utility Functions */
int cla_validation(int argc, char *argv[]);
int list_len(Dlist *head);
void remove_pre_zeros(Dlist **head);

/* Arithmetic Operations */
void addition(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
void subtraction(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
void multiplication(Dlist *tail1, Dlist *tail2, Dlist **headR, Dlist **tailR);
void division(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, Dlist **headQ, Dlist **tailQ, Dlist **headRem, Dlist **tailRem);

#endif