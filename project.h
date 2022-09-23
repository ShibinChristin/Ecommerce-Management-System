#include <iostream>
#include <istream>
#include <fstream>
#include <cstdlib>
#include <string.h>
#include <cstring>
#include <regex>
using namespace std;

class Authentication
{
    string customerUsername, customerPassword, password_confirm1, pass1, user;
    string merchantUsername, merchantPassword, password_confirm2;
    string courierUsername, courierPassword, password_confirm3;

public:
    size_t pos = 0;
    std::string delimiter = ";";
    int count;
    string line1, line2, line3;
    void customerLogin();
    void customerRegistration();
    void merchantLogin();
    void merchantRegistration();
    void courierLogin();
    void courierRegistration();
    int idGeneration();
    void mainMenu();
};
class Customer
{
    std::string line1, name, price;
    std::string delimiter = ";";
    std::string token;
    std::string id, customer_id;
    std::string merchant_id, merId;
    int cusId;

public:
    int customerChoice;
    std::string line;
    int ProductBuy;
    void customerBuy();
    void customerChoiceDisplay();
    void showProducts();
    void orderStatus();
    void cancelOrder();
    int idGenerate();
    void customerMenu();
};

class Merchant
{
public:
    std::string merchantId, productId;
    std::string productName, productPrice;
    std::string productType, productCount; //,MerchantChoice;
    int productChoice, MerchantChoice;
    void addProducts();
    void merchantOptions();
    void searchProducts();
    void displayOutOfStock();
    void assignCourier();
    void cancelledProducts();
    void orderStatusView();
    int idGeneration();
    void merchantMenu();
    void addOutofStock();
};

class Courier
{
public:
    void listOfOrders();
    void courierOptions();
    void statusUpdate();
    void pendingAndDelivered();
    void courierMenu();
};