#include "project.h"
void Merchant::merchantMenu()
{
        Authentication authenticationObj;
        std::string merchantChoice;
        std::cout << "********************************************************************************\n\n";
        std::cout << "                          Welcome to Merchant Portal                             \n\n";
        std::cout << "****************************        MENU        ********************************\n\n";
        std::cout << "1.Login\n";
        std::cout << "2.Register\n";
        std::cout << "3.Previous Menu\n";
        std::cout << "Enter choice : ";
        std::cin >> merchantChoice;
        std::regex x("^[1-3]$");
        if (!(regex_match(merchantChoice, x)))
        {
                std::cout << "Invalid Choice .....Please try again\n";
                merchantMenu();
        }
        switch (stoi(merchantChoice))
        {
        case 1:
                authenticationObj.merchantLogin();
                merchantOptions();
                break;
        case 2:
                authenticationObj.merchantRegistration();
                merchantMenu();
                merchantOptions();
                break;

        case 3:
                authenticationObj.mainMenu();
                break;
        }
}
void Merchant::orderStatusView() // View the  Orders made by the customer
{

        ifstream customer1("orders.txt", ios::in);
        std::string Cproduct, line2;
        std::string OrderId, OrderName, ProductstatusID, StatusType, OrderCount, OrderStatus, defStatus = "Pending", merId, merchant_id, Merchant;
        bool status = false, flag = false;
        int NoStatus = 0;
        std::cout << "***********************************************************************\n\n";
        std::cout << "                      Order Status                             \n\n";
        std::cout << "***********************************************************************\n\n";
        ifstream merchantId1("merchantId.txt", ios::in);
        while (std::getline(merchantId1, merId))
        {
                merchant_id = merId;
        }
        merchantId1.close();
        while (std::getline(customer1, line2))
        {
                while ((pos = line2.find(delimiter)) != std::string::npos)
                {
                        token = line2.substr(0, pos);
                        if (token.rfind("MerchantID ", 0) == 0)
                        {
                                Merchant = token.substr(11);
                                if (Merchant == merchant_id)
                                {
                                        flag = true;
                                }
                        }
                        if (token.rfind("OrderID ", 0) == 0 && flag)
                        {
                                OrderId = token.substr(8);
                        }
                        if (token.rfind("ProductID ", 0) == 0 && flag)
                        {
                                ProductstatusID = token.substr(10);
                        }
                        if (token.rfind("Name ", 0) == 0 && flag)
                        {
                                OrderName = token.substr(5);
                        }
                        if (token.rfind("Type ", 0) == 0 && flag)
                        {
                                StatusType = token.substr(4);
                        }
                        if (token.rfind("Count ", 0) == 0 && flag)
                        {
                                OrderCount = token.substr(5);
                        }
                        if (token.rfind("Status ", 0) == 0 && flag)
                        {
                                OrderStatus = token.substr(7);
                                if (OrderStatus == defStatus)
                                {
                                        status = true;
                                        NoStatus++;
                                }
                        }
                        line2.erase(0, pos + delimiter.length());
                }
                if (status)
                {
                        std::cout << "Order ID " << OrderId << " | "
                                                               "Product ID "
                                  << ProductstatusID << " | "
                                  << "Name " << OrderName << " | "
                                  << "Type " << StatusType << " | "
                                  << "Count " << OrderCount << " | "
                                  << "Status " << OrderStatus << std::endl;
                        status = false;
                }
                flag = false;
        }

        if (NoStatus == 0)
        {
                std::cout << "\nNo orders Present......" << std::endl;
                return;
        }
}

///////////////////////////////////////////////////////////////////////////
int Merchant::idGeneration()
{
        int productId;
        srand(time(0));
        productId = rand() % 100 + 10;
        return productId;
}
void Merchant::addProducts()
{
        std::string line, Merchant_id, MerId;
        std::string productChoice;
        ifstream merchantId1("merchantId.txt", ios::in);
        while (std::getline(merchantId1, MerId))
        {
                Merchant_id = MerId;
        }
        merchantId1.close();

        std ::cout << "<---------------------- ADD PRODUCTS----------------------->" << std ::endl;

        std ::cout << "\nEnter the Product Name : ";
        std ::getline(std::cin >> std::ws, productName);

choice:
        std ::cout << "\nEnter the Type of the Product \n1.Electronics\n2.Furniture\n3.Fashion\nEnter choice :";
        std::getline(std::cin >> std::ws, productChoice);
        std::regex l("^[1-3]$");
        if (!(regex_match(productChoice, l)))
        {
                std::cout << "Invalid Choice .....Please try again\n";
                goto choice;
        }
        switch (stoi(productChoice))
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
        if (!(std::regex_match(productPrice, q)))
        {
                std::cout << "Invalid data...! Please Try Again.." << std::endl;
                std::cout << "\n";
                goto b;
        }
Type:
        std::cout << "\nThe number of available " << productType << " Products : ";
        std::getline(std::cin >> std::ws, productCount);
        std::regex i("^[1-9]+[0-9]*$");
        if (!(std::regex_match(productCount, i)))
        {
                std::cout << "Invalid data...! Please Try Again.." << std::endl;
                std::cout << "\n";
                goto Type;
        }
        std::fstream merchantFile;
        merchantFile.open("products.txt", std::ios::in | std::ios::out | std::ios::app);
        merchantFile << "ProductID " << idGeneration() << ";MerchantID " << Merchant_id << ";Name " << productName << ";Price " << productPrice << ";Type " << productType << ";Count " << productCount << ";" << std::endl;
        std::cout << "\n";
        merchantFile.close();
        std::cout << "<----------------------- PRODUCT ADDED SUCCESFULLY---------------------------->";
        std::cout << "\nWould you like to continue?(Y/N) ";
        std::string choice;
        std::getline(std::cin >> std::ws, choice);
        if (choice == "Y" || choice == "y")
        {
                addProducts();
        }
}
void Merchant::merchantOptions()
{
        std::string options;
        std::cout << "\n\n*******************        MENU        ********************************\n\n";
        std::cout << "1.Add Products\n";
        std::cout << "2.Search Products\n";
        std::cout << "3.Orders List\n";
        std::cout << "4.Products Count\n";
        std::cout << "5.Cancelled Products\n";
        std::cout << "6.Add Stock to Out of Stock\n";
        std::cout << "7.Assign Delivery to Courier\n";
        std::cout << "8.Exit\n";
        std::cout << "Enter choice : ";
        std::cin >> options;
        std::regex y("^[1-8]$");
        if (!(regex_match(options, y)))
        {
                std::cout << "\nInvalid Choice .....Please try again\n";
                merchantOptions();
        }
        switch (stoi(options))
        {
        case 1:
        {
                addProducts();
                merchantOptions();
        }
        break;
        case 2:
        {
                searchProducts();
                merchantOptions();
        }
        break;
        case 3:
        {
                orderStatusView();

                merchantOptions();
        }
        break;
        case 4:
        {
                displayOutOfStock();
                merchantOptions();
        }
        break;
        case 5:
        {
                cancelledProducts();
                merchantOptions();
        }
        break;
        case 6:
        {
                addOutofStock();
                merchantOptions();
        }
        break;
        case 7:
        {
                assignCourier();
                merchantOptions();
        }
        break;
        case 8:
        {
                merchantMenu();
        }
        break;
        }
}
void Merchant::displayOutOfStock()
{
        std::string line, name, ProductID, outCount, ProductType, merId, merchant_id, Merchant;
        int Stock = 0, lessProductCount = 0;
        bool found = false, id = false;
        std::ifstream file;
        file.open("products.txt", std::ios::in);
        ifstream merchantId1("merchantId.txt", ios::in);
        cout << "Enter Product Count: ";
        cin >> lessProductCount;
        while (std::getline(merchantId1, merId))
        {
                merchant_id = merId;
        }
        merchantId1.close();
        while (std::getline(file, line))
        {
                while ((pos = line.find(delimiter)) != std::string::npos)
                {
                        token = line.substr(0, pos);
                        if (token.rfind("ProductID ", 0) == 0)
                        {
                                ProductID = token.substr(10);
                        }
                        if (token.rfind("MerchantID ", 0) == 0)
                        {
                                Merchant = token.substr(11);
                                if (Merchant == merchant_id)
                                {
                                        id = true;
                                        // Stock++;
                                }
                        }
                        if (token.rfind("Name ", 0) == 0 && id)
                        {
                                name = token.substr(5);
                        }
                        if (token.rfind("Type ", 0) == 0 && id)
                        {
                                ProductType = token.substr(5);
                        }
                        if (token.rfind("Count ", 0) == 0 && id)
                        {
                                outCount = token.substr(6); // out of stock count
                                int CountVal = stoi(outCount);
                                if (CountVal <= lessProductCount)
                                {
                                        found = true;
                                        Stock++;
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
                id = false;
        }
        if (Stock == 0)
        {
                std::cout << "\nNo Products are out of stock...." << std::endl;
        }

        file.close();
}

void Merchant::assignCourier()
{
        std::string OrderId, line;
        bool iffound = false;
        std::string CourierChoice;
        ifstream courier("orders.txt", ios::in);
        ofstream temp("Temp.txt", ios::out);
        //////////////////////////////////////////////////////////////////////
        std::cout << "***********************      Orders     ********************************\n";
        std::string line1, defstatus = "Pending", status, Order, Name, Type, customer_id, merchant_id, merId, Mer;
        ifstream view1("orders.txt", ios::in);
        bool statusFound = false, flag = false;
        int count = 0, statusCount = 0;
        ifstream MerchantId("merchantId.txt", ios::in);
        while (std::getline(MerchantId, merId))
        {
                merchant_id = merId;
        }
        MerchantId.close();
        while (std::getline(view1, line1))
        {
                while ((pos = line1.find(delimiter)) != std::string::npos)
                {
                        token = line1.substr(0, pos);
                        if (token.rfind("CustomerID ", 0) == 0)
                        {
                                customer_id = token.substr(11);
                        }
                        if (token.rfind("MerchantID ", 0) == 0)
                        {
                                Mer = token.substr(11);
                                if (Mer == merchant_id)
                                {
                                        flag = true;
                                        count++;
                                }
                        }
                        if (token.rfind("OrderID ", 0) == 0 && flag)
                        {
                                Order = token.substr(8);
                        }
                        if (token.rfind("Name ", 0) == 0 && flag)
                        {
                                Name = token.substr(5);
                        }
                        if (token.rfind("Type ", 0) == 0 && flag)
                        {
                                Type = token.substr(5);
                        }
                        if (token.rfind("Status ", 0) == 0 && flag)
                        {

                                status = token.substr(7);
                                if (defstatus == status)
                                {
                                        statusFound = true;
                                        statusCount++;
                                }
                        }
                        line1.erase(0, pos + delimiter.length());
                }
                if (statusFound)
                {
                        std::cout << "Order ID " << Order << "|"
                                  << "Name " << Name << "|"
                                  << "Type "
                                  << Type << "|"
                                  << "Status "
                                  << status
                                  << std::endl;
                        statusFound = false;
                }
                flag = false;
        }
        if (count == 0 || statusCount == 0)
        {
                std::cout << "No Products to assign......." << endl;
                return;
        }
        std::cout << "Enter the order ID to be assigned to Courier \n";
        std::getline(std::cin >> std::ws, OrderId);
        std::cout << "Enter Courier Person to be assigned :\n";
        std::cout << "1.Kochi\n2.Ernakulam\n";
        std::cin >> CourierChoice;
        std::regex m("^[1-2]$");
        if (!(regex_match(CourierChoice, m)))
        {
                std::cout << "Invalid choice .....Please try again\n";
                merchantOptions();
        }
        int count1 = 0;
        while (std::getline(courier, line))
        {
                std::string OrderID, ProductID, Name, Type, Count, Status;
                std::string OriginalLine = line;
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
                                ProductID = token.substr(10);
                        }
                        if (token.rfind("Name ", 0) == 0 && iffound)
                        {
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

                switch (stoi(CourierChoice))
                {
                case 1:
                        if (iffound)
                        {
                                std::cout << "Updated Successfully......" << std::endl;
                                temp << "CustomerID " << customer_id << ";"
                                     << "MerchantID " << merchant_id << ";"
                                     << "OrderID " << OrderID << ";"
                                     << "ProductID " << ProductID << ";"
                                     << "Name " << Name << ";"
                                     << "Type " << Type << ";"
                                     << "Count " << Count << ";"
                                     << "Courier "
                                     << "Kochi"
                                     << ";"
                                     << "Status "
                                     << "Shipping"
                                     << ";" << std::endl;
                                iffound = false;
                                break;
                        }
                        else
                        {
                                temp << OriginalLine << std::endl;
                        }
                        break;
                case 2:
                        if (iffound)
                        {
                                temp << "CustomerID " << customer_id << ";"
                                     << "MerchantID " << merchant_id << ";"
                                     << "OrderID " << OrderID << ";"
                                     << "ProductID " << ProductID << ";"
                                     << "Name " << Name << ";"
                                     << "Type " << Type << ";"
                                     << "Count " << Count << ";"
                                     << "Courier "
                                     << "Ernakulam"
                                     << ";"
                                     << "Status "
                                     << "Shipping"
                                     << ";" << std::endl;
                                iffound = false;
                                break;
                                std::cout << "Order assigned successfully\n";
                        }
                        else
                        {
                                temp << OriginalLine << std::endl;
                        }
                        break;
                default:
                        // // cout << "Not Valid...." << endl;
                        // continue;
                        break;
                }
        }
        if (count1 == 0)
        {
                std::cout << "No Such Order ID exists......." << std::endl;
                return;
        }
        courier.close();
        temp.close();
        remove("orders.txt");
        rename("Temp.txt", "orders.txt");
}
void Merchant::searchProducts()
{
        std::string choice, merchant_id, merId;
        ifstream file("products.txt", ios::in);
        std::cout << "1.Search By Name\n2.Search By Type\n";
        std::cout << "Enter choice :";
        std::getline(std::cin >> std::ws, choice);
        ifstream merchantId1("merchantId.txt", ios::in);
        while (std::getline(merchantId1, merId))
        {
                merchant_id = merId;
        }
        merchantId1.close();
        if (choice == "1")
        {
                std::string search, line, Name;
                std::cout << "Enter the name of the product" << std::endl;
                getline(std::cin >> std::ws, search);

                std::string Id, name1, price1, Type1, count1, Merchant;

                ifstream pName;
                int ProductNotFound = 0;
                pName.open("products.txt", std::ios::in);
                while (std::getline(pName, line))
                {
                        bool found = false, flag = false;
                        while ((pos = line.find(delimiter)) != std::string::npos)
                        {
                                token = line.substr(0, pos);
                                if (token.rfind("ProductID ", 0) == 0)
                                {
                                        Id = token.substr(10);
                                }
                                if (token.rfind("MerchantID ", 0) == 0)
                                {
                                        Merchant = token.substr(11);
                                        if (Merchant == merchant_id)
                                        {
                                                flag = true;
                                        }
                                }
                                if (token.rfind("Name ", 0) == 0 && flag)
                                {
                                        Name = token.substr(5);
                                        if (search == Name)
                                        {
                                                found = true;
                                                ProductNotFound++;
                                        }
                                }
                                if (token.rfind("Price ", 0) == 0 && found)
                                {
                                        price1 = token.substr(6);
                                }
                                if (token.rfind("Type ", 0) == 0 && found)
                                {
                                        Type1 = token.substr(5);
                                }
                                if (token.rfind("Count ", 0) == 0 && found)
                                {
                                        count1 = token.substr(5);
                                }
                                line.erase(0, pos + delimiter.length());
                        }
                        if (found)
                        {
                                std::cout << "ProductID " << Id << " | "
                                          << "Name " << Name << " | "
                                          << "Price " << price1 << " | "
                                          << "Type " << Type1 << " | "
                                          << "Count " << count1 << std::endl;
                                found = false;
                                break;
                        }
                        flag = false;
                }
                pName.close();
                if (ProductNotFound == 0)
                {
                        std::cout << "Product not found" << std::endl;
                }
        }
        else if (choice == "2")
        {
                std::string pType;
                string choice;
                int notFound = 0;
                std::cout << "\n1.Electronics\n2.Furniture\n3.Fashion" << std::endl;
        ch:
                std::cout << "Enter your choice" << std::endl;
                cin >> choice;
                std::regex check("^[1-3]$");
                if (!(regex_match(choice, check)))
                {
                        std::cout << "Invalid Choice .....Please try again\n";
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
                std::string line, Type, name, id, count, price, Merchant;
                bool found = false, flag = false;
                ifstream productFile;
                productFile.open("products.txt", ios::in);
                while (std::getline(productFile, line))
                {
                        while ((pos = line.find(delimiter)) != std::string::npos)
                        {
                                token = line.substr(0, pos);

                                if (token.rfind("ProductID ", 0) == 0)
                                {
                                        id = token.substr(10);
                                }
                                if (token.rfind("MerchantID ", 0) == 0)
                                {
                                        Merchant = token.substr(11);
                                        if (Merchant == merchant_id)
                                        {
                                                flag = true;
                                        }
                                }
                                if (token.rfind("Name ", 0) == 0 & flag)
                                {
                                        name = token.substr(5);
                                }
                                if (token.rfind("Price ", 0) == 0 & flag)
                                {
                                        price = token.substr(6);
                                }
                                if (token.rfind("Type ", 0) == 0 & flag)
                                {
                                        Type = token.substr(5);
                                        if (Type == pType)
                                        {
                                                found = true;
                                                notFound++;
                                        }
                                }
                                if (token.rfind("Count ", 0) == 0 & flag)
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
                        // else
                        // {
                        //         continue;
                        // }
                        flag = false;
                }
                if (notFound == 0)
                {
                        cout << "No Such Product has been added......\n";
                }
                productFile.close();
        }
        else
        {
                cout << "Invalid Choice... Please try again\n";
                cout << "\n";
                searchProducts();
        }
}

void Merchant::cancelledProducts()
{
        std::string line, orderId, pId, pName, Price, pType, pCount, pStatus;
        std::string status = "Cancelled";
        bool found = false, id = false;
        int cancelled = 0;
        std::cout << "<--------------------------List of Cancelled Orders----------------------------->" << std::endl;
        std::ifstream orderList;
        orderList.open("orders.txt", std::ios::in);
        std::string merchant_id, merId, Merchant;
        ifstream merchantId1("merchantId.txt", ios::in);
        while (std::getline(merchantId1, merId))
        {
                merchant_id = merId;
        }
        merchantId1.close();
        while (std::getline(orderList, line))
        {
                while ((pos = line.find(delimiter)) != std::string::npos)
                {
                        token = line.substr(0, pos);
                        if (token.rfind("MerchantID ", 0) == 0)
                        {
                                Merchant = token.substr(11);
                                if (Merchant == merchant_id)
                                {
                                        id = true;
                                }
                        }
                        if (token.rfind("OrderID ", 0) == 0 && id)
                        {
                                orderId = token.substr(8);
                        }
                        if (token.rfind("ProductID ", 0) == 0 && id)
                        {
                                pId = token.substr(10);
                        }
                        if (token.rfind("Name ", 0) == 0 && id)
                        {
                                pName = token.substr(5);
                        }
                        if (token.rfind("Type ", 0) == 0 && id)
                        {
                                pType = token.substr(5);
                        }
                        if (token.rfind("Count ", 0) == 0 && id)
                        {
                                pCount = token.substr(6);
                        }
                        if (token.rfind("Status ", 0) == 0 && id)
                        {
                                pStatus = token.substr(7);
                                if (status == pStatus)
                                {
                                        found = true;
                                        cancelled++;
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
                        found = false;
                }
                id = false;
        }

        if (cancelled == 0)
        {
                std::cout << "\nNo Products have been cancelled by user......" << std::endl;
        }
        orderList.close();
}

void Merchant::addOutofStock()
{
        std::cout << "*******************      Out of Stock Products      ********************************\n\n";
        std::string line, name, ProductID, outCount, ProductType, merId, merchant_id, Merchant;
        int Stock = 0;
        bool found = false, id = false;
        std::ifstream file;
        file.open("products.txt", std::ios::in);
        ifstream merchantId1("merchantId.txt", ios::in);
        while (std::getline(merchantId1, merId))
        {
                merchant_id = merId;
        }
        merchantId1.close();
        while (std::getline(file, line))
        {
                while ((pos = line.find(delimiter)) != std::string::npos)
                {
                        token = line.substr(0, pos);
                        if (token.rfind("ProductID ", 0) == 0)
                        {
                                ProductID = token.substr(10);
                        }
                        if (token.rfind("MerchantID ", 0) == 0)
                        {
                                Merchant = token.substr(11);
                                if (Merchant == merchant_id)
                                {
                                        id = true;
                                }
                        }
                        if (token.rfind("Name ", 0) == 0 && id)
                        {
                                name = token.substr(5);
                        }
                        if (token.rfind("Type ", 0) == 0 && id)
                        {
                                ProductType = token.substr(5);
                        }
                        if (token.rfind("Count ", 0) == 0 && id)
                        {
                                outCount = token.substr(6); // out of stock count
                                int CountVal = stoi(outCount);
                                if (CountVal <= 0)
                                {
                                        found = true;
                                        Stock++;
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
                id = false;
        }
        if (Stock == 0)
        {
                cout << "\nNo products are out of stock.........";
                return;
        }

        file.close();
        std::string addline, addProductId, addMerchantID, addName, addPrice, addType, addCount, PID, ProductNumber;
        ifstream ProductFile;
        ofstream ProductTemp("ProductTemp.txt", ios::out | ios::app);
        int productOut = 0;
        bool OutOfStock = false;
        ProductFile.open("products.txt", ios::in);
        // displayOutOfStock();
        cout << "Enter the Product Id of stock  to be  increased :";
        getline(cin >> ws, PID);
        cout << "Enter the  number of products :";
        getline(cin, ProductNumber);
        while (std::getline(ProductFile, addline))
        {
                std::string OriginalLine = addline;
                while ((pos = addline.find(delimiter)) != std::string::npos)
                {
                        token = addline.substr(0, pos);

                        if (token.rfind("ProductID ", 0) == 0)
                        {
                                addProductId = token.substr(10);
                                if (addProductId == PID)
                                {
                                        OutOfStock = true;
                                        productOut++;
                                }
                        }
                        if (token.rfind("MerchantID ", 0) == 0 && OutOfStock)
                        {
                                addMerchantID = token.substr(11);
                        }
                        if (token.rfind("Name ", 0) == 0 && OutOfStock)
                        {
                                addName = token.substr(5);
                        }
                        if (token.rfind("Price ", 0) == 0 && OutOfStock)
                        {
                                addPrice = token.substr(6);
                        }
                        if (token.rfind("Type ", 0) == 0 && OutOfStock)
                        {
                                addType = token.substr(5);
                        }
                        if (token.rfind("Count ", 0) == 0 && OutOfStock)
                        {
                                addCount = token.substr(6);
                        }
                        addline.erase(0, pos + delimiter.length());
                }
                if (OutOfStock)
                {
                        ProductTemp << "ProductID " << addProductId << ";MerchantID " << addMerchantID << ";Name " << addName << ";Price " << addPrice
                                    << ";Type " << addType << ";Count " << ProductNumber << ";" << endl;
                        OutOfStock = false;
                }
                else
                {
                        ProductTemp << OriginalLine << endl;
                }
        }
        if (productOut == 0)
        {
                cout << "\nNo Such Product ID....................";
        }
        remove("products.txt");
        rename("ProductTemp.txt", "products.txt");
}