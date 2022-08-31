#include<iostream>
#include<istream>
#include<fstream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class Authentication{
    public:
void CustomerLogin();
void CustomerRegistration();
void forgotPassword();
void MerchantLogin();
void CourierLogin();
};
class Customer{   
    public:
int customerChoice;
std::string line; 
int  ProductBuy;  
string subString; //added on 31/august/2022
void CustomerBuy();
void CustomerCondition();
void CustomerChoiceDisplay();
};

