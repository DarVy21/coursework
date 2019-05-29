#include"allFun.h"
void menuAdminStruct()
{
	cout << "1 - ����������� ��� �����" << endl;
	cout << "2 - �������� ����" << endl;
	cout << "3 - ������� ����" << endl;
	cout << "4 - ������������� ����" << endl;
	cout << "5 - �������������� �������" << endl;
	cout << "6 - ������������� �����" << endl;
	cout << "7 - ����� ������ �� ��������" << endl;
	cout << "0 - �����" << endl;
}
void menuUserStruct()
{
	cout << "1 - ����������� ��� �����" << endl;
	cout << "2 - �������������� �������" << endl;
	cout << "3 - ������������� �����" << endl;
	cout << "4 - ����� ������ �� ��������" << endl;
	cout << "0 - �����" << endl;
}
void menuUpdateRoutes()
{
	cout << "�������� ��� ��������: " << endl;
	cout << "1 - ����� �����" << endl;
	cout << "2 - ��� �����" << endl;
	cout << "3 - ����� ����������" << endl;
	cout << "4 - ����� �����������" << endl;
	cout << "5 - ����� ��������" << endl;
	cout << "6 - ������������� ��" << endl;
	cout << "0 - �����" << endl;
}
void menuSortRoutes()
{
	cout << "�������� �������� ��� ���������� : " << endl;
	cout << "1 - �� ������ ����������" << endl;
	cout << "2 - �� ������� �����������" << endl;
	cout << "3 - �� ������ �����" << endl;
	cout << "0 - �����" << endl;
}
void menuSearchRoutes()
{
	cout << "�������� �������� ��� ������ : " << endl;
	cout << "1 - �� ������ ����������" << endl;
	cout << "2 - �� ���� �����" << endl;
	cout << "3 - �� ������ �����" << endl;
	cout << "0 - �����" << endl;
}
void menuUpdateAccounts()
{
	cout << "�������� ��� �������������: " << endl;
	cout << "1 - �����" << endl;
	cout << "2 - ������" << endl;
	cout << "3 - ����" << endl;
	cout << "4 - ������" << endl;
	cout << "5 - ������������� ��" << endl;
	cout << "0 - �����" << endl;
}
void menuRole(vector<Account> &list_of_accounts, vector<Routes> &list_of_routes, int role)
{
	bool choise = true;
	int workWith;
	if (role == 1)
	{
		system("cls");
		cout << " �� ����� � ���� ������  " << endl;
		while (choise)
		{
			cout << "------------------------------���� ��������������-------------------------------" << endl << endl;
			cout << "\t1.������ � �������� ��������." << endl
				<< "\t2.������ � �������." << endl
				<< "\t0.�����." << endl;
			workWith = security_for_any_numbers_i(0, 2);
			switch (workWith)
			{

			case 1:AdminAccounts(list_of_accounts); break;

			case 2:	AdminStruct(list_of_routes); break;


			case 0: choise = false;


			}
		}
	}

	else if (role == 0)
	{
		system("cls");
		cout << " �� ����� � ���� �����  " << endl;
		UserStruct(list_of_routes);
	}
}
void menuAutorisation()
{
	vector<Account> list_of_accounts = createListOfAccounts();
	vector<Routes> list_of_routes = createListOfRoutes();
	bool choise = true;
	int temp;
	while (choise)
	{
		cout << "������������! ��� ����� ����� � �������.\n 1. ����� � ������������ �������.\n 2. ����������� ��������.\n 0. ����� " << endl;
		temp = security_for_any_numbers_i(0, 2);


		switch (temp)
		{

		case 1:access(list_of_accounts, list_of_routes); break;

		case 2:addAccount(list_of_accounts);
			cout << "�� ����������������." << endl; break;


		case 0: choise = false; break;


		}

	}
}


/*void access(vector<Account>&list_of_accounts, vector<Routes>&list_of_routes)
{
	bool flag_login = true, poisk_login = true;
	int login;
	string temp_pass, temp_login;
	while (flag_login) {
		system("cls");
		cout << "������� �����:" << endl;
		cin >> temp_login;
		for (int i = 0; i < list_of_accounts.size(); i++) {
			if (temp_login == list_of_accounts.at(i).login) {
				login = i;
				flag_login = false;
				poisk_login = false;
			}
			else {

			}
		}
		if (poisk_login) {
			cout << "�������� �����, ��� ��� ���!" << endl;
		}
		else {

		}
	}
	cout << "������� ������:";
	cin >> temp_pass;
	if (temp_pass == list_of_accounts.at(login).password) {

	}
	else {
		cout << "�������� ������!" << endl;
	}
	hello(list_of_accounts, list_of_accounts.at(login).role);
}*/

/*void hello(vector<Account>&list_of_accounts, int role)
{
	if (role == 1) {
		cout << "����� ����������, �����!" << endl;
		menuAdminAccounts(list_of_accounts);
	}
	else if (role == 0) {
		cout << "����� ����������, ������������!" << endl;

	}
	else
	{
		menuUserAccounts(list_of_accounts);
		cout << "���, ���-�� �� ���!" << endl;
	}
}*/
