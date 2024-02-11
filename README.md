# Banking System

## Description:

This project involves modeling, designing, and developing a comprehensive banking application. The application empowers bank employees to efficiently manage bank accounts for specific clients. It offers functionalities such as creating new bank accounts, listing existing accounts, displaying account details, and facilitating withdrawal and deposit operations.  
Features.<br>

Customers can perform the following operations in the banking system:

### 1. BankAccount:

    -- Create an account with specified initial balance or default to zero.<br>
    -- Check the account balance.<br>
    -- Withdraw funds if the balance is sufficient.<br>
    -- Deposit funds into the account.<br>

### 2. SavingsBankAccount (Extends BankAccount):

    -- Create a savings account with specified initial balance and minimum balance.<br>
    -- Check the savings account balance.<br>
    -- Withdraw funds, ensuring the balance stays above the minimum.<br>
    -- Deposit funds into the savings account (only if the deposit is >= 100 L.E.).<br>

### 3. Client:

    -- Provide and update basic client information (name, address, phone number).<br>
    -- Associate a bank account with a client.<br>
    -- View client's bank account information.<br>

### 4. BankingApplication:

    -- Display the main menu for user interaction.<br>
    -- Accept user choices for operations in the menu.<br>
    Maintain lists of accounts and clients.<br>
    -- Allow users to perform various operations on a bank account, as described above.
