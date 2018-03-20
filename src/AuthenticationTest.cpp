#include <iostream>
#include <string>
#include <fstream>
#include <istream>
using namespace std;

int main() {
	string userName = "";
	string passWord = "";
	int choice = 0;
	bool finished = false;
	ifstream readData;
	ofstream writeData;
	string auth;
	string individualUser;
	string authContents;
	bool login = false;

	cout << "Welcome to the Authentication Test. Sign up below! \nIf you have an account already, please enter your username and password.\n" << endl;
	cout << "1. Log in\n2. Sign up" << endl;

	while(!finished) {
		cin >> choice;
		switch(choice){
			case 1:
				cout << "Username : ";
				cin >> userName;
				cout << "Password : ";
				cin >> passWord;
				readData.open("authData.txt");
				auth = userName + passWord;
				while(getline(readData, individualUser) && !login){
					if(individualUser == auth)
						login = true;
				}
				if(login){
					cout << "You're in! :)" << endl;
					finished = true;
				}
				else
					cout << "Didn't find your username. Please sign up." << endl;
				readData.close();
				break;
			case 2:
				cout << "Username : ";
				cin >> userName;
				cout << "Password : ";
				cin >> passWord;
				auth = userName + passWord;
				writeData.open ("authData.txt");
				writeData << auth;
				writeData.close();
				cout << "Good stuff! You can now log in." << endl;
				break;
			case 3:
				finished = true;
				break;
			default:
				cout << "WRONG." << endl;
				break;
		}
	}
	return 0;
}
