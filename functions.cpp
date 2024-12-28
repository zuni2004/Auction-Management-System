#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include "functions.h"
using namespace std;

bool authenticateAdmin(const string &name,const string &username,const string &password, const Admin *admin) {
    if (name == admin->name && username == admin->username && password == admin->password) {
        return true;
    }
    return false;
}

void loadadminCredentials(Admin *admin) {
    ifstream infile("admin.txt");
    if (!infile.is_open()) {
        cout << "Error : Unable to Open Admin Credentials File for Loading Credentials." << endl;
        return;
    }
    getline(infile,admin->name);
    getline(infile,admin->username);
    getline(infile,admin->password);
    infile.close();
}

void loadSellersFromFile(Seller sellers[], int &numSellers) {
    ifstream infile("sellers.txt");
    if (!infile.is_open()) {
        cout << "Error : Unable to Open Sellers Data File for Obtaining Previous Data." << endl;
        return;
    }
    infile >> numSellers;
    infile.ignore();
    for (int i = 0; i < numSellers; i++) {
        infile >> sellers[i].id;
        infile.ignore();
        getline(infile,sellers[i].name);
        infile >> sellers[i].budget;
        infile >> sellers[i].isBlocked;
        infile.ignore();
    }
    infile.close();
}

void loadBuyersFromFile(Buyer buyers[], int &numBuyers) {
    ifstream infile("buyers.txt");
    if (!infile.is_open()) {
        cout << "Error : Unable to Open Buyers Data File for Obtaining Previous Data." << endl;
        return;
    }
    infile >> numBuyers;
    infile.ignore();
    for (int i = 0; i < numBuyers; i++) {
        infile >> buyers[i].id;
        infile.ignore();
        getline(infile,buyers[i].name);
        infile >> buyers[i].budget;
        infile >> buyers[i].chances;
        infile.ignore();
    }
    infile.close();
}

void loadItemsFromFile(Item item[], int &numItems) {
    ifstream infile("items.txt");
    if (!infile.is_open()) {
        cout << "Error : Unable to Open Items Data File for Obtaining Previous Data." << endl;
        return;
    }
    infile >> numItems;
    infile.ignore();
    for (int i = 0; i < numItems; i++) {
        infile >> item[i].id;
        infile.ignore();
        getline(infile, item[i].name);
        getline(infile, item[i].description);
        infile >> item[i].startingPrice;
        infile >> item[i].currentBid;
        infile >> item[i].sellerId;
        infile >> item[i].isAuctionActive;
        infile >> item[i].isDelivered;
        infile >> item[i].buyerId;
        infile.ignore();
    }
    infile.close();
}

void loadBillsFromFile(Bill bills[], int &numBills) {
    ifstream infile("bills.txt");
    if (!infile.is_open()) {
        cout << "Error : Unable to Open Bills Data File for Obtaining Previous Data." << endl;
        return;
    }
    infile >> numBills;
    infile.ignore();
    for (int i = 0; i < numBills; i++) {
        infile >> bills[i].id;
        infile >> bills[i].buyerId;
        infile >> bills[i].itemId;
        infile >> bills[i].amount;
        infile.ignore();
    }
    infile.close();
}

void loadAuthenticationsFromFile(Authentication authData[], int &numAuthData) {
    ifstream infile("authentications.txt");
    if (!infile.is_open()) {
        cout << "Error : Unable to Open Authentications Data File for Obtaining Previous Data." << endl;
        return;
    }
    while (!infile.eof() && numAuthData < MAX_AuthData) {
        infile >> authData[numAuthData].authID;
        infile >> authData[numAuthData].id;
        infile.ignore();
        getline(infile, authData[numAuthData].username);
        getline(infile, authData[numAuthData].password);
        infile.ignore();
        numAuthData++;
    }
    infile.close();
}

void saveSellersToFile(Seller sellers[], const int &numSellers) {
    ofstream outfile("sellers.txt");
    if (!outfile.is_open()) {
        cout << "Error : Unable to Open Sellers Data File for Saving Data." << endl;
        return;
    }
    outfile << numSellers << endl;
    for (int i = 0; i < numSellers; i++) {
        outfile << sellers[i].id << endl;
        outfile << sellers[i].name << endl;
        outfile << sellers[i].budget << endl;
        outfile << sellers[i].isBlocked << endl;
    }
    outfile.close();
}

void saveBuyersToFile(Buyer buyers[], const int &numBuyers) {
    ofstream outfile("buyers.txt");
    if (!outfile.is_open()) {
        cout << "Error : Unable to Open Buyers Data File for Saving Data." << endl;
        return;
    }
    outfile << numBuyers << endl;
    for (int i = 0; i < numBuyers; i++) {
        outfile << buyers[i].id << endl;
        outfile << buyers[i].name << endl;
        outfile << buyers[i].budget << endl;
        outfile << buyers[i].chances << endl;
    }
    outfile.close();
}

void saveItemsToFile(Item item[], const int &numItems) {
    ofstream outfile("items.txt");
    if (!outfile.is_open()) {
        cout << "Error : Unable to Open Items Data File for Saving Data." << endl;
        return;
    }
    outfile << numItems << endl;
    for (int i = 0; i < numItems; i++) {
        outfile << item[i].id << endl;
        outfile << item[i].name << endl;
        outfile << item[i].description << endl;
        outfile << item[i].startingPrice << endl;
        outfile << item[i].currentBid << endl;
        outfile << item[i].sellerId << endl;
        outfile << item[i].isAuctionActive << endl;
        outfile << item[i].isDelivered << endl;
        outfile << item[i].buyerId << endl;
    }
    outfile.close();
}

void saveBillsToFile(Bill bills[], const int &numBills) {
    ofstream outfile("bills.txt");
    if (!outfile.is_open()) {
        cout << "Error : Unable to Open Bills Data File for Saving Data." << endl;
        return;
    }
    outfile << numBills << endl;
    for (int i = 0; i < numBills; i++) {
        outfile << bills[i].id << endl;
        outfile << bills[i].buyerId << endl;
        outfile << bills[i].itemId << endl;
        outfile << bills[i].amount << endl;
    }
    outfile.close();
}

void saveAdminCredentialsToFile(Admin *admin) {
    ofstream outfile("admin.txt");
    if (!outfile.is_open()) {
        cout << "Error : Unable to Open Admin Credential File for Saving Credentials." << endl;
        return;
    }
    outfile << admin->name << endl;
    outfile << admin->username << endl;
    outfile << admin->password << endl;
    outfile.close();
}

void saveAuthenticationToFile(Authentication authData[], const int &numAuthData) {
    ofstream outfile("authentications.txt");
    if (!outfile.is_open()) {
        cout << "Error : Unable to Open Authentications Data file to Save Data." << endl;
        return;
    }
    for (int i = 0; i < numAuthData; i++) {
        outfile << authData[i].authID << endl;
        outfile << authData[i].id << endl;
        outfile << authData[i].username << endl;
        outfile << authData[i].password << endl;
    }
    outfile.close();
}

bool isStrongPassword(const string &password) {
    bool hasUpperCase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;

    if (password.length() < 8) {
        cout << "Password must have at least 8 characters." << endl;
        return false;
    }

    for (char c : password) {
        if (c >= 'A' && c <= 'Z') {
            hasUpperCase = true;
        } else if (c >= '0' && c <= '9') {
            hasDigit = true;
        } else if (c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '~' || c == '`') {
            hasSpecialChar = true;
        }
    }

    if (!hasUpperCase) {
        cout << "Password must contain at least one uppercase letter." << endl;
    }
    if (!hasDigit) {
        cout << "Password must contain at least one digit." << endl;
    }
    if (!hasSpecialChar) {
        cout << "Password must contain at least one special character." << endl;
    }
    return hasUpperCase && hasDigit && hasSpecialChar;
}

void registerSeller(Seller sellers[], int &numSellers, Authentication authData[], int &numAuthData) {
    string username,password;
    Authentication newAuth;
    cout << "\tKindly Create An Account and Register Yourself.\n";
    if (numSellers < MAX_SELLERS) {
        sellers[numSellers].id = numSellers + 1;
        cout << "Enter Your Name : ";
        cin.ignore();
        getline(cin, sellers[numSellers].name);
        cout << "Enter a username: ";
        getline(cin, username);
        do {
            cout << "Enter a password: ";
            getline(cin, password);
        } while (!isStrongPassword(password));
        cout << "Enter Your Budget : Rs. ";
        cin >> sellers[numSellers].budget;
        sellers[numSellers].isBlocked = false;
        newAuth = {numAuthData,sellers[numSellers].id,username,password};
        authData[numAuthData] = newAuth;
        numAuthData++;
        numSellers++;
        saveAuthenticationToFile(authData,numAuthData);
        saveSellersToFile(sellers,numSellers);
        cout << "Seller registered successfully.\n";
        cout << "(Note : Your Particular Unique ID For Most Functionalities is ' " << numSellers << " ' & ' " << numAuthData - 1 << " ' RESPECTIVELY )\n";
    } else {
        cout << "Maximum number of sellers reached. Cannot register new seller.\n";
    }
}

void registerBuyer(Buyer buyers[], int &numBuyers, Authentication authData[], int &numAuthData) {
    string username,password;
    Authentication newAuth;
    cout << "\tKindly Create An Account and Register Yourself.\n";
    if (numBuyers < MAX_BUYERS) {
        buyers[numBuyers].id = numBuyers + 1;
        cout << "Enter Your Name : ";
        cin.ignore();
        getline(cin, buyers[numBuyers].name);
        cout << "Enter a username: ";
        getline(cin, username);
        do {
            cout << "Enter a password: ";
            getline(cin, password);
        } while (!isStrongPassword(password));
        cout << "Enter Your Budget : Rs. ";
        cin >> buyers[numBuyers].budget;
        buyers[numBuyers].chances = 3;
        newAuth = {numAuthData,buyers[numBuyers].id,username,password};
        authData[numAuthData] = newAuth;
        numAuthData++;
        numBuyers++;
        saveAuthenticationToFile(authData,numAuthData);
        saveBuyersToFile(buyers,numBuyers);
        cout << "Buyer registered successfully.\n";
        cout << "(Note : Your Particular Unique ID & Authentication ID For Most Functionalities is ' " << numBuyers << " ' & ' " << numAuthData - 1 << " ' RESPECTIVELY )\n";
    } else {
        cout << "Maximum number of buyers reached. Cannot register new buyer.\n";
    }
}

bool authenticateUser(Authentication authData[], int numAuthData, const int &authID, const int &id , const string &username, const string &password) {
    for (int i = 0; i < numAuthData; i++) {
        if (authData[i].authID == authID && authData[i].id == id && authData[i].username == username && authData[i].password == password) {
            return true;
        }
    }
    return false;
}

void changeCredentials(Authentication authData[], int numAuthData,const int &authID, const int &id, const string &newUsername, const string &newPassword) {
    for (int i = 0; i < numAuthData; i++) {
        if (authData[i].authID == authID && authData[i].id == id) {
            authData[i].username = newUsername;
            authData[i].password = newPassword;
            saveAuthenticationToFile(authData,numAuthData);
            break;
        }
    }
}

void processPayment(Buyer *buyers, const int &numBuyers, Item *items, const int &numItems, Seller *sellers, const int &numSellers, Bill *bills, int &numBills, const int &buyerId, const int &itemId, const float &amount) {
    for (int i = 0; i < numBuyers; i++) {
        if (buyers[i].id == buyerId) {
            if (buyers[i].budget < amount) {
                cout << "\tInsufficient Funds ! Payment Failed !\n"
                     << "\tPlease Try Again After Adding Funds in Your Account !\n";
                return;
            }
            int itemIndex = itemId - 1;
            if (itemId < 0 || itemId >= numItems || items[itemIndex].isDelivered) {
                cout << "Invalid Item ID or Item Not Available For Purchase!\n";
                return;
            }
            int sellerIndex = items[itemIndex].sellerId - 1;
            if (sellers[sellerIndex].isBlocked) {
                cout << "Seller is Blocked ! Payment Failed !\n";
                return;
            }
            buyers[i].budget -= amount;
            sellers[sellerIndex].budget += amount;
            bills[numBills].id = numBills + 1;
            bills[numBills].buyerId = buyerId;
            bills[numBills].itemId = itemId;
            bills[numBills].amount = amount;
            numBills++;

            cout << "Payment Successful ! Amount Paid : " << amount << endl;
            cout << "Bill ID : " << bills[numBills].id << " (Make Sure to Save it For Bill Related Functionalities of Program)\n";
            cout << "Item ID : " << itemId << " Purchased From Seller Having ID : " << sellers[sellerIndex].id << endl;
            cout << "Item Name : " << items[itemIndex].name << endl;
            cout << "Seller Name : " << sellers[sellerIndex].name << endl;
            saveBuyersToFile(buyers,numBuyers);
            saveSellersToFile(sellers,numSellers);
            saveItemsToFile(items,numItems);
            saveBillsToFile(bills,numBills);
            return;
        }
    }
    cout << "Buyer with ID ' " << buyerId << " ' NOT FOUND.\n";
}

void generateBillRecursive(Bill bills[], const int &numBills, const int &billId, Item items[], Buyer buyers[], Seller sellers[], int i) {
    if (i < numBills) {
        if (bills[i].id == billId) {
            int itemId = bills[i].itemId;
            int buyerId = bills[i].buyerId;
            int buyerIndex = buyerId - 1;
            int itemIndex = itemId - 1;
            int sellerId = items[itemIndex].sellerId;
            int sellerIndex = items[itemIndex].sellerId - 1;
            cout << "Bill ID : " << bills[i].id << endl;
            cout << "Buyer ID : " << buyerId << endl;
            cout << "Buyer Name : " << buyers[buyerIndex].name << endl;
            cout << "Item ID : " << itemId << endl;
            cout << "Item Name : " << items[itemIndex].name << endl;
            cout << "Item Description : " << items[itemIndex].description << endl;
            cout << "Seller ID : " << sellerId << endl;
            cout << "Seller Name : " << sellers[sellerIndex].name << endl;
            cout << "Billing Amount Deducted : " << bills[i].amount << endl;
            cout << "Remaining Buyer Amount : " << buyers[buyerIndex].budget << endl;
            return;
        }
        generateBillRecursive(bills, numBills, billId, items, buyers, sellers, i + 1);
    } else {
        cout << "Bill With ID ' " << billId << " ' NOT FOUND.\n";
    }
}

void generateBill(Bill bills[], const int &numBills, const int &billId, Item items[], Buyer buyers[], Seller sellers[]) {
    generateBillRecursive(bills, numBills, billId, items, buyers, sellers, 0);
}

void viewTransactions(Item *items, Seller *sellers, Bill *bills, const int &numBills, const int &buyerId) {
    cout << "Transaction History for Buyer ID '" << buyerId << "' is Given Below:\n";
    bool foundBills = false;
    for (int i = 0; i < numBills; i++) {
        if (bills[i].buyerId == buyerId) {
            foundBills = true;
            int itemIndex = bills[i].itemId - 1;
            int sellerIndex = items[itemIndex].sellerId - 1;

            cout << "Bill ID : " << bills[i].id << " ;\n"
                 << "Item Name : " << items[itemIndex].name << " ;\n"
                 << "Seller Name : " << sellers[sellerIndex].name << " ;\n"
                 << "Current Bid : " << items[itemIndex].currentBid << " ;\n"
                 << "Billing Amount : " << bills[i].amount << " ;\n"
                 << "Remaining Buyer Budget : " << sellers[sellerIndex].budget << " ;\n"
                 << "\t--------------------------\n";
        }
    }
    if (!foundBills) {
        cout << "No bills found for Buyer ID ' " << buyerId << " '.\n";
    }
}

void buyerMenuForBills(Seller sellers[], const int &numSellers, Buyer buyers[], const int &numBuyers, Bill bills[], int &numBills, Item items[], const int &numItems) {
    cout << "This Menu is a Part of Buyer Menu and only used for Initialization of Data to show the working of Payment Module Functions.\n";
    items[0] = {1,"Special Item 1","It is a Sample Initialized Item.",50000,60000,1,true,false,1};
    items[1] = {2,"Special Item 2","It is a Sample Initialized Item.",60000,70000,1,true,true,2};
    items[2] = {3,"Special Item 3","It is a Sample Initialized Item.",30000,74000,2,true,true,1};
    items[3] = {4,"Special Item 4","It is a Sample Initialized Item.",90000,100000,2,true,false,2};
    cout << "4 items have been Initialised, You can check the Validity of Program.\n";
    int choice;
    do {
        cout << "The following are the 3 functionalities to Check :\n"
             << "1 - Payment Processing After Winning Auction\n"
             << "2 - Generation of Bill\n"
             << "3 - View Transaction History\n"
             << "4 - Exit the Checking Program\n";
        cin >> choice;
        switch (choice) {
            case 1: {
                int id,itemId,amount;
                cout << "Please Provide Your Unique ID : ";
                cin >> id;
                cout << "Provide the ID of the Item for whom you have Won Auction : ";
                cin >> itemId;
                int itemIndex = itemId - 1;
                amount = items[itemIndex].currentBid;
                processPayment(buyers,numBuyers,items,numItems,sellers,numSellers,bills,numBills,id,itemId,amount);
                break;
            }
            case 2: {
                int id;
                cout << "Provide the Unique Bill ID to Generate Bill : ";
                cin >> id;
                generateBill(bills,numBills,id,items,buyers,sellers);
                break;
            }
            case 3: {
                int id;
                cout << "Please Provide Your Unique ID to View Your Transactions : ";
                cin >> id;
                viewTransactions(items,sellers,bills,numBills,id);
                break;
            }
            case 4: {
                break;
            }
        }
    } while (choice != 4);
}
int randomGenerateIdForAuction() {
    static int lastId = 0;
    ifstream idCheck("lastIdForAuction.txt");
    if (idCheck.is_open()) {
        idCheck >> lastId;
        idCheck.close();
    }
    int newId = lastId + 1;
    ofstream idStore("lastIdForAuction.txt");
    if (idStore.is_open()) {
        idStore << newId;
        idStore.close();
    }
    return newId;
}

void createAuction(string auctionName, float startingPrice, int auctionDuration) {
    time_t currentTime;
    time(&currentTime);

    tm* timeInfo = localtime(&currentTime);
    string startTime = asctime(timeInfo);
    timeInfo->tm_sec += auctionDuration * 24 * 60 * 60;
    string endTime = asctime(timeInfo);

    Auction newAuction;
    newAuction.id = randomGenerateIdForAuction();
    newAuction.name = auctionName;
    newAuction.startingPrice = startingPrice;
    newAuction.startTimeString = startTime;
    newAuction.endTimeString = endTime;
    newAuction.currentBid = startingPrice;
    newAuction.status = "active";
    newAuction.buyerId = 0;

    ofstream auctionFile("auctionDetails.txt", ios::app);
    if (auctionFile.is_open()) {
        auctionFile << newAuction.id << " " << newAuction.name << " " << newAuction.startingPrice
            << " " << newAuction.startTimeString << " " << newAuction.endTimeString << " "
            << newAuction.currentBid << " " << newAuction.status << " " << newAuction.buyerId << endl;
        auctionFile.close();
        cout << "Auction created successfully and details stored in file." << endl;
    } else {
        cout << "Error: Unable to open the auction details file." << endl;
    }
}

Auction getAuctionById(int auctionId) {
    Auction details;
    ifstream auctionFile("auctionDetails.txt");
    if (auctionFile.is_open()) {
        int id;
        string name;
        float startingPrice;
        string startTime, endTime;
        float currentBid;
        string status;
        int buyerId;
        while (auctionFile >> id >> name >> startingPrice >> startTime >> endTime >> currentBid >> status >> buyerId) {
            if (id == auctionId) {
                details.id = id;
                details.name = name;
                details.startingPrice = startingPrice;
                details.startTimeString = startTime;
                details.endTimeString = endTime;
                details.currentBid = currentBid;
                details.status = status;
                details.buyerId = buyerId;
                break;
            }
        }

        auctionFile.close();
    }
    return details;
}

void placeBid(int auctionId, int buyerId, float bidAmount) {
    Auction auction = getAuctionById(auctionId);

    if (auction.status != "closed"||auction.status != "terminated") {
        if (bidAmount > auction.currentBid) {
            auction.currentBid = bidAmount;
            auction.buyerId = buyerId;
            ofstream newHighestBidFile("highestBid_" + to_string(auctionId) + ".txt");
            if (newHighestBidFile.is_open()) {
                newHighestBidFile << bidAmount << "," << buyerId;
                newHighestBidFile.close();
            }

            cout << "Bid placed successfully for auction ID #" << auctionId << endl;
            cout << "Current highest bid amount: " << auction.currentBid << endl;
        } else {
            cout << "Your bid amount is not higher than the current highest bid." << endl;
        }
    } else {
        cout << "Auction is already closed." << endl;
    }
}

void endAuction(int auctionId) {
    Auction auction = getAuctionById(auctionId);
    time_t currentTime;
    time(&currentTime);

    if (currentTime >= mktime(localtime(&currentTime))) {
        auction.status = "closed";

        int winningBuyerId = 0;
        float bidAmount = 0;
        ifstream highestBidFile("highestBid_" + to_string(auction.id) + ".txt");
        if (highestBidFile.is_open()) {
            highestBidFile >> bidAmount >> winningBuyerId;
            highestBidFile.close();
        }

        cout << "The winning buyer ID is: " << winningBuyerId << endl;

        ofstream bidsWonFile("bidsWon.txt", ios::app);
        if (bidsWonFile.is_open()) {
            bidsWonFile << auction.id << "," << winningBuyerId << endl;
            bidsWonFile.close();
        }

        if (auction.currentBid == 0) {
            auction.status = "expired";
        }
    } else {
        cout << "Auction has not ended yet." << endl;
    }
}

void displayWonBids() {
    ifstream bidsWonFile("bidsWon.txt");
    if (bidsWonFile.is_open()) {
        int auctionId, winningBuyerId;
        while (bidsWonFile >> auctionId >> winningBuyerId) {
            cout << "Auction ID: " << auctionId << ", Winning buyer ID: " << winningBuyerId << endl;
        }
        bidsWonFile.close();
    } else {
        cout << "Error: Unable to open the won bids file." << endl;
    }
}

void displayExpiredBids() {
    ifstream auctionFile("auctionDetails.txt");
    if (auctionFile.is_open()) {
        int auctionId;
        string status;
        while (auctionFile >> auctionId >> status) {
            if (status == "expired") {
                cout << "Expired auction ID: " << auctionId << endl;
            }
        }
        auctionFile.close();
    } else {
        cout << "Error: Unable to open the auction details file." << endl;
    }
}

void terminateAuction(int auctionId) {
    fstream auctionFile("auctionDetails.txt", ios::in | ios::out);
    if (auctionFile.is_open()) {
        int id;
        string name;
        float startingPrice;
        string startTime, endTime;
        float currentBid;
        int buyerId;
        string status;

        while (auctionFile >> id >> name >> startingPrice >> startTime >> endTime >> currentBid >> status >> buyerId) {
            if (id == auctionId) {
                auctionFile.seekp(auctionFile.tellg());
                auctionFile << id << " " << name << " " << startingPrice << " " << startTime << " " << endTime << " " << currentBid << " " << "terminated" << " " << buyerId << endl;

                break;
            }
        }
        auctionFile.close();
        cout << "Auction terminated successfully." << endl;
    } else {
        cout << "Error: Unable to open the auction file." << endl;
    }
}
void addFunds(Buyer &buyers) {
    float amount;
    cout << "Enter the amount to add: ";
    cin >> amount;
    if (amount > 0) {
        buyers.budget += amount;
        cout << "Funds added successfully\n Your New Budget: " << buyers.budget << endl;
    } else {
        cout << "Invalid amount\n";
    }
}

void viewBudget(Buyer &buyers) {
    cout << "Your Budget: " << buyers.budget << endl;
}

void automatedBudgetAlert(Buyer &buyers) {
    if (buyers.budget < ALERT_THRESHOLD) {
        cout << "Automated Budget Alert: Your account balance is below the threshold! Current Balance: "
             << buyers.budget << endl;
    } else {
        cout << "No budget alert needed. Current Balance: " << buyers.budget << endl;
    }
}

void transactionFeeOptions(Buyer &buyers) {
    cout << "Select Transaction Fee Option:\n";
    cout << "1. Fixed Fee\n";
    cout << "2. Percentage Fee\n";
    int feeOption;
    cin >> feeOption;

    float transactionAmount;
    cout << "Enter the transaction amount: ";
    cin >> transactionAmount;

    switch (feeOption) {
        case 1: {
            const float fixedFee = 5.0;
            float totalAmount = transactionAmount + fixedFee;

            if (totalAmount <= buyers.budget) {
                buyers.budget -= totalAmount;
                cout << "Transaction successful. New Balance: " << buyers.budget << endl;
            } else {
                cout << "Insufficient funds for the transaction.\n";
            }
            break;
        }
        case 2: {
            const float percentageFee = 0.02;
            float feeAmount = transactionAmount * percentageFee;
            float totalAmount = transactionAmount + feeAmount;

            if (totalAmount <= buyers.budget) {
                buyers.budget -= totalAmount;
                cout << "Transaction successful. New Balance: " << buyers.budget << endl;
            } else {
                cout << "Insufficient funds for the transaction.\n";
            }
            break;
        }
        default:
            cout << "Invalid transaction fee option.\n";
            break;
    }
}
void manageBuyerBudget(Buyer buyers[]) {
    buyers[0].id = 23058;
    cout << "Enter your ID for verification \n";
    cin >> buyerID;
    for (int i = 0; i < MAX_BUYERS; i++) {
        if (buyers[i].id == buyerID) {
            cout << "LOGIN SUCCESSFUL\n";
            cout << "Enter Budget: ";
            cin >> buyers[i].budget;
            cout << endl;
            cout << "BUDGET MANAGEMENT SYSTEM FOR BUYER\n";
            cout << "1. Add funds\n";
            cout << "2. View Budget\n";
            cout << "3. Automated Budget Alerts\n";
            cout << "4. Transaction Fee Options\n";
            int q;
            cin >> q;
            switch (q) {
                case 1: {
                    addFunds(buyers[i]);
                    break;
                }
                case 2: {
                    viewBudget(buyers[i]);
                    break;
                }
                case 3:{
                    automatedBudgetAlert(buyers[i]);
                    break;
                }
                case 4:{
                    transactionFeeOptions(buyers[i]);
                    break;
                }
                default: {
                    cout << "Invalid request\n";
                    break;
                }

            }
        }
    }
}

void addFunds(Seller &seller) {
    float amount;
    cout << "Enter the amount to add: ";
    cin >> amount;
    if (amount > 0) {
        seller.budget += amount;
        cout << "Funds added successfully\n Your New budget: " << seller.budget << endl;
    } else {
        cout << "Invalid amount. Funds not added." << endl;
    }
}

void withdrawFunds(Seller &seller) {
    float amount;
    cout << "Enter the amount you want to withdraw: ";
    cin >> amount;
    if (amount > 0 && amount <= seller.budget) {
        seller.budget -= amount;
        cout << "Funds withdrawal successful\n Your New Budget: " << seller.budget << endl;
    } else {
        cout << "Insufficient Funds\n Withdrawal of Funds Failed\n";
    }
}

void viewBudget(Seller &seller) {
    cout << "Your Budget: " << seller.budget << endl;
}

void automatedBudgetAlert(Seller &seller) {
    if (seller.budget < ALERT_THRESHOLD) {
        cout << "Automated Budget Alert: Your account balance is below the threshold! Current Balance: "
             << seller.budget << endl;
    } else {
        cout << "No budget alert needed. Current Balance: " << seller.budget << endl;
    }
}

void transactionFeeOptions(Seller &seller) {
    cout << "Select Transaction Fee Option:\n";
    cout << "1. Fixed Fee\n";
    cout << "2. Percentage Fee\n";
    int feeOption;
    cin >> feeOption;

    float transactionAmount;
    cout << "Enter the transaction amount: ";
    cin >> transactionAmount;

    switch (feeOption) {
        case 1: {
            const float fixedFee = 5.0;
            float totalAmount = transactionAmount + fixedFee;

            if (totalAmount <= seller.budget) {
                seller.budget -= totalAmount;
                cout << "Transaction successful. New Balance: " << seller.budget << endl;
            } else {
                cout << "Insufficient funds for the transaction.\n";
            }
            break;
        }
        case 2: {
            const float percentageFee = 0.02;
            float feeAmount = transactionAmount * percentageFee;
            float totalAmount = transactionAmount + feeAmount;

            if (totalAmount <= seller.budget) {
                seller.budget -= totalAmount;
                cout << "Transaction successful. New Balance: " << seller.budget << endl;
            } else {
                cout << "Insufficient funds for the transaction.\n";
            }
            break;
        }
        default:
            cout << "Invalid transaction fee option.\n";
            break;
    }
}

void manageSellerBudget(Seller seller[]) {
    seller[0].id = 23058;
    cout << "Enter your ID for verification \n";
    cin >> sellerID;
    for (int i = 0; i < MAX_SELLERS; i++) {
        if (seller[i].id == sellerID) {
            cout << "LOGIN SUCCESSFUL\n";
            cout << "Enter your Budget: ";
            cin >> seller[i].budget;
            cout << endl;
            cout << "BUDGET MANAGEMENT SYSTEM FOR SELLER\n";
            cout << "1. Add funds\n";
            cout << "2. Withdraw funds\n";
            cout << "3. View Budget\n";
            cout << "4. Automated Budget Alert System: \n";
            cout << "5. Transaction Fee Options: \n";
            int q;
            cin >> q;
            switch (q) {
                case 1: {
                    addFunds(seller[i]);
                    break;
                }
                case 2: {
                    withdrawFunds(seller[i]);
                    break;
                }
                case 3: {
                    viewBudget(seller[i]);
                    break;
                }
                case 4:
                    automatedBudgetAlert(seller[i]);
                    break;
                case 5:
                    transactionFeeOptions(seller[i]);
                    break;
                default: {
                    cout << "Invalid request\n";
                    break;
                }
            }
        }
    }
}
int main() {

    Buyer buyers[MAX_BUYERS];
    Seller seller[MAX_SELLERS];
    cout << "BUDGET MANAGEMENT SYSTEM\n";
    cout << "Are you a Buyer or Seller\n";
    cout << "1. Buyer\n";
    cout << "2. Seller\n";
    int e;
    cin >> e;
    switch (e) {
        case 1: {
            manageBuyerBudget(buyers);
            break;
        }
        case 2: {
            manageSellerBudget(seller);
            break;
        }
        default: {
            cout << "Invalid\n Please enter again\n";
            break;
        }
    }

    return 0;
}
time_t getCurrentTime() {
    return time(nullptr);
}

void saveData(Bid bids[], Item items[], Auction auctions[],
              Buyer buyers[], Bill bills[], Delivery deliveries[]) {


    ofstream dataFile("data.txt");

    if (!dataFile.is_open()) {
        cout << "Error: Unable to open data.txt for writing.\n";
        return;
    }

    for (int i = 0; i < 2; ++i) {
        dataFile << "Bid Information: ID - " << bids[i].id << ", Item ID - " << bids[i].itemId
                 << ", Buyer ID - " << bids[i].buyerId << ", Amount - " << bids[i].amount << "\n";

        dataFile << "Item Information: ID - " << items[i].id << ", Name - " << items[i].name
                 << ", Description - " << items[i].description << ", Starting Price - " << items[i].startingPrice
                 << ", Current Bid - " << items[i].currentBid << ", Seller ID - " << items[i].sellerId
                 << ", Auction Active - " << items[i].isAuctionActive << ", Delivered - " << items[i].isDelivered
                 << ", Buyer ID - " << items[i].buyerId << "\n";

        dataFile << "Auction Information: ID - " << auctions[i].id << ", Item ID - " << auctions[i].itemId
                 << ", Terminated - " << auctions[i].isTerminated << ", Start Time - " << auctions[i].starttime
                 << ", End Time - " << auctions[i].endtime << ", Name - " << auctions[i].name
                 << ", Starting Price - " << auctions[i].startingprice << ", Current Bid - " << auctions[i].currentbid
                 << ", Status - " << auctions[i].status << ", Buyer ID - " << auctions[i].buyerid << "\n";

        dataFile << "Buyer Information: ID - " << buyers[i].id << ", Name - " << buyers[i].name
                 << ", Budget - " << buyers[i].budget << ", Chances - " << buyers[i].chances << "\n";

        dataFile << "Bill Information: ID - " << bills[i].id << ", Buyer ID - " << bills[i].buyerId
                 << ", Item ID - " << bills[i].itemId << ", Amount - " << bills[i].amount << "\n";

        dataFile << "Delivery Information: Item ID - " << deliveries[i].itemId << ", Buyer ID - "
                 << deliveries[i].buyerId
                 << ", Delivered - " << deliveries[i].delivered << "\n";

        dataFile << "-----------------------\n";
    }

    dataFile.close();
    cout << "Data saved successfully.\n";
}

void loadData(Bid bids[], Item items[], Auction auctions[],
              Buyer buyers[], Bill bills[], Delivery deliveries[]) {
    ifstream dataFile("data.txt");

    if (!dataFile.is_open()) {
        cout << "Error: Unable to open data.txt for reading.\n";
        return;
    }

    for (int i = 0; i < 2; ++i) {
        dataFile >> bids[i].id >> bids[i].itemId >> bids[i].buyerId >> bids[i].amount;

        dataFile >> items[i].id >> items[i].name >> items[i].description >> items[i].startingPrice
                 >> items[i].currentBid >> items[i].sellerId >> items[i].isAuctionActive
                 >> items[i].isDelivered >> items[i].buyerId;

        dataFile >> auctions[i].id >> auctions[i].itemId >> auctions[i].isTerminated
                 >> auctions[i].starttime >> auctions[i].endtime >> auctions[i].name
                 >> auctions[i].startingprice >> auctions[i].currentbid >> auctions[i].status
                 >> auctions[i].buyerid;

        dataFile >> buyers[i].id >> buyers[i].name >> buyers[i].budget >> buyers[i].chances;

        dataFile >> bills[i].id >> bills[i].buyerId >> bills[i].itemId >> bills[i].amount;

        dataFile >> deliveries[i].itemId >> deliveries[i].buyerId >> deliveries[i].delivered;
    }

    dataFile.close();  // Move this line outside the loop

    cout << "Data loaded successfully.\n";
    cout << endl;
}

void generateSummary() {
    // Load data at the start of the function
    const int SIZE = 2;  // Adjust the size based on the number of elements you want

    Bid bids[SIZE] = {
            {0, 101, 201, 500.00},
            {2, 102, 202, 300.00}
    };

    Item items[SIZE] = {
            {101, "Item1", "Description1", 100.00, 150.00, 301, true, false, 201},
            {102, "Item2", "Description2", 200.00, 250.00, 302, true, false, 202}
    };

    Auction auctions[SIZE] = {
            {201, 101, false, 0, 0, "Auction1", 100.00,
                    "2022-01-01 12:00:00", "2022-01-02 12:00:00", 150.00, "Active", 0},

            {202, 102, false, 0, 0, "Auction2", 200.00,
                    "2022-01-01 14:00:00", "2022-01-02 14:00:00", 250.00, "Active", 0}
    };

    Buyer buyers[SIZE] = {
            {201, "Buyer1", 1000.00, 3},
            {202, "Buyer2", 800.00,  2}
    };

    Bill bills[SIZE] = {
            {301, 201, 101, 150.00},
            {302, 202, 102, 250.00}
    };

    Delivery deliveries[SIZE] = {
            {101, 201, false},
            {102, 202, false}
    };

    loadData(bids, items, auctions, buyers, bills, deliveries);
    saveData(bids, items, auctions, buyers, bills, deliveries);
}


bool isAuctionExpired(const Auction &auction) {
    time_t currentTime = getCurrentTime();

    if (currentTime > auction.endTime) {
        cout << "The auction has expired.\n";
        return true;
    } else {
        cout << "The auction is still ongoing.\n";
        return false;
    }
}


const int MAX_ITEMS = 2;

void addItem(AuctionItem items[], int &itemCount, int itemId, int initialDuration) {
    if (itemCount < MAX_ITEMS) {
        items[itemCount++] = {itemId, initialDuration};
    } else {
        cout << "Cannot add more items. Auction system is full.\n";
    }
}

bool extendAuctionDuration(AuctionItem items[], int itemCount, int itemId, int additionalMinutes) {
    for (int i = 0; i < itemCount; ++i) {
        if (items[i].itemId == itemId) {
            // Check if the auction is ongoing (currentDuration > 0)
            if (items[i].currentDuration > 0) {
                items[i].currentDuration += additionalMinutes;
                cout << "Auction duration for item " << itemId << " extended by "
                     << additionalMinutes << " minutes.\n";
                return true;
            } else {
                cout << "Auction for item " << itemId << " has already ended.\n";
                return false;
            }
        }
    }

    cout << "Item " << itemId << " not found in the auction system.\n";
    return false;
}

int getRemainingTime(const AuctionItem items[], int itemCount, int itemId) {
    for (int i = 0; i < itemCount; ++i) {
        if (items[i].itemId == itemId) {
            // Calculate remaining time only if the auction is ongoing (currentDuration > 0)
            return (items[i].currentDuration > 0) ? items[i].currentDuration : 0;
        }
    }

    cout << "Item " << itemId << " not found in the auction system.\n";
    return -1; // Return -1 to indicate item not found
}

void displayAuctionStatus(const AuctionItem items[], int itemCount) {
    cout << "Auction Status:\n";
    for (int i = 0; i < itemCount; ++i) {
        cout << "Item " << items[i].itemId << ": Duration - " << items[i].currentDuration << " minutes\n";
    }
}

bool isAuctionExpired(const Auction &auction) {
    time_t currentTime = getCurrentTime();
    if (currentTime > auction.endTime) {
        cout << "The auction has expired.\n";
        cout << endl;
        return true;
    } else {
        cout << "The auction is still ongoing.\n";
        cout << endl;
        return false;
    }
}
