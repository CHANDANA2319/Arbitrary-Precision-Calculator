#include "main.h"

int dl_delete_list(Dlist **head, Dlist **tail)
{
if(*head==NULL){
    return FAILURE;
}
Dlist* temp=*head;
Dlist* prev;
while(temp!=NULL){
    prev=temp;
    temp=temp->next;
    free(prev);
}
*head=NULL;
*tail=NULL;
return SUCCESS;
}