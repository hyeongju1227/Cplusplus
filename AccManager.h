/***** AccManager.h *****/

#ifndef _ACC_MANAGER_H_
#define _ACC_MANAGER_H_

#include "Contribution.h"
#include "FaithAccount.h"
#include "Container.h"

const int NAME_LEN = 20;

class AccManager
{
    Container<Account*> ctr;
public:
    AccManager();
    void PrintMenu();
    void MakeAccount();
    void Deposit();
    void Withdraw();
    void Inquire();
};

#endif