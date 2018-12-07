#ifndef WINDOW_H
#define WINDOW_H

#include <QWidget>
#include <QPushButton>
#include <QString>
#include <QTextEdit>
#include <QLineEdit>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <fstream>

class Item
{
private:
    std::string name;
    std::string brand;
    std::string type;
    std::vector<std::string> shelf;
    //int id;
    int count;
    double sales_price;
public:
    //Constructor used when loading the data to the system
    Item(std::string n, std::string b, std::string t, std::vector<std::string> s, int c, double sp) {
        name = n;
        brand = b;
        type = t;
        shelf = s;
        count = c;
        sales_price = sp;
    }
    //Most used constructor, used with Add Item
    Item(std::string n, std::string b, std::string t, int c, double sp){
        name = n;
        brand = b;
        type = t;
        count = c;
        sales_price = sp;
    }
    //Getters each private variable Setters only for count and price

    std::string get_name() {
        return name;
    }
    std::string get_brand() {
        return brand;
    }
    std::vector<std::string> get_shelf() {
        return shelf;
    }
    std::string get_type() {
        return type;
    }
    int get_count() {
        return count;
    }
    void set_count(int c) {
        count = c;
    }
    void change_count(int c) {
        count = count + c;
    }
    void new_shelf(std::string s) {
        shelf.push_back(s);
    }
    void remove_shelf(std::string s){
        for (uint i = 0; i<shelf.size();i++){
            if (shelf[i] == s){
                shelf.erase(shelf.begin() + i);
            }
        }
    }
    double get_sp(){
        return sales_price;
    }
};

class Shelf {
private:
    std::string shelf_loc;
    std::string type;
    bool full;
    int count;
    int max;
    int remaining;
    std::vector<std::string> storedNames;
    std::vector<int> storedCount;
public:
    Shelf(std::string s, std::string t, int c, int m) {
        shelf_loc = s;
        type = t;
        count = c;
        max = m;
        remaining = max - count;
        set_full();
    }
    Shelf(std::string s, std::string t, int m, int c, std::vector<std::string> sName, std::vector<int> sCount){
        shelf_loc = s;
        type = t;
        max = m;
        count = c;
        storedNames = sName;
        storedCount = sCount;
        remaining = max - count;
        set_full();
    }
    void set_full() {
        remaining = max - count;
        if (remaining <= 0)
            full = true;
        else
            full = false;
    }
    //getters and setters for each variable needed
    std::string get_type() {
        return type;
    }
    std::string get_shelfloc() {
        return shelf_loc;
    }
    int get_count() {
        return count;
    }
    int get_remaining() {
        return remaining;
    }
    void set_count(int c) {
        count = c;
        remaining = max - count;
        set_full();
    }
    int get_max() {
        return max;
    }
    bool is_full() {
        return full;
    }
    void new_store(std::string n, int c) {
        storedNames.push_back(n);
        storedCount.push_back(c);
        count = count + c;
        remaining = max - count;
        set_full();
    }
    void change_store(std::string n, int c) {
        for (uint i = 0; i < storedNames.size(); i++) {
            if (storedNames[i] == n) {
                storedCount[i] = storedCount[i] + c;
                count = count + c;
                remaining = max - count;
                set_full();
                return;
            }
        }
        new_store(n, c);
    }
    std::string remove_store(std::string n) {
        std::string removedItem = "";
        for (uint i = 0; i < storedNames.size(); i++) {
            if (storedNames[i] == n) {

                //cout << "Remove " << storedCount[i] << " " << storedNames[i] << " from shelf " << shelf_loc << endl;
                removedItem.append("Remove ");
                removedItem.append(std::to_string(storedCount[i]));
                removedItem.append(" ");
                removedItem.append(storedNames[i]);
                removedItem.append(" from shelf ");
                removedItem.append(shelf_loc);
                storedNames.erase(storedNames.begin() + i);
                count = count - storedCount[i];
                storedCount.erase(storedCount.begin() + i);
                remaining = max - count;
                set_full();
                return removedItem;
            }
        }
        return "Item not found";
    }
    int sell_store(std::string n, int c){
        int temp;
        for (uint i = 0; i < storedNames.size(); i++){
            if (storedNames[i] == n){
                if (storedCount[i] > c && c != 0){
                    storedCount[i] = storedCount[i] - c;
                    count -= c;
                    remaining = max - count;
                    return 0;
                }
                else if(storedCount[i] == c && c != 0){
                    storedNames.erase(storedNames.begin() + i);
                    storedCount.erase(storedCount.begin() + i);
                    count -= c;
                    remaining = max - count;
                    return -1;
                }
                else if(storedCount[i] > 0 && c != 0){
                    temp = storedCount[i];
                    storedNames.erase(storedNames.begin() + i);
                    storedCount.erase(storedCount.begin() + i);
                    count -= temp;
                    remaining = max - count;
                    return c - temp;
                }
            }
        }
        //This removes the warning, may want to send some number back instead of 0 to be an error check in case
        //it tries to sell an item from a shelf its not on, shouldn't happen since remove deletes the item and
        //sell deletes specific shelves from the item once they have no more of the item left
        return 0;
    }
    std::vector<std::string> get_storedNames() {
        return storedNames;
    }
    std::vector<int> get_storedCount() {
        return storedCount;
    }
};

class Account
{
private:
    std::string username;
    std::string password;
    int authLevel;
public:
    Account(std::string u, std::string p, int a) {
        username = u;
        password = p;
        authLevel = a;
    }
    //Setters for each private variable

    int get_auth() {
        return authLevel;
    }
    std::string get_user() {
        return username;
    }
    std::string get_pass() {
        return password;
    }
    void set_pass(std::string p){
        password = p;
    }
    void set_auth(int a){
        authLevel = a;
    }
};

class EmployeeAct
{
private:
    std::string user;
    std::string action;
    time_t timestamp;
public:
    EmployeeAct(std::string u, std::string a){
        user = u;
        action = a;
        time(&timestamp);
    }
    EmployeeAct(std::string u, std::string a, time_t t){
        user = u;
        action = a;
        timestamp = t;
    }
    std::string get_user(){
        return user;
    }
    std::string get_action(){
        return action;
    }
    time_t get_time(){
        return timestamp;
    }
    std::string get_timestamp(){
        std::string ts;
        ts = ctime(&timestamp);
        ts[ts.size() - 1] = '\0';

        return ts;
    }
};

class Financial
{
private:
    std::string name;
    int count;
    int dollar;
    int cents;
    std::string type;
    time_t timestamp;
public:
    Financial(std::string n, int c, double d, std::string t){
        name = n;
        count = c;
        if (t == "SELL"){
            d = d * c;
        }
        dollar = d;
        cents = (d * 100);
        cents = cents % 100;
        type = t;
        time (&timestamp);
    }
    Financial(std::string n, std::string t, int c, int d, int ce, time_t ts){
        name = n;
        count = c;
        dollar = d;
        cents = ce;
        type = t;
        timestamp = ts;
    }
    std::string get_name(){
        return name;
    }
    int get_count(){
        return count;
    }
    int get_dollar(){
        return dollar;
    }
    int get_cents(){
        return cents;
    }
    std::string get_type(){
        return type;
    }
    time_t get_time(){
        return timestamp;
    }
    std::string get_timestamp(){
        std::string ts;
        ts = ctime(&timestamp);
        ts[ts.size() - 1] = '\0';

        return ts;
    }
};

class EmployeeTime{
private:
    std::string uName;
    time_t inTime;
    time_t outTime;
    bool complete;
public:
    EmployeeTime(std::string name){
        uName = name;
        time(&inTime);
        complete = false;
    }
    EmployeeTime(std::string name, bool done, time_t in, time_t out){
        uName = name;
        complete = done;
        inTime = in;
        outTime = out;
    }
    EmployeeTime(std::string name, bool done, time_t in){
        uName = name;
        complete = done;
        inTime = in;
    }
    void clock_out(){
        time(&outTime);
        complete = true;
    }
    time_t get_inTime(){
        return inTime;
    }
    time_t get_outTime(){
        return outTime;
    }
    std::string get_uName(){
        return uName;
    }
    bool is_complete(){
        return complete;
    }
};

class Window : public QWidget
{
    Q_OBJECT
public:
    explicit Window(QWidget *parent = nullptr);
    void login(std::string uName, std::string pName);
    void HideAll();
    void MainMenu();
    void add_account(std::string userName, std::string password, int auth);
    void remove_account(std::string userName);
    void change_shelf();
    void display_report();
    void add_item(std::string name, std::string brand, std::string type, int count, double sales_price, double cost);
    void remove_item(std::string name);
    void sell_item(std::string name, int count);
    void change_password(std::string oldPass, std::string newPass, std::string confirmPass);
    void change_auth(std::string userName, int newAuth);
    void load_items();
    void store_items();
    void load_shelves();
    void store_shelves();
    void load_acc();
    void store_acc();
    //For timestamps copy the portion of ehour that reads/stores using a tmp var struct tm t
    void load_ereport();
    void store_ereport();
    void load_freport();
    void store_freport();
    void load_ehour();
    void store_ehour();

private:
    //Necessary Variables
    int currentAuth;
    int removeWarning;
    std::string currentUser;
    //Data structures
    std::vector<Item> ItemList;
    std::vector<Account> AccountList;
    std::vector<Shelf> ShelfList;
    std::vector<EmployeeAct> EmployeeReport;
    std::vector<Financial> FinancialReport;
    std::vector<EmployeeTime> EmployeeHours;
    //Login
    QLineEdit *loginUInput;
    QLineEdit *loginPInput;
    QTextEdit *UText;
    QTextEdit *PText;
    QTextEdit *UWrong;
    QTextEdit *PWrong;
    QPushButton *loginButton;
    //Main Menu
    QTextEdit *notification;
    QPushButton *clockIn;
    QPushButton *clockOut;
    QPushButton *gotoAddItem;
    QPushButton *gotoRemoveItem;
    QPushButton *gotoAddAccount;
    QPushButton *gotoRemoveAccount;
    QPushButton *logoutButton;
    QPushButton *gotoSellItem;
    QPushButton *gotoFinancial;
    QPushButton *gotoChangeAuth;
    QPushButton *gotoChangePass;
    QPushButton *gotoEmployeeReport;
    QPushButton *gotoItemSearch;
    QPushButton *gotoShelfList;
    QPushButton *gotoItemList;
    QPushButton *gotoEmployeeHours;
    //Add Item
    QTextEdit *itemName;
    QTextEdit *itemBrand;
    QTextEdit *itemType;
    QTextEdit *itemCount;
    QTextEdit *itemPrice;
    QTextEdit *itemCost;
    QLineEdit *inName;
    QLineEdit *inBrand;
    QLineEdit *inType;
    QLineEdit *inCount;
    QLineEdit *inPrice;
    QLineEdit *inCost;
    QPushButton *addItem;
    QPushButton *addItemCancel;
    //Sell Item
    QTextEdit *sellName;
    QTextEdit *sellCount;
    QLineEdit *sName;
    QLineEdit *sCount;
    QPushButton *sellItem;
    QPushButton *sellItemCancel;
    //Remove Item
    QTextEdit *removeName;
    QLineEdit *rName;
    QPushButton *removeItem;
    QPushButton *removeItemCancel;
    //Item Search
    QTextEdit *searchName;
    QLineEdit *searchIn;
    QPushButton *searchItem;
    QPushButton *searchCancel;
    QTextEdit *itemInfo;
    QPushButton *searchReturn;
    QTextEdit *searchFail;

    //Warning info
    QTextEdit *noItem;
    QTextEdit *noCount;

    //Report Info
    QTextEdit *reportInfo;
    QPushButton *reportNext;

    //Update Shelf window
    QTextEdit *changedShelf;
    QPushButton *shelfNext;

    //Change Password
    QTextEdit *oldPassText;
    QTextEdit *newPassText;
    QTextEdit *confirmNewPass;
    QLineEdit *oldPassIn;
    QLineEdit *newPassIn;
    QLineEdit *confirmIn;
    QPushButton *changePass;
    QPushButton *changePassCancel;
    QTextEdit *noMatch;
    QTextEdit *wrongPassChange;
    QTextEdit *blankPassword;

    //Change Auth
    QTextEdit *aUserText;
    QTextEdit *aAuthText;
    QTextEdit *aNoUser;
    QLineEdit *aUser;
    QLineEdit *aAuth;
    QPushButton *changeAuth;
    QPushButton *changeAuthCancel;

    //Add Account
    QTextEdit *newUser;
    QTextEdit *newPass;
    QTextEdit *newAuth;
    QLineEdit *NewUInput;
    QLineEdit *NewPInput;
    QLineEdit *NewAInput;
    QTextEdit *authTypes;
    QTextEdit *invalidAcc;
    QPushButton *newAccount;
    QPushButton *accountReturn;
    //Remove Account
    QTextEdit *remUser;
    QTextEdit *noUser;
    QLineEdit *rUserInput;
    QPushButton *removeAccount;

    QPushButton *quitButton;
signals:

public slots:
    void slotLoginClicked();
    void slotLogoutClicked();

    void slotAddItemUI();
    void slotAddItemCancel();
    void slotAddItem();

    void slotSellItemUI();
    void slotSellItemCancel();
    void slotSellItem();

    void slotRemoveItemUI();
    void slotRemoveItem();
    void slotRemoveItemCancel();

    void slotSearchItemUI();
    void slotSearchItem();
    void slotSearchItemCancel();
    void slotSearchReturn();

    void slotClockIn();
    void slotClockOut();

    void slotItemListUI();
    void slotShelfListUI();
    void slotFReportUI();
    void slotEReportUI();
    void slotEHoursUI();
    void slotReportDone();

    void slotChangePassUI();
    void slotChangePass();
    void slotChangePassCancel();

    void slotChangeAuthUI();
    void slotChangeAuth();
    void slotChangeAuthCancel();

    void slotShelfNext();
    void slotAddAccountUI();
    void slotAddAccount();
    void slotRemoveAccountUI();
    void slotRemoveAccount();
    void slotAccountCancel();
};

#endif // WINDOW_H
