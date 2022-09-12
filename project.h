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
    void CustomerLogin();
    void CustomerRegistration();
    void forgotPassword();
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
    void CancelOrder();
    int idGenerate();
};

class Products
{
public:
    std::string merchantId, productId;
    std::string productName, productPrice;
    std::string productType, productCount; //,MerchantChoice;
    int productChoice, MerchantChoice;
    void addProduct();
    void merchantOptions();
    void displayProducts();
    void searchProducts();
    void MerchantCondition(std::string sub);
    void OrderStatusView();
    void displayOutofStock();
    void AssignCourier();
};

class Courier{
public:
void listOfOrders();
void StatusUpdate();
};