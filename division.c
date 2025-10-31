#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "APC.h"
#include <stdbool.h>
int remove_zeros(Dlist **head){
    Dlist *temp=*head;
    if(*head==NULL){
        return 0;
    }

    
    while(temp && temp->data==0 && temp->next!=NULL){
        Dlist *new=temp;
        temp=temp->next;
        temp->prev=NULL;
        free(new);
    

    }
    *head=temp;
    return 0;
    }
    
            
int get_length(Dlist *head)
{
    Dlist *temp = head;
    int count = 0;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
Dlist *get_tail(Dlist *head)
{
    Dlist *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp;
}
int compare(Dlist *head1, Dlist *head2)
{

    
    int numerator1 = get_length(head1);
    
    int denominator = get_length(head2);
    
    if(numerator1 > denominator)
    //printf("hello");
    {
      // printf("numerator is big\n");
        return 1;
    }
    if(denominator > numerator1)
    {
       printf("the quotient = 0\n");
       exit(0);
        
    }
  
        Dlist *temp = head1;
        Dlist *temp1 = head2;
    while (temp && temp1)
        {

            if (temp->data > temp1->data)
            {
                return 1;
            }
            else if (temp->data < temp1->data)
            {
                return 0;
            }
            temp = temp->next;
            temp1 = temp1->next;
        }
        return 0;
    }
    


Dlist *subtraction1(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2){
    Dlist *res_head=NULL;
     Dlist *res_tail=NULL;
     //printf("HJLLOE");

    int difference;
    int borrow=0;
    

    while(tail1|| tail2)
    {
        int data1=0,data2=0;
        
        if(tail1){
            data1=(tail1->data)-borrow;
            tail1=tail1->prev;
        } 
        else{
            data1=-borrow;
        }
        if(tail2){
            data2=tail2->data;
            tail2=tail2->prev;
        }
        if(data1<data2){
            difference=(data1+10)-data2;
            borrow=1;
        }
        else{
            difference=data1-data2;
            borrow=0;
        }
        Dlist *new=malloc(sizeof(Dlist));
        if(new==NULL){
            printf("ERROR:");
            return 0;
        }
        new->data=difference;
        new->prev=NULL;
        new->next=NULL;
        if(res_head==NULL){
            res_head=res_tail=new;
        }
        else{
            new->next=res_head;
            res_head->prev=new;
            res_head=new;
        }
}
return res_head;
}
    

int division(Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2)
{
    if(head2==NULL || head2->data==0 && head2->next==NULL){
        printf("there is an error in the division code");
        return 0;
    }

    Dlist *numerator=head1;
    Dlist *denominator=head2;
    int count=1;
    remove_zeros(&numerator);
    remove_zeros(&denominator);

    while(compare(numerator,denominator)){
        

        numerator=subtraction1(numerator,get_tail(numerator),denominator,tail2);
        remove_zeros(&numerator);
        count++;
        
    }
    
    printf("the quotient = %d\n",count);

    return count;
}
    
    