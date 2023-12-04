#include "keeper.h"


Keeper::Keeper(const Keeper& other)
{
	array = new Student[other.size];
	for (int i = 0; i < other.size; i++)
	{
		array[i] = other.array[i];
	}

}
void Keeper::selectionSort()
{
	Keeper buffer(*this);
	array = new Student  [Getter_size()];
	for (int i = 0; i < Getter_size(); i++)
	{
		array[i] = buffer.array[i];
	}
	for (int i = 0; i < size; i++) {
		int min_index = i;
		float min_GPA = array[i].CalculateGPA();

		for (int j = i + 1; j < size; j++) {
			float curr_GPA = array[j].CalculateGPA();
			if (curr_GPA < min_GPA) {
				min_GPA = curr_GPA;
				min_index = j;
			}
		}
		Student temp = array[i];
		array[i] = array[min_index];
		array[min_index] = temp;
	}
}

int Keeper::Getter_size() { return size; };
void Keeper::Show_grade2()
{
	int count = 0;
	for (int i = 0; i < Getter_size(); i++)
	{
		for (int j = 0; j < array[i].Getter_number_subjects(); j++)
		{
			if (array[i].subjects[j].grade == 2)
			{
				cout << i + 1 << endl;
				array[i].Show();
				count++;
				break;
			}
		}

	}
	if (count == 0)
		cout << "No students with grade 2" << endl;
}


void Keeper::Setter_size(int size) { this->size = size; };

void Keeper::Show_all()
{


	cout << "All the students:" << endl;
	for (int i = 0; i < Getter_size(); i++)
	{
		cout << i + 1 << endl;
		cout<<array[i];
	}
}
Keeper Keeper ::operator +(int number)
{
	cout << "Add:" << endl;
	Keeper buffer(*this);
	Setter_size(Getter_size() + 1);
	array = new Student [Getter_size()];
	for (int i = 0; i < Getter_size() - 1; i++)
	{
		array[i] = buffer.array[i];
	}
	cin>>array[Getter_size() - 1];
	return *this;
}
Keeper Keeper ::operator -(int number)
{
	Keeper buffer(*this);
	Setter_size(Getter_size() - 1);
	array = new Student [Getter_size()];
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
void Keeper::Edit_all(int number)
{
	array[number - 1].Edit();
}
