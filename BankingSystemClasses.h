//
// Created by Abdelrhman on 9/17/2023.
//
#ifndef BANKINGSYSTEM_BANKINGSYSTEMCLASSES_H
#define BANKINGSYSTEM_BANKINGSYSTEMCLASSES_H
#endif //BANKINGSYSTEM_BANKINGSYSTEMCLASSES_H
#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <cctype>
#include <vector>
#include <algorithm>
#include <regex>
#include <vector>
#include <fstream>
#include <windows.h> // to color compilare

using namespace std;
// client class
class Client
{
private:
    string name;
    string numberPhone;

public:
    Client() {}
    Client(string name, string numPhone);
    void setClientName();
    void setClientNumberPhone();
    void setClientNameFromFile(string nameFFile);
    void setClientNumberPhoneFromFile(string numebrPhoneFFile);
    string getClientName();
    string getClientNumberPhone();
};
// bank account class
class BankAccount
{
protected:
    int indexInvector = 0;
    long long newBalance = 0;
    string account_ID;
    string account_Type;
    long long balance;
    int minimumBalance;

public:
    vector<BankAccount> clientsAccount;
    vector<Client> clients;
    BankAccount();
    BankAccount(long long money);
    virtual BankAccount withdraw(vector<BankAccount> &clientsAccount, string id);
    virtual BankAccount deposit(vector<BankAccount> &clientsAccount, string id);
    void setAcconutBalance();
    void setAcconutNewBalance(long long newB);
    void setAcconutType(string typeAccount);
    void setAcconutId(string id);
    void setAcconutBalanceFromFile(long long balanceFromFile);
    void setAcconutMinBalance(int minBalance);
    int getAcconutMinBalance();
    void setAcconutIdFromFile(string idFromFile);
    long long getAcconutBalance();
    long long getAcconutNewBalance();
    string getAcconutID();
    string getAcconutType();
};

// saving banking application
class savingsbankaccount : public BankAccount
{
private:
    long long minimum_balance;

public:
    savingsbankaccount();
    BankAccount deposit(vector<BankAccount> &clientsAccount, string id);
    BankAccount withdraw(vector<BankAccount> &clientsAccount, string id);
    void setSavingMinimumBalance();
    long long getSavingMinimumBalance();
};


// Banking Application
class bankingApplication
{

public:
    fstream useFile;
    vector<BankAccount> clientsAccount;
    vector<Client> clients;
    bankingApplication();
    void addClient(string typeAccount);
    void loadData();
    void saveData(Client NextUser, BankAccount NextAccount);
    void printData();
    void changePassInFile(BankAccount dataTogetInfile);
    void BankingApplicationSystem();
};