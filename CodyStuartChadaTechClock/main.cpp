/*
*	Name: Cody Stuart
*	Assignment: Chada Tech Clock (Project one)
* 
*/

//pre-processor declarations
#include <iostream>
#include <string>
#include <vector>

using namespace std; //assign this to avoid typing std:: in front of everything.

//global variables for hours, minutes, and seconds
unsigned int h, m, s;

string twoDigitString(unsigned int n) {
	string result;

	if ((n >= 0) && (n <= 9)) { //check if the integer parameter given is between 0 and 9
		result = "0" + to_string(n); // converts parameter n to string and appends 0 to the beginning
	}
	else { //for any number that is two digits already just convert it to a string.
		result = to_string(n);
	}

	return result;
}

string nCharString(size_t n, char c) {
	int i;
	string outputString; // string to output

	//use loop to append the desired char to a string continuously until the desired size has been reached.
	for (i = 0; i < n; i++) {
		outputString += c;
	}

	return outputString;
}

string formatTime24(unsigned int h, unsigned int m, unsigned int s) {
	string time24;
	time24 = twoDigitString(h) + ':' + twoDigitString(m) + ':' + twoDigitString(s); // this output time in the following format 23:59:59

	return time24;
}

string formatTime12(unsigned int h, unsigned int m, unsigned int s) {
	string time12; //return variable
	string meridiem; //String to hold AM or PM
	bool isPM = false; //If PM true, if AM false

	//Check if its between 12 (afternoon) and 11 (One hour before midnight)
	if ((h > 11) && (h <= 23)) {
		isPM = true;
		h -= 12;

	}

	//Whether or not its AM or PM 0 should be changed to 12
	if (h == 0) {
		h = 12;
	}

	//Set our AM or PM string after determing the time
	if (isPM) {
		meridiem = "P M";
	}
	else {
		meridiem = "A M";
	}

	//Build our string using our parameters
	time12 = twoDigitString(h) + ':' + twoDigitString(m) + ':' + twoDigitString(s) + " " + meridiem;

	return time12; // replace this placeholder with return of your formatted string
}

void printMenu(string strings[], unsigned int numStrings, unsigned int width) {
	int i; //loop variable
	int remainingWidth; //variable will be used to output spaces to the length of the rest of width

	cout << nCharString(width, '*') << endl; //Top bar of the menu
	
	//for each index(string) in the array of string output a line based on the following
	for (i = 0; i < numStrings; i++) {
		remainingWidth = 0; //reset to 0 for each line
		if (i != (numStrings - 1)) { //check to see if we are on the last string of the array
			cout << '*' << ' ' << i + 1 << ' ' << '-' << " " << strings[i]; // This outputs each string in the proper format i.e. "* 1 - Add one hour"
			remainingWidth = width - (6 + strings[i].size()); //determine how many spaces left in the line by subtracting from the width what we've already printed.
			cout << nCharString(remainingWidth - 1, ' ') << '*' << "\n" << endl; // finish printing the line

		}
		else { //same as the if but for the last string of the index, this is seperate so we don't put a newline out at the end
			cout << '*' << ' ' << i + 1 << ' ' << '-' << " " << strings[i];
			remainingWidth = width - (6 + strings[i].size());
			cout << nCharString(remainingWidth - 1, ' ') << '*' << endl;
		}

	}

	cout << nCharString(width, '*') << endl; //bottom of the menu box
}

unsigned int getMenuChoice(unsigned int maxChoice) {
	bool validChoice = false;
	int choice;

	while (!validChoice) { //continue until the choice is a valid one
		cout << "Please enter your choice: ";
		cin >> choice;

		if ((choice > 0) && (choice <= maxChoice)) { //make sure the user entered a number that is 1 or greater, and no more than the highest number of choices.
			validChoice = true;
		}
	}

	return choice;
}

void displayClocks(unsigned int h, unsigned int m, unsigned int s) {
	// cout 27 stars + 3 spaces + 27 stars + endl
	cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;

	// cout 1 star + 6 spaces + 12-HOUR CLOCK + 6 spaces + 1 star + 3 spaces
	cout << '*' << nCharString(6, ' ') << "12-HOUR CLOCK" << nCharString(6, ' ') << '*' << "   ";

	// cout 1 star + 6 spaces + 24-HOUR CLOCK + 6 spaces + 1 star + endl
	cout << '*' << nCharString(6, ' ') << "24-HOUR CLOCK" << nCharString(6, ' ') << '*' << endl;

	// cout an endl for a blank line
	cout << endl;

	// cout 1 star + 6 spaces + formatTime12(h, m, s) + 7 spaces + 1 star + 3 spaces
	cout << '*' << nCharString(6, ' ') << formatTime12(h, m, s) << nCharString(7, ' ') << '*' << "   ";

	// cout 1 star + 8 spaces + formatTime24(h, m, s) + 9 spaces + 1 star + endl
	cout << '*' << nCharString(8, ' ') << formatTime24(h, m, s) << nCharString(9, ' ') << '*' << endl;

	// cout 27 stars + 3 spaces + 27 stars + endl
	cout << nCharString(27, '*') << "   " << nCharString(27, '*') << endl;
}

int getSecond() {
	return s; //returns the value of the global variable s
}

int getMinute() {
	return m; //returns the value of the global variable m
}

int getHour() {
	return h; //returns the value of the global variable h
}

void setSecond(unsigned int s) {
	::s = s; //sets the value of the global variable s to the value of the passed in parameter s
}

void setMinute(unsigned int m) {
	::m = m; //sets the value of the global variable m to the value of the passed in parameter m
}

void setHour(unsigned int h) {
	::h = h; //sets the value of the global variable h to the value of the passed in parameter h
}

void addOneHour() {

	int h = getHour(); //assigns the value of the global variable h to the local variable h

	//check if the hours needs to be reset to 0 or if we can just add one
	if ((h >= 0) && (h <= 22)) {
		setHour(h + 1);
	}
	else if (h == 23) {
		setHour(0);
	}
}

void addOneMinute() {
	int m = getMinute(); //assigns the value of the global variable m to the local variable m

	//check if the minutes needs to be reset to 0 or if we can just add one
	if ((m >= 0) && (m <= 58)) {
		setMinute(m + 1);
	}
	else if (m == 59) {
		setMinute(0);
		addOneHour(); //update hours as well because 60 minutes is one hour and if we hit 60 we need to start the hour over from 0
	}
}

void addOneSecond() {
	int s = getSecond(); //assigns the value of the global variable s to the local variable s

	//check if the seconds needs to be reset to 0 or if we can just add one
	if ((s >= 0) && (s <= 58)) {
		setSecond(s + 1);
	}
	else if (s == 59) {
		setSecond(0);
		addOneMinute(); //update minutes as well because 60 seconds is one minute and if we hit 60 we need to start the minute over from 0
	}
}

void getInitialTime() {
	unsigned int validTimeInput = 0; //use this integer to validate if hours, minutes, and seconds are all valid.

	//There is probably a smarter way to do this, but create a bool initialized to false as a loop variable for hours/minutes/seconds
	bool validHours = false;
	bool validMinutes = false;
	bool validSeconds = false;

	//Tell the user the paramters for each entry
	cout << "Hours must be between 0 and 23\n" << "Minutes and seconds must be between 0 and 59" << endl;
	cout << "Please enter the initial time: " << endl;

	while (!validHours) { //loop to validate hours
		if (!validHours) {
			cout << "Hours: ";
			cin >> h;
			if ((h >= 0) && (h <= 23)) { //sets the loop variable to true only if hours is a valid number
				validHours = true;
			}
		}
	}
	while (!validMinutes) {
		if (!validMinutes) {
			cout << "Minutes: ";
			cin >> m;
			if ((m >= 0) && (m <= 59)) {  //sets the loop variable to true only if minutes is a valid number
				validMinutes = true;
			}
		}
	}
	while (!validSeconds) {
		if (!validSeconds) {
			cout << "Seconds: ";
			cin >> s;
			if ((s >= 0) && (s <= 59)) {  //sets the loop variable to true only if seconds is a valid number
				validSeconds = true;
			}
		}
	}
}

int main() {

	string menuStrings[4] = {"Add one hour", "Add one minute", "Add one second", "Exit"}; //array of strings to hold the menu options.
	

	getInitialTime();


	bool running = true; //assume the program starts and is running
	int userChoice; //variable to hold the menu choice of the user

	//allow user to continuously be prompted for input until they wish to exit the while loop
	while (running) {
		cout << nCharString(100, '-') << endl; //creates a break between each loop of the program
		displayClocks(h, m, s);
		cout << endl;

		printMenu(menuStrings, 4, 25);
		cout << endl;

		userChoice = getMenuChoice(4); //Get the user's choice
		cout << endl;

		switch (userChoice) { //determine what to do with the user's choice with a switch/case statement
		case 1:
			addOneHour();
			break;
		case 2:
			addOneMinute();
			break;
		case 3:
			addOneSecond();
			break;
		case 4:
			running = false;
			break;
		}
	}
	return 0;
}