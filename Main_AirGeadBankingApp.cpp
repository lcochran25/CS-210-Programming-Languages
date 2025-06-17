/**
* Author: Lukas Cochran
* Date: June 6, 2025
*
* This is the main function for the program. In this function we handle error resolution with input validation
*  and display the home screen to collect user input.
*
*/

#include<iostream>
#include<string>
#include<cmath>
#include<iomanip>

#include "AirGeadBankingApp.cpp"

using namespace std;


BankingApplication mySavings;
double m_initialDeposit;
double m_monthlyDeposit;
double m_annualInterest;
double months;
int years;
char user_input = 'a';
void PrintHomeScreen();
int validIntInput();
double validDoubleInput();

int main() {

while (user_input != 'q') {
		system("cls");
		PrintHomeScreen();

		mySavings.balanceWithoutMonthlyDeposit(mySavings.GetInitialDeposit(), mySavings.GetAnnualInterest(), mySavings.GetNumberYears());
		mySavings.balanceWithMonthlyDeposit(mySavings.GetInitialDeposit(), mySavings.GetMonthlyDeposit(), mySavings.GetAnnualInterest(), mySavings.GetNumberYears());

		cout << "Please enter 'q' to quit. Enter any other character or number to run another report. ";
		cin >> user_input;
	}

	return 0;
}

/**
 *Function that prints home screen and gets input from user.
 *
 */
void PrintHomeScreen() {
	try {
		cout << "**********************************" << endl;
		cout << "********** Data Input ************" << endl;
		cout << "Initial Investment Amount: $";

		m_initialDeposit = validDoubleInput();
		if (m_initialDeposit < 0) {
			throw runtime_error("Invalid entry, please try again.");
		}
		mySavings.SetInitialDeposit(m_initialDeposit);

		cout << "Monthly Deposit: $";
		m_monthlyDeposit = validDoubleInput();
		if (monthlyDeposit < 0) {
			throw runtime_error("Invalid entry, please try again.");
		}
		mySavings.SetMonthlyDeposit(m_monthlyDeposit);

		cout << "Annual Interest: ";
		m_annualInterest = validDoubleInput();;
		if (m_annualInterest < 0) {
			throw runtime_error("Invalid entry, please try again.");
		}
		mySavings.SetAnnualInterest(m_annualInterest);

		cout << "Number of years: ";
		years = validIntInput();
		if (years <= 0) {
			throw runtime_error("Invalid entry, please try again.");
		}
		mySavings.SetNumberYears(years);

		system("PAUSE");
	}

	// Displays error to user and asks displays home screen again
	catch (runtime_error& excpt) {
		cout << excpt.what() << endl;
		cout << "Cannot compute with negative value entered." << endl;
		system("PAUSE");
		system("cls");
		PrintHomeScreen();
	}
}

/**
 *
 *User input validation to verify the input is an integer value
 */

int validIntInput() {
	int x;

	while (1) {
		if (cin >> x) {
			// valid number
			break;
		}
		else {
			// not a valid number
			cout << "Invalid Input! Please input a numerical value.";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	return x;
}

/**
 *User input validation to verify input is a double value
 *
 */

double validDoubleInput() {
	double x;

	while (1) {
		if (cin >> x) {
			// valid number
			break;
		}
		else {
			// not a valid number
			cout << "Invalid Input! Please enter a valid number: ";
			cin.clear();
			while (cin.get() != '\n');
		}
	}

	return x;
}








