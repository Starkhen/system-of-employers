#include "employee.h"

employee::employee(int id, string name, int apartment)
{
	this->m_ID = id;
	this->m_apartment = apartment;
	this->m_name = name;
}

void employee::showInfo()
{
	cout << "ID:" << this->m_ID
		<< "\tname:" << this->m_name
		<< "\tapartment:" << this->m_apartment
		<< "\tmission:Finish the mission published by manager" << endl;
}

string employee::getPosition()
{
	return string("employee");
}
