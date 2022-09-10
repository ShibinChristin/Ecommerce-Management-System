#include "project.h"
// void Products::addProduct()
// {
//         // std ::cout << "Enter the Merchant ID : ";
//         // getline(std::cin >> ws, merchantId);
//         std ::cout << "\nEnter the Product ID : ";
//         getline(std::cin >> ws, productId);
//         std ::cout << "\nEnter the Name of the Product : ";
//         getline(std::cin >> ws, productName);
//         std ::cout << "\nEnter the Price of the Product : ";
//         getline(std::cin >> ws, productPrice);
// choice:
//         std ::cout << "\nEnter the Type of the Product \n1.Electronics\n2.Furniture\n3.Clothings : ";
//         cin >> productChoice;
//         if (productChoice == 1)
//         {
//                 productType = "Electronics";
//         }
//         else if (productChoice == 2)
//         {
//                 productType = "Furniture";
//         }
//         else if (productChoice == 3)
//         {
//                 productType = "Fashion";
//         }
//         else
//         {
//                 cout << "Wrong choice....Enter Again!!";
//                 goto choice;
//         }
//         std ::cout << "\nThe number of available " << productType << " Products: ";
//         getline(std::cin >> ws, productCount);
//         fstream merchant_file;
//         merchant_file.open("products.txt", std::ios::out | std::ios::app);
//         merchant_file //<< "MerchantID " << merchantId << ";"
//             << "ProductID " << productId << ";"
//             << "Name " << productName << ";"
//             << "Price " << productPrice << ";"
//             << "Type " << productType << ";"
//             << "Count " << productCount << ";" << endl;
//         cout << "\n";
//         merchant_file.close();
//         cout << "Would you like to continue?(Y/N) ";
//         std::string choice;
//         getline(std::cin >> std::ws, choice);
//         if (choice == "Y" || choice == "y")
//         {
//                 addProduct();
//         }
//         else
//         {
//                 merchantOptions();
//         }
// }
// void Products::merchantOptions()
// {
//         cout << "*******************        MENU        ********************************\n\n";
//         cout << "1.Add Products\n";
//         cout << "2.View Products\n";
//         cout << "2.Assign Delivery to Courier\n";
//         cout << "3.Canceled Orders\n";
//         cout << "4.Order Status\n"
//              << endl;
// }
// ifstream MerchantDisplay("products.txt");
// void Products::displayProducts()
// {
//         std::string subString;
//         std::cout << "1.Electronics\n";
//         std::cout << "2.Furniture\n";
//         std::cout << "3.Clothings\n";
//         std::cout << "Enter your choice : ";
//         std::cin >> MerchantChoice;
//         switch (MerchantChoice)
//         {
//         case 1:
//                 subString = "Electronics";
//                 MerchantCondition(subString);
//                 break;

//         case 2:
//                 subString = "Furniture";
//                 MerchantCondition(subString);

//                 break;
//         case 3:
//                 subString = "Clothes";
//                 MerchantCondition(subString);
//                 break;
//         }
// }
// /////////////////////////////////////////////////////////

// void Products::MerchantCondition(std::string Sub)
// {
//         std::string line1;
//         ifstream MerchantDisplay("products.txt");
//         do
//         {
//                 if (line1.find(Sub) != std::string::npos)
//                         // cout<<line<<"\n";
//                         cout << line1 << endl;
//         } while (getline(MerchantDisplay, line1));

// }

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
                                cout << " | Count :" << token.substr(5) << endl;
                        }
                        line2.erase(0, pos + delimiter.length());
                }
        }
}

///////////////////////////////////////////////////////////////////////////

void Products::addProduct()
{

        int productChoice;
        std::string line;
        std::fstream writeData;
        // bool flag=false;
        Products p;
        writeData.open("products.txt", std::ios::in | std::ios::out);

        std ::cout << "<---------------------- ADD PRODUCTS----------------------->" << std ::endl;
name:
        std ::cout << "\nEnter the Name of the Product : ";
        std ::getline(std::cin >> std::ws, productName);
        while (std::getline(writeData, line))
        {
                std::string delimiter = ";";
                size_t pos = 0;
                std::string token;
                while ((pos = line.find(delimiter)) != std::string::npos)
                {
                        token = line.substr(0, pos);
                        if (token.rfind("Name ", 0) == 0)
                        {
                                std::string name = token.substr(5);
                                if (name == productName)
                                {
                                        std::cout << "       ===This Product Name already exists! Please try again.===\n";
                                        goto name;
                                }
                        }
                        line.erase(0, pos + delimiter.length());
                }
        }

begin:
        std ::cout << "\nEnter the Product ID : ";
        std ::getline(std::cin >> std::ws, productId);
        std::regex u("^\\d{2}$"); // 4 digits
        if (std::regex_match(productId, u))
        {
        }
        else
        {
                std::cout << "\n";
                std::cout << "       ===Only 2-digit ID is allowed! Please try again.===\n";
                std::cout << "\n";
                goto begin;
        }
        while (std::getline(writeData, line))
        {
                std::string delimiter = ";";
                size_t pos = 0;
                std::string token;
                while ((pos = line.find(delimiter)) != std::string::npos)
                {
                        token = line.substr(0, pos);
                        if (token.rfind("ProductID", 0) == 0)
                        {
                                std::string id = token.substr(10);
                                if (id == productId)
                                {
                                        std::cout << "       ===This Product ID already exists! Please try again.===\n";
                                        goto begin;
                                }
                        }
                        line.erase(0, pos + delimiter.length());
                }
        }
choice:
        std ::cout << "\nEnter the Type of the Product \n1.Electronics\n2.Furniture\n3.Fashion \n";
        std ::cin >> productChoice;
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
                std::cout << "Wrong choice....Enter Again!!";
                goto choice;
        }
b:
        std ::cout << "\nEnter the Price of the Product : ";
        std ::getline(std::cin >> std::ws, productPrice);
        std::regex q("[^0][0-9]+");
        if (std::regex_match(productPrice, q))
        {
        }
        else
        {
                std::cout << "Invalid data...! Please Try Again.." << std::endl;
                std::cout << "\n";
                goto b;
        }

        std ::cout << "\nThe number of available " << productType << " Products : ";
        std ::getline(std::cin >> std::ws, productCount);
        std::regex i("[0-9]+");
        if (std::regex_match(productCount, i))
        {
        }
        else
        {
                std::cout << "Invalid data...! Please Try Again.." << std::endl;
                std::cout << "\n";
                goto b;
        }

        std::fstream merchantFile;
        merchantFile.open("products.txt", std::ios::in | std::ios::out | std::ios::app);
        //     merchantFile << "Product Name "<< productName <<";" << "ProductId "<< productId << ";"<< "Product Price " << productPrice << ";" << "Product Type " << productType << ";"<< "ProductCount " << productCount << ";" << std::endl;
        merchantFile << "ProductID " << productId << ";Name " << productName << ";Price " << productPrice << ";Type " << productType << ";Count " << productCount<<";"<<endl;

        writeData.close();
        merchantFile.close();
        std::cout << "<----------------------- PRODUCT ADDED SUCCESFULLY---------------------------->";
        std::string conditionChoice;
        std::cout << "\nWould you like to continue(Y/N) :" << std::endl;
        std::cin >> conditionChoice;
        if (conditionChoice == "y" || conditionChoice == "Y")
        {
                std::cout << std::endl;
                p.addProduct();
        }
        else
        {
                p.merchantOptions();
                //     goto continuation;
        }
}
void Products::merchantOptions()
{

        std::cout << "*******************        MENU        ********************************\n\n";
        std::cout << "1.Add Products\n";
        std::cout << "2.Search Products\n";
        std::cout << "3.Orders List\n";

        std::cout << "4.List of Out Of Stock products\n";
        std::cout << "5.Assign Delivery to Courier\n";

        std::cout << "6.Exit\n";
        // cout<<"5.Order Status\n"<<endl;
}
void Products::searchProducts()
{

        std::string search;
        std::string line;
        std::ifstream file;
        bool found = false;
        file.open("products.txt", std::ios::in);

        std::cout << "Search for item: ";
        std::cin >> search;
        std::cout << "Search results : \n";

        file.seekg(0, std::ios::beg);
        while (!file.eof() && getline(file, line))
        {

                if ((line.find(search)) != std::string::npos)
                {
                        found = true;
                        std::cout << line << std::endl;
                }
        }
        if (found == false)
        {
                std::cout << "Search not found...!!!" << std::endl;
        }

        file.close();
}

void Products::displayOutofStock()
{
        std::cout << "*******************      Out of Stock Products      ********************************\n\n";

        std::string line, name, ProductID, outCount, ProductType;
        int CountVal;
        bool found = false;
        ifstream file("products.txt", std::ios::in);
        std::string delimiter = ";";
        while (std::getline(file, line))
        {
                size_t pos = 0;
                std::string token;
                while ((pos = line.find(delimiter)) != std::string::npos)
                {
                        token = line.substr(0, pos);
                        if (token.rfind("Count ", 0) == 0)
                        {
                                outCount = token.substr(6); // out of stock count
                                CountVal = stoi(outCount);
                                cout << CountVal << "Count" << endl;
                                if (CountVal <= 0)
                                {
                                        found = true;
                                }
                        }
                        if (token.rfind("Name ", 0) == 0 && found)
                        {
                                name = token.substr(5);
                        }
                        if (token.rfind("ProductID ", 0) == 0 && found)
                        {
                                ProductID = token.substr(10);
                        }
                        if (token.rfind("Type ", 0) == 0 && found)
                        {
                                ProductType = token.substr(5);
                        }

                        line.erase(0, pos + delimiter.length());
                }
                if (found)
                {
                        cout << "Product ID: " << ProductID << " | "
                             << "Name: " << name << " | "
                             << "Type: " << ProductType << endl;
                }
        }
}

void Products::AssignCourier()
{
        std::string OrderId, line;
        bool iffound = false;
        int CourierChoice;
        std::string delimiter = ";";
        ifstream courier("orders.txt", ios::in);
        ofstream temp("Temp.txt", ios::out);
        OrderStatusView();
        cout << "Enter the order ID to be assigned to Courier \n";
        getline(cin >> ws, OrderId);
        cout << "Enter Courier Person to be assigned :\n";
        cout << "1.Kochi\n2.Ernakulam\n";
        cin >> CourierChoice;
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
                                cout<<Status<<"Status";
                        }
                        line.erase(0, pos + delimiter.length());
                }

                switch (CourierChoice)
                {
                case 1:
                        if (iffound)
                        {
                                temp << "OrderID " << OrderID << ";"
                                     << "ProductID " << ProductID << ";"
                                     << "Name " << Name << ";"
                                     << "Type " << Type << ";"
                                     << "Count " << Count << ";"
                                     << "Courier "
                                     << "Kochi"
                                     << ";"
                                     << "Status "
                                     << "Shipping"
                                     << ";" << endl;
                                break;
                        }
                        else
                        {
                                temp << OriginalLine << endl;
                        }
                case 2:
                        if (iffound)
                        {
                                temp << "OrderID " << OrderID << ";"
                                     << "ProductID " << ProductID << ";"
                                     << "Name " << Name << ";"
                                     << "Type " << Type << ";"
                                     << "Count " << Count << ";"
                                     << "Courier "
                                     << "Ernakulam"
                                     << ";"
                                     << "Status "
                                     << "Shipping"
                                     << ";" << endl;
                                break;
                                cout << "Order assigned successfully\n";
                        }
                        else
                        {
                                temp << OriginalLine << endl;
                        }
                }
        }
        courier.close();
        temp.close();
// remove("orders.txt");
// rename("Temp.txt","orders.txt");
}
