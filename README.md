# Banking System

## description:
This project involves modeling, designing, and developing a comprehensive banking application. The application empowers bank employees to efficiently manage bank accounts for specific clients. It offers functionalities such as creating new bank accounts, listing existing accounts, displaying account details, and facilitating withdrawal and deposit operations.  
Features.<br>
### 1. BankAccount 
   -- Class Attributes:<br>
   Account ID 
   Balance 
   -- Methods:<br>
   Constructor:Two constructors available. The first sets the balance to a given value, and the second is a no-argument constructor setting the balance to 0. 
   Setters and getters for accessing private data fields.
   Withdraw: Allows the withdrawal of an amount if the balance is sufficient.
   Deposit: Enables depositing an amount of money into the account. 
### 2. SavingsBankAccount Class (Extends BankAccount) 
   -- Additional Attribute:  
   Minimum Balance (default value of 1000 L.E.).<br>
   -- Additional Methods:  
   Constructor: Sets the initial balance and minimum balance (initial balance must be >= minimum balance). 
   Setters and getters for private data fields. 
   Withdraw (Override): Permits withdrawal, ensuring the balance does not fall below the minimum balance. 
   Deposit: Accepts deposits only if the amount is >= 100 L.E.
### 3. Client Class
   Holds basic client information, including name, address, and phone number. <br>
   Contains a pointer to the client's bank account. <br>
   An account also points to its owner.<br>
### 4. BankingApplication Class Functionality:
   Displays the main menu. Accepts user choices for operations.<br>
   Maintains lists of accounts and clients.<br>
   Allows users to perform various operations on a bank account.<br>

