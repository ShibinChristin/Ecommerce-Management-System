#include "project.h"
int main()
{
    int choice;
start:
    cout << "***********************************************************************\n\n";
    cout << "                         Welcome to ShopTronics                               \n\n";
    cout << "**************************        MENU        ********************************\n\n";
    cout << "1.Customer\n";
    cout << "2.Merchant\n";
    cout << "3.Courier\n";
	cout << "\nEnter your choice : ";
    cin >> choice;
    cout << endl;
    Authentication auth;
    Customer cust;
    Products Mer;
    // int i = 3;
    switch (choice)
    {
    case 1:
        int CustomerChoice;
        //system("clear");
        cout << "***********************************************************************\n\n";
        cout << "                      Welcome to Customer Portal                             \n\n";
        cout << "*******************        MENU        ********************************\n\n";
        cout << "1.Login\n";
        cout << "2.Register\n";
        cout <<  "3.Go Back\n";
        cout << "Enter choice : ";
        cin >> CustomerChoice;
        if (CustomerChoice == 1)
        {
            auth.CustomerLogin();
            sleep(1);
            //system("clear");
            cust.CustomerChoiceDisplay();
            std::string Cusoptions;
            cout << "Enter choice : ";
            cin >> Cusoptions;
            switch (stoi(Cusoptions))
            {
            case 1:
                //system("clear");
                cust.CustomerBuy();
                break;
            case 2:
                // cust.showProducts();
                break;
            case 3:
                //system("clear");
                cust.orderStatus();
                break;
            case 4:
                //cust.cancelOrder();
                break;
            case 5:
                goto start;
                break;

            
            }
        }
        else if (CustomerChoice == 2)
        {
            auth.CustomerRegistration();
            cust.CustomerChoiceDisplay();
        }
        else if(CustomerChoice==3)
        {
            goto start;
        }
        else
        {
            cout<<"Invalid Choice...!!...Please try again\n";
        }
        break;
    case 2:
        
        
        cout << "***********************************************************************\n\n";
        cout << "                      Welcome to Merchant Portal                             \n\n";
        //system("clear");
        int MerchantChoice;
        cout << "1.Login\n";
        cout << "2.Register\n";
        cout << "3.Go Back\n";
        cout << "Enter choice : ";
        cin >> MerchantChoice;
        if(MerchantChoice==1)
        {
            auth.MerchantLogin();
        }
        else if(MerchantChoice==2)
        {
            auth.MerchantRegistration();
        }
        else if(MerchantChoice ==3)
        {
            goto start;
        }
        else
            cout<<"Invalid Choice\n";
        //sleep(1);
        //system("clear");
    //a:
        Mer.merchantOptions();
        cout << "Enter your choice :";
        cin >> MerchantChoice;
        if (MerchantChoice == 1)
        {
            //system("clear");
            Mer.addProduct();
            
        }
        else if (MerchantChoice == 2)
        {
            //system("clear");
            Mer.searchProducts();
            //goto a;
            Mer.
        }
        else if(MerchantChoice==3)
        {
            Mer.OutofStockProducts();
        }
        else if(MerchantChoice ==4)
        {
            //Mer.cancelledOrders();
        }
        else if(MerchantChoice==5)
        {
            Mer.orderStatus();
        }
        break;
    case 3:
        cout << "***********************************************************************\n\n";
        cout << "                      Welcome to Courier Portal                             \n\n";
        //system("clear");
        int CourierChoice;
        cout << "1.Login\n";
        cout << "2.Register\n";
        cout << "Enter choice : \n";
        cin >> CourierChoice;
        if(CourierChoice==1)
        {
            auth.CourierLogin();
        }
        
        break;
    
    default:
        cout << "Invalid Choice....." << endl;
        goto start;
        return 0;
    }
}
