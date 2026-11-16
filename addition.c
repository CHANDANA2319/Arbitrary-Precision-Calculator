#include "main.h"
int addition(Dlist **headR,Dlist ** tailR,Dlist **head1,Dlist ** tail1,Dlist **head2,Dlist ** tail2){
   
    Dlist* temp1=*tail1;
    Dlist* temp2=*tail2;
   
    int data;
    int carry=0;
    while(temp1 || temp2){
        if(temp1 && temp2){
            data=temp1->data+temp2->data+carry;
            temp1=temp1->prev;
            temp2=temp2->prev;
        }
        else if(temp1 && temp2==NULL){
            data=temp1->data+carry;
            temp1=temp1->prev;
        }
        else{
            data=temp2->data+carry;
            temp2=temp2->prev;
        }
        if(carry==1){
            carry=0;
        }
        
        if(dl_insert_first(headR, tailR, data%10)==FAILURE){
            return FAILURE;
        }
            carry=data/10;
        
    }
    if(carry==1){
        if(dl_insert_first(headR, tailR, carry)==FAILURE){
            return FAILURE;
        }
    }
    remove_zeros(headR, tailR);
    
    return SUCCESS;

}