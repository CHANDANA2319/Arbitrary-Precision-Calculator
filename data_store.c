#include "main.h"
int data_store_operand1(Dlist **head, Dlist **tail, char *str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {
        if(str[0] == '-' || str[0] == '+')
        {
            if(i == 0)
            {
                continue;
            }
        }

        if(str[i] >= '0' && str[i] <= '9')
        {
            int data = str[i] - '0';

            if(dl_insert_last(head, tail, data) == FAILURE)
            {
                return FAILURE;
            }
        }
        else
        {
            return INVALID;
        }
    }

    return SUCCESS;
}

int data_store_operand2(Dlist **head, Dlist **tail,char* str1)
{

for(int i = 0; str1[i] != '\0'; i++)
    {
        if(str1[0] == '-' || str1[0] == '+')
        {
            if(i == 0)
            {
                continue;
            }
        }

        if(str1[i] >= '0' && str1[i] <= '9')
        {
            int data = str1[i] - '0';

            if(dl_insert_last(head, tail, data) == FAILURE)
            {
                return FAILURE;
            }
        }
        else
        {
            return INVALID;
        }
    }

    return SUCCESS;
}