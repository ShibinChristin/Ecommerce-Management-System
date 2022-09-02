#include "project.h"
fstream file;
void Authentication::CustomerRegistration()
{
	string username, password, password_confirm;
	file.open("CustomerAuthentication.txt", ios::out | ios::app);
	std::regex s("^[a-zA-Z\\s]+$");
user:
	cout << "Enter your desired username : ";
	getline(cin >> ws, username);
	if (!(regex_match(username, s)))
	{
		std::cout << "\n";
		std::cout << "       ===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto user;
	}
	Validate(username);
	cout << "Enter password :";
	cin >> password;
passwordStart:
	cout << "Enter password to confirm :";
	getline(cin >> ws, password_confirm);
	if (password != password_confirm)
	{
		cout << "\nThe passwords do not match. Please enter a new password\n";
		goto passwordStart;
	}
	else
	{
		cout << "Awesome....Your Registration is successful......" << endl;
	}
	cout << "Your USERID :"
			 << "\e[1m" << username << endl
			 << endl;
	file << username << " " << password << endl;
	file.close();
}

////////////////////////////////////////////////////////////////////////////////////

void Authentication::CustomerLogin()
{
	int count;
	string line, username, password, user, pass, condition;
	system("clear");
	cout << "So Glad to see you back......." << endl;
user:
	cout << "please enter the following details" << endl;
	cout << "\e[1m"
			 << "USERNAME :";
	cin >> username;
retry:
	cout << "\e[1m"
			 << "PASSWORD :";
	cin >> password;

	ifstream input("CustomerAuthentication.txt");
	while (input >> user >> pass)
	{
		if (user == username && pass == password)

		{
			count = 1;
			system("clear");
		}
	}
	input.close();
	if (count == 1)
	{
		cout << "\nLOGIN SUCESS\nWe're glad that you're here.\nThanks for logging in\n";
	}
	else
	{
		std::cout << "\n";
		std::cout << "       ===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto user;
	}
}

void Authentication::MerchantLogin()
{
	int count;
	string username, password, u, p, condition;
	system("clear");
	cout << "Hello Merchant..........So Glad to see you back......." << endl;
merchant:
	cout << "please enter the following details" << endl;
	cout << "\e[1m"
			 << "USERNAME :";
	cin >> username;
retry:
	cout << "\e[1m"
			 << "PASSWORD :";
	cin >> password;

	ifstream input("merchantAuthentication.txt");
	while (input >> u >> p)
	{
		if (u == username && p == password)

		{
			count = 1;
			system("clear");
		}
	}
	input.close();
	if (count == 1)
	{
		cout << "\nLOGIN SUCESS\nWe're glad that you're here.\n";
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

void Authentication::CourierLogin()
{
	int count;
	string username, password, u, p, condition;
	system("clear");
	cout << "So Glad to see you back......." << endl;
courier:
	cout << "please enter the following details" << endl;
	cout << "\e[1m"
			 << "USERNAME :";
	cin >> username;
retry:
	cout << "\e[1m"
			 << "PASSWORD :";
	cin >> password;

	ifstream input("CourierAuthentication.txt");
	while (input >> u >> p)
	{
		if (u == username && p == password)

		{
			count = 1;
			system("clear");
		}
	}
	input.close();
	if (count == 1)
	{
		cout << "\nLOGIN SUCESS\nThanks for being a partner with us \n";
	}
	else
	{
		std::cout << "\n";
		std::cout << "       ===Invalid name! Please try again.===\n";
		std::cout << "\n";
		goto courier;
	}
}

void Authentication::Validate(string user)
{
	std::string line;
	ifstream in;
	int count;
	in.open("CustomerAuthentication.txt");
	while (std::getline(in, line))
	{
		if (line.find(user) != string::npos)
		{
			count = 1;
		}
	}
	if (count == 1)
	{
		cout << "Username already exists" << endl;
	}
	in.close();
}