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
    string username1 ,password1,password_confirm1 , pass1 ,user;
public:
int count1 , count2,count3;
string line1 , line2 , line3; 
    void CustomerLogin();
    void CustomerRegistration();
    void MerchantLogin();
    void MerchantRegistration();
    void CourierLogin();
    void CourierRegistration();
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
    void addProducts();
    void merchantOptions();
    void displayProducts();
    void searchProducts();
    // void MerchantCondition(std::string sub);
    void OrderStatusView();
    void displayOutofStock();
    void AssignCourier();
    void CancelledProducts();
    int idGeneration();
};

class Courier
{
public:
void listOfOrders();
void courierOptions();
void StatusUpdate();
void PendingAndDelivered();
};