#include "workerManager.h"
#include "employee.h"
#include "boss.h"
#include "manager.h"


workerManager::workerManager()
{
	
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open())
	{
		cout << "No file." << endl;
		this->m_num = 0;
		this->m_array = NULL;
		this->isempty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "empty." << endl;
		this->m_num = 0;
		this->m_array = NULL;
		this->isempty = true;
		ifs.close();
		return;
	}
	int num = this->get();
	cout << "there are " << num << endl;
	this->m_num = num;
	this->m_array = new worker * [this->m_num];
	init();
	
}

workerManager::~workerManager()
{
	if (this->m_array != NULL)
	{
		delete[] this->m_array;
	}
}
void workerManager::exitSystem()
{
	cout << "GoodBye!" << endl;
	system("pause");
	exit(0);
}
void workerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->m_num; i++)
	{
		ofs << this->m_array[i]->m_ID << " "
			<< this->m_array[i]->m_name << " "
			<< this->m_array[i]->m_apartment << endl;
	}
	ofs.close();
}
void workerManager::add()
{
	cout << "Please input the number of the workers:" << endl;
	int addNum;
	cin >> addNum;
	if (addNum > 0)
	{
		int newSize = this->m_num + addNum;
		worker** newSpace = new worker * [newSize];//open the new space
		//move ptr to new memory
		if (this->m_array != NULL)
		{
			for (int i = 0; i < this->m_num; i++)
			{
				newSpace[i] = this->m_array[i];
			}
		}
		for (int i = 0; i < addNum; i++)
		{
			int id;
			string name;
			int apartment;
			
			cout << "Please input No." << i + 1 << "id" << endl;
			cin >> id;
			cout << "name:" << endl;
			cin >> name;
			cout << "select the position:1.employee 2.manager 3.boss" << endl;
			cin >> apartment;

			worker* worker = NULL;
			switch (apartment)
			{
			case 1://employee
				worker = new employee(id, name, 1);
				break;
			case 2:
				worker = new manager(id, name, 2);
				break;
			case 3:
				worker = new boss(id, name, 3);
				break;
			default:
				cout << "there is no this position" << endl;
				break;
			}
			if (apartment == 1 || apartment == 2 || apartment == 3)
			{
				newSpace[this->m_num + i] = worker;
			}
			
		}
		delete[] this->m_array;//release the origin
		this->m_array = newSpace;
		this->m_num = newSize;
		cout << "Finish!" << endl;
		this->save();
		this->isempty = false;

	}
	else
	{
		cout << "error!" << endl;
	}
	system("pause");
	system("cls");
}
int workerManager::get()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int apartment;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> apartment)
	{
		num++;
	}
	ifs.close();
	return num;
}
void workerManager::init()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int apartment;
	int index=0;
	while (ifs>>id&&ifs>>name&&ifs>>apartment)
	{
		worker* worker = NULL;
		if (apartment == 1)
		{
			worker = new employee(id, name, apartment);
		}
		else if (apartment == 2)
		{
			worker = new manager(id, name, apartment);
		}
		else
		{
			worker = new boss(id, name, apartment);
		}
		this->m_array[index] = worker;
		index++;
	}
}
void workerManager::show()
{
	if (this->isempty)
	{
		cout << "no info" << endl;
	}
	else
	{
		for (int i = 0; i < this->m_num; i++)
		{
			this->m_array[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}
void workerManager::del()
{
	if (this->isempty)
	{
		cout << "empty" << endl;
	}
	else
	{
		cout << "Please input id:" << endl;
		int id = 0;
		cin >> id;
		int index = this->isexist(id);
		if (index != -1)
		{
			for (int i = index; i < this->m_num - 1; i++)
			{
				this->m_array[i] = this->m_array[i + 1];
			}
			this->m_num--;
			this->save();
			cout << "Finish" << endl;
		}
		else
		{
			cout << "no this id" << endl;
		}
		system("pause");
		system("cls");
	}
}
int workerManager::isexist(int id)
{
	int index = -1;
	for (int i = 0; i < this->m_num; i++)
	{
		if (this->m_array[i]->m_ID == id)
		{
			index = i;
			break;
		}
	}
	return index;
}
void workerManager::change()
{
	if (this->isempty)
	{
		cout << "no info" << endl;
	}
	else
	{
		cout << "input the id" << endl;
		int id;
		cin >> id;
		int ret = this->isexist(id);
		if (ret != -1)
		{
			delete this->m_array[ret];
			int newid = 0;
			string newname;
			int newapartment;
			cout << "newid:" << endl;
			cin >> newid;
			cout << "newname:" << endl;
			cin >> newname;
			cout << "newapartment:" << endl;
			cin >> newapartment;
			worker* worker = NULL;
			switch (newapartment)
			{
			case 1://employee
				worker = new employee(newid, newname, 1);
				break;
			case 2:
				worker = new manager(newid, newname, 2);
				break;
			case 3:
				worker = new boss(newid, newname, 3);
				break;
			default:
				cout << "there is no this position" << endl;
				break;
			}
			this->m_array[ret] = worker;
			cout << "finish" << endl;
			this->save();
		}
		else
		{
			cout << "no info" << endl;
		}
		system("pause");
		system("cls");
	}
}
void workerManager::find()
{
	if (this->isempty)
	{
		cout << "no info" << endl;
	}
	else
	{
		cout << "input id:" << endl;
		int id;
		cin >> id;
		int ret = this->isexist(id);
		if (ret != -1)
		{
			this->m_array[ret]->showInfo();
		}
		else
		{
			cout << "no this man" << endl;
		}
		system("pause");
		system("cls");
	}

}
void workerManager::sort()
{
	if (this->isempty)
	{
		cout << "no info" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "1.up 2.down,select your choice" << endl;
		int choice;
		cin >> choice;
		if (choice == 1)
		{
			for (int i = 0; i < m_num; i++)
			{
				for (int j = i + 1; j < this->m_num; j++)
				{
					if (this->m_array[i]->m_ID > this->m_array[j]->m_ID)
					{
						worker* temp = m_array[i];
						m_array[i] = m_array[j];
						m_array[j] = temp;
					}
				}
			}
		}
		else if (choice == 2)
		{
			for (int i = 0; i < m_num; i++)
			{
				for (int j = i + 1; j < this->m_num; j++)
				{
					if (this->m_array[j]->m_ID > this->m_array[i]->m_ID)
					{
						worker* temp = m_array[i];
						m_array[i] = m_array[j];
						m_array[j] = temp;
					}
				}
			}
		}
		cout << "finish" << endl;
		this->save();
		this->show();
	}
}
void workerManager::clean()
{
	cout << "sure?\t1.yes2.no" << endl;
	int choice = 0;
	cin >> choice;
	if (choice == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_array != NULL)
		{
			for (int i = 0; i < this->m_num; i++)
			{
				delete this->m_array[i];
			}
			this->m_num = 0;
			delete[] this->m_array;
			this->m_array = NULL;
			this->isempty = true;
		}
		cout << "ok" << endl;
	}
	system("pause");
	system("cls");
}
void workerManager::showMenu()
{
	cout << "**************************************************************" << endl;
	cout << "Welcome to use the system of the administartion of the worker!" << endl;
	cout << "****************0.exit the system*****************************" << endl;
	cout << "****************1.add the information*************************" << endl;
	cout << "****************2.show the info*******************************" << endl;
	cout << "****************3.del the worker******************************" << endl;
	cout << "****************4.change the info*****************************" << endl;
	cout << "****************5.find the info*******************************" << endl;
	cout << "****************6.sort****************************************" << endl;
	cout << "****************7.clean all***********************************" << endl;
	cout << "**************************************************************" << endl;
	cout << endl;
}
