#include <iostream>
#include <string>
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
	getline(cin, text);

	if (stoi(text) == 1)
	{
		object + 1;
	}
	getline(cin, text);
	if (stoi(text) == 1)
	{
		object + 1;
	}
	getline(cin, text);
	if (stoi(text) == 1)
	{
		object + 1;
	}

	getline(cin, text);
	if (stoi(text) == 2)
	{
		object.Show_all();
	}

	getline(cin, text);
	if (stoi(text) == 3)
	{
		object.Show_grade2();
	}
	getline(cin, text);
	if (stoi(text) == 3)
	{
		cout << "VV num" << endl;
		getline(cin, text);
		object - (stoi(text));
	}
	getline(cin, text);
	if (stoi(text) == 2)
	{
		object.Show_all();
	}

	return 0;
}