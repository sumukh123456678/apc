 #include<stdio.h>
 #include "APC.h"
 #include <string.h>
 #include<stdlib.h>

 Dlist * subtraction(Dlist *head1,Dlist *tail1, Dlist *head2, Dlist *tail2){
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
    printf("in sub\n");
    print_func(res_head);
    
return res_head;

 }

int compare_num(char *num1,char *num2,int *sign){
    while(*num1=='0' && *(num1+1))num1++;
    while(*num2=='0' && *(num2+1))num2++;
    int len1=strlen(num1);
    int len2=strlen(num2);
    if(len1>len2){
        *sign=1;
        return 1;
    }
    else if(len1<len2){
        *sign=-1;
        return -1;
    }
    else{
        for(int i=0;i<len1;i++){
            if(num1[i]>num2[i]){
                *sign=1;
                return 1;
            }
            else if(num1[i]<num2[i]){
                *sign=-1;
                return -1;
            }
        }
    }
    *sign=1;
    return 0;
}