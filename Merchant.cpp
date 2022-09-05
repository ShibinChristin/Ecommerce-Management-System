#include "project.h"
void Products::addProduct()
{
        // std ::cout << "Enter the Merchant ID : ";
        // getline(std::cin >> ws, merchantId);
        std ::cout << "\nEnter the Product ID : ";
        getline(std::cin >> ws, productId);
        std ::cout << "\nEnter the Name of the Product : ";
        getline(std::cin >> ws, productName);
        std ::cout << "\nEnter the Price of the Product : ";
        getline(std::cin >> ws, productPrice);
choice:
        std ::cout << "\nEnter the Type of the Product \n1.Electronics\n2.Furniture\n3.Clothings : ";
        cin >> productChoice;
        if (productChoice == 1)
        {
                productType = "Electronics";
        }
        else if (productChoice == 2)
        {
                productType = "Furniture";
        }
        else if (productChoice == 3)
        {
                productType = "Fashion";
        }
        else
        {
                cout << "Wrong choice....Enter Again!!";
                goto choice;
        }
        std ::cout << "\nThe number of available " << productType << " Products: ";
        getline(std::cin >> ws, productCount);
        fstream merchant_file;
        merchant_file.open("products.txt", std::ios::out | std::ios::app);
        merchant_file //<< "MerchantID " << merchantId << ";"
            << "ProductID " << productId << ";"
            << "Name " << productName << ";"
            << "Price " << productPrice << ";"
            << "Type " << productType << ";"
            << "Count " << productCount << ";" << endl;
        cout << "\n";
        merchant_file.close();
        cout << "Would you like to continue?(Y/N) ";
        std::string choice;
        getline(std::cin >> std::ws, choice);
        if (choice == "Y" || choice == "y")
        {
                addProduct();
        }
        else
        {
                merchantOptions();
        }
}
void Products::searchProducts()
{
    std::string search, str;
    std::string line;
    std::ifstream file;
    bool found = false;
    file.open("products.txt", std::ios::in);
    std::cout<<"Search for item: ";
    std::cin >> search;
    std::cout<< "Search results : \n";
    file >> str;
        file.seekg(16, std::ios::beg);
        while(!file.eof() && getline(file,line))
        {
            if ((line.find(search)) != std::string::npos)  
            {
                found = true;
                std::cout << line << std::endl;  
            }  
        }
        if(found == false)
        {
            std::cout <<"Search not found...!!!" << std::endl;
        }          
    file.close();
}

void Products::OutofStockProducts()
{
        
}

void Products::merchantOptions()
{
        cout << "*******************        MENU        ********************************\n\n";
        cout << "1.Add Products\n";
        cout << "2.Search Products\n";
        cout << "3.List of out of stock products\n";
        cout << "4.Canceled Orders\n";
        cout << "5.Order Status\n";
        cout << "6.Go Back\n";
            
}
ifstream MerchantDisplay("products.txt");

void Products::displayProducts()
{
        std::string subString;
        std::cout << "1.Electronics\n";
        std::cout << "2.Furniture\n";
        std::cout << "3.Clothings\n";
        std::cout << "Enter your choice : ";
        std::cin >> MerchantChoice;
        switch (MerchantChoice)
        {
        case 1:
                subString = "Electronics";
                MerchantCondition(subString);
                break;

        case 2:
                subString = "Furniture";
                MerchantCondition(subString);

                break;
        case 3:
                subString = "Clothes";
                MerchantCondition(subString);
                break;
        }
}
/////////////////////////////////////////////////////////

void Products::MerchantCondition(std::string Sub)
{
        std::string line1;
        ifstream MerchantDisplay("products.txt");
        do
        {
                if (line1.find(Sub) != std::string::npos)
                        // cout<<line<<"\n";
                        cout << line1 << endl;
        } while (getline(MerchantDisplay, line1));

        // std::string line1, name, price, Type, Count;
        // std::string delimiter = ";";
        // ifstream in("products.txt", ios::in);
        // bool found = false;
        // while (std::getline(in, line1))
        // {
        //         size_t pos = 0;
        //         std::string token;
        //         while ((pos = line1.find(delimiter)) != std::string::npos)
        //         {
        //                 token = line1.substr(0, pos);
        //                 if (token.rfind("Name ", 0) == 0)
        //                 {
        //                         /*std::cout << "Name : " << */ name = token.substr(5);
        //                 }
        //                 if (token.rfind("Price ", 0) == 0)
        //                 {
        //                         /* cout << " |"
        //                               << "Price : " << */
        //                         price = token.substr(6);
        //                 }
        //                 if (token.rfind("Type ", 0) == 0)
        //                 {
        //                         /*  cout << " |"
        //                                << "Price : " << */
        //                         Type = token.substr(5);
        //                         if (Type == Sub)
        //                         {
        //                                 found = true;
        //                         }
        //                 }
        //                 if (token.rfind("Count ", 0) == 0)
        //                 {
        //                         /*  cout << " |"
        //                                << "Count : " << */
        //                         Count = token.substr(6); //<< endl;
        //                 }
        //                 line1.erase(0, pos + delimiter.length());
        //         }
        //         if (found == true)
        //         {
        //                 cout << "Name : " << name << "|"
        //                      << "Price : " << price << "|"
        //                      << "Type : " << Type << "|"
        //                      << "Count :" << Count << endl;
        //         }
        // }
        // in.close();
}

void Products::orderStatus()
{

        ifstream customer1("orders.txt", ios::in);
        std::string Cproduct, line2, delimiter = ";"; /// cProduct   --- Customer Product
        cout << "***********************************************************************\n\n";
        cout << "                      Order Status                             \n\n";
        cout << "***********************************************************************\n\n";

        while (std::getline(customer1, line2))
        {
                size_t pos = 0;
                std::string token;
                while ((pos = line2.find(delimiter)) != std::string::npos)
                {
                        token = line2.substr(0, pos);
                        if (token.rfind("ProductID ", 0) == 0)
                        {
                                cout << "ProductID :" << token.substr(10);
                        }
                        if (token.rfind("Name ", 0) == 0)
                        {
                                cout << " | Name :" << token.substr(5);
                        }
                        if (token.rfind("Type ", 0) == 0)
                        {
                                cout << " | Type :" << token.substr(4);
                        }
                        if (token.rfind("Count ", 0) == 0)
                        {
                                cout << " | Count :" << token.substr(5) << endl;
                        }
                        line2.erase(0, pos + delimiter.length());
                }
        }
}