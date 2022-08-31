#include "project.h"
int main(){
int choice;
Authentication auth; 
 cout<<"***********************************************************************\n\n";
        cout<<"                      Welcome to ShopTronics                               \n\n";
        cout<<"*******************        MENU        ********************************\n\n";
        cout<<"1.Customer\n";
        cout<<"2.Merchant\n";
        cout<<"3.Courier\n";
        cout<<"\nEnter your choice : ";
        cin>>choice;
        cout<<endl;
switch(choice){
case 1:
    int CustomerChoice;
    system("clear");
    cout<<"***********************************************************************\n\n";
        cout<<"                      Welcome to Customer Portal                             \n\n";
        cout<<"*******************        MENU        ********************************\n\n";
        cout<<"1.Login\n";
        cout<<"2.Register\n";
        cout<<"Enter choice : ";
        cin>>CustomerChoice;
        if(CustomerChoice==1){
         auth.CustomerLogin();
        sleep(2);
        system("clear");
        cust.CustomerChoiceDisplay();                    
        }
        if(CustomerChoice==2){auth.CustomerRegistration();}
    break;
case 2:
 cout<<"***********************************************************************\n\n";
        cout<<"                      Welcome to Merchant Portal                             \n\n";
        system("clear");
        auth.MerchantLogin();
break;
case 3:
cout<<"***********************************************************************\n\n";
        cout<<"                      Welcome to Courier Portal                             \n\n";
        system("clear");
        auth.CourierLogin();
        break;


    return 0;
}
}
