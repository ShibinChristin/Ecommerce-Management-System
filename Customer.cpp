#include "project.h"
ifstream customer("products.txt", ios::in);
ifstream Customerid("customerId.txt", ios::in);
void Customer::customerMenu()
{
    Authentication authenticationObj;
    std::string CustChoice;
    cout << "********************************************************************************\n\n";
    cout << "                          Welcome to Customer Portal                             \n\n";
    cout << "****************************        MENU        ********************************\n\n";
    cout << "1.Login\n";
    cout << "2.Register\n";
    cout << "3.Previous Menu\n";
    cout << "Enter choice : ";
    cin >> CustChoice;
    std::regex v("^[1-3]$");
    if (!(regex_match(CustChoice, v)))
    {
        cout << "Invalid Choice .....Please try again\n";
        customerMenu();
    }
    switch (stoi(CustChoice))
    {
    case 1:
        authenticationObj.customerLogin();
        customerChoiceDisplay();
        break;
    case 2:
        authenticationObj.customerRegistration();
        customerMenu();
        customerChoiceDisplay();
        break;

    case 3:
        authenticationObj.mainMenu();
        break;
    }
}
int Customer::idGenerate()
{
    int id;
    srand(time(0));        // srand() initialize random number generators
    id = rand() % 100 + 1; // generate random numbers
    return id;
}

void Customer::customerChoiceDisplay()
{
    std::string options;
    cout << "\n\n***********************       MENU        ********************************\n\n";
    cout << "1.Buy Product\n";
    cout << "2.Show Product\n";
    cout << "3.Order Status\n";
    cout << "4.Cancel Order\n";
    cout << "5.Press 5 to logout\n"
         << endl;
    cout << "Enter choice : ";
    cin >> options;
    std::regex w("^[1-5]$");
    if (!(regex_match(options, w)))
    {
        cout << "\nInvalid Choice .....Please try again\n";
        customerChoiceDisplay();
    }
    switch (stoi(options))
    {
    case 1:
    {
        customerBuy();
        customerChoiceDisplay();
    }
    break;
    case 2:
    {
        showProducts();
        customerChoiceDisplay();
    }
    break;
    case 3:
    {
        orderStatus();
        customerChoiceDisplay();
    }
    break;
    case 4:
    {
        cancelOrder();
        customerChoiceDisplay();
    }
    break;
    case 5:
    {
        customerMenu();
    }
    break;
    }
}
void Customer::showProducts() ////// To Display the Products
{
    std::string ProductID, ProductName, ProductPrice, ProductType;
    ifstream in("products.txt", ios::in);
    while (std::getline(in, line1))
    {
        size_t pos = 0;
        while ((pos = line1.find(delimiter)) != std::string::npos)
        {
            token = line1.substr(0, pos);
            if (token.rfind("ProductID ", 0) == 0)
            {
                ProductID = token.substr(9);
            }
            if (token.rfind("Name ", 0) == 0)
            {
                ProductName = token.substr(5);
            }
            if (token.rfind("Price ", 0) == 0)
            {
                ProductPrice = token.substr(6);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                ProductType = token.substr(5);
            }
            line1.erase(0, pos + delimiter.length());
        }
        cout<<"Name : "<<ProductName<<"   "<<"Price : "<<ProductPrice<<endl;
    }
    in.close();
}
void Customer::customerBuy() /*Function to buy products from merchant*/
{
    /* @param  cProduct Customer Product */
    ifstream Customerid("customerId.txt", ios::in);
    ifstream customer1("products.txt", ios::in);
    std::regex obj("^[1-5]$");
    std::string Cproduct, line2, name, ProductID, count, ProductType, ProductPrice, Val, Price, merchant_id1, merchant_id2;
    bool found = false;
    ofstream buy("orders.txt", ios::out | ios::app);
    showProducts();
    cout << endl;
    cout << "Enter the product name you want to buy :";
    getline(std::cin >> std::ws, Cproduct);
buy:
    cout << "How many would you like to buy? ";
    cin >> count;
    if (!(regex_match(count, obj)))
    {
        cout << "Invalid input or you cannot buy more than 5 products " << endl;
        goto buy;
    }
    ofstream temp("temp10.txt", ios::out | ios::app);
    ifstream in1("products.txt", ios::in);
    bool idfound = false;
    int ProductNotFound = 0;
    while (std::getline(Customerid, id))
    {
        customer_id = id;
    }
    Customerid.close();
    while (std::getline(in1, line))
    {
        size_t pos = 0;
        idfound = false;
        std::string originalLine = line;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);

            if (token.rfind("Name ", 0) == 0)
            {
                std::string Pname = token.substr(5);
                if (Pname == Cproduct)
                {
                    idfound = true;
                    ProductNotFound++;
                }
            }
            if (token.rfind("Count ", 0) == 0 && idfound)
            {
                Val = token.substr(6);
            }

            line.erase(0, pos + delimiter.length());
        }
    }
    if (ProductNotFound == 0)
    {
        cout << "Product not found " << endl;
        customerChoiceDisplay();
    }
    in1.close();
    int TempCount;
    int productCount; 
    TempCount = stoi(count);
    productCount = stoi(Val);
    ifstream in3("products.txt", ios::in);
    std::string line3;
    while (std::getline(in3, line3))
    {
        size_t pos = 0;
        idfound = false;
        std::string originalLine = line3;
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
            if (token.rfind("MerchantID ", 0) == 0)
            {
                merchant_id1 = token.substr(11);
            }
            if (token.rfind("Price ", 0) == 0)
            {
                Price = token.substr(6);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                ProductType = token.substr(5);
            }
            line3.erase(0, pos + delimiter.length());
        }
        if (idfound)
        {
            if (productCount - TempCount < 0)
            {
                cout << "Product Out of stock......\nPlease try again later\n";
                customerChoiceDisplay();
            }
            else
            {
                temp << "ProductID " << ProductID;
                temp << ";MerchantID " << merchant_id1;
                temp << ";Name " << Cproduct;
                temp << ";Price " << Price;
                temp << ";Type " << ProductType;
                temp << ";Count " << productCount - TempCount << ";" << endl;
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
    rename("temp10.txt", "products.txt");
    while (std::getline(customer1, line2))
    {
        size_t pos = 0;
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
            if (token.rfind("MerchantID ", 0) == 0)
            {
                merchant_id2 = token.substr(11);
            }
            if (token.rfind("Price ", 0) == 0)
            {
                ProductPrice = token.substr(6);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                ProductType = token.substr(5);
            }

            line2.erase(0, pos + delimiter.length());
        }
        if (found)
        {
            cout << "Order added to cart successfully......\n";
            cout << "Name : " << name << endl;
            cout << "Type : " << ProductType << endl;
            cout << "Price : " << ProductPrice << endl;
            cout << "*******************************************************************************\n\n";
            buy << "CustomerID " << customer_id << ";"
                << "MerchantID " << merchant_id2 << ";"
                << "OrderID " << idGenerate() << ";"
                << "ProductID " << ProductID << ";"
                << "Name " << name << ";"
                << "Type " << ProductType << ";"
                << "Count " << count
                << ";Status "
                << "Pending"
                << ";" << endl;
            found = false;

            break;
        }
    }
    buy.close();
}
/*Code to check status of order*/
void Customer::orderStatus()
{
    std::string line1, name, price, Customer_ID, file;
    ifstream in("orders.txt", ios::in);
    ifstream cuID("customerId.txt", ios::in);
    bool idCustomer = false;
    int buy = 0;
    while (std::getline(cuID, file))
    {
        Customer_ID = file;
    }
    while (std::getline(in, line1))
    {
        std::string ProductS, nameS, PriceS, TypeS, Status, countS, CustomerIdS;
        size_t pos = 0;
        while ((pos = line1.find(delimiter)) != std::string::npos)
        {
            token = line1.substr(0, pos);
            if (token.rfind("CustomerID ", 0) == 0)
            {
                CustomerIdS = token.substr(11);
                if (CustomerIdS == Customer_ID)
                {
                    idCustomer = true;
                    buy++;
                }
            }
            if (token.rfind("ProductID ", 0) == 0 && idCustomer)
            {
                ProductS = token.substr(9);
            }
            if (token.rfind("Name ", 0) == 0 && idCustomer)
            {
                nameS = token.substr(5);
            }
            if (token.rfind("Type ", 0) == 0 && idCustomer)
            {
                TypeS = token.substr(5);
            }
            if (token.rfind("Count ", 0) == 0 && idCustomer)
            {
                countS = token.substr(6);
            }
            if (token.rfind("Status ", 0) == 0 && idCustomer)
            {
                Status = token.substr(7);
            }
            line1.erase(0, pos + delimiter.length());
        }
        if (idCustomer)
        {
            cout << "ProductID " << ProductS << "|"
                 << "Name " << nameS << "|"
                 << "Type "
                 << TypeS << "|"
                 << "Count "
                 << countS << "|"
                 << "Status "
                 << Status
                 << endl;
            idCustomer = false;
        }
    }
    if (buy == 0)
    {
        cout << "\nYou haven't made any orders...." << endl;
        customerChoiceDisplay();
    }
    in.close();
}
/*Function to cancel the order*/
void Customer::cancelOrder()
{
    ifstream Customerid("customerId.txt", ios::in);
    ifstream view("orders.txt", ios::in);
    cout << "***********************      Orders     ********************************\n";
    std::string line1, Cid, defstatus = "Pending", defstatus1 = "Shipping", status, Order, Name, Type, iDCustomer, id1, id2;
    int NoOrders = 0;
    while (std::getline(Customerid, id1))
    {
        customer_id = id1;
    }
    Customerid.close();
    while (std::getline(view, line1))
    {
        bool idCustomer = false, statusCancelled = false;
        size_t pos = 0;
        while ((pos = line1.find(delimiter)) != std::string::npos)
        {
            token = line1.substr(0, pos);
            if (token.rfind("CustomerID ", 0) == 0)
            {
                Cid = token.substr(11); // Cid = Customer ID
                if (Cid == customer_id)
                {
                    idCustomer = true;
                }
            }
            if (token.rfind("OrderID ", 0) == 0 && idCustomer)
            {
                Order = token.substr(8);
            }
            if (token.rfind("Name ", 0) == 0 && idCustomer)
            {
                Name = token.substr(5);
            }
            if (token.rfind("Type ", 0) == 0 && idCustomer)
            {
                Type = token.substr(5);
            }
            if (token.rfind("Status ", 0) == 0 && idCustomer)
            {

                status = token.substr(7);
                if (status == defstatus || status == defstatus1)
                {
                    statusCancelled = true;
                    NoOrders++;
                }
            }
            line1.erase(0, pos + delimiter.length());
        }
        if (statusCancelled)
        {
            cout << "Order ID " << Order << "|"
                 << "Name " << Name << "|"
                 << "Type "
                 << Type << "|"
                 << "Status "
                 << status
                 << endl;
            statusCancelled = false;
        }
        idCustomer = false;
    }
    if (NoOrders == 0)
    {
        cout << "No orders to cancel.....\n";
        customerChoiceDisplay();
    }
    view.close();
    ////////////////////////////////////////////////////////////////////////////
    std::string line2, id, CancelId, Pid, Name1, Type1, Count1, merchant_id5;
    ifstream orders("orders.txt", ios::in);
    ofstream temp1("temp.txt", ios::out);
    std::regex obj("^[0-9]*$");
    int count = 0;
    bool found = false;
    while (std::getline(Customerid, id))
    {
        customer_id = id;
    }
    Customerid.close();
cancel:
    cout << "Enter the Order ID you want to cancel :";
    getline(std::cin >> std::ws, CancelId);
    while (std::getline(orders, line2))
    {
        std::string OriginalLine = line2;
        size_t pos = 0;
        while ((pos = line2.find(delimiter)) != std::string::npos)
        {
            token = line2.substr(0, pos);
            if (token.rfind("MerchantID ", 0) == 0)
            {
                merchant_id5 = token.substr(11);
            }
            if (token.rfind("OrderID ", 0) == 0)
            {
                id = token.substr(8);
                if (CancelId == id)
                {
                    found = true;
                    count++;
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
            cout << "Cancelled Succesfully" << endl;
            temp1 << "CustomerID " << customer_id;
            temp1 << ";MerchantID " << merchant_id5;
            temp1 << ";OrderID " << id;
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
    if (count == 0)
    {
        cout << "No Such Order ID exists......." << endl;
        customerChoiceDisplay();
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
        idfound1 = false;
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
    in.close();
    /*Updating Products.txt*/
    ifstream updation("products.txt", ios::in);
    ofstream Temp("temp2.txt", ios::out);
    std::string line4, name, Price, Type2, Count, merchant_id1;
    bool isfound = false;
    while (std::getline(updation, line4))
    {
        std::string originalLine1 = line4;
        size_t pos = 0;

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
            if (token.rfind("MerchantID ", 0) == 0 && isfound)
            {
                merchant_id1 = token.substr(11);
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
            Temp << ";MerchantID " << merchant_id1;
            Temp << ";Name " << name;
            Temp << ";Price " << Price;
            Temp << ";Type " << Type2;
            Temp << ";Count " << TempCount + ProductCount << ";" << endl;
            isfound = false;
        }
        else
        {
            Temp << originalLine1 << endl;
        }
    }
    in.close();
    Temp.close();
    remove("products.txt");
    rename("temp2.txt", "products.txt");
}
