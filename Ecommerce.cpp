#include "project.h"
fstream file;
void Authentication::CustomerRegistration(){
    string username , password , password_confirm;
 file.open("CustomerAuthentication.txt",ios::out|ios::app);
    cout<<"Enter your desired username (5-20 characters): ";
    getline(cin>>ws,username);
    cout<<"Enter password :";
    cin>>password;
    passwordStart:
    cout<<"Enter password to confirm :";
    getline(cin>>ws,password_confirm);
    if(password!=password_confirm){
          cout << "\nThe passwords do not match. Please enter a new password\n";
          goto passwordStart;
    }
    else{
        cout<<"Awesome....Your Registration is successful......"<<endl;
    }
    cout<<"Your USERID :"<<"\e[1m"<<username<<endl<<endl;
    file<<username<<" "<<password<<endl;
    file.close();
}



////////////////////////////////////////////////////////////////////////////////////

void Authentication::CustomerLogin()
{
        int count;
        string username,password,user,pass,condition;
        system("clear");
        cout<<"So Glad to see you back......."<<endl;
        cout<<"please enter the following details"<<endl;
        cout<<"\e[1m"<<"USERNAME :";
        cin>>username;
        retry:
        cout<<"\e[1m"<<"PASSWORD :";
        cin>>password;

        ifstream input("CustomerAuthentication.txt");
        while(input>>user>>pass)
        {
                if(user==username && pass==password)

                {
                        count=1;
                        system("clear");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
                // cin.get();
                // cin.get();
        }
        // else
        // {
        //         cout<<endl<<"LOGIN ERROR"<<endl;
        //         cout<<"********Would you like to reset your password?(Y/N) ";
        //         cin>>condition;
        //         if(condition=="y"||"Y")
        //             forgotPassword();
        //         else{
        //             goto retry;
        //         }
        // }
}

///////////////////////////////////////////////////////////////////////////////////////////////
// void forgotPassword(){
//     string username , u ,password,line;
//     int count;
//      cout<<"please enter the following details"<<endl;
//         cout<<"\e[1m"<<"USERNAME :";
//         cin>>username;
//         ifstream input("CustomerAuthentication.txt");
//           while(input>>u)
//         {
//                 if(u==username)

//                 {
//                         count=1;
//                         system("clear");
//                 }
//                 if(count==1){
//                     cout<<"Enter your new password : ";
//                     cin>>password;
//                 }
//                 ofstream output("temp.txt");
//                 output<<username<<" "<<password;
//         }
//         input.close();
        


// }

/////////////////////////////////////////////////////////////////////////////




void Authentication::MerchantLogin()
{
        int count;
        string username,password,u,p,condition;
        system("clear");
        cout<<"Hello Merchant..........So Glad to see you back......."<<endl;
        cout<<"please enter the following details"<<endl;
        cout<<"\e[1m"<<"USERNAME :";
        cin>>username;
        retry:
        cout<<"\e[1m"<<"PASSWORD :";
        cin>>password;

        ifstream input("merchantAuthentication.txt");
        while(input>>u>>p)
        {
                if(u==username && p==password)

                {
                        count=1;
                        system("clear");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nLOGIN SUCESS\nWe're glad that you're here.\n";
                // cin.get();
                // cin.get();
        }
}




///////////////////////////////////////////////////////////////////////




void Authentication::CourierLogin()
{
        int count;
        string username,password,u,p,condition;
        system("clear");
        cout<<"So Glad to see you back......."<<endl;
        cout<<"please enter the following details"<<endl;
        cout<<"\e[1m"<<"USERNAME :";
        cin>>username;
        retry:
        cout<<"\e[1m"<<"PASSWORD :";
        cin>>password;

        ifstream input("CourierAuthentication.txt");
        while(input>>u>>p)
        {
                if(u==username && p==password)

                {
                        count=1;
                        system("clear");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\nLOGIN SUCESS\nThanks for being a partner with us \n";
                // cin.get();
                // cin.get();
        }
}

////////////////////////////////CUSTOMER PART////////////////////////////////////////////////////////////////////////////
ifstream customer("products.txt",ios::in);
ofstream buy("orders.txt",ios::out|ios::in|ios::app);
void Customer::CustomerChoiceDisplay(){
// ostream customerb("temp.txt");
std::cout<<"What would you like to buy\n";
        std::cout<<"1.Electronics\n";
        std::cout<<"2.Furniture\n";
        std::cout<<"3.Clothings\n";
        std::cout<<"Enter your choice : ";
        std::cin>>customerChoice;
        switch(customerChoice){
            case 1 :
            subString="ele";
            CustomerCondition();
                break;

         case 2 :
            subString="furniture";
            CustomerCondition();
            
                break;
        case 3 :
        subString="clothes";
        CustomerCondition();
        break;
}
}
///////////////////////////////////////////////////////////

void Customer::CustomerCondition(){
    do{
    if(line.find(subString)!=std::string::npos)
                cout<<line<<"\n";
                }while(getline(customer,line));
}



