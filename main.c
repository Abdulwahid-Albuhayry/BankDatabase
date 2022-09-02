//this app is for bank employee to use
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "BankDatabase.h"

//-lwinmm

//client_t Bank_DataBase_Arr[CLIENTS_NO];

u32 Loc_ID;
u32 _DestID;
f64 _CashTransferAmount;

int main()
{
    u8 Loc_ReadUserChoice=1;

    while(Loc_ReadUserChoice)
    {
        printf("**************************************************\n");
        printf("Enter\n1 for creating new client.\n2 for editing client data.\n3 for printing client data.\n4 for transferring money.\n5 for deleting client data.\n0 for quiting the application.\n");
        printf("**************************************************\n");
        scanf("%i",&Loc_ReadUserChoice);
        switch(Loc_ReadUserChoice)
        {
            case 0:
                Loc_ReadUserChoice=0;
            break;
            case 1:
                Bank_void_Create_New_Client();
            break;
            case 2:
                printf("enter Client ID to edit his/her data:");
                scanf("%u",&Loc_ID);
                Bank_void_Edit_Client_Data(Loc_ID);
            break;
            case 3:
                printf("enter Client ID to print his/her data:");
                scanf("%u",&Loc_ID);
                Bank_void_Print_Client_Data(Loc_ID);
            break;
            case 4:
                printf("enter source Client ID which cash will be transfered from his/her account:");
                scanf("%u",&Loc_ID);
                printf("enter destination Client ID which cash will be transfered into his/her account:");
                scanf("%u",&_DestID);
                printf("enter the amount of cash money that will be transfered from %u account into %u account:",Loc_ID, _DestID);
                scanf("%lf",&_CashTransferAmount);
                Bank_void_Transfer_Money(Loc_ID,_DestID,_CashTransferAmount);
            break;
            case 5:
                printf("enter Client ID to delete his/her data:");
                scanf("%u",&Loc_ID);
                Bank_void_Delete_Client_Data(Loc_ID);
            break;
            default:
                printf("Invalid Input\n");
            break;
        }
    }
    return 0;
}
