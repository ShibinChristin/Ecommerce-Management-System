#include"project.h"
void Products::addProduct(){
   std :: cout <<"Enter the Merchant ID : ";
    getline(std::cin >> ws, merchantId);
    std :: cout <<"\nEnter the Product ID : ";
    getline(std::cin >> ws, productId);
    std :: cout <<"\nEnter the Name of the Product : ";
    getline(std::cin >> ws, productName);
    std :: cout <<"\nEnter the Price of the Product : ";
    getline(std::cin >> ws, productPrice);
    choice:
    std :: cout <<"\nEnter the Type of the Product \n1.Electronics\n2.Furniture\n3.Clothings : ";
//     getline(std::cin >> ws, productType);
        cin>>productChoice;
        if(productChoice==1){
                productType="Electronics";
        }
        else if(productChoice==2){
                productType="Furniture";
        }
        else if(productChoice==3){
                productType="Fashion";
        }
        else{
                cout<<"Wrong choice....Enter Again!!";
                goto choice;
        }
    std :: cout <<"\nThe number of available " << productType << " Products: ";
    getline(std::cin >> ws, productCount);

    fstream merchant_file;
    merchant_file.open("products.txt", std::ios::out | std::ios::app);
    merchant_file <<"Merchant ID "<<merchantId << ";"<<"Product ID "<< productId << ";"<<"Name "<<productName << ";" <<"Price "<< productPrice << ";" <<"Type "<<productType <<";"<<"Count "<< productCount<<";"<<endl;
    cout <<"\n";
    merchant_file.close();
    cout<<"Would you like to continue?(Y/N) ";
    std::string choice;
    if(choice=="Y"||choice=="y"){
                addProduct();
    }
    else{
        merchantOptions();
    }

}
void Products::merchantOptions(){
     cout<<"*******************        MENU        ********************************\n\n";
        cout<<"1.Add Products\n";
        cout<<"2.Assign Delivery to Courier\n";
        cout<<"3.Canceled Orders\n";
        cout<<"4.Order Status\n"<<endl;

}
