#include <iostream>
#include <string>
#include <cmath>
#include <cstdlib>

using namespace std;
bool testLetterNumbers(string str);
bool testPassword(string str);

int main()
{
	/*Create a program that asks the user to enter a user name and password.
	After they havedone so, perform input validation on both.The user name should :
	Not have any characters other than letters or numbers
	Not start with a number
	The password should :
	Contain at least one non numeric or alphabetic character
	Contain at least one uppercase letter and one lowercase letter
	Contain at least one number
	Not contain three of the same letter in a row
	Continue asking for inputs until the user inputs correct values.*/

	string username, password;
	bool testLetterNumber, testPass;
	do
	{
		cout << "\n";
		cout << "Enter username:";
		getline(cin, username);
		cout << "Enter password: ";
		getline(cin, password);
		testLetterNumber = testLetterNumbers(username);
		testPass = testPassword(password);
	} while ((testLetterNumber == false) || (testPass == false));

	cout << "Your input is successfully created!\n";
	return 0;
} 
bool testLetterNumbers(string str)
{

	if (str == "")
	{
		cout << "Please input your username!" << endl;
		return false;
	}
	bool firstCharacter = true;
	if (isdigit(str[0]))
	{
		cout << "Username not start with a number" << endl;
		firstCharacter = false;
	}
		for (int i = 0; i < str.length(); i++)
		{
			
			if (!isalnum(str[i]))
			{
				cout << "Username not have any characters other than letters or numbers" << endl;
				return false;
			}
		}
		
	return firstCharacter;
}

bool testPassword(string str)
{

	if (str == "")
	{
		cout << "Please input your password!" << endl;
		return false;
	}
	str = str + " ";
	int length = str.length();
	
	/*
	Contain at least one non numeric or alphabetic character
	Contain at least one uppercase letter and one lowercase letter
	Contain at least one number
	Not contain three of the same letter in a row
	*/
	
	bool nonNumAlpha = false;
	bool lowerCase = false;
	bool upperCase = false;
	bool number = false;
	bool sameLetter = false;
	int count = 0;

	for (int i = 0; i < length; i++)
	{
		if (!isalnum(str[i]))
		{
			nonNumAlpha = true;
		}
		else if (islower(str[i]))
		{
			lowerCase = true;
		}
		else if (isupper(str[i]))
		{
			upperCase = true;
		}
		else if (isdigit(str[i]))
		{
			number = true;
		}
		if (str[i] == str[i + 1])
		{
			count++;
		}
	}

	if (nonNumAlpha == false)
	{
		cout << "The password should contain at least one non numeric or alphabetic character." << endl;
	}
	if (lowerCase == false)
	{
		cout << "The password should contain at least one lowercase letter." << endl;
	}
	if (upperCase == false)
	{
		cout << "The password should contain at least one uppercase letter." << endl;
	}
	if (number == false)
	{
		cout << "The password should contain at least one number." << endl;
	}
	if (count > 1)
	{
		cout << "The password should not contain three of the same letter in a row." << endl;
	}
	if ((nonNumAlpha == true) && (lowerCase == true) && (upperCase == true) && (number == true) && (count < 2))
	{
		return true;
	}
	return false;
}