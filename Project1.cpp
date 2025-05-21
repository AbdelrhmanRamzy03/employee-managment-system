//employee managment system By Abdelrhman Ramzy Using C++
#include<iostream> //for the input and the output (cin and cout)
#include<conio.h> //for the getch() function
#include <string> //for the string statment
#include<windows.h> //for the Sleep() function

using namespace std; //to write the cout and the cin without the std statment

struct emp { //the structure of the employee called "Emp" from employee
	string name, id, address;
	char rank;
	int  salary, contact, month, benfit;
};
int total = 0;
emp e[50]; //the array 
void empdata() { //the function of the employee data
	int user = 0;
	int z;
	cout << "How many employees data do you want to enter??" << endl; //for entering the number of employees 
	cin >> user;
	for (int i = total; i < total + user; i++) {
		cout << "Enter data of employee " << i + 1 << endl << endl;
		cout << "Enter employee name: "; //enter the employee name
		cin >> e[i].name; 
		cout << "Enter id: "; //enter the id
		cin >> e[i].id;
		cout << "Enter address: "; //enter the address
		cin >> e[i].address;
		cout << "Enter Phone Number(+20): "; //enter the phone number
		cin >> e[i].contact;
		cout << "Choose one Of these Ranks\n1 Ceo(A)" << endl; //enter the rank by categorie the ceo will be (A)
		cout << "2 Coo (B)" << endl; //the coo will (B)
		cout << "3 team-leader(C)" << endl; //the team-leader will be (C)
		cout << "4 employee (D)" << endl; //the employee will be (D)
		cout << "Enter Rank: " << endl; //enter the rank
		cin >> e[i].rank;
		switch (e[i].rank) //cases if you choose a number it will choose a categorie
		{
		case '1':;
			e[i].rank = 'A';
			break;
		case '2':;
			e[i].rank = 'B';
			break;
		case '3':;
			e[i].rank = 'C';
			break;
		case '4':;
			e[i].rank = 'D';
			break;
		}
		cout << "Enter salary: "; //enter the salary
		cin >> e[i].salary;
		cout << "Enter month: "; //enter the worked months
		cin >> e[i].month;
		z = i; 
	}
	total = total + user;
	int benfsalary = e[z].salary;
	int benfit; 
	for (int counter = 0; counter < (e[z].month / 12); counter++) //this loop to calculate the benfit  depends on the worked months
	{
		benfsalary += benfsalary / 10; 
	}
	benfit = benfsalary - e[z].salary;
	e[z].benfit = benfit;
}
void show() { //the function of the show data that is stored
	if (total != 0) {
		for (int i = 0; i < total; i++) {
			cout << "Data of employee " << i + 1 << endl;
			cout << "Name: " << e[i].name << endl;
			cout << "ID: " << e[i].id << endl;
			cout << "Address: " << e[i].address << endl;
			cout << "Contact: " << e[i].contact << endl;
            cout << "Salary: " << e[i].salary << endl;
			cout << "Rank: " << e[i].rank << endl;
			cout << "Month: " << e[i].month << endl;
			cout << "Benfit: " << e[i].benfit << endl;
		}
	}
	else {
		cout << "No data is entered" << endl;
	}
}
void search() { //the function of the search data
	if (total != 0) {
		string id;
		cout << "Enter id of employee which you want to search" << endl;
		cin >> id;
		for (int i = 0; i < total; i++) {
			if (e[i].id == id) {
				cout << "Data of employee " << i + 1 << endl;
				cout << "Name: " << e[i].name << endl;
				cout << "ID: " << e[i].id << endl;
				cout << "Address: " << e[i].address << endl;
				cout << "Contact: " << e[i].contact << endl;
				cout << "Rank: " << e[i].rank << endl;
				cout << "Salary: " << e[i].salary << endl;
				cout << "Salary after benfit: " << e[i].salary + e[i].benfit << endl;
				break;
			}
			if (i == total - 1) {
				cout << "No such record found" << endl;
			}
		}
	}
	else {
		cout << "No data is entered" << endl;
	}
}
void update() { //the function of changing data
	if (total != 0) {
		string id;
		cout << "Enter id of employee which you want to update" << endl; //enter th id of the employee that you want to change
		cin >> id;
		for (int i = 0; i < total; i++) {
			if (e[i].id == id) {
				cout << "Old data of employee " << i + 1 << endl;
				cout << "Name: " << e[i].name << endl;
				cout << "ID: " << e[i].id << endl;
				cout << "Address: " << e[i].address << endl;
				cout << "Contact: " << e[i].contact << endl;
				cout << "Salary: " << e[i].salary << endl;
				cout << "\nEnter new data" << endl; //enter the new data
				cout << "Enter employee name: "; //enter the new name
				cin >> e[i].name;
				cout << "Enter id: "; //enter the new id 
				cin >> e[i].id;
				cout << "Enter address: "; //enter the new address
				cin >> e[i].address;
				cout << "Enter contact: "; //enter the new phone number
				cin >> e[i].contact;
				cout << "Enter salary: "; //enter the new salary
				cin >> e[i].salary;
				cout << "Choose one Of these Ranks\n1 Ceo(A)" << endl; //enter the new rank by (categorie)
				cout << "2 Coo (B)" << endl;
				cout << "3 team-leader(C)" << endl;
				cout << "4 emp (D)" << endl;
				cout << "Enter Rank: ";
				e[i].rank = _getch();
				
				switch (e[i].rank)
				{
				case '1':;
					e[i].rank = 'A';
					break;
				case '2':;
					e[i].rank = 'B';
					break;
				case '3':;
					e[i].rank = 'C';
					break;
				case '4':;
					e[i].rank = 'D';
					break;
				}
				break;
			}
			if (i == total - 1) {
				cout << "No such record found" << endl;
			}
		}
	}
	else {
		cout << "No data is entered" << endl;
	}
}
void del() { //the function of deleting data
	if (total != 0) {
		int press;
		cout << "Press 1 to delete specific record" << endl; //this will delete all the data stored
		cout << "Press 2 to delete full record" << endl; //this will delete a specific data by id
		cin >> press;
		if (press == 1) {
			string id;
			cout << "Enter id of employee which you want to delete" << endl; //enter the id of the employee that you want to delete
			cin >> id;
			for (int i = 0; i < total; i++) {
				if (e[i].id == id) {
					e[i].name = e[i + 1].name;
					e[i].id = e[i + 1].id;
					e[i].address = e[i + 1].address;
					e[i].contact = e[i + 1].contact;
					e[i].salary = e[i + 1].salary;
					total--;
					cout << "Your required record is deleted" << endl; 
					break;
				}
				if (i == total - 1) {
					cout << "No such record found" << endl;
				}
			}
		}
		else if (press == 2) {
			total = 0;
			cout << "All record is deleted" << endl;
		}
		else {
			cout << "Invalid Input" << endl;
		}
	}
	else {
		cout << "No data is entered" << endl;
	}
}
int main() { //the main function and the start of the code
	cout << "\n\t\t\t\t ****************************************";
	Sleep(500);
	cout << "\n\t\t\t\t |** >> Employee Management System << **|"; //The Main title of the program
	Sleep(500);
	cout << "\n\t\t\t\t ****************************************" << endl;
	Sleep(500);
	cout << "\n\t\t\t\t\t    >> By Abdelrhman Ramzy <<\n"; //Our Team name
	Sleep(500);
	string username, password;
	cout << "\n\t\t\t\t\t ******************************";
	cout << "\n\t\t\t\t\t || >> Registeration Page << ||"; //Registeration Page
	cout << "\n\t\t\t\t\t ******************************\n" << endl;
	cout << "\t\t-------------------------" << endl;
	cout << "\t\tEnter new username: "; //enter the username for registeration
	cin >> username;
	cout << "\t\t------------------------" << endl;
	cout << "\t\tEnter new password: "; //enter the password for registeration
	cin >> password;
	cout << "\t\t------------------------" << endl;
	cout << "\t\tYour new id is creating please wait";
	for (int i = 0; i < 6; i++)
	{
		cout << ".";
		Sleep(500);
	}
	cout << "\n\t\tYour id created successfully";
	Sleep(2000);
start: //a point to make a goto to here when i choose to logout
	system("CLS");
	string usrn, pswd;
	cout << "\n\t\t\t\t ****************************************";
	Sleep(200);
	cout << "\n\t\t\t\t |** >> Employee Management System << **|"; //The Main title of the program
	Sleep(200);
	cout << "\n\t\t\t\t ****************************************" << endl;
	Sleep(200);
	cout << "\n\t\t\t\t\t    >> By Abdelrhman Ramzy <<\n"; //Our team name
	Sleep(200);
	cout << "\n\t\t\t\t\t -----------------";
	cout << "\n\t\t\t\t\t || >> Login << ||"; //Login Page
	cout << "\n\t\t\t\t\t -----------------" << endl;
	cout << "\t\t-------------------------" << endl;
	cout << "\t\tEnter new username: "; //Enter the username from the registration 
	cin >> usrn;
	cout << "\t\t------------------------" << endl;
	cout << "\t\tEnter password: "; //Enter the Password from the Registration
	cin >> pswd;
	cout << "\t\t------------------------" << endl;
	if (usrn == username && pswd == password)
	{
		system("CLS");
		char ch;
		while (1) {
			cout << "\n\t\t\t\t --------------------------------------";
			cout << "\n\t\t\t\t || >> Choose One of these options << ||"; //The Option Menu that takes you to the functions
			cout << "\n\t\t\t\t --------------------------------------" << endl;
			cout << "\n\nPress 1 to Enter Data" << endl; //To Got to the empdata function
			cout << "Press 2 to Show Data" << endl; //To got to the show function
			cout << "Press 3 to Search Data" << endl; //To got to the search function
			cout << "Press 4 to Update Data" << endl; //to go to the update function
			cout << "Press 5 to Delete Data" << endl; //to go to the delete function
			cout << "Press 6 to Logout" << endl; //to go to the start point in the main function
			cout << "Press 7 to Exit" << endl; //to exit the program and return 0
			cout << "Your Choise:"; //To choose which function you want to go to
			ch = _getch();
			system("CLS"); //To clear the screen and open a new page for the coming statments
			switch (ch) {
			case '1':
				empdata();
				break;
			case '2':
				show();
				break;
			case '3':
				search();
				break;
			case '4':
				update();
				break;
			case '5':
				del();
				break;
			case '6':
				goto start;
				break;
			case '7':
				exit(0);
				break;
			default:
				cout << "\aInvalid Input" << endl;
				break;
			}
		}
	}
	else if (usrn != username)
	{
		cout << "\t\t\aInvalid username"; //in case the username is incorrect
		Sleep(3000);
		goto start;
	}
	else if (pswd != password)
	{
		cout << "\t\t\aInvalid password \a\a"; // in case the password is only incorrect
		Sleep(3000);
		goto start;
	}
	else {
		cout << "\t\t\aInvalid username or password \a\a"; //in case the password and the username are incorrect 
		Sleep(3000);
		goto start;
	}
}