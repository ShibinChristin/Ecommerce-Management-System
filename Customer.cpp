#include "project.h"

ifstream customer("products.txt", ios::in);

int Customer::idGenerate()
{
    int id;
    srand(time(0));        // srand() initialize random number generators
    id = rand() % 100 + 1; // generate random numbers
    return id;
}

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
    cout << "4.Cancel Order\n";
    cout << "Press 5 to logout\n"
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
            if (token.rfind("ProductID ", 0) == 0)
            {
                std::cout << "Product ID: " << token.substr(9);
            }
            if (token.rfind("Name ", 0) == 0)
            {
                std::cout << " |Name : " << token.substr(5);
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
    std::string Cproduct, line2, delimiter = ";", name, ProductID, count, ProductType, Val; /// cProduct   --- Customer Product
    bool found = false;
    ofstream buy("orders.txt", ios::out | ios::app);
    showProducts();
    cout << endl;
    cout << "Enter the product name you want to buy :";
    getline(std::cin >> std::ws, Cproduct);
gotobuy:
    cout << "How many would you like to buy? ";
    cin >> count;
    if (!(regex_match(count, obj)))
    {
        cout << "Invalid input or you cannot buy more than 5 products " << endl;
        goto gotobuy;
    }
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
                ProductType = token.substr(5);
            }

            line2.erase(0, pos + delimiter.length());
        }
        if (found == true)
        {
            buy << "OrderID " << idGenerate() << ";"
                << "ProductID " << ProductID << ";"
                << "Name " << name << ";"
                << "Type " << ProductType << ";"
                << "Count " << count
                << ";Status "
                << "Pending"
                << ";" << endl;

            break;
        }
    }
    if (found == false)
    {
        cout << "Product not found " << endl;
    }
    buy.close();
    ofstream temp("temp.txt", ios::out | ios::app);
    ifstream in1("products.txt", ios::in);
    bool idfound = false;
    while (std::getline(in1, line))
    {
        std::string delimiter = ";";
        size_t pos = 0;
        idfound = false;
        std::string originalLine = line;
        std::string token;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);

            if (token.rfind("Name ", 0) == 0)
            {
                std::string Pname = token.substr(5);
                if (Pname == Cproduct)
                {
                    idfound = true;
                }
            }
            if (token.rfind("Count ", 0) == 0 && idfound)
            {
                Val = token.substr(6);
            }

            line.erase(0, pos + delimiter.length());
        }
    }
    in1.close();
    int TempCount;
    int ProductC;

    TempCount = stoi(count);
    ProductC = stoi(Val);
    ifstream in3("products.txt", ios::in);
    std::string line3;
    while (std::getline(in3, line3))
    {
        std::string delimiter = ";";
        size_t pos = 0;
        idfound = false;
        std::string originalLine = line3;
        std::string token;
        while ((pos = line3.find(delimiter)) != std::string::npos)
        {
            token = line3.substr(0, pos);
            if (token.rfind("Name ", 0) == 0)
            {
                std::string ChecK_name = token.substr(5);
                if (Cproduct == ChecK_name)
                {
                    idfound = true;
                }
            }
            if (token.rfind("ProductID ", 0) == 0)
            {
                ProductID = token.substr(10);
            }
            line3.erase(0, pos + delimiter.length());
        }
        if (idfound)
        {
            temp << "ProductID " << ProductID;
            temp << ";Name " << name;
            temp << ";Type " << ProductType;
            temp << ";Count " << ProductC - TempCount << ";" << endl;
            if (ProductC - TempCount <= 0)
            {
                cout << "Product Out of stock......\nPlease try again later\n";
                sleep(2);
            }
        }

        else
        {

            temp << originalLine << endl;
        }
    }
    temp.close();
    in3.close();
    remove("products.txt");
    rename("temp.txt", "products.txt");
    // }
}
/*Code to check status of order*/
void Customer::orderStatus()
{
    std::string line1, name, price;
    std::string delimiter = ";";
    ifstream in("orders.txt", ios::in);
    // ofstream out("OrderStatus.txt", ios::out | ios::app);
    while (std::getline(in, line1))
    {
        std::string ProductS, nameS, PriceS, TypeS, Status, countS;
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
                TypeS = token.substr(5);
            }
            if (token.rfind("Count ", 0) == 0)
            {
                countS = token.substr(6);
            }
            if (token.rfind("Status ", 0) == 0)
            {
                Status = token.substr(7);
            }
            line1.erase(0, pos + delimiter.length());
        }
        cout << "ProductID " << ProductS << "|"
             << "Name " << nameS << "|"
             << "Type "
             << TypeS << "|"
             << "Count "
             << countS << "|"
             << "Status "
             << Status
             << endl;
    }
    in.close();
    // out.close();
}
void Customer::CancelOrder()
{
    cout << "***********************      Orders     ********************************\n";
    // orderStatus();
    // cout << endl;
    //     ifstream orders("orders.txt", ios::in);
    //     std::regex obj("^[0-9]*$");
    //     std::string CancelProduct, line4, delimiter = ";", name, ProductID, cancelCount, ProductCount, Val, OrderID, Status; /// cProduct   --- Customer Product
    //     bool found = false;
    //     ofstream buy("orders.txt", ios::out | ios::app);
    // cancelChoice:
    //     cout << "Enter the product name you want to cancel :";
    //     getline(std::cin >> std::ws, CancelProduct);
    // cancel:
    //     cout << "How many would you like to cancel? ";
    //     cin >> cancelCount;
    //     if (!(regex_match(cancelCount, obj)))
    //     {
    //         cout << "Invalid input " << endl;
    //         goto cancel;
    //     }
    //     while (std::getline(orders, line4))
    //     {
    //         size_t pos = 0;
    //         std::string token;
    //         while ((pos = line4.find(delimiter)) != std::string::npos)
    //         {
    //             token = line4.substr(0, pos);
    //             if (token.rfind("Name ", 0) == 0)
    //             {
    //                 name = token.substr(5);

    //                 if (CancelProduct == name)
    //                 {
    //                     found = true;
    //                 }
    //             }

    //             if (token.rfind("Count ", 0) == 0 && found)
    //             {
    //                 ProductCount = token.substr(6);
    //                 if (ProductCount < cancelCount)
    //                 {
    //                     cout << "You cannot cancel more than you ordered\n";
    //                     goto cancel;
    //                 }
    //                 else
    //                 {
    //                     cout << "Canceled " << cancelCount << " products successfully\n";
    //                 }
    //             }

    //             line4.erase(0, pos + delimiter.length());
    //         }
    //     }
    //     orders.close();
    //     ofstream temp("temp.txt", ios::out | ios::app);
    //     ifstream in2("products.txt", ios::in);
    //     bool idfound = false;
    //     while (std::getline(in2, line))
    //     {
    //         std::string delimiter = ";";
    //         size_t pos = 0;
    //         idfound = false;
    //         std::string originalLine = line;
    //         std::string token;
    //         while ((pos = line.find(delimiter)) != std::string::npos)
    //         {
    //             token = line.substr(0, pos);

    //             if (token.rfind("Name ", 0) == 0)
    //             {
    //                 std::string Pname = token.substr(5);
    //                 if (Pname == CancelProduct)
    //                 {
    //                     idfound = true;
    //                 }
    //             }
    //             if (token.rfind("Count ", 0) == 0 && idfound)
    //             {
    //                 Val = token.substr(6);
    //             }

    //             line.erase(0, pos + delimiter.length());
    //         }
    //     }
    //     in2.close();
    //     int TempCount;
    //     int ProductC;

    //     TempCount = stoi(cancelCount);
    //     ProductC = stoi(Val);
    //     ifstream in3("products.txt", ios::in);
    //     std::string line3, ProductType;
    //     while (std::getline(in3, line3))
    //     {
    //         std::string delimiter = ";";
    //         size_t pos = 0;
    //         idfound = false;
    //         std::string originalLine = line3;
    //         std::string token;
    //         while ((pos = line3.find(delimiter)) != std::string::npos)
    //         {
    //             token = line3.substr(0, pos);
    //             if (token.rfind("Name ", 0) == 0)
    //             {
    //                 std::string ChecK_name = token.substr(5);
    //                 if (CancelProduct == ChecK_name)
    //                 {
    //                     idfound = true;
    //                 }
    //             }
    //             if (token.rfind("ProductID ", 0) == 0)
    //             {
    //                 ProductID = token.substr(10);
    //             }
    //             if (token.rfind("Type ", 0) == 0)
    //             {
    //                 ProductType = token.substr(5);
    //             }
    //             line3.erase(0, pos + delimiter.length());
    //         }
    //         if (idfound)
    //         {
    //             temp << "ProductID " << ProductID;
    //             temp << ";Name " << CancelProduct;
    //             temp << ";Type " << ProductType;
    //             temp << ";Count " << ProductC + TempCount << ";" << endl;
    //         }

    //         else
    //         {

    //             temp << originalLine << endl;
    //         }
    //     }
    //     temp.close();
    //     in3.close();
    //     remove("products.txt");
    //     rename("temp.txt", "products.txt");
    //     /*Updating Orders */
    //     std::string line5, Val1;
    //     ofstream temp1("temp1.txt", ios::out | ios::app);
    //     ifstream orderinput("orders.txt", ios::in);
    //     bool isfound = false;
    //     while (std::getline(orderinput, line5))
    //     {
    //         std::string delimiter = ";";
    //         size_t pos = 0;
    //         idfound = false;
    //         std::string originalLine = line5;
    //         std::string token;
    //         while ((pos = line5.find(delimiter)) != std::string::npos)
    //         {
    //             token = line5.substr(0, pos);

    //             if (token.rfind("Name ", 0) == 0)
    //             {
    //                 std::string Pname = token.substr(5);
    //                 if (Pname == CancelProduct)
    //                 {
    //                     idfound = true;
    //                 }
    //             }
    //             if (token.rfind("Count ", 0) == 0 && idfound)
    //             {
    //                 Val1 = token.substr(6);
    //                 cout << Val1 << "value1 ";
    //             }

    //             line5.erase(0, pos + delimiter.length());
    //         }
    //     }
    //     orderinput.close();
    //     int TempCountCancel;
    //     int ProductCancel;

    //     TempCountCancel = stoi(Val1);
    //     ProductCancel = stoi(cancelCount);
    //     cout << TempCountCancel << "TempCount";
    //     ifstream in4("orders.txt", ios::in);
    //     std::string line8, ProductType1;
    //     while (std::getline(in4, line8))
    //     {
    //         std::string delimiter = ";";
    //         size_t pos = 0;
    //         idfound = false;
    //         std::string originalLine = line8;
    //         std::string token;
    //         while ((pos = line8.find(delimiter)) != std::string::npos)
    //         {
    //             token = line8.substr(0, pos);
    //             if (token.rfind("Name ", 0) == 0)
    //             {
    //                 std::string ChecK_name = token.substr(5);
    //                 if (CancelProduct == ChecK_name)
    //                 {
    //                     idfound = true;
    //                 }
    //             }
    //             if (token.rfind("OrderID ", 0) == 0&&idfound)
    //             {
    //                 OrderID = token.substr(8);
    //             }
    //             if (token.rfind("ProductID ", 0) == 0&&idfound)
    //             {
    //                 ProductID = token.substr(10);
    //             }
    //             if (token.rfind("Type ", 0) == 0&&idfound)
    //             {
    //                 ProductType = token.substr(5);
    //             }
    //             if (token.rfind("Status ", 0) == 0&&idfound)
    //             {
    //                 Status = token.substr(7);
    //             }
    //             line8.erase(0, pos + delimiter.length());
    //         }
    //         if (idfound)
    //         {
    //             temp1 << "OrderID " << OrderID;
    //             temp1 << ";ProductID " << ProductID;
    //             temp1 << ";Name " << CancelProduct;
    //             temp1 << ";Type " << ProductType;
    //             temp1 << ";Count " << ProductC - TempCount << ";" ;
    //             temp1 << "Status "<<"Cancelled"<< endl;
    //         }

    //         else
    //         {

    //             temp1 << originalLine << endl;
    //         }
    //     }
    //     remove("orders.txt");
    //     rename("temp1.txt","orders.txt");
    //     temp.close();
    //     in3.close();
    ////////////////////////////////////////////////////////////////////////////
    std::string line1, defstatus = "Pending", status, Order, Name, Type;
    std::string delimiter = ";";
    ifstream view("orders.txt", ios::in);
    bool st = false;
    while (std::getline(view, line1))
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
        // else{
        //     cout<<"No Products to Cancel....\n";
        //     break;
        // }
    }
    view.close();
    ////////////////////////////////////////////////////////////////////////////
    std::string line2, id, CancelId, Pid, Name1, Type1, Count1;
    ifstream orders("orders.txt", ios::in);
    ofstream temp1("temp.txt", ios::out);
    std::regex obj("^[0-9]*$");
    bool found = false;
cancel:
    cout << "Enter the Product ID you want to cancel :";
    getline(std::cin >> std::ws, CancelId);
    while (std::getline(orders, line2))
    {
        std::string OriginalLine = line2;
        size_t pos = 0;
        std::string token;
        while ((pos = line2.find(delimiter)) != std::string::npos)
        {
            token = line2.substr(0, pos);
            if (token.rfind("OrderID ", 0) == 0)
            {
                id = token.substr(8);
                if (CancelId == id)
                {
                    found = true;
                }
            }
            if (token.rfind("ProductID ", 0) == 0 && found)
            {
                Pid = token.substr(10);
            }
            if (token.rfind("Name ", 0) == 0 && found)
            {
                Name1 = token.substr(5);
            }
            if (token.rfind("Type ", 0) == 0 && found)
            {
                Type1 = token.substr(5);
            }
            if (token.rfind("Count ", 0) == 0 && found)
            {
                Count1 = token.substr(6);
            }
            line2.erase(0, pos + delimiter.length());
        }
        if (found)
        {
            temp1 << "OrderID " << id;
            temp1 << ";ProductID " << Pid;
            temp1 << ";Name " << Name1;
            temp1 << ";Type " << Type1;
            temp1 << ";Count " << Count1 << ";";
            temp1 << "Status "
                  << "Cancelled;" << endl;
            found = false;
        }
        else
        {
            temp1 << OriginalLine << endl;
        }
    }
    remove("orders.txt");
    rename("temp.txt", "orders.txt");
    int TempCount = stoi(Count1);
    int ProductCount;
    std::string PorderID, PCount;
    ifstream in("products.txt", ios::in);
    std::string line3;
    bool idfound1 = false;
    while (std::getline(in, line3))
    {
        size_t pos = 0;
        std::string token;
        while ((pos = line3.find(delimiter)) != std::string::npos)
        {
            token = line3.substr(0, pos);
            if (token.rfind("ProductID ", 0) == 0)
            {
                PorderID = token.substr(10);
                if (Pid == PorderID)
                {
                    idfound1 = true;
                }
            }
            if (token.rfind("Count ", 0) == 0 && idfound1)
            {
                PCount = token.substr(6);
            }
            line3.erase(0, pos + delimiter.length());
        }
        if (idfound1)
        {
            ProductCount = stoi(PCount);
            idfound1 = false;
        }
    }
    cout << "Product Count" << ProductCount << endl;
    cout << "Total COunt " << TempCount + ProductCount;
    in.close();
    //////////////////////////////////////////////////////////////////////////
    ifstream updation("products.txt", ios::in);
    ofstream Temp("temp2.txt", ios::out);
    std::string line4, name, Price, Type2, Count;
    bool isfound = false;
    while (std::getline(updation, line4))
    {
        std::string originalLine1;
        size_t pos = 0;
        std::string token;
        while ((pos = line4.find(delimiter)) != std::string::npos)
        {
            token = line4.substr(0, pos);
            if (token.rfind("ProductID ", 0) == 0)
            {
                PorderID = token.substr(10);
                if (Pid == PorderID)
                {
                    isfound = true;
                }
            }
            if (token.rfind("Name ", 0) == 0 && isfound)
            {
                name = token.substr(5);
            }
            if (token.rfind("Price ", 0) == 0 && isfound)
            {
                Price = token.substr(6);
            }
            if (token.rfind("Type ", 0) == 0 && isfound)
            {
                Type2 = token.substr(5);
            }
            line4.erase(0, pos + delimiter.length());
        }
        if (isfound)
        {
            Temp << "ProductID " << PorderID;
            Temp << ";Name " << name;
            Temp << ";Price " << Price;
            Temp << ";Type " << Type2;
            Temp << ";Count " << TempCount + ProductCount << ";" << endl;
        }
        else
        {
            Temp << originalLine1 << endl;
        }
    }
    in.close();
    Temp.close();
    remove("products.txt");
    rename("temp2.txt","products.txt");
}
