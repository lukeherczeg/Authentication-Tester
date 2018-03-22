#include <iostream>
#include <string>
#include <fstream>
#include <istream>
using namespace std;

void signUp(string userName, string passWord){
	bool exists = false;
	string auth = "Username: " + userName + "    Password: " + passWord;
	ifstream readData;
	string tempUser;

	readData.open("authData.txt");
	while(getline(readData, tempUser) && !exists){
		if(tempUser == auth)
			exists= true;
	}

	if(!exists){
		ofstream writeData;
		writeData.open ("authData.txt", ios_base::app);
		writeData << auth << endl;
		cout << "Good stuff! You can now log in." << endl;
		writeData.close();
	}
	else{
		cout << "That account exists silly! Go log in!" << endl;
	}
}

void logIn(string userName, string passWord, bool & finished){
	string tempUser;
	bool login = false;
	ifstream readData;
	string auth = "Username: " + userName + "    Password: " + passWord;

	readData.open("authData.txt");
	while(getline(readData, tempUser) && !login){
		if(tempUser == auth)
			login = true;
	}
	if(login){
		cout << "You're in! :)" << endl;
		finished = true;
	}
	else
		cout << "Didn't find your username. Please sign up." << endl;
	readData.close();
}

void printUsers(){
	ifstream readData;
	string tempUser;
	int count = 0;

	cout << "Users:" << endl;
	readData.open("authData.txt");
	while(getline(readData, tempUser)){
		count++;
		cout << count << ".) " << tempUser << endl;
	}
	if(count == 0)
		cout << "No users found.";
	readData.close();
}







int main() {
	string userName = "";
	string passWord = "";
	int choice = 0;
	string choice2 = "";
	bool finished = false;

	cout << "Welcome to the Authentication Test. Sign up below! \nIf you have an account already, please enter your username and password.\n" << endl;
	cout << "1. Log in\n2. Sign up\n3. Print users\n4. Exit\n5. Clear all users" << endl;

	while(!finished) {
		cin >> choice;
		switch(choice){
			case 1:
				cout << "Username : "; cin >> userName;
				cout << "Password : "; cin >> passWord;

				logIn(userName, passWord, finished);
				break;
			case 2:
				cout << "Username : "; cin >> userName;
				cout << "Password : "; cin >> passWord;

				signUp(userName, passWord);
				break;
			case 3:
				printUsers();
				break;
			case 4:
				cout << "Are you sure you want to clear all users? y/n : ";
				cin >> choice2;
				if(choice2 == "y")
					remove("authData.txt");
				else
					break;
				cin.clear();
				break;
			case 5:
				finished = true;
				break;
			default:
				cout << "WRONG." << endl;
				break;
		}
	}
	return 0;
}
