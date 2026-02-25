#include<iostream>
#include<conio.h>

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

	//GameLoop
	//Frame
	for (;;)
	{
		//Render
		for (int Y = 0; Y < 10; ++Y)
		{
			for (int X = 0; X < 10; ++X)
			{
				if (PlayerX == X && PlayerY == Y)
				{
					cout << "@";
				}
				else if (Map[Y][X] == 1)
				{
					cout << "#";
				}
				else if (Map[Y][X] == 0) {
					cout << ' ';
				}

				if (Map[Y][X] == 9) {
					cout << 'G';
				}
				cout << ' ';
			}
			cout << '\n';
		}

		//Process();
		int Temp;
		Temp = _getch();

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
		if (Map[PlayerY][PlayerX] == 9)
		{
			Map[PlayerY][PlayerX] = '@';
			cout << "골인~!";
			break;
		}
		system("cls");
	}

	return 0;
}