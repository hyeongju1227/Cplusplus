#include <iostream>
#include "Account.h"
#include "MinException.h"
#include "InsuffException.h"

using namespace std;

Account::Account(int id, string name, int balance)
{
    this->id=id;
    this->balance=balance;
    this->name=name;
}
int Account::GetID() const{
    return id;
}
int Account::GetBalance() const{
    return balance;
}
void Account::AddMoney(int val){
    if(val<0)
        throw MinException(val);

    if(balance<val)
        throw InsuffException(balance, val);

    balance-=val;
}
const string& Account::GetName() const{
    return name;
}
void Account::ShowAllData(){
    cout<<"계좌 ID: "<<id<<endl;
    cout<<"Name : "<<name<<endl;
    cout<<"balance: "<<balance<<endl;
}