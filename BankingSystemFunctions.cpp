//
// Created by Abdelrhman on 9/17/2023.
//
#include "BankingSystemClasses.h"

// client function
Client::Client(string name, string numPhone)
{
    this->name = name;
    this->numberPhone = numPhone;
}
void Client::setClientName()
{
    string clientName, nameSaved = "";
    cout << "\n<<<Please, Enter Client Name : \n=>";
    cin.ignore();
    getline(cin, clientName);
    regex filter("[ |A-Z|a-z]+[ |A-Z|a-z]+");
    if (!regex_match(clientName, filter))
    {
        cout << "\n\t\t*****1 Invalid Input Type *****\n\t\t\tTry Again\n";
        setClientName();
    }
    else
    {
        nameSaved = clientName;
    }
    for (size_t i = 0; i < nameSaved.size(); i++)
    {
        if (nameSaved[i] == ' ')
        {
            nameSaved[i] = '_';
        }
    }
    this->name = nameSaved;
}
void Client::setClientNameFromFile(string nameFFile)
{
    this->name = nameFFile;
}
void Client::setClientNumberPhoneFromFile(string numebrPhoneFFile)
{
    numberPhone = numebrPhoneFFile;
}

string Client::getClientName()
{
    return this->name;
}
void Client::setClientNumberPhone()
{
    string clientNumberPhone;
    cout << "\n<<<Please, Enter Client Phone : \n=>";
    cin >> clientNumberPhone;
    regex filter("(01)+(0|1|2|5){1}[0-9]{8}");
    regex_match(clientNumberPhone, filter);
    if (!regex_match(clientNumberPhone, filter))
    {
        cout << "\n\t\t***** Invalid Input Type *****\n\t\t\tTry Again\n";
        setClientNumberPhone();
    }
    if (regex_match(clientNumberPhone, filter))this->numberPhone = clientNumberPhone;
}
string Client::getClientNumberPhone()
{
    return this->numberPhone;
}


// function bank account client
BankAccount::BankAccount()
{
    this->balance = 0;
}
void BankAccount::setAcconutBalanceFromFile(long long balanceFromFile)
{
    this->balance = balanceFromFile;
}
void BankAccount::setAcconutIdFromFile(string idFromFile)
{
    this->account_ID = idFromFile;
}
void BankAccount::setAcconutBalance()
{
    long long yourBalance;
    cout << "\n<<<Please, Enter the Starting Balance : \n=>";
    cin >> yourBalance;
    this->balance = yourBalance;
}
void BankAccount::setAcconutMinBalance(int minBalance)
{
    minimumBalance = minBalance;
}
void BankAccount::setAcconutNewBalance(long long newB)
{
    newBalance = newB;
}
int BankAccount::getAcconutMinBalance()
{
    return minimumBalance;
}
void BankAccount::setAcconutId(string id)
{
    this->account_ID = id;
}
void BankAccount::setAcconutType(string typeAccount)
{
    this->account_Type = typeAccount;
}
long long BankAccount::getAcconutBalance()
{
    return balance;
}
long long BankAccount::getAcconutNewBalance()
{
    return newBalance;
}
string BankAccount::getAcconutID()
{
    return account_ID;
}
string BankAccount::getAcconutType()
{
    return account_Type;
}
BankAccount::BankAccount(long long money)
{
    this->balance = money;
}
BankAccount BankAccount::deposit(vector<BankAccount> &clientsAccount, string id)
{
    BankAccount dataTogetInfile;
    string type = "";
    bool flag = false;
    long long depositedMoney, b = 0;
    // cout << "\n<<<Please, Enter Account ID (e.g., FCAI-015) : \n===>>";
    // cin >> id;
    for (int i = 0; i < clientsAccount.size(); i++)
    {
        if (clientsAccount[i].getAcconutID() == id)
        {
            b = clientsAccount[i].getAcconutBalance();
            type = clientsAccount[i].getAcconutType();
            dataTogetInfile.indexInvector = i;
            flag = true;
            break;
        }
        flag = false;
    }
    if (!flag)
    {
        cout << "\n\t\t***** This Id Account Not Found ***** \n"
             << endl;
        exit(0);
    }
    dataTogetInfile.balance = b;
    cout << "\n\t\t\t================================================\n\n";
    cout << "Account ID : " << id
         << "\nAcocunt Type : " << type << "\nBalance : " << dataTogetInfile.balance << endl;

    cout << "\n\t\t\t================================================\n";
    cout << "\n<<<Please, Enter The Amount to Deposit : \n===>>";
    cin >> depositedMoney;

    dataTogetInfile.newBalance = dataTogetInfile.balance + depositedMoney;
    // cout << "old balance: " << dataTogetInfile.balance << endl;
    // cout << "new balance: " << dataTogetInfile.newBalance << endl;
    cout << "\n\t\t\t\t***** Thank You *****\n";
    cout << "\n\t\t==============Your account after the modification==============\n\n";
    cout << "Account ID : " << id << "\nBalance : " << dataTogetInfile.newBalance << endl;
    cout << "\n\t\t\t================================================\n\n";
    return dataTogetInfile;
}
BankAccount BankAccount::withdraw(vector<BankAccount> &clientsAccount, string id)
{
    BankAccount dataTogetInfile;
    string type = "";
    bool flag = false;
    long long withdrawedMoney, b = 0;
    // cout << "\n<<<Please, Enter Account ID (e.g., FCAI-015) : \n=>";
    // cin >> id;
    cout << clientsAccount.size() << endl;
    for (int i = 0; i < clientsAccount.size(); i++)
    {
        if (clientsAccount[i].getAcconutID() == id)
        {
            b = clientsAccount[i].getAcconutBalance();
            type = clientsAccount[i].getAcconutType();
            dataTogetInfile.indexInvector = i;
            flag = true;
            break;
        }
        flag = false;
    }
    if (!flag)
    {
        cout << "\n\t\t***** This Id Account Not Found ***** \n"
             << endl;
        exit(0);
    }
    dataTogetInfile.balance = b;
    cout << "\n\t\t\t================================================\n\n";
    cout << "Account ID : " << id
         << "\nAcocunt Type : " << type << "\nBalance : " << dataTogetInfile.balance << endl;

    cout << "\n\t\t\t================================================\n";
    while (true)
    {
        cout << "\nPlease, Enter The Amount to Withdraw : \n===>>";
        cin >> withdrawedMoney;
        if (withdrawedMoney > clientsAccount[dataTogetInfile.indexInvector].balance)
        {
            cout << "\n\t\t***** Sorry. This is more than what you can withdraw! *****" << endl;
            continue;
        }
        else
            break;
    }
    dataTogetInfile.newBalance = dataTogetInfile.balance - withdrawedMoney;
    // cout << "old balance: " << dataTogetInfile.balance << endl;
    // cout << "new balance: " << dataTogetInfile.newBalance << endl;
    cout << "\n\t\t\t\t***** Thank You *****\n";
    cout << "\n\t\t=============Your account after the modification==============\n\n";
    cout << "Account ID : " << id << "\nBalance : " << dataTogetInfile.newBalance << endl;
    cout << "\n\t\t\t================================================\n";
    return dataTogetInfile;
}
savingsbankaccount::savingsbankaccount()
{
}
void savingsbankaccount::setSavingMinimumBalance()

{
    long long minBalance;
    cout << "\n<<<Please, Enter your minimum Balance : \n-->";
    cin >> minBalance;
    minimum_balance = minBalance;
}
long long savingsbankaccount::getSavingMinimumBalance()
{
    return minimum_balance;
}

BankAccount savingsbankaccount::withdraw(vector<BankAccount> &clientsAccount, string id)
{
    // cout << "enter "<< endl;
    BankAccount dataTogetInfile;
    string type = "";
    bool flag = false;
    int index = 0;
    long long withdrawedMoney, b = 0, minBalanceAccount = 0;
    for (int i = 0; i < clientsAccount.size(); i++)
    {
        if (clientsAccount[i].getAcconutID() == id)
        {
            b = clientsAccount[i].getAcconutBalance();
            type = clientsAccount[i].getAcconutType();
            minBalanceAccount = clientsAccount[i].getAcconutMinBalance();
            index = i;
            flag = true;
            break;
        }
        flag = false;
    }
    if (!flag)
    {
        cout << "\n\t\t***** This Id Account Not Found ***** \n"
             << endl;
        exit(0);
    }
    dataTogetInfile.setAcconutBalanceFromFile(b);
    cout << "\n\t\t\t================================================\n\n";
    cout << "Account ID : " << id
         << "\nAcocunt Type : " << type << "\nBalance : "
         << dataTogetInfile.getAcconutBalance()
         << "\nMinimum Balance : " << clientsAccount[index].getAcconutMinBalance() << endl;

    cout << "\n\t\t\t================================================\n";
    while (true)
    {
        cout << "\nPlease, Enter The Amount to Withdraw : \n===>>";
        cin >> withdrawedMoney;
        if (clientsAccount[index].getAcconutBalance() - withdrawedMoney < clientsAccount[index].getAcconutMinBalance())
        {
            cout << "\n\t\t***** Sorry. This is less than your minimum Account Balance *****" << endl;
            continue;
        }
        else
        {
            break;
        }
    }
    dataTogetInfile.setAcconutNewBalance(dataTogetInfile.getAcconutBalance() - withdrawedMoney);
    cout << "\n\t\t\t\t***** Thank You *****\n";
    cout << "\n\t\t=============Your account after the modification==============\n\n";
    cout << "Account ID : " << id << "\nBalance : " << dataTogetInfile.getAcconutNewBalance()
         << endl;
    cout << "\n\t\t\t================================================\n";
    return dataTogetInfile;
}
BankAccount savingsbankaccount::deposit(vector<BankAccount> &clientsAccount, string id)
{
    BankAccount dataTogetInfile;
    string type = "";
    bool flag = false;
    int index = 0;
    long long depositedMoney, b = 0;
    for (int i = 0; i < clientsAccount.size(); i++)
    {
        if (clientsAccount[i].getAcconutID() == id)
        {
            b = clientsAccount[i].getAcconutBalance();
            type = clientsAccount[i].getAcconutType();
            index = i;
            flag = true;
            break;
        }
        flag = false;
    }
    if (!flag)
    {
        cout << "\n\t\t***** This Id Account Not Found ***** \n"
             << endl;
        exit(0);
    }
    dataTogetInfile.setAcconutBalanceFromFile(b);
    cout << "\n\t\t\t================================================\n\n";
    cout << "Account ID : " << id
         << "\nAcocunt Type : " << type << "\nBalance : " << dataTogetInfile.getAcconutBalance() << endl;

    cout << "\n\t\t\t================================================\n";
    while (true)
    {
        cout << "\n<<<Please, Enter The Amount to Deposit : \n===>>";
        cin >> depositedMoney;
        if (depositedMoney < 100)
        {
            cout << "\n\t\t***** sorry, You must enter money not less than 100 ***** \n";
            continue;
        }
        else
            break;
    }
    dataTogetInfile.setAcconutNewBalance(b + depositedMoney);
    cout << "\n\t\t\t\t***** Thank You *****\n";
    cout << "\n\t\t==============Your account after the modification==============\n\n";
    cout << "Account ID : " << id << "\nBalance : " << dataTogetInfile.getAcconutNewBalance() << endl;
    cout << "\n\t\t\t================================================\n\n";
    return dataTogetInfile;
}


bankingApplication::bankingApplication()
{
}
void bankingApplication::addClient(string typeAccount)
{
    string id = "FCAI-";
    int minB = 0;
    Client client;
    savingsbankaccount saveAccount;

    client.setClientName();
    client.setClientNumberPhone();
    BankAccount accountClient;
    accountClient.setAcconutBalance();
    id = id + to_string(clients.size());
    accountClient.setAcconutId(id);
    accountClient.setAcconutType(typeAccount);
    if (typeAccount == "Basic")
    {
        accountClient.setAcconutMinBalance(minB);
    }
    if (typeAccount == "Saving")
    {
        saveAccount.setSavingMinimumBalance();
        accountClient.setAcconutMinBalance(saveAccount.getSavingMinimumBalance());
    }
    clients.push_back(client);
    clientsAccount.push_back(accountClient);
    saveData(client, accountClient);
    cout << "\n\tAn account was created with ID " << id << " and Starting Balance " << accountClient.getAcconutBalance() << " L.E.\n";
}
void bankingApplication::loadData()
{
    string type;
    string nameFFile;
    string phoneNumberFFile;
    string idFFile;
    long long BalanceFFile;
    int minimum_balance;
    useFile.open("Client.txt", ios::in);
    while (!useFile.eof())
    {
        Client NextUser;
        BankAccount NextAccount;
        useFile >> type;
        NextAccount.setAcconutType(type);
        useFile >> nameFFile;
        NextUser.setClientNameFromFile(nameFFile);
        useFile >> phoneNumberFFile;
        NextUser.setClientNumberPhoneFromFile(phoneNumberFFile);
        useFile >> idFFile;
        NextAccount.setAcconutIdFromFile(idFFile);
        useFile >> BalanceFFile;
        NextAccount.setAcconutBalanceFromFile(BalanceFFile);
        useFile >> minimum_balance;
        NextAccount.setAcconutMinBalance(minimum_balance);
        clients.push_back(NextUser);
        clientsAccount.push_back(NextAccount);
    }
}

void bankingApplication::saveData(Client NextUser, BankAccount NextAccount)
{
    useFile.close();
    useFile.open("Client.txt", ios::app);
    useFile << NextAccount.getAcconutType();
    useFile << "  ";
    useFile << NextUser.getClientName();
    useFile << "  ";
    useFile << NextUser.getClientNumberPhone();
    useFile << "  ";
    useFile << NextAccount.getAcconutID();
    useFile << "  ";
    useFile << NextAccount.getAcconutBalance();
    useFile << "  ";
    useFile << NextAccount.getAcconutMinBalance();
    useFile << endl;
    useFile.close();
}

void bankingApplication::changePassInFile(BankAccount dataTogetInfile)
{
    string StrNewBalance = "", StrOldBalance = "";
    StrOldBalance = to_string(dataTogetInfile.getAcconutBalance());
    StrNewBalance = to_string(dataTogetInfile.getAcconutNewBalance());
    char line[1000];
    vector<string> text;
    int k = 0;
    useFile.close();
    useFile.open("Client.txt");
    while (!useFile.eof())
    {
        useFile.getline(line, 1000, '\n');
        text.push_back(string(line));
    }
    int x, z;
    for (int i = 0; i < text.size(); i++)
    {
        if (text[i].find(StrOldBalance, 0) < 1000)
        {
            x = text[i].find(StrOldBalance, 0);
            z = i;
        }
    }
    for (int j = x; j < (x + StrNewBalance.size()); j++)
    {
        text[z][j] = StrNewBalance[k];
        k++;
    }
    useFile.close();
    useFile.open("Client.txt", ios::out);

    for (int i = 0; i < text.size(); i++)
    {
        useFile << text[i];
        useFile << '\n';
    }
    useFile.close();
}
void bankingApplication::printData()
{
    loadData();
    cout << "\n";
    for (size_t i = 0; i < clients.size() - 1; i++)
    {
        cout << "\n\n\t\t------------------------[" << clients[i].getClientName() << "]------------------------\n\n";
        cout << "Number Phone : " << clients[i].getClientNumberPhone() << "    "
             << "\nAccount ID : " << clientsAccount[i].getAcconutID() << "\nAcocunt Type : "
             << "(" << clientsAccount[i].getAcconutType() << ")"
             << "\nBalance : " << clientsAccount[i].getAcconutBalance() << endl;
    }
}
void bankingApplication::BankingApplicationSystem()
{
    Sleep(2000);
    system("cls");
    cout << "\n\t\t\t[<===========Welcome to FCAI Banking Application===========>]\n\n";
    cout << "\n\t1)Create a New Account.\n"
            "\t2)List Clients and Accounts.\n"
         << "\t3)Withdraw Money.\n"
         << "\t4)Deposit Money.\n"
         << "\n";
    string choice, id, type = "";
    savingsbankaccount userS;
    BankAccount dataTogetInfile, userB;
    loadData();
    cout << "Enter your choice from this list (1 --> 4) : \n==>>>";
    cin >> choice;
    if (choice == "1")
    {
        while (true)
        {
            string AccountTypeChoice;
            cout << "\nWhat Type of Account Do You Like? \n(1) Basic \n(2) Saving \n===>>";
            cin >> AccountTypeChoice;
            if (AccountTypeChoice == "1")
            {
                addClient("Basic");
                cout << "\n\t\t***** Thank you for use FCAI Banking Application *****\n";
                break;
            }
            else if (AccountTypeChoice == "2")
            {
                addClient("Saving");
                cout << "\n\t\t***** Thank you for use FCAI Banking Application *****\n";
                break;
            }
            else
            {
                cout << "\n\t\t***** Invalid Input Type *****\n\t\t\tTry Again\n";
            }
        }
    }
    else if (choice == "2")
    {
        printData();
    }
    else if (choice == "3")
    {

        while (true)
        {
            cout << "\n<<<Please, Enter Account ID (e.g., FCAI-(1-100)) : \n===>>";
            cin >> id;
            regex filter("[F]+[C]+[A]+[I]+[-]+[1-9]+");
            if (!regex_match(id, filter))
            {
                cout << "\n\t\t***** Invalid Input *****\n\t<= Try Again And Enter This pattern (FCAI-(1->100)) =>\n";
            }
            else
            {
                break;
            }
        }
        for (auto k : clientsAccount)
        {
            if (id == k.getAcconutID())
            {
                type = k.getAcconutType();
            }
        }
        if (type == "Basic")
        {
            dataTogetInfile = userB.withdraw(clientsAccount, id);
            changePassInFile(dataTogetInfile);
            exit(0);
        }
        else if (type == "Saving")
        {
            dataTogetInfile = userS.withdraw(clientsAccount, id);
            changePassInFile(dataTogetInfile);
            exit(0);
        }
    }
    else if (choice == "4")
    {
        while (true)
        {
            cout << "\n<<<Please, Enter Account ID (e.g., FCAI-(1-100)) : \n===>>";
            cin >> id;
            regex filter("[F]+[C]+[A]+[I]+[-]+[1-9]+");
            if (!regex_match(id, filter))
            {
                cout << "\n\t\t***** Invalid Input *****\n\t<= Try Again And Enter This pattern (FCAI-(1->100)) =>\n";
            }
            else
            {
                break;
            }
        }
        for (auto k : clientsAccount)
        {
            if (id == k.getAcconutID())
            {
                type = k.getAcconutType();
            }
        }
        if (type == "Basic")
        {
            dataTogetInfile = userB.deposit(clientsAccount, id);
            changePassInFile(dataTogetInfile);
            exit(0);
        }
        else if (type == "Saving")
        {
            dataTogetInfile = userS.deposit(clientsAccount, id);
            changePassInFile(dataTogetInfile);
            exit(0);
        }
    }
    else
    {
        cout << "\n\t\t***** Invalid Input *****\n\t<= Try Again And Enter (1 --> 4) => \n";
        BankingApplicationSystem();
    }
}