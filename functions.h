#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>
using namespace std;


const int MAX_AuthData = 100;
const int MAX_BUYERS = 100;
const int MAX_SELLERS = 100;
const int MAX_ITEMS = 1000;
const int MAX_BILLS = 10000;
const int MAX_ITEMS = 50;
const string ITEMS_FILE = "items.txt";
const string BUYERS_FILE = "buyers.txt";
int itemCount = 0;
Buyer buyers[MAX_ITEMS];


struct AuctionItem {
    string itemName;
    string sellerName;
    double startingPrice;
    bool sold;
    time_t endTime;
};

struct Buyer {
    string buyerName;
    double totalSpent;
    bool firstPurchase;
};

struct Admin {
    string name;
    string username;
    string password;
};

struct Authentication {
    int authID;
    int id;
    string username;
    string password;
};

struct Seller {
    int id;
    string name;
    float budget;
    bool isBlocked;
};

struct Buyer {
    int id;
    string name;
    float budget;
    int chances;
};

struct Item {
    int id;
    string name;
    string description;
    float startingPrice;
    float currentBid;
    int sellerId;
    bool isAuctionActive;
    bool isDelivered;
    int buyerId;
};

struct Bill {
    int id;
    int buyerId;
    int itemId;
    float amount;
};

struct Auction {
    int id;
    int itemId;
    bool isTerminated;
    time_t startTime;
    time_t endTime;
    string name;
    float startingPrice;
    string startTimeString;
    string endTimeString;
    float currentBid;
    string status;
    int buyerId;
};
void loadadminCredentials(Admin *admin);
bool authenticateAdmin(const string &name,const string &username,const string &password, const Admin *admin);
void saveAdminCredentialsToFile(Admin *admin);

bool isStrongPassword(const string &password);
void registerSeller(Seller sellers[], int &numSellers, Authentication authData[], int &numAuthData);
void registerBuyer(Buyer buyers[], int &numBuyers, Authentication authData[], int &numAuthData);

bool authenticateUser(Authentication authData[], int numAuthData, const int &authID, const int &id , const string &username, const string &password);

void loadAuthenticationsFromFile(Authentication authData[], int &numAuthData);
void saveAuthenticationToFile(Authentication authData[], const int &numAuthData);

void changeCredentials(Authentication authData[], int numAuthData,const int &authID, const int &id, const string &newUsername, const string &newPassword);

void loadSellersFromFile(Seller sellers[], int &numSellers);
void loadBuyersFromFile(Buyer buyers[], int &numBuyers);
void loadItemsFromFile(Item item[], int &numItems);
void loadBillsFromFile(Bill bills[], int &numBills);

void saveBuyersToFile(Buyer buyers[], const int &numBuyers);
void saveSellersToFile(Seller sellers[], const int &numSellers);
void saveItemsToFile(Item item[], const int &numItems);
void saveBillsToFile(Bill bills[], const int &numBills);

void processPayment(Buyer *buyers, const int &numBuyers, Item *items, const int &numItems, Seller *sellers, const int &numSellers, Bill *bills, int &numBills, const int &buyerId, const int &itemId, const float &amount);
void generateBillRecursive(Bill bills[], const int &numBills, const int &billId, Item items[], Buyer buyers[], Seller sellers[], int i);
void generateBill(Bill bills[], const int &numBills, const int &billId, Item items[], Buyer buyers[], Seller sellers[]);
void viewTransactions(Item *items, Seller *sellers, Bill *bills, const int &numBills, const int &buyerId);

void createAuction(string auctionName, float startingPrice, int auctionDuration);
Auction getAuctionById(int auctionId);
void placeBid(int auctionId, int buyerId, float bidAmount);
void endAuction(int auctionId);
void displayWonBids();
void displayExpiredBids();
void terminateAuction(int auctionId);

void generateSummary();
void saveData(Bid bids[], Item items[], Auction auctions[],Buyer buyers[], Bill bills[], Delivery deliveries[]);
void loadData(Bid bids[], Item items[], Auction auctions[],Buyer buyers[], Bill bills[], Delivery deliveries[]);
bool isAuctionExpired(const Auction &auction);
void addItem(AuctionItem items[], int &itemCount, int itemId, int initialDuration);
bool extendAuctionDuration(AuctionItem items[], int itemCount, int itemId, int additionalMinutes);
int getRemainingTime(const AuctionItem items[], int itemCount, int itemId);
void displayAuctionStatus(const AuctionItem items[], int itemCount);

#endif // FUNCTIONS_H