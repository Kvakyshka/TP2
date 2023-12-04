#pragma once
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
	void selectionSort();
	float CalculateGPA();
	~Student();
	Student(int a);
	Student();
	Student(const Student& object);

	void Add_subjects_grade(string name_subject, int grade, int num);
	void Setter_name(string name);
	void Setter_group(string group);
	void Setter_number_subjects(int number_subjects);
	void Setter_size(int size);

	void Edit(int number);

	string Getter_name();
	string Getter_group();
	int Getter_number_subjects();
	int Getter_size();

	void Show_grade2();
	void Show();
	void Show_all();
	Student operator +(int number);
	Student operator -(int number);
};