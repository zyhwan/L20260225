#include<iostream>

using namespace std;

int main()
{
	int Number1 = 0;
	int Number2 = 0;

	int Number3 = 0;

	cin >> Number1 >> Number2 >> Number3;

	cout << "합: " << Number1 + Number2 + Number3 << '\n';
	cout << "차: " << Number1 - Number2 - Number3 << '\n';
	cout << "곱: " << Number1 * Number2 * Number3 << '\n';
	cout << "몫: " << Number1 / Number2 / Number3 << '\n';
	cout << "나머지: " << Number1 % Number2 % Number3 << '\n';

	return 0;
}