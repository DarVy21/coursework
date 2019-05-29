#include"allFun.h"
double unnumericInputProtection(double &number)
{
	while (true)
	{
		cin >> number;

		if (cin.good()) break;
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Некорректный ввод!" << endl;
		}
	}
	return number;

}
int unnumericInputProtection(int &number)
{
	while (true)
	{
		cin >> number;

		if (cin.good()) break;
		else
		{
			cin.clear();
			cin.ignore(256, '\n');
			cout << "Некорректный ввод!" << endl;
		}
	}
	return number;
}
int getCountOfStucturesInFile(string file_path)
{
	ifstream file(file_path, ios::in); // Открыли текстовый файл для  чтения
	int number_of_strings = 0;
		if (!file.is_open())
		{
			file.close();
			return 1;
		}
	
		else if (file.is_open())
		{

			string buffer;
			while (getline(file, buffer))
				number_of_strings++;


			file.close();
			return number_of_strings;
		}
}

double security_for_positiv_numbers_d(int border1, int border2)
{
	double A;
	while (!(cin >> A) || A <= 0 || A< border1 || A>border2 || cin.get() != '\n')
	{
		cout << "Неверный вввод! Попробуйте снова.\n";
		cin.clear();
		cin.ignore(256, '\n');
	}
	return A;
}
string inputAnyStringOfChars()///ввод строки с проверкой
{
	char ch;
	int next = 0;
	string name = "";
	while (next < SIZE_NAME - 1)
	{
		ch = _getch();
		if ((ch == 13 || ch == 32) && name.size() > 3) break;//в константу
		if (ch == 8 && name != ""&& ch != '\n') {
			name.pop_back();
			cout << ch;
		}
		if (ch != 8 && ch != '\n' && ch != ' ')
		{
			name += ch;
			next++;
			cout << ch;
		}
	}
	cout << endl;
	return name;
}
int security_for_any_numbers_i(int border1, int border2)//проверка с границами
{
	int A;
	while (!(cin >> A) || A< border1 || A>border2 || cin.get() != '\n')
	{
		cout << "Неверный вввод! Попробуйте снова.\n";
		cin.clear();
		cin.ignore(256, '\n');
	}
	return A;
}
int security_for_any_numbers_i_with_message(int border1, int border2, string message)
{
	int A;
	while (!(cin >> A) || A< border1 || A>border2 || cin.get() != '\n')
	{
		cout << message << endl;
		cin.clear();
		cin.ignore(256, '\n');
	}
	return A;
}
int security_for_positiv_numbers_i(int border1, int border2)
{
	int A;
	while (!(cin >> A) || A <= 0 || cin.get() != '\n' || A< border1 || A>border2)
	{
		cout << "Неверный вввод! Попробуйте снова.\n";
		cin.clear();
		cin.ignore(256, '\n');
	}
	return A;
}
