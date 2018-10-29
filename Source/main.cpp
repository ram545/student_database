/**********************************************************************
* FILENAME:        main.cpp
*
* DESCRIPTION/PURPOSE:
* Design a C++ base class consisting of the data members such as name of the student, roll number and subject.
* The derived class consists of the data  members subject code, internal assessment and university examination marks.
* Construct a virtual base class for the item name of the student and roll number.
* The program should have the facilities.
* i) Build a master table
* ii) list a table
* iii) insert a new entry
* iv) Delete old enter
* v) Edit an entry
* vi) Search for a record
*
* AUTHOR: 20020298 | Rama Krishna | sabbella.krishna@wipro.com
* START DATE: 10/23/2018
* SUBMISSION DATE: 10/23/2018
*
* Design: (Explain below algorithm in steps)
* 1) table is constructed using vector of objects
* 2) search,delete and edit are done using rollNo
* 3)
* 4)
* ...
**********************************************************************/
#include<iostream>
#include "../Include/student.h"
#include<vector>
#include<iterator>
using namespace std;
int showMenu();
void insertRecord(vector<marks> &rec);
void displayRecord(vector<marks> &rec);
void searchRecord(vector<marks> &rec);
void deleteRecord(vector<marks> &rec);
void editRecord(vector<marks> &rec);

int main(int argc, char **argv)
{
    int inputCase;
    vector<marks> Record;
	vector<marks> :: iterator it;
	do{
        inputCase = showMenu();
        switch(inputCase)
        {
            case 1 : displayRecord(Record); break;
            case 2 : insertRecord(Record); break;
            case 3 : deleteRecord(Record); break;
            case 4 : editRecord(Record); break;
            case 5 : searchRecord(Record); break;
            default : cout << "Execution Successful" << endl;break;
        }
	}while(inputCase!=6);
    return 0;
}

int showMenu()
{
	int choice;
	cout << "\n<< Student Record Menu >>" << endl;
	cout << "1) List a table" << endl;
	cout << "2) Insert a new entry" << endl;
	cout << "3) Delete old entry" << endl;
	cout << "4) Edit an entry" << endl;
	cout << "5) Search for a record" << endl;
	cout << "6) Exit" << endl;
	cout << "Please Enter your choice" << endl;
	cin >> choice;
	cin.ignore(250,'\n');
	if(choice >= 1 && choice <= 6)
		return choice;
	else{
		cout << "Choose a value between 1 and 6" << endl;
		return showMenu();
	}
}

void insertRecord(vector<marks>& rec)
{
    marks obj;
	char *name,*subject,*subCode;
	int rollNo,internals,finals;
	name = new char[20];
	subject = new char[20];
	subCode = new char[8];
	cout << "Enter the name of the student :" << endl;
	cin.getline(name,20);
	cout << "Enter the rollNo : "<< endl;
	cin >> rollNo;
	cin.ignore(250,'\n');
	cout << "Enter the name of the subject : " << endl;
	cin.getline(subject,20);
	cout << "Enter the subject code : " << endl;
	cin.getline(subCode,20);
	cout << "Enter the internal marks : " << endl;
	cin >> internals;
	cout << "Enter the final exam marks : " << endl;
	cin >> finals;
	cin.ignore(250,'\n');
	obj.setStuData(name,rollNo,subject);
	obj.setData(subCode,internals,finals);
	rec.push_back(obj);
	delete[] name;
	delete[] subject;
	delete[] subCode;
}

void displayRecord(vector<marks> &rec)
{
    if(rec.size()==0)
        cout << "No Entries Found" << endl;
    else
    {
        vector<marks> :: iterator it;
        cout << "               Student Record Data\n" << endl;
        for(it=rec.begin();it<rec.end();++it){
            it->showData();
            cout << endl;
        }
    }
}

void searchRecord(vector<marks> &rec)
{
    int rollNo;
    bool flag=false;
    cin >> rollNo;
    cin.ignore(250,'\n');
    vector<marks> :: iterator it;
    for(it=rec.begin();it<rec.end();++it){
        if(it->getRollNo() == rollNo){
            it->showData();
            flag=true;
            break;
        }
    }
    if(!flag)
        cout << "No Record matching the requirement found" << endl;
}

void deleteRecord(vector<marks> &rec)
{
    int rollNo;
    bool flag=false;
    cin >> rollNo;
    cin.ignore(250,'\n');
    vector<marks> :: iterator it;
    for(it=rec.begin();it<rec.end();++it){
        if(it->getRollNo() == rollNo){
            rec.erase(it);
            displayRecord(rec);
            flag=true;
            break;
        }
    }
    if(!flag)
        cout << "No Record matching the requirement found" << endl;
}

void editRecord(vector<marks> &rec)
{
    int rollNo,i=0;
    bool flag=false;
    cin >> rollNo;
    cin.ignore(250,'\n');
    vector<marks> :: iterator it;
    for(it=rec.begin();it<rec.end();++it,i++){
        if(it->getRollNo() == rollNo){
            it->showData();
            flag=true;
            break;
        }
    }
    if(!flag)
        cout << "No Record matching the requirement found" << endl;
}


/***********************************************************************
Test Cases:
Tc01:
2
Rama Krishna
140545
Maths
MA1001
43
45
2
Pavan Krishna
140541
Physics
PA2002
45
46
2
Praneeth Vikram
140635
Chemistry
CH1003
45
48
2
Vaishali
140934
Chemistry
CH1001
48
43
2
Swarna Jayanthi
140703
Computers
CA5002
45
45
***********************************************************************/
