// #include "project.h"




// void Courier :: orderDetails()
// {
//    std::cout<<"------ORDER DETAILS------\n";
//    std::ofstream Orderfile;
//    Orderfile.open("order.txt",std::ios::app);
//    while(Orderfile.is_open())
//    {

//     std::cout<<"Enter the product ID ";
//     getline(std::cin>>ws,productId);
//     Orderfile<<"productId "<<productId<<";";
//     std::cout<<"Enter the product name:"<<std::endl;
//     getline(std::cin>>ws,productName);
//     Orderfile<<"productName"<<productName<<";";
//     std::cout<<"Enter the product price";
//     getline(std::cin>>ws,Price);
//     Orderfile<<"Price "<<Price<<";";
//     std::cout<<"Enter the product type:"<<std::endl;
//     getline(std::cin>>ws,Type);
//     Orderfile<<"Type "<<Type<<";";
//     std::cout<<"Enter the product count:"<<std::endl;
//     getline(std::cin>>ws,Count);
//     Orderfile<<"Count "<<Count<<";"<<endl;
//     Orderfile.close();
    
//    }

// }

// void Courier ::orderStatus()

// {

//     std:: string line1;
//     std:: string delimiter=";";
//     ifstream Orderfile("order.txt",ios::in);
//     ofstream statusFile("delivered.txt",ios::out | ios::app);
//     while (std::getline(Orderfile,line1))
//     {
//       std:: string ProductIds;
//       size_t pos=0;
//       std:: string token;
//       while ((pos=line1.find(delimiter)) !=std:: string::npos)
//       {
//         token = line1.substr(0,pos);
//         if (token.rfind("productId",0)==0)
//         {
//            ProductIds=token.substr(10);
//         }
//         line1.erase(0, pos + delimiter.length());
//       }
//       std::cout<<"productId"<<ProductIds<<"\t Status:"<<"\t pending"<<std::endl;
//     }


//   //  ifstream Orderfile("order.txt",ios::in);
//   //  ofstream statusFile("delivered.txt",ios::out | ios::app);
//   //  std::cout << "List of assigned orders" << std::endl;
//   //  std::string details;
//   //  if (Orderfile && statusFile)
//   //   {
//   //    while (getline (Orderfile, details))
//   //     {
//   //       statusFile << details<<"\n";
//   //     }
//   //     //replace()
//   //   }
//   //    else
//   //   {
//   //    std::cout<<"No orders";
//   //   }
//   //   Orderfile.close();

// }


// void Courier :: assignedOrders()
// {
  
//    ifstream Orderfile("order.txt",ios::in);
//    ofstream orderdetailsFile("details.txt",ios::out | ios::app);
//    std::cout << "List of assigned orders" << std::endl;
//    std::string details;
//    if (Orderfile && orderdetailsFile)
//     {
//      while (getline (Orderfile, details))
//       {
//         orderdetailsFile << details<<"\n";
//         std:: cout<<details;
//       }
//     }
//      else
//     {
//      std::cout<<"No orders";
//     }
//     Orderfile.close();


// }

// //void Courier :: updateDelivery()  

