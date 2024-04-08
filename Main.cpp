#include <iostream>
#include <string>

using namespace std;
int x;

class Game
{
public:
	Game() : Name(), score()
	{

	}
	Game(string _Name, int _score) : Name(_Name), score(_score)
	{

	}

	void Show()
	{
		cout << Name << ' ' << score;
	}
private:
	string Name;
	int score;
};

void ScoreSet()
{
	int* a = new int[x];
	for (int i = 0; i < x; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < x; i++)
	{
		int j = i - 1;
		while (j >= 0 && a[j] > a[j + 1])
		{
			swap(a[j], a[j + 1]);
			j--;
		}
	}

	for (int i = 0; i < x; i++)
	{
		cout << a[i] << " ";
	}
		
	delete[] a; 
}

int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите количество игроков: ";
	cin >> x;

	ScoreSet();
	
}