#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank_databas.h"

CLIENT_INFO client[CLIENTS_MAX];

int main()
{
    unsigned char client_num = 0;
    unsigned int client_id;
    char work =1;
    char selector;

    printf("WELCOME TO THE SYSTEM\n\n");

    while(work)
    {
        printf("1-To create a new account please press 1 \n");
        printf("2-To delete an account please press 2 \n");
        printf("3-To edit data of certain account please press 3 \n");
        printf("4-To transfer cash from an account to another one please press 4 \n");
        printf("5-To print the information of an account please press 5 \n");
        printf("6-To exit from the system please press 6 \n");
        printf("Enter your choice : ");

        fflush(stdin);
        scanf("%c",&selector);
        printf("\n\n");
        switch (selector)
        {
            case '1':
                {
                    creat_account(&client[client_num],client,&client_num);
                    break;
                }
            case '2':
                {
                    if(client_num == 0)
                    {
                        printf("!!!THERE IS NO CLIENT YET!!!\n");
                    }
                    else
                    {
                        delete_account(client,&client_num);
                    }
                    break;
                }
            case '3':
                {
                    if(client_num == 0)
                    {
                        printf("!!!THERE IS NO CLIENT YET!!!\n");
                    }
                    else
                    {
                        printf("Pleas enter the id : ");
                        fflush(stdin);
                        scanf("%u",&client_id);
                        edit_account(client_id,client,client_num);
                    }
                    break;
                }
            case '4':
                {
                    if(client_num == 0)
                    {
                        printf("!!!THERE IS NO CLIENT YET!!!\n");
                    }
                    else
                    {
                        cash_transfer(client,client_num);
                    }
                    break;
                }
            case '5':
                {
                    if(client_num == 0)
                    {
                        printf("!!!THERE IS NO CLIENT YET!!!\n");
                    }
                    else
                    {
                        printf("Pleas enter the id : ");
                        fflush(stdin);
                        scanf("%u",&client_id);
                        print_info(client_id,client,client_num);
                    }
                    break;
                }
            case '6':
                {
                    work = 0;
                    printf("*-*SEE YOU SOON*-*\n");
                    break;
                }
            default:
                {
                    printf("!!! PLEAS ENTER A VALID NUMBER !!! \n\n\n");
                }

        }
        printf("\t\t--------------\n\n");
    }
    return 0;
}
