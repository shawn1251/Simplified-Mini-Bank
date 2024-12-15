# Simplified Mini Bank

This project is a simple Bank Management System implemented in C++. It serves as a practical example of Object-Oriented Programming (OOP) concepts, demonstrating the use of classes, encapsulation, and data management.

## Overview

The Bank Management System allows users to perform various banking operations such as creating accounts, depositing and withdrawing money, transferring funds, and inquiring about account balances. The system is designed to manage multiple accounts and keep track of transactions.

## Classes
### Bank
The `Bank` class is the main class that manages the overall banking operations. It includes methods for:

* Creating accounts
* Depositing money
* Withdrawing money
* Transferring funds between accounts
* Inquiring about account balances
* Performing daily audits of transactions

### Teller
The `Teller` class represents a bank teller who can perform operations on behalf of customers. It has methods to:

* Create accounts
* Deposit money
* Withdraw money
* Transfer funds
* Inquire about account balances

### Account
The `Account` class represents a bank account. It includes methods to:

* Check if a customer ID is valid
* Get the account ID
* Add money to the account
* Retrieve the account balance

### TransactionNode
The `TransactionNode` class is used to create a linked list of transactions. Each node contains information about a transaction, including the date, source account ID, target account ID, and the amount of money involved. It provides methods to:

* Fix the next node in the list
* Print transaction details
* Get the next transaction node


## How to Run

1. Compile
    ```sh
    make
    ```
2. Run
    ```sh
    ./simple_bank
    ```

## Conclusion

This project, completed in 2013, showcases the fundamental concepts of C++ and OOP, providing a solid foundation for understanding how to manage data and operations in a structured way. It can be further expanded with additional features such as user authentication, error handling, and a user interface.
