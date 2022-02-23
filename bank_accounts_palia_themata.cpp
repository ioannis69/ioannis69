#include <iostream>
#include <string>

using namespace std;

class BankCard{
    
    public:
        BankCard(string new_bankName=" ",string new_holderName=" ",int new_year=2000);
        string getBank();
        string getHolder();
        int getYear();
        void SendAlert(int in_year);
    
    private:
        string bankName;
        string holderName; 
        int year;
};

class CreditCard: public BankCard {
    
    public:
        CreditCard(string text1,string text2, int integer1,int integer2,int integer3);
        int getLimit();
        int NoDoses();
        void Print();
    
    private:
        int creditLimit;
        int type;
};

void checkForExpire(CreditCard *arrayOfCreditCards)
{
    for (int i=0;i<3;i++)
    {
        arrayOfCreditCards[i].SendAlert(2022);
    }
}

void sumCreditLimit(CreditCard *arrayOfCreditCards)
{
    int sum = 0;
    for (int i=0; i<3; i++)
    {
        sum += arrayOfCreditCards[i].getLimit();
    }
    cout<<"sum of credit limit: "<<sum<<endl;
}

int main()
{
    string name="John Smith";

    CreditCard cc1("Bank1",name,2017,3000,1);
    CreditCard cc2("Bank2",name,2019,1200,2);
    CreditCard cc3("Bank3",name,2020,4000,1);
    
    CreditCard arrayOfCreditCards[3] = {cc1,cc2,cc3};
    
    checkForExpire(arrayOfCreditCards);
    sumCreditLimit(arrayOfCreditCards);
    
    return 0;
}

BankCard::BankCard(string new_bankName,string new_holderName,int new_year)
{
    bankName = new_bankName;
    holderName = new_holderName;
    year = new_year;
}

int BankCard::getYear()
{
    return year;
}

string BankCard::getBank()
{
    return bankName;
}

string BankCard::getHolder()
{
    return holderName;
}

void BankCard::SendAlert(int in_year)
{
    if (in_year>=year)
    {
        cout<<"error == card expired"<<endl;
    }
}

CreditCard::CreditCard(string text1,string text2, int integer1,int integer2,int integer3):BankCard(text1,text2,integer1)
{
    creditLimit = integer2;
    type = integer3;
}

int CreditCard::getLimit()
{
    return creditLimit;
}

int CreditCard::NoDoses()
{
    int value;
    
    if (type==1)
    {
        value=60;
    }
    else if (type==2)
    {
        value=30;
    }
    
    return value;
}

void CreditCard::Print()
{
    cout<<"bank name: "<<getBank()<<endl;
    cout<<"holder name: "<<getHolder()<<endl;
    cout<<"expiration year: "<<getYear()<<endl;
    cout<<"credit limit: "<<getLimit()<<endl;
    cout<<"max amount: "<<NoDoses()<<endl;
    
}


