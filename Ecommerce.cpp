#include "project.h"
void Authentication::mainMenu()
{	
	Customer customerObj;
	Merchant merchantObj;
	Courier courierObj;
	std::string choice;
	cout << "\n\n*******************************************************************************\n\n";
    cout << "                           Welcome to ShopTronics                               \n\n";
    cout << "****************************       MENU        ********************************\n\n";
    cout << "1.Customer\n";
    cout << "2.Merchant\n";
    cout << "3.Courier\n";
    cout << "4.Exit\n";
    cout << "\n";
    cout << "Enter your choice : ";
    cout << "\n";
    cin >> choice;
	std::regex f("^[1-4]$");

    if (!(regex_match(choice, f)))
    {
        cout << "\nInvalid Choice .....Please try again\n";
        mainMenu();
    }
	switch(stoi(choice))
	{
		case 1:
		customerObj.customerMenu();
		break;
		
		case 2:
		merchantObj.merchantMenu();
		break;

		case 3:
		courierObj.courierMenu();
		break;
		
		case 4:
		cout<<"\n.....Thank you for Shopping.....\n\n";
		exit(0);

	}
}
int Authentication::idGeneration()
{
	int id;
	srand(time(0));		   // srand() initialize random number generators
	id = rand() % 100 + 1; // generate random numbers
	return id;
}
void Authentication::customerRegistration()
{
	std::regex s("^[a-zA-Z0-9\\s]+$");

	cout << "Enter your desired username : ";
	getline(cin >> ws, username1);
	if (!(regex_match(username1, s)))
	{
		std::cout << "\n";
		std::cout << "       ===Invalid name! Please try again.===\n";
		std::cout << "\n";
		customerRegistration();
	}
	
	ifstream in1;
	bool customerUsername = false;
	in1.open("CustomerAuthentication.txt", ios::in);
	while (std::getline(in1, line1))
	{
		std::string token = line1.substr(0, pos);

		if (line1.find(username1) != string::npos)
		{
			customerUsername = true;
		}
		line1.erase(0, pos + delimiter.length());
	}

	if (customerUsername)
	{
		cout << "Username already exists" << endl;
		customerUsername = false;
		mainMenu();
		
	}

	in1.close();
	fstream file1;
	file1.open("CustomerAuthentication.txt", ios::in | ios::out | ios::app);
	cout << "Enter password :";
	cin >> password1;
passwordStart:
	cout << "Enter password to confirm :";
	getline(cin >> ws, password_confirm1);

	if (password1 != password_confirm1)
	{
		cout << "\nThe passwords do not match. Please enter a new password\n";
		goto passwordStart;
	}
	else
	{
		cout << "Awesome....Your Registration is successful......" << endl;
	}
	cout << "Your USERNAME :"
		 << username1 << endl;
	file1 << "Username " << username1 << ";"
		  << "Password " << password1 << ";"
		  << "CustomerID " << idGeneration() << ";" << endl;
	file1.close();
	cout << "\n";
	
	}

////////////////////////////////////////////////////////////////////////////////////

void Authentication::customerLogin()
{
	int cAuthenticate = 0;
	bool ifound = false, flag = false;
	std::string line5, token, CustomerID, pass;
	std::string ChecK_name;
	cout << "Hello Customer...\nSo Glad to see you back......." << endl;

	cout << "Please enter the following details" << endl;
	cout << "USERNAME :";
	cin >> username1;
	cout << "PASSWORD :";
	cin >> password1;

	ifstream input("CustomerAuthentication.txt", ios::in);
	ofstream cId("customerId.txt", ios::out);
	while (getline(input, line5))
	{
		while ((pos = line5.find(delimiter)) != std::string::npos)
		{
			token = line5.substr(0, pos);

			if (token.rfind("Username ", 0) == 0)
			{
				ChecK_name = token.substr(9);
				if (username1 == ChecK_name)
				{
					ifound = true;
				}
			}
			if (token.rfind("Password ", 0) == 0 && ifound)
			{
				pass = token.substr(9);
				if(pass == password1)
				{
					flag = true;
					cAuthenticate++;
				}
			}
			if (token.rfind("CustomerID ", 0) == 0 && ifound)
			{
				CustomerID = token.substr(11);
			}
			line5.erase(0, pos + delimiter.length());
		}
		if (flag)
		{
			cout << "\nLOGIN SUCCESSFUL...\nWe're glad that you're here.\nThanks for logging in\n";
			flag = false;
			cId << CustomerID << endl;
		}
		ifound = false;
	}
	if (cAuthenticate == 0) 
	{
		std::cout << "\n";
		std::cout << "       ===Invalid Username or password! Please try again.===\n";
		std::cout << "\n";
		mainMenu();
	}
	input.close();
	
}
/////////////////////////////////////////////////////////////////////////////////////////

void Authentication::merchantRegistration()
{
	string username2, password2, password_confirm2;

	std::regex s("^[a-zA-Z0-9\\s]+$");

	cout << "Enter your desired username : ";
	getline(cin >> ws, username2);
	if (!(regex_match(username2, s)))
	{
		std::cout << "\n";
		std::cout << "===Invalid name! Please try again.===\n";
		std::cout << "\n";
		merchantRegistration();
	}

	ifstream in2;
	bool found = false;
	in2.open("merchantAuthentication.txt", ios::in);
	while (std::getline(in2, line2))
	{
		if (line2.find(username2) != string::npos)
		{
			found = true;
		}
		line2.erase(0, pos + delimiter.length());
	}
	if (found)
	{
		cout << "Username already exists" << endl;
		found = false;
		mainMenu();
	}
	in2.close();
	fstream file2;
	file2.open("merchantAuthentication.txt", ios::out | ios::app);

	cout << "Enter password :";
	cin >> password2;
promptPassword:
	cout << "Enter password to confirm :";
	getline(cin >> ws, password_confirm2);
	if (password2 != password_confirm2)
	{
		cout << "\nThe passwords do not match. Please enter a new password\n";
		goto promptPassword;
	}
	else
	{
		cout << "Awesome....Your Registration is successful......" << endl;
	}
	cout << "Your USERNAME :"
		 << username2 << endl;
	file2 << "Username " << username2 << ";"
		  << "Password " << password2 << ";"
		  << "MerchantID " << idGeneration() << ";" << endl;
	file2.close();
	cout << "\n";
	
}

void Authentication::merchantLogin()
{
	int mAuthenticate = 0;
	bool ifound = false, flag = false;
	std::string line6, token, MerchantID, pass;
	std::string Check_name;
	string username2, password2, u, p, condition;
	cout << "Hello Merchant..........So Glad to see you back......." << endl;

	cout << "Please enter the following details" << endl;
	cout << "USERNAME :";
	cin >> username2;
	cout << "PASSWORD :";
	cin >> password2;

	ifstream merchantFile("merchantAuthentication.txt");
	ofstream mId("merchantId.txt", ios::out);
	while (getline(merchantFile, line6))
	{

		while ((pos = line6.find(delimiter)) != std::string::npos)
		{
			token = line6.substr(0, pos);

			if (token.rfind("Username ", 0) == 0)
			{
				Check_name = token.substr(9);
				if (username2 == Check_name)
				{
					ifound = true;
				}
			}
			if (token.rfind("Password ", 0) == 0 && ifound)
			{
				pass = token.substr(9);
				if(pass == password2)
				{
					flag = true;
					mAuthenticate++;
				}
			}
			if (token.rfind("MerchantID ", 0) == 0 && ifound)
			{
				MerchantID = token.substr(11);
			}
			line6.erase(0, pos + delimiter.length());
		}
		if (flag)
		{
			cout << "\nLOGIN SUCCESSFUL...\nWe're glad that you're here.\nThanks for logging in\n";
			flag = false;
			mId << MerchantID <<endl;
		}
		ifound = false;
	}
	if (mAuthenticate == 0)
	{
		std::cout << "\n";
		std::cout << "       ===Invalid Username or password! Please try again.===\n";
		std::cout << "\n";
		mainMenu();
		
	}
	merchantFile.close();
	}

///////////////////////////////////////////////////////////////////////

void Authentication::courierRegistration()
{
	
	count = 0;
	std::regex s("^[a-zA-Z0-9\\s]+$");
	cout << "Enter your desired username : ";
	getline(cin >> ws, username3);
	if (!(regex_match(username3, s)))
	{
		std::cout << "\n";
		std::cout << "===Invalid name! Please try again.===\n";
		std::cout << "\n";
		courierRegistration();
	}
	
	ifstream in3;
	in3.open("CourierAuthentication.txt");
	while (std::getline(in3, line3))
	{
		if (line3.find(username3) != string::npos)
		{
			count++;
		}
	}
	if (count > 0)
	{
		count = 0;
		cout << "Username already exists...!" << endl;
		mainMenu();
	}
	in3.close();
	fstream file3;
	file3.open("CourierAuthentication.txt", ios::out | ios::app);
	cout << "Enter password :";
	cin >> password3;
passwordMatch:
	cout << "Enter password to confirm :";
	getline(cin >> ws, password_confirm3);
	if (password3 != password_confirm3)
	{
		cout << "\nThe passwords do not match. Please enter a new password\n";
		goto passwordMatch;
	}
	else
	{
		cout << "Awesome....Your Registration is successful......" << endl;
	}
	cout << "Your USERNAME :"
		 << username3 << endl;
	file3 << username3 << " " << password3 << endl;
	file3.close();
	cout << "\n";
	
}
void Authentication::courierLogin()
{
	int count;
	string username3, password3, fileUsername, filePassword;
	cout << "Hello Courier........So Glad to see you back......." << endl;

	cout << "Please enter the following details" << endl;
	cout << "USERNAME :";
	cin >> username3;

	cout << "PASSWORD :";
	cin >> password3;

	ifstream input("CourierAuthentication.txt");
	while (input >> fileUsername >> filePassword)
	{
		if (fileUsername == username3 && filePassword == password3)
		{
			count = 1;
		}
	}
	input.close();
	if (count == 1)
	{
		cout << "\nLOGIN SUCCESSFUL...\nThanks for being a partner with us\nThanks for logging in.\n";
	}
	else
	{
		std::cout << "\n";
		std::cout << "       ===Invalid Username or password! Please try again.===\n";
		std::cout << "\n";
		mainMenu();
	}
}
