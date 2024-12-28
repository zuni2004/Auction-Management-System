#include <iostream>
#include <ctime>
#include <string>
#include <fstream>
#include "functions.h"
using namespace std;

int main() {
    auto *admin = new Admin;
    auto *authData = new Authentication[MAX_AuthData];
    auto *sellers = new Seller[MAX_SELLERS];
    auto *buyers = new Buyer[MAX_BUYERS];
    auto *item = new Item[MAX_ITEMS];
    auto *bills = new Bill[MAX_BILLS];

    int numAuthData = 0;
    int numSellers = 0;
    int numBuyers = 0;
    int numItems = 0;
    int numBills = 0;

    loadadminCredentials(admin);
    loadAuthenticationsFromFile(authData, numAuthData);
    loadSellersFromFile(sellers, numSellers);
    loadBuyersFromFile(buyers, numBuyers);
    loadItemsFromFile(item, numItems);
    loadBillsFromFile(bills, numBills);

    if (admin->name.empty() && admin->username.empty() && admin->password.empty()) {
        admin->name = "Administrator";
        admin->username = "Admin";
        admin->password = "Admin@786";
    }

    int ch, opt1, triesN = 0;
    char opt = 'N', ch1 = 'N';

    cout << "\tWelcome to the Auction Bidding Program.\n";
    do {
        cout << "Please Choose Any one of Given 3 Choices Which Best Describes You.\n"
             << "1 - Admin\n"
             << "2 - Seller\n"
             << "3 - Buyer\n"
             << "4 - Exit Program\n"
             << "Enter Your Choice : ";
        cin >> ch;
        switch (ch) {
            case 1: {
                string name, username, password;
                cout << "\tHello Respected Admin !\n";
                do {
                    cout << "\tWelcome to the Login Page For Admin !\n"
                         << "Choose Any one of the Following to Proceed.\n"
                         << "1 - Login\n"
                         << "2 - Change Password\n"
                         << "3 - Return to Main\n"
                         << "Enter Your Choice : ";
                    cin >> opt1;
                    switch (opt1) {
                        case 1: {
                            triesN = 0;
                            cout << "Redirecting to the Account Authentication System.\n"
                                 << "Kindly Provide Your Name, Username and Password to Verify Its You.\n";
                            do {
                                cout << "Name : ";
                                cin >> name;
                                cout << "Username : ";
                                cin >> username;
                                cout << "Password : ";
                                cin >> password;

                                if (authenticateAdmin(name, username, password, admin)) {
                                    cout << "\tAdmin Authenticated\nRedirecting to Admin Menu...\n";
                                    ch1 = 'N';
                                    triesN = 4;
                                } else {
                                    cout << "\tIncorrect Credentials ! Kindly Try Again\n";
                                    triesN++;
                                    if (triesN > 3) {
                                        cout << "\tSorry ! You Could Not Verify Your Identity.\nKindly Try Again Later.\n";
                                    }
                                }
                            } while (triesN <= 3);
                            break;
                        }
                        case 2: {
                            triesN = 0;
                            cout << "Redirecting to the Account Credential Changing Program.\n"
                                 << "Kindly Provide Your Previous Name, Username and Password to Verify Its You.\n";
                            do {
                                cout << "Name : ";
                                cin >> name;
                                cout << "Username : ";
                                cin >> username;
                                cout << "Password : ";
                                cin >> password;

                                if (authenticateAdmin(name, username, password, admin)) {
                                    cout << "\tAdmin Authenticated\n";
                                    cout << "Now Give the New Password.\n";
                                    cout << "Password : ";
                                    cin >> password;
                                    admin->password = password;
                                    saveAdminCredentialsToFile(admin);
                                    cout << "\tPassword Changed Successfully !\n\tYou Can Login Now.\n";
                                    ch1 = 'Y';
                                    triesN = 4;
                                } else {
                                    cout << "\tIncorrect Credentials ! Kindly Try Again.\n";
                                    triesN++;
                                    if (triesN > 3) {
                                        cout << "\tSorry ! You Could Not Verify Your Identity.\nKindly Try Again Later.\n";
                                    }
                                }
                            } while (triesN <= 3);
                            break;
                        }
                        case 3: {
                            ch1 = 'Y';
                            break;
                        }
                        default: {
                            cout << "Invalid Input ! Check Again.\n";
                            break;
                        }
                    }
                } while (opt1 != 3 || ch1 != 'Y');
                cout << "Do You Want to Go Back to Main (Y or N) : ";
                cin >> opt;
                if (opt >= 'a' && opt <= 'z') {
                    opt -= ('a' - 'A');
                    if (opt == 'N') {
                        ch = 4;
                    }
                }
                break;
            }
            case 2: {
                int id, authID;
                string username, password;
                cout << "\tHello Respected Seller !\n";
                do {
                    cout << "\tWelcome to the Login Page For Seller !\n"
                         << "Choose Any one of the Following to Proceed.\n"
                         << "1 - Login\n"
                         << "2 - Create an Account\n"
                         << "3 - Change Login Credentials of Your Account\n"
                         << "4 - Return to Main\n"
                         << "Enter Your Choice : ";
                    cin >> opt1;
                    switch (opt1) {
                        case 1: {
                            triesN = 0;
                            cout << "Redirecting to the Account Authentication System.\n"
                                 << "Kindly Provide Your ID, Username and Password to Verify Its You.\n";
                            do {
                                cout << "Your Unique ID : ";
                                cin >> id;
                                cout << "Your Authentication ID : ";
                                cin >> authID;
                                cout << "Username : ";
                                cin >> username;
                                cout << "Password : ";
                                cin >> password;
                                if (authenticateUser(authData, numAuthData, authID, id, username, password)) {
                                    cout << "\tSeller Authenticated\nRedirecting to Seller Menu...\n";
                                    ch1 = 'N';
                                    triesN = 4;
                                } else {
                                    cout << "\tIncorrect Credentials ! Kindly Try Again\n";
                                    triesN++;
                                    if (triesN > 3) {
                                        cout << "\tSorry ! You Could Not Verify Your Identity.\nKindly Try Again Later.\n";
                                    }
                                }
                            } while (triesN <= 3);
                            break;
                        }
                        case 2: {
                            cout << "Redirecting to the Account Creation Program.\n";
                            registerSeller(sellers, numSellers, authData, numAuthData);
                            cout << "You can Now Login.\n";
                            break;
                        }
                        case 3: {
                            triesN = 0;
                            cout << "Redirecting to the Account Credential Changing Program.\n"
                                 << "Kindly Provide Your ID , Username and Password to Verify Its You.\n";
                            do {
                                cout << "Your Unique ID : ";
                                cin >> id;
                                cout << "Your Authentication ID : ";
                                cin >> authID;
                                cout << "Username : ";
                                cin >> username;
                                cout << "Password : ";
                                cin >> password;

                                if (authenticateUser(authData, numAuthData, authID, id, username, password)) {
                                    cout << "\tSeller Authenticated\n";
                                    cout << "Now Give the New Username & Password.\n";
                                    cout << "Username : ";
                                    cin >> username;
                                    cout << "Password : ";
                                    cin >> password;

                                    changeCredentials(authData, numAuthData, authID, id, username, password);
                                    cout << "\tCredentials Changed Successfully !\n\tYou Can Login Now.\n";
                                    ch1 = 'Y';
                                    triesN = 4;
                                } else {
                                    cout << "\tIncorrect Credentials ! Kindly Try Again.\n";
                                    triesN++;
                                    if (triesN > 3) {
                                        cout << "\tSorry ! You Could Not Verify Your Identity.\nKindly Try Again Later.\n";
                                    }
                                }
                            } while (triesN <= 3);
                            int choice;
                            string auctionName;
                            float startingPrice;
                            int auctionDuration;
                            int bidAuctionId, bidBuyerId;
                            float bidAmount;
                            int endAuctionId;
                            int terminateAuctionId;

                            while (true) {
                                cout << "----------------------------------------Welcome to the Auction Management System----------------------------------------" << endl;
                                cout << "1. Create a new auction" << endl;
                                cout << "2. Place a bid" << endl;
                                cout << "3. End an auction" << endl;
                                cout << "4. Display won bids" << endl;
                                cout << "5. Display expired bids" << endl;
                                cout << "6. Terminate an auction" << endl;
                                cout << "7. Exit" << endl;
                                cout << "----------------------------------------Enter your choice: ----------------------------------------";
                                cin >> choice;

                                switch (choice) {
                                    case 1: {
                                        cout << "Enter auction name: ";
                                        cin >> auctionName;

                                        cout << "Enter starting price: ";
                                        cin >> startingPrice;

                                        cout << "Enter auction duration (in days): ";
                                        cin >> auctionDuration;

                                        createAuction(auctionName, startingPrice, auctionDuration);
                                        break;
                                    }

                                    case 2: {
                                        cout << "Enter auction ID: ";
                                        cin >> bidAuctionId;

                                        cout << "Enter your buyer ID: ";
                                        cin >> bidBuyerId;

                                        cout << "Enter your bid amount: ";
                                        cin >> bidAmount;

                                        placeBid(bidAuctionId, bidBuyerId, bidAmount);
                                        break;
                                    }

                                    case 3: {
                                        cout << "Enter auction ID: ";
                                        cin >> endAuctionId;

                                        endAuction(endAuctionId);
                                        break;
                                    }

                                    case 4:
                                        displayWonBids();
                                        break;

                                    case 5:
                                        displayExpiredBids();
                                        break;

                                    case 6: {
                                        cout << "Enter auction ID: ";
                                        cin >> terminateAuctionId;

                                        terminateAuction(terminateAuctionId);
                                        break;
                                    }

                                    case 7:
                                        cout << "Exiting the Auction Management System..." << endl;
                                        return 0;

                                    default:
                                        cout << "Invalid choice. Please enter a number between 1 and 7." << endl;
                                        break;
                                }
                            }
                            break;
                        }
                        case 4: {
                            ch1 = 'Y';
                            break;
                        }
                        default: {
                            cout << "Invalid Input ! Check Again.\n";
                            break;
                        }
                    }
                } while (opt1 != 4 || ch1 != 'Y');
                cout << "Do You Want to Go Back to Main (Y or N) : ";
                cin >> opt;
                if (opt >= 'a' && opt <= 'z') {
                    opt -= ('a' - 'A');
                    if (opt == 'N') {
                        ch = 4;
                    }
                }
                break;
            }
            case 3: {
                int id, authID;
                string username, password;
                cout << "\tHello Respected Buyer !\n";
                do {
                    cout << "\tWelcome to the Login Page For Buyer !\n"
                         << "Choose Any one of the Following to Proceed.\n"
                         << "1 - Login\n"
                         << "2 - Create an Account\n"
                         << "3 - Change Login Credentials of Your Account\n"
                         << "4 - Return to Main\n"
                         << "Enter Your Choice : ";
                    cin >> opt1;
                    switch (opt1) {
                        case 1: {
                            triesN = 0;
                            cout << "Redirecting to the Account Authentication System.\n"
                                 << "Kindly Provide Your ID , Username and Password to Verify Its You.\n";
                            do {
                                cout << "Your Unique ID : ";
                                cin >> id;
                                cout << "Your Authentication ID : ";
                                cin >> authID;
                                cout << "Username : ";
                                cin >> username;
                                cout << "Password : ";
                                cin >> password;

                                if (authenticateUser(authData, numAuthData, authID, id, username, password)) {
                                    cout << "\tBuyer Authenticated\nRedirecting to Buyer Related Menu to check 3 functionalities...\n";
                                    buyerMenuForBills(sellers,numSellers,buyers,numBuyers,bills,numBills,item,numItems);
                                    ch1 = 'N';
                                    triesN = 4;
                                } else {
                                    cout << "\tIncorrect Credentials ! Kindly Try Again\n";
                                    triesN++;
                                    if (triesN > 3) {
                                        cout << "\tSorry ! You Could Not Verify Your Identity.\nKindly Try Again Later.\n";
                                    }
                                }
                            } while (triesN <= 3);
                            break;
                        }
                        case 2: {
                            cout << "Redirecting to the Account Creation Program.\n";
                            registerBuyer(buyers, numBuyers, authData, numAuthData);
                            cout << "You can Now Login.\n";
                            break;
                        }
                        case 3: {
                            triesN = 0;
                            cout << "Redirecting to the Account Credential Changing Program.\n"
                                 << "Kindly Provide Your ID , Username and Password to Verify Its You.\n";
                            do {
                                cout << "Your Unique ID : ";
                                cin >> id;
                                cout << "Your Authentication ID : ";
                                cin >> authID;
                                cout << "Username : ";
                                cin >> username;
                                cout << "Password : ";
                                cin >> password;

                                if (authenticateUser(authData, numAuthData, authID, id, username, password)) {
                                    cout << "\tBuyer Authenticated\n";
                                    cout << "Now Give the New Username & Password.\n";
                                    cout << "Username : ";
                                    cin >> username;
                                    cout << "Password : ";
                                    cin >> password;

                                    changeCredentials(authData, numAuthData, authID, id, username, password);
                                    cout << "\tCredentials Changed Successfully !\n\tYou Can Login Now.\n";
                                    ch1 = 'Y';
                                    triesN = 4;
                                } else {
                                    cout << "\tIncorrect Credentials ! Kindly Try Again.\n";
                                    triesN++;
                                    if (triesN > 3) {
                                        cout << "\tSorry ! You Could Not Verify Your Identity.\nKindly Try Again Later.\n";
                                    }
                                }
                            } while (triesN <= 3);
                            break;
                        }
                        case 4: {
                            ch1 = 'Y';
                            break;
                        }
                        default: {
                            cout << "Invalid Input ! Check Again.\n";
                            break;
                        }
                    }
                } while (opt1 != 4 || ch1 != 'Y');
                cout << "Do You Want to Go Back to Main (Y or N) : ";
                cin >> opt;
                if (opt >= 'a' && opt <= 'z') {
                    opt -= ('a' - 'A');
                    if (opt == 'N') {
                        ch = 4;
                    }
                }
                break;
            }
            case 4: {
                ch = 4;
                opt = 'N';
                break;
            }
            default: {
                cout << "Invalid Choice ! Please Try Again.\n";
                break;
            }
        }
    } while (ch != 4 || opt != 'N');
    cout << "\n\tProgram is Closing ! Please Wait !\n";
    saveAdminCredentialsToFile(admin);
    saveAuthenticationToFile(authData, numAuthData);
    saveSellersToFile(sellers, numSellers);
    saveBuyersToFile(buyers, numBuyers);
    saveItemsToFile(item, numItems);
    saveBillsToFile(bills, numBills);
    cout << "\tThank-You for Using this Program\n"
         << "\tKindly Take a Visit Again\n";

    delete admin;
    delete[] authData;
    delete[] sellers;
    delete[] buyers;
    delete[] item;
    delete[] bills;

    return 0;
}