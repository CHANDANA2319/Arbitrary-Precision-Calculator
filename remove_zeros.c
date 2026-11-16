
#include "main.h"

void remove_zeros(Dlist **headR, Dlist **tailR)
{
    if (*headR == NULL)
    {
        return;
    }

    while (*headR != NULL &&
           (*headR)->data == 0 &&
           *headR != *tailR)
    {
        Dlist *temp = *headR;

        *headR = (*headR)->next;
        (*headR)->prev = NULL;

        free(temp);
    }

   
}
