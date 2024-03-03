using namespace std;

#include "UserInvestment.h"

// Define setter functions
void UserInvestment::setInitialInvestment(double t_initialInvestment) {
    this->m_initialInvestment = t_initialInvestment;
}

void UserInvestment::setMonthlyDeposit(double t_monthlyDeposit) {
    this->m_monthlyDeposit = t_monthlyDeposit;
}

void UserInvestment::setAnnualInterest(double t_annualInterest) {
    this->m_annualInterest = t_annualInterest;
}

void UserInvestment::setNumOfYears(int t_numOfYears) {
    this->m_numOfYears = t_numOfYears;
}

// Define calculation functions
double UserInvestment::calcInterestWithoutDeposits() {
    return (this->m_totalWithoutDeposits) * ((this->m_annualInterest / 100) / 12);
}

double UserInvestment::calcInterestWithDeposits() {
    return (this->m_totalWithDeposits) * ((this->m_annualInterest / 100) / 12);
}

// Functions to store total values during report display
void UserInvestment::setTotalWithoutDeposits(double t_amount) {
    this->m_totalWithoutDeposits += t_amount;
}

void UserInvestment::setTotalWithDeposits(double t_amount) {
    this->m_totalWithDeposits += t_amount;
}

// Getter functions for use during calculation
double UserInvestment::getTotalWithDeposits() {
    return this->m_totalWithDeposits;
}

double UserInvestment::getTotalWithoutDeposits() {
    return this->m_totalWithoutDeposits;
}