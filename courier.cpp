#include"project.h"
void Courier ::orderStatus()




{

   ifstream Orderfile("order.txt",ios::in);

   ofstream assignedorderFile("delivered.txt",ios::out | ios::app);

   std::cout << "List of assigned orders" << std::endl;

   std::string details;

   if (Orderfile && assignedorderFile)

    {

     while (getline (Orderfile, details))

      {

        assignedorderFile << details<<"\n";

      }

      //replace()

    }

     else

    {

     std::cout<<"No orders";

    }

    Orderfile.close();



}