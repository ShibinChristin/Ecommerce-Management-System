#include "project.h"
int main()
{
    string choice, options, CustChoice;
    string MerchantChoice, merchoice;
    string CourierChoice, courierChoice;
    Authentication auth;
    Customer cust;
    Products Mer;
    Courier C;
    std::regex m("^[1-9]$");
sgain:
    cout << endl;
    cout << "*******************************************************************************\n\n";
    cout << "                          Welcome to ShopTronics                               \n\n";
    cout << "****************************       MENU        ********************************\n\n";
    cout << "1.Customer\n";
    cout << "2.Merchant\n";
    cout << "3.Courier\n";
    cout << "4.Exit\n";
    cout << "\n";
    cout << "\nEnter your choice : ";
    cout << "\n";
    cin >> choice;
    if (!(regex_match(choice, m)))
    {
        cout << "Invalid Choice .....Please try again\n";
        goto sgain;
    }
    int Choice = stoi(choice);
    cout << endl;
    switch (Choice)
    {
    case 1:
    C:
        // system("clear");
        cout << "********************************************************************************\n\n";
        cout << "                          Welcome to Customer Portal                             \n\n";
        cout << "****************************        MENU        ********************************\n\n";
        cout << "1.Login\n";
        cout << "2.Register\n";
        cout << "3.Previous Menu\n";
        cout << "Enter choice : ";
        cin >> CustChoice;
        if (!(regex_match(CustChoice, m)))
        {
            cout << "Invalid Choice .....Please try again\n";
            goto C;
        }

        switch (stoi(CustChoice))
        {
        case 1:
            auth.CustomerLogin();
        Coptions:
            cust.CustomerChoiceDisplay();
            cout << "Enter choice : ";
            cin >> options;
            if (!(regex_match(options, m)))
            {
                cout << "Invalid Choice .....Please try again\n";
                goto Coptions;
            }
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
                goto Coptions;
                break;
            case 3:
                system("clear");
                cust.orderStatus();
                goto Coptions;
            case 4:
                cust.CancelOrder();
                goto Coptions;
                break;
            case 5:
                goto sgain;
                break;
            default:
                cout << "Invalid Choice....!! PLease try again\n";
                goto Coptions;
            }

        case 2:
            auth.CustomerRegistration();
            goto C;
            break;

        case 3:
            goto sgain;
            break;

        default:
            cout << "Invalid choice...!!Please try again\n";
            cout << "\n";
            goto C;
            break;
        }
    case 2:

    mgain:
        // system("clear");
        cout << "*****************************************************************************\n\n";
        cout << "                      Welcome to Merchant Portal                             \n\n";
        cout << "*****************************************************************************\n\n";
        cout << "1.Login\n";
        cout << "2.Register\n";
        cout << "3.Previous Menu\n";
        cout << "Enter choice : \n";
        cin >> MerchantChoice;
        // system("clear");
        if (!(regex_match(MerchantChoice, m)))
        {
            cout << "Invalid Choice....!!Please try again\n";
            goto mgain;
        }
        switch (stoi(MerchantChoice))
        {
        case 1:
            auth.MerchantLogin();
        mopt:
            Mer.merchantOptions();
            cout << "\nEnter your choice :";
            cin >> merchoice;
            if (!(regex_match(merchoice, m)))
            {
                cout << "Invalid Choice !!.....Please try again\n";
                goto mopt;
            }
            switch (stoi(merchoice))
            {
            case 1:
                system("clear");
                Mer.addProducts();
                goto mopt;
                break;

            case 2:
                system("clear");
                Mer.searchProducts();
                goto mopt;
                break;

            case 3:
                system("clear");
                Mer.OrderStatusView();
                goto mopt;
                break;

            case 4:
                system("clear");
                Mer.displayOutofStock();

                goto mopt;
                break;

            case 5:
                system("clear");
                Mer.CancelledProducts();
                goto mopt;
                break;

            case 6:
                system("clear");
                Mer.AssignCourier();
                goto mopt;
                break;

            case 7:
                goto mgain;
                break;

            default:
                cout << "Invalid Choice......!! Please Try again\n";
                goto mopt;
                break;
            }
            break;
        case 2:
            auth.MerchantRegistration();
            goto mgain;
            break;
        default:
            goto sgain;
            break;
        }
        break;
    case 3:
        // system("clear");
        cout << "******************************************************************************\n\n";
        cout << "                        Welcome to Courier Portal                             \n\n";
        cout << "******************************************************************************\n\n";
    dopt:
        cout << "1.Login\n";
        cout << "2.Register\n";
        cout << "3.Previous Menu\n";
        cout << "Enter choice : \n";
        cin >> CourierChoice;
        if (!(regex_match(CourierChoice, m)))
        {
            cout << "Invalid Choice !!.....Please try again\n";
            goto dopt;
        }
        switch (stoi(CourierChoice))
        {
        case 1:
            auth.CourierLogin();
        copt:
            C.courierOptions();
            cout << "\nEnter your choice: ";
            cin >> courierChoice;
            if (!(regex_match(courierChoice, m)))
            {
                cout << "Invalid Choice !!.....Please try again\n";
                goto copt;
            }
            switch (stoi(courierChoice))
            {
            case 1:
                system("clear");
                C.listOfOrders();
                goto copt;
                break;
            case 2:
                C.StatusUpdate();
                goto copt;
                break;
            case 3:
                system("clear");
                C.PendingAndDelivered();
                goto copt;
                break;
            case 4:
                goto sgain;
                break;
            default:
                cout << "Invalid choice !!......Please Try again\n";
                goto copt;
                break;
            }
            break;
        case 2:
            auth.CourierRegistration();
            goto dopt;
            break;

        case 3:
            goto sgain;
            break;

        default:
            cout << "Invalid Choice !!...Please try again\n";
            goto sgain;
            break;
        }
    case 4:
        cout << "Thank you for shopping" << endl;
        exit(0);
    default:
        cout << "Invalid choice.....!" << endl;
        goto sgain;
    }
    return 0;
}
