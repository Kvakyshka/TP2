#include "Student.h"
#include<conio.h>
#include <Windows.h>
using namespace std;

int main()
{
	string text;
	Student object;
	char c, c1;
	int flag = 1;
	const char* oper[] =
	{
	  "Menu:",
	 " 1 - Add",
	 " 2 - Delete",
	 " 3 - Edit",
	 " 4 - Show all",
	 " 5 - Show students with 2",
	 " 6 - GPA increase",
	 " 7 - Exit",
	};

	while (flag != 0)
	{
		for (int i = 0; i < 8; i++)
		{
			cout << oper[i] << endl;
		}
		cout << "Enter option number";
		c = _getch();
		if (c == '1')
		{
			system("cls");
			object + 1;
			cout << "0-Menu: ";
			c1 = _getch();
			if (c1 == '0')
			{
				system("cls");
			}

		}
		if (c == '2')
		{
			system("cls");
			if (object.Getter_size() > 0)
			{
				object.Show_all();
				cout << "Select item number to delete: ";
				getline(cin, text);
				object - (stoi(text));
			}
			else
				cout << "There are no students in the database" << endl;
			cout << "0-Menu: ";
			c1 = _getch();
			if (c1 == '0')
			{
				system("cls");
			}


		}
		if (c == '3')
		{
			system("cls");
			if (object.Getter_size() > 0)
			{
				string num;
				int n;
				object.Show_all();
				cout << "What change?: ";
				getline(cin, num);
				object.Edit(stoi(num));
			}
			else
				cout << "There are no students in the database" << endl;
			cout << "0-Menu: ";
			c1 = _getch();
			if (c1 == '0')
			{
				system("cls");
			}
		}
		if (c == '4')
		{
			system("cls");
			if (object.Getter_size() > 0)
				object.Show_all();
			else
				cout << "There are no students in the database" << endl;
			cout << "0-Menu: ";
			c1 = _getch();
			if (c1 == '0')
			{
				system("cls");
			}
		}
		if (c == '5')
		{
			system("cls");
			if (object.Getter_size() > 0)
				object.Show_grade2();
			else
				cout << "There are no students in the database" << endl;
			cout << "0-Menu: ";
			c1 = _getch();
			if (c1 == '0')
			{
				system("cls");
			}
		}
		if (c == '6')
		{
			system("cls");
			if (object.Getter_size() > 0)
			{
				cout << "Sorting completed successfully" << endl;
				object.selectionSort();
				object.Show_all();
			}
			else
				cout << "There are no students in the database" << endl;
			cout << "0-Menu: ";
			c1 = _getch();
			if (c1 == '0')
			{
				system("cls");
			}
		}
		if (c == '7')
		{
			system("cls");
			flag = 0;
			break;
		}
	}

	return 0;
}

