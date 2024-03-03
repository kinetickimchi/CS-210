#include <iostream>
#include <iomanip>
#include "UserInvestmentCalc.h"

using namespace std;

void UserDataCalculations::dataWithoutDeposits(UserInvestment t_userInvestment) {
    // Initialize variables with data for table
    double initialInvestment = t_userInvestment.getInitialInvestment();
    int years = t_userInvestment.getNumOfYears();

    // Report 1 header
    cout << endl;
    cout << " Balance and Interest Without Additional Monthly Deposits\n";
    cout << setw(60) << setfill('=') << "\n";
    cout << " Year\t\tYear End Balance\tYear End Earned Interest" << endl;
    cout << setw(60) << setfill('-') << "\n";

    // Add initial investment to total for calculating consecutive years
    t_userInvestment.setTotalWithoutDeposits(initialInvestment);

    // Initialize interest total for the year to 0
    double interestYTD = 0;

    // Variables for incrementing year and month during the loop
    unsigned int yearCount;
    unsigned int monthCount;

    // Perform calculations for report without monthly deposit
    for (yearCount = 1; yearCount <= years; ++yearCount) {
        for (monthCount = 1; monthCount <= 12; ++monthCount) {
            interestYTD += t_userInvestment.calcInterestWithoutDeposits();
        }
        t_userInvestment.setTotalWithoutDeposits(interestYTD);

        cout << setprecision(2) << fixed << "    " << yearCount << setfill(' ') << setw(19);
        cout << "$" << t_userInvestment.getTotalWithoutDeposits() << setw(24) << "$" << interestYTD << "\n";

        interestYTD = 0; // Reset to 0 for calculating the next year
    }
}

void UserDataCalculations::dataWithDeposits(UserInvestment t_userInvestment) {
    // Initialize variables with data for table
    double initialInvestment = t_userInvestment.getInitialInvestment();
    double monthlyDeposit = t_userInvestment.getMonthlyDeposit();
    int years = t_userInvestment.getNumOfYears();

    // Report 2 header
    cout << "\n\n";
    cout << "   Balance and Interest With Additional Monthly Deposits\n";
    cout << setw(60) << setfill('=') << "\n";
    cout << " Year" << "\t\tYear End Balance" << "\tYear End Earned Interest" << endl;
    cout << setw(60) << setfill('-') << "\n";

    // Add initial investment to total for calculating consecutive years
    t_userInvestment.setTotalWithDeposits(initialInvestment);

    // Initialize interest total for the year to 0
    double interestYTD = 0;

    // Variables for incrementing year and month during the loop
    unsigned int yearCount;
    unsigned int monthCount;

    // Perform calculations for report with monthly deposit
    for (yearCount = 1; yearCount <= years; ++yearCount) {
        for (monthCount = 1; monthCount <= 12; ++monthCount) {
            t_userInvestment.setTotalWithDeposits(monthlyDeposit);
            double interest = t_userInvestment.calcInterestWithDeposits();
            t_userInvestment.setTotalWithDeposits(interest);
            interestYTD += interest;
        }

        // Had trouble figuring out how to properly justify the center and right columns here due to changing digits...
        cout << setprecision(2) << fixed << "    " << yearCount << setfill(' ') << setw(15);
        cout << right << '$' << t_userInvestment.getTotalWithDeposits() << setw(24) << right << "$" << interestYTD << "\n";

        interestYTD = 0; // Reset to 0 for calculating the next year
    }
}