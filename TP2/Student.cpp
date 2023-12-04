#include "Student.h"


Student::Student(const Student& other)
{
	name = other.name;
	group = other.group;
	number_subjects = other.number_subjects;
	subjects = new Subject[number_subjects];
	for (int i = 0; i < number_subjects; i++)
	{
		subjects[i].grade = other.subjects[i].grade;
		subjects[i].name_subject = other.subjects[i].name_subject;
	}
}

Student::Student(int val )
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
	try
	{
		Setter_number_subjects(stoi(text));
	}
	catch (const invalid_argument& ex)
	{
		cout << "You did not enter a number: " << ex.what() << endl;
		getline(cin, text);
		Setter_number_subjects(stoi(text));

	}
	catch (const exception&)
	{
		std::cout << "Something wrong" << std::endl;
	}
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
Student Student::operator = (const Student & other)

{
	name = other.name;
	group = other.group;
	number_subjects = other.number_subjects;
	subjects = new Subject[number_subjects];
	for (int i = 0; i < number_subjects;i++)
	{
		subjects[i].grade = other.subjects[i].grade;
		subjects[i].name_subject = other.subjects[i].name_subject;
	}
	return*this;

}

void Student::add()
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
	try
	{
		Setter_number_subjects(stoi(text));
	}
	catch (const invalid_argument& ex)
	{
		cout << "You did not enter a number: " << ex.what() << endl;
		getline(cin, text);
		Setter_number_subjects(stoi(text));

	}
	catch (const exception&)
	{
		std::cout << "Something wrong" << std::endl;
	}
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
void Student::Add_subjects_grade(string name_subject, int grade, int num)
{
	this->subjects[num].name_subject = name_subject;
	this->subjects[num].grade = grade;
}
void Student::Setter_name(string name) { this->name = name; };
void Student::Setter_group(string group) { this->group = group; };
void Student::Setter_number_subjects(int number_subjects) { this->number_subjects = number_subjects; };



string Student::Getter_name() { return name; }
string Student::Getter_group() { return group; };
int Student::Getter_number_subjects() { return number_subjects; };


void Student::Show()
{
	cout << "name: " << Getter_name() << endl;
	cout << "group: " << Getter_group() << endl;
	cout << "subjects: " << endl;
	for (int i = 0; i < Getter_number_subjects(); i++)
		cout << subjects[i].name_subject << ": " << subjects[i].grade << endl;

}

ostream& operator <<(ostream& os, const Student& el)
{
	os << el.name << ' ' << el.group<< endl;
	for (int i = 0; i < el.number_subjects; i++)
	{
		os << "subject: "<<el.subjects[i].name_subject << endl << " Grade: " << el.subjects[i].grade<<endl;//tyt menyti vivod esli shto
	}
	os << endl;
	return os;
}


istream& operator >>(istream& os, Student& el)
{
	string buf,buf2;

	cout << "input name" << endl;
	getline(os, buf);
	el.name = buf;

	cout << "group" << endl;
	getline(os, buf);
	el.group = buf;


	cout << "number subject" << endl;
	getline(os, buf);
	
	el.number_subjects = stoi(buf);
	cout << el.number_subjects << endl;
	
	el.subjects = new Subject[el.number_subjects];
	for (int i = 0; i < el.number_subjects; i++)
	{
		cout << "name_subject" << endl;
		getline(os, buf2);
		
		el.subjects[i].name_subject = buf2;
		

		cout << "grade" << endl;
		getline(os, buf);
		el.subjects[i].grade = stoi(buf);

	}
	return os;
}
float Student::CalculateGPA()
{
	float sum = 0;
	float average = 0;

	for (int i = 0; i < Getter_number_subjects(); i++)
	{
		sum += subjects[i].grade;
	}

	average = sum / Getter_number_subjects();

	return average;
}
void Student::Edit()
{
	Show();
	cout << "What change?: " << endl << "1. name" << endl << "2. group" << endl << "3. subjects" << endl;
	string number_change;
	string text;
	cout << endl << "number: ";
	getline(cin, number_change);
	switch (stoi(number_change))
	{
	case 1:
	{
		cout << "name: ";
		getline(cin, text);
		Setter_name(text);
		break;
	}
	case 2:
	{
		cout << "group: ";
		getline(cin, text);
		Setter_group(text);
		break;
	}

	case 3:
	{
		cout << "number subjects: ";
		getline(cin, text);
		Setter_number_subjects(stoi(text));
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

		break;
	}
	}
}

