#include<iostream>
#include<conio.h>
#include<random>

using namespace std;

int main()
{
	int Map[10][10] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 1, 1, 1, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 1, 0, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 1, 1, 1},
	{1, 1, 1, 0, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 1, 0, 1},
	{1, 1, 1, 0, 1, 0, 1, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 1, 0, 9, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
	};

	int PlayerX = 1;
	int PlayerY = 1;

	int EnemyX = 8;
	int EnemyY = 1;

	//GameLoop
	//Frame
	for (;;)
	{
		//Process();
		int Temp;
		Temp = _getch();

		int PrevPlayerX = PlayerX;
		int PrevPlayerY = PlayerY;
		int PrevEnemyX = EnemyX;
		int PrevEnemyY = EnemyY;


		if (Temp == 'w' || Temp == 'W') //w키
		{
			if (Map[PlayerY - 1][PlayerX] != 1) PlayerY--;
		}
		if (Temp == 's' || Temp == 'S') //s키
		{
			if (Map[PlayerY + 1][PlayerX] != 1) PlayerY++;
		}
		if (Temp == 'a' || Temp == 'A') //a키
		{
			if (Map[PlayerY][PlayerX - 1] != 1) PlayerX--;
		}
		if (Temp == 'd' || Temp == 'D') //d키
		{
			if (Map[PlayerY][PlayerX + 1] != 1) PlayerX++;
		}

		//적 움직임
		int Random = rand() % 4;

		for (;;) {
			bool EnemyMoveCount = false;
			if (Random == 0)
			{
				if (Map[EnemyY - 1][EnemyX] != 1) 
				{
					EnemyY--;
					EnemyMoveCount = true;
				}
			}
			else if (Random == 1)
			{
				if (Map[EnemyY + 1][EnemyX] != 1)
				{
					EnemyY++;
					EnemyMoveCount = true;
				}
			}
			else if (Random == 2)
			{
				if (Map[EnemyY][EnemyX - 1] != 1)
				{
					EnemyX--;
					EnemyMoveCount = true;
				}
			}
			else if (Random == 3)
			{
				if (Map[EnemyY][EnemyX + 1] != 1)
				{
					EnemyX++;
					EnemyMoveCount = true;
				}
			}
			if (EnemyMoveCount) break;
		}

		system("cls");

		//Render
		for (int Y = 0; Y < 10; ++Y)
		{
			for (int X = 0; X < 10; ++X)
			{
				if (PlayerX == X && PlayerY == Y)
				{
					cout << 'o';
				}
				else if (EnemyX == X && EnemyY == Y)
				{
					cout << '?';
				}
				else if (Map[Y][X] == 1)
				{
					cout << "+";
				}
				else if (Map[Y][X] == 0) {
					cout << ' ';
				}
				else if (Map[Y][X] == 9) {
					cout << 'G';
				}

				cout << ' ';
			}
			cout << '\n';
		}

		//Goal
		if (Map[PlayerY][PlayerX] == 9)
		{
			cout << "골인~!";
			break;
		}

		//적이랑 닿을 경우
		if ((PrevPlayerX == EnemyX && PrevPlayerY == PlayerY) || (PlayerY == EnemyY && PlayerX == EnemyX)) {
			cout << "GameOver...";
			break;
		}
	}

	return 0;
}