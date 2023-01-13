#pragma once
#include <iostream>
#include"worker.h"
#include<fstream>
#define FILENAME "empFile.txt"

using namespace std;

class workerManager
{
public:
	workerManager();
	void showMenu();
	~workerManager();
	void exitSystem();
	void save();
	void add();
	int get();
	void init();
	void show();
	void del();
	int isexist(int id);
	void change();
	void find();
	void sort();
	void clean();
	
public:
	int m_num;
	worker** m_array;//the ptr of the array
	bool isempty;
};