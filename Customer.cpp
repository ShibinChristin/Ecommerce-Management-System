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
    std::regex obj("^[1-5]$");
    std::string Cproduct, line2, delimiter = ";", name, ProductID, count, ProductType, Val, Price; /// cProduct   --- Customer Product
    bool found = false;
    int i = 0;
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
    ofstream temp("temp.txt", ios::out | ios::app);
    ifstream in1("products.txt", ios::in);
    bool idfound = false;
    int j = 0;
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
                    j++;
                }
            }
            if (token.rfind("Count ", 0) == 0 && idfound)
            {
                Val = token.substr(6);
            }

            line.erase(0, pos + delimiter.length());
        }
    }
    if (j == 0)
    {
        cout << "Product not found " << endl;
        return;
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
            if (ProductC - TempCount < 0)
            {
                cout << "Product Out of stock......\nPlease try again later\n";
                return;
            }
            else
            {
                temp << "ProductID " << ProductID;
                temp << ";Name " << Cproduct;
                temp << ";Price " << Price;
                temp << ";Type " << ProductType;
                temp << ";Count " << ProductC - TempCount << ";" << endl;
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
                    i++;
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
        if (found)
        {
            cout << "Order added to cart successfully......\n";
            buy << "OrderID " << idGenerate() << ";"
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
    std::string line1, name, price;
    std::string delimiter = ";";
    ifstream in("orders.txt", ios::in);
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
                ProductS = token.substr(9);
            }
            if (token.rfind("Name ", 0) == 0)
            {
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
}
void Customer::CancelOrder()
{
    ifstream view("orders.txt", ios::in);
    cout << "***********************      Orders     ********************************\n";
    std::string line1, defstatus = "Pending", defstatus1 = "Shipping", status, Order, Name, Type;
    std::string delimiter = ";";
    bool st = false;
    int count2 = 0;
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
                if (defstatus == status || status == defstatus1)
                {
                    st = true;
                    count2++;
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
    if (count2 == 0)
    {
        cout << "No orders to cancel.....\n";
        return;
    }
    view.close();
    ////////////////////////////////////////////////////////////////////////////
    std::string line2, id, CancelId, Pid, Name1, Type1, Count1;
    ifstream orders("orders.txt", ios::in);
    ofstream temp1("temp.txt", ios::out);
    std::regex obj("^[0-9]*$");
    int count = 0;
    bool found = false;
cancel:
    cout << "Enter the Order ID you want to cancel :";
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
    if (count == 0)
    {
        cout << "No Such Order ID exists......." << endl;
        return;
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
    //////////////////////////////////////////////////////////////////////////
    ifstream updation("products.txt", ios::in);
    ofstream Temp("temp2.txt", ios::out);
    std::string line4, name, Price, Type2, Count;
    bool isfound = false;
    while (std::getline(updation, line4))
    {
        std::string originalLine1 = line4;
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