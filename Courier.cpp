#include "project.h"
void Courier::listOfOrders()
{
    std::string location, choice;
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
                cout << location << "location\n";
                cout << Location << "Location\n";

                if (location == Location)
                {
                    found = true;
                }
            }
            if (token.rfind("Name ", 0) == 0 && found)
            {
                std::cout << " |Name : " << token.substr(5);
            }
            if (token.rfind("Price ", 0) == 0 && found)
            {
                cout << " |"
                     << "Price : " << token.substr(6);
            }
            if (token.rfind("Type ", 0) == 0 && found)
            {
                cout << " |"
                     << "Type : " << token.substr(5) << endl;
            }
            line.erase(0, pos + delimiter.length());
        }
    }
    in.close();
}