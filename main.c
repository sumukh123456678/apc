#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "APC.h" // Your header with Dlist, addition(), subtraction(), etc.

int print_func(Dlist *head)
{
    Dlist *temp = head;
    while (temp != NULL)
    {
        printf("%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Usage: %s <number1> <operator> <number2>\n", argv[0]);
        return 1;
    }

    int sign1 = 1, sign2 = 1;
    char *num1 = argv[1];
    char *num2 = argv[3];

    // Handle signs
    if (num1[0] == '-')
    {
        sign1 = -1;
        num1++;
    }
    if (num2[0] == '-')
    {
        sign2 = -1;
        num2++;
    }

    // Create linked lists directly from num1 and num2 (your original style)
    Dlist *head1 = NULL;
    Dlist *tail1 = NULL;
    Dlist *head2 = NULL;
    Dlist *tail2 = NULL;
    Dlist *res_head = NULL;

    for (int i = 0; i < strlen(num1); i++)
    {
        Dlist *op1 = malloc(sizeof(Dlist));
        op1->data = num1[i] - '0';
        op1->prev = op1->next = NULL;

        if (head1 == NULL)
            head1 = tail1 = op1;
        else
        {
            tail1->next = op1;
            op1->prev = tail1;
            tail1 = op1;
        }
    }

    for (int i = 0; i < strlen(num2); i++)
    {
        Dlist *op2 = malloc(sizeof(Dlist));
        op2->data = num2[i] - '0';
        op2->prev = op2->next = NULL;

        if (head2 == NULL)
            head2 = tail2 = op2;
        else
        {
            tail2->next = op2;
            op2->prev = tail2;
            tail2 = op2;
        }
    }

    char oper = argv[2][0];

    if (oper == '+')
    {
        if (sign1 == sign2)
        {
            if (sign1 == -1)
                printf("-");
            addition(head1, tail1, head2, tail2);
        }
        else
        {
            int sign = 1;
            int cmp = compare_num(num1, num2, &sign);

            if (cmp == 0)
            {
                printf("0\n");
            }
            else if (cmp > 0)
            {
                if (sign1 == -1)
                    printf("-");
                res_head = subtraction(head1, tail1, head2, tail2);
                print_func(res_head);
            }
            else
            {
                if (sign2 == -1)
                    printf("-");
                res_head = subtraction(head2, tail2, head1, tail1);
                print_func(res_head);
            }
        }
    }
    else if (oper == '-')
    {
        // Convert subtraction to addition by flipping sign of second number
        sign2 *= -1;

        if (sign1 == sign2)
        {
            if (sign1 == -1)
                printf("-");
            addition(head1, tail1, head2, tail2);
        }
        else
        {
            int sign = 1;
            int cmp = compare_num(num1, num2, &sign);

            if (cmp == 0)
            {
                printf("0\n");
            }
            else if (cmp > 0)
            {
                if (sign1 == -1)
                    printf("-");
                res_head = subtraction(head1, tail1, head2, tail2);
                print_func(res_head);
            }
            else
            {
                if (sign2 == -1)
                    printf("-");
                res_head = subtraction(head2, tail2, head1, tail1);
                print_func(res_head);
            }
        }
    }
    else if (oper == 'x')
    {
        if (sign1 * sign2 == -1)
            printf("-");
        multiplication(head1, tail1, head2, tail2);
    }
    else if (oper == '/')
    {
        if (sign1 * sign2 == -1)
            printf("-");
        division(head1, tail1, head2, tail2);
    }
    else
    {
        printf("Unsupported operator. Use +, -, x, or /.\n");
        return 1;
    }

    return 0;
}
