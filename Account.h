/**** Account.h *****/

#ifndef _ACCOUNT_H_
#define _ACCOUNT_H_

#include "String.h"

class Account
{
    int id;
    int balance;
    string name;

public:
    Account(int id, string name, int balance);
    int GetID() const;
    int GetBalance() const;
    virtual void AddMoney(int val);
    void MinMoney(int val);

    const string& GetName() const;

    virtual void ShowAllData();
};


#endif