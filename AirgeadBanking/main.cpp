/*
 * Name: Kyunghoon Lee
 * Date: 11 February 2024
 * CS-210
 * Project 2
 */

#include <iostream>
#include <string>
#include <stdexcept>
#include "UserInvestment.h"
#include "UserInvestmentCalc.h"

using namespace std;

// Function definitions
void mainMenu() {
    UserInvestment userInvestment;

    // User input variables
    double initialAmount;
    double monthlyDeposit;
    double interest;
    int years;

    string continueApp;  // Variable to store quit condition
    bool keepRunning = true;  // Ties in with continueApp to store quit condition

    do {
        cout << "************************************" << endl;
        cout << "************ Data Input ************" << endl;

        // Get user inputs, with validation
        while (true) {
            cout << "Initial Investment Amount: $";
            if (cin >> initialAmount && initialAmount >= 0) {
                break;
            }
            else {
                cout << "Input must be non-negative. Please try again." << endl;
                cin.clear();
                cin.ignore(256, '\n');
            }
        }

        while (true) {
            cout << "Monthly Deposit: $";
            if (cin >> monthlyDeposit && monthlyDeposit >= 0) {
                break;
            }
            else {
                cout << "Input must be non-negative. Please try again." << endl;
                cin.clear();
                cin.ignore(256, '\n');
            }
        }

        while (true) {
            cout << "Annual Interest: %";
            if (cin >> interest && interest >= 0) {
                break;
            }
            else {
                cout << "Input must be non-negative. Please try again." << endl;
                cin.clear();
                cin.ignore(256, '\n');
            }
        }

        while (true) {
            cout << "Number of years: ";
            if (cin >> years && years >= 0) {
                break;
            }
            else {
                cout << "Input must be non-negative. Please try again." << endl;
                cin.clear();
                cin.ignore(256, '\n');
            }
        }

        // Call setter functions to input into variables
        userInvestment.setInitialInvestment(initialAmount);
        userInvestment.setMonthlyDeposit(monthlyDeposit);
        userInvestment.setAnnualInterest(interest);
        userInvestment.setNumOfYears(years);

        cout << endl;

        // Print the data back to the user
        cout << "You entered:" << endl;
        cout << "Initial Investment Amount: " << "$" << userInvestment.getInitialInvestment() << endl;
        cout << "Monthly Deposit: " << "$" << userInvestment.getMonthlyDeposit() << endl;
        cout << "Annual Interest: " << "%" << userInvestment.getAnnualInterest() << endl;
        cout << "Number of years: " << userInvestment.getNumOfYears() << endl;

        cout << "Press ENTER/RETURN to continue. . .";
        cout << endl;

        /*
         * This should wait for a key press from the user to display the reports. I tried system(pause)
         * at first but that only works on Windows. This still requires the user to specifically press enter,
         * but I felt it was the best implementation beyond making this way more complex.
         */
        cin.ignore();
        cin.get();

        // Calls functions to display report 1 and 2 plus exception handling
        try {
            UserDataCalculations::dataWithoutDeposits(userInvestment);
        }
        catch (const exception& e) {
            cout << e.what() << endl;
            cout << "Exception occurred with dataWithoutDeposits()" << endl;
            keepRunning = false;
        }

        try
        {
            UserDataCalculations::dataWithDeposits(userInvestment);
        }
        catch (const exception& e)
        {
            cout << e.what() << endl;
            cout << "Exception occurred with dataWithDeposits()" << endl;
            keepRunning = false;
        }

        cout << endl;

        // Checks if user wants to quit, plus input validation
        while (true) {
            cout << "Would you like to start over? (Y/N)" << endl;
            cin >> continueApp;

            // Convert input to type char to account for lowercase
            for (char &c : continueApp) {
                c = toupper(c);
            }

            if (continueApp == "N") {
                keepRunning = false;
                break;
            }
            else if (continueApp == "Y") {
                break;
            }
            else {
                cout << "Invalid input. Please enter 'Y' or 'N'." << endl;
            }
        }

    } while (keepRunning);
}

// Main function
int main() {
    try {
        mainMenu();
    }
    catch (const exception& e) {
        cout << e.what() << endl;
        cout << "Exception occurred with mainMenu()" << endl;
        cin.get();
        return 1;
    }
    return 0;
}