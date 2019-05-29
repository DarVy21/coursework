#include"allFun.h"
void access(vector<Account> &list_of_accounts, vector<Routes> &list_of_routes) //���� ��� �����������
{
	int temp;
	bool flagAccess = true, searchAccess = true;
	string login;//������ �����
	string password;//������ ������
	string passwordAgain;

	while (flagAccess)
	{
		cout << "������� �����: ";
		login = inputAnyStringOfChars();
		cout << endl;
		cout << "������� ������: ";
		password = input_password();
		cout << endl;
		for (int i = 0; i < list_of_accounts.size(); i++)
		{
			if (list_of_accounts.at(i).login == login && list_of_accounts.at(i).salted_hash_password == myhash(password + list_of_accounts.at(i).salt))
			{
				//cout << "���� ������� ��������!" << endl;
				flagAccess = false;
				searchAccess = false;
				menuRole(list_of_accounts, list_of_routes, list_of_accounts.at(i).role);

			}
		}
		if (searchAccess) cout << "�������� ����� �/��� ������. ���������� ������ �����." << endl;
	}
}



	
void writeFileAccounts(vector<Account>&list_of_accounts)
{
	ofstream fout(FILE_OF_ACCOUNTS, ios::out);
	for (int i = 0; i < list_of_accounts.size(); i++)
	{
		fout << list_of_accounts.at(i).login << " "
			<< list_of_accounts.at(i).salted_hash_password << " "
			<< list_of_accounts.at(i).salt << " "
			<< list_of_accounts.at(i).role << " "
			<< list_of_accounts.at(i).access;
		if (i < list_of_accounts.size() - 1)
		{
			fout << endl;
		}
	}
	
	fout.close();
}
void writeEndFileAccounts(Account new_account)
{
	ofstream fadd(FILE_OF_ACCOUNTS, ios::app);
	fadd << endl;
	fadd << new_account.login << " "
		<< new_account.salted_hash_password << " "
		<< new_account.salt << " "
		<< new_account.role << " "
		<< new_account.access;
	fadd.close();
}
void showAccounts(vector<Account>list_of_accounts)
{
	header_of_ACCOUNT();
	for (int i = 0; i < list_of_accounts.size(); i++)
	{
		cout << setfill(' ') << setw(2) << "|" << setfill('-') << setw(107) << "|" << endl;
		cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') <<
			std::setw(11) << i + 1 <<
			std::setw(19) << std::left << list_of_accounts.at(i).login <<
			std::setw(20) << std::left << list_of_accounts.at(i).role <<
			std::setw(20) << std::left << list_of_accounts.at(i).access << endl;
		cout << setfill(' ') << setw(2) << "|" << setfill('-') << setw(107) << "|" << endl;
		cout << endl;
	}
}

vector<Account> createListOfAccounts()//�������� ������� ��������
{
	int n = getCountOfStucturesInFile(FILE_OF_ACCOUNTS);
	vector<Account> list_of_accounts(n);
	
	ifstream file(FILE_OF_ACCOUNTS, ios::in); //������� ���� ��� ������
	if (!file.is_open())
	{
		list_of_accounts.at(0).login = "admin";
		list_of_accounts.at(0).salt = salt();
		list_of_accounts.at(0).salted_hash_password = myhash("admin" + list_of_accounts.at(0).salt);
		list_of_accounts.at(0).role = 1;
		list_of_accounts.at(0).access = 1;
		writeFileAccounts(list_of_accounts);
	}
	else
	{
		while (!file.eof())
		{
			for (int i = 0; i < list_of_accounts.size(); i++) {
				file >> list_of_accounts.at(i).login
					>> list_of_accounts.at(i).salted_hash_password
					>> list_of_accounts.at(i).salt
					>> list_of_accounts.at(i).role
					>> list_of_accounts.at(i).access;
			}
		}
	}
	file.close();
	return list_of_accounts;
}
void addAccount(vector<Account>&list_of_accounts)
{
	string login;//������ �����
	string password;//������ ������
	string passwordAgain;
	cout << "������� ����� (������� 5 ������): ";
	login = inputAnyStringOfChars();
	for (int i = 0; i < list_of_accounts.size(); i++)
	{
		if (list_of_accounts.at(i).login == login)
		{
			cout << "\n������ ����� �����. ���������� ������ ������." << endl;
			login = inputAnyStringOfChars();
		}
	}
	int count = 0;
	do {
		if (count != 0)
		{
			cout << "��������� ������ �� ���������!" << endl;
		}
		cout << "������� ������ (������� 5 ������): ";
		password = input_password();
		cout << endl;
		cout << "��������� ������: ";
		passwordAgain = input_password();
		cout << endl;
		count++;
	} while (password != passwordAgain);
	Account account_temp;
	account_temp.login = login;
	account_temp.salt = salt();
	account_temp.salted_hash_password = myhash(password + account_temp.salt);
	account_temp.role = 0;
	account_temp.access = 0;
	list_of_accounts.push_back(account_temp);
	writeEndFileAccounts(account_temp);
	cout << "������� ������ ������� ���������!" << endl;
	

}
void delAccount(vector<Account>&list_of_accounts)
{
	showAccounts(list_of_accounts);
	int delAccount;
	int count = 0;//�������
	cout << "������� ����� ��������, ������� ����������� �������: ";
	delAccount = security_for_any_numbers_i_with_message(1, list_of_accounts.size(), "�������� ����!������� ����� ��������, ������� ����������� �������: ");
	cout << "�� �������, ��� ������ ������� ���� �������?" << endl;
	int yes_or_no;
	cout << "1.��" << endl << "2.���" << endl;
	yes_or_no = security_for_positiv_numbers_i(1, 2);
	switch (yes_or_no)
	{
	case 1:
	{
		if (list_of_accounts.at(delAccount - 1).role == 1)
		{
			for (int i = 0; i < list_of_accounts.size(); i++)
			{
				if (list_of_accounts.at(i).role == 1)
				{
					count++;
				}
			}

			if (count > 1)
			{
				list_of_accounts.erase(list_of_accounts.begin() + delAccount - 1);
				cout << "������� ������� ������." << endl;
				writeFileAccounts(list_of_accounts);
			}
			else if (count == 1)
			{
				cout << "�� ������������ �������������, � �� ������ ������� ���� �������." << endl;
			}
		}
		else
		{
			list_of_accounts.erase(list_of_accounts.begin() + delAccount - 1);
			cout << "������� ������� ������." << endl;
			writeFileAccounts(list_of_accounts);
		}

		break;
	}
	case 2:
	{
		cout << "�� �������� ��������." << endl;
		break;
	}
	}
	////////////////////////////////////
	/*string dellogin;
	cout << "�������� ����� ����� �������: ";
	cin >> dellogin;
	int i = 0;

	bool flag = true;
	while (flag && i < list_of_accounts.size())
	{
		if (list_of_accounts.at(i).login == dellogin)
		{
			flag = false;
			

				list_of_accounts.erase(list_of_accounts.begin() + i);
			
		}
		else
		{
			i++;
		}
	}
	if (flag)
	{
		cout << "������ �� �������" << endl;
	}*/

}
void updateAccount(vector<Account>&list_of_accounts)
{
	int updateAccount, updateItem;
	showAccounts(list_of_accounts);
	cout << "������� ����� ��������, ������� ����������� �������������: ";
	updateAccount = security_for_any_numbers_i_with_message(1, list_of_accounts.size(), "�������� ����!������� ����� ��������, ������� ����������� �������������. ");
	menuUpdateAccounts();
	updateItem = security_for_any_numbers_i(0, 5);
	int count1 = 0;
	int count = 0;//������� 
	string login, password, passwordAgain;
	bool temp = true;
	switch (updateItem)
	{
	case 5:
		cout << "����� �����: ";
		login = inputAnyStringOfChars();
		for (int i = 0; i < list_of_accounts.size(); i++)
		{
			if (list_of_accounts.at(updateAccount - 1).login == list_of_accounts.at(i).login)
			{
				temp = false;
				cout << "\n������������ � ����� ������� ��� ����������!�������������� ������ ��� ��������." << endl;
				break;
			}
		}
		if (temp == true)
		{
			list_of_accounts.at(updateAccount - 1).login = login;
			cout << "������� ���������������!" << endl;
		}
		//////
		cout << "����� ������: ";
		
		do {
			if (count != 0)
			{
				cout << "��������� ������ �� ���������!" << endl;
			}
			cout << "������� ������ (������� 5 ������): ";
			password = input_password();
			cout << endl;
			cout << "��������� ������: ";
			passwordAgain = input_password();
			cout << endl;
			count++;
		} while (password != passwordAgain);

		list_of_accounts.at(updateAccount - 1).salt = salt();

		list_of_accounts.at(updateAccount - 1).salted_hash_password = myhash(password + list_of_accounts.at(updateAccount - 1).salt);

		cout << "������� ���������������!" << endl;
		//////////
		for (int i = 0; i < list_of_accounts.size(); i++)
		{
			if (list_of_accounts.at(i).role == 1)count1++;
		}
		if (count1 >= 1)
		{
			cout << "1.���� ������������\n2.���� ��������������" << endl;
			cout << "����� ����: ";
			list_of_accounts.at(updateAccount - 1).role = security_for_any_numbers_i(1, 2);
			writeFileAccounts(list_of_accounts);
			cout << "������� ���������������!" << endl;
		}
		else if (count1 < 2)
		{
			cout << "�� ������������ �������������, � �� ������ �������� ���� � ������." << endl;
		}
		break;
		writeFileAccounts(list_of_accounts);
	case 1:
		cout << "����� �����: ";
		login = inputAnyStringOfChars();
		cout << endl;
		for (int i = 0; i < list_of_accounts.size(); i++)
		{
			if (list_of_accounts.at(updateAccount - 1).login == list_of_accounts.at(i).login)
			{
				temp = false;
				cout << "\n������������ � ����� ������� ��� ����������!�������������� ������ ��� ��������." << endl;
				break;
			}
		}
		if (temp == true)
		{
			list_of_accounts.at(updateAccount - 1).login = login;
			cout << "������� ���������������!" << endl;
		}
		writeFileAccounts(list_of_accounts);
		break;
	case 2:
		cout << "����� ������: ";
		
		do {
			if (count != 0)
			{
				cout << "��������� ������ �� ���������!" << endl;
			}
			cout << "������� ������ (������� 5 ������): ";
			password = input_password();
			cout << endl;
			cout << "��������� ������: ";
			passwordAgain = input_password();
			cout << endl;
			count++;
		} while (password != passwordAgain);
		
		list_of_accounts.at(updateAccount - 1).salt = salt();

		list_of_accounts.at(updateAccount - 1).salted_hash_password = myhash(password + list_of_accounts.at(updateAccount - 1).salt);
			
			cout << "������� ���������������!" << endl;
		
		writeFileAccounts(list_of_accounts);
		break;

	case 3:

		for (int i = 0; i < list_of_accounts.size(); i++)
		{
			if (list_of_accounts.at(i).role == 1)count1++;
		}
		if (count1 >= 1) 
		{
			cout << "1.���� ������������\n2.���� ��������������" << endl;
			cout << "����� ����: ";
			list_of_accounts.at(updateAccount - 1).role = security_for_any_numbers_i(1, 2);
			writeFileAccounts(list_of_accounts);
			cout << "������� ���������������!" << endl;
		}
		else if(count1<2)
		{
			cout << "�� ������������ �������������, � �� ������ �������� ���� � ������." << endl;
		}
		break;
	case 4:
		
		for (int i = 0; i < list_of_accounts.size(); i++)
		{
			if (list_of_accounts.at(i).role == 1) count1++;
		}

		if (list_of_accounts.at(updateAccount - 1).role == 1 && count1 > 1 || list_of_accounts.at(updateAccount - 1).role == 0)
		{

			cout << "1.��� �������\n2.� ��������" << endl;
			cout << "����� ������: ";
			list_of_accounts.at(updateAccount - 1).access = security_for_any_numbers_i(1, 2);
			writeFileAccounts(list_of_accounts);
			cout << "������� ���������������!" << endl;

		}
		else if (list_of_accounts.at(updateAccount - 1).role == 1 && count1 == 1)
		{
			cout << "�� ������������ �������������, � �� ������ �������� ���� � ������." << endl;
		}
		break;
	case 0:break;
	}
	
}
void AdminAccounts(vector<Account>&list_of_accounts)
{
	int choise;
	int YesOrNot;
	bool flag_AdminAccounts = true;
	while (flag_AdminAccounts)
	{
		cout << "\t1 - ����������� ��������" << endl;
		cout << "\t2 - �������� �������" << endl;
		cout << "\t3 - ������������� �������" << endl;
		cout << "\t4 - ������� �������" << endl;
		cout << "\t5 - ��������� �����" << endl;
		cout << "\t0 - �����" << endl;
		unnumericInputProtection(choise);
		switch (choise)
		{
		case 1:	showAccounts(list_of_accounts);
			break;
		case 2: addAccount(list_of_accounts);
			break;
		case 3:updateAccount(list_of_accounts);
			break;
		case 4:delAccount(list_of_accounts);
			break;
		case 5:system("cls");
			break;
		case 0: flag_AdminAccounts = false;
			break;
		default:cout << "����� ��� � ������!" << endl;
			break;
		}
	}
}
string salt()//rand() % (b - a + 1) + a
{
	string Salt;
	int n, temp;
	char chr;
	n = rand() % (25 - 15 + 1) + 15;//���� �� 15 �� 25 ��������
	for (int i = 0; i < n; i++)
	{
		temp = rand() % (3 - 1 + 1) + 1;
		if (temp == 1) chr = rand() % (90 - 65 + 1) + 65;//��������� �����
		if (temp == 2) chr = rand() % (122 - 97 + 1) + 97;//�������� �����
		if (temp == 3) chr = rand() % (57 - 48 + 1) + 48;//�����
		Salt += chr;
	}
	return Salt;
}
string input_password()
{
	char ch;
	string password;
	int next = 0;
	while (next < SIZE_PASSWORD - 1)
	{
		ch = _getch();
		if (ch == 13 || ch == 32) break;
		if (ch == 8 && password != "")
		{
			password.pop_back();
			cout << ch;
		}
		else
		{
			if (ch != 8) {
				password += ch;
				next++;
				cout << '*';
			}
		}
	}
	cout << endl;
	return password;
}
string myhash(string str)
{
	int a;
	hash<string> hash_str;
	size_t hash = hash_str(str);
	a = hash;
	string new_str = to_string(a);
	return new_str;
}

void header_of_ACCOUNT()
{
	cout << endl;
	cout << setfill(' ') << setw(2) << "|" << setfill('-') << setw(107) << "|" << endl;
	cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') <<
		std::setw(11) << " � | " <<
		std::setw(15) << std::left << "����� | " <<
		std::setw(19) << std::left << "���� | " <<
		std::setw(19) << std::left << "������ | " << endl;
}