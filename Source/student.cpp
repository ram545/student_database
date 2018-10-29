/**********************************************************************
* FILENAME:        student.cpp
*
* DESCRIPTION/PURPOSE: method definition for class student and marks
*
* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 10/23/2018
* SUBMISSION DATE: 10/23/2018
*
**********************************************************************/

#include <iostream>
#include <string.h>
#include "../Include/student.h"
using namespace std;

student::student()
{

}

student::~student()
{
    delete[] name;
	delete[] subject;
	rollNo = 0;
	cout << "Destructor-1 Called" << endl;
}

student::student(char* stu_name,int stu_rollNo,char* stu_subject)
{
	int len;
	len = strlen(stu_name);
	name = new char[len+1];
	strcpy(name,stu_name);
    rollNo = stu_rollNo;
    len = strlen(stu_subject);
	subject = new char[len+1];
    strcpy(subject,stu_subject);
}

student::student(const student& obj)
{
	int len;
	len = strlen(obj.name);
	name = new char[len+1];
	strcpy(name,obj.name);
    rollNo = obj.rollNo;
	len = strlen(obj.subject);
	subject = new char[len+1];
    strcpy(subject,obj.subject);
}

void student::setStuData(char* stu_name,int stu_rollNo,char* stu_subject)
{
	int len;
	len = strlen(stu_name);
	name = new char[len+1];
	strcpy(name,stu_name);
    rollNo = stu_rollNo;
	len = strlen(stu_subject);
	subject = new char[len+1];
    strcpy(subject,stu_subject);
}

char* student::getName(){
	return name;
}

int student::getRollNo(){
	return rollNo;
}

char* student::getSubject(){
    return subject;
}

marks::marks(){

}

marks::~marks(){
    cout << "Destructor Called for" << subCode << endl;
	delete[] subCode;
    assessmentMarks=0;
    examinationMarks=0;
    cout << "Destructor Called" << endl;
}

marks::marks(char* code,int marks,int finalMarks){
	int len;
	len = strlen(code);
	subCode = new char[len+1];
	strcpy(subCode,code);
	assessmentMarks = marks;
	examinationMarks = finalMarks;
}

void marks::setData(char* code,int marks,int finalMarks){
	int len;
	len = strlen(code);
	subCode = new char[len+1];
	strcpy(subCode,code);
	assessmentMarks = marks;
	examinationMarks = finalMarks;
}

marks::marks(const marks& obj) : student(obj) {
	int len;
	len = strlen(obj.subCode);
	subCode = new char[len+1];
	strcpy(subCode,obj.subCode);
	assessmentMarks = obj.assessmentMarks;
	examinationMarks = obj.examinationMarks;
}

void marks::showData(){
	cout << "  Name                         : " << "   " << getName() << endl;
	cout << "  RollNumber                   : " << "   " << getRollNo() << endl;
	cout << "  Subject                      : " << "   " << getSubject() << endl;
	cout << "  Subject Code                 : " << "   " << subCode << endl;
	cout << "  Internal Assessment Marks    : " << "   " << assessmentMarks << endl;
	cout << "  University Examination Marks : " << "   " << examinationMarks << endl;
}
// Implement Operator overloaded functions
// Implement static functions
// Implement friend functions
