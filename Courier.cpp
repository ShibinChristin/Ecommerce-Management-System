#include "project.h"
void Courier::listOfOrders()
{
    std::string location, choice;
    std::string Name, OrderID, Count, Courier, Type;
    cout << "1.Kochi\n2.Ernakulam\n ";
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
            if (token.rfind("Name ", 0) == 0 && found)
            {
                Name = token.substr(5);
            }
            if (token.rfind("OrderID ", 0) == 0 && found)
            {
                Name = token.substr(8);
            }
            if (token.rfind("Type ", 0) == 0 && found)
            {
                Type = token.substr(5);
            }
            if (token.rfind("Count ", 0) == 0 && found)
            {
                Count = token.substr(5);
            }
            line.erase(0, pos + delimiter.length());
        }
        if(found==false){
            cout<<"Order ID "<<OrderID<<" | "<<"Name "<<Name<<" | "<<"Type "<<Type<<" | "<<"Count "<<Count<<endl;
            break;
        }
    }

    in.close();
}

void Courier::StatusUpdate()
{
    std::string location, choice;
    cout << "*********************Status Updater*********************\n";
    cout << "1.Kochi\n2.Ernakulam\n ";
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
}