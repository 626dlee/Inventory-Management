#include "window.h"
#include <QApplication>

Window::Window(QWidget *parent) : QWidget(parent)
{
    //Declarations

    load_items();
    load_shelves();
    load_ehour();
    load_acc();
    load_freport();
    load_ereport();

    setFixedSize(800,600);

    //Login
    UText = new QTextEdit("Username:",this);
    UText->setGeometry(250,300,100,30);
    PText = new QTextEdit("Password:",this);
    UText->setReadOnly(true);
    PText->setGeometry(250,350,100,30);
    PText->setReadOnly(true);
    UWrong = new QTextEdit("Wrong Username",this);
    UWrong->setGeometry(470,300,110,30);
    UWrong->setReadOnly(true);
    UWrong->setVisible(false);
    PWrong = new QTextEdit("Wrong Password",this);
    PWrong->setGeometry(470,350,110,30);
    PWrong->setReadOnly(true);
    PWrong->setVisible(false);
    loginUInput = new QLineEdit(this);
    loginUInput->setGeometry(320,300,150,30);
    loginPInput = new QLineEdit(this);
    loginPInput->setGeometry(320,350,150,30);
    loginPInput->setEchoMode(QLineEdit::Password);
    loginButton = new QPushButton("Login",this);
    loginButton->setGeometry(350,400,100,30);
    connect(loginButton,SIGNAL(clicked()),this,SLOT(slotLoginClicked()));

    //Main Menu
    notification = new QTextEdit("",this);
    notification->setReadOnly(true);
    notification->setAlignment(Qt::AlignCenter);
    notification->setVisible(false);
    notification->setGeometry(250,75,300,30);

    clockIn = new QPushButton("Clock in",this);
    clockIn->setGeometry(280,150,110,30);
    clockOut = new QPushButton("Clock out",this);
    clockOut->setGeometry(410,150,110,30);
    gotoAddItem = new QPushButton("Add Item",this);
    gotoAddItem->setGeometry(215,200,110,30);
    gotoSellItem = new QPushButton("Sell Item",this);
    gotoSellItem->setGeometry(215,250,110,30);
    gotoRemoveItem = new QPushButton("Remove Item",this);
    gotoRemoveItem->setGeometry(215,300,110,30);
    gotoItemSearch = new QPushButton("Item Search",this);
    gotoItemSearch->setGeometry(215,350,110,30);
    //200 gap -> 215
    //200-310 -> 215 - 325
    //310-330 -> 335 mid : 110 long -> 55 -> 280 start
    //330-440 -> 345 - 455
    //440-460 -> 465 mid : 110 long -> 55 -> 410 start
    //460-570 -> 475 - 585
    //230 gap -> 215

    gotoChangePass = new QPushButton("Change Password",this);
    gotoChangePass->setGeometry(345,200,110,30);
    gotoAddAccount = new QPushButton("Add Account",this);
    gotoAddAccount->setGeometry(345,250,110,30);
    gotoRemoveAccount = new QPushButton("Remove Account",this);
    gotoRemoveAccount->setGeometry(345,300,110,30);
    gotoChangeAuth = new QPushButton("Change Auth",this);
    gotoChangeAuth->setGeometry(345,350,110,30);

    gotoItemList = new QPushButton("Item List",this);
    gotoItemList->setGeometry(475,200,110,30);
    gotoShelfList = new QPushButton("Shelf List",this);
    gotoShelfList->setGeometry(475,250,110,30);
    gotoFinancial = new QPushButton("Financial Report",this);
    gotoFinancial->setGeometry(475,300,110,30);
    gotoEmployeeReport = new QPushButton("Employee Report",this);
    gotoEmployeeReport->setGeometry(475,350,110,30);
    gotoEmployeeHours = new QPushButton("Employee Hours",this);
    gotoEmployeeHours->setGeometry(475,400,110,30);
    logoutButton = new QPushButton("Logout",this);
    logoutButton->setGeometry(670,570,60,20);
    connect(logoutButton, SIGNAL(clicked()),this,SLOT(slotLogoutClicked()));
    connect(gotoAddAccount,SIGNAL(clicked()),this,SLOT(slotAddAccountUI()));
    connect(gotoRemoveAccount,SIGNAL(clicked()),this,SLOT(slotRemoveAccountUI()));
    connect(gotoAddItem,SIGNAL(clicked()),this,SLOT(slotAddItemUI()));
    connect(gotoSellItem,SIGNAL(clicked()),this,SLOT(slotSellItemUI()));
    connect(gotoRemoveItem,SIGNAL(clicked()),this,SLOT(slotRemoveItemUI()));
    connect(gotoEmployeeReport,SIGNAL(clicked()),this,SLOT(slotEReportUI()));
    connect(gotoFinancial,SIGNAL(clicked()),this,SLOT(slotFReportUI()));
    connect(gotoChangePass,SIGNAL(clicked()),this,SLOT(slotChangePassUI()));
    connect(gotoChangeAuth,SIGNAL(clicked()),this,SLOT(slotChangeAuthUI()));
    connect(gotoItemList,SIGNAL(clicked()),this,SLOT(slotItemListUI()));
    connect(gotoShelfList,SIGNAL(clicked()),this,SLOT(slotShelfListUI()));
    connect(gotoEmployeeHours,SIGNAL(clicked()),this,SLOT(slotEHoursUI()));
    connect(clockIn,SIGNAL(clicked()),this,SLOT(slotClockIn()));
    connect(clockOut,SIGNAL(clicked()),this,SLOT(slotClockOut()));
    connect(gotoItemSearch,SIGNAL(clicked()),this,SLOT(slotSearchItemUI()));

    //Add Item
    //itemName, itemBrand, itemType, itemCount, itemPrice, inName, inBrand, inType, inCount, inPrice, addItem
    itemName = new QTextEdit("Name:",this);
    itemName->setGeometry(90,100,100,30);
    itemName->setReadOnly(true);
    itemBrand = new QTextEdit("Brand:",this);
    itemBrand->setGeometry(90,150,100,30);
    itemBrand->setReadOnly(true);
    itemType = new QTextEdit("Type:",this);
    itemType->setGeometry(90,200,100,30);
    itemType->setReadOnly(true);
    itemCount = new QTextEdit("Count:",this);
    itemCount->setGeometry(90,250,100,30);
    itemCount->setReadOnly(true);
    itemPrice = new QTextEdit("Sales Price:",this);
    itemPrice->setGeometry(90,300,100,30);
    itemPrice->setReadOnly(true);
    itemCost = new QTextEdit("Restock Cost:",this);
    itemCost->setGeometry(90,350,100,30);
    itemCost->setReadOnly(true);
    inName = new QLineEdit(this);
    inName->setGeometry(170,100,480,30);
    inBrand = new QLineEdit(this);
    inBrand->setGeometry(170,150,480,30);
    inType = new QLineEdit(this);
    inType->setGeometry(170,200,480,30);
    inCount = new QLineEdit(this);
    inCount->setGeometry(170,250,480,30);
    inPrice = new QLineEdit(this);
    inPrice->setGeometry(170,300,480,30);
    inCost = new QLineEdit(this);
    inCost->setGeometry(170,350,480,30);
    addItem = new QPushButton("Add Item",this);
    addItem->setGeometry(350,400,100,30);
    addItemCancel = new QPushButton("Cancel",this);
    addItemCancel->setGeometry(350,450,100,30);
    connect(addItemCancel,SIGNAL(clicked()),this,SLOT(slotAddItemCancel()));
    connect(addItem,SIGNAL(clicked()),this,SLOT(slotAddItem()));

    //Sell Item
    //sellName, sellCount, sName, sCount, sellItem, sellItemCancel
    sellName = new QTextEdit("Name:",this);
    sellName->setGeometry(100,250,100,30);
    sellName->setReadOnly(true);
    sellCount = new QTextEdit("Count:",this);
    sellCount->setGeometry(100,300,100,30);
    sellCount->setReadOnly(true);
    sName = new QLineEdit(this);
    sName->setGeometry(170,250,480,30);
    sCount = new QLineEdit(this);
    sCount->setGeometry(170,300,480,30);
    sellItem = new QPushButton("Sell Item",this);
    sellItem->setGeometry(350,350,100,30);
    sellItemCancel = new QPushButton("Cancel",this);
    sellItemCancel->setGeometry(350,400,100,30);
    connect(sellItem,SIGNAL(clicked()),this,SLOT(slotSellItem()));
    connect(sellItemCancel,SIGNAL(clicked()),this,SLOT(slotSellItemCancel()));

    //Remove Item
    //removeName, rName, removeItem, removeItemCancel
    removeName = new QTextEdit("Name:",this);
    removeName->setGeometry(100,300,100,30);
    removeName->setReadOnly(true);
    rName = new QLineEdit(this);
    rName->setGeometry(170,300,480,30);
    removeItem = new QPushButton("Remove Item",this);
    removeItem->setGeometry(350,350,100,30);
    removeItemCancel = new QPushButton("Cancel",this);
    removeItemCancel->setGeometry(350,400,100,30);
    connect(removeItem,SIGNAL(clicked()),this,SLOT(slotRemoveItem()));
    connect(removeItemCancel,SIGNAL(clicked()),this,SLOT(slotRemoveItemCancel()));

    //Search Item
    searchName = new QTextEdit("Name: ",this);
    searchName->setReadOnly(true);
    searchName->setGeometry(100,300,100,30);
    searchFail = new QTextEdit("Item does not exist.",this);
    searchFail->setReadOnly(true);
    searchFail->setGeometry(335,250,130,30);
    searchFail->setAlignment(Qt::AlignCenter);
    searchIn = new QLineEdit(this);
    searchIn->setGeometry(170,300,480,30);
    searchItem = new QPushButton("Search",this);
    searchItem->setGeometry(350,350,100,30);
    searchCancel = new QPushButton("Cancel",this);
    searchCancel->setGeometry(350,400,100,30);
    connect(searchCancel,SIGNAL(clicked()),this,SLOT(slotSearchItemCancel()));
    connect(searchItem,SIGNAL(clicked()),this,SLOT(slotSearchItem()));

    //Search Result
    itemInfo = new QTextEdit("",this);
    itemInfo->setReadOnly(true);
    itemInfo->setGeometry(300,200,200,200);
    searchReturn = new QPushButton("Return",this);
    searchReturn->setGeometry(350,450,100,30);
    connect(searchReturn,SIGNAL(clicked()),this,SLOT(slotSearchReturn()));

    //Warnings
    noItem = new QTextEdit("The item does not exist.",this);
    noItem->setGeometry(325,150,150,30);
    noItem->setReadOnly(true);
    noItem->setAlignment(Qt::AlignCenter);
    noCount = new QTextEdit("There is not enough of the item remaining.",this);
    noCount->setGeometry(270,200,260,30);
    noCount->setAlignment(Qt::AlignCenter);
    noCount->setReadOnly(true);


    //Shelf Update Info
    changedShelf = new QTextEdit("",this); //THIS GETS UPDATED WHENEVER ADD_ITEM SELL_ITEM REMOVE_ITEM CALLED
    changedShelf->setGeometry(100,180,600,150);
    changedShelf->setReadOnly(true);
    changedShelf->setAlignment(Qt::AlignCenter);
    shelfNext = new QPushButton("Next",this);
    shelfNext->setGeometry(350,350,100,30);
    connect(shelfNext,SIGNAL(clicked()),this,SLOT(slotShelfNext()));

    //Add Account
    newUser = new QTextEdit("New Username:",this);
    newUser->setGeometry(155,200,150,30);
    newUser->setReadOnly(true);
    newPass = new QTextEdit("Password:",this);
    newPass->setGeometry(155,250,150,30);
    newPass->setReadOnly(true);
    newAuth = new QTextEdit("Authorization (number):",this);
    newAuth->setGeometry(155,300,150,30);
    newAuth->setReadOnly(true);
    authTypes = new QTextEdit(this);
    authTypes->setGeometry(550,200,200,200);
    authTypes->setReadOnly(true);
    authTypes->setText("Authorization types:\n");
    authTypes->append("1 - Add, Remove item, Item Search, Item List, Shelf List");
    authTypes->append("2 - Add, Remove Employee, Employee Report, Change Authorization");
    //authTypes->append("3 - ");
    //authTypes->append("4 - ");
    authTypes->append("3 - Everything");
    invalidAcc = new QTextEdit("Username and Password cannot be blank.",this);
    invalidAcc->setGeometry(275,150,250,27);
    NewUInput = new QLineEdit(this);
    NewUInput->setGeometry(300,200,200,30);
    NewPInput = new QLineEdit(this);
    NewPInput->setGeometry(300,250,200,30);
    NewAInput = new QLineEdit(this);
    NewPInput->setEchoMode(QLineEdit::Password);
    NewAInput->setGeometry(300,300,200,30);
    newAccount = new QPushButton("Add Account",this);
    newAccount->setGeometry(350,350,100,30);
    accountReturn = new QPushButton("Cancel",this);
    accountReturn->setGeometry(350,400,100,30);
    connect(newAccount,SIGNAL(clicked()),this,SLOT(slotAddAccount()));
    connect(accountReturn,SIGNAL(clicked()),this,SLOT(slotAccountCancel()));

    //Remove Account
    remUser = new QTextEdit("User to Remove:",this);
    remUser->setGeometry(175,300,150,30);
    remUser->setReadOnly(true);
    noUser = new QTextEdit("User does not exist.",this);
    noUser->setGeometry(335,250,130,27);
    noUser->setReadOnly(true);
    rUserInput = new QLineEdit(this);
    rUserInput->setGeometry(300,300,200,30);
    removeAccount = new QPushButton("Remove Account",this);
    removeAccount->setGeometry(350,350,100,30);
    connect(removeAccount,SIGNAL(clicked()),this,SLOT(slotRemoveAccount()));

    //Change Password
    //oldPassText, newPassText, confirmNewPass, oldPassIn, newPassIn, confirmIn, changePass, changePassCancel
    oldPassText = new QTextEdit("Old Password:",this);
    oldPassText->setGeometry(155,200,150,30);
    oldPassText->setReadOnly(true);
    newPassText = new QTextEdit("New Password:",this);
    newPassText->setGeometry(155,250,150,30);
    newPassText->setReadOnly(true);
    confirmNewPass = new QTextEdit("Confirm Password:",this);
    confirmNewPass->setGeometry(155,300,150,30);
    confirmNewPass->setReadOnly(true);
    wrongPassChange = new QTextEdit("Wrong Password",this);
    wrongPassChange->setGeometry(500,200,110,30);
    wrongPassChange->setReadOnly(true);
    wrongPassChange->setVisible(false);
    blankPassword = new QTextEdit("Password cannot be blank",this);
    blankPassword->setGeometry(500,250,170,30);
    blankPassword->setReadOnly(true);
    blankPassword->setVisible(false);
    noMatch = new QTextEdit("The passwords don't match",this);
    noMatch->setGeometry(500,300,170,30);
    noMatch->setReadOnly(true);
    noMatch->setVisible(false);
    oldPassIn = new QLineEdit(this);
    oldPassIn->setGeometry(300,200,200,30);
    oldPassIn->setEchoMode(QLineEdit::Password);
    newPassIn = new QLineEdit(this);
    newPassIn->setGeometry(300,250,200,30);
    newPassIn->setEchoMode(QLineEdit::Password);
    confirmIn = new QLineEdit(this);
    confirmIn->setGeometry(300,300,200,30);
    confirmIn->setEchoMode(QLineEdit::Password);
    changePass = new QPushButton("Change Password",this);
    changePass->setGeometry(350,350,120,30);
    changePassCancel = new QPushButton("Cancel",this);
    changePassCancel->setGeometry(350,400,120,30);
    connect(changePassCancel,SIGNAL(clicked()),this,SLOT(slotChangePassCancel()));
    connect(changePass,SIGNAL(clicked()),this,SLOT(slotChangePass()));

    //Change Auth
    //aUserText, aAuthText, aNoUser, aUser, aAuth, changeAuth, changeAuthCancel
    aUserText = new QTextEdit("User:",this);
    aUserText->setGeometry(155,250,150,30);
    aUserText->setReadOnly(true);
    aAuthText = new QTextEdit("Authorization (Number):",this);
    aAuthText->setGeometry(155,300,150,30);
    aAuthText->setReadOnly(true);
    aNoUser = new QTextEdit("No existing user.",this);
    aNoUser->setGeometry(345,200,110,30);
    aNoUser->setReadOnly(true);
    aNoUser->setVisible(false);
    aUser = new QLineEdit(this);
    aUser->setGeometry(300,250,200,30);
    aAuth = new QLineEdit(this);
    aAuth->setGeometry(300,300,200,30);
    changeAuth = new QPushButton("Change Auth",this);
    changeAuth->setGeometry(350,350,100,30);
    changeAuthCancel = new QPushButton("Cancel",this);
    changeAuthCancel->setGeometry(350,400,100,30);
    connect(changeAuthCancel,SIGNAL(clicked()),this,SLOT(slotChangeAuthCancel()));
    connect(changeAuth,SIGNAL(clicked()),this,SLOT(slotChangeAuth()));

    //Report info
    reportInfo = new QTextEdit("",this);
    reportInfo->setGeometry(50,50,700,475);
    reportInfo->setReadOnly(true);
    reportNext = new QPushButton("Return",this);
    reportNext->setGeometry(350,550,100,30);
    connect(reportNext,SIGNAL(clicked()),this,SLOT(slotReportDone()));

    quitButton = new QPushButton("Quit",this);
    quitButton->setGeometry(740,570,50,20);
    connect(quitButton, SIGNAL(clicked()), QApplication::instance(), SLOT (quit()));

    //Put HIDES here for creating other UI's
    /*
    UText->setVisible(false);
    PText->setVisible(false);
    loginUInput->setVisible(false);
    loginPInput->setVisible(false);
    loginButton->setVisible(false);
    UWrong->setVisible(false);
    PWrong->setVisible(false);
    */
//    /*
    clockIn->setVisible(false);
    clockOut->setVisible(false);
    gotoAddItem->setVisible(false);
    gotoRemoveItem->setVisible(false);
    gotoAddAccount->setVisible(false);
    gotoRemoveAccount->setVisible(false);
    logoutButton->setVisible(false);
    gotoChangeAuth->setVisible(false);
    gotoChangePass->setVisible(false);
    gotoFinancial->setVisible(false);
    gotoSellItem->setVisible(false);
    gotoEmployeeReport->setVisible(false);
    gotoEmployeeHours->setVisible(false);
    gotoItemList->setVisible(false);
    gotoShelfList->setVisible(false);
    gotoItemSearch->setVisible(false);
//    */
    newUser->setVisible(false);
    newPass->setVisible(false);
    newAuth->setVisible(false);
    NewUInput->setVisible(false);
    NewPInput->setVisible(false);
    NewAInput->setVisible(false);
    authTypes->setVisible(false);
    newAccount->setVisible(false);
    accountReturn->setVisible(false);
    invalidAcc->setVisible(false);
    remUser->setVisible(false);
    noUser->setVisible(false);
    rUserInput->setVisible(false);
    removeAccount->setVisible(false);
    //AddItem
    itemName->setVisible(false);
    itemBrand->setVisible(false);
    itemType->setVisible(false);
    itemCount->setVisible(false);
    itemPrice->setVisible(false);
    inName->setVisible(false);
    inBrand->setVisible(false);
    inType->setVisible(false);
    inCount->setVisible(false);
    inPrice->setVisible(false);
    addItem->setVisible(false);
    addItemCancel->setVisible(false);
    changedShelf->setVisible(false);
    shelfNext->setVisible(false);
    inCost->setVisible(false);
    itemCost->setVisible(false);
    //SellItem
    sellName->setVisible(false);
    sellCount->setVisible(false);
    sName->setVisible(false);
    sCount->setVisible(false);
    sellItem->setVisible(false);
    sellItemCancel->setVisible(false);
    //RemoveItem
    removeName->setVisible(false);
    rName->setVisible(false);
    removeItem->setVisible(false);
    removeItemCancel->setVisible(false);
    //Item Search
    searchName->setVisible(false);
    searchIn->setVisible(false);
    searchItem->setVisible(false);
    searchCancel->setVisible(false);
    itemInfo->setVisible(false);
    searchReturn->setVisible(false);
    searchFail->setVisible(false);
    //Report Info
    reportInfo->setVisible(false);
    reportNext->setVisible(false);
    //Change Password
    oldPassText->setVisible(false);
    newPassText->setVisible(false);
    confirmNewPass->setVisible(false);
    oldPassIn->setVisible(false);
    newPassIn->setVisible(false);
    confirmIn->setVisible(false);
    changePass->setVisible(false);
    changePassCancel->setVisible(false);
    noMatch->setVisible(false);
    wrongPassChange->setVisible(false);
    blankPassword->setVisible(false);
    //Change Auth
    aUserText->setVisible(false);
    aAuthText->setVisible(false);
    aNoUser->setVisible(false);
    aUser->setVisible(false);
    aAuth->setVisible(false);
    changeAuth->setVisible(false);
    changeAuthCancel->setVisible(false);
    //Warnings
    noItem->setVisible(false);
    noCount->setVisible(false);

}
void Window::slotLoginClicked(){
    std::string uName = loginUInput->text().toLocal8Bit().constData();
    std::string pName = loginPInput->text().toLocal8Bit().constData();
    login(uName,pName);
}
void Window::login(std::string uName, std::string pName){
    for (uint i = 0; i < AccountList.size(); i++){
        if (uName == AccountList[i].get_user()){
            UWrong->setVisible(false);
            if (pName == AccountList[i].get_pass()){
                //Set users auth
                currentAuth = AccountList[i].get_auth();
                currentUser = AccountList[i].get_user();
                EmployeeReport.push_back(EmployeeAct(currentUser,"Logged in"));
                store_ereport();
                HideAll();
                //Menu based on auth
                MainMenu();
                //Clears the Username/Password fields
                loginUInput->setText("");
                loginPInput->setText("");
                return;
            }
            else{
                PWrong->setVisible(true);
                return;
            }
        }
    }
    UWrong->setVisible(true);
}
void Window::slotLogoutClicked(){
    HideAll();
    UText->setVisible(true);
    PText->setVisible(true);
    loginUInput->setVisible(true);
    loginPInput->setVisible(true);
    loginButton->setVisible(true);
    EmployeeReport.push_back(EmployeeAct(currentUser,"Logged out"));
    store_ereport();
    currentAuth = 0;
    currentUser = "";
}
void Window::slotAddAccount(){
    if (strcmp(NewUInput->text().toLocal8Bit().constData(),"") == 0 || strcmp(NewPInput->text().toLocal8Bit().constData(),"") == 0){
        invalidAcc->setVisible(true);
    }
    else{
        add_account(NewUInput->text().toLocal8Bit().constData(),NewPInput->text().toLocal8Bit().constData(),
                    std::stoi(NewAInput->text().toLocal8Bit().constData()));
        NewUInput->setText("");
        NewPInput->setText("");
        NewAInput->setText("");
        HideAll();
        MainMenu();
        store_acc();
        notification->setText("Account successfully added.");
        notification->setAlignment(Qt::AlignCenter);
        notification->setVisible(true);
    }
}
void Window::slotAddAccountUI(){
    HideAll();
    newUser->setVisible(true);
    newPass->setVisible(true);
    newAuth->setVisible(true);
    NewUInput->setVisible(true);
    NewPInput->setVisible(true);
    NewAInput->setVisible(true);
    authTypes->setVisible(true);
    newAccount->setVisible(true);
    accountReturn->setVisible(true);
}
void Window::slotRemoveAccount(){
    remove_account(rUserInput->text().toLocal8Bit().constData());
    store_acc();
}
void Window::slotRemoveAccountUI(){
    HideAll();
    remUser->setVisible(true);
    rUserInput->setVisible(true);
    removeAccount->setVisible(true);
    accountReturn->setVisible(true);
}
void Window::slotAccountCancel(){
    HideAll();
    MainMenu();
    NewUInput->setText("");
    NewPInput->setText("");
    NewAInput->setText("");
    rUserInput->setText("");
}
void Window::slotAddItemUI(){
    HideAll();
    itemName->setVisible(true);
    itemBrand->setVisible(true);
    itemType->setVisible(true);
    itemCount->setVisible(true);
    itemPrice->setVisible(true);
    inName->setVisible(true);
    inBrand->setVisible(true);
    inType->setVisible(true);
    inCount->setVisible(true);
    inPrice->setVisible(true);
    addItem->setVisible(true);
    addItemCancel->setVisible(true);
    inCost->setVisible(true);
    itemCost->setVisible(true);
}
void Window::slotAddItem(){
    if(strcmp(inPrice->text().toLocal8Bit().constData(),"") == 0){
            add_item(inName->text().toLocal8Bit().constData(),inBrand->text().toLocal8Bit().constData(),
                     inType->text().toLocal8Bit().constData(),std::stoi(inCount->text().toLocal8Bit().constData()),
                     0.0,std::stod(inCost->text().toLocal8Bit().constData()));
    }
    else{
        add_item(inName->text().toLocal8Bit().constData(),inBrand->text().toLocal8Bit().constData(),
             inType->text().toLocal8Bit().constData(),std::stoi(inCount->text().toLocal8Bit().constData()),
             std::stod(inPrice->text().toLocal8Bit().constData()),std::stod(inCost->text().toLocal8Bit().constData()));
    }
    change_shelf();
    store_shelves();
    store_items();
    store_freport();
}
void Window::slotAddItemCancel(){
    HideAll();
    MainMenu();
    inName->setText("");
    inBrand->setText("");
    inType->setText("");
    inCount->setText("");
    inPrice->setText("");
    inCost->setText("");
}
void Window::slotSellItemUI(){
    HideAll();
    sellName->setVisible(true);
    sellCount->setVisible(true);
    sName->setVisible(true);
    sCount->setVisible(true);
    sellItem->setVisible(true);
    sellItemCancel->setVisible(true);
}
void Window::slotSellItem(){
    //Call sell_item
    for(uint i = 0; i < ItemList.size();i++){
        if (ItemList[i].get_name() == sName->text().toLocal8Bit().constData()){
            if (ItemList[i].get_count() >= std::stoi(sCount->text().toLocal8Bit().constData())){
                sell_item(sName->text().toLocal8Bit().constData(), std::stoi(sCount->text().toLocal8Bit().constData()));
                change_shelf();
                store_shelves();
                store_items();
                store_freport();
                return;
            }
            else{
                noCount->setVisible(true);
                noItem->setVisible(false);
                return;
            }
        }
    }
    noItem->setVisible(true);
    noCount->setVisible(false);

}
void Window::slotSellItemCancel(){
    HideAll();
    MainMenu();
    sName->setText("");
    sCount->setText("");
}
void Window::slotRemoveItemUI(){
    HideAll();
    removeName->setVisible(true);
    rName->setVisible(true);
    removeItem->setVisible(true);
    removeItemCancel->setVisible(true);
}
void Window::slotRemoveItem(){
    //Call remove_item
    for(uint i = 0; i < ItemList.size();i++){
        if (ItemList[i].get_name() == rName->text().toLocal8Bit().constData()){
            remove_item(rName->text().toLocal8Bit().constData());
            change_shelf();
            store_shelves();
            store_items();
            return;
        }
    }
    noItem->setVisible(true);
}
void Window::slotRemoveItemCancel(){
    HideAll();
    MainMenu();
    rName->setText("");
}
void Window::slotSearchItemUI(){
    HideAll();
    searchName->setVisible(true);
    searchIn->setVisible(true);
    searchItem->setVisible(true);
    searchCancel->setVisible(true);
}
void Window::slotSearchItemCancel(){
    HideAll();
    MainMenu();
    searchIn->setText("");
}
void Window::slotSearchItem(){
    //Populate item info & employee action item search
    int d, c;
    double sp;
    std::vector<std::string> shelves;

    for (uint i = 0; i < ItemList.size(); i++){
        if (ItemList[i].get_name() == searchIn->text().toLocal8Bit().constData()){
            itemInfo->append(QString::fromStdString(ItemList[i].get_name()));
            itemInfo->append("     Brand: ");
            itemInfo->insertPlainText(QString::fromStdString(ItemList[i].get_brand()));
            itemInfo->append("     Type: ");
            itemInfo->insertPlainText(QString::fromStdString(ItemList[i].get_type()));
            itemInfo->append("     Count: ");
            itemInfo->insertPlainText(QString::fromStdString(std::to_string(ItemList[i].get_count())));
            itemInfo->append("     Sales Price: $");
            sp = ItemList[i].get_sp();
            d = sp;
            c = sp * 100;
            c = c % 100;
            itemInfo->insertPlainText(QString::fromStdString(std::to_string(d)));
            itemInfo->insertPlainText(".");
            if (c < 10)
                itemInfo->insertPlainText("0");
            itemInfo->insertPlainText(QString::fromStdString(std::to_string(c)));
            shelves = ItemList[i].get_shelf();
            itemInfo->append("     Shelves: ");
            for (uint k = 0; k < shelves.size(); k++){
                itemInfo->insertPlainText(QString::fromStdString(shelves[k]));
                if (k < shelves.size() - 1){
                    itemInfo->insertPlainText(", ");
                }
            }
            HideAll();
            itemInfo->setVisible(true);
            searchReturn->setVisible(true);
            searchIn->setText("");
            EmployeeReport.push_back(EmployeeAct(currentUser,"Searched for an item"));
            store_ereport();
            return;
        }
    }
    searchFail->setVisible(true);
}
void Window::slotSearchReturn(){
    HideAll();
    MainMenu();
    itemInfo->setText("");
}
void Window::change_shelf(){
    //Clear text fields of on windows that lead to this
    inName->setText("");
    inBrand->setText("");
    inType->setText("");
    inCount->setText("");
    inPrice->setText("");
    inCost->setText("");
    sName->setText("");
    sCount->setText("");
    rName->setText("");
    HideAll();
    changedShelf->setVisible(true);
    shelfNext->setVisible(true);
}
void Window::slotShelfNext(){
    changedShelf->setText("");
    changedShelf->setAlignment(Qt::AlignCenter);
    HideAll();
    MainMenu();
}
void Window::slotEReportUI(){
    //Call employee_report to adjust display data
    for (uint i = 0; i < EmployeeReport.size(); i++){
        reportInfo->append(QString::fromStdString(EmployeeReport[i].get_timestamp()));
        reportInfo->insertPlainText("   ");
        reportInfo->insertPlainText(QString::fromStdString(EmployeeReport[i].get_user()));
        reportInfo->insertPlainText("   ");
        reportInfo->insertPlainText(QString::fromStdString(EmployeeReport[i].get_action()));
    }
    EmployeeReport.push_back(EmployeeAct(currentUser,"Viewed the employee action report"));
    store_ereport();
    display_report();
}
void Window::slotClockIn(){
    for (uint i = 0; i < EmployeeHours.size(); i++){
        if (currentUser == EmployeeHours[i].get_uName() && !EmployeeHours[i].is_complete()){
            notification->setText("Already clocked in.");
            notification->setAlignment(Qt::AlignCenter);
            notification->setVisible(true);
            return;
        }
    }
    EmployeeHours.push_back(EmployeeTime(currentUser));
    EmployeeReport.push_back(EmployeeAct(currentUser,"Clocked in"));
    store_ereport();
    time_t t;
    time(&t);
    struct tm * timeinfo;
    timeinfo = localtime(&t);
    char tmp[32];
    std::strftime(tmp,32,"Clocked in at %r.",timeinfo);
    notification->setText(QString::fromStdString(tmp));
    notification->setAlignment(Qt::AlignCenter);
    notification->setVisible(true);
    store_ehour();
}
void Window::slotClockOut(){
    for (uint i = 0; i < EmployeeHours.size(); i++){
        if (currentUser == EmployeeHours[i].get_uName() && !EmployeeHours[i].is_complete()){
            EmployeeHours[i].clock_out();
            EmployeeReport.push_back(EmployeeAct(currentUser,"Clocked out"));
            store_ereport();
            time_t t;
            time(&t);
            struct tm * timeinfo;
            timeinfo = localtime(&t);
            char tmp[32];
            std::strftime(tmp,32,"Clocked out at %r.",timeinfo);
            notification->setText(QString::fromStdString(tmp));
            notification->setAlignment(Qt::AlignCenter);
            notification->setVisible(true);
            store_ehour();
            return;
        }
    }
    notification->setText("Already clocked out.");
    notification->setAlignment(Qt::AlignCenter);
    notification->setVisible(true);
}
void Window::slotEHoursUI(){
    time_t in, out;
    int h, m, s;
    std::string sIn, sOut;
    for (uint i = 0; i < EmployeeHours.size(); i++){
        if (EmployeeHours[i].is_complete()){
            in = EmployeeHours[i].get_inTime();
            out = EmployeeHours[i].get_outTime();
            reportInfo->append(QString::fromStdString(EmployeeHours[i].get_uName()));
            reportInfo->append("     Clock in: ");
            sIn = ctime(&in);
            sOut = ctime(&out);
            sIn[sIn.size() - 1] = '\0';
            sOut[sOut.size() - 1] = '\0';
            reportInfo->insertPlainText(QString::fromStdString(sIn));
            reportInfo->insertPlainText("     Clock out: ");
            reportInfo->insertPlainText(QString::fromStdString(sOut));
            reportInfo->insertPlainText("     Time worked: ");
            s = difftime(out,in);
            m = s / 60;
            s = s % 60;
            h = m / 60;
            m = m % 60;
            reportInfo->insertPlainText(QString::fromStdString(std::to_string(h)));
            reportInfo->insertPlainText(" Hours ");
            reportInfo->insertPlainText(QString::fromStdString(std::to_string(m)));
            reportInfo->insertPlainText(" Min ");
              reportInfo->insertPlainText(QString::fromStdString(std::to_string(s)));
            reportInfo->insertPlainText(" Sec");
        }
    }
    EmployeeReport.push_back(EmployeeAct(currentUser,"Viewed the employee hours"));
    store_ereport();
    display_report();
}
void Window::slotFReportUI(){
    int d = 0, c = 0;
    double total = 0;
    for (uint i = 0; i < FinancialReport.size(); i++){
        reportInfo->append(QString::fromStdString(FinancialReport[i].get_timestamp()));
        reportInfo->insertPlainText("   ");
        reportInfo->insertPlainText(QString::fromStdString(FinancialReport[i].get_type()));
        reportInfo->insertPlainText("   ");
        reportInfo->insertPlainText(QString::fromStdString(FinancialReport[i].get_name()));
        reportInfo->insertPlainText("   ");
        reportInfo->insertPlainText(QString::fromStdString(std::to_string(FinancialReport[i].get_count())));
        reportInfo->insertPlainText("   ");
        if(FinancialReport[i].get_type() == "ADD"){
            reportInfo->insertPlainText("-");
        }
        reportInfo->insertPlainText("$");
        reportInfo->insertPlainText(QString::fromStdString(std::to_string(FinancialReport[i].get_dollar())));
        reportInfo->insertPlainText(".");
        if (FinancialReport[i].get_cents() < 10)
            reportInfo->insertPlainText("0");
        reportInfo->insertPlainText(QString::fromStdString(std::to_string(FinancialReport[i].get_cents())));
        if (FinancialReport[i].get_type() == "ADD"){
            d -= FinancialReport[i].get_dollar();
            c -= FinancialReport[i].get_cents();
        }
        else{
            d += FinancialReport[i].get_dollar();
            c += FinancialReport[i].get_cents();
        }
    }
    total += d;
    total = total * 100;
    total += c;
    total = total / 100;
    d = total;
    c = total * 100;
    c = c % 100;
    reportInfo->append("Net profit: ");
    if (total < 0){
        d = d * -1;
        c = c * -1;
        reportInfo->insertPlainText("-");
    }
    reportInfo->insertPlainText("$");
    reportInfo->insertPlainText(QString::fromStdString(std::to_string(d)));
    reportInfo->insertPlainText(".");
    if (c < 10)
        reportInfo->insertPlainText("0");
    reportInfo->insertPlainText(QString::fromStdString(std::to_string(c)));
    EmployeeReport.push_back(EmployeeAct(currentUser,"Viewed the financial report"));
    store_ereport();
    display_report();
}
void Window::slotItemListUI(){
    std::vector<std::string> shelves;
    int d, c;
    double sp;
    for (uint i = 0; i < ItemList.size(); i++){
        reportInfo->append("NAME: ");
        reportInfo->insertPlainText(QString::fromStdString(ItemList[i].get_name()));
        reportInfo->append("   TYPE: ");
        reportInfo->insertPlainText(QString::fromStdString(ItemList[i].get_type()));
        reportInfo->insertPlainText("   BRAND: ");
        reportInfo->insertPlainText(QString::fromStdString(ItemList[i].get_brand()));
        reportInfo->insertPlainText("   COUNT: ");
        reportInfo->insertPlainText(QString::fromStdString(std::to_string(ItemList[i].get_count())));
        reportInfo->insertPlainText("   SALES PRICE: ");
        sp = ItemList[i].get_sp();
        d = sp;
        c = sp * 100;
        c = c % 100;
        reportInfo->insertPlainText("$");
        reportInfo->insertPlainText(QString::fromStdString(std::to_string(d)));
        reportInfo->insertPlainText(".");
        if (c < 10)
            reportInfo->insertPlainText("0");
        reportInfo->insertPlainText(QString::fromStdString(std::to_string(c)));
        shelves = ItemList[i].get_shelf();
        reportInfo->append("   SHELVES: ");
        for (uint k = 0; k < shelves.size(); k++){
            reportInfo->insertPlainText(QString::fromStdString(shelves[k]));
            reportInfo->insertPlainText(", ");
        }
    }
    EmployeeReport.push_back(EmployeeAct(currentUser,"Viewed the item list"));
    store_ereport();
    display_report();
}
void Window::slotShelfListUI(){
    std::vector<int> storeCount;
    std::vector<std::string> storeName;
    for (uint i = 0; i < ShelfList.size(); i++){
        reportInfo->append(QString::fromStdString(ShelfList[i].get_shelfloc()));
        reportInfo->insertPlainText("   TYPE: ");
        reportInfo->insertPlainText(QString::fromStdString(ShelfList[i].get_type()));
        reportInfo->insertPlainText("   MAX: ");
        reportInfo->insertPlainText(QString::fromStdString(std::to_string(ShelfList[i].get_max())));
        reportInfo->insertPlainText("   COUNT: ");
        reportInfo->insertPlainText(QString::fromStdString(std::to_string(ShelfList[i].get_count())));
        reportInfo->insertPlainText("   REMAINING: ");
        reportInfo->insertPlainText(QString::fromStdString(std::to_string(ShelfList[i].get_remaining())));
        storeCount = ShelfList[i].get_storedCount();
        storeName = ShelfList[i].get_storedNames();
        for (uint k = 0; k < storeName.size(); k++){
            reportInfo->append("     ITEM: ");
            reportInfo->insertPlainText(QString::fromStdString(storeName[k]));
            reportInfo->insertPlainText("   COUNT: ");
            reportInfo->insertPlainText(QString::fromStdString(std::to_string(storeCount[k])));
        }
    }
    EmployeeReport.push_back(EmployeeAct(currentUser,"Viewed the shelf list"));
    store_ereport();
    display_report();
}
void Window::slotReportDone(){
    HideAll();
    MainMenu();
    reportInfo->setText("");
}
void Window::display_report(){
    HideAll();
    reportInfo->setVisible(true);
    reportNext->setVisible(true);
    reportInfo->moveCursor(QTextCursor::Start);
}
void Window::slotChangePass(){
    change_password(oldPassIn->text().toLocal8Bit().constData(),newPassIn->text().toLocal8Bit().constData(),
                    confirmIn->text().toLocal8Bit().constData());
    store_acc();
}
void Window::slotChangePassUI(){
    HideAll();
    oldPassText->setVisible(true);
    newPassText->setVisible(true);
    confirmNewPass->setVisible(true);
    oldPassIn->setVisible(true);
    newPassIn->setVisible(true);
    confirmIn->setVisible(true);
    changePass->setVisible(true);
    changePassCancel->setVisible(true);
}
void Window::slotChangePassCancel(){
    HideAll();
    MainMenu();
    oldPassIn->setText("");
    newPassIn->setText("");
    confirmIn->setText("");
}
void Window::slotChangeAuthUI(){
    HideAll();
    //Change Auth
    aUserText->setVisible(true);
    aAuthText->setVisible(true);
    aUser->setVisible(true);
    aAuth->setVisible(true);
    changeAuth->setVisible(true);
    changeAuthCancel->setVisible(true);
    authTypes->setVisible(true);
}
void Window::slotChangeAuth(){
    change_auth(aUser->text().toLocal8Bit().constData(),std::stoi(aAuth->text().toLocal8Bit().constData()));
    store_acc();
}
void Window::slotChangeAuthCancel(){
    HideAll();
    MainMenu();
    aUser->setText("");
    aAuth->setText("");
}
void Window::HideAll(){
    //Hide everything, as new fields are added append to this
    //Login
    UText->setVisible(false);
    PText->setVisible(false);
    loginUInput->setVisible(false);
    loginPInput->setVisible(false);
    loginButton->setVisible(false);
    UWrong->setVisible(false);
    PWrong->setVisible(false);
    //Menu
    clockIn->setVisible(false);
    clockOut->setVisible(false);
    gotoAddItem->setVisible(false);
    gotoRemoveItem->setVisible(false);
    gotoAddAccount->setVisible(false);
    gotoRemoveAccount->setVisible(false);
    logoutButton->setVisible(false);
    gotoChangeAuth->setVisible(false);
    gotoChangePass->setVisible(false);
    gotoFinancial->setVisible(false);
    gotoSellItem->setVisible(false);
    gotoEmployeeReport->setVisible(false);
    gotoEmployeeHours->setVisible(false);
    gotoItemList->setVisible(false);
    gotoShelfList->setVisible(false);
    gotoItemSearch->setVisible(false);
    notification->setVisible(false);
    //AddItem
    itemName->setVisible(false);
    itemBrand->setVisible(false);
    itemType->setVisible(false);
    itemCount->setVisible(false);
    itemPrice->setVisible(false);
    inName->setVisible(false);
    inBrand->setVisible(false);
    inType->setVisible(false);
    inCount->setVisible(false);
    inPrice->setVisible(false);
    addItem->setVisible(false);
    addItemCancel->setVisible(false);
    inCost->setVisible(false);
    itemCost->setVisible(false);
    //SellItem
    sellName->setVisible(false);
    sellCount->setVisible(false);
    sName->setVisible(false);
    sCount->setVisible(false);
    sellItem->setVisible(false);
    sellItemCancel->setVisible(false);
    //RemoveItem
    removeName->setVisible(false);
    rName->setVisible(false);
    removeItem->setVisible(false);
    removeItemCancel->setVisible(false);
    //Item Search
    searchName->setVisible(false);
    searchIn->setVisible(false);
    searchItem->setVisible(false);
    searchCancel->setVisible(false);
    itemInfo->setVisible(false);
    searchReturn->setVisible(false);
    searchFail->setVisible(false);
    //AddAccount
    newUser->setVisible(false);
    newPass->setVisible(false);
    newAuth->setVisible(false);
    NewUInput->setVisible(false);
    NewPInput->setVisible(false);
    NewAInput->setVisible(false);
    authTypes->setVisible(false);
    newAccount->setVisible(false);
    accountReturn->setVisible(false);
    invalidAcc->setVisible(false);
    //RemoveAccount
    remUser->setVisible(false);
    noUser->setVisible(false);
    rUserInput->setVisible(false);
    removeAccount->setVisible(false);
    //Update Shelf
    changedShelf->setVisible(false);
    shelfNext->setVisible(false);
    //Report Info
    reportInfo->setVisible(false);
    reportNext->setVisible(false);
    //Change Password
    oldPassText->setVisible(false);
    newPassText->setVisible(false);
    confirmNewPass->setVisible(false);
    oldPassIn->setVisible(false);
    newPassIn->setVisible(false);
    confirmIn->setVisible(false);
    changePass->setVisible(false);
    changePassCancel->setVisible(false);
    noMatch->setVisible(false);
    wrongPassChange->setVisible(false);
    blankPassword->setVisible(false);
    //Change Auth
    aUserText->setVisible(false);
    aAuthText->setVisible(false);
    aNoUser->setVisible(false);
    aUser->setVisible(false);
    aAuth->setVisible(false);
    changeAuth->setVisible(false);
    changeAuthCancel->setVisible(false);
    //Warnings
    noItem->setVisible(false);
    noCount->setVisible(false);

}
void Window::MainMenu(){
    //Needs to be defined, displays a main menu based on current auth
//    1 - Add, Remove item, Item Search
//    2 - Add, Remove Employee, Employee Report, Change Authorization

    if (currentAuth == 1){
        gotoAddItem->setVisible(true);
        gotoSellItem->setVisible(true);
        gotoRemoveItem->setVisible(true);
        gotoChangePass->setVisible(true);
        gotoItemSearch->setVisible(true);
        gotoItemList->setVisible(true);
        gotoShelfList->setVisible(true);
    }
    else if (currentAuth == 2){
        gotoAddAccount->setVisible(true);
        gotoRemoveAccount->setVisible(true);
        gotoEmployeeReport->setVisible(true);
        gotoEmployeeHours->setVisible(true);
        gotoChangeAuth->setVisible(true);
        gotoChangePass->setVisible(true);
    }
    else if (currentAuth == 3){
        gotoAddItem->setVisible(true);
        gotoSellItem->setVisible(true);
        gotoRemoveItem->setVisible(true);
        gotoFinancial->setVisible(true);
        gotoAddAccount->setVisible(true);
        gotoRemoveAccount->setVisible(true);
        gotoChangeAuth->setVisible(true);
        gotoChangePass->setVisible(true);
        gotoEmployeeReport->setVisible(true);
        gotoEmployeeHours->setVisible(true);
        gotoItemList->setVisible(true);
        gotoShelfList->setVisible(true);
        gotoItemSearch->setVisible(true);
    }
    clockIn->setVisible(true);
    clockOut->setVisible(true);
    logoutButton->setVisible(true);
}
void Window::add_account(std::string user, std::string pass, int auth){
    AccountList.push_back(Account(user, pass, auth));
    EmployeeReport.push_back(EmployeeAct(currentUser, "Added an account"));
    store_ereport();
}
void Window::remove_account(std::string user){
    for (uint i = 0; i < AccountList.size(); i++) {
        if (AccountList[i].get_user() == user) {
            AccountList.erase(AccountList.begin()+i);
            rUserInput->setText("");
            HideAll();
            MainMenu();
            EmployeeReport.push_back(EmployeeAct(currentUser, "Removed an account"));
            store_ereport();
            notification->setText("Account successfully removed.");
            notification->setAlignment(Qt::AlignCenter);
            notification->setVisible(true);
            return;
        }
    }
    noUser->setVisible(true);
}
void Window::add_item(std::string name, std::string brand, std::string type, int count, double sales_price, double cost){
    std::vector<std::string> shelves;
    for (uint i = 0; i < ItemList.size(); i++){
        if (ItemList[i].get_name() == name){
            FinancialReport.push_back(Financial(name,count,cost,"ADD"));
            ItemList[i].change_count(count);
            shelves = ItemList[i].get_shelf();
            //Existing Shelves
            for (uint k = 0; k < shelves.size(); k++){
                for (uint j = 0; j < ShelfList.size(); j++){
                    if (shelves[k] == ShelfList[j].get_shelfloc()){
                        if (ShelfList[j].get_remaining() >= count && count != 0){

                            //Display store text
                            changedShelf->append("Add ");
                            changedShelf->insertPlainText(QString::fromStdString(std::to_string(count)));
                            changedShelf->insertPlainText(" ");
                            changedShelf->insertPlainText(QString::fromStdString(ItemList[i].get_name()));
                            changedShelf->insertPlainText(" to shelf ");
                            changedShelf->insertPlainText(QString::fromStdString(ShelfList[j].get_shelfloc()));
                            changedShelf->insertPlainText(".");

                            ShelfList[j].change_store(ItemList[i].get_name(),count);
                            count = 0;
                        }
                        else if(ShelfList[j].get_remaining() > 0 && count != 0){

                            //Display store text
                            changedShelf->append("Add ");
                            changedShelf->insertPlainText(QString::fromStdString(std::to_string(ShelfList[j].get_remaining())));
                            changedShelf->insertPlainText(" ");
                            changedShelf->insertPlainText(QString::fromStdString(ItemList[i].get_name()));
                            changedShelf->insertPlainText(" to shelf ");
                            changedShelf->insertPlainText(QString::fromStdString(ShelfList[j].get_shelfloc()));
                            changedShelf->insertPlainText(".");

                            count = count - ShelfList[j].get_remaining();
                            ShelfList[j].change_store(ItemList[i].get_name(),ShelfList[j].get_remaining());
                        }
                    }
                }
            }
            //New Shevles
            if (count != 0){
                for (uint k = 0; k < ShelfList.size(); k++){
                    if (ShelfList[k].get_type() == ItemList[i].get_type() && !ShelfList[k].is_full()){
                        if (ShelfList[k].get_remaining() >= count && count != 0){

                            //Display store text
                            changedShelf->append("Add ");
                            changedShelf->insertPlainText(QString::fromStdString(std::to_string(count)));
                            changedShelf->insertPlainText(" ");
                            changedShelf->insertPlainText(QString::fromStdString(ItemList[i].get_name()));
                            changedShelf->insertPlainText(" to shelf ");
                            changedShelf->insertPlainText(QString::fromStdString(ShelfList[k].get_shelfloc()));
                            changedShelf->insertPlainText(".");

                            ShelfList[k].new_store(ItemList[i].get_name(),count);
                            count = 0;
                            ItemList[i].new_shelf(ShelfList[k].get_shelfloc());
                        }
                        else if(ShelfList[k].get_remaining() > 0 && count != 0){

                            //Display store text
                            changedShelf->append("Add ");
                            changedShelf->insertPlainText(QString::fromStdString(std::to_string(ShelfList[k].get_remaining())));
                            changedShelf->insertPlainText(" ");
                            changedShelf->insertPlainText(QString::fromStdString(ItemList[i].get_name()));
                            changedShelf->insertPlainText(" to shelf ");
                            changedShelf->insertPlainText(QString::fromStdString(ShelfList[k].get_shelfloc()));
                            changedShelf->insertPlainText(".");

                            count = count - ShelfList[k].get_remaining();
                            ShelfList[k].new_store(ItemList[i].get_name(),ShelfList[k].get_remaining());
                            ItemList[i].new_shelf(ShelfList[k].get_shelfloc());
                        }
                    }
                }
            }
            if (count > 0){

                //Display overflow
                changedShelf->append(QString::fromStdString(std::to_string(count)));
                changedShelf->insertPlainText(" ");
                changedShelf->insertPlainText(QString::fromStdString(ItemList[i].get_name()));
                changedShelf->insertPlainText(" left over with no shelf to store on.");

                EmployeeReport.push_back(EmployeeAct(currentUser, "Added an item"));
                store_ereport();
                return;
            }
            else{
                EmployeeReport.push_back(EmployeeAct(currentUser, "Added an item"));
                store_ereport();
                return;
            }
        }

    }
    //New Item
    FinancialReport.push_back(Financial(name,count,cost,"ADD"));
    Item tmp(name, brand, type, count, sales_price);
    for (uint k = 0; k < ShelfList.size(); k++){
        if (ShelfList[k].get_type() == type && !ShelfList[k].is_full()){
            if (ShelfList[k].get_remaining() >= count && count != 0){

                //Display text
                changedShelf->append("Add ");
                changedShelf->insertPlainText(QString::fromStdString(std::to_string(count)));
                changedShelf->insertPlainText(" ");
                changedShelf->insertPlainText(QString::fromStdString(name));
                changedShelf->insertPlainText(" to shelf ");
                changedShelf->insertPlainText(QString::fromStdString(ShelfList[k].get_shelfloc()));
                changedShelf->insertPlainText(".");

                ShelfList[k].new_store(name, count);
                tmp.new_shelf(ShelfList[k].get_shelfloc());
                count = 0;
            }
            else if (ShelfList[k].get_remaining() > 0 && count != 0){

                //Display text
                changedShelf->append("Add ");
                changedShelf->insertPlainText(QString::fromStdString(std::to_string(ShelfList[k].get_remaining())));
                changedShelf->insertPlainText(" ");
                changedShelf->insertPlainText(QString::fromStdString(name));
                changedShelf->insertPlainText(" to shelf ");
                changedShelf->insertPlainText(QString::fromStdString(ShelfList[k].get_shelfloc()));
                changedShelf->insertPlainText(".");


                count = count - ShelfList[k].get_remaining();
                ShelfList[k].new_store(name, ShelfList[k].get_remaining());
                tmp.new_shelf(ShelfList[k].get_shelfloc());
            }
        }
    }
    ItemList.push_back(tmp);
    if (count > 0){

        //Display overflow
        changedShelf->append(QString::fromStdString(std::to_string(count)));
        changedShelf->insertPlainText(" ");
        changedShelf->insertPlainText(QString::fromStdString(name));
        changedShelf->insertPlainText(" left over with no shelf to store on.");

        EmployeeReport.push_back(EmployeeAct(currentUser, "Added an item"));
        store_ereport();
        return;
    }
    else{
        EmployeeReport.push_back(EmployeeAct(currentUser, "Added an item"));
        store_ereport();
        return;
    }
}
void Window::remove_item(std::string name){
        std::vector<std::string> shelves;
        std::string removedItem;
        //Later may want a helper function to output all items names in a list

        //Iterates through ItemList to find correct item
        for (uint i = 0; i < ItemList.size(); i++) {
            if (ItemList[i].get_name() == name) {
                //Modify shelf vector for this item still needed
                shelves = ItemList[i].get_shelf();
                //Clears all existing shelves that contained the item of said item
                for (uint j = 0; j < shelves.size(); j++) {
                    for (uint k = 0; k < ShelfList.size(); k++){
                        if (shelves[j] == ShelfList[k].get_shelfloc()) {

                            removedItem = ShelfList[k].remove_store(ItemList[i].get_name());
                            changedShelf->append(QString::fromStdString(removedItem));
                        }
                    }

                }
                ItemList.erase(ItemList.begin() + i);
            }
        }
        EmployeeReport.push_back(EmployeeAct(currentUser, "Removed an item"));
        store_ereport();
}
void Window::change_password(std::string oldPass, std::string newPass, std::string confirmPass){
    for(uint i = 0; i < AccountList.size(); i++){
        if(AccountList[i].get_user() == currentUser){
            if (AccountList[i].get_pass() != oldPass){
                wrongPassChange->setVisible(true);
                noMatch->setVisible(false);
                blankPassword->setVisible(false);
                return;
            }
            else if (newPass != confirmPass){
                wrongPassChange->setVisible(false);
                noMatch->setVisible(true);
                blankPassword->setVisible(false);
                return;
            }
            else if(strcmp(newPassIn->text().toLocal8Bit().constData(),"") == 0){
                blankPassword->setVisible(true);
                wrongPassChange->setVisible(false);
                noMatch->setVisible(false);
                return;
            }
            else{
                AccountList[i].set_pass(newPass);
                EmployeeReport.push_back(EmployeeAct(currentUser, "Changed their password"));
                store_ereport();
                HideAll();
                MainMenu();
                oldPassIn->setText("");
                newPassIn->setText("");
                confirmIn->setText("");
                notification->setText("Password successfully changed.");
                notification->setAlignment(Qt::AlignCenter);
                notification->setVisible(true);

            }
        }
    }
}
void Window::change_auth(std::string userName, int newAuth){
    for(uint i = 0; i < AccountList.size(); i++){
        if (userName == AccountList[i].get_user()){
            AccountList[i].set_auth(newAuth);
            EmployeeReport.push_back(EmployeeAct(currentUser, "Changed an authorization level"));
            store_ereport();
            HideAll();
            MainMenu();
            aUser->setText("");
            aAuth->setText("");
            notification->setText("Authorization successfully changed.");
            notification->setAlignment(Qt::AlignCenter);
            notification->setVisible(true);
            return;
        }
    }
    aNoUser->setVisible(true);
}
void Window::sell_item(std::string name, int count){
    std::vector<std::string> shelves;
    std::vector<std::string> removeShelves;
    EmployeeReport.push_back(EmployeeAct(currentUser, "Sold an item"));
    store_ereport();
    int tmp = count;
    for (uint i = 0; i < ItemList.size(); i++){
        if (ItemList[i].get_name() == name){
            FinancialReport.push_back(Financial(name, count, ItemList[i].get_sp(), "SELL"));
            ItemList[i].change_count(-1 * count);
            shelves = ItemList[i].get_shelf();
            for(uint k = 0; k < shelves.size();k++){
                for (uint j = 0; j <ShelfList.size();j++){
                    if (shelves[k] == ShelfList[j].get_shelfloc() && count != 0){
                        tmp = ShelfList[j].sell_store(name,tmp);
                        if (tmp > 0 || tmp == -1){
                            removeShelves.push_back(shelves[k]);
                            if (tmp == -1)
                                tmp = 0;
                        }
                        changedShelf->append("Sell ");
                        changedShelf->insertPlainText(QString::fromStdString(std::to_string(count - tmp)));
                        changedShelf->insertPlainText(" ");
                        changedShelf->insertPlainText(QString::fromStdString(name));
                        changedShelf->insertPlainText(" from shelf ");
                        changedShelf->insertPlainText(QString::fromStdString(shelves[k]));
                        changedShelf->insertPlainText(".");
                        count = tmp;
                    }
                }
            }
            for (uint p = 0; p<removeShelves.size();p++){
                ItemList[i].remove_shelf(removeShelves[p]);
            }
            if (ItemList[i].get_count() == 0)
                ItemList.erase(ItemList.begin() + i);

        }
    }
}
void Window::load_items(){
    std::ifstream file;
    //FILE NEEDS TO BE IN build-InvManage... DIRECTORY
    file.open("itemList.txt"/*,std::ifstream::in*/);
    std::string s, shf, line, name, brand, type, c, sp;
    int count = 0;
    double saleprice = 0;
    std::vector<std::string> shelves;
    uint i;
    if (file.is_open()){
        while (!file.eof()){
            std::getline(file, line);
            shelves.clear();
            i = 0;
            name = "";
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                name = name + line[i];
                i++;
            }
            brand = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                brand = brand + line[i];
                i++;
            }
            type = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                type = type + line[i];
                i++;
            }
            c = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                c = c + line[i];
                i++;
            }
            if (c != "")
                count = std::stoi(c);
            else
                count = 0;
            sp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                sp = sp + line[i];
                i++;
            }
            if (sp != "")
                saleprice = std::stod(sp);
            else
                saleprice = 0;
            shf = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '$')){
                if (line[i] != '|' && line[i] != '$'){
                    shf = shf + line[i];
                    i++;
                }
                else if (line[i] == '|'){
                    shelves.push_back(shf);
                    shf = "";
                    i++;
                }
            }
            if (name != "")
                ItemList.push_back(Item(name,brand,type,shelves,count,saleprice));
        }
        file.close();
    }
}
void Window::store_items(){
    std::ofstream file;
    file.open("itemList.txt");
    std::vector<std::string> shelves;
    for (uint i = 0; i < ItemList.size(); i++){
        file << ItemList[i].get_name() << '|';
        file << ItemList[i].get_brand() << '|';
        file << ItemList[i].get_type() << '|';
        file << ItemList[i].get_count() << '|';
        file << ItemList[i].get_sp() << '|';
        shelves = ItemList[i].get_shelf();
        for (uint k = 0; k < shelves.size(); k++){
            file << shelves[k] << '|';
        }
        file << '$' << '\n';
    }
    file.close();
}
void Window::load_shelves(){
    std::ifstream file;
    //FILE NEEDS TO BE IN build-InvManage... DIRECTORY
    file.open("shelfList.txt"/*,std::ifstream::in*/);
    std::string line, shf, type, c, m, s;
    int count = 0, max = 0;
    std::vector<std::string> sName;
    std::vector<int> sCount;
    uint i;

    if (file.is_open()){
        while (!file.eof()){
            std::getline(file, line);
            sName.clear();
            sCount.clear();
            i = 0;
            shf = "";
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                shf = shf + line[i];
                i++;
            }
            type  = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                type = type + line[i];
                i++;
            }
            m = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                m = m + line[i];
                i++;
            }
            if (m != "")
                max = std::stoi(m);
            else
                max = 0;
            c = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                c = c + line[i];
                i++;
            }
            if (c != "")
                count = std::stoi(c);
            else
                count = 0;
            s = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '$')){
                if (line[i] != '|' && line[i] != '$'){
                    s = s + line[i];
                    i++;
                }
                else if (line[i] == '|'){
                    sName.push_back(s);
                    s = "";
                    i++;
                }
            }
            s="";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '$')){
                if (line[i] != '|' && line[i] != '$'){
                    s = s + line[i];
                    i++;
                }
                else if (line[i] == '|'){
                    sCount.push_back(std::stoi(s));
                    s = "";
                    i++;
                }
            }
            if (shf != "")
                ShelfList.push_back(Shelf(shf,type,max,count,sName,sCount));
        }
        file.close();
    }
    else{
        //Default shelves, only executes on first run of program
        ShelfList.push_back(Shelf("X1A1","LCD COMPLETE ASSEMBLY",0,10));
        ShelfList.push_back(Shelf("X1A2","LCD COMPLETE ASSEMBLY",0,10));
        ShelfList.push_back(Shelf("X2A1","LCD COMPLETE ASSEMBLY",0,10));
        ShelfList.push_back(Shelf("X2A2","LCD COMPLETE ASSEMBLY",0,10));
        ShelfList.push_back(Shelf("X3A1","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("X3A2","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("X4A1","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("X4A2","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("X1B1","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("X1B2","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("X2B1","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("X2B2","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("X3B1","CPU COOLING FAN",0,12));
        ShelfList.push_back(Shelf("X3B2","CPU COOLING FAN",0,12));
        ShelfList.push_back(Shelf("X4B1","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("X4B2","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("X1C1","BATTERY OEM",0,15));
        ShelfList.push_back(Shelf("X1C2","BATTERY OEM",0,15));
        ShelfList.push_back(Shelf("X2C1","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("X2C2","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("X3C1","SATA CD DVD DRIVER",0,8));
        ShelfList.push_back(Shelf("X3C2","SATA CD DVD DRIVER",0,8));
        ShelfList.push_back(Shelf("X4C1","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("X4C2","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("X1D1","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("X1D2","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("X2D1","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("X2D2","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("X3D1","HARD DRIVE",0,25));
        ShelfList.push_back(Shelf("X3D2","CPU PROCESSOR",0,30));
        ShelfList.push_back(Shelf("X4D1","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("X4D2","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("X1E1","BACK COVER",0,10));
        ShelfList.push_back(Shelf("X1E2","BACK COVER",0,10));
        ShelfList.push_back(Shelf("X2E1","BACK COVER",0,10));
        ShelfList.push_back(Shelf("X2E2","BACK COVER",0,10));
        ShelfList.push_back(Shelf("X3E1","SPEARKER SET",0,20));
        ShelfList.push_back(Shelf("X3E2","HARD DRIVE CADDY",0,25));
        ShelfList.push_back(Shelf("X4E1","BACK COVER",0,10));
        ShelfList.push_back(Shelf("X4E2","BACK COVER",0,10));
        ShelfList.push_back(Shelf("X1F1","LCD LED SCREEN",0,12));
        ShelfList.push_back(Shelf("X1F2","LCD LED SCREEN",0,12));
        ShelfList.push_back(Shelf("X2F1","LCD LED SCREEN",0,12));
        ShelfList.push_back(Shelf("X2F2","LCD LED SCREEN",0,12));
        ShelfList.push_back(Shelf("X3F1","MEMORY",0,30));
        ShelfList.push_back(Shelf("X3F2","SSD CARD AND READER",0,40));
        ShelfList.push_back(Shelf("X4F1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("X4F2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("X1G1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("X1G2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("X2G1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("X2G2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("X3G1","HARD DRIVE CONNECTOR",0,40));
        ShelfList.push_back(Shelf("X3G2","VGA&DVI PORT",0,80));
        ShelfList.push_back(Shelf("X4G1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("X4G2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("X1H1","BOTTOM CASE COVER",0,30));
        ShelfList.push_back(Shelf("X1H2","HINGE BRACKET",0,30));
        ShelfList.push_back(Shelf("X2H1","BOTTOM CASE COVER",0,30));
        ShelfList.push_back(Shelf("X2H2","HINGE BRACKET",0,30));
        ShelfList.push_back(Shelf("X3H1","CAMERA WEBCAM",0,40));
        ShelfList.push_back(Shelf("X3H2","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("X4H1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("X4H2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("X1I1","KEYBOARD",0,20));
        ShelfList.push_back(Shelf("X1I2","KEYBOARD",0,20));
        ShelfList.push_back(Shelf("X2I1","KEYBOARD",0,20));
        ShelfList.push_back(Shelf("X2I2","KEYBOARD",0,20));
        ShelfList.push_back(Shelf("X3I1","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("X3I2","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("X4I1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("X4I2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("X1J1","CHARGER OEM",0,12));
        ShelfList.push_back(Shelf("X1J2","CHARGER OEM",0,12));
        ShelfList.push_back(Shelf("X2J1","CHARGER OEM",0,12));
        ShelfList.push_back(Shelf("X2J2","CHARGER OEM",0,12));
        ShelfList.push_back(Shelf("X3J1","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("X3J2","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("X4J1","BACK COVER",0,10));
        ShelfList.push_back(Shelf("X4J2","BACK COVER",0,10));

        ShelfList.push_back(Shelf("Y1A1","LCD COMPLETE ASSEMBLY",0,10));
        ShelfList.push_back(Shelf("Y1A2","LCD COMPLETE ASSEMBLY",0,10));
        ShelfList.push_back(Shelf("Y2A1","LCD COMPLETE ASSEMBLY",0,10));
        ShelfList.push_back(Shelf("Y2A2","LCD COMPLETE ASSEMBLY",0,10));
        ShelfList.push_back(Shelf("Y3A1","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("Y3A2","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("Y4A1","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Y4A2","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Y1B1","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Y1B2","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Y2B1","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Y2B2","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Y3B1","CPU COOLING FAN",0,12));
        ShelfList.push_back(Shelf("Y3B2","CPU COOLING FAN",0,12));
        ShelfList.push_back(Shelf("Y4B1","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Y4B2","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Y1C1","BATTERY OEM",0,15));
        ShelfList.push_back(Shelf("Y1C2","BATTERY OEM",0,15));
        ShelfList.push_back(Shelf("Y2C1","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Y2C2","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Y3C1","SATA CD DVD DRIVER",0,8));
        ShelfList.push_back(Shelf("Y3C2","SATA CD DVD DRIVER",0,8));
        ShelfList.push_back(Shelf("Y4C1","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Y4C2","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Y1D1","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Y1D2","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Y2D1","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Y2D2","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Y3D1","HARD DRIVE B",0,6));
        ShelfList.push_back(Shelf("Y3D2","WEBCAM",0,40));
        ShelfList.push_back(Shelf("Y4D1","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Y4D2","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Y1E1","BACK COVER",0,10));
        ShelfList.push_back(Shelf("Y1E2","BACK COVER",0,10));
        ShelfList.push_back(Shelf("Y2E1","BACK COVER",0,10));
        ShelfList.push_back(Shelf("Y2E2","BACK COVER",0,10));
        ShelfList.push_back(Shelf("Y3E1","SPEARKER SET",0,20));
        ShelfList.push_back(Shelf("Y3E2","HARD DRIVE CADDY",0,25));
        ShelfList.push_back(Shelf("Y4E1","BACK COVER",0,10));
        ShelfList.push_back(Shelf("Y4E2","BACK COVER",0,10));
        ShelfList.push_back(Shelf("Y1F1","LCD LED SCREEN",0,10));
        ShelfList.push_back(Shelf("Y1F2","LCD LED SCREEN",0,10));
        ShelfList.push_back(Shelf("Y2F1","LCD LED SCREEN",0,10));
        ShelfList.push_back(Shelf("Y2F2","LCD LED SCREEN",0,10));
        ShelfList.push_back(Shelf("Y3F1","POWER BUTTON",0,40));
        ShelfList.push_back(Shelf("Y3F2","SSD CARD AND READER",0,40));
        ShelfList.push_back(Shelf("Y4F1","LCD LED SCREEN",0,10));
        ShelfList.push_back(Shelf("Y4F2","LCD LED SCREEN",0,10));
        ShelfList.push_back(Shelf("Y1G1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Y1G2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Y2G1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Y2G2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Y3G1","HARD DRIVE CONNECTOR",0,40));
        ShelfList.push_back(Shelf("Y3G2","LCD VIDEO CABLE",0,40));
        ShelfList.push_back(Shelf("Y4G1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Y4G2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Y1H1","BOTTOM CASE COVER",0,30));
        ShelfList.push_back(Shelf("Y1H2","HINGE BRACKET",0,30));
        ShelfList.push_back(Shelf("Y2H1","BOTTOM CASE COVER",0,30));
        ShelfList.push_back(Shelf("Y2H2","HINGE BRACKET",0,30));
        ShelfList.push_back(Shelf("Y3H1","CAMERA WEBCAM",0,40));
        ShelfList.push_back(Shelf("Y3H2","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("Y4H1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Y4H2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Y1I1","KEYBOARD",0,20));
        ShelfList.push_back(Shelf("Y1I2","KEYBOARD",0,20));
        ShelfList.push_back(Shelf("Y2I1","KEYBOARD",0,20));
        ShelfList.push_back(Shelf("Y2I2","KEYBOARD",0,20));
        ShelfList.push_back(Shelf("Y3I1","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("Y3I2","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("Y4I1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Y4I2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Y1J1","CHARGER OEM",0,12));
        ShelfList.push_back(Shelf("Y1J2","CHARGER OEM",0,12));
        ShelfList.push_back(Shelf("Y2J1","CHARGER OEM",0,12));
        ShelfList.push_back(Shelf("Y2J2","CHARGER OEM",0,12));
        ShelfList.push_back(Shelf("Y3J1","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("Y3J2","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("Y4J1","BACK COVER",0,10));
        ShelfList.push_back(Shelf("Y4J2","BACK COVER",0,10));

        ShelfList.push_back(Shelf("Z1A1","LCD COMPLETE ASSEMBLY",0,7));
        ShelfList.push_back(Shelf("Z1A2","LCD COMPLETE ASSEMBLY",0,7));
        ShelfList.push_back(Shelf("Z2A1","LCD COMPLETE ASSEMBLY",0,7));
        ShelfList.push_back(Shelf("Z2A2","LCD COMPLETE ASSEMBLY",0,7));
        ShelfList.push_back(Shelf("Z3A1","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("Z3A2","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("Z4A1","BOTTOM CASE",0,8));
        ShelfList.push_back(Shelf("Z4A2","BOTTOM CASE",0,8));
        ShelfList.push_back(Shelf("Z1B1","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Z1B2","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Z2B1","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Z2B2","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Z3B1","CPU COOLING FAN",0,12));
        ShelfList.push_back(Shelf("Z3B2","CPU COOLING FAN",0,12));
        ShelfList.push_back(Shelf("Z4B1","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Z4B2","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Z1C1","BATTERY OEM",0,15));
        ShelfList.push_back(Shelf("Z1C2","BATTERY OEM",0,15));
        ShelfList.push_back(Shelf("Z2C1","BOTTOM CASE",0,8));
        ShelfList.push_back(Shelf("Z2C2","BOTTOM CASE",0,8));
        ShelfList.push_back(Shelf("Z3C1","SATA CD DVD DRIVER",0,8));
        ShelfList.push_back(Shelf("Z3C2","SATA CD DVD DRIVER",0,8));
        ShelfList.push_back(Shelf("Z4C1","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Z4C2","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Z1D1","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Z1D2","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Z2D1","BOTTOM CASE",0,8));
        ShelfList.push_back(Shelf("Z2D2","BOTTOM CASE",0,8));
        ShelfList.push_back(Shelf("Z3D1","HARD DRIVE B",0,6));
        ShelfList.push_back(Shelf("Z3D2","WEBCAM",0,40));
        ShelfList.push_back(Shelf("Z4D1","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Z4D2","BOTTOM CASE",0,10));
        ShelfList.push_back(Shelf("Z1E1","BACK COVER",0,10));
        ShelfList.push_back(Shelf("Z1E2","BACK COVER",0,10));
        ShelfList.push_back(Shelf("Z2E1","BACK COVER",0,10));
        ShelfList.push_back(Shelf("Z2E2","BACK COVER",0,10));
        ShelfList.push_back(Shelf("Z3E1","HARD DRIVE B",0,6));
        ShelfList.push_back(Shelf("Z3E2","SCREW KIT",0,40));
        ShelfList.push_back(Shelf("Z4E1","BACK COVER",0,10));
        ShelfList.push_back(Shelf("Z4E2","BACK COVER",0,10));
        ShelfList.push_back(Shelf("Z1F1","LCD LED SCREEN",0,10));
        ShelfList.push_back(Shelf("Z1F2","LCD LED SCREEN",0,10));
        ShelfList.push_back(Shelf("Z2F1","LCD LED SCREEN",0,10));
        ShelfList.push_back(Shelf("Z2F2","LCD LED SCREEN",0,10));
        ShelfList.push_back(Shelf("Z3F1","POWER BUTTON",0,40));
        ShelfList.push_back(Shelf("Z3F2","SSD CARD AND READER",0,40));
        ShelfList.push_back(Shelf("Z4F1","LCD LED SCREEN",0,10));
        ShelfList.push_back(Shelf("Z4F2","LCD LED SCREEN",0,10));
        ShelfList.push_back(Shelf("Z1G1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Z1G2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Z2G1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Z2G2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Z3G1","HARD DRIVE CONNECTOR",0,40));
        ShelfList.push_back(Shelf("Z3G2","LCD VIDEO CABLE",0,40));
        ShelfList.push_back(Shelf("Z4G1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Z4G2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Z1H1","BOTTOM CASE COVER",0,30));
        ShelfList.push_back(Shelf("Z1H2","HINGE BRACKET",0,30));
        ShelfList.push_back(Shelf("Z2H1","BOTTOM CASE COVER",0,30));
        ShelfList.push_back(Shelf("Z2H2","HINGE BRACKET",0,30));
        ShelfList.push_back(Shelf("Z3H1","CAMERA WEBCAM",0,40));
        ShelfList.push_back(Shelf("Z3H2","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("Z4H1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Z4H2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Z1I1","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Z1I2","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Z2I1","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Z2I2","LCD BESEL TRIMM",0,12));
        ShelfList.push_back(Shelf("Z3I1","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("Z3I2","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("Z4I1","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Z4I2","PALMREST+TOUCHPAD",0,10));
        ShelfList.push_back(Shelf("Z1J1","CHARGER OEM",0,12));
        ShelfList.push_back(Shelf("Z1J2","CHARGER OEM",0,12));
        ShelfList.push_back(Shelf("Z2J1","CHARGER OEM",0,12));
        ShelfList.push_back(Shelf("Z2J2","CHARGER OEM",0,12));
        ShelfList.push_back(Shelf("Z3J1","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("Z3J2","MOTHERBOARD",0,5));
        ShelfList.push_back(Shelf("Z4J1","BACK COVER",0,10));
        ShelfList.push_back(Shelf("Z4J2","BACK COVER",0,10));
        store_shelves();
    }
}
void Window::store_shelves(){
    std::ofstream file;
    std::vector<std::string> items;
    std::vector<int> counts;
    file.open("shelfList.txt");
    for (uint i = 0; i < ShelfList.size(); i++){
        file << ShelfList[i].get_shelfloc() << '|';
        file << ShelfList[i].get_type() << '|';
        file << ShelfList[i].get_max() << '|';
        file << ShelfList[i].get_count() << '|';
        items = ShelfList[i].get_storedNames();
        for (uint k = 0; k < items.size(); k++){
            file << items[k] << '|';
        }
        file << '$';
        counts = ShelfList[i].get_storedCount();
        for (uint j = 0; j < counts.size(); j++){
            file << counts[j] << '|';
        }
        file << '$' << '\n';
    }
    file.close();
}
void Window::load_acc(){
    std::ifstream file;
    file.open("accList.txt");
    std::string line, user, pass, a;
    int auth;
    uint i;

    if (file.is_open()){
        while (!file.eof()){
            std::getline(file, line);
            i = 0;
            user = "";
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                user = user + line[i];
                i++;
            }
            pass  = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                pass = pass + line[i];
                i++;
            }
            a = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '$')){
                a = a + line[i];
                i++;
            }
            if (a != "")
                auth = std::stoi(a);
            else
                auth = 0;

            if (user != "")
                AccountList.push_back(Account(user,pass,auth));
        }
        file.close();
    }
    else{
        //Admin Account
        AccountList.push_back(Account("Admin","password",3));
        store_acc();
    }
}
void Window::store_acc(){
    std::ofstream file;
    file.open("accList.txt");
    for (uint i = 0; i < AccountList.size(); i++){
        file << AccountList[i].get_user() << '|';
        file << AccountList[i].get_pass() << '|';
        file << AccountList[i].get_auth() << '$';
        file << '\n';
    }
    file.close();
}
void Window::load_ereport(){
    std::ifstream file;
    file.open("eReport.txt");
    struct tm t;
    time_t tm;
    std::string line, name, act, tmp;
    int time_part;
    uint i;

    if (file.is_open()){
        while (!file.eof()){
            std::getline(file, line);
            i = 0;
            name = "";
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                name = name + line[i];
                i++;
            }
            act  = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                act = act + line[i];
                i++;
            }
            //Construct time
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_sec = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_min = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_hour = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_mday = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_mon = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_year = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_wday = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_yday = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '$')){
                tmp = tmp + line[i];
                i++;
            }
            i++;
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_isdst = time_part;
            }
            tm = std::mktime(&t);
            if (name != "")
                EmployeeReport.push_back(EmployeeAct(name, act, tm));
        }
        file.close();
    }
}
void Window::store_ereport(){
    std::ofstream file;
    file.open("eReport.txt");
    struct tm t;
    time_t tm;
    for (uint i = 0; i < EmployeeReport.size(); i++){
        file << EmployeeReport[i].get_user() << '|';
        file << EmployeeReport[i].get_action() << '|';
        tm = EmployeeReport[i].get_time();
        t = *std::localtime(&tm);
        file << t.tm_sec << '|';
        file << t.tm_min << '|';
        file << t.tm_hour << '|';
        file << t.tm_mday << '|';
        file << t.tm_mon << '|';
        file << t.tm_year << '|';
        file << t.tm_wday << '|';
        file << t.tm_yday << '|';
        file << t.tm_isdst << '$';
        file << '\n';
    }
}
void Window::load_freport(){
    std::ifstream file;
    file.open("fReport.txt");
    struct tm t;
    time_t tm;
    std::string line, name, type, c, d, ce, tmp;
    int count, dollar, cent, time_part;
    uint i;

    if (file.is_open()){
        while (!file.eof()){
            std::getline(file, line);
            i = 0;
            name = "";
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                name = name + line[i];
                i++;
            }
            type  = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                type = type + line[i];
                i++;
            }
            c = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                c = c + line[i];
                i++;
            }
            if (c != "")
                count = std::stoi(c);
            else
                count = 0;
            d = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                d = d + line[i];
                i++;
            }
            if (d != "")
                dollar = std::stoi(d);
            else
                dollar = 0;
            ce = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                ce = ce + line[i];
                i++;
            }
            if (ce != "")
                cent = std::stoi(ce);
            else
                cent = 0;

            //Construct time
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_sec = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_min = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_hour = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_mday = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_mon = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_year = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_wday = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_yday = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '$')){
                tmp = tmp + line[i];
                i++;
            }
            i++;
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_isdst = time_part;
            }
            tm = std::mktime(&t);
            if (name != "")
                FinancialReport.push_back(Financial(name,type,count,dollar,cent,tm));
        }
        file.close();
    }
}
void Window::store_freport(){
    std::ofstream file;
    file.open("fReport.txt");
    struct tm t;
    time_t tm;
    for (uint i = 0; i < FinancialReport.size(); i++){
        file << FinancialReport[i].get_name() << '|';
        file << FinancialReport[i].get_type() << '|';
        file << FinancialReport[i].get_count() << '|';
        file << FinancialReport[i].get_dollar() << '|';
        file << FinancialReport[i].get_cents() << '|';
        tm = FinancialReport[i].get_time();
        t = *std::localtime(&tm);
        file << t.tm_sec << '|';
        file << t.tm_min << '|';
        file << t.tm_hour << '|';
        file << t.tm_mday << '|';
        file << t.tm_mon << '|';
        file << t.tm_year << '|';
        file << t.tm_wday << '|';
        file << t.tm_yday << '|';
        file << t.tm_isdst << '$';
        file << '\n';
    }
    file.close();
}
void Window::load_ehour(){
    std::ifstream file;
    //FILE NEEDS TO BE IN build-InvManage... DIRECTORY
    file.open("empHour.txt"/*,std::ifstream::in*/);
    std::string line, uname, tmp, finish;
    bool done;
    int time_part;
    time_t in, out;
    struct tm t;
    uint i;

    if (file.is_open()){
        while (!file.eof()){
            std::getline(file, line);
            i = 0;
            uname = "";
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                uname = uname + line[i];
                i++;
            }
            finish  = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                finish = finish + line[i];
                i++;
            }
            if (finish == "t")
                done = true;
            else
                done = false;
            //Construct time
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_sec = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_min = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_hour = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_mday = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_mon = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_year = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_wday = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_yday = time_part;
            }
            tmp = "";
            i++;
            while (!file.eof() && (i < line.length() && line[i] != '|')){
                tmp = tmp + line[i];
                i++;
            }
            i++;
            if(tmp != "") {
                time_part = std::stoi(tmp);
                t.tm_isdst = time_part;
            }
            in = mktime(&t);
            if (done){
                //Construct time
                tmp = "";
                while (!file.eof() && (i < line.length() && line[i] != '|')){
                    tmp = tmp + line[i];
                    i++;
                }
                time_part = std::stoi(tmp);
                t.tm_sec = time_part;
                tmp = "";
                i++;
                while (!file.eof() && (i < line.length() && line[i] != '|')){
                    tmp = tmp + line[i];
                    i++;
                }
                time_part = std::stoi(tmp);
                t.tm_min = time_part;
                tmp = "";
                i++;
                while (!file.eof() && (i < line.length() && line[i] != '|')){
                    tmp = tmp + line[i];
                    i++;
                }
                time_part = std::stoi(tmp);
                t.tm_hour = time_part;
                tmp = "";
                i++;
                while (!file.eof() && (i < line.length() && line[i] != '|')){
                    tmp = tmp + line[i];
                    i++;
                }
                time_part = std::stoi(tmp);
                t.tm_mday = time_part;
                tmp = "";
                i++;
                while (!file.eof() && (i < line.length() && line[i] != '|')){
                    tmp = tmp + line[i];
                    i++;
                }
                time_part = std::stoi(tmp);
                t.tm_mon = time_part;
                tmp = "";
                i++;
                while (!file.eof() && (i < line.length() && line[i] != '|')){
                    tmp = tmp + line[i];
                    i++;
                }
                time_part = std::stoi(tmp);
                t.tm_year = time_part;
                tmp = "";
                i++;
                while (!file.eof() && (i < line.length() && line[i] != '|')){
                    tmp = tmp + line[i];
                    i++;
                }
                time_part = std::stoi(tmp);
                t.tm_wday = time_part;
                tmp = "";
                i++;
                while (!file.eof() && (i < line.length() && line[i] != '|')){
                    tmp = tmp + line[i];
                    i++;
                }
                time_part = std::stoi(tmp);
                t.tm_yday = time_part;
                tmp = "";
                i++;
                while (!file.eof() && (i < line.length() && line[i] != '|')){
                    tmp = tmp + line[i];
                    i++;
                }
                i++;
                time_part = std::stoi(tmp);
                t.tm_isdst = time_part;
                out = mktime(&t);
                if (uname != "")
                    EmployeeHours.push_back(EmployeeTime(uname, done, in , out));
            }
            else if (uname != "")
                EmployeeHours.push_back(EmployeeTime(uname, done, in));

        }
        file.close();
    }
}
void Window::store_ehour(){
    std::ofstream file;
    file.open("empHour.txt");
    time_t tmp;
    struct tm t;
    bool finished;
    for (uint i = 0; i < EmployeeHours.size(); i++){
        file << EmployeeHours[i].get_uName() << '|';
        finished = EmployeeHours[i].is_complete();
        if (finished)
                file << 't' << '|';
        else
                file << 'f' << '|';
        //Intime store
        tmp = EmployeeHours[i].get_inTime();
        t = *std::localtime(&tmp);
        file << t.tm_sec << '|';
        file << t.tm_min << '|';
        file << t.tm_hour << '|';
        file << t.tm_mday << '|';
        file << t.tm_mon << '|';
        file << t.tm_year << '|';
        file << t.tm_wday << '|';
        file << t.tm_yday << '|';
        file << t.tm_isdst << '|';
        if (finished){
            tmp = EmployeeHours[i].get_outTime();
            t = *std::localtime(&tmp);
            file << t.tm_sec << '|';
            file << t.tm_min << '|';
            file << t.tm_hour << '|';
            file << t.tm_mday << '|';
            file << t.tm_mon << '|';
            file << t.tm_year << '|';
            file << t.tm_wday << '|';
            file << t.tm_yday << '|';
            file << t.tm_isdst << '|';
        }
        file << '$' << '\n';
    }
    file.close();
}
