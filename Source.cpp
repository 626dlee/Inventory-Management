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
	vector<string> shelf;
	int id;
	int count;
	double sales_price;
public:
	//ID Commented out, when we have a use for it we can readd it, but will need to add a way to get one in add_item()
	Item(string n, string b, string t, string s, /*int i,*/ int c, double sp) {
		name = n;
		brand = b;
		type = t;
		shelf.push_back(s);
		//id = i;
		count = c;
		sales_price = sp;
	}
	//Getters each private variable Setters only for count and price

	string get_name() {
		return name;
	}
	vector<string> get_shelf() {
		return shelf;
	}
	string get_type() {
		return type;
	}
	int get_count() {
		return count;
	}
	void set_count(int c) {
		count = c;
	}
};

//May want to add an object to keep track of which items and how many are kept per shelf, eg 2 intel CPUS and 1 AMD CPU
class Shelf {
private:
	string shelf_loc;
	string type;
	bool full;
	int count;
	int max;
public:
	Shelf(string s, string t, int c, int m) {
		shelf_loc = s;
		type = t;
		count = c;
		max = m;
		set_full();
	}
	void set_full() {
		if (count == max)
			full = true;
		else
			full = false;
	}
	//getters and setters for each variable needed
	string get_type() {
		return type;
	}
	string get_shelfloc() {
		return shelf_loc;
	}
	int get_count() {
		return count;
	}
	void set_count(int c) {
		count = c;
		set_full();
	}
	int get_max() {
		return max;
	}
	bool is_full() {
		return full;
	}
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
	//Setters for each private variable

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
//Incomplete
//For finding the shelf, iterate through the shelf vector to find one of the correct type
//Return that type for the item if not full
void add_item(vector<Item> &ItemList, vector<Shelf> &ShelfList) {
	string name, brand, type, shelf;
	int id, count, sales_price;
	cout << "GIVE NAME" << endl;
	cin >> name;
	for (int i = 0; i < ItemList.size(); i++) {
		if (ItemList[i].get_name() == name) {
			cout << "GIVE COUNT" << endl;
			cin >> count;
			ItemList[i].set_count(ItemList[i].get_count() + count);
			//Add later: increment shelf its currently on
			//cout which shelf to put it on
			return;
		}
	}
	cout << "NO EXISTING ITEM, CREATING NEW ITEM" << endl;
	cout << "GIVE BRAND" << endl;
	cin >> brand;
	cout << "GIVE TYPE" << endl;
	cin >> type;
	cout << "GIVE COUNT" << endl;
	cin >> count;
	cout << "GIVE SALES PRICE" << endl;
	cin >> sales_price;

	//Logic to find a shelf and an ID number
	for (int k = 0; k < ShelfList.size(); k++) {
		if ((ShelfList[k].get_type() == type && !ShelfList[k].is_full) && (ShelfList[k].get_count() + count <= ShelfList[k].get_max())) {
			shelf = ShelfList[k].get_shelfloc();
			ShelfList[k].set_count(ShelfList[k].get_count() + count);
			ItemList.push_back(Item(name, brand, type, shelf, count, sales_price));
			cout << "Place item(s) in shelf" << shelf << endl;
			return;
		}
		else if (ShelfList[k].get_type() == type && !ShelfList[k].is_full()) {
			for (int j = 0; j < ShelfList.size(); j++) {
				if ((ShelfList[j].get_shelfloc() != ShelfList[k].get_shelfloc()) && 
					(count - (ShelfList[k].get_max() - ShelfList[k].get_count()) <= (ShelfList[j].get_max() - ShelfList[j].get_count()))) {
					shelf = ShelfList[k].get_shelfloc();
					ShelfList[k].set_count(ShelfList[k].get_max());
					ShelfList[j].set_count(ShelfList[j].get_count() + (count - (ShelfList[k].get_max() - ShelfList[k].get_count())));
					ItemList.push_back(Item(name, brand, type, shelf, count, sales_price));
					//Add function call to add second shelf to shelf vector in item, that function still needs to be made
					cout << "Place " << (ShelfList[k].get_max() - ShelfList[k].get_count()) << " items in shelf " << ShelfList[k].get_shelfloc()
						<< " and " << (count - (ShelfList[k].get_max() - ShelfList[k].get_count())) << " items in shelf " << ShelfList[j].get_shelfloc() << endl;
				}
			}
		}
		else {
			cout << "NO SHELF CAN FIT, TERMINATING ITEM ADDITION" << endl;
		}
	}
}
void remove_item(vector<Item> &ItemList) {
	string name;
	cout << "GIVE ITEM NAME TO REMOVE" << endl;
	cin >> name;
	
	//Later may want a helper function to output all items names in a list

	for (int i = 0; i < ItemList.size(); i++) {
		if (ItemList[i].get_name() == name) {
			//Modify shelf vector for this item still needed
			ItemList.erase(ItemList.begin() + i);
		}
	}
}
void add_account(vector<Account> &AccountList) {
	string user, pass;
	int auth;
	cout << "GIVE USER TO CREATE" << endl;
	cin >> user;
	cout << "GIVE PASS" << endl;
	cin >> pass;
	cout << "GIVE AUTH" << endl;
	cin >> auth;

	AccountList.push_back(Account(user, pass, auth));
}
void remove_account(vector<Account> &AccountList) {
	string user;
	cout << "GIVE USER TO DELETE" << endl;
	cin >> user;

	//Later may want a helper function to list all user names

	for (int i = 0; i < AccountList.size(); i++) {
		if (AccountList[i].get_user() == user) {
			AccountList.erase(AccountList.begin()+i);
		}
	}
}

//Change couts to be coherent
void login(bool *loggedIn, vector<Account> AccountList, int *auth) {
	string user, pass;
	int userLoc;
	int attempts = 0;
	cout << "GIVE USER or SHUTDOWN" << endl;
	cin >> user;
	//If keyword shutdown is passed, exits program
	if (user == "shutdown" || user == "SHUTDOWN") {
		exit(1);
	}
	else {
		//loops through account list to find the matching username
		for (int i = 0; i < AccountList.size(); i++) {
			if (user == AccountList[i].get_user()) {
				cout << "GIVE PASS" << endl;
				cin >> pass;
				//Gives 3 attemtps or until logged in successfully to give a correct password
				do {
					//If correct, it logs in, and makes it so the remaining accounts are not looked at
					if (pass == AccountList[i].get_pass()) {
						*loggedIn = true;
						*auth = AccountList[i].get_auth();
						i = AccountList.size();
					}
					//If wrong password, requests again, and increments attempt count
					else {
						cout << "WRONG" << endl;
						attempts++;
						cin >> pass;
					}
				} while (attempts < 2 && !*loggedIn);
			}

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
	vector<Shelf> ShelfList;
	//repeat for all item types and initialize with shelves for each type
	bool loggedIn = false;
	bool running = true;

	int auth = 0;

	AccountList.push_back(Account("Admin", "password", 5));

	while (running) {
		login(&loggedIn, AccountList, &auth);
		while (loggedIn) {
			//shutdown(&loggedIn, &running);
			add_account(AccountList);
			cout << "Account added" << endl;
			remove_account(AccountList);
			cout << "Account removed" << endl;
			logout(&loggedIn, &auth);
		}
	}


	return 0;
}
