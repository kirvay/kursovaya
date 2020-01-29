#pragma once
#include <iostream>
#include <iomanip>
#include "fstream"
using namespace std;
class List {
public:
	List() { head = NULL; }
	~List();
	void add(int v, int c, int d, int m, int y, const char *p = NULL, const char*t = NULL, const char *n = NULL, int pos = -1);
	void show(int v, int c);
	void delFront();
	void remove(int index);
	void clear();
	void sortDate();
	void search(const char *str);
	void saveBinary();
	void loadBinary();
	int getSize() { return Size; };
private:
	class Node {
	public:
		Node *next;
		~Node();
		int day, month, year, view, category;
		char* price, *text, *number;
		Node(int v = 0, int c = 0, int d = 0, int m = 0, int y = 0, const char* p = NULL, const char *t = NULL, const char* n = NULL, Node *pNext = NULL);
	};
	Node *head; int Size = 0;
};

