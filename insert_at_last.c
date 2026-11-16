#include "main.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    Dlist *newNode=malloc(sizeof(Dlist));
    if(newNode==NULL){
        printf("Memory allocation failed");
        return FAILURE;
    }
    newNode->data=data;
    newNode->prev=NULL;
    newNode->next=NULL;
    if((*head)==NULL || (*tail)==NULL){
        *head=newNode;
        *tail=newNode;
        return SUCCESS;
    }
    else{
        newNode->prev=(*tail);
        (*tail)->next=newNode;
        (*tail)=newNode;
        return SUCCESS;
    }
    return FAILURE;
}







