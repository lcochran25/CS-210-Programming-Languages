/**
* Author: Lukas Cochran
* Date:June 6, 2025
*
* Class file for banking application. This header file lists public and private data members
*
*/

#ifndef AIRGEADBANKINGAPP_H
#define AIRGEADBANKINGAPP_H



class BankingApplication {

//public data members
public:
    BankingApplication(); //default constructor
    void SetInitialDeposit(double initialDeposit);
    double GetInitialDeposit() const;
    void SetMonthlyDeposit(double monthlyDeposit);
    double GetMonthlyDeposit() const;
    void SetAnnualInterest(double annualInterest);
    double GetAnnualInterest() const;
    void SetNumberYears(int numberYears);
    int GetNumberYears() const;
    double balanceWithMonthlyDeposit(double initialDeposit, double monthlyDeposit, double annualInterest, int numberYears);
    double balanceWithoutMonthlyDeposit(double initialDeposit, double annualInterest, int numberYears);

//private data members
private:
    double initialDeposit;
    double monthlyDeposit;
    double annualInterest;
    double annualInterestAmount;
    double yearlyTotalInterest;
    int numberYears;
    double totalAmount;

};



#endif //AIRGEADBANKINGAPP_H
