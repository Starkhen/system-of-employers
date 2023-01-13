#pragma once
#include<iostream>
#include<string>
using namespace std;
class worker {
public:
	virtual void showInfo() = 0;//personal info
	virtual string getPosition() = 0;//get the work name
	int m_ID;
	string m_name;
	int m_apartment;
 };