#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "APC.h"




void print_list(Dlist *head) {
    while (head) {
        printf("%d", head->data);
        head = head->next;
    }
    printf("\n");
}


void free_list(Dlist *head) {
    while (head) {
        Dlist *temp = head;
        head = head->next;
        free(temp);
    }
}


Dlist* get_tail1(Dlist *head) {
    while (head && head->next)
        head = head->next;
    return head;
}


int multiply(Dlist *tail1, int digit, Dlist **res_head, Dlist **res_tail) {
    *res_head = NULL;
    *res_tail = NULL;
    int carry = 0;

    while (tail1) {
        int mul = (tail1->data * digit) + carry;
        carry = mul / 10;

        Dlist *new = malloc(sizeof(Dlist));
        if (!new){
         return 0;
        }
        new->data = mul % 10;
        new->prev = NULL;
        new->next = *res_head;
        if (*res_head){
            (*res_head)->prev = new;
        }
        else
            *res_tail = new;
        *res_head = new;

        tail1 = tail1->prev;
    }

    if (carry) {
        Dlist *new = malloc(sizeof(Dlist));
        if(!new) {
            return 0;
        }
        new->data=carry;
        new->prev=NULL;
        new->next = *res_head;
        if (*res_head){
            (*res_head)->prev = new;
        }
        else
            *res_tail = new;
        *res_head = new;
    }

    return SUCCESS;
}


Dlist* addition1(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2) {
    Dlist *res_head=NULL;
    Dlist *res_tail=NULL;

    int sum=0;
    int carry=0;
    while(tail1||tail2){
        sum=carry;
    Dlist *new=malloc(sizeof(Dlist));
    if(new==NULL){
        printf("node is empty");
        return 0;
    }
    new->prev=NULL;
    new->next=NULL;
   
    if(tail1){

    sum+=tail1->data;
    tail1=tail1->prev;
    
    }
    if(tail2){
    sum+=tail2->data;
    tail2=tail2->prev;
    }
    //sum+=carry;
      
   
    if(sum>=10){
        new->data=sum%10;
        carry=sum/10;
        
    }
    else{
        carry=0;
        new->data=sum;
    }

    if(res_head==NULL){
        res_head=res_tail=new;
       // return 0;
    }
    else{
        new->next=res_head;
        res_head->prev=new;
        res_head=new;
    }
}
}


Dlist* multiplication(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2) {
    Dlist *res_head1 = NULL, *res_tail1 = NULL;
    Dlist *res_head2 = NULL, *res_tail2 = NULL;

    int shift = 0;

    while (tail2) {
        if (shift == 0) {
            multiply(tail1, tail2->data, &res_head1, &res_tail1);
        } else {
            multiply(tail1, tail2->data, &res_head2, &res_tail2);

            // Add trailing zeroes
            for (int i = 0; i < shift; i++) {
                Dlist *zero = malloc(sizeof(Dlist));
                if (!zero) return 0;
                zero->data = 0;
                zero->prev = NULL;
                zero->next = NULL;
                if (res_tail2) {
                    res_tail2->next = zero;
                    zero->prev = res_tail2;
                    res_tail2 = zero;
                } else {
                    res_head2 = res_tail2 = zero;
                }
            }

            Dlist *sum = addition1(res_head1, get_tail1(res_head1), res_head2, get_tail1(res_head2));
            free_list(res_head1);
            free_list(res_head2);
            res_head1 = sum;
            res_tail1 = get_tail1(res_head1);
        }

        tail2 = tail2->prev;
        res_head2 = res_tail2 = NULL;
        shift++;
    }
    
    printf("Result: ");
    print_list(res_head1);

}

