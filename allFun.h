#pragma once
#include<iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <algorithm>
#include <Windows.h>
#include <vector>
#include<iomanip>
#include<conio.h>


using namespace std;
struct Routes
{

	int number;
	string type;
	string destination;
	double start_time;
	double arriving_time;

};
struct Account
{
	string login;
	
	string salted_hash_password;
	string salt;
	bool role;
	bool access;
};
const string FILE_OF_ACCOUNTS = "D://Account.txt";// путь к файлу
string const FILE_OF_ROUTES = "D://Routes1.txt";
string const FILE_OF_ROUTES_1 = "D://Fit_Routes1.txt";
const int SIZE_PASSWORD = 50;
const int SIZE_NAME = 50;

/////////////////////////////////            MENU          /////////////////////////////////////
void menuUpdateRoutes();
void menuSortRoutes();
void menuSearchRoutes();
void menuAdminStruct();//меню админа для работы с рейсами
void menuUserStruct();//меню юзера для работы с рейсами
void menuUpdateAccounts();
void menuAutorisation();//главное меню                             !!!!!!!!!!!!!!!!!!!!!!!!!
void menuRole(vector<Account> &list_of_accounts, vector<Routes> &list_of_routes, int role); 
//void hello(vector<Account>&list_of_accounts, bool role);//приветствие

////////////////////////////////        ACCOUNTS           /////////////////////////////////////


void writeFileAccounts(vector<Account> &);
void writeEndFileAccounts(Account new_account);
void readFileAccounts(vector<Account> &);
void showAccounts(vector<Account>);
vector<Account> createListOfAccounts();
void addAccount(vector<Account>&);
void delAccount(vector<Account>&);
void updateAccount(vector<Account>&);
void AdminAccounts(vector<Account>&);//работа для админа с учёткой     !!!!!!!!!!!!!!!!!!
string input_password();//ввод пароля с прверкой и звёздочками
string myhash(string str);
string salt();
void header_of_ACCOUNT();
void access(vector<Account>&list_of_accounts, vector<Routes> &list_of_routes);//вход в систему как админ ци не админ  


//////////////////////////////                 ROUTES        /////////////////////////////////
vector<Routes> createListOfRoutes();
void readFileRoutes(vector<Routes>&);
bool mySortByDestination(Routes rout_a, Routes rout_b);
void writeFileRoutes(vector<Routes>&);
void sortRoutesByDestination(vector<Routes> &list_of_routes);
void writeEndFileRoutes(Routes new_rout);
void showRoutes(vector<Routes>);
void addRoutes(vector<Routes>&);
void delRoutes(vector<Routes>&);
void updateRoutes(vector<Routes>&);
void myTask(vector<Routes>&);
void sortRoutes(vector<Routes>&);
bool mySortByNumberOfRout(Routes rout_a, Routes rout_b);
bool mySortByStart_time(Routes rout_a, Routes rout_b);
void sortRoutesByStart_time(vector<Routes> &list_of_routes);
void SortByNumberOfRout(vector<Routes> &list_of_routes);
void searchForDestination(vector<Routes> &);
void searchForType(vector<Routes> &);
void searchForNumber(vector<Routes> &);
void searchRoutes(vector<Routes> &list_of_routes);
void AdminStruct(vector<Routes> &list_of_routes);//работа с рейсами для админа
void UserStruct(vector<Routes> &list_of_routes);//работа с рейсами для юзера
void headerForRoutes();
void showNecessaryRout(Routes necessaryRout, int number_of_list);

/////////////////////////           VALIDATION                 /////////////////////////////////
double unnumericInputProtection(double &number);
int unnumericInputProtection(int &number);
int getCountOfStucturesInFile(string file_path);

double security_for_positiv_numbers_d(int border1, int border2);//защита от нечислового ввода для положительных чисел
int security_for_any_numbers_i(int border1, int border2);//защита от нечислового ввода для любых целых чисел
int security_for_any_numbers_i_with_message(int border1, int border2, string message);//защита от нечислового ввода для любых целых чисел с сообщением об ошибке
double security_for_positiv_numbers_d(int border1, int border2);//защита от нечислового ввода для положительных чисел типа double
int security_for_positiv_numbers_i(int border1, int border2);//защита от нечислового ввода для положительных целых чисел
string inputAnyStringOfChars();//ввод строки с проверкой