typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;
#define SUCCESS 0
#define FAILURE -1

Dlist *addition(Dlist *head1,Dlist *tail1, Dlist *head2, Dlist *tail2);
Dlist *subtraction(Dlist *head1,Dlist *tail1, Dlist *head2, Dlist *tail2);
int compare_num(char *num1,char *num2,int *sign);
Dlist *multiplication(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2);
int division(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2);
int print_func(Dlist *head);