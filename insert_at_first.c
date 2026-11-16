#include "main.h"

int dl_insert_first(Dlist **headR, Dlist **tailR, int data)
{
  Dlist *newNode=malloc(sizeof(Dlist));
  if(newNode==NULL){
      return FAILURE;
  }
  newNode->data=data;
  newNode->prev=NULL;
  newNode->next=NULL;
  if(*headR==NULL){
      *headR=newNode;
      *tailR=newNode;
      return SUCCESS;
      
  }
  newNode->next=*headR;
  
  (*headR)->prev=newNode;
  *headR=newNode;
  return SUCCESS;
 
}