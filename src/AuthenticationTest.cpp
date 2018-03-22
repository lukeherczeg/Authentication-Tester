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
	while(getline(readData, tempUser)){
		if(tempUser == auth){
			exists = true;
			break;
		}
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
	string auth = "Username: " + userName + "    Password: " + passWord;

	bool login = false;
	ifstream readData;

	readData.open("authData.txt");
	while(getline(readData, tempUser)){
		if(tempUser == auth){
			login = true;
			break;
		}
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
	int count = 0;
	string choice2 = "";
	bool finished = false;

	cout << "\nWelcome to the Authentication Test. Sign up below! \nIf you have an account already, please enter your username and password.\n" << endl;
	cout << "\t1. Log in\n\t2. Sign up\n\t3. Print users\n\t4. Clear all users\n\t5. Exit" << endl;

	while(!finished) {
		cin >> choice;
		while (true){
			cin >> choice;

			if(cin.fail()){
				cin.clear(); //This corrects the stream.
				cin.ignore(); //This skips the left over stream data.
				if(count == 0)
					cout << "Please enter an Integer only." << endl;
				count++;
			}
			else{
				break;
			}
		}

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
		count = 0;
	}


	return 0;
}
