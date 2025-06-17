/**
 *  Clock Program for Chada Tech
 *  Module Three Project - CS 210
 *
 *  Date: 05/24/2025
 *  Author: Lukas Cochran
 *
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <ctime>

using namespace std;

/**
 *
 *This function will display the current time when the program is run
*/
void displayClock(tm* localTime)
{
	// This computes AM/PM. The time format is by 24 hours so this creates the 12-hour clock
	int hour = localTime->tm_hour - 12;
	string timeOfDay;

	if (hour < 0) { //negative is between 12 midnight and 12 noon
		timeOfDay = "AM";
		hour += 12; //increase hours by 12. The hours are negative so we add 12 for the 12-hour clock
	}
	else {
		timeOfDay = "PM"; //it is more than 12 Noon so PM time
	}
	if (hour == 0) { //when the 24-hour time is 12:00:00
		hour = 12;
	}
	//Prints out the clock display side by side with 12-hour clock and 24-hour clock.
    cout << "***************************\t***************************" << endl;
	cout << "*      12-Hour Clock      *\t*      24-Hour Clock      *" << endl;
	cout << "*\t" << hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << " " << timeOfDay << "\t  *\t*\t"
		 << localTime->tm_hour << ":" << localTime->tm_min << ":" << localTime->tm_sec << timeOfDay << "\t  *" << endl;
	cout << "***************************\t***************************" << endl;
}

int main()
{
	// Function declarations
	time_t now = time(0); //creates a time object and initializes it to the current time.

	//tm is a struct type used to manipulate the time object and to access the hour, min and sec separately.
	tm* localTime = localtime(&now);  //gets local time

	displayClock(localTime);//Shows the initial time

	//full user menu display and selection of functions
	int userInput = 0;
	while (userInput != 4){
		cout << endl;
		cout << "***********************" << endl;
		cout << "* 1 - Add One Hour    *" << endl;
		cout << "* 2 - Add One Minute  *" << endl;
		cout << "* 3 - Add One Second  *" << endl;
		cout << "* 4 - Exit Program    *" << endl;
		cout << "***********************" << endl;

		cin >> userInput; //collect user input from menu

	    // allows the user to enter options 1-4
		if (userInput == 1)
		{
			localTime->tm_hour = (localTime->tm_hour + 1); //Add one hour to the time
			displayClock(localTime); //display the time
			cout << "You have added one hour. " << endl;

		}
		else if (userInput == 2)
		{
			localTime->tm_min = (localTime->tm_min + 1) % 60; //Add one minute to the time
			displayClock(localTime); //display the time
			cout << "You have added one minute. " << endl;
		}
		else if (userInput == 3)
		{
			localTime->tm_sec = (localTime->tm_sec + 1) % 60; //Add one second to the time
			displayClock(localTime); //display the time
			cout << "You have added one second. " << endl;
		}
		else if (userInput == 4) // exits program
			{
			    cout << "Time program has ended, thank you for using!" << endl;

			}
		else
		{
			cout << "Invalid selection. Please try again!" << endl;
		}

	}
	return 0;
}

