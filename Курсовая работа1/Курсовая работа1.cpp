#include <iostream>
#include<stdio.h>
#include <fstream>
#include <conio.h>
#include <sstream>
#include<math.h>
#include<stdlib.h>
#include<iomanip>
#include<string.h>
#include<Windows.h>
#include <cstdio>
#include<vector>
#include <algorithm>

using namespace std;

struct Car
{
	string numberOfCar;
	string brand;
	int horsePower;
	int distanceTravelled;
	int fuelConsumption;
	int koefD;
};

struct CarWithLineNumber
{
	int lineNumber;
	Car car;
};

string file1 = "mainFile.doc", writeFile = "fileForWriteDelete.doc", sortFile = "fileForSort.doc";

vector <Car> cars;
void Menu();
void FilesMenu();
void FileRewrite(string file);
void FileAdd(string file);
void Output(string file);
void DeleteCarByNumber(string file);
void MenuDelete();
void DeleteCarByBrand(string file);
void DeleteCarAll(string file);
void MenuSort();
void sortByNumberOfCar();
void SortByBrand();
void SortByHorsePower();
void SortByDistanceTravelled();

int countOfCars = 1;

void main()
{
	setlocale(LC_ALL, "Russian");
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("color f0");
	Menu();
}

void Menu()
{
	system("cls"); // Очищение консоли
	while (1)
	{
		// Main menu
		system("cls");
		cout << setfill(' ');
		int request;

		cout << "\t\t\t\tГлавное меню \n\n";
		cout << "\t\t\t\t+--------------------------------+ \n";
		cout << "\t\t\t\t|" << " 1 - Работа с файлами " << setw(12) << "|\n";
		cout << "\t\t\t\t+--------------------------------+ \n";
		cout << "\t\t\t\t|" << " 2 - Вывод из файла " << setw(14) << "|\n";
		cout << "\t\t\t\t+--------------------------------+ \n";
		cout << "\t\t\t\t|" << " 3 - Сортировка " << setw(18) << "|\n";
		cout << "\t\t\t\t+--------------------------------+ \n";
		cout << "\t\t\t\t|" << " 4 - Удалить автомобиль " << setw(10) << "|\n";
		cout << "\t\t\t\t+--------------------------------+ \n";
		cout << "\t\t\t\t|" << " 5 - Выход " << setw(23) << "|\n";
		cout << "\t\t\t\t+--------------------------------+ \n";
		cout << "\n\t\t\t\tВведите запрос = ";

		cin >> request;
		switch (request)
		{
		case 1:
			FilesMenu();
			break;
		case 2:
			Output(file1);
			break;
		case 3:
			MenuSort();
			break;
		case 4:
			MenuDelete();
			break;
		case 5:
			exit(0);
			break;
		default:
			system("cls");
			cout << "\n\t\t\t\tНеверный запрос, попробуйте ещё раз.\n\n";
			system("pause");
			Menu();
			break;
		}


		break;
	}
}

void FilesMenu()
{
	system("cls");
	int request;
	cout << "\t\t\t\tМеню работы с файлами \n\n";
	cout << "\t\t\t\t+--------------------------------+ \n";
	cout << "\t\t\t\t|" << " 1 - Перезаполнение данных " << setw(7) << "|\n";
	cout << "\t\t\t\t+--------------------------------+ \n";
	cout << "\t\t\t\t|" << " 2 - Добавление данных " << setw(11) << "|\n";
	cout << "\t\t\t\t+--------------------------------+ \n";
	cout << "\t\t\t\t|" << " 3 - Главное меню " << setw(16) << "|\n";
	cout << "\t\t\t\t+--------------------------------+ \n";
	cout << "\n\t\t\t\tВведите запрос = ";
	cin >> request;
	switch (request)
	{
	case 1:
		system("cls");
		FileRewrite(file1);
		break;
	case 2:
		system("cls");
		FileAdd(file1);
		break;
	case 3:
		system("cls");
		Menu();
		break;
	default:
		system("cls");
		cout << "\n\t\tНеверный запрос, попробуйте ещё раз. Чтобы продолжить нажмите любую клавишу...\n";
		system("pause>nul");
		FilesMenu();
	}
}

void FileRewrite(string file)
{
	ofstream fout(file, ofstream::out);
	if (!fout) {
		cout << "\n\t\tФайл не найден." << endl;
		return;
	}
	cout << "\n\t\tВведите количество авто: ";
	int countCars = 0;
	cin >> countCars;
	cin.ignore();

	countOfCars = 1;

	Car* carsLocal = new Car[countCars];
	for (int i = 0; i < countCars; i++) {
		cout << "Введите данные об авто для заполнения: \n";

		fout << countOfCars << "\t";

		cout << "Городской номер авто: ";
		/*getline(cin, carsLocal[i].numberOfCar);*/
		cin >> carsLocal[i].numberOfCar;
		fout << carsLocal[i].numberOfCar << "\t";

		cout << "Бренд авто: ";
		cin >> carsLocal[i].brand;
		fout << carsLocal[i].brand << "\t";

		cout << "Лошадиные силы авто: ";
		cin >> carsLocal[i].horsePower;
		fout << carsLocal[i].horsePower << "\t";

		cout << "Пробег авто: ";
		cin >> carsLocal[i].distanceTravelled;
		fout << carsLocal[i].distanceTravelled << "\t";

		cout << "Затраты л/100км: ";
		cin >> carsLocal[i].fuelConsumption;
		fout << carsLocal[i].fuelConsumption << "\t";

		cout << "Поправочный коэф. D: ";
		cin >> carsLocal[i].koefD;
		fout << carsLocal[i].koefD << "\n";

		cin.ignore();

		countOfCars++;
	}

	fout.close();

	system("cls");
	FilesMenu();
}

void FileAdd(string file)
{
	ofstream fout(file, ios_base::app | ios_base::ate);
	if (!fout) {
		cout << "\nФайл не найден." << endl;
		return;
	}
	cout << "\nВведите количество авто: ";
	int countCars = 0, k = 0;
	cin >> countCars;
	cin.ignore();
	CarWithLineNumber* carsLocal = new CarWithLineNumber[countCars];
	for (int i = 0; i < countCars; i++)
	{
		cout << setw(56) << "Введите данные об авто для заполнения: \n";

		ifstream fin;
		fin.open(file, ios_base::in | ios_base::ate);
		string lineForStream;
		stringstream stream(lineForStream);
		stream >> k;

		fout << k << "\t";

		cout << "Городской номер авто: ";
		/*getline(cin, carsLocal[i].numberOfCar);*/
		cin >> carsLocal[i].car.numberOfCar;
		fout << carsLocal[i].car.numberOfCar << "\t";

		cout << "Бренд авто: ";
		cin >> carsLocal[i].car.brand;
		fout << carsLocal[i].car.brand << "\t";

		cout << "Лошадиные силы авто: ";
		cin >> carsLocal[i].car.horsePower;
		fout << carsLocal[i].car.horsePower << "\t";

		cout << "Пробег авто: ";
		cin >> carsLocal[i].car.distanceTravelled;
		fout << carsLocal[i].car.distanceTravelled << "\t";

		cout << "Затраты л/100км: ";
		cin >> carsLocal[i].car.fuelConsumption;
		fout << carsLocal[i].car.fuelConsumption << "\t";

		cout << "Поправочный коэф. D: ";
		cin >> carsLocal[i].car.koefD;
		fout << carsLocal[i].car.koefD << "\n";

		cin.ignore();

		k++;
	}

	fout.close();

	system("cls");
	FilesMenu();
}

void Output(string file)
{
	system("cls");
	ifstream read(file);
	if (!read)
		cout << "Файл не открыт." << endl;
	cout << "\t\t+" << setfill('-') << setw(3) << "+" << setw(17) << "+" << setw(15) << "+" << setw(16) << "+" << setw(12) << "+" << setw(9) << "+" << setw(9) << "+\n";

	cout << "\t\t|" << setfill(' ') << setw(2) << "#" << "|" << setw(16) << "Городской номер" << "|" << setw(14) << "Бренд  " << "|" << setw(15) << "Лошадиные силы " << "|" << setw(7) << "Пробег, км " << "|" << setw(8) << "л/100км" << "|" << setw(6) << "Коэф. D" << "|\n";

	cout << "\t\t+" << setfill('-') << setw(3) << "+" << setw(17) << "+" << setw(15) << "+" << setw(16) << "+" << setw(12) << "+" << setw(9) << "+" << setw(9) << "+\n";

	CarWithLineNumber carsLocal;
	int n = 0;
	string line;
	cout << fixed;

	while (getline(read, line))
	{
		stringstream carRead(line);
		carRead >> carsLocal.lineNumber >> carsLocal.car.numberOfCar >> carsLocal.car.brand >> carsLocal.car.horsePower >> carsLocal.car.distanceTravelled >> carsLocal.car.fuelConsumption >> carsLocal.car.koefD;

		cout << "\t\t|" << setfill(' ') << setw(2) << carsLocal.lineNumber << "|" << setw(16) << carsLocal.car.numberOfCar << "|" << setw(14) << carsLocal.car.brand << "|" << setw(15) << carsLocal.car.horsePower
			<< "|" << setw(11) << carsLocal.car.distanceTravelled << "|" << setw(8) << carsLocal.car.fuelConsumption << "|" << setw(7) << carsLocal.car.koefD << "|\n";

		cout << "\t\t+" << setfill('-') << setw(3) << "+" << setw(17) << "+" << setw(15) << "+" << setw(16) << "+" << setw(12) << "+" << setw(9) << "+" << setw(9) << "+\n";
	}

	system("pause");
	system("cls");
	Menu();
}

void MenuDelete()
{
	system("cls");
	cout << "\t\t\t\tМеню удаления из файла \n\n";
	cout << "\t\t\t\t+-----------------------------------+ \n";
	cout << "\t\t\t\t|" << " 1 - Удалить по городскому номеру " << setw(3) << "|\n";
	cout << "\t\t\t\t+-----------------------------------+ \n";
	cout << "\t\t\t\t|" << " 2 - Удалить по бренду " << setw(14) << "|\n";
	cout << "\t\t\t\t+-----------------------------------+ \n";
	cout << "\t\t\t\t|" << " 3 - Удалить всё " << setw(20) << "|\n";
	cout << "\t\t\t\t+-----------------------------------+ \n";
	cout << "\t\t\t\t|" << " 4 - Главное меню " << setw(19) << "|\n";
	cout << "\t\t\t\t+-----------------------------------+ \n";
	cout << "\t\t\t\tВведите запрос = ";
	int request;
	cin >> request;
	switch (request)
	{
	case 1:
		DeleteCarByNumber(file1);
		break;
	case 2:
		DeleteCarByBrand(file1);
		break;
	case 3:
		DeleteCarAll(file1);
		break;
	case 4:
		Menu();
	}
}

void DeleteCarByNumber(string file)
{
	system("cls");
	ifstream search(file);
	ofstream fill(writeFile, ios::out); //fill - Заполнить

	if (!search)
		cout << "Файл не открыт." << endl;

	CarWithLineNumber localCar;
	string line, searchNumber;
	int k = 0;

	cout << "Введите городской номер для удаления: ";
	cin >> searchNumber;

	while (getline(search, line)) {
		stringstream ss(line);

		ss >> k >> localCar.car.numberOfCar >> localCar.car.brand >> localCar.car.horsePower >> localCar.car.distanceTravelled
			>> localCar.car.fuelConsumption >> localCar.car.koefD;

		if (searchNumber != localCar.car.numberOfCar)
		{
			fill << line << "\n";
		}
	}

	search.close();
	fill.close();

	//Перезапись
	ifstream withdraw(writeFile, ios::in);
	ofstream output(file, ios::trunc);

	if (!output) cout << "Файл не открыт." << endl;

	while (getline(withdraw, line))
	{
		output << line << "\n";
	}

	withdraw.close();
	output.close();

	cout << "Удаление по бренду " << searchNumber << " успешно выполнено.\n";
	system("pause");
	system("cls");
	Menu();
}

void DeleteCarByBrand(string file)
{
	system("cls");
	ifstream search(file);
	ofstream fill(writeFile, ios::out); //fill - Заполнить

	if (!search)
		cout << "Файл не открыт." << endl;

	CarWithLineNumber localCar;
	string line, searchBrand;
	int k = 0;

	cout << "Введите бренд для удаления: ";
	cin >> searchBrand;

	while (getline(search, line)) {
		stringstream ss(line);

		ss >> localCar.lineNumber >> localCar.car.numberOfCar >> localCar.car.brand >> localCar.car.horsePower >> localCar.car.distanceTravelled
			>> localCar.car.fuelConsumption >> localCar.car.koefD;

		if (searchBrand != localCar.car.brand)
		{
			fill << line << "\n";
		}
	}

	search.close();
	fill.close();

	//Перезапись
	ifstream withdraw(writeFile, ios::in);
	ofstream output(file, ios::trunc);

	if (!output) cout << "Файл не открыт." << endl;

	while (getline(withdraw, line))
	{
		output << line << "\n";
	}

	withdraw.close();
	output.close();

	cout << "\t\tУдаление по городскому номеру " << searchBrand << " успешно выполнено.\n";
	system("pause");
	system("cls");
	Menu();
}

void DeleteCarAll(string file)
{
	ofstream fdelete(file, ios::trunc);
	fdelete.close();
	system("cls");

	cout << "\t\tВсе автомобили удалены успешно. \n";

	system("pause");
	Menu();
}

void MenuSort()
{
	system("cls");
	int request;
	cout << "\t\t\t\tМеню с сортировками \n\n";
	cout << "\t\t\t\t+------------------------------------+ \n";
	cout << "\t\t\t\t|" << " 1 - Сортировка по городскому номеру" << setw(2) << "|\n";
	cout << "\t\t\t\t+------------------------------------+ \n";
	cout << "\t\t\t\t|" << " 2 - Сортировка по бренду " << setw(12) << "|\n";
	cout << "\t\t\t\t+------------------------------------+ \n";
	cout << "\t\t\t\t|" << " 3 - Сортировка по лошадиным силам " << setw(3) << "|\n";
	cout << "\t\t\t\t+------------------------------------+ \n";
	cout << "\t\t\t\t|" << " 4 - Сортировка по пробегу " << setw(11) << "|\n";
	cout << "\t\t\t\t+------------------------------------+ \n";
	cout << "\t\t\t\t|" << " 5 - Главное меню " << setw(20) << "|\n";
	cout << "\t\t\t\t+------------------------------------+ \n";
	cout << "\n\t\t\t\tВведите запрос = ";
	cin >> request;
	switch (request)
	{
	case 1:
		sortByNumberOfCar();
		break;
	case 2:
		SortByBrand();
		break;
	case 3:
		SortByHorsePower();
		break;
	case 4:
		SortByDistanceTravelled();
		break;
	case 5:
		Menu();
		break;
	}
}

void sortByNumberOfCar()
{
	ifstream ifStreamSort(file1);
	ofstream ofStreamSort(sortFile, ios::out);
	if (!ifStreamSort)
		cout << "Файл не открыт." << endl;

	CarWithLineNumber localCar;
	string stream;
	int k;
	vector <CarWithLineNumber> carsVector;

	while (getline(ifStreamSort, stream))
	{
		// Создание объекта типа Car из строки stream и добавление его в вектор carsVector
		stringstream streamWord(stream);

		streamWord >> localCar.lineNumber >> localCar.car.numberOfCar >> localCar.car.brand >> localCar.car.horsePower >> localCar.car.distanceTravelled
			>> localCar.car.fuelConsumption >> localCar.car.koefD;

		carsVector.push_back(localCar);
	}

	int request;
	system("cls");
	cout << "\n\t\t\t\t+------------------------------------+ \n";
	cout << "\t\t\t\t|" << " 1 - Сортировка по возрастанию" << setw(8) << "|\n";
	cout << "\t\t\t\t+------------------------------------+ \n";
	cout << "\t\t\t\t|" << " 2 - Сортировка по убыванию " << setw(10) << "|\n";
	cout << "\t\t\t\t+------------------------------------+ \n";
	cout << "\n\t\t\t\tВведите запрос = ";
	cin >> request;

	if (request == 1)
	{
		std::sort(carsVector.begin(), carsVector.end(), [](const CarWithLineNumber& a, const CarWithLineNumber& b)
			{
				return a.car.numberOfCar< b.car.numberOfCar;
			});
	}

	else if (request == 2)
	{
		std::sort(carsVector.begin(), carsVector.end(), [](const CarWithLineNumber& a, const CarWithLineNumber& b)
			{
				return a.car.numberOfCar > b.car.numberOfCar;
			});
	}

	else
	{
		system("cls");
		cout << "\n\t\t\t\tНеверный запрос, попробуйте ещё раз.\n\n";
		system("pause");
		MenuSort();
	}

	for (const auto& car : carsVector)
	{
		// Запись объекта car в файл ofStream
		ofStreamSort << car.lineNumber << "\t" << car.car.numberOfCar << "\t" << car.car.brand << "\t"
			<< car.car.horsePower << "\t" << car.car.distanceTravelled << "\t"
			<< car.car.fuelConsumption << "\t" << car.car.koefD << "\n";
	}

	ifStreamSort.close();
	ofStreamSort.close();

	system("cls");
	Output(sortFile);
}

void SortByBrand()
{
	ifstream ifStreamSort(file1);
	ofstream ofStreamSort(sortFile, ios::out);
	if (!ifStreamSort)
		cout << "Файл не открыт." << endl;

	CarWithLineNumber localCar;
	string stream;
	int k;
	vector <CarWithLineNumber> carsVector;

	while (getline(ifStreamSort, stream))
	{
		// Создание объекта типа Car из строки stream и добавление его в вектор carsVector
		stringstream streamWord(stream);

		streamWord >> localCar.lineNumber >> localCar.car.numberOfCar >> localCar.car.brand >> localCar.car.horsePower >> localCar.car.distanceTravelled
			>> localCar.car.fuelConsumption >> localCar.car.koefD;

		carsVector.push_back(localCar);
	}

	int request;
	system("cls");
	cout << "\n\t\t\t\t+------------------------------------+ \n";
	cout << "\t\t\t\t|" << " 1 - Сортировка по возрастанию" << setw(8) << "|\n";
	cout << "\t\t\t\t+------------------------------------+ \n";
	cout << "\t\t\t\t|" << " 2 - Сортировка по убыванию " << setw(10) << "|\n";
	cout << "\t\t\t\t+------------------------------------+ \n";
	cout << "\n\t\t\t\tВведите запрос = ";
	cin >> request;

	if (request == 1)
	{
		std::sort(carsVector.begin(), carsVector.end(), [](const CarWithLineNumber& a, const CarWithLineNumber& b)
			{
				return a.car.brand < b.car.brand;
			});
	}

	else if (request == 2)
	{
		std::sort(carsVector.begin(), carsVector.end(), [](const CarWithLineNumber& a, const CarWithLineNumber& b)
			{
				return a.car.brand > b.car.brand;
			});
	}

	else
	{
		system("cls");
		cout << "\n\t\t\t\tНеверный запрос, попробуйте ещё раз.\n\n";
		system("pause");
		MenuSort();
	}
	for (const auto& car : carsVector)
	{
		// Запись объекта car в файл ofStream
		ofStreamSort << car.lineNumber << "\t" << car.car.numberOfCar << "\t" << car.car.brand << "\t"
			<< car.car.horsePower << "\t" << car.car.distanceTravelled << "\t"
			<< car.car.fuelConsumption << "\t" << car.car.koefD << "\n";
	}

	ifStreamSort.close();
	ofStreamSort.close();

	system("cls");
	Output(sortFile);
}

void SortByHorsePower()
{
	ifstream ifStreamSort(file1);
	ofstream ofStreamSort(sortFile, ios::out);
	if (!ifStreamSort)
		cout << "Файл не открыт." << endl;

	CarWithLineNumber localCar;
	string stream;
	int k;
	vector <CarWithLineNumber> carsVector;

	while (getline(ifStreamSort, stream))
	{
		// Создание объекта типа Car из строки stream и добавление его в вектор carsVector
		stringstream streamWord(stream);

		streamWord >> localCar.lineNumber >> localCar.car.numberOfCar >> localCar.car.brand >> localCar.car.horsePower >> localCar.car.distanceTravelled
			>> localCar.car.fuelConsumption >> localCar.car.koefD;

		carsVector.push_back(localCar);
	}
	int request;
	system("cls");
	cout << "\n\t\t\t\t+------------------------------------+ \n";
	cout << "\t\t\t\t|" << " 1 - Сортировка по возрастанию" << setw(8) << "|\n";
	cout << "\t\t\t\t+------------------------------------+ \n";
	cout << "\t\t\t\t|" << " 2 - Сортировка по убыванию " << setw(10) << "|\n";
	cout << "\t\t\t\t+------------------------------------+ \n";
	cout << "\n\t\t\t\tВведите запрос = ";
	cin >> request;

	if (request == 1)
	{
		std::sort(carsVector.begin(), carsVector.end(), [](const CarWithLineNumber& a, const CarWithLineNumber& b)
			{
				return a.car.horsePower < b.car.horsePower;
			});
	}

	else if (request == 2)
	{
		std::sort(carsVector.begin(), carsVector.end(), [](const CarWithLineNumber& a, const CarWithLineNumber& b)
			{
				return a.car.horsePower > b.car.horsePower;
			});
	}

	else
	{
		system("cls");
		cout << "\n\t\t\t\tНеверный запрос, попробуйте ещё раз.\n\n";
		system("pause");
		MenuSort();
	}

	for (const auto& car : carsVector)
	{
		// Запись объекта car в файл ofStream
		ofStreamSort << car.lineNumber << "\t" << car.car.numberOfCar << "\t" << car.car.brand << "\t"
			<< car.car.horsePower << "\t" << car.car.distanceTravelled << "\t"
			<< car.car.fuelConsumption << "\t" << car.car.koefD << "\n";
	}

	ifStreamSort.close();
	ofStreamSort.close();

	system("cls");
	Output(sortFile);
}

void SortByDistanceTravelled()
{
	ifstream ifStreamSort(file1);
	ofstream ofStreamSort(sortFile, ios::out);
	if (!ifStreamSort)
		cout << "Файл не открыт." << endl;

	CarWithLineNumber localCar;
	string stream;
	int k;
	vector <CarWithLineNumber> carsVector;

	while (getline(ifStreamSort, stream))
	{
		// Создание объекта типа Car из строки stream и добавление его в вектор carsVector
		stringstream streamWord(stream);

		streamWord >> localCar.lineNumber >> localCar.car.numberOfCar >> localCar.car.brand >> localCar.car.horsePower >> localCar.car.distanceTravelled
			>> localCar.car.fuelConsumption >> localCar.car.koefD;

		carsVector.push_back(localCar);
	}

	int request;
	system("cls");
	cout << "\n\t\t\t\t+------------------------------------+ \n";
	cout << "\t\t\t\t|" << " 1 - Сортировка по возрастанию" << setw(8) << "|\n";
	cout << "\t\t\t\t+------------------------------------+ \n";
	cout << "\t\t\t\t|" << " 2 - Сортировка по убыванию " << setw(10) << "|\n";
	cout << "\t\t\t\t+------------------------------------+ \n";
	cout << "\n\t\t\t\tВведите запрос = ";
	cin >> request;

	if (request == 1)
	{
		std::sort(carsVector.begin(), carsVector.end(), [](const CarWithLineNumber& a, const CarWithLineNumber& b)
			{
				return a.car.distanceTravelled < b.car.distanceTravelled;
			});
	}

	else if (request == 2)
	{
		std::sort(carsVector.begin(), carsVector.end(), [](const CarWithLineNumber& a, const CarWithLineNumber& b)
			{
				return a.car.distanceTravelled > b.car.distanceTravelled;
			});
	}

	else
	{
		system("cls");
		cout << "\n\t\t\t\tНеверный запрос, попробуйте ещё раз.\n\n";
		system("pause");
		MenuSort();
	}

	for (const auto& car : carsVector)
	{
		// Запись объекта car в файл ofStream
		ofStreamSort << car.lineNumber << "\t" << car.car.numberOfCar << "\t" << car.car.brand << "\t"
			<< car.car.horsePower << "\t" << car.car.distanceTravelled << "\t"
			<< car.car.fuelConsumption << "\t" << car.car.koefD << "\n";
	}

	ifStreamSort.close();
	ofStreamSort.close();

	system("cls");
	Output(sortFile);
}