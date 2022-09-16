#include "project.h"
fstream file1;
int Authentication::idGeneration()
{
	int id;
	srand(time(0));		   // srand() initialize random number generators
	id = rand() % 100 + 1; // generate random numbers
	return id;
}
void Authentication::CustomerRegistration()
{
	count1 = 0;
	size_t pos = 0;
	std::string delimiter = ";";
	std::regex s("^[a-zA-Z0-9\\s]+$");
user1:
	cout << "Enter your desired username : ";
	getline(cin >> ws, username1);
	if (!(regex_match(username1, s)))
	{
		std::cout << "\n";
		std::cout << "       ===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto user1;
	}
	// Validatecustomer(username1);
	ifstream in1;
	bool found = false;
	in1.open("CustomerAuthentication.txt", ios::in);
	while (std::getline(in1, line1))
	{
		std::string token = line1.substr(0, pos);

		if (line1.find(username1) != string::npos)
		{
			// count1++;
			found = true;
		}
		line1.erase(0, pos + delimiter.length());
	}

	if (found)
	{
		cout << "Username already exists" << endl;
		found = false;
		goto user1;
		// CustomerRegistration();
	}

	in1.close();
	fstream file1;
	file1.open("CustomerAuthentication.txt", ios::in | ios::out | ios::app);
	cout << "Enter password :";
	cin >> password1;
passwordStart1:
	cout << "Enter password to confirm :";
	getline(cin >> ws, password_confirm1);

	if (password1 != password_confirm1)
	{
		cout << "\nThe passwords do not match. Please enter a new password\n";
		goto passwordStart1;
	}
	else
	{
		cout << "Awesome....Your Registration is successful......" << endl;
	}
	cout << "Your USERNAME :"
		 << "\e[1m" << username1 << endl;
	file1 << "Username " << username1 << ";"
		  << "Password " << password1 << ";"
		  << "CustomerID " << idGeneration() << ";" << endl;
	file1.close();
	cout << "\n";
	return;
}

////////////////////////////////////////////////////////////////////////////////////

void Authentication::CustomerLogin()
{
	int cAuthenticate = 0;
	bool ifound = false, flag = false;
	std::string line5, token, CustomerID, pass;
	std::string ChecK_name;
	std::string delimiter = ";";
	size_t pos = 0;
	// system("clear");
	cout << "Hello Customer...\nSo Glad to see you back......." << endl;
usera:
	cout << "Please enter the following details" << endl;
	cout << "\e[1m"
		 << "USERNAME :";
	cin >> username1;
retry:
	cout << "\e[1m"
		 << "PASSWORD :";
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
				// cout<<"User name "<<ChecK_name;
				if (username1 == ChecK_name)
				{
					ifound = true;
				}
			}
			if (token.rfind("Password ", 0) == 0 && ifound)
			{
				pass = token.substr(9);
				if (pass == password1)
				{
					flag = true;
					cAuthenticate++;
				}
			}
			if (token.rfind("CustomerID ", 0) == 0 && ifound)
			{
				CustomerID = token.substr(11);
			}
			// }
			line5.erase(0, pos + delimiter.length());
		}
		if (flag)
		{
			cout << "\nLOGIN SUCCESSFUL...\nWe're glad that you're here.\nThanks for logging in\n";
			flag = false;
			cId << CustomerID << endl;
		}
			ifound=false;

	}
	if (cAuthenticate == 0)
	{
		std::cout << "\n";
		std::cout << "       ===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto usera;
	}
	input.close();
}
/////////////////////////////////////////////////////////////////////////////////////////

void Authentication::MerchantRegistration()
{
	count2 = 0;
	string username2, password2, password_confirm2;
	size_t pos = 0;
	string delimiter = ";";

	std::regex s("^[a-zA-Z0-9\\s]+$");
user2:
	cout << "Enter your desired username : ";
	getline(cin >> ws, username2);
	if (!(regex_match(username2, s)))
	{
		std::cout << "\n";
		std::cout << "===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto user2;
	}
	// Validatemerchant(username2);

	// int count1;

	ifstream in2;
	bool found = false;
	in2.open("merchantAuthentication.txt", ios::in);
	while (std::getline(in2, line2))
	{
		if (line2.find(username2) != string::npos)
		{
			// count2++;
			found = true;
		}
		line2.erase(0, pos + delimiter.length());
	}
	if (found)
	{
		cout << "Username already exists" << endl;
		found = false;
		goto user2;
		// MerchantRegistration();
	}
	in2.close();
	fstream file2;
	file2.open("merchantAuthentication.txt", ios::out | ios::app);

	cout << "Enter password :";
	cin >> password2;
passwordStart2:
	cout << "Enter password to confirm :";
	getline(cin >> ws, password_confirm2);
	if (password2 != password_confirm2)
	{
		cout << "\nThe passwords do not match. Please enter a new password\n";
		goto passwordStart2;
	}
	else
	{
		cout << "Awesome....Your Registration is successful......" << endl;
	}
	cout << "Your USERNAME :"
		 << "\e[1m" << username2 << endl;
	file2 << "Username " << username2 << ";"
		  << "Password " << password2 << ";"
		  << "MerchantID " << idGeneration() << ";" << endl;
	file2.close();
	cout << "\n";
	return;
}

void Authentication::MerchantLogin()
{
	int count;
	int mAuthenticate = 0;
	bool ifound = false;
	std::string line6, token, MerchantID, pass;
	std::string Check_name;
	std::string delimiter = ";";
	size_t pos = 0;
	string username2, password2, u, p, condition;
	system("clear");
	cout << "Hello Merchant..........So Glad to see you back......." << endl;
merchant:
	cout << "Please enter the following details" << endl;
	cout << "\e[1m"
		 << "USERNAME :";
	cin >> username2;
retry:
	cout << "\e[1m"
		 << "PASSWORD :";
	cin >> password2;

	ifstream merchantFile("merchantAuthentication.txt");
	ofstream mer("merchantId.txt", ios::out);
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
					mAuthenticate++;
				}
			}
			if (token.rfind("Password ", 0) == 0 && ifound)
			{
				pass = token.substr(9);
			}
			if (token.rfind("MerchantID ", 0) == 0 && ifound)
			{
				MerchantID = token.substr(11);
			}
			line6.erase(0, pos + delimiter.length());
		}
		if (ifound)
		{
			cout << "\nLOGIN SUCCESSFUL...\nWe're glad that you're here.\nThanks for logging in\n";
			ifound = false;
			mer << MerchantID << endl;
		}
	}
	if (mAuthenticate == 0)
	{
		std::cout << "\n";
		std::cout << "       ===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto merchant;
	}
	merchantFile.close();
}

///////////////////////////////////////////////////////////////////////

void Authentication::CourierRegistration()
{

	count3 = 0;
	std::regex s("^[a-zA-Z0-9\\s]+$");
user3:
	cout << "Enter your desired username : ";
	getline(cin >> ws, username3);
	if (!(regex_match(username3, s)))
	{
		std::cout << "\n";
		std::cout << "===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto user3;
	}
	// Validatecourier(username3);
	ifstream in3;
	in3.open("CourierAuthentication.txt");
	while (std::getline(in3, line3))
	{
		if (line3.find(username3) != string::npos)
		{
			count3++;
		}
	}
	if (count3 > 0)
	{
		count3 = 0;
		cout << "Username already exists...!" << endl;
		goto user3;
		// CourierRegistration();
	}
	in3.close();
	fstream file3;
	file3.open("CourierAuthentication.txt", ios::out | ios::app);
	cout << "Enter password :";
	cin >> password3;
passwordStart3:
	cout << "Enter password to confirm :";
	getline(cin >> ws, password_confirm3);
	if (password3 != password_confirm3)
	{
		cout << "\nThe passwords do not match. Please enter a new password\n";
		goto passwordStart3;
	}
	else
	{
		cout << "Awesome....Your Registration is successful......" << endl;
	}
	cout << "Your USERNAME :"
		 << "\e[1m" << username3 << endl;
	file3 << username3 << " " << password3 << endl;
	file3.close();
	cout << "\n";
	return;
}
void Authentication::CourierLogin()
{
	int count;
	string username3, password3, u, p;
	system("clear");
	cout << "Hello Courier........So Glad to see you back......." << endl;
courier:
	cout << "Please enter the following details" << endl;
	cout << "\e[1m"
		 << "USERNAME :";
	cin >> username3;
retry:
	cout << "\e[1m"
		 << "PASSWORD :";
	cin >> password3;

	ifstream input("CourierAuthentication.txt");
	while (input >> u >> p)
	{
		if (u == username3 && p == password3)
		{
			count = 1;
			system("clear");
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
		goto courier;
	}
}
