#ifndef GUARD
#define GUARD

#define CLIENTS_MAX 3

typedef struct
{
    char name[20];
    unsigned int id;
    double cash;
    char card[7];
    char password[9];
}CLIENT_INFO;

void creat_account(CLIENT_INFO *client,CLIENT_INFO *all_client,unsigned char *client_num);

void delete_account(CLIENT_INFO *all_client,unsigned char *client_num);

void edit_account(unsigned int client_id,CLIENT_INFO *all_client,unsigned char client_num);

void cash_transfer(CLIENT_INFO *all_client,unsigned char client_num);

void print_info(unsigned int client_id,CLIENT_INFO *all_client,unsigned char client_num);

#endif // GUARD
