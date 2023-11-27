#include <iostream>
#include <string>

#include<conio.h>
#include <Windows.h>
using namespace std;

class Student
{
	string name;
	string group;
	struct Subject
	{
		string name_subject;
		int grade;

	};
	Subject* subjects;
	int number_subjects;
	int size;
	Student** array;
public:
	~Student() { cout << "Destructor" << endl; delete array; }
	Student(int a)
	{
		string text;
		cout << "name: ";
		getline(cin, text);
		Setter_name(text);
		cout << "group: ";
		getline(cin, text);
		Setter_group(text);


		cout << "number subjects: ";
		getline(cin, text);
		Setter_number_subjects(stoi(text));
		subjects = new Subject[Getter_number_subjects()];
		for (int i = 0; i < Getter_number_subjects(); i++)
		{
			cout << "name subject: ";
			getline(cin, text);
			string name_sbj = text;
			cout << "grade: ";
			getline(cin, text);
			int grd = stoi(text);

			Add_subjects_grade(name_sbj, grd, i);
		}


	}
	Student()
	{
		number_subjects = 0;

	}
	Student(const Student& object)
	{

		this->array = new Student * [object.size];

		for (int i = 0; i < object.size; i++)
		{
			array[i] = object.array[i];
		}
	}

	void Add_subjects_grade(string name_subject, int grade, int num)
	{
		this->subjects[num].name_subject = name_subject;
		this->subjects[num].grade = grade;
	}
	void Setter_name(string name) { this->name = name; };
	void Setter_group(string group) { this->group = group; };
	void Setter_number_subjects(int number_subjects) { this->number_subjects = number_subjects; };
	void Setter_size(int size) { this->size = size; };



	string Getter_name() { return name; }
	string Getter_group() { return group; };
	int Getter_number_subjects() { return number_subjects; };
	int Getter_size() { return size; };

	void Show_grade2()
	{
		for (int i = 0; i < Getter_size(); i++)
		{
			for (int j = 0; j < Getter_number_subjects(); j++)
			{
				if (this->subjects[j].grade == 2)
				{
					array[i]->Show();
					break;
				}
			}

		}
	}
	void Show()
	{
		cout << "name: " << Getter_name() << endl;
		cout << "group: " << Getter_group() << endl;
		cout << "subjects: " << endl;
		for (int i = 0; i < Getter_number_subjects(); i++)
			cout << subjects[i].name_subject << ": " << subjects[i].grade << endl;

	}
	void Show_all()
	{
		for (int i = 0; i < Getter_size(); i++)
		{
			cout << i + 1 << endl;
			cout << "Show all-Show" << endl;
			array[i]->Show();
		}
	}
	Student operator +(int number)
	{
		cout << "ADD" << endl;
		Student buffer(*this);
		Setter_size(Getter_size() + 1);
		array = new Student * [Getter_size()];


		for (int i = 0; i < Getter_size() - 1; i++)
		{
			array[i] = buffer.array[i];
		}
		array[Getter_size() - 1] = new Student(1);
		return *this;
	}
	Student operator -(int number)
	{
		Student buffer(*this);
		Setter_size(Getter_size() - 1);
		array = new Student * [Getter_size()];
		for (int i = 0; i < number - 1; i++)
		{
			array[i] = buffer.array[i];
		}
		for (int i = number - 1; i < Getter_size(); i++)
		{
			array[i] = buffer.array[i + 1];
		}

		return *this;

	}
};
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
	 " 3 - Show all",
	 " 4 - Show students with 2",
	 " 5 - Exit",
	};

	while (flag != 0)
	{
		for (int i = 0; i < 6; i++)
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
			object.Show_all();
			cout << "Select item number to delete: ";
			getline(cin, text);
			object - (stoi(text));
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
			object.Show_all();
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
			object.Show_grade2();
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
			flag = 0;
			break;
		}
	}

	return 0;
}
