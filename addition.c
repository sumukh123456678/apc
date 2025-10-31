#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "APC.h"

Dlist *addition(Dlist *head1,Dlist *tail1,Dlist *head2,Dlist *tail2){

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
if(carry){
    Dlist *new=malloc(sizeof(Dlist));
    new->data=carry;
    new->prev=NULL;
    new->next=res_head;
    if(res_head){
        res_head->prev=new;
        res_head=new;
    }
    else{
        res_head=res_tail=new;
    }
}
printf("the res is :");

Dlist *temp=res_head;
while(temp!=NULL){
    printf("%d",temp->data);
   // printf("\nworld");
    temp=temp->next;
}
printf("\n");




}