#include "main.h"
int list_compare(Dlist ** head1,Dlist **head2){
    int list_count1=0,list_count2=0;
    Dlist* temp1=*head1;
    Dlist* temp2=*head2;
    while(temp1!=NULL){
        list_count1++;
        temp1=temp1->next;
    }
    while(temp2!=NULL){
        list_count2++;
        temp2=temp2->next;
    }
    if(list_count1>list_count2){
        return 1;

    }
    else if(list_count1<list_count2){
    return 0;
    }
    else {
            temp1 = *head1;
            temp2 = *head2;

while (temp1 != NULL && temp2 != NULL)
{
    if (temp1->data > temp2->data)
        return 1;

    if (temp1->data < temp2->data)
        return 0;

    temp1 = temp1->next;
    temp2 = temp2->next;
}

return 2;
}
}



int Sub(Dlist **headR, Dlist **tailR,Dlist **head1, Dlist **tail1,Dlist **head2, Dlist **tail2, char *oper,int flag)
{
    int data;
    int borrow = 0;

    Dlist *temp1 = *tail1;
    Dlist *temp2 = *tail2;

    while (temp1 != NULL)
    {
        int d1 = temp1->data;
        int d2 = 0;

        if (temp2 != NULL)
        {
            d2 = temp2->data;
            temp2 = temp2->prev;
        }

        data = d1 - d2 - borrow;

        if (data < 0)
        {
            data += 10;
            borrow = 1;
        }
        else
        {
            borrow = 0;
        }
        
        if (dl_insert_first(headR, tailR, data) == FAILURE)
        {
            return FAILURE;
        }

        temp1 = temp1->prev;
    }
    remove_zeros(headR, tailR);
    
    if(flag==1){
        (*headR)->data=(*headR)->data*-1;
    }
    
       
   

    return SUCCESS;
}



