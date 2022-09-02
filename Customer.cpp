#include"project.h"
ifstream customer("products.txt",ios::in);
ofstream buy("orders.txt",ios::out|ios::in|ios::app);
void Customer::CustomerChoiceDisplay(){
// ostream customerb("temp.txt");
// std::cout<<"What would you like to buy\n";
//        

///////////////////////////////////////////////////
 std::string line1, name, price;
    std::string delimiter = ";";
    ifstream in("products.txt",ios::in);
    while (std::getline(in, line1))
    {
        size_t pos = 0;
        std::string token;
        while ((pos = line1.find(delimiter)) != std::string::npos)
        {
            token = line1.substr(0, pos);
            if (token.rfind("Name ", 0) == 0)
            {
                std::cout<<"Name : "<<token.substr(5);
            }
            if(token.rfind("Price ",0)==0){
                cout<<" |"<<"Price : "<<token.substr(6)<<endl;
            }
            //  if(token.rfind("Count ",0)==0){
            //     cout<<" |"<<"Count : "<<token.substr(5)<<endl;
            // }
            line1.erase(0,pos+delimiter.length());
}
    }
    in.close();
}