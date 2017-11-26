/***** AccManager.cpp *****/

#include <iostream>
#include "AccManager.h"
#include "String.h"
#include "MinException.h"
#include "InsuffException.h"

using namespace std;

AccManager::AccManager(){}

void AccManager::PrintMenu()
{
    cout<<"----Menu---------"<<endl;
    cout<<"1. 계좌 개설"<<endl;
    cout<<"2. 입 금"<<endl;
    cout<<"3. 출 금"<<endl;
    cout<<"4. 잔액 조회 "<<endl;
    cout<<"5. 프로그램 종료"<<endl;
}

void AccManager::MakeAccount()
{
    int id;
    string name;

    int balance;
    int sel;

    cout<<"개설할 계좌의 종류------------"<<endl;
    cout<<"1. 일반 계좌 "<<endl;
    cout<<"2. 신용 계좌 "<<endl;
    cout<<"2. 기부 계좌 "<<endl;
    cout<<">>";
    cin>>sel;

    cout<<"계좌 개설------"<<endl;
    cout<<"계좌 ID: "; cin>>id;
    cout<<"이 름: "; cin>>name;
    cout<<"입금액: "; cin>>balance;

    if(sel==1)
        ctr.Insert(new Account(id, name, balance));
    else if(sel==2)
        ctr.Insert(new FaithAccount(id, name, balance));
    else if(sel==3)
        ctr.Insert(new ContriAccount(id, name, balance));
    else
        cout<<"선택 오류!!!"<<endl;

}

void AccManager::Deposit()
{
    int money;
    int id;

    cout<<"계좌 I:"; cin>>id;
    cout<<"입금액: "; cin>>money;

    int num = ctr.GetElemSum();     //계좌 총 개수
    try{
        for(int i=0; int<num; i++)
        {
            if(ctr.GetItem(i)->GetID()==id)
            {
                ctr.GetItem()->AdMoney(money);
                cout<<"입금 완료"<<endl;
                return;
            }
        }
        cout<<"유효하지 않은 ID입니다."<<endl;
    }
    catch(MinException& ex){
        ex.What();
    }
}

void AccManager::Withdraw()
{
    int money;
    int id;

    cout<<"계좌 ID: "; cin>>id;
    cout<<"출금액: "; cin>>money;

    int num = ctr.GetElemSum();     //계좌의 총 개수

    try{
        for(int i=0; i<num; i++)
        {
            if(ctr.GetItem(i)->GetID()==id)
            {
                ctr.GetItem(i)->MinMoney(money);
                cout<<"출금 완료"<<endl;
                return;
            }
        }
        cout<<"유효하지 않은 ID입니다."<<endl;
    }
    catch(MinException& ex){
        ex.What();
    }
}

void AccManager::Inquire()      // 전체 잔액 조회
{
    int num = ctr.GetElemSum();     //게좌의 총 개수

    for(int i=0; i<num; i++){
        ctr.GetItem(i)->ShowAllData();
    }
}