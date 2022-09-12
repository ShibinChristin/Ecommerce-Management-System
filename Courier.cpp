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

    std::string line, Location;
    bool found = false;
    std::string delimiter = ";";
    ifstream in("orders.txt", ios::in);
    while (std::getline(in, line))
    {
        size_t pos = 0;
        std::string token;
        while ((pos = line.find(delimiter)) != std::string::npos)
        {
            token = line.substr(0, pos);
            if (token.rfind("Courier ", 0) == 0)
            {
                Location = token.substr(8);
                if (location == Location)
                {
                    found = true;
                }
            }
            if (token.rfind("Name ", 0) == 0)
            {
                Name = token.substr(5);
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
            line.erase(0, pos + delimiter.length());
        }
        if (found)
        {
            cout << "Order ID " << OrderID << " | "
                 << "Name " << Name << " | "
                 << "Type " << Type << " | "
                 << "Count " << Count << endl;
            found = false;
            break;
        }
    }

    in.close();
}

void Courier::StatusUpdate()
{
    std::string Orderid;
    listOfOrders();
    cout << "Enter Order ID to be updated : ";
    getline(cin >> ws, Orderid);
    std::string OrderId, line;
    bool flag = false;
    int CourierChoice;
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
    courier.close();
    temp.close();
    remove("orders.txt");
    rename("Temp.txt","orders.txt");
}

void Courier::PendingAndDelivered()
{
    ifstream in("orders.txt", ios::in);
    std::string delimiter = ";";
    std::string OrderID, Name, Type, Count, Status;
    std::string line;
    while (std::getline(in, line))
    {
        size_t pos = 0;
        std::string token;

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
                Count = token.substr(6);
            }
            if (token.rfind("Status ", 0) == 0)
            {
                Status = token.substr(7);
            }
            line.erase(0, pos + delimiter.length());
        }
        cout << "Order ID " << OrderID<<" | "<<"Name "<<Name<<" | "<<"Type "<<Type<<" | "<<"Status :"<<Status<<endl;
    }
}