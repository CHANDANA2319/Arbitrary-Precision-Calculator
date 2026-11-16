#include "main.h"
#include <string.h>

int validate_input(char *str)
{
    int i = 0;

    if (str[i] == '+' || str[i] == '-')
        i++;

    if (str[i] == '\0')
        return INVALID;

    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
            return INVALID;

        i++;
    }

    return SUCCESS;
}

int main(int argc, char *argv[])
{
    if (argc != 4)
    {
        printf("Invalid input\n");
        return FAILURE;
    }

    if (validate_input(argv[1]) == INVALID ||
        validate_input(argv[3]) == INVALID)
    {
        printf("Invalid input\n");
        return FAILURE;
    }

    if (strcmp(argv[2], "+") != 0 &&
        strcmp(argv[2], "-") != 0 &&
        strcmp(argv[2], "x") != 0 &&
        strcmp(argv[2], "/") != 0)
    {
        printf("Invalid input\n");
        return FAILURE;
    }

    char sign1 = (argv[1][0] == '-') ? '-' : '+';
    char sign2 = (argv[3][0] == '-') ? '-' : '+';

    Dlist *head1 = NULL, *tail1 = NULL;
    Dlist *head2 = NULL, *tail2 = NULL;
    Dlist *head3 = NULL, *tail3 = NULL;
    Dlist *headR = NULL, *tailR = NULL;
    Dlist *headR1 = NULL, *tailR1 = NULL;
    Dlist *headR2 = NULL, *tailR2 = NULL;

    if (data_store_operand1(&head1, &tail1, argv[1]) != SUCCESS)
    {
        printf("Invalid input\n");
        return FAILURE;
    }

    if (data_store_operand1(&head2, &tail2, argv[3]) != SUCCESS)
    {
        printf("Invalid input\n");
        return FAILURE;
    }

    if (result_list(&headR, &tailR,&head1, &tail1,&head2, &tail2,&headR1, &tailR1,&headR2, &tailR2,&head3, &tail3,argv[2], sign1, sign2) == SUCCESS)
    {
        if (strcmp(argv[2], "x") == 0 ||strcmp(argv[2], "/") == 0)
        {
            print_list(headR1);
        }
        else
        {
            print_list(headR);
        }
    }
    else
{
    return FAILURE;
}

    return SUCCESS;
}