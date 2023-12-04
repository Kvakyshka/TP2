#pragma once
#include <iostream>
#include <string>
using namespace std;
class Student
{
	string name;
	string group;
	
	int number_subjects;
	
public:

	struct Subject
	{
		string name_subject;
		int grade;
	};
	Subject* subjects;

	~Student() {};
	Student(int a);
	Student() {};
	Student(const Student& other) ;
	void add();
	void Setter_name(string name);
	void Setter_group(string group);
	void Setter_number_subjects(int number_subjects);
	Student operator = (const Student& other);
	void Edit();
	
	float CalculateGPA();

	string Getter_name();
	string Getter_group();
	int Getter_number_subjects();
	void Add_subjects_grade(string name_subject, int grade, int num);
	void Show();
};