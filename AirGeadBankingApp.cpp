/**
*
*Author: Lukas Cochran
*Date: June 6, 2025
*
*This lists accessors and mutators (getter and setters) to be called in the main function. They will store
*different user inputs for each respective category.
*
*/



#include<iostream>
#include<iomanip>
#include "AirGeadBankingApp.h"

using namespace std;

//default constructor with initialized values
BankingApplication::BankingApplication() {
    initialDeposit = 1.0;
    monthlyDeposit = 0.0;
    annualInterest = 0.0;
    numberYears = 0;
}

double initialDeposit;
double monthlyDeposit;
double annualInterest;
int numberYears;

//setter
void BankingApplication::SetInitialDeposit(double initialDeposit) {
    this->initialDeposit = initialDeposit;
}
//getter
double BankingApplication::GetInitialDeposit() const {
    return initialDeposit;
}
//setter
void BankingApplication::SetMonthlyDeposit(double monthlyDeposit) {
    this->monthlyDeposit = monthlyDeposit;
}
//getter
double BankingApplication::GetMonthlyDeposit() const {
    return monthlyDeposit;
}
//setter
void BankingApplication::SetAnnualInterest(double annualInterest) {
    this->annualInterest = annualInterest;
}
//getter
double BankingApplication::GetAnnualInterest() const {
    return annualInterest;
}
//setter
void BankingApplication::SetNumberYears(int numberYears) {
    this->numberYears = numberYears;
}
//getter
int BankingApplication::GetNumberYears() const {
    return numberYears;
}


/**
 *
 * @param initialDeposit
 * @param annualInterest
 * @param numberOfYears
 * @return balances and interest without monthly deposit
 */
double BankingApplication::balanceWithoutMonthlyDeposit(double initialDeposit, double annualInterest, int numberOfYears) {
    totalAmount = initialDeposit;

    // Displays the table heading
    cout << endl << "     Balance and Interest Without Additional Monthly Deposits" << endl;
    cout << std::string(70, '=') << endl;
    cout << "Year          Year End Balance          Year End Earned Interest" << endl;
    cout << std::string(70, '=') << endl;

    //Calculate yearly interest and year-end totals
    for (int i = 0; i < numberOfYears; i++) {
        annualInterestAmount = totalAmount * (annualInterest / 100);
        totalAmount = totalAmount + annualInterest;
        cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t\t$" << annualInterestAmount << endl;
}

return totalAmount;
}


/**
 *
 * @param initialDeposit
 * @param monthlyDeposit
 * @param annualInterest
 * @param numberOfYears
 * @return balances and interest with monthly deposit
 */
double BankingApplication::balanceWithMonthlyDeposit(double initialDeposit, double monthlyDeposit, double annualInterest, int numberOfYears) {
    totalAmount = initialDeposit;

    // Displays the table heading
    cout << endl << "     Balance and Interest With Additional Monthly Deposits" << endl;
    cout << std::string(70, '=') << endl;
    cout << "Year          Year End Balance          Year End Earned Interest" << endl;
    cout << std::string(70, '=') << endl;

    // Calculates yearly interest and year-end totals
    for (int i = 0; i < numberOfYears; i++) {
        yearlyTotalInterest = 0;

        for (int j = 0; j < 12; j++) {
            annualInterestAmount = (totalAmount + monthlyDeposit) * ((annualInterest / 100.00) / 12.00);
            yearlyTotalInterest = yearlyTotalInterest + annualInterestAmount;
            totalAmount = totalAmount + monthlyDeposit + annualInterestAmount;
}

        cout << " " << left << setw(5) << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t\t$" << yearlyTotalInterest << endl;
}

return totalAmount;
}