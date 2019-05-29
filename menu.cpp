#include"allFun.h"
void menuAdminStruct()
{
	cout << "1 - Просмотреть все рейсы" << endl;
	cout << "2 - Добавить рейс" << endl;
	cout << "3 - Удалить рейс" << endl;
	cout << "4 - Редактировать рейс" << endl;
	cout << "5 - Индивидуальное задание" << endl;
	cout << "6 - Отсортировать рейсы" << endl;
	cout << "7 - Поиск рейсов по критерию" << endl;
	cout << "0 - Выход" << endl;
}
void menuUserStruct()
{
	cout << "1 - Просмотреть все рейсы" << endl;
	cout << "2 - Индивидуальное задание" << endl;
	cout << "3 - Отсортировать рейсы" << endl;
	cout << "4 - Поиск рейсов по критерию" << endl;
	cout << "0 - Выход" << endl;
}
void menuUpdateRoutes()
{
	cout << "Выберите что изменить: " << endl;
	cout << "1 - Номер рейса" << endl;
	cout << "2 - Тип рейса" << endl;
	cout << "3 - Пункт назначения" << endl;
	cout << "4 - Время отправления" << endl;
	cout << "5 - Время прибытия" << endl;
	cout << "6 - Редактировать всё" << endl;
	cout << "0 - Назад" << endl;
}
void menuSortRoutes()
{
	cout << "Выберите критерий для сортировки : " << endl;
	cout << "1 - По пункту назначения" << endl;
	cout << "2 - По времени отправления" << endl;
	cout << "3 - По номеру рейса" << endl;
	cout << "0 - Назад" << endl;
}
void menuSearchRoutes()
{
	cout << "Выберите критерий для поиска : " << endl;
	cout << "1 - По пункту назначения" << endl;
	cout << "2 - По типу рейса" << endl;
	cout << "3 - По номеру рейса" << endl;
	cout << "0 - Назад" << endl;
}
void menuUpdateAccounts()
{
	cout << "Выберите что редактировать: " << endl;
	cout << "1 - Логин" << endl;
	cout << "2 - Пароль" << endl;
	cout << "3 - Роль" << endl;
	cout << "4 - Доступ" << endl;
	cout << "5 - Редактировать всё" << endl;
	cout << "0 - Назад" << endl;
}
void menuRole(vector<Account> &list_of_accounts, vector<Routes> &list_of_routes, int role)
{
	bool choise = true;
	int workWith;
	if (role == 1)
	{
		system("cls");
		cout << " Вы зашли в роли админа  " << endl;
		while (choise)
		{
			cout << "------------------------------Меню администратора-------------------------------" << endl << endl;
			cout << "\t1.Работа с учетными записями." << endl
				<< "\t2.Работа с данными." << endl
				<< "\t0.Выход." << endl;
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
		cout << " Вы зашли в роли юзера  " << endl;
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
		cout << "Здравствуйте! Вам нужно войти в систему.\n 1. Войти в существующий аккаунт.\n 2. Регистрация аккаунта.\n 0. Выход " << endl;
		temp = security_for_any_numbers_i(0, 2);


		switch (temp)
		{

		case 1:access(list_of_accounts, list_of_routes); break;

		case 2:addAccount(list_of_accounts);
			cout << "Вы зарегистрированы." << endl; break;


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
		cout << "Введите логин:" << endl;
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
			cout << "Неверный логин, или его нет!" << endl;
		}
		else {

		}
	}
	cout << "Введите пароль:";
	cin >> temp_pass;
	if (temp_pass == list_of_accounts.at(login).password) {

	}
	else {
		cout << "Неверный пароль!" << endl;
	}
	hello(list_of_accounts, list_of_accounts.at(login).role);
}*/

/*void hello(vector<Account>&list_of_accounts, int role)
{
	if (role == 1) {
		cout << "Добро пожаловать, админ!" << endl;
		menuAdminAccounts(list_of_accounts);
	}
	else if (role == 0) {
		cout << "Добро пожаловать, пользователь!" << endl;

	}
	else
	{
		menuUserAccounts(list_of_accounts);
		cout << "Упс, что-то не так!" << endl;
	}
}*/
