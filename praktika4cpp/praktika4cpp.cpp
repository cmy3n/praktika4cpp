#include <iostream>
#include <string>
#include <Windows.h>
#include <algorithm>
#include <random>
using namespace std;

string reverseStr(string stroka)
{
	reverse(stroka.begin(), stroka.end());
	return stroka;
}

string deleteVowels(string stroka)
{
	string withoutVowels = "";
	string vowels = "aeiouAEIOUаеёиоуыэюяАЕЁИОУЫЭЮЯ";

	for (char c : stroka) {
		if (vowels.find(c) == string::npos) {
			withoutVowels += c;
		}
	}

	return withoutVowels;
}

string deleteConsonants(string stroka)
{
	string withoutConsonants = "";
	string consonants = "bcdfghjklmnpqrstvwxzBCDFGHJKLMNPQRSTVWXZбвгджзйклмнпрстфхцчшщБВГДЖЗЙКЛМНПРСТФХЦЧШЩ";

	for (char c : stroka) {
		if (consonants.find(c) == string::npos) {
			withoutConsonants += c;
		}
	}

	return withoutConsonants;
}

string shuffleStr(string stroka)
{
	random_device rd;
	mt19937 g(rd());
	shuffle(stroka.begin(), stroka.end(), g);

	return stroka;
}

int main()
{
	SetConsoleCP(1251);
	setlocale(LC_ALL, "Rus");

	int oper;
	string str;

	do
	{
		cout << "1. Вывод слова задом наперед\n2. Вывод слова без гласных\n3. Вывод слова без согласных\n4. Перемешать буквы в слове\n5. Выход\n\nВыберите действие: ";
		cin >> oper;

		switch (oper) {
		case 1:
			cout << "\nВведите слово: ";
			cin >> str;
			cout << "\nСлово задом наперед: " << reverseStr(str) << endl << endl;
			break;
		case 2:
			cout << "\nВведите слово: ";
			cin >> str;
			cout << "\nСлово без гласных: " << deleteVowels(str) << endl << endl;
			break;
		case 3:
			cout << "\nВведите слово: ";
			cin >> str;
			cout << "\nСлово без согласных: " << deleteConsonants(str) << endl << endl;
			break;
		case 4:
			cout << "\nВведите слово: ";
			cin >> str;
			cout << "\nПеремешанное слово: " << shuffleStr(str) << endl << endl;
			break;
		case 5:
			cout << "\nВыход...";
			break;
		default:
			cout << "\nНеверная операция!\n\n";
			break;
		}

	} while (oper != 5 );

	return 0;
}