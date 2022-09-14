#include "project.h"
std::string choice;
void Courier::courierOptions()
{
    std::cout << "\n\n*********WELCOME TO COURIER PORTAL********\n\n";
    std::cout << "\t1. View assigned orders \n";
    std::cout << "\t2. Update status of orders \n";
    std::cout << "\t3. List of pending and completed delivery \n";
    std::cout << "\t4. LOGOUT\n\n";
}
void Courier::listOfOrders()
{
    std::string location;
    std::string Name, OrderID, Count, Courier, Type;
    cout << "1.Kochi\n2.Ernakulam\n";
ch:
    cout << "Enter choice :";
    getline(cin >> ws, choice);
    if (choice == "1")
    {
        location = "Kochi";
    }
    else if (choice == "2")
    {
        location = "Ernakulam";
    }
    else
    {
        std::cout << "       ===Not a valid choice !! Please retry.......===\n";
        goto ch;
    }

    std::string line, Location, Status1, defStatus = "Shipping";
    bool found = false, flag1 = false;
    int c = 0, d = 0;
    std::string delimiter = ";";
    ifstream in("orders.txt", ios::in);
    while (std::getline(in, line))
    {
        size_t pos = 0;
        std::string originalLine = line;
        std::string token;
        found = false;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            if (token.rfind("OrderID ", 0) == 0)
            {
                OrderID = token.substr(8);
            }
            if (token.rfind("Name ", 0) == 0)
            {
                Name = token.substr(5);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                Type = token.substr(5);
            }
            if (token.rfind("Count ", 0) == 0)
            {
                Count = token.substr(5);
            }
            if (token.rfind("Courier ", 0) == 0)
            {
                Location = token.substr(8);
                if (location == Location)
                {
                    found = true;
                }
            }
            if (token.rfind("Status ", 0) == 0 && found)
            {
                Status1 = token.substr(7);
                if (Status1 == defStatus)
                {
                    flag1 = true;
                    cout << "Order ID " << OrderID << " | "
                         << "Name " << Name << " | "
                         << "Type " << Type << " | "
                         << "Count " << Count << endl;
                    c++;
                }
            }
            line.erase(0, pos + delimiter.length());
        }
    }
    if (c == 0)
    {
        cout << "No Products have been assigned to deliver" << endl;
        return;
    }
    in.close();
}

void Courier::StatusUpdate()
{
    std::string Orderid;
    // listOfOrders();
////////////////////////////////////////////////////////////////
    std::string location;
    std::string Name1, OrderID1, Count1, Courier1, Type1;
    cout << "1.Kochi\n2.Ernakulam\n";
ch:
    cout << "Enter choice :";
    getline(cin >> ws, choice);
    if (choice == "1")
    {
        location = "Kochi";
    }
    else if (choice == "2")
    {
        location = "Ernakulam";
    }
    else
    {
        std::cout << "       ===Not a valid choice !! Please retry.......===\n";
        goto ch;
    }

    std::string line1, Location, Status1, defStatus = "Shipping";
    bool found = false, flag1 = false;
    int c = 0, d = 0;
    ifstream in("orders.txt", ios::in);
    while (std::getline(in, line1))
    {
        size_t pos = 0;
        std::string originalLine = line1;
        std::string delimiter=";";
        std::string token;
        found = false;
        while ((pos = line1.find(delimiter)) != std::string::npos)
        {
            token = line1.substr(0, pos);
            if (token.rfind("OrderID ", 0) == 0)
            {
                OrderID1 = token.substr(8);
            }
            if (token.rfind("Name ", 0) == 0)
            {
                Name1 = token.substr(5);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                Type1 = token.substr(5);
            }
            if (token.rfind("Count ", 0) == 0)
            {
                Count1 = token.substr(5);
            }
            if (token.rfind("Courier ", 0) == 0)
            {
                Location = token.substr(8);
                if (location == Location)
                {
                    found = true;
                }
            }
            if (token.rfind("Status ", 0) == 0 && found)
            {
                Status1 = token.substr(7);
                if (Status1 == defStatus)
                {
                    flag1 = true;
                    cout << "Order ID " << OrderID1 << " | "
                         << "Name " << Name1 << " | "
                         << "Type " << Type1 << " | "
                         << "Count " << Count1 << endl;
                    c++;
                }
            }
            line1.erase(0, pos + delimiter.length());
        }
    }
    if(c==0){
        cout<<"No Prducts to update"<<endl;
        return;
    }
///////////////////////////////////////
    cout << "Enter Order ID to be updated : ";
    getline(cin >> ws, Orderid);
    std::string OrderId, line;
    bool flag = false;
    int CourierChoice, count = 0;
    std::string delimiter = ";";
    ifstream courier("orders.txt", ios::in);
    ofstream temp("Temp.txt", ios::out);
    std::string OrderID, ProductID, Name, Type, Count, Status;
    while (std::getline(courier, line))
    {
        size_t pos = 0;
        std::string token, OriginalLine = line;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            if (token.rfind("OrderID ", 0) == 0)
            {
                OrderID = token.substr(8);
                if (OrderID == Orderid)
                {
                    flag = true;
                    count++;
                }
            }
            if (token.rfind("ProductID ", 0) == 0 && flag)
            {
                ProductID = token.substr(9);
            }
            if (token.rfind("Name ", 0) == 0 && flag)
            {
                Name = token.substr(5);
            }
            if (token.rfind("Type ", 0) == 0 && flag)
            {
                Type = token.substr(5);
            }
            if (token.rfind("Count ", 0) == 0 && flag)
            {
                Count = token.substr(6);
            }
            if (token.rfind("Status ", 0) == 0 && flag)
            {
                Status = token.substr(7);
            }
            line.erase(0, pos + delimiter.length());
        }
        switch (stoi(choice))
        {
        case 1:
            if (flag)
            {
                cout << "Updated Successfully......" << endl;
                temp << "OrderID " << OrderID << ";"
                     << "ProductID " << ProductID << ";"
                     << "Name " << Name << ";"
                     << "Type " << Type << ";"
                     << "Count " << Count << ";"
                     << "Courier "
                     << "Kochi"
                     << ";"
                     << "Status "
                     << "Delivered"
                     << ";" << endl;
                flag = false;
                break;
            }
            else
            {
                temp << OriginalLine << endl;
            }
            break;
        case 2:
            if (flag)
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
                     << "Delivered"
                     << ";" << endl;
                flag = false;
                break;
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
    if (count == 0)
    {
        cout << "No Orders to be updated....." << endl;
        return;
    }
    courier.close();
    temp.close();
    remove("orders.txt");
    rename("Temp.txt", "orders.txt");
}

void Courier::PendingAndDelivered()
{
    std::string stats;
    std::string Name, OrderID, ProductID, Count, Type;
    int choice;
W:
    std::cout << "\n1.List of Pending\n2.List of Delivered\n";
    std::cout << "Enter your choice :";
    cin >> choice;

    switch (choice)
    {
    case 1:
        std::cout << "\nOrders Pending\n";
        stats = "Shipping";
        break;

    case 2:
        std::cout << "\nOrders Delivered\n";
        stats = "Delivered";
        break;

    default:
        std::cout << "\n...Not a valid choice !! Please retry...\n";
        goto W;
    }

    std::string line, Stats;
    bool found = false;
    int i = 0;
    std::string delimiter = ";";
    ifstream temp("orders.txt", ios::in);
    while (std::getline(temp, line))
    {
        size_t pos = 0;
        std::string token;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);

            if (token.rfind("Name ", 0) == 0)
            {
                Name = token.substr(5);
            }
            if (token.rfind("ProductID ", 0) == 0)
            {
                ProductID = token.substr(9);
            }
            if (token.rfind("OrderID ", 0) == 0)
            {
                OrderID = token.substr(8);
            }
            if (token.rfind("Type ", 0) == 0)
            {
                Type = token.substr(5);
            }
            if (token.rfind("Count ", 0) == 0)
            {
                Count = token.substr(5);
            }
            if (token.rfind("Status", 0) == 0)
            {
                Stats = token.substr(7);
                if (stats == Stats)
                {
                    found = true;
                    i++;
                }
            }
            line.erase(0, pos + delimiter.length());
        }
        if (found)
        {
            std::cout << "OrderID " << OrderID << "|"
                      << " ProductID " << ProductID << "|"
                      << " Name " << Name << "|"
                      << " Type " << Type << "|"
                      << " Count " << Count << std::endl;
            found = false;
        }
    }
    if (i == 0)
    {
        cout << "No orders present...." << endl;
    }
    temp.close();
}