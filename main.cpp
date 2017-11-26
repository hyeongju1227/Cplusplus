/*
    Banking System v7.0
*/


/**** main.cpp ****/

#include <iostream>
#include "AccManager.h"

using namespace std;

enum{
    MAKE=1,
    DEPOSIT,
    WITHDRAW,
    INQUIRE,
    EXIT
};

int main(void)
{
    int choice;
    AccManager manager;

    while(true)
    {
        manager.PrintMenu();
        cout<<"선택: ";
        cin>>choice;

        switch(choice)
        {
            case MAKE:
                manager.MakeAccount();
                break;
            case DEPOSIT:
                manager.Deposit();
                break;
            case WITHDRAW:
                manager.Withdraw();
                break;
            case INQUIRE:
                manager.Inquire();
                break;
            case EXIT:
                return 0;
            default:
                cout<<"Illegal selection..."<<endl;
                break;
        }
    }
    return 0;
}