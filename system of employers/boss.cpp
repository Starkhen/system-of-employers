#include "boss.h"

boss::boss(int id, string name, int apartment)
{
	this->m_apartment = apartment;
	this->m_ID = id;
	this->m_name = name;
}

void boss::showInfo()
{
	cout << "ID:" << this->m_ID
		<< "\tname:" << this->m_name
		<< "\tapartment:" << this->m_apartment
		<< "\tmission:admin the all things about the company" << endl;
}

string boss::getPosition()
{
	return string("boss");
}

