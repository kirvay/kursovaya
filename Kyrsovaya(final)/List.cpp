#include "pch.h"
#include "List.h"


//Constructor Node
List::Node::Node(int v, int c, int d, int m, int y, const char * p, const char * t, const char * n, Node * pNext)
{
	int j = 0;
	this->view = v; this->category = c; this->day = d; this->month = m; this->year = y; this->next = pNext;
	if (p == NULL) {
		try {
			price = new char[1];
		}
		catch (bad_alloc xa) {
			cout << "Allocation eror\n";
			exit(1);
		}
		price[0] = '\0';
	}
	else {
		try {
			price = new char[strlen(p) + 1];
		}
		catch (bad_alloc xa) {
			cout << "Allocation eror\n";
			exit(1);
		}
		for (int i = 0; i < strlen(p); i++) price[i] = p[i];
		price[strlen(p)] = '\0';
	}
	if (t == NULL) {
		try {
			text = new char[1];
		}
		catch (bad_alloc xa) {
			cout << "Allocation eror\n";
			exit(1);
		}
		text[0] = '\0';
	}
	else {
		try {
			text = new char[strlen(t) + 1];
		}
		catch (bad_alloc xa) {
			cout << "Allocation eror\n";
			exit(1);
		}
		for (int i = 0; i < strlen(t); i++) text[i] = t[i];
		text[strlen(t)] = '\0';
	}
	if (n == NULL) {
		try {
			number = new char[1];
		}
		catch (bad_alloc xa) {
			cout << "Allocation eror\n";
			exit(1);
		}
		number[0] = '\0';
	}
	else {
		try {
			number = new char[strlen(n) + 1];
		}
		catch (bad_alloc xa) {
			cout << "Allocation eror\n";
			exit(1);
		}
		for (int i = 0; i < strlen(n); i++) number[i] = n[i];
		number[strlen(n)] = '\0';
	}

}
// end Constructor Node

//Destructor Node
List::Node::~Node() {
	delete[]price;
	delete[]text;
	delete[]number;
}
//end Destructor Node

//Destructor List
List::~List()
{
	Node *prev;
	while (head) {
		prev = head->next;
		delete head;
		head = prev;
	}
}
//end Destructor List

// Add element(to the tail)
void List::add(int v, int c, int d, int m, int y, const char *p, const char*t, const char *n, int pos) {
	if (pos == -1) {
		if (head == NULL) {
			try {
				head = new Node(v, c, d, m, y, p, t, n);
			}
			catch (bad_alloc xa) {
				cout << "Allocation eror\n";
				exit(1);
			}
		}
		else {
			Node *temp = this->head;
			while (temp->next != NULL) {
				temp = temp->next;
			}
			try {
				temp->next = new Node(v, c, d, m, y, p, t, n);
			}
			catch (bad_alloc xa) {
				cout << "Allocation eror\n";
				exit(1);
			}

		}
		Size++;
	}
	else {
		if (pos == 1) {
			Node * temp = this->head;
			try {
				head = new Node(v, c, d, m, y, p, t, n, temp);
			}
			catch (bad_alloc xa) {
				cout << "Allocation eror\n"; exit(1);
			}
			Size++;
		}
		else {
			Node *current = this->head, *prev = NULL;
			for (int i = 0; i < pos - 1; i++) { prev = current; current = current->next; }
			try {
				Node *temp = new Node(v, c, d, m, y, p, t, n, prev->next);
				prev->next = temp;
			}
			catch (bad_alloc xa) {
				cout << "Allocation error\n"; exit(1);
			}

			Size++;
		}

	}
	cout << "\nОбъявление добавлено.\n";
}
// end Add element(to the tail)

//Delete head
void List::delFront() {
	Node *temp = head;
	head = head->next;
	delete temp;
	Size--;
}
//end Delete head

//Clear list
void List::clear() {
	while (Size) delFront();
	cout << "\nВсе объявления были удалены.\n";
}
// end Clear list

// Delete by logical number
void List::remove(int index) {

	if (index == 0) delFront();
	else {
		Node *prev = this->head;
		for (int i = 0; i < index - 1; i++) prev = prev->next;
		Node *temp = prev->next;
		prev->next = temp->next;
		delete temp;
		Size--;
	}
	cout << "\nУдалено.\n";
}
// end Delete by logical number

//Search for ads
void List::search(const char *str) {
	int count = 0, countAdd = 0;
	Node *temp = head;
	cout << "\nТекст объявнления" << setw(38) << "Цена/Бюджет" << setw(20) << "Телефон" << setw(20) << "Дата подачи\n";
	while (temp != NULL) {
		for (int i = 0; i < strlen(temp->text); i++) {
			if (str[0] == temp->text[i]) {
				for (int j = 0; j < strlen(str); j++, i++) {
					if (str[j] == temp->text[i]) count++;
					else { count = 0; break; }
				}
			}
			if (count == strlen(str)) {
				//cout << endl;			
				cout << temp->text << setw(38) << temp->price << setw(20) << temp->number << setw(20) << temp->day << '.' << temp->month << '.' << temp->year << '\n';
				count = 0;
				countAdd++;
			}
		}
		temp = temp->next;
	}
	if (!countAdd) cout << "\nНичего не найдено.";

}
//end Search for ads

//Sort data
void List::sortDate() {
	Node * temp = head;
	Node *current;
	while (temp != NULL) {
		current = temp->next;
		while (current != NULL) {
			if (temp->year < current->year) {
				swap(temp->day, current->day);
				swap(temp->month, current->month);
				swap(temp->year, current->year);
				swap(temp->text, current->text);
				swap(temp->category, current->category);
				swap(temp->number, current->number);
				swap(temp->price, current->price);
				swap(temp->view, current->view);

			}
			else if (temp->year == current->year) {
				if (temp->month < current->month) {
					swap(temp->day, current->day);
					swap(temp->month, current->month);
					swap(temp->year, current->year);
					swap(temp->text, current->text);
					swap(temp->category, current->category);
					swap(temp->number, current->number);
					swap(temp->price, current->price);
					swap(temp->view, current->view);
				}
				else if (temp->month == current->month) {
					if (temp->day < current->day) {
						swap(temp->day, current->day);
						swap(temp->month, current->month);
						swap(temp->year, current->year);
						swap(temp->text, current->text);
						swap(temp->category, current->category);
						swap(temp->number, current->number);
						swap(temp->price, current->price);
						swap(temp->view, current->view);
					}
				}

			}
			current = current->next;
		}
		temp = temp->next;
	}
	cout << "\nСортировка прошла успешно!";
}
// end Sort data

//Show + sort
void List::show(int v, int c) {
	Node * temp = head;
	cout << endl;
	cout << "Текст объявнления" << setw(38) << "Цена/Бюджет" << setw(20) << "Телефон" << setw(20) << "Дата подачи\n";
	if (v == 3 && c == 4) {
		while (temp != NULL) {
			cout << temp->text << setw(38) << temp->price << setw(20) << temp->number << setw(20) << temp->day << '.' << temp->month << '.' << temp->year << '\n';
			temp = temp->next;
		}
		return;
	}
	else if (v == 1 && c == 1) {
		while (temp != NULL) {
			if (temp->view == v && temp->category == c) {
				cout << temp->text << setw(38) << temp->price << setw(20) << temp->number << setw(20) << temp->day << '.' << temp->month << '.' << temp->year << '\n';
			}
			temp = temp->next;
		}
		return;
	}
	else if (v == 1 && c == 2) {
		while (temp != NULL) {
			if (temp->view == v && temp->category == c) {
				cout << temp->text << setw(38) << temp->price << setw(20) << temp->number << setw(20) << temp->day << '.' << temp->month << '.' << temp->year << '\n';
			}
			temp = temp->next;
		}
		return;
	}
	else if (v == 1 && c == 3) {
		while (temp != NULL) {
			if (temp->view == v && temp->category == c) {
				cout << temp->text << setw(38) << temp->price << setw(20) << temp->number << setw(20) << temp->day << '.' << temp->month << '.' << temp->year << '\n';
			}
			temp = temp->next;
		}
		return;
	}
	else if (v == 1 && c == 4) {
		while (temp != NULL) {
			if (temp->view == v) {
				cout << temp->text << setw(38) << temp->price << setw(20) << temp->number << setw(20) << temp->day << '.' << temp->month << '.' << temp->year << '\n';
			}
			temp = temp->next;
		}
		return;
	}
	else if (v == 2 && c == 1) {
		while (temp != NULL) {
			if (temp->view == v && temp->category == c) {
				cout << temp->text << setw(38) << temp->price << setw(20) << temp->number << setw(20) << temp->day << '.' << temp->month << '.' << temp->year << '\n';
			}
			temp = temp->next;
		}
		return;
	}
	else if (v == 2 && c == 2) {
		while (temp != NULL) {
			if (temp->view == v && temp->category == c) {
				cout << temp->text << setw(38) << temp->price << setw(20) << temp->number << setw(20) << temp->day << '.' << temp->month << '.' << temp->year << '\n';
			}
			temp = temp->next;
		}
		return;
	}
	else if (v == 2 && c == 3) {
		while (temp != NULL) {
			if (temp->view == v && temp->category == c) {
				cout << temp->text << setw(38) << temp->price << setw(20) << temp->number << setw(20) << temp->day << '.' << temp->month << '.' << temp->year << '\n';
			}
			temp = temp->next;
		}
		return;
	}
	else if (v == 2 && c == 4) {
		while (temp != NULL) {
			if (temp->view == v) {
				cout << temp->text << setw(38) << temp->price << setw(20) << temp->number << setw(20) << temp->day << '.' << temp->month << '.' << temp->year << '\n';
			}
			temp = temp->next;
		}
		return;
	}
	else if (v == 3 && c == 1) {
		while (temp != NULL) {
			if (temp->category == c) {
				cout << temp->text << setw(38) << temp->price << setw(20) << temp->number << setw(20) << temp->day << '.' << temp->month << '.' << temp->year << '\n';
			}
			temp = temp->next;
		}
		return;
	}
	else if (v == 3 && c == 2) {
		while (temp != NULL) {
			if (temp->category == c) {
				cout << temp->text << setw(38) << temp->price << setw(20) << temp->number << setw(20) << temp->day << '.' << temp->month << '.' << temp->year << '\n';
			}
			temp = temp->next;
		}
		return;
	}
	else if (v == 3 && c == 3) {
		while (temp != NULL) {
			if (temp->category == c) {
				cout << temp->text << setw(38) << temp->price << setw(20) << temp->number << setw(20) << temp->day << '.' << temp->month << '.' << temp->year << '\n';
			}
			temp = temp->next;
		}
		return;
	}
}
// end Show + sort

// Save date
void List::saveBinary() {
	Node *current = head;
	int temp;
	ofstream file("bina.bin", ios::out | ios::binary);
	if (!file) { return; };
	int lenght;
	while (current != NULL) {
		temp = current->view;
		file.write((char*)&temp, sizeof(int));
		temp = current->category;
		file.write((char*)&temp, sizeof(int));
		temp = current->day;
		file.write((char*)&temp, sizeof(int));
		temp = current->month;
		file.write((char*)&temp, sizeof(int));
		temp = current->year;
		file.write((char*)&temp, sizeof(int));
		lenght = strlen(current->text);
		file.write((char*)&lenght, sizeof(int));
		file.write(current->text, lenght);
		lenght = strlen(current->number);
		file.write((char*)&lenght, sizeof(int));
		file.write(current->number, lenght);
		lenght = strlen(current->price);
		file.write((char*)&lenght, sizeof(int));
		file.write(current->price, lenght);
		current = current->next;
	}
	cout << "\nСохранено.\n";
	file.close();
}
//end Save date

// load Date
void List::loadBinary() {
	ifstream file("bina.bin", ios::in | ios::binary);
	if (!file) return;
	file.seekg(0);
	while (!file.eof()) {
		int v;
		file.read((char*)&v, sizeof(int));
		int c;
		file.read((char*)&c, sizeof(int));
		int d;
		file.read((char*)&d, sizeof(int));
		int m;
		file.read((char*)&m, sizeof(int));
		int y;
		file.read((char*)&y, sizeof(int));
		int lenght;
		file.read((char*)&lenght, sizeof(int));
		char *t = new char[lenght + 1];
		file.read(t, lenght);
		t[lenght] = '\0';
		file.read((char*)&lenght, sizeof(int));
		char *n = new char[lenght + 1];
		file.read(n, lenght);
		n[lenght] = '\0';
		file.read((char*)&lenght, sizeof(int));
		char *p = new char[lenght + 1];
		file.read(p, lenght);
		p[lenght] = '\0';
		this->add(v, c, d, m, y, p, t, n);
	}
	remove(getSize() - 1);
	file.close();
	cout << "\nЗагруженно.\n";
}
//end load Date