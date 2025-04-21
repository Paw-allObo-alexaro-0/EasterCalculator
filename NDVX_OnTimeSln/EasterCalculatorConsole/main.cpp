#include ".\..\NDVX_OnTimeHeader\EasterCalculator.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
using namespace std;

int main(void)
{
	cout << "r---------------------------------------------i" << endl;
	cout << "|                                             |" << endl;
	cout << "|        NDVX EasterCalculator Console        |" << endl;
	cout << "|     NDVX - Paw all Obo alexaro 0 - 2025     |" << endl;
	cout << "|                                             |" << endl;
	cout << "l_____________________________________________," << endl;
	cout << endl;

	char menu_in_c;
	while(true)
	{
		cout << "(1) Single year" << endl;
		cout << "(2) Range of years" << endl;
		cout << "(3) Exit" << endl;

		menu_in_c = _getch();
		switch(menu_in_c)
		{
			case '1':
			{
				signed short year;
				while(true)
				{
					cout << "Enter year: ";
					cin >> year;

					if (cin.fail())
					{
						cout << "Invalid input! Please enter a valid number." << endl;
						cin.clear();
						cin.ignore();
						continue;
					}
					break;
				}
				ntime::time_private t = time_calculator::calc_single_easter(year);
				cout << "Easter Sunday: " << (int)t.get_day() << "/" << (int)t.get_month() << "/" << (int)t.get_year() << endl;
			}
			break;
			case '2':
			{
				signed short start_year, end_year;
				cout << "File Name: ";
				string file_name;
				cin >> file_name;
				while (true)
				{
					cout << "Enter start year: ";
					cin >> start_year;

					if (cin.fail())
					{
						cout << "Invalid input! Please enter a valid number." << endl;
						cin.clear();
						cin.ignore();
						continue;
					}
					break;
				}
				while (true)
				{
					cout << "Enter end year: ";
					cin >> end_year;

					if (cin.fail())
					{
						cout << "Invalid input! Please enter a valid number." << endl;
						cin.clear();
						cin.ignore();
						continue;
					}
					break;
				}
				ntime::time_private* ts = new ntime::time_private[end_year - start_year + 1];
				ts = time_calculator::calc_range_of_easters(start_year, end_year);
				{
					FILE* file;
					fopen_s(&file, file_name.c_str(), "w");
					if (file == NULL)
					{
						cout << "Error opening file!" << endl;
						break;
					}
					fprintf(file, "+--------+-----+\n");
					fprintf(file, "|YYYYYYYY|MM DD|\n");
					fprintf(file, "+--------+-----+\n");
					for (signed short i = 0; i < end_year - start_year + 1; i++)
					{
						fprintf(file, "|%08d|%02d %02d|\n", ts[i].get_year(), ts[i].get_month(), ts[i].get_day());
					}
					fprintf(file, "+--------+-----+\n");
					fclose(file);
				}
				delete[] ts;
			}
			break;
			case '3':
			{
				cout << "Exiting";
				printf(".  ");
				Sleep(500);
				printf("\b\b\b.. ");
				Sleep(500);
				printf("\b\b\b...");
				Sleep(500);
				exit(0);
			}
			default:
				continue;
		}
	}

	return 0;
}