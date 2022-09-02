#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "BankDatabase.h"


client_t client1,client2,client3;
//client_t StructDataSetArr[CLIENTS_NO]={client1,client2,client3};

client_t Bank_DataBase_Arr[CLIENTS_NO];

u32 CountCreatedClients=0;

void Bank_void_Create_New_Client(void)
{
    //static u32 CountCreatedClients=0;
    #if (CLIENTS_NO>=1&&CLIENTS_NO<=3)
        if(CountCreatedClients<CLIENTS_NO)
        {
            client_t StructDataSetArr[CLIENTS_NO]={client1,client2,client3};
            Bank_DataBase_Arr[CountCreatedClients]=StructDataSetArr[CountCreatedClients];
            fflush(stdin);
            printf("enter name of client No. %u: ",CountCreatedClients+1);
            gets(&(Bank_DataBase_Arr[CountCreatedClients].name));
            printf("enter cash amount of client No. %u: ",CountCreatedClients+1);
            scanf("%lf",&(Bank_DataBase_Arr[CountCreatedClients].cash));
            fflush(stdin);
            printf("enter type of client No. %u: ",CountCreatedClients+1);
            gets(&(Bank_DataBase_Arr[CountCreatedClients].type));
            printf("enter id of client No. %u: ",CountCreatedClients+1);
            scanf("%u",&(Bank_DataBase_Arr[CountCreatedClients].id));
        }
        else
        {
            printf("Number of clients to add is up to 3\n");
        }
    CountCreatedClients++;  //if user entered data of a client count is increased by 1
    #else
    printf("Number of clients to add is up to 3\n");
    #endif
}

void Bank_void_Edit_Client_Data(u32 Copy_u32Client_Id)
{
    static volatile u32 Loc_count;
    u8 Loc_IsClientFound;
    u8 Loc_ReadUserChoice_DataEdit;
    u8 Loc_ContinueEdit=1;
    #if (CLIENTS_NO>=1&&CLIENTS_NO<=3)
    for(Loc_count=0;Loc_count<CLIENTS_NO;Loc_count++)
    {
        if(Bank_DataBase_Arr[Loc_count].id == Copy_u32Client_Id)
        {
            Loc_IsClientFound=1;
            break;
        }
        else
        {
            Loc_IsClientFound=0;
        }
    }
    switch(Loc_IsClientFound)
    {
        case 1:
            printf("Here is the data of the client whose (Client ID is %u):\n",Copy_u32Client_Id);
            printf("Client ID:%u\n",Bank_DataBase_Arr[Loc_count].id);
            printf("Client Name:%s\n",Bank_DataBase_Arr[Loc_count].name);
            printf("Client Type:%s\n",Bank_DataBase_Arr[Loc_count].type);
            printf("Client Cash:%lf\n",Bank_DataBase_Arr[Loc_count].cash);
            while(Loc_ContinueEdit)
            {
                printf("**************************************************\n");
                printf("Enter\n1 for editing client ID.\n2 for editing client Name.\n3 for editing client cash amount.\n4 for editing client Type.\n0 for quiting without editing client data.\n");
                printf("**************************************************\n");
                scanf("%i",&Loc_ReadUserChoice_DataEdit);
                Loc_ContinueEdit=Loc_ReadUserChoice_DataEdit;
                switch(Loc_ReadUserChoice_DataEdit)
                {
                    case 0:
                        printf("quiting without editing client data...\n");
                        Loc_ContinueEdit=0;
                    break;
                    case 1:
                        printf("enter the new ID for this client whose ID is: %u\n", Copy_u32Client_Id);
                        fflush(stdin);
                        scanf("%u",&(Bank_DataBase_Arr[Loc_count].id));
                        printf("Now The new ID for this client ( with old ID of: %u ) is updated to: %u\n", Copy_u32Client_Id, Bank_DataBase_Arr[Loc_count].id );
                    break;
                    case 2:
                        printf("enter the new Name for this client whose ID is: %u\n", Bank_DataBase_Arr[Loc_count].id);
                        fflush(stdin);
                        gets(&(Bank_DataBase_Arr[Loc_count].name));
                        printf("Now The new Name for this client ( whose ID is: %u ) is updated to: %s\n", Bank_DataBase_Arr[Loc_count].id, Bank_DataBase_Arr[Loc_count].name );
                    break;
                    case 3:
                        printf("enter the new Cash amount for this client whose ID is: %u\n", Bank_DataBase_Arr[Loc_count].id);
                        fflush(stdin);
                        scanf("%lf",&(Bank_DataBase_Arr[Loc_count].cash));
                        printf("Now The new Cash amount for this client ( whose ID is: %u ) is updated to: %lf\n", Bank_DataBase_Arr[Loc_count].id, Bank_DataBase_Arr[Loc_count].cash );
                    break;
                    case 4:
                        printf("enter the new Type for this client whose ID is: %u\n", Bank_DataBase_Arr[Loc_count].id);
                        fflush(stdin);
                        gets(&(Bank_DataBase_Arr[Loc_count].type));
                        printf("Now The new Type for this client ( whose ID is: %u ) is updated to: %s\n", Bank_DataBase_Arr[Loc_count].id, Bank_DataBase_Arr[Loc_count].type );
                    break;
                    default:
                        printf("Invalid Input\n");
                    break;
                }
            }
        break;
        case 0:
            printf("Client not found\n");
        break;
    }
    #else
    printf("Number of clients to add is up to 3\n");
    #endif

}
void Bank_void_Print_Client_Data(u32 Copy_u32Client_Id)
{
    u32 Loc_count;
    u8 Loc_IsClientFound;
    #if (CLIENTS_NO>=1&&CLIENTS_NO<=3)
    for(Loc_count=0;Loc_count<CountCreatedClients;Loc_count++)
    {
        if(Bank_DataBase_Arr[Loc_count].id == Copy_u32Client_Id)
        {
            Loc_IsClientFound=1;
            break;
        }
        else
        {
            Loc_IsClientFound=0;
        }
    }
    switch(Loc_IsClientFound)
    {
        case 1:
            printf("Here is the data of the client whose (Client ID is %u):\n",Copy_u32Client_Id);
            printf("Client ID:%u\n",Bank_DataBase_Arr[Loc_count].id);
            printf("Client Name:%s\n",Bank_DataBase_Arr[Loc_count].name);
            printf("Client Type:%s\n",Bank_DataBase_Arr[Loc_count].type);
            printf("Client Cash:%lf\n",Bank_DataBase_Arr[Loc_count].cash);
        break;
        case 0:
            printf("Client not found\n");
        break;
    }
    #else
    printf("Number of clients to add is up to 3\n");
    #endif
}

void Bank_void_Transfer_Money(u32 Copy_u32SrcClient_Id, u32 Copy_u32DestClient_Id, f64 Copy_f64Money)
{
    static volatile u32 Loc_count;
    static volatile u32 Loc_Dest_count;
    u8 Loc_IsSrcClientFound,Loc_IsDestClientFound,Loc_IsCashFoundAtSrc;
    u8 Loc_ReadUserChoice_MoneyTransfer;
    //s32 Loc_pos_count;
    u8 Loc_ContinueMoneyTransfer=1;
    #if (CLIENTS_NO>=1&&CLIENTS_NO<=3)
    for(Loc_count=0;Loc_count<CLIENTS_NO;Loc_count++)
    {
        if(Bank_DataBase_Arr[Loc_count].id == Copy_u32SrcClient_Id)
        {
            Loc_IsSrcClientFound=1;
            break;
        }
        else
        {
            Loc_IsSrcClientFound=0;
        }
    }

    if( Loc_IsSrcClientFound && Copy_f64Money <= Bank_DataBase_Arr[Loc_count].cash )
    {
        Loc_IsCashFoundAtSrc=1;
    }
    else
    {
        Loc_IsCashFoundAtSrc=0;
    }

    for(Loc_Dest_count=0;Loc_Dest_count<CLIENTS_NO;Loc_Dest_count++)
    {
        if(Bank_DataBase_Arr[Loc_Dest_count].id == Copy_u32DestClient_Id)
        {
            Loc_IsDestClientFound=1;
            break;
        }
        else
        {
            Loc_IsDestClientFound=0;
        }
    }

    //switch(Loc_IsSrcClientFound&&Loc_IsDestClientFound&&Loc_IsCashFoundAtSrc)
    //while(Loc_ContinueMoneyTransfer)
    //{
    switch( (Loc_IsSrcClientFound&&Loc_IsDestClientFound&&Loc_IsCashFoundAtSrc) + (2*(!Loc_IsSrcClientFound)) + (3*(!Loc_IsDestClientFound)) + (4*(!Loc_IsCashFoundAtSrc)) )
    {
        case 1:
            printf("Here is the data of the source client whose (Client ID is %u):\n",Copy_u32SrcClient_Id);
            printf("Client ID:%u\n",Bank_DataBase_Arr[Loc_count].id);
            printf("Client Name:%s\n",Bank_DataBase_Arr[Loc_count].name);
            printf("Client Type:%s\n",Bank_DataBase_Arr[Loc_count].type);
            printf("Client Cash:%lf\n",Bank_DataBase_Arr[Loc_count].cash);

            printf("And Here is the data of the destination client whose (Client ID is %u):\n",Copy_u32DestClient_Id);
            printf("Client ID:%u\n",Bank_DataBase_Arr[Loc_Dest_count].id);
            printf("Client Name:%s\n",Bank_DataBase_Arr[Loc_Dest_count].name);
            printf("Client Type:%s\n",Bank_DataBase_Arr[Loc_Dest_count].type);
            printf("Client Cash:%lf\n",Bank_DataBase_Arr[Loc_Dest_count].cash);

            printf("**************************************************\n");
            printf("Enter\n1 for confirming transferring a cash amount of %lf from client (with ID %u) account to client (with ID %u) account.\n0 for quiting without transferring any amount of cash.\n",Copy_f64Money,Copy_u32SrcClient_Id,Copy_u32DestClient_Id);
            printf("**************************************************\n");
            scanf("%i",&Loc_ReadUserChoice_MoneyTransfer);
            Loc_ContinueMoneyTransfer=Loc_ReadUserChoice_MoneyTransfer;

//                printf("**************************************************\n");
//                printf("Enter\n1 for confirming transferring a cash amount of %lf from client (with ID %u) account to client (with ID %u) account.\n0 for quiting without transferring any amount of cash.\n",Copy_f64Money,Copy_u32SrcClient_Id,Copy_u32DestClient_Id);
//                printf("**************************************************\n");
//                scanf("%i",&Loc_ReadUserChoice_MoneyTransfer);
//                Loc_ContinueMoneyTransfer=Loc_ReadUserChoice_MoneyTransfer;
                switch(Loc_ReadUserChoice_MoneyTransfer)
                {
                    case 0:
                        printf("Quiting without transferring any amount of cash...\n");
                        Loc_ContinueMoneyTransfer=0;
                    break;
                    case 1:
                        printf("Proceeding to transfer a cash amount of %lf from client (with ID %u) account to client (with ID %u) account.\n", Copy_f64Money,Bank_DataBase_Arr[Loc_count].id,Bank_DataBase_Arr[Loc_Dest_count].id);
                        Bank_DataBase_Arr[Loc_Dest_count].cash += Copy_f64Money;
                        Bank_DataBase_Arr[Loc_count].cash -= Copy_f64Money;
                        printf("Now Here is the full data of both clients after this money transfer transaction:\n");

                        printf("Here is the data of the source client whose (Client ID is %u):\n",Copy_u32SrcClient_Id);
                        printf("Client ID:%u\n",Bank_DataBase_Arr[Loc_count].id);
                        printf("Client Name:%s\n",Bank_DataBase_Arr[Loc_count].name);
                        printf("Client Type:%s\n",Bank_DataBase_Arr[Loc_count].type);
                        printf("Client Cash:%lf\n",Bank_DataBase_Arr[Loc_count].cash);

                        printf("And Here is the data of the destination client whose (Client ID is %u):\n",Copy_u32DestClient_Id);
                        printf("Client ID:%u\n",Bank_DataBase_Arr[Loc_Dest_count].id);
                        printf("Client Name:%s\n",Bank_DataBase_Arr[Loc_Dest_count].name);
                        printf("Client Type:%s\n",Bank_DataBase_Arr[Loc_Dest_count].type);
                        printf("Client Cash:%lf\n",Bank_DataBase_Arr[Loc_Dest_count].cash);
                    break;
                    default:
                        printf("Invalid Input\n");
                    break;
                }
            //}
        break;
        case 6:
            printf("Source Client not found\n");
        break;
        case 3:
            printf("Destination Client not found\n");
        break;
        case 4:
            printf("Cash money in the account of Source Client is not sufficient to complete the transfer transaction\n");
        break;
        case 0:
            printf("Quiting without transferring any amount of cash...\n");
            Loc_ContinueMoneyTransfer=0;
        break;
        }
    //}
    #else
    printf("Number of clients to add is up to 3\n");
    #endif

}

void Bank_void_Delete_Client_Data(u32 Copy_u32Client_Id)
{
    static volatile s32 Loc_count;
    u8 Loc_IsClientFound;
    u8 Loc_ReadUserChoice_DataDel;
    s32 Loc_pos_count;
    u8 Loc_ContinueDel=1;
    #if (CLIENTS_NO>=1&&CLIENTS_NO<=3)
    for(Loc_count=0;Loc_count<CountCreatedClients;Loc_count++)
    {
        if(Bank_DataBase_Arr[Loc_count].id == Copy_u32Client_Id)
        {
            Loc_IsClientFound=1;
            break;
        }
        else
        {
            Loc_IsClientFound=0;
        }
    }
    switch(Loc_IsClientFound)
    {
        case 1:
            printf("Here is the data of the client whose (Client ID is %u):\n",Copy_u32Client_Id);
            printf("Client ID:%u\n",Bank_DataBase_Arr[Loc_count].id);
            printf("Client Name:%s\n",Bank_DataBase_Arr[Loc_count].name);
            printf("Client Type:%s\n",Bank_DataBase_Arr[Loc_count].type);
            printf("Client Cash:%lf\n",Bank_DataBase_Arr[Loc_count].cash);
            while(Loc_ContinueDel)
            {
                printf("**************************************************\n");
                printf("Enter\n1 for deleting the whole client data.\n0 for quiting without deleting any client's data.\n");
                printf("**************************************************\n");
                scanf("%i",&Loc_ReadUserChoice_DataDel);
                Loc_ContinueDel=Loc_ReadUserChoice_DataDel;
                switch(Loc_ReadUserChoice_DataDel)
                {
                    case 0:
                        printf("Quiting without deleting the client data...\n");
                        Loc_ContinueDel=0;
                    break;
                    case 1:
                        printf("Proceeding to delete the whole data of the client whose ID is: %u\n", Copy_u32Client_Id);
                        // Loc_count is position of element to delete
                        for(Loc_pos_count=Loc_count-1;Loc_pos_count<CountCreatedClients-1;Loc_pos_count++)
                        {
                            Bank_DataBase_Arr[Loc_pos_count]=Bank_DataBase_Arr[Loc_pos_count+1];
                        }
                        Bank_DataBase_Arr[CountCreatedClients].cash=-1; // -1 indicate this is empty place for new customer
                        Bank_DataBase_Arr[CountCreatedClients].id=-1 ;  // -1 indicate this is empty place for new customer
                        strcpy(Bank_DataBase_Arr[CountCreatedClients].name,"-1"); // -1 indicate this is empty place for new customer
                        strcpy(Bank_DataBase_Arr[CountCreatedClients].type,"-1"); // -1 indicate this is empty place for new customer
                        CountCreatedClients--;
                        printf("Now the whole data of the client ( whose ID was: %u ) is completely deleted\n", Copy_u32Client_Id );
                        Loc_ContinueDel = 0;
                    break;
                    default:
                        printf("Invalid Input\n");
                    break;
                }
            }
        break;
        case 0:
            printf("Client not found\n");
        break;
    }
    #else
    printf("Number of clients to add is up to 3\n");
    #endif

}
