#include "project.h"
ifstream customer("products.txt", ios::in);
void Customer::CustomerChoiceDisplay()
{
    // ostream customerb("temp.txt");
    // std::cout<<"What would you like to buy\n";
    ///////////////////////////////////////////////////
    cout << "***********************       MENU        ********************************\n\n";
    cout << "1.Buy Product\n";
    cout << "2.Show Product\n";
    cout << "3.Order Status\n";
    cout << "3.Cancel Order\n"
         << endl;
}
void Customer::showProducts()
{
    std::string line1, name, price;
    std::string delimiter = ";";
    ifstream in("products.txt", ios::in);
    while (std::getline(in, line1))
    {
        size_t pos = 0;
        std::string token;
        while ((pos = line1.find(delimiter)) != std::string::npos)
        {
            token = line1.substr(0, pos);
            if (token.rfind("Name ", 0) == 0)
            {
                std::cout << "Name : " << token.substr(5);
            }
            if (token.rfind("Price ", 0) == 0)
            {
                cout << " |"
                     << "Price : " << token.substr(6) << endl;
            }
            //  if(token.rfind("Count ",0)==0){
            //     cout<<" |"<<"Count : "<<token.substr(5)<<endl;
            // }
            line1.erase(0, pos + delimiter.length());
        }
    }
    in.close();
}
void Customer::CustomerBuy()
{
    std::string Cproduct, line2, delimiter = ";", name, ProductID; /// cProduct   --- Customer Product
    int count;
    bool found = false;
    ofstream buy("orders.txt", ios::out | ios::app);
    showProducts();
    cout << endl;
    cout << "Enter the product name you want to buy :";
    getline(std::cin >> std::ws, Cproduct);
    while (std::getline(customer, line2))
    {
        size_t pos = 0;
        std::string token;
        while ((pos = line2.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            if (token.rfind("Name ", 0) == 0)
            {
                name = token.substr(5);
                found = true;
            }
            if (token.rfind("ProductID ", 0) == 0)
            {
                ProductID = token.substr(9);
            }
        }
        cout << "How many would you like to buy ?";
        cin >> count;
        if (!found)
        {
            cout << "Product not found " << endl;
        }
        else
        {
            buy << "ProductID " << ProductID << ";"
                << "Name " << name << ";"
                << "count " << count << ";" << endl;
        }
    }
}
