#include "Student.h"

void Student::selectionSort() {
	Student buffer(*this);
	array = new Student * [Getter_size()];
	for (int i = 0; i < Getter_size(); i++)
	{
		array[i] = buffer.array[i];
	}
	for (int i = 0; i < size; i++) {
		int min_index = i;
		float min_GPA = array[i]->CalculateGPA();

		for (int j = i + 1; j < size; j++) {
			float curr_GPA = array[j]->CalculateGPA();
			if (curr_GPA < min_GPA) {
				min_GPA = curr_GPA;
				min_index = j;
			}
		}
		Student* temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
	}
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
Student::~Student()
{
	delete array;
}
Student::Student(int a)
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
Student::Student()
{
	number_subjects = 0;
	array = nullptr;

}
Student::Student(const Student& object)
{

	this->array = new Student * [object.size];

	for (int i = 0; i < object.size; i++)
	{
		array[i] = object.array[i];
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
void Student::Setter_size(int size) { this->size = size; };



string Student::Getter_name() { return name; }
string Student::Getter_group() { return group; };
int Student::Getter_number_subjects() { return number_subjects; };
int Student::Getter_size() { return size; };

void Student::Show_grade2()
{
	int count = 0;
	for (int i = 0; i < Getter_size(); i++)
	{
		for (int j = 0; j < array[i]->Getter_number_subjects(); j++)
		{
			if (array[i]->subjects[j].grade == 2)
			{
				cout << i + 1 << endl;
				array[i]->Show();
				count++;
				break;
			}
		}

	}
	if (count == 0)
		cout << "No students with grade 2" << endl;
}
void Student::Show()
{
	cout << "name: " << Getter_name() << endl;
	cout << "group: " << Getter_group() << endl;
	cout << "subjects: " << endl;
	for (int i = 0; i < Getter_number_subjects(); i++)
		cout << subjects[i].name_subject << ": " << subjects[i].grade << endl;

}
void Student::Show_all()
{
	cout << "All the students:" << endl;
	for (int i = 0; i < Getter_size(); i++)
	{
		cout << i + 1 << endl;
		array[i]->Show();
	}
}
Student Student::operator +(int number)
{
	cout << "Add:" << endl;
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
Student Student::operator -(int number)
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
void Student::Edit(int number)
{
	array[number - 1]->Show();
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
		array[number - 1]->Setter_name(text);
		break;
	}
	case 2:
	{
		cout << "group: ";
		getline(cin, text);
		array[number - 1]->Setter_group(text);
		break;
	}

	case 3:
	{
		cout << "number subjects: ";
		getline(cin, text);
		array[number - 1]->Setter_number_subjects(stoi(text));
		for (int i = 0; i < array[number - 1]->Getter_number_subjects(); i++)
		{
			cout << "name subject: ";
			getline(cin, text);
			string name_sbj = text;
			cout << "grade: ";
			getline(cin, text);
			int grd = stoi(text);

			array[number - 1]->Add_subjects_grade(name_sbj, grd, i);
		}

		break;
	}
	}
}