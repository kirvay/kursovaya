// Kyrsovaya(final).cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "List.h"
#include <string>
using namespace std;

void menu(List &lst);
int main()
{
	setlocale(LC_ALL, "rus");
	List lst;
	menu(lst);
	return 0;
}

void menu(List &lst) {
	string tt, pp, nn, str;
	int choose, d, m, y, v, c, position;
	const char *t, *p, *n, *str2;
	do {
		while (true) {
			cout << "\nКоличество объявлений: " << lst.getSize();
			cout << "\n\n1)Добавить объявление\n2)Показать объявления\n3)Удалить объявление\n4)Сортировать по дате\n";
			cout << "5)Поиск по тексту объявления\n6)Сохранить данные\n7)Загрузить данные\n8)Вставка по логическому номеру\n0)Выйти\n";
			cout << "\nВыберите нужный пункт меню: ";
			cin >> choose;
			if (cin.fail()) {
				cout << "\nТакого пункта нет в меню!\n";
				cin.clear();
				cin.ignore(32767, '\n');
			}
			else break;
		}
		cin.clear();
		cin.ignore(32767, '\n');
		switch (choose)
		{
		case 1:
			while (true)
			{
				cout << "\n\nВыберите категорию:\n1)Купилю\n2)Продам\n3)Вернуться в меню\n";
				cin >> v;
				if (cin.fail() || (v != 1 && v != 2 && v != 3)) {
					cout << "\nНеверное значение!\n";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else { cin.ignore(32767, '\n'); break; }
			}
			if (v == 3) break;
			while (true)
			{
				cout << "\n\nВыберите рубрику:\n1)Транспорт\n2)Недвижимость\n3)Материалы\n";
				cin >> c;
				if (cin.fail() || (c != 1 && c != 2 && c != 3)) {
					cout << "\nНеверное значение!\n";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else { cin.ignore(32767, '\n'); break; }
			}
			cout << "\n\nВведите текст объявления: ";
			getline(cin, tt);
			t = new char[tt.size()];
			t = tt.c_str();
			if (v == 1)cout << "Введите бюджет: ";
			else cout << "Введите цену: ";
			getline(cin, pp);
			p = new char[pp.size()];
			p = pp.c_str();
			//cin.ignore();
			//cin.clear();
			cout << "Введите номер телефона: ";
			getline(cin, nn);
			n = new char[nn.size()];
			n = nn.c_str();
			while (true)
			{
				cout << "Введите число: ";
				cin >> d;
				if (cin.fail() || (d < 1 || d>31)) {
					cout << "\nНеверное значение!\n";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else { cin.ignore(32767, '\n');  break; }
			}
			while (true)
			{
				cout << "Введите месяц: ";
				cin >> m;
				if (cin.fail() || (m < 1 || m>12)) {
					cout << "\nНеверное значение!\n";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else { cin.ignore(32767, '\n');  break; }
			}
			while (true)
			{
				cout << "Введите год: ";
				cin >> y;
				if (cin.fail() || (y > 2020)) {
					cout << "\nНеверное значение!\n";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else { cin.ignore(32767, '\n');  break; }
			}
			cout << endl;
			lst.add(v, c, d, m, y, p, t, n);
			break;
		case 2:
			if (!lst.getSize()) { cout << "Объявлений нет.\n"; break; }
			while (true)
			{
				cout << "\n\nВыберите категорию:\n1)Куплю\n2)Продам\n3)Показать все\n4)Вернуться в меню\n";
				cin >> v;
				if (cin.fail() || (v > 4 || v < 1)) {
					cout << "\nНеверное значение!\n";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else { cin.ignore(32767, '\n');  break; }
			}
			if (v == 4) break;
			while (true)
			{
				cout << "\n\nВыберите рубрику:\n1)Транспорт\n2)Недвижимость\n3)Материалы\n4)Показать все\n";
				cin >> c;
				if (cin.fail() || (c > 4 || c < 1)) {
					cout << "\nНеверное значение!\n";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else { cin.ignore(32767, '\n');  break; }
			}
			lst.show(v, c);
			//for (int i = 0; i < lst.getSize(); i++) lst[i];
			break;
		case 3:
			if (!lst.getSize()) {
				cout << "\nОбъявлений нет.\n"; break;
			}
			while (true)
			{
				cout << "\n1)Удалить по логическому номеру\n2)Удалить все объявления\n3)Отмена\n";
				cin >> v;
				if (cin.fail() || (v > 3 || v < 1)) {
					cout << "\nНеверное значение!\n";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else { cin.ignore(32767, '\n');  break; }
			}
			if (v == 3) break;
			if (v == 1) {
				while (true)
				{
					cout << "Введите номер объявления(всего объвлений: " << lst.getSize() << "): ";
					cin >> c;
					if (cin.fail() || ((c < 1) || (c > lst.getSize()))) {
						cout << "\nНеверное значение!\n";
						cin.clear();
						cin.ignore(32767, '\n');
					}
					else { cin.ignore(32767, '\n');  break; }
				}
				lst.remove(--c);
			}
			else lst.clear();
			break;
		case 4:
			if (!lst.getSize()) {
				cout << "\nОбъявлений нет.\n"; break;
			}
			cout << endl;
			lst.sortDate();
			break;
		case 5:
			if (!lst.getSize()) {
				cout << "\nОбъявлений нет.\n"; break;
			}
			cout << endl << "Введите текст/слово: ";
			getline(cin, str);
			str2 = new char[str.size() + 1];
			str2 = str.c_str();
			lst.search(str2);
			break;
		case 6:	lst.saveBinary();
			break;
		case 7: lst.loadBinary();
			break;
		case 8:
			while (true)
			{
				cout << "\n\nВыберите позицию( всего объявлений: " << lst.getSize() << " ):";
				cin >> position;
				//if (position == 1 && lst.getSize() == 0) break;
				if (cin.fail() || ((position <= 0) || (position - 1 > lst.getSize()))) {
					cout << "\nНеверное значение!\n";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else { cin.ignore(32767, '\n'); break; }
			}
			while (true)
			{
				cout << "\n\nВыберите категорию:\n1)Купилю\n2)Продам\n3)Вернуться в меню\n";
				cin >> v;
				if (cin.fail() || (v != 1 && v != 2 && v != 3)) {
					cout << "\nНеверное значение!\n";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else { cin.ignore(32767, '\n'); break; }
			}
			if (v == 3) break;
			while (true)
			{
				cout << "\n\nВыберите рубрику:\n1)Транспорт\n2)Недвижимость\n3)Материалы\n";
				cin >> c;
				if (cin.fail() || (c != 1 && c != 2 && c != 3)) {
					cout << "\nНеверное значение!\n";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else { cin.ignore(32767, '\n'); break; }
			}
			cout << "\n\nВведите текст объявления: ";
			getline(cin, tt);
			t = new char[tt.size()];
			t = tt.c_str();
			if (v == 1)cout << "Введите бюджет: ";
			else cout << "Введите цену: ";
			getline(cin, pp);
			p = new char[pp.size()];
			p = pp.c_str();
			//cin.ignore();
			//cin.clear();
			cout << "Введите номер телефона: ";
			getline(cin, nn);
			n = new char[nn.size()];
			n = nn.c_str();
			while (true)
			{
				cout << "Введите число: ";
				cin >> d;
				if (cin.fail() || (d < 1 || d>31)) {
					cout << "\nНеверное значение!\n";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else { cin.ignore(32767, '\n');  break; }
			}
			while (true)
			{
				cout << "Введите месяц: ";
				cin >> m;
				if (cin.fail() || (m < 1 || m>12)) {
					cout << "\nНеверное значение!\n";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else { cin.ignore(32767, '\n');  break; }
			}
			while (true)
			{
				cout << "Введите год: ";
				cin >> y;
				if (cin.fail() || (y > 2020)) {
					cout << "\nНеверное значение!\n";
					cin.clear();
					cin.ignore(32767, '\n');
				}
				else { cin.ignore(32767, '\n');  break; }
			}
			cout << endl;
			lst.add(v, c, d, m, y, p, t, n, position);
			break;
		case 0: return;
			break;
		default: cout << "Такого пункта нет в меню!";
			break;
		}

	} while (choose != 0);
}
