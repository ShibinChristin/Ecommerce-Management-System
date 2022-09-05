#include <iostream>
#include <istream>
#include <fstream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <regex>
using namespace std;
class Authentication
{
public:
    int choice;
    void HomePage();
    void CustomerLogin();
    void CustomerRegistration();
    void forgotPassword();
    void MerchantRegistration();
    void MerchantLogin();
    void CourierLogin();
    void Validate(string user);
};
class Customer
{
public:
    int customerChoice;
    std::string line;
    int ProductBuy;
    string subString; // added on 31/august/2022
    void CustomerBuy();
    void CustomerChoiceDisplay();
    void showProducts();
    void orderStatus();
};

class Products
{
public:
    std::string merchantId, productId;
    std::string productName, productPrice;
    std::string productType, productCount; //,MerchantChoice;
    int productChoice, MerchantChoice;
    void addProduct();
    void searchProducts();
    void merchantOptions();
    void OutofStockProducts();
    void cancelledOrders();
    void displayProducts();
    void MerchantCondition(std::string sub);
    void orderStatus();
};

class Courier{
public:
void AddCourier();
};