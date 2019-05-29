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


		default:cout << "������������ ����!" << endl;
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


		default:cout << "������������ ����!" << endl;
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
		cout << "������ ����������� " << endl;
	}
	cout << endl; 
}
void headerForRoutes()
{
	cout << endl;
	cout << setfill(' ') << setw(2) << "|" << setfill('-') << setw(107) << "|" << endl;
	cout << std::setfill(' ') << std::setw(2) << "|" << std::setfill(' ') <<
		std::setw(11) << " � | " <<
		std::setw(15) << std::left << " ����� ����� | " <<
		std::setw(15) << std::left << "��� | " <<
		std::setw(19) << std::left << "����� ���������� | " <<
		std::setw(20) << std::left << "����� ���������� | " <<
		std::setw(17) << std::left << "����� �������� | " << endl;
}
void addRoutes(vector<Routes> &list_of_routes)
{
	Routes routes_temp;
	vector<Routes>::iterator it;
	it = list_of_routes.end();
	cout << "������� ����� �����: ";
	routes_temp.number= security_for_positiv_numbers_i(0,100000);
	cout << "������� ���: ";
	 routes_temp.type= inputAnyStringOfChars();
	cout << "������� ����� ����������: ";
	 routes_temp.destination= inputAnyStringOfChars();
	cout << "������� ����� �����������: ";
	routes_temp.start_time= security_for_positiv_numbers_d(0, 24);
	cout << "������� ����� ��������: ";
	routes_temp.arriving_time= security_for_positiv_numbers_d(0, 24);
	list_of_routes.insert(it, routes_temp);
	writeEndFileRoutes(routes_temp);
	cout << "���� ������� ��������" << endl;

}
void delRoutes(vector<Routes>&list_of_routes)
{
	showRoutes(list_of_routes);
	int delrout;
	cout << "�������� �����, ������� ������ �������: ";
	delrout= security_for_any_numbers_i_with_message(1, list_of_routes.size(), "������������ ����!������ ����� ���. ");
	cout << "�� �������, ��� ������ ������� ���� ���� ?" << endl;
	int yes_or_no;
	cout << "1.��" << endl << "2.���" << endl;
	yes_or_no = security_for_positiv_numbers_i(1, 2);
	switch (yes_or_no)
	{
	case 1:
		list_of_routes.erase(list_of_routes.begin() + delrout - 1);
		cout << "���� ������� ������." << endl;
		writeFileRoutes(list_of_routes);
		break;
	case 2:
		cout << "�� �������� ��������." << endl;
	}
}
void updateRoutes(vector<Routes>&list_of_routes)
{
	showRoutes(list_of_routes);
	int updaterout;
	cout << "������� ����� , ������� ������ ��������: ";
	updaterout= security_for_any_numbers_i_with_message(1, list_of_routes.size(), "������������ ����!������ ����� ���. ");
	menuUpdateRoutes();
	int updateItem= security_for_any_numbers_i(0, 6);
   switch (updateItem)
   {	
		case 1:
		{
			cout << "������� ����� ����� �����: ";
			list_of_routes.at(updaterout -1).number= security_for_positiv_numbers_i(0, 100000);
			break;
		}
		case 2:
		{
			cout << "������� ����� ��� �����: ";
			 list_of_routes.at(updaterout - 1).type= inputAnyStringOfChars();
			break; 
		}
		case 3:
		{
			cout << "������� ����� ����� ����������: ";
			 list_of_routes.at(updaterout - 1).destination== inputAnyStringOfChars();
			 break; }
		case 4:
		{
			cout << "������� ����� ����� �����������: ";
			list_of_routes.at(updaterout - 1).start_time= security_for_positiv_numbers_d(0, 24);
			break;
		}
		case 5:
		{
			cout << "������� ����� ����� ��������: ";
			list_of_routes.at(updaterout - 1).arriving_time= security_for_positiv_numbers_d(0, 24);
           break;
		}
		case 6:
		{
			cout << "������� ����� ����� �����: ";
			list_of_routes.at(updaterout - 1).number = security_for_positiv_numbers_i(0, 100000);
			cout << "������� ����� ��� �����: ";
			list_of_routes.at(updaterout - 1).type = inputAnyStringOfChars();
			cout << "������� ����� ����� ����������: ";
			list_of_routes.at(updaterout - 1).destination == inputAnyStringOfChars();
			cout << "������� ����� ����� �����������: ";
			list_of_routes.at(updaterout - 1).start_time= security_for_positiv_numbers_d(0, 24);

			cout << "������� ����� ����� ��������: ";
			list_of_routes.at(updaterout - 1).arriving_time= security_for_positiv_numbers_d(0, 24);
			break;
		}
		case 0: break;
	}
   writeFileRoutes(list_of_routes);
   cout << "���������� ������� ���������������." << endl;
}
vector<Routes> createListOfRoutes()//�������� ������� ��������
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
	cout << "������� ������ ��� ����� ����������:" << endl;
	 point= inputAnyStringOfChars();

	cout << endl;
	cout << "� ������ ������� ��� ����� ��������� �� ������ ����������?" << endl;
     time=security_for_positiv_numbers_d(0, 24);
	
	temp_time = time - 12;//�� 12 �����

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

		cout << "����� �� �������" << endl;
	}
}

void sortRoutesByDestination(vector<Routes> &list_of_routes) // ����������
{
	sort(list_of_routes.begin(), list_of_routes.end(), mySortByDestination);
}
void SortByNumberOfRout(vector<Routes> &list_of_routes) // ����������
{
	sort(list_of_routes.begin(), list_of_routes.end(), mySortByNumberOfRout);
}
void sortRoutesByStart_time(vector<Routes> &list_of_routes) // ����������
{
	sort(list_of_routes.begin(), list_of_routes.end(), mySortByStart_time);
}

bool mySortByDestination(Routes rout_a, Routes rout_b) // �������-����������
{
	return  rout_a.destination > rout_b.destination; // �� ��������: �� � � �
}
bool mySortByStart_time(Routes rout_a, Routes rout_b) // �������-����������
{
	return  rout_a.start_time < rout_b.start_time;
}
bool mySortByNumberOfRout(Routes rout_a, Routes rout_b) // �������-����������
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
			cout << "----------�����, ��������������� �� ������ ����������(�� ��������)--------- " << endl;

			sortRoutesByDestination(list_of_routes);
			showRoutes(list_of_routes);
			break;
		}
		case 2: {
			cout << "----------�����, ��������������� �� ������� �����������---------  " << endl;
			sortRoutesByStart_time(list_of_routes);
			showRoutes(list_of_routes);
			break; }
		case 3: {
			cout << "----------�����, ��������������� �� ������ �����---------  " << endl;
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
	cout << "������� ������ ��� ��� �����:" << endl;
	cin >> necessary_type;
	cout << endl;
	bool find =true;
	cout << "------------����� � �������� �����------------";
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

		cout << "����� �� �������" << endl;
	}
}
void searchForDestination(vector<Routes> &list_of_routes)
{
	string necessary_destination;
	cout << endl;
	cout << "������� ������ ���  ����� ����������:" << endl;
	 necessary_destination= inputAnyStringOfChars();
	cout << endl;
	int find = 0;
	cout << "---------����� � �������� ������� ����������-----------";
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


		cout << "����� �� �������" << endl;
	}
}
void searchForNumber(vector<Routes> &list_of_routes)
{
	int necessary_number;
	cout << endl;
	cout << "������� ������ ��� ����� �����:" << endl;
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

		cout << "����� �� �������" << endl;
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
			cout << "----------����� ����� � �������� ������� ����������--------- " << endl;

			searchForDestination(list_of_routes);

			break;
		}
		case 2: {
			cout << "----------����� ����� � �������� �����---------  " << endl;
			searchForType(list_of_routes);

			break; }
		case 3: {
			cout << "---------����� ��������� �����---------  " << endl;
			searchForNumber(list_of_routes);

			break; }
		case 0:flag_exit = false; break;
		default: cout << "����������� ����!" << endl;
			break;
		}
	}
}
