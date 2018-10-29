/************************************************************************
* FILENAME:      student.h
*
* DESCRIPTION/PURPOSE: Create a base class called student and also a derived class
*
* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 10/23/2018
* SUBMISSION DATE: 10/23/2018
*
************************************************************************/
#ifndef student_H
#define student_H

class student
{
private:
    char* name;
    int rollNo;
    char* subject;

public:
    student();
    ~student();
    student(char* name,int rollNo,char* subject);
    student(const student&);
    virtual char* getName();
	virtual int getRollNo();
	virtual char* getSubject();
	void setStuData(char* name,int rollNo,char* subject);
};

class marks : public student
{
private:
    char* subCode;
    int assessmentMarks;
    int examinationMarks;
public:
    marks();
    ~marks();
    marks(char* code,int marks,int finalMarks);
    marks(const marks&);
	void setData(char* code,int marks,int finalMarks);
	void showData();
};

#endif /* student_H */
