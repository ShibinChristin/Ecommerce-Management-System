#include "project.h"
ifstream customer("products.txt", ios::in);

void Customer::CustomerChoiceDisplay()
{
    // ostream customerb("temp.txt");
    // std::cout<<"What would you like to buy\n";
    ///////////////////////////////////////////////////
    // ifstream customer("products.txt", ios::in);
    cout << "***********************       MENU        ********************************\n\n";
    cout << "1.Buy Product\n";
    cout << "2.Show Product\n";
    cout << "3.Order Status\n";
    cout << "3.Cancel Order\n"
         << endl;
}
void Customer::showProducts()
{
    // ifstream customer("products.txt", ios::in);
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
                     << "Price : " << token.substr(6);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                cout << " |"
                     << "Type : " << token.substr(5) << endl;
            }
            line1.erase(0, pos + delimiter.length());
        }
    }
    in.close();
}
void Customer::CustomerBuy()
{
    ifstream customer1("products.txt", ios::in);
    std::regex obj("^[0-5]$");
    std::string Cproduct, line2, delimiter = ";", name, ProductID, count, ProductType; /// cProduct   --- Customer Product
    bool found = false;
    ofstream buy("orders.txt", ios::out | ios::app);
    showProducts();
    cout << endl;
    cout << "Enter the product name you want to buy :";
    getline(std::cin >> std::ws, Cproduct);
    while (std::getline(customer1, line2))
    {
        size_t pos = 0;
        std::string token;
        while ((pos = line2.find(delimiter)) != std::string::npos)
        {
            token = line2.substr(0, pos);
            if (token.rfind("Name ", 0) == 0)
            {
                name = token.substr(5);
                // }
                if (Cproduct == name)
                {
                    found = true;
                }
            }
            if (token.rfind("ProductID ", 0) == 0)
            {
                ProductID = token.substr(10);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                ProductType = token.substr(4);
            }
            line2.erase(0, pos + delimiter.length());
        }
    }
buy:
    cout << "How many would you like to buy? ";
    cin >> count;
    if (!(regex_match(count, obj)))
    {
        cout << "Invalid input or you cannot buy more than 5 products " << endl;
        goto buy;
    }

    if (!found)
    {
        cout << "Product not found " << endl;
    }
    else
    {
        buy << "ProductID " << ProductID << ";"
            << "Name " << name << ";"
            << "Type " << ProductType << ";"
            << "Count " << count << ";" << endl;
    }
    ofstream temp("temp.txt", ios::out | ios::app);
    ifstream in1("products.txt", ios::in);
    bool idfound = false;
    while (std::getline(in1, line))
    {
        std::string delimiter = ";", Val;
        int tempCount;
        size_t pos = 0;
        idfound = false;
        std::string originalLine = line;
        std::string token;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            if (token.rfind("Count ", 0) == 0)
            {
                Val = token.substr(5);
                // tempCount = stoi(Val);
            }
            if (token.rfind("Name ", 0) == 0)
            {
                std::string name = token.substr(4);

                if (Cproduct == name)
                {
                    idfound = true;
                    temp << "ProductID " << ProductID;
                    temp << ";Name " << name;
                    temp << ";Count " << stoi(Val) - stoi(count);
                }
            }
            line.erase(0, pos + delimiter.length());
        }
        if (!idfound)
        {
            temp << line << "\n";
        }
    }
    temp.close();
    in1.close();
    // .close();
    // remove("products.txt");
    // rename("temp.txt", "products.txt");
}
// void Customer::orderStatus(){
// ofstream out("status.txt",ios::out|ios::app);
// ifstream in("orders.txt",ios::in);

// }

// void Customer::orderStatus(){
//     std::string line1, name, price;
//     std::string delimiter = ";";
//     ifstream in("orders.txt", ios::in);
//     ofstream out("OrderStatus.txt",ios::out|ios::app);
//     while (std::getline(in, line1))
//     {
//         size_t pos = 0;
//         std::string token;
//         while ((pos = line1.find(delimiter)) != std::string::npos)
//         {
//             token = line1.substr(0, pos);
//             if (token.rfind("Name ", 0) == 0)
//             {
//                 std::cout << "Name : " << token.substr(5);
//             }
//             if (token.rfind("Price ", 0) == 0)
//             {
//                 cout << " |"
//                      << "Price : " << token.substr(6) ;
//             }
//              if (token.rfind("Type ", 0) == 0)
//             {
//                 cout << " |"
//                      << "Type : " << token.substr(5) << endl;
//             }
//             line1.erase(0, pos + delimiter.length());
//         }
//     }
//     in.close();
// }
void Customer::orderStatus()
{
    std::string line1, name, price;
    std::string delimiter = ";";
    ifstream in("orders.txt", ios::in);
    ofstream out("OrderStatus.txt", ios::out | ios::app);
    while (std::getline(in, line1))
    {
        std::string ProductS, nameS, PriceS, TypeS;
        size_t pos = 0;
        std::string token;
        while ((pos = line1.find(delimiter)) != std::string::npos)
        {
            token = line1.substr(0, pos);
            if (token.rfind("ProductID ", 0) == 0)
            {
                // std::cout << "ProductID : " << token.substr(9);
                ProductS = token.substr(9);
            }
            if (token.rfind("Name ", 0) == 0)
            {
                // std::cout << "Name : " << token.substr(5);
                nameS = token.substr(5);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                // cout << " |"
                //      << "Type : " << token.substr(5) << endl;
                TypeS = token.substr(5);
            }
            line1.erase(0, pos + delimiter.length());
        }
        out << "ProductID " << ProductS << ";"
            << "Name " << nameS << ";"
            << "Type "
            << TypeS << ";"
            << "Status "
            << " Pending"
            << ";" << endl;
    }
    in.close();
    out.close();
}