#include "project.h"

int main()
{
    int choice;
    Authentication auth;
    Customer cust;
    Products Mer;
    Courier C;
    std::regex m("^[1-3]$");
sgain:
    cout << "***********************************************************************\n\n";
    cout << "                      Welcome to ShopTronics                               \n\n";
    cout << "*******************        MENU        ********************************\n\n";
    cout << "1.Customer\n";
    cout << "2.Merchant\n";
    cout << "3.Courier\n";
    cout << "4.Exit\n";
    cout << "\nEnter your choice : ";
    cin >> choice;

    cout << endl;
    switch (choice)
    {
    case 1:
        int CustomerChoice;
        system("clear");
        cout << "***********************************************************************\n\n";
        cout << "                      Welcome to Customer Portal                             \n\n";
        cout << "*******************        MENU        ********************************\n\n";
        cout << "1.Login\n";
        cout << "2.Register\n";
        cout << "3.Previous Menu\n";
        cout << "Enter choice : ";
        cin >> CustomerChoice;
        if (CustomerChoice == 1)
        {
            auth.CustomerLogin();
            sleep(1);
            system("clear");
        Coptions:
            cust.CustomerChoiceDisplay();
            std::string options;
            cout << "Enter choice : ";
            cin >> options;
            switch (stoi(options))
            {
            case 1:
                system("clear");
                cust.CustomerBuy();
                goto Coptions;
                break;
            case 2:
                system("clear");
                cust.showProducts();
                sleep(3);
                goto Coptions;
                break;
            case 3:
                system("clear");
                cust.orderStatus();
                sleep(3);
                goto Coptions;
            case 4:
                cust.CancelOrder();
                sleep(5);
                goto Coptions;
                break;
            default:
                //    if(stoi(options)==5){
                goto sgain;
                //    }
            }
        }
        if (CustomerChoice == 2)
        {
            auth.CustomerRegistration();
            goto Coptions;
            break;
        }
        if (CustomerChoice == 3)
        {
            goto sgain;
            break;
        }
        break;
    case 2:
        int MerchantChoice, merchoice;
    mgain:
        cout << "***********************************************************************\n\n";
        cout << "                      Welcome to Merchant Portal                             \n\n";
        cout << "1.Login\n";
        cout << "2.Register\n";
        cout << "3.Previous Menu\n";
        cout << "Enter choice : ";
        cin >> MerchantChoice;
        system("clear");
        switch (MerchantChoice)
        {
        case 1:
            auth.MerchantLogin();
            sleep(1);
            system("clear");
        mopt:
            Mer.merchantOptions();
            cout << "Enter your choice :";
            cin >> merchoice;
            if (merchoice == 1)
            {
                system("clear");
                Mer.addProduct();
                goto mopt;
            }
            if (merchoice == 2)
            {
                system("clear");
                Mer.searchProducts();
                goto mopt;
            }
            if (merchoice == 3)
            {
                system("clear");
                Mer.OrderStatusView();
                sleep(4);
                goto mopt;
            }
            if (merchoice == 4)
            {
                system("clear");
                Mer.displayOutofStock();
                sleep(4);
                goto mopt;
            }
             if (merchoice == 5)
            {
                system("clear");
                Mer.CancelledProducts();
                sleep(4);
                goto mopt;
            }
            if (merchoice == 6)
            {
                system("clear");
                Mer.AssignCourier();
                sleep(4);
                goto mopt;
            }
            if (merchoice == 7)
            {
                goto mgain;
            }
            else
            {
                cout << "Invalid Choice......Try again\n";
                sleep(2);
                goto mopt;
            }
            break;
        // case 2:
        //     auth.MerchantRegistration();
        //     goto mopt;
        //     break;
        default:
            goto sgain;
            break;
        }
        break;
    case 3:
        int courierChoice;
        cout << "***********************************************************************\n\n";
        cout << "                      Welcome to Courier Portal                             \n\n";
        // system("clear");
        int CourierChoice;
    dopt:
        cout << "1.Login\n";
        cout << "2.Register\n";
        cout << "3.Previous Menu\n";
        cout << "Enter choice : ";
        cin >> CourierChoice;
        switch (CourierChoice)
        {
        case 1:
            auth.CourierLogin();
            sleep(1);
        copt:
            C.courierOptions();
            cout << "Enter your choice: ";
            cin >> courierChoice;
            switch (courierChoice)
            {
            case 1:
                system("clear");
                C.listOfOrders();
                sleep(4);
                goto copt;
                break;
            case 2:
                C.StatusUpdate();
                sleep(3);
                goto copt;
                break;
            case 3:
                system("clear");
                C.PendingAndDelivered();
                sleep(3);
                goto copt;
                break;
            case 4:
                goto sgain;
                break;
            default:
                cout << "Invalid choice.......Try again\n";
                goto copt;
                break;
            }
            break;
            // case 2:
            //     auth.CourierRegistration();
            //     goto dopt;
            //     break;
        }
    default:
        cout << "Thank you for visiting.............\n";
        break;
    }
    //     //default:
    //         // std::string choice1 = to_string(choice);
    //         //   regex e("^[^4]+$");
    //         // if (!(regex_match(e, choice1))){
    //         //     cout<<"Not Valid number....\n";
    //         //   }
    //         break;
    // }
    return 0;
}
