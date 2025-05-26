#include <iostream>
using namespace std;

// Simple 'Bank' Application to demonstrate use of control structures

double transactionAmountInput(string transactionType)
{
    /*
    This function will be used to prompt a user for an amount whenever such input is needed
    transactionType - withdrawal /  deposit
    */

    double tempAmount;
    cout << "Enter " << transactionType << " amount in Ksh. : ";
    cin >> tempAmount;
    return tempAmount;
}

double withdraw(double currentAccountBalance)
{
    /*
    This fuction updates the account balance (withdraw),
    given valid amount and account balance.
    Assumption:
        - flat constant withdrawal fee of Ksh. 50
        - Minimum withdraw amount Ksh. 100
    */
    const double MIN_WITHDRAW_AMOUNT = 100.0;
    const double TRANSACTION_FEE = 50.0;

    // get user input - withdraw amount
    double withdrawAmount = transactionAmountInput("withdraw");

    // Validate withdrawal amount
    if (withdrawAmount >= MIN_WITHDRAW_AMOUNT)
    {
        // validate amount
        int totalTransactionAmount = withdrawAmount + TRANSACTION_FEE;

        if (currentAccountBalance >= totalTransactionAmount)
        {
            // withdraw and update balance
            currentAccountBalance -= totalTransactionAmount;
            cout << "Your withdraw was successful. New account balance: Ksh." << currentAccountBalance << endl;
        }
        else
        {
            cout << "You have insufficient funds to withdraw Ksh. " << withdrawAmount << " . Your account balance is Ksh. " << currentAccountBalance << endl;
        }
    }
    else
    {
        cout << "Invalid withdrawal amount. Must be Ksh. " << MIN_WITHDRAW_AMOUNT << " or more." << endl;
    }
    return currentAccountBalance;
}

double deposit(double currentAccountBalance)
{
    /* This function takes an input amount and updates the balance given the amount is valid
    Assumption:
        - Deposit fee of Ksh. 0
        - Minimum deposit amount Ksh. 50
    */
    const double MIN_DEPOSIT_AMOUNT = 50.0;

    // get user input - deposit amount
    double depositAmount = transactionAmountInput("deposit");

    if (depositAmount >= MIN_DEPOSIT_AMOUNT)
    {
        currentAccountBalance += depositAmount;
        cout << "Your deposit was successful. New account balance: Ksh." << currentAccountBalance << endl;
    }
    else
    {
        cout << "Invalid amount, must be Ksh. " << MIN_DEPOSIT_AMOUNT << " or more." << endl;
    }
    return currentAccountBalance;
}

void checkAccountBalance(double currentBalance)
{
    /*
    Function to display the user's current account balance.
    */
    cout << "Your account balance is Ksh. " << currentBalance;
}

bool checkPin(int knownPin)
{
    /*
     This function will prompt the user with their pin, and validate against a known value
    */
    const int MAX_PIN_ATTEMPTS = 3;
    int tempPin;
    int attemptCounter = 1;
    bool validated = false;
    do
    {
        cout << "\nEnter your account pin: ";
        cin >> tempPin;
        if (tempPin == knownPin)
        {
            validated = true;
            break;
        }
        else
        {
            if (attemptCounter == MAX_PIN_ATTEMPTS)
            {
                cout << " You have entered a wrong pin too many times. You account is locked. Visit customer service for help." << endl;
                attemptCounter++;
            }
            else
            {
                cout << " You have entered a wrong pin. You've " << MAX_PIN_ATTEMPTS - attemptCounter << " attempts left." << endl;
                attemptCounter++;
            }
        }
    } while (attemptCounter <= MAX_PIN_ATTEMPTS);
    return validated;
}

int getProcess()
{
    /*
    Function to get user input - used to select the process to carry out
    */
    int process = 999; // defaults to unknown process
    cout << "\n\n************************\n1. Deposit \n2. Withdraw \n3. Check Account Balance \n0. Logout\n************************\n\nSelect process: ";
    cin >> process;
    return process;
}

int main()
{
    // global values
    double accountBalance = 0.0;
    const int DEFAULT_PIN = 1234;
    bool loggedIn = false;

    // login
    cout << "Greetings,\nKindly login to access your account.\n";
    loggedIn = checkPin(DEFAULT_PIN);

    if (loggedIn)
    {
        cout << "==================================" << endl;
        cout << "   -- Welcome to AWESOME BANK --   " << endl;
        cout << "==================================" << endl;
        while (loggedIn)
        {

            int process = getProcess();

            switch (process)
            {
            case 1:
            {
                // deposit and update account balance
                accountBalance = deposit(accountBalance);
                break;
            }
            case 2:
            {
                // withdraw and update account balance
                accountBalance = withdraw(accountBalance);
                break;
            }
            case 3:
            {
                // Check and display balance
                checkAccountBalance(accountBalance);
                break;
            }

            case 0:
            {
                // logout
                loggedIn = false;
                break;
            }
            default:
            {
                cout << "Unknown process. Try again" << endl;
                break;
            }
            }
        }
        cout << "Goodbye. \nThanks for banking with us." << endl;
    } // else - we don't exect to be here, unless the pin was incorrect, in which case, account gets locked
}
