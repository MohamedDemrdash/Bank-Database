#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "bank_databas.h"

void creat_account(CLIENT_INFO *client,CLIENT_INFO *all_client,unsigned char *client_num)
{
    unsigned char counter =1;
    char exist = 0;
    char selector;
    if(*client_num < CLIENTS_MAX) //check if there is a space for a new client
    {
        (*client_num)++;
        printf("Please enter the data of the client no. %i \n",*client_num);
        printf("Please enter the id of the client : ");
        fflush(stdin);
        scanf("%u",&(client->id));
        for(counter=0;counter < *client_num-1;counter++)
        {
            if(client->id == (all_client+counter)->id)
            {
                exist++;
                break;
            }
        }
        if(exist != 0)
        {
            (*client_num)--;
            printf("This client is already exist\n");
            printf("If you want to print his data please press 6\n");
            printf("Enter your choice : ");
            fflush(stdin);
            scanf("%c",&selector);
            if(selector == '6')
            {
                print_info((all_client+counter)->id,all_client,*client_num);
            }
        }
        else
        {
            printf("Please enter the name of the client : ");
            fflush(stdin);
            gets(client->name);
            printf("Please enter the amount of money : ");
            fflush(stdin);
            scanf("%lf",& (client->cash));
            printf("Choose the type of the card:\n1-Credit \t2-Debit\n");
            printf("Enter your choice : ");
            fflush(stdin);
            scanf("%c",&selector);
            if(selector == '1')
            {
                strcpy(client->card,"Credit");
            }
            else if(selector == '2')
            {
                strcpy(client->card,"Debit");
            }
            else
            {
                strcpy(client->card,"Credit");
                printf("Warning!!! You have entered an invalid card type --- The default Type is Credit\n");
                printf("If you want to change the type please press 3\n");
                printf("Enter your choice : ");
                fflush(stdin);
                scanf("%c",&selector);
                if(selector == '3')
                {
                    edit_account(client->id,all_client,*client_num);
                }
                else
                {
                    printf("The type of the card is Credit\n");
                }
            }
            printf("Ask the client to set a password for the account : ");
            fflush(stdin);
            gets(client->password);
        }
    }
    else
    {
        printf("!!! THE DATABASE IS FULL YOU CAN'T CREAT A NEW ACCOUNT!!!\n\n\n");
    }
}

void delete_account(CLIENT_INFO *all_client,unsigned char *client_num)
{
    unsigned int client_id;
    unsigned char counter =0;
    char exist = 0;
    char check[9];
    printf("Pleas enter the id : ");
    fflush(stdin);
    scanf("%u",&client_id);
    for(counter=0;counter<*client_num;counter++)
    {
        if(client_id == (all_client+counter)->id)
        {
            exist++;
            break;
        }
    }
    if(exist == 1)
    {
        printf("Please enter the password : ");
        fflush(stdin);
        gets(check);
        printf("\n");
        if(strcmp(check,(all_client+counter)->password) == 0)
        {
            (*client_num)--;
            for(  ;counter<*client_num;counter++)
            {
                (all_client+counter)->id = (all_client+counter+1)->id;
                (all_client+counter)->cash = (all_client+counter+1)->cash;
                strcpy((all_client+counter)->password,(all_client+counter+1)->password);
                strcpy((all_client+counter)->name,(all_client+counter+1)->name);
                strcpy((all_client+counter)->card,(all_client+counter+1)->card);
            }
        }
        else
        {
            printf("The password is incorrect!!!\n");
        }
    }
    else
    {
        printf("Sorry There is no account with this id\n");
    }
}

void edit_account(unsigned int client_id,CLIENT_INFO *all_client,unsigned char client_num)
{
    unsigned char counter =0,counter1 =0;
    char exist = 0;
    char check[9];
    char selector;
    double money;
    for(counter=0;counter<client_num;counter++)
    {
        if(client_id == (all_client+counter)->id)
        {
            exist++;
            break;
        }
    }
    if(exist == 1)
    {
        printf("Please enter the password : ");
        fflush(stdin);
        gets(check);
        printf("\n");
        if(strcmp(check,(all_client+counter)->password) == 0)
        {
            printf("Choose from the following list\n");
            printf("1-change id \n");
            printf("2-change name \n");
            printf("3-withdraw money \n");
            printf("4-Deposit money \n");
            printf("5-change card type \n");
            printf("6-Set a new password \n");
            printf("Enter your choice : ");

            fflush(stdin);
            scanf("%c",&selector);
            switch (selector)
            {
                case '1':
                {
                    printf("Please enter the new id : ");
                    fflush(stdin);
                    scanf("%u",&client_id);
                    for(counter1=0;counter1 < client_num-1;counter1++)
                    {
                        if(client_id == (all_client+counter1)->id)
                        {
                            exist++;
                            break;
                        }
                    }
                    if(exist != 0)
                    {
                        printf("Warnning!!! This id is already exist\n");
                    }
                    else
                    {
                        (all_client+counter)->id = client_id;
                    }
                    break;
                }
                case '2':
                {
                    printf("Please enter the new name : ");
                    fflush(stdin);
                    gets((all_client+counter)->name);
                    break;
                }
                case '3' :
                {
                    printf("Please enter the amount of money to withdraw : ");
                    fflush(stdin);
                    scanf("%lf",&money);
                    if(money > (all_client+counter)->cash )
                    {
                        printf("Sorry the process failed you don't have enough money in your account\n");
                        printf("Your cash is : %lf",(all_client+counter)->cash);
                    }
                    else
                    {
                        (all_client+counter)->cash -= money;
                    }
                    break;
                }
                case '4' :
                {
                    printf("Please enter the amount of money to withdraw : ");
                    fflush(stdin);
                    scanf("%lf",&money);
                    (all_client+counter)->cash += money;
                    break;
                }
                case '5' :
                {
                    printf("Choose the type of the card:\n1-Credit \t2-Debit\n");
                    printf("Enter your choice : ");
                    fflush(stdin);
                    scanf("%c",&selector);
                    if(selector == '1')
                    {
                        strcpy((all_client+counter)->card,"Credit");
                    }
                    else if(selector == '2')
                    {
                        strcpy((all_client+counter)->card,"Debit");
                    }
                    else
                    {
                        strcpy((all_client+counter)->card,"Credit");
                        printf("Warning!!! You have entered an invalid card type --- The default Type is Credit\n");
                    }
                    break;
                }
                case '6' :
                {
                    printf("Please enter the new name : ");
                    fflush(stdin);
                    gets((all_client+counter)->name);
                    break;
                }
                default :
                {
                    printf("!!! YOU HAVE ENTERD AN INVALID NUMBER !!! \n\n\n");
                }
            }

        }
        else
        {
            printf("The password is incorrect!!!\n");
        }
    }
    else
    {
        printf("Sorry There is no account with this id\n");
    }
}

void cash_transfer(CLIENT_INFO *all_client,unsigned char client_num)
{
    unsigned int client_id,client1_id;
    unsigned char counter =0,counter1 =0;
    char exist = 0;
    char check[9];
    double money;
    printf("Pleas enter the id of source account : ");
    fflush(stdin);
    scanf("%u",&client_id);
    for(counter=0;counter<client_num;counter++)
    {
        if(client_id == (all_client+counter)->id)
        {
            exist++;
            break;
        }
    }
    if(exist == 1)
    {
        printf("Please enter the password : ");
        fflush(stdin);
        gets(check);
        if(strcmp(check,(all_client+counter)->password) == 0)
        {
            printf("Pleas enter the id of destination account : ");
            fflush(stdin);
            scanf("%u",&client1_id);
            for(counter1=0;counter1<client_num;counter1++)
            {
                if(client1_id == (all_client+counter1)->id)
                {
                    exist++;
                    break;
                }
            }
            if(exist == 2)
            {
                printf("Please enter the amount of money to transfer : ");
                fflush(stdin);
                scanf("%lf",&money);
                if(money > (all_client+counter)->cash )
                {
                    printf("Sorry the process failed you don't have enough money in your account\n");
                    printf("Your cash is : %lf",(all_client+counter)->cash);
                }
                else
                {
                    (all_client+counter)->cash -= money;
                    (all_client+counter1)->cash += money;
                }
            }
            else
            {
                printf("Sorry There is no account with this id\n");
            }
        }
        else
        {
            printf("The password is incorrect!!!\n");
        }
    }
    else
    {
        printf("Sorry There is no account with this id\n");
    }
}
void print_info(unsigned int client_id,CLIENT_INFO *all_client,unsigned char client_num)
{
    unsigned char counter =0;
    char exist = 0;
    char check[9];
    for(counter=0;counter<client_num;counter++)
    {
        if(client_id == (all_client+counter)->id)
        {
            exist++;
            break;
        }
    }
    if(exist == 1)
    {
        printf("Please enter the password : ");
        fflush(stdin);
        gets(check);
        printf("\n");
        if(strcmp(check,(all_client+counter)->password) == 0)
        {
            printf("*Information of client no. %i :-\n",counter+1);
            printf("The client name is : %s\n",(all_client+counter)->name);
            printf("The client id is : %u\n",(all_client+counter)->id);
            printf("The cash at the account is : %lf\n",(all_client+counter)->cash);
            printf("The Card type is : %s\n",(all_client+counter)->card);
        }
        else
        {
            printf("The password is incorrect!!!\n");
        }
    }
    else
    {
        printf("Sorry There is no account with this id\n");
    }
}
