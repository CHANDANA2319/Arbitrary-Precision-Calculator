#include "main.h"
int flag;
int result_list(Dlist **headR,Dlist ** tailR,Dlist **head1,Dlist ** tail1,Dlist **head2,Dlist ** tail2,Dlist** headR1,Dlist** tailR1,Dlist** headR2,Dlist** tailR2,Dlist** head3,Dlist** tail3,char* oper,char sign1,char sign2){
   if(sign1=='-' && sign2=='+' && oper[0]=='-'){
    oper[0]='+';
   }
   else if(sign1=='-' && sign2=='+' && oper[0]=='+'){
    oper[0]='-';
   }
   else if(sign1=='+' && sign2=='-' && oper[0]=='-'){
    oper[0]='+';
   }
   else if(sign1=='+' && sign2=='-' && oper[0]=='+'){
    oper[0]='-';
   }
    Dlist* temp1=*tail1;
    Dlist* temp2=*tail2;
    if(oper[0]=='+'){
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
    signs(sign1,sign2,oper,headR,headR1);
    
    return SUCCESS;
}
// substarction
else if(oper[0] == '-')
{
    int compare = list_compare(head1, head2);

    if(compare == 2)
    {
        if(dl_insert_first(headR, tailR, 0) == FAILURE)
        {
            return FAILURE;
        }
    }
    else if(compare == 1)
    {
        // Operand 1 is greater than operand 2
        flag = 0;

        if(Sub(headR, tailR, head1, tail1,
               head2, tail2, oper, flag) == FAILURE)
        {
            return FAILURE;
        }
    }
    else
    {
        // Operand 2 is greater than operand 1
        flag = 1;

        if(Sub(headR, tailR, head2, tail2,
               head1, tail1, oper, flag) == FAILURE)
        {
            return FAILURE;
        }
    }
   remove_zeros(headR, tailR);
  signs(sign1,sign2,oper,headR,headR1);

 
    return SUCCESS;
}

else if(oper[0]=='x'){
    Dlist* temp2=*tail2;
    int count=0;
    
    while(temp2!=NULL){
    int carry=0;
      Dlist* temp1=*tail1;
      for(int i=0;i<count;i++){
        dl_insert_first(headR2, tailR2, 0);
      }
      while(temp1!=NULL){
       int  data=temp1->data*temp2->data+carry;
       carry=0;
       if(count==0){
       dl_insert_first(headR1, tailR1, data%10);
      }
      else {
        dl_insert_first(headR2, tailR2, data%10);
        
     

       
      }
      carry=data/10;
      temp1=temp1->prev;
    }
    if (carry != 0)
{
    if (count == 0)
    {
        dl_insert_first(headR1, tailR1, carry);
    }
    else
    {
        dl_insert_first(headR2, tailR2, carry);
    }
}
    if(count!=0){
     if(addition(headR,tailR,headR1,tailR1,headR2,tailR2)==FAILURE){
        return FAILURE;
     }
     if(dl_delete_list(headR1, tailR1)==FAILURE){
        return FAILURE;
     }
     *headR1=*headR;
     *tailR1=*tailR;
     *headR=NULL;
     *tailR=NULL;
      if(dl_delete_list(headR2, tailR2)==FAILURE){
        return FAILURE;
     }

    }
   
    


    temp2=temp2->prev;
    count++;
}


   remove_zeros(headR, tailR); 
    signs(sign1,sign2,oper,headR,headR1);
return SUCCESS;
}


else if(oper[0]=='/')
{
    Dlist* temp1 = *head2;
    int list2_data = 0;

    while(temp1 != NULL)
    {
        list2_data = list2_data * 10 + temp1->data;
        temp1 = temp1->next;
    }

    if(list2_data == 0)
    {
        printf("We can't divide by zero\n");
        return FAILURE;
    }

    Dlist* temp2 = *head1;
    int list1_data = 0;

    while(temp2 != NULL)
    {
        list1_data = list1_data * 10 + temp2->data;
        temp2 = temp2->next;
    }

    if(list1_data == 0)
    {
        if(dl_insert_last(headR1, tailR1, 0) == FAILURE)
        {
            return FAILURE;
        }
        return SUCCESS;
    }

    Dlist* tempR = *head1;

    while(tempR != NULL)
    {
        if(dl_insert_last(head3, tail3, tempR->data) == FAILURE)
        {
            return FAILURE;
        }

        tempR = tempR->next;

        remove_zeros(head3, tail3);

        int list3_data = 0;
        Dlist* temp3 = *head3;

        while(temp3 != NULL)
        {
            list3_data = list3_data * 10 + temp3->data;
            temp3 = temp3->next;
        }

        int count_result = 0;

        while(list3_data >= list2_data)
        {
            flag = 0;

            if(Sub(headR, tailR, head3, tail3,
                   head2, tail2, "-", flag) == FAILURE)
            {
                return FAILURE;
            }

            if(dl_delete_list(head3, tail3) == FAILURE)
            {
                return FAILURE;
            }

            *head3 = *headR;
            *tail3 = *tailR;

            *headR = NULL;
            *tailR = NULL;

            count_result++;

            list3_data = 0;
            temp3 = *head3;

            while(temp3 != NULL)
            {
                list3_data = list3_data * 10 + temp3->data;
                temp3 = temp3->next;
            }
        }

        if(dl_insert_last(headR1, tailR1, count_result) == FAILURE)
        {
            return FAILURE;
        }
    }

    remove_zeros(headR1, tailR1);

    signs(sign1, sign2, oper, headR, headR1);

    return SUCCESS;
}

    


}

