#include "project.h"
void Products::OrderStatusView()
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
                        if (token.rfind("OrderID ", 0) == 0)
                        {
                                cout << "OrderID :" << token.substr(8);
                        }
                        if (token.rfind("ProductID ", 0) == 0)
                        {
                                cout << " | ProductID :" << token.substr(10);
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
                                cout << " | Count :" << token.substr(5);
                        }
                        if (token.rfind("Status ", 0) == 0)
                        {
                                cout << " | Status :" << token.substr(7) << endl;
                        }
                        line2.erase(0, pos + delimiter.length());
                }
        }
}

///////////////////////////////////////////////////////////////////////////
int Products::idGeneration()
{
        int productId;
        srand(time(0));
        productId = rand() % 100 + 1;
        return productId;
}
void Products::addProducts()
{
        std::string line;
        std::string productChoice;
        std::fstream writeData;
        writeData.open("products.txt", std::ios::in | std::ios::out);

        std ::cout << "<---------------------- ADD PRODUCTS----------------------->" << std ::endl;

        productId = idGeneration();

        std ::cout << "\nEnter the Product Name : ";
        std ::getline(std::cin >> std::ws, productName);

choice:
        std ::cout << "\nEnter the Type of the Product \n1.Electronics\n2.Furniture\n3.Fashion\nEnter choice :";
        // std ::cin >> productChoice;
        getline(cin>>ws,productChoice);
        std::regex l("^[1-3]$");
        if (!(regex_match(productChoice, l)))
            {
                cout << "Invalid Choice .....Please try again\n";
                goto choice;
            }
        switch(stoi(productChoice))
        {
        case 1:
                productType = "Electronics";
                break;
        
        case 2:
                productType = "Furniture";
                break;
        
        case 3:
                productType = "Fashion";
                break;
        default:
                std::cout << "Wrong choice....Enter Again!!";
                goto choice;
                break;
        }
b:
        std ::cout << "\nEnter the Price of the Product : ";
        std::getline(std::cin >> std::ws, productPrice);
        std::regex q("^[1-9]+[0-9]*$");
        if (std::regex_match(productPrice, q))
        {
        }
        else
        {
                std::cout << "Invalid data...! Please Try Again.." << std::endl;
                std::cout << "\n";
                goto b;
        }
Type:
        std ::cout << "\nThe number of available " << productType << " Products : ";
        std ::getline(std::cin >> std::ws, productCount);
        std::regex i("^[1-9]+[0-9]*$");
        if (std::regex_match(productCount, i))
        {
        }
        else
        {
                std::cout << "Invalid data...! Please Try Again.." << std::endl;
                std::cout << "\n";
                goto Type;
        }
        std::fstream merchantFile;
        merchantFile.open("products.txt", std::ios::in | std::ios::out | std::ios::app);
        merchantFile << "ProductID " << idGeneration() << ";Name " << productName << ";Price " << productPrice << ";Type " << productType << ";Count " << productCount << ";" << std::endl;
        std::cout << "\n";

        writeData.close();
        merchantFile.close();

        std::cout << "<----------------------- PRODUCT ADDED SUCCESFULLY---------------------------->";
        cout << "\nWould you like to continue?(Y/N) ";
        std::string choice;
        getline(std::cin >> std::ws, choice);
        if (choice == "Y" || choice == "y")
        {
                system("clear");
                addProducts();
        }
        // else
        // {
        //         // merchantOptions();
                
        // }
}
void Products::merchantOptions()
{

        std::cout << "*******************        MENU        ********************************\n\n";
        std::cout << "1.Add Products\n";
        std::cout << "2.Search Products\n";
        std::cout << "3.Orders List\n";
        std::cout << "4.Products Out Of Stock\n";
        std::cout << "5.Cancelled Products\n";
        std::cout << "6.Assign Delivery to Courier\n";
        std::cout << "7.Exit\n";
}

void Products::displayOutofStock()
{
        std::cout << "*******************      Out of Stock Products      ********************************\n\n";

        std::string line, name, ProductID, outCount, ProductType;
        // int CountVal;
        bool found = false;
        std::ifstream file;
        file.open("products.txt", std::ios::in);
        std::string delimiter = ";";
        while (std::getline(file, line))
        {
                size_t pos = 0;
                std::string token;
                while ((pos = line.find(delimiter)) != std::string::npos)
                {
                        token = line.substr(0, pos);
                        if (token.rfind("ProductID ", 0) == 0)
                        {
                                ProductID = token.substr(10);
                        }
                        if (token.rfind("Name ", 0) == 0)
                        {
                                name = token.substr(5);
                        }
                        if (token.rfind("Type ", 0) == 0)
                        {
                                ProductType = token.substr(5);
                        }
                        if (token.rfind("Count ", 0) == 0)
                        {
                                outCount = token.substr(6); // out of stock count
                                int CountVal = stoi(outCount);
                                if (CountVal <= 5)
                                {
                                        found = true;
                                }
                        }
                        line.erase(0, pos + delimiter.length());
                }
                if (found)
                {
                        std::cout << "Product ID: " << ProductID << " | "
                                  << "Name: " << name << " | "
                                  << "Type: " << ProductType << std::endl;
                        found = false;
                }
        }
        file.close();
}

void Products::AssignCourier()
{
        std::string OrderId, line;
        bool iffound = false;
        int CourierChoice;
        std::string delimiter = ";";
        ifstream courier("orders.txt", ios::in);
        ofstream temp("Temp.txt", ios::out);
        //////////////////////////////////////////////////////////////////////
        cout << "***********************      Orders     ********************************\n";
        std::string line1, defstatus = "Pending", status, Order, Name, Type;
        //     std::string delimiter = ";";
        ifstream view1("orders.txt", ios::in);
        bool st = false;
        int count = 0;
        while (std::getline(view1, line1))
        {
                size_t pos = 0;
                std::string token;
                while ((pos = line1.find(delimiter)) != std::string::npos)
                {
                        token = line1.substr(0, pos);
                        if (token.rfind("OrderID ", 0) == 0)
                        {
                                Order = token.substr(8);
                        }
                        if (token.rfind("Name ", 0) == 0)
                        {
                                Name = token.substr(5);
                        }
                        if (token.rfind("Type ", 0) == 0)
                        {
                                Type = token.substr(5);
                        }
                        if (token.rfind("Status ", 0) == 0)
                        {

                                status = token.substr(7);
                                if (defstatus == status)
                                {
                                        st = true;
                                        count++;
                                }
                        }
                        line1.erase(0, pos + delimiter.length());
                }
                if (st)
                {
                        cout << "Order ID " << Order << "|"
                             << "Name " << Name << "|"
                             << "Type "
                             << Type << "|"
                             << "Status "
                             << status
                             << endl;
                        st = false;
                }
        }
        if (count == 0)
        {
                cout << "No Such Order ID exists......." << endl;
                return;
        }
        cout << "Enter the order ID to be assigned to Courier \n";
        getline(cin >> ws, OrderId);
        cout << "Enter Courier Person to be assigned :\n";
        cout << "1.Kochi\n2.Ernakulam\n";
        cin >> CourierChoice;
        int count1 = 0;
        while (std::getline(courier, line))
        {
                std::string OrderID, ProductID, Name, Type, Count, Status;
                size_t pos = 0;
                std::string token, OriginalLine = line;
                while ((pos = line.find(delimiter)) != std::string::npos)
                {
                        token = line.substr(0, pos);
                        if (token.rfind("OrderID ", 0) == 0)
                        {
                                OrderID = token.substr(8);
                                if (OrderID == OrderId)
                                {
                                        iffound = true;
                                        count1++;
                                }
                        }
                        if (token.rfind("ProductID ", 0) == 0 && iffound)
                        {
                                ProductID = token.substr(9);
                        }
                        if (token.rfind("Name ", 0) == 0 && iffound)
                        {
                                // std::cout << "Name : " << token.substr(5);
                                Name = token.substr(5);
                        }
                        if (token.rfind("Type ", 0) == 0 && iffound)
                        {
                                Type = token.substr(5);
                        }
                        if (token.rfind("Count ", 0) == 0 && iffound)
                        {
                                Count = token.substr(6);
                        }
                        if (token.rfind("Status ", 0) == 0 && iffound)
                        {
                                Status = token.substr(7);
                        }
                        line.erase(0, pos + delimiter.length());
                }

                switch (CourierChoice)
                {
                case 1:
                        if (iffound)
                        {
                                cout << "Updated Successfully......" << endl;
                                temp << "OrderID " << OrderID << ";"
                                     << "ProductID "<< ProductID << ";"
                                     << "Name " << Name << ";"
                                     << "Type " << Type << ";"
                                     << "Count " << Count << ";"
                                     << "Courier "
                                     << "Kochi"
                                     << ";"
                                     << "Status "
                                     << "Shipping"
                                     << ";" << endl;
                                iffound = false;
                                break;
                        }
                        else
                        {
                                temp << OriginalLine << endl;
                        }
                        break;
                case 2:
                        if (iffound)
                        {
                                temp << "OrderID " << OrderID << ";"
                                     << "ProductID "<<ProductID<< ";"
                                     << "Name " << Name << ";"
                                     << "Type " << Type << ";"
                                     << "Count " << Count << ";"
                                     << "Courier "
                                     << "Ernakulam"
                                     << ";"
                                     << "Status "
                                     << "Shipping"
                                     << ";" << endl;
                                iffound = false;
                                break;
                                cout << "Order assigned successfully\n";
                        }
                        else
                        {
                                temp << OriginalLine << endl;
                        }
                        break;
                default:
                        cout << "Not Valid...." << endl;
                }
        }
        if (count1 == 0)
        {
                cout << "No Such Order ID exists......." << endl;
                return;
        }
        courier.close();
        temp.close();
        remove("orders.txt");
        rename("Temp.txt", "orders.txt");
}
void Products::searchProducts()
{
        std::string choice;
        ifstream file("products.txt", ios::in);
        cout << "1.Search By Name\n2.Search By Type\n";
        cout << "Enter choice :";
        getline(cin >> ws, choice);
        if (choice == "1")
        {
                std::string search, line, Name;
                std::cout << "Enter the name of the product" << std::endl;
                getline(std::cin >> std::ws, search);

                std::string Id, name1, price1, Type1, count1;

                std::string delimiter = ";";
                ifstream pName;
                pName.open("products.txt", std::ios::in);
                while (std::getline(pName, line))
                {
                        bool found = false;
                        size_t pos = 0;
                        std::string token;
                        while ((pos = line.find(delimiter)) != std::string::npos)
                        {
                                token = line.substr(0, pos);
                                if (token.rfind("ProductID ", 0) == 0)
                                {
                                        Id = token.substr(10);
                                }
                                if (token.rfind("Name ", 0) == 0)
                                {
                                        Name = token.substr(5);
                                        if (search == Name)
                                        {
                                                found = true;
                                        }
                                }
                                if (token.rfind("Price ", 0) == 0)
                                {
                                        price1 = token.substr(6);
                                }
                                if (token.rfind("Type ", 0) == 0)
                                {
                                        Type1 = token.substr(5);
                                }
                                if (token.rfind("Count ", 0) == 0)
                                {
                                        count1 = token.substr(5);
                                }
                                line.erase(0, pos + delimiter.length());
                        }
                        if (found)
                        {
                                std::cout << "ProductID "<< Id << " | "
                                          << "Name " << Name << " | "
                                          << "Price " << price1 << " | "
                                          << "Type " << Type1 << " | "
                                          << "Count " << count1 << std::endl;
                                found = false;
                                break;
                        }
                        else
                        {
                                // continue;
                                cout << "product not found" << endl;
                        }
                }
                pName.close();
        }
        else if (choice == "2")
        {
                std::string pType;
                string choice;
                std::cout << "\n1.Electronics\n2.Furniture\n3.Fashion" << std::endl;
        ch:
                std::cout << "Enter your choice" << std::endl;
                cin >> choice;
                std::regex check("^[1-3]$");
        if (!(regex_match(choice, check)))
            {
                cout << "Invalid Choice .....Please try again\n";
                goto ch;
            }
                switch (stoi(choice))
                {
                case 1:
                        pType = "Electronics";
                        break;

                case 2:
                        pType = "Furniture";
                        break;

                case 3:
                        pType = "Fashion";
                        break;

                default:
                        std::cout << "       ===Not a valid choice !! Please Try Again.......===\n";
                        goto ch;
                }
                std::string line, Type, name, id, count, price;
                bool found = false;
                std::string delimiter = ";";
                ifstream productFile;
                productFile.open("products.txt", ios::in);
                while (std::getline(productFile, line))
                {
                        size_t pos = 0;
                        std::string token;
                        while ((pos = line.find(delimiter)) != std::string::npos)
                        {
                                token = line.substr(0, pos);

                                if (token.rfind("ProductID ", 0) == 0)
                                {
                                        id = token.substr(10);
                                }
                                if (token.rfind("Name ", 0) == 0)
                                {
                                        name = token.substr(5);
                                }
                                if (token.rfind("Price ", 0) == 0)
                                {
                                        price = token.substr(6);
                                }
                                if (token.rfind("Type ", 0) == 0)
                                {
                                        Type = token.substr(5);
                                        if (Type == pType)
                                        {
                                                found = true;
                                        }
                                }
                                if (token.rfind("Count ", 0) == 0)
                                {
                                        count = token.substr(5);
                                }
                                line.erase(0, pos + delimiter.length());
                        }
                        if (found)
                        {
                                std::cout << "Product ID " << id << " | "
                                          << "Name " << name << " | "
                                          << "Price " << price << " | "
                                          << "Type " << Type << " | "
                                          << "Count " << count << std::endl;
                                found = false;
                        }
                        else
                        {
                                continue;
                        }
                }
                productFile.close();
        }
        else
        {
                cout<<"Invalid Choice... Please try again\n";
                cout<<"\n";
                searchProducts();
        }
}

void Products::CancelledProducts()
{
        std::string line, orderId, pId, pName, Price, pType, pCount, pStatus;
        std::string status = "Cancelled";
        bool found = false;
        std::cout << "<--------------------------List of Cancelled Orders----------------------------->" << std::endl;
        std::ifstream orderList;
        orderList.open("orders.txt", std::ios::in);
        std::string delimiter = ";";
        while (std::getline(orderList, line))
        {
                size_t pos = 0;
                std::string token;
                while ((pos = line.find(delimiter)) != std::string::npos)
                {
                        token = line.substr(0, pos);
                        if (token.rfind("OrderID ", 0) == 0)
                        {
                                orderId = token.substr(8);
                        }
                        if (token.rfind("ProductID ", 0) == 0)
                        {
                                pId = token.substr(10);
                        }
                        if (token.rfind("Name ", 0) == 0)
                        {
                                pName = token.substr(5);
                        }
                        if (token.rfind("Type ", 0) == 0)
                        {
                                pType = token.substr(5);
                        }
                        if (token.rfind("Count ", 0) == 0)
                        {
                                pCount = token.substr(6);
                        }
                        if (token.rfind("Status ", 0) == 0)
                        {
                                pStatus = token.substr(7);
                                if (status == pStatus)
                                {
                                        found = true;
                                }
                        }
                        line.erase(0, pos + delimiter.length());
                }
                if (found)
                {

                        std::cout << "OrderID " << orderId << " | "
                                  << "Product ID " << pId << " | "
                                  << "Name " << pName << " | "
                                  << "Type " << pType << " | "
                                  << "Count " << pCount << std::endl;
                        //<< "Status " << status << std::endl;
                        found = false;
                }
                else
                {
                        continue;
                }
        }
        orderList.close();
}
