Compile the Code: Use a C++ compiler like g++ to compile the program:
    bash :: (g++ bank_system.cpp -o bank_system )
Run the Program:
    bash :: (./bank_system)

    
Choose Options from the Menu:
Press 1 to create a new account by entering the account number and account holder's name.
Press 2 to deposit money by entering the account number and deposit amount.
Press 3 to withdraw money by entering the account number and amount.
Press 4 to transfer funds between two accounts.
Press 5 to display all accounts.
Press 6 to exit the application.  


Note:
* Error handling is implemented for invalid inputs or insufficient funds.
* Accounts are stored in a linked list, allowing dynamic addition and removal.
* Proper memory management is handled in the destructor to avoid memory leaks.
