#include <iostream>
#include <string>

using namespace std;
int x;

class Player
{
public:
	void SetPoints(int _points) 
	{ 
		points = _points; 
	}
	void SetName(string _name)
	{
		Name = _name;
	}
	int GetPoints()
	{
		return points;
	}
	string GetName()
	{
		return Name;
	}
private:
	string Name;
	int points = 0;
};


int main()
{
	setlocale(LC_ALL, "Russian");

	cout << "Введите количество игроков: ";
	cin >> x;


	Player** players = new Player * [x];

	int p;
	string n;


	for (int i = 0; i < x; ++i)

	{
		players[i] = new Player();
		cout << "Имя игрока: ";
		cin >> n;
		players[i]->SetName(n);
		cout << "Количество очков: ";
		cin >> p;
		players[i]->SetPoints(p);
	}
	
	for (int i = 0; i < x; i++)
	{
		int j = i - 1;
		while (j >= 0 && players[j]->GetPoints() > players[j + 1]->GetPoints())
		{
			swap(players[j], players[j + 1]);
			j--;
		}
	}

	for (int i = 0; i < x; i++)
	{
		cout << players[i]->GetName() << " " << players[i]->GetPoints() << "\n";
	}

	delete[] players;
}