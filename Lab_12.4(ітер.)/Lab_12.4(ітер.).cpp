#include <iostream>
#include <Windows.h>
#include <time.h>

using namespace std;

typedef int inform;

struct Spusok
{
	Spusok* link;
	inform inf;
};

void Creata(Spusok*& L, Spusok*& T, inform inf);
void COUT(Spusok*& T, Spusok*& L);
void Process(Spusok*& L, Spusok*& L1, Spusok*& L2, Spusok*& T, Spusok*& G);

int main(void)
{
	srand((unsigned)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Spusok* L = NULL;
	Spusok* L1 = NULL;
	Spusok* L2 = NULL;
	Spusok* T, * G;

	int x = 0;
	for (int i = 0; i < 6; i++)
	{
		T = L;
		x = 6 - rand() % 12;
		Creata(L, T, x);
	}

	cout << "Список сформований:" << endl << endl;
	T = L;
	COUT(T, L);

	T = L;
	Process(L, L1, L2, T, G);
	cout << "Список з додатніми числами сформований:" << endl << endl;
	T = L1;
	COUT(T, L1);
	cout << "Список з від'ємними числами сформований:" << endl << endl;
	T = L2;
	COUT(T, L2);

	return 0;
}

void Creata(Spusok*& L, Spusok*& T, inform inf)
{
	Spusok* tmp = new Spusok;

	if (L != NULL)
		while (T->link != L)
			T = T->link;

	tmp->inf = inf;
	if (L == NULL)
		L = tmp;
	else
		T->link = tmp;
	tmp->link = L;
}

void COUT(Spusok*& T, Spusok*& L)
{
	inform inf;

	while (T->link != L)
	{
		inf = T->inf;
		cout << inf << "   ";
		T = T->link;
	}
	inf = T->inf;
	cout << inf << "   ";
	cout << endl << endl;
}

void Process(Spusok*& L, Spusok*& L1, Spusok*& L2, Spusok*& T, Spusok*& G)
{
	int zmina = 0;
	inform index;
	while (T->link != L)
	{
		index = T->inf;            // 1('index' отримує значення від елемента(інформаційного поля))
		T = T->link;               // 2(перехід вказівника 'T' на наступну позицію(вперед))
		if (index >= 0)
		{
			G = L1;                // 3(якщо 'index >= 0' то вказівник 'G' отримує(значення) адресу вказівника 'L1')
			Creata(L1, G, index);  // 4(якщо 'index >= 0' то відбувається створення нового списку(першого) і добавлення певного елемнта)
		}
		else
		{
			G = L2;                // 3(інкаше вказівник 'G' отримує(значення) адресу вказівника 'L2')
			Creata(L2, G, index);  // 4(інакше відбуваєтьься створення нового списку(другого) і добавлення певного елемнта)
		}
	}

	if (index >= 0)           //для перевірки останнього елемна
	{
		G = L1;
		Creata(L1, G, index);
	}
	else
	{
		G = L2;
		Creata(L2, G, index);
	}
}