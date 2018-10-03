#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Item
{
private:
	string name;
	string brand;
	string type;
	string shelf;
	int id;
	int count;
	double sales_price;
public:
	Item(string n, string b, string t, string s, int i, int c, double sp) {
		name = n;
		brand = b;
		type = t;
		shelf = s;
		id = i;
		count = c;
		sales_price = sp;
	}
	//Getters and Setters for each private variable
};


class Account
{
private:
	string username;
	string password;
	int authLevel;
	/*
	1 - Add, Remove Item
	2 - 
	3 - 
	4 - 
	5 - Everything
	*/
public:
	Account(string u, string p, int a) {
		username = u;
		password = p;
		authLevel = a;
	}
	//Getters and Setters for each private variable

	int get_auth() {
		return authLevel;
	}
	string get_user() {
		return username;
	}
	string get_pass() {
		return password;
	}
};

void add_item() {}
void remove_item() {}
void add_account() {}
void remove_account() {}

//Change couts to be coherent
void login(bool *loggedIn, vector<Account> AccountList, int *auth) {
	string user, pass;
	int userLoc;
	cout << "GIVE USER" << endl;
	cin >> user;
	for (int i = 0; i < AccountList.size(); i++) {
		if (user == AccountList[i].get_user()) {
			cout << "GIVE PASS" << endl;
			cin >> pass;
			do {
				if (pass == AccountList[i].get_pass()) {
					*loggedIn = true;
					*auth = AccountList[i].get_auth();
					i = AccountList.size();
				}
				else {
					cout << "WRONG" << endl;
					cin >> pass;
				}
			} while (!*loggedIn);
		}

	}

	
}
void logout(bool *loggedIn, int *auth) {
	*loggedIn = false;
	*auth = 0;
}

void shutdown(bool *loggedIn, bool *running) {
	*loggedIn = false;
	*running = false;
}


int main() {
	vector<Item> ItemList;
	vector<Account> AccountList;
	bool loggedIn = false;
	bool running = true;

	int auth = 0;

	AccountList.push_back(Account("Admin", "password", 5));

	while (running) {
		login(&loggedIn, AccountList, &auth);
		while (loggedIn) {
			shutdown(&loggedIn, &running);
		}
	}


	return 0;
}