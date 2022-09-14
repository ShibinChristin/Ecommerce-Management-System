#include "project.h"

fstream file1;

void Authentication::CustomerRegistration()
{
	count1 = 0;
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
			if (line1.find(username1) != string::npos)
			{
				// count1++; 
				found = true;
			}
		}
		
	if (found)
		{
			cout << "Username already exists" << endl;
			found=false;
			 goto user1;
			//CustomerRegistration();
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
	file1 << username1 << " " << password1 << endl;
	file1.close();
	cout<<"\n";
	return;
}

////////////////////////////////////////////////////////////////////////////////////

void Authentication::CustomerLogin()
{

	// string line, username, password, user, pass, condition;
	system("clear");
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

	ifstream input("CustomerAuthentication.txt");
	while (input >> user >> pass1)
	{
		if (user == username1 && pass1 == password1)

		{
			count1 = 1;
			system("clear");
		}
	}
	input.close();
	if (count1 == 1)
	{
		cout << "\nLOGIN SUCCESSFUL...\nWe're glad that you're here.\nThanks for logging in\n";
	}
	else
	{
		std::cout << "\n";
		std::cout << "       ===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto usera;
	}
}

void Authentication::MerchantRegistration()
{
	count2 = 0;
	string username2, password2, password_confirm2;
	
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
	ifstream in2;
	// int count1;
	in2.open("merchantAuthentication.txt" , ios:: in);
	while (std::getline(in2, line2))
	{
		if (line2.find(username2) != string::npos)
		{
			count2++;
		}
	}
	if (count2 > 0)
	{
		count2 = 0;
		cout << "Username already exists" << endl;
			goto user2;
		//MerchantRegistration();
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
		cout << "Your USERID :"
			 << "\e[1m" << username2 << endl;
		file2 << username2 << " " << password2 << endl;
		file2.close();
		cout<<"\n";
		return;
	
}

void Authentication::MerchantLogin()
{
	int count;
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

	ifstream input("merchantAuthentication.txt");
	while (input >> u >> p)
	{
		if (u == username2 && p == password2)

		{
			count = 1;
			system("clear");
		}
	}
	input.close();
	if (count == 1)
	{
		cout << "\nLOGIN SUCCESSFUL...\nWe're glad that you're here.\nThanks for logging in.\n";
	}
	else
	{
		std::cout << "\n";
		std::cout << "       ===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto merchant;
	}
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
		cout << "Your USERID :"
			 << "\e[1m" << username3 << endl;
		file3 << username3 << " " << password3 << endl;
		file3.close();
		cout <<"\n";
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
		std::cout << "       ===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto courier;
	}
}

