#include"allFun.h"
void AdminStruct(vector<Routes> &list_of_routes)
{
	bool flag_exit = true;
	while (flag_exit)
	{
		menuAdminStruct();
		int item;
		item= security_for_any_numbers_i(0,7);
		switch (item)
		{
		case 0: flag_exit = false; break;
		case 1: showRoutes(list_of_routes); break;
		case 2: system("cls"); addRoutes(list_of_routes); break;
		case 3: delRoutes(list_of_routes); break;
		case 4: updateRoutes(list_of_routes); break;
		case 5: system("cls"); myTask(list_of_routes); break;
		case 6:	system("cls"); sortRoutes(list_of_routes); break;
		case 7: system("cls"); searchRoutes(list_of_routes); break;
			break;


		default:cout << "Некорректный ввод!" << endl;
			break;
		}
	}
}
void UserStruct(vector<Routes> &list_of_routes)
{
	bool flag_exit = true;
	while (flag_exit)
	{
		menuUserStruct();
		int item;
		unnumericInputProtection(item);
		switch (item)
		{
		case 0: flag_exit = false; break;
		case 1: showRoutes(list_of_routes); break;
		case 2: system("cls"); myTask(list_of_routes); break;
		case 3:	system("cls"); sortRoutes(list_of_routes); break;
		case 4: system("cls"); searchRoutes(list_of_routes); break;
			break;


		default:cout << "Некорректный ввод!" << endl;
			break;
		}
	}
}
void writeFileRoutes(vector<Routes> &list_of_routes)
{
	ofstream fout(FILE_OF_ROUTES, ios::out);
	for (int i = 0; i < list_of_routes.size(); i++)
	{
		fout << list_of_routes.at(i).number << " " << list_of_routes.at(i).type << " "
			<< list_of_routes.at(i).destination << " " << list_of_routes.at(i).start_time << " " << list_of_routes.at(i).arriving_time;
		if (i < list_of_routes.size() - 1)
			fout << endl;
	}
	fout.close();
}
void showNecessaryRout(Routes necessaryRout, int number_of_list)
{
	headerForRoutes();
	cout << setfill(' ') << setw(2) << "|" << setfill('-') << setw(107) << "|" << endl;
	cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') <<
		std::setw(11) << number_of_list <<
		std::setw(15) << std::left << necessaryRout.number <<
		std::setw(15) << std::left << necessaryRout.type <<
		std::setw(19) << std::left << necessaryRout.destination <<
		std::setw(20) << std::left << necessaryRout.start_time <<
		std::setw(17) << std::left << necessaryRout.arriving_time << endl;
	cout << setfill(' ') << setw(2) << "|" << setfill('-') << setw(107) << "|" << endl;
}
void writeEndFileRoutes(Routes new_rout)

{
	ofstream fadd(FILE_OF_ROUTES, ios::app);
	fadd << endl;
	fadd << new_rout.number << " " << new_rout.type << " " << new_rout.destination << " " << new_rout.start_time << " " << new_rout.arriving_time;
	fadd.close();
}
void showRoutes(vector<Routes> list_of_routes)
{
	 headerForRoutes();
	for (int i = 0; i < list_of_routes.size(); i++)
	{
		
		cout << setfill(' ') << setw(2) << "|" << setfill('-') << setw(107) << "|" << endl;
		cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') <<
			std::setw(11) << i + 1 <<
			std::setw(15) << std::left << list_of_routes.at(i).number <<
			std::setw(15) << std::left << list_of_routes.at(i).type <<
			std::setw(19) << std::left << list_of_routes.at(i).destination <<
			std::setw(20) << std::left << list_of_routes.at(i).start_time <<
			std::setw(17) << std::left << list_of_routes.at(i).arriving_time << endl;
		cout << setfill(' ') << setw(2) << "|" << setfill('-') << setw(107) << "|" << endl;
	}
	if (list_of_routes.size() == 0)
	{
		cout << "Данные отсутствуют " << endl;
	}
	cout << endl; 
}
void headerForRoutes()
{
	cout << endl;
	cout << setfill(' ') << setw(2) << "|" << setfill('-') << setw(107) << "|" << endl;
	cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') <<
		std::setw(11) << " № | " <<
		std::setw(15) << std::left << " Номер рейса | " <<
		std::setw(15) << std::left << "Тип | " <<
		std::setw(19) << std::left << "Пункт назначения | " <<
		std::setw(20) << std::left << "Время отправлени | " <<
		std::setw(17) << std::left << "Время прибытия | " << endl;
}
void addRoutes(vector<Routes> &list_of_routes)
{
	Routes routes_temp;
	vector<Routes>::iterator it;
	it = list_of_routes.end();
	cout << "Введите номер рейса: ";
	routes_temp.number= security_for_positiv_numbers_i(0,100000);
	cout << "Введите тип: ";
	 routes_temp.type= inputAnyStringOfChars();
	cout << "Введите пункт назначения: ";
	 routes_temp.destination= inputAnyStringOfChars();
	cout << "Укажите время отправления: ";
	routes_temp.start_time= security_for_positiv_numbers_d(0, 24);
	cout << "Укажите время прибытия: ";
	routes_temp.arriving_time= security_for_positiv_numbers_d(0, 24);
	list_of_routes.insert(it, routes_temp);
	writeEndFileRoutes(routes_temp);
	cout << "Рейс успешно добавлен" << endl;

}
void delRoutes(vector<Routes>&list_of_routes)
{
	showRoutes(list_of_routes);
	int delrout;
	cout << "Выберите номер, который хотите удалить: ";
	delrout= security_for_any_numbers_i_with_message(1, list_of_routes.size(), "Некорректный ввод!Такого рейса нет. ");
	cout << "Вы уверены, что хотите удалить этот рейс ?" << endl;
	int yes_or_no;
	cout << "1.Да" << endl << "2.Нет" << endl;
	yes_or_no = security_for_positiv_numbers_i(1, 2);
	switch (yes_or_no)
	{
	case 1:
		list_of_routes.erase(list_of_routes.begin() + delrout - 1);
		cout << "РЕйс успешно удален." << endl;
		writeFileRoutes(list_of_routes);
		break;
	case 2:
		cout << "Вы отменили удаление." << endl;
	}
}
void updateRoutes(vector<Routes>&list_of_routes)
{
	showRoutes(list_of_routes);
	int updaterout;
	cout << "Введите номер , который хотите изменить: ";
	updaterout= security_for_any_numbers_i_with_message(1, list_of_routes.size(), "Некорректный ввод!Такого рейса нет. ");
	menuUpdateRoutes();
	int updateItem= security_for_any_numbers_i(0, 6);
   switch (updateItem)
   {	
		case 1:
		{
			cout << "Введите новый номер рейса: ";
			list_of_routes.at(updaterout -1).number= security_for_positiv_numbers_i(0, 100000);
			break;
		}
		case 2:
		{
			cout << "Введите новый тип рейса: ";
			 list_of_routes.at(updaterout - 1).type= inputAnyStringOfChars();
			break; 
		}
		case 3:
		{
			cout << "Введите новый пункт назначения: ";
			 list_of_routes.at(updaterout - 1).destination== inputAnyStringOfChars();
			 break; }
		case 4:
		{
			cout << "Введите новое время отправления: ";
			list_of_routes.at(updaterout - 1).start_time= security_for_positiv_numbers_d(0, 24);
			break;
		}
		case 5:
		{
			cout << "Введите новое время прибытия: ";
			list_of_routes.at(updaterout - 1).arriving_time= security_for_positiv_numbers_d(0, 24);
           break;
		}
		case 6:
		{
			cout << "Введите новый номер рейса: ";
			list_of_routes.at(updaterout - 1).number = security_for_positiv_numbers_i(0, 100000);
			cout << "Введите новый тип рейса: ";
			list_of_routes.at(updaterout - 1).type = inputAnyStringOfChars();
			cout << "Введите новый пункт назначения: ";
			list_of_routes.at(updaterout - 1).destination == inputAnyStringOfChars();
			cout << "Введите новое время отправления: ";
			list_of_routes.at(updaterout - 1).start_time= security_for_positiv_numbers_d(0, 24);

			cout << "Введите новое время прибытия: ";
			list_of_routes.at(updaterout - 1).arriving_time= security_for_positiv_numbers_d(0, 24);
			break;
		}
		case 0: break;
	}
   writeFileRoutes(list_of_routes);
   cout << "Информация успешно отредактирована." << endl;
}
vector<Routes> createListOfRoutes()//создание вектора структур
{
	int n = getCountOfStucturesInFile(FILE_OF_ROUTES);
	vector<Routes> list_of_routes(n);
	if (n != 0)
	{
		ifstream file(FILE_OF_ROUTES, ios::in);
		for (int i = 0; i < n; i++)
		{
			file >> list_of_routes.at(i).number
				>> list_of_routes.at(i).type
				>> list_of_routes.at(i).destination
				>> list_of_routes.at(i).start_time
				>> list_of_routes.at(i).arriving_time;
		}
		file.close();
	}
	return list_of_routes;
}
void myTask(vector<Routes>&list_of_routes)
{
	double time;
	string point;
	double temp_time;

	cout << endl;
	cout << "введите нужный Вам пункт назначения:" << endl;
	 point= inputAnyStringOfChars();

	cout << endl;
	cout << "К какому времени Вам нужно добраться до пункта назначения?" << endl;
     time=security_for_positiv_numbers_d(0, 24);
	
	temp_time = time - 12;//за 12 часов

	cout << endl;
	int find = 0;
	ofstream fout2(FILE_OF_ROUTES_1, ios::out);

	for (int i = 0; i < list_of_routes.size(); i++)
	{
		if (list_of_routes.at(i).destination == point)
		{
			if (temp_time >= 0)
			{
				if (list_of_routes.at(i).arriving_time >= temp_time && list_of_routes.at(i).arriving_time < time)
				{
					showNecessaryRout(list_of_routes.at(i), find+1);
					find++;
					
				}
			}
			else if (temp_time < 0)
			{
				
				temp_time = 24 + temp_time;
				if ((list_of_routes.at(i).arriving_time >= temp_time && list_of_routes.at(i).arriving_time <= 24) || (list_of_routes.at(i).arriving_time > 24 && list_of_routes.at(i).arriving_time < time))
				{
					showNecessaryRout(list_of_routes.at(i), find + 1);
					find++;
					
				}

			}
		}

	}
	if (find == 0)
	{

		cout << "рейсы не найдены" << endl;
	}
}

void sortRoutesByDestination(vector<Routes> &list_of_routes) // сортировка
{
	sort(list_of_routes.begin(), list_of_routes.end(), mySortByDestination);
}
void SortByNumberOfRout(vector<Routes> &list_of_routes) // сортировка
{
	sort(list_of_routes.begin(), list_of_routes.end(), mySortByNumberOfRout);
}
void sortRoutesByStart_time(vector<Routes> &list_of_routes) // сортировка
{
	sort(list_of_routes.begin(), list_of_routes.end(), mySortByStart_time);
}

bool mySortByDestination(Routes rout_a, Routes rout_b) // функция-компаратор
{
	return  rout_a.destination > rout_b.destination; // по алфавиту: от а к я
}
bool mySortByStart_time(Routes rout_a, Routes rout_b) // функция-компаратор
{
	return  rout_a.start_time < rout_b.start_time;
}
bool mySortByNumberOfRout(Routes rout_a, Routes rout_b) // функция-компаратор
{
	return  rout_a.number < rout_b.number;
}
void sortRoutes(vector<Routes>&list_of_routes)
{
	int sort;

	bool flag_exit = true;
	while (flag_exit)
	{
		menuSortRoutes();
		sort = security_for_any_numbers_i(0, 3);
		switch (sort)
		{
		case 1: {
			cout << "----------Рейсы, отсортированные по пункту назначения(по алфавиту)--------- " << endl;

			sortRoutesByDestination(list_of_routes);
			showRoutes(list_of_routes);
			break;
		}
		case 2: {
			cout << "----------Рейсы, отсортированные по времени отправления---------  " << endl;
			sortRoutesByStart_time(list_of_routes);
			showRoutes(list_of_routes);
			break; }
		case 3: {
			cout << "----------Рейсы, отсортированные по номеру рейса---------  " << endl;
			SortByNumberOfRout(list_of_routes);
			showRoutes(list_of_routes);
			break; }
		case 0:flag_exit = false; break;
		
		}
	}
}
void searchForType(vector<Routes> &list_of_routes)
{
	string necessary_type;
	cout << endl;
	cout << "введите нужный Вам тип рейса:" << endl;
	cin >> necessary_type;
	cout << endl;
	bool find =true;
	cout << "------------Рейсы с заданным типом------------";
	for (int i = 0; i < list_of_routes.size(); i++)
	{
		if (list_of_routes.at(i).type == necessary_type)
		{
			
			showNecessaryRout(list_of_routes.at(i), find+1);
			find = false;
		}
	}
	if (find==true )
	{

		cout << "рейсы не найдены" << endl;
	}
}
void searchForDestination(vector<Routes> &list_of_routes)
{
	string necessary_destination;
	cout << endl;
	cout << "введите нужный Вам  пункт назначения:" << endl;
	 necessary_destination= inputAnyStringOfChars();
	cout << endl;
	int find = 0;
	cout << "---------Рейсы с заданным пунктом назначения-----------";
	for (int i = 0; i < list_of_routes.size(); i++)
	{
		if (list_of_routes.at(i).destination == necessary_destination)
		{
			find++;
			showNecessaryRout(list_of_routes.at(i), find + 1);

		}
	}
	if (find == 0)
	{


		cout << "рейсы не найдены" << endl;
	}
}
void searchForNumber(vector<Routes> &list_of_routes)
{
	int necessary_number;
	cout << endl;
	cout << "введите нужный Вам номер рейса:" << endl;
	unnumericInputProtection(necessary_number);
	cout << endl;
	int find = 0;

	for (int i = 0; i < list_of_routes.size(); i++)
	{
		if (list_of_routes.at(i).number == necessary_number)
		{
			find++;
			showNecessaryRout(list_of_routes.at(i), find + 1);

		}
	}
	if (find == 0)
	{

		cout << "рейсы не найдены" << endl;
	}
}
void searchRoutes(vector<Routes> &list_of_routes)
{
	int search;

	bool flag_exit = true;
	while (flag_exit)
	{
		menuSearchRoutes();
		unnumericInputProtection(search);
		switch (search)
		{
		case 1: {
			cout << "----------Поиск рейса с заданным пунктом назначения--------- " << endl;

			searchForDestination(list_of_routes);

			break;
		}
		case 2: {
			cout << "----------Поиск рейса с заданным типом---------  " << endl;
			searchForType(list_of_routes);

			break; }
		case 3: {
			cout << "---------Поиск заданного рейса---------  " << endl;
			searchForNumber(list_of_routes);

			break; }
		case 0:flag_exit = false; break;
		default: cout << "Некорректый ввод!" << endl;
			break;
		}
	}
}
