#ifndef DLL_H
#define DLL_L

#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define INVALID 2

typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;




int data_store_operand1(Dlist **head, Dlist **tail, char* str);
int data_store_operand2(Dlist **head, Dlist **tail, char* str1);
void signs(char sign1,char sign2,char* oper,Dlist** headR,Dlist** headR1);

int dl_insert_last(Dlist **head, Dlist **tail, int data);
int result_list(Dlist **headR,Dlist ** tailR,Dlist **head1,Dlist ** tail1,Dlist **head2,Dlist ** tail2,Dlist** headR1,Dlist** tailR1,Dlist** headR2,Dlist** tailR2,Dlist** head3,Dlist** tail3,char* oper,char sign1,char sign2);
   
int dl_insert_first(Dlist **headR, Dlist **tailR, int data);
int list_compare(Dlist ** head1,Dlist **head2);
int Sub(Dlist **headR,Dlist ** tailR,Dlist **head1,Dlist ** tail1,Dlist **head2,Dlist ** tail2,char* oper,int flag);
void remove_zeros(Dlist **headR,Dlist **tailR);
int dl_delete_list(Dlist **head, Dlist **tail);
int addition(Dlist **headR,Dlist ** tailR,Dlist **head1,Dlist ** tail1,Dlist **head2,Dlist ** tail2);
void print_list(Dlist *head);
#endif