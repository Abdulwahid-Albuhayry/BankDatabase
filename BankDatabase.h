#ifndef BANKDATABASE_H
#define BANKDATABASE_H

#define CLIENTS_NO 3


typedef unsigned char u8;
typedef signed char s8;
typedef unsigned int u32;
typedef signed int s32;
typedef double f64;


//bank will have many clients so it will be an array of client structures
typedef struct client
{
    u8 name[55];
    f64 cash;
    u8 type[7];       //debit or credit
    u32 id;             //special integers for every client
}client_t;



////linked list instead of array
////linked list adv. it's not a fixed size unlike array
////linked list adv. in deleting element we make a pointer to point to another location instead of locationA and then locationA is now deleted unlike array it's done by deleting an element and then making shift to other elements
//typedef struct client
//{
//    client_t client;
//    client_t* ptr;
//}client_t;


//client_t Bank_DataBase_Arr[CLIENTS_NO];


void Bank_void_Create_New_Client(void);
void Bank_void_Edit_Client_Data(u32 Copy_u32Client_Id);
void Bank_void_Print_Client_Data(u32 Copy_u32Client_Id);
void Bank_void_Transfer_Money(u32 Copy_u32SrcClient_Id, u32 Copy_u32DestClient_Id, f64 Copy_f64Money);
void Bank_void_Delete_Client_Data(u32 Copy_u32Client_Id);

#endif // BANKDATABASE_H
