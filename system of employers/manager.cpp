#include "manager.h"

manager::manager(int id, string name, int apartment)
{
	this->m_apartment = apartment;
	this->m_ID = id;
	this->m_name = name;
}

void manager::showInfo()
{
	cout << "ID:" << this->m_ID
		<< "\tname:" << this->m_name
		<< "\tapartment:" << this->m_apartment
		<< "\tmission:Finish the mission published by boss and publish the mission to employee" << endl;
}

string manager::getPosition()
{
	return string("manager");
}
