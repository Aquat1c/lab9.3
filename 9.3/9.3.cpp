#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>

using namespace std;

struct Zodiac
{
	string surname;
	string zodiac;
	int date[3];
};

void Create(Zodiac* p, const int N);
void Print(Zodiac* p, const int N);
int BinSearch(Zodiac* p, const int N, const string surname);
void PrintSearch(Zodiac* p, const int Num);
void Sort(Zodiac* p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N;
	cout << " Введіть кількість людей:"; cin >> N;
	Zodiac* p = new Zodiac[N];

	string zodiak;
	string surname;
	string date;
	int found;

	int MenuItem;
	do {
		cout << endl << endl << endl;
		cout << "Виберіть дію: " << endl << endl;
		cout << "[1] - ввід з клавіатури" << endl;
		cout << "[2] - вивід данних" << endl;
		cout << "[3] -	фізичне упорядкування за зодіаками" << endl;
		cout << "[4] - пошук інформації за місяцем " << endl;
		cout << endl << endl;
		cout << "[0] - вихід з програми" << endl << endl;
		cout << "Введіть значення: "; cin >> MenuItem;
		cout << endl << endl << endl;

		switch (MenuItem)
		{
		case 1:
			Create(p, N);
			break;
		case 2:
			Print(p, N);
			break;
		case 3:
			Sort(p, N);
			break;
		case 4:
			cout << "Введіть ключі пошуку:" << endl;
			cin.get();
			cin.sync();
			cout << "Місяць: "; getline(cin, date);
			cout << endl;
			if ((found = BinSearch(p, N, date)) != -1)
			{
				cout << "Інформація за заданим параметром \n";
				PrintSearch(p, found + 1);
			}
			else
				cout << "Не знайдено" << endl;
			break;
		case 0:
			break;
		default:
			cout << "Ви ввели неправильне значення"
				"Введіть число вибраного елемента в меню" << endl;
		}
	} while (MenuItem != 0);
	return 0;
}

void Create(Zodiac* p, const int N)
{
	int zodiac;
	int date[3];
	for (int i = 0; i < N; i++)
	{
		cout << " Людина # " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " Знак Зодіаку: "; getline(cin, p[i].zodiac);

		cout << " Прізвище: "; getline(cin, p[i].surname);
		cout << "Дата народження " << i << " День-Місяць-Рік:\n";
		cin >> p[i].date[1] >> p[i].date[2] >> p[i].date[3];
		cout << endl << endl;
	}
}

void Print(Zodiac* p, const int N)
{
	cout << "=========================================================="
		<< endl;
	cout << "|  #  |     Знак Зодіаку    |      Прізвище     |     Дата народження     |"
		<< endl;
	cout << "=========================================================="
		<< endl;

	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(3) << right << i + 1 << " ";
		cout << "| " << setw(16) << left << p[i].zodiac
			<< "| " << setw(16) << left << p[i].surname
			<< "| " << setw(12) << right << setprecision(2) << p[i].date[1] << "-" << p[i].date[2]<< "-" << p[i].date[3] << " |";
		cout << endl;
		cout << "----------------------------------------------------------";
		cout << endl;
	}
}

int BinSearch(Zodiac* p, const int N, const string zodiak)
{
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (p[m].zodiac == zodiak)
			return m;

		if (p[m].zodiac < zodiak)
			L = m + 1;

		else
			R = m - 1;

	} while (L <= R);
	return -1;
}

void PrintSearch(Zodiac* p, const int Num)
{
	cout << "=========================================================="
		<< endl;
	cout << "|  #  |     Знак Зодіаку    |      Прізвище     |     Дата Народження      |"
		<< endl;
	cout << "----------------------------------------------------------"
		<< endl;

	cout << "| " << setw(3) << right << Num << " ";
	cout << "| " << setw(16) << left << p[Num].zodiac
		<< "| " << setw(16) << left << p[Num].surname
		<< "| " << setw(12) << right << setprecision(2) << p[Num].date << " |";
	cout << endl;
	cout << "----------------------------------------------------------" << endl;
}
void Sort(Zodiac* p, const int N)
{
	Zodiac tmp;
	for (int i = 0; i < N - 1; i++) // "bubbles" method
		for (int j = 0; j < N - i - 1; j++)
			if (p[j].zodiac > p[j + 1].zodiac) {
				tmp = p[j];
				p[j] = p[j + 1];
				p[j + 1] = tmp;
			}
}