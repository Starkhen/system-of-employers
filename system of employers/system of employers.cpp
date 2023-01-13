#include <iostream>
using namespace std;
#include "workerManager.h"
#include "worker.h"
#include "boss.h"
#include "employee.h"
#include "manager.h"
void test()
{
	worker* worker = NULL;
	worker = new employee(1, "zhangshan", 1);
	worker->showInfo();
	delete worker;
	
	worker = new manager(2, "lisi", 2);
	worker->showInfo();
	delete worker;

	worker = new boss(3, "wangwu", 3);
	worker->showInfo();
	delete worker;
}
int main() {
	workerManager wm;
	int choice;
	//test();
	while (true)
	{
		wm.showMenu();
		cout << "Please enter your choice." << endl;
		cin >> choice;
		switch (choice)
		{
			case 0://exit
				wm.exitSystem();
				break;
			case 1://add
				wm.add();
				break;
			case 2://show
				wm.show();
				break;
			case 3://del
				wm.del();
				break;
			case 4://change
				wm.change();
				break;
			case 5://find
				wm.find();
				break;
			case 6://sort
				wm.sort();
				break;
			case 7://clean
				wm.clean();
				break;
			default:
				system("cls");
				break;
		}
	}
	
	system("pause");
	return 0;
}
