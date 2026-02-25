#include<iostream>

using namespace std;

int main()
{
	int num1 = 0;
	int num2 = 0;

	cin >> num1 >> num2;

	cout << "ÇÕ: " << num1 + num2 << '\n';
	cout << "Â÷: " << num1 - num2 << '\n';
	cout << "°ö: " << num1 * num2 << '\n';
	cout << "¸ò: " << num1 / num2 << '\n';
	cout << "³ª¸ÓÁö: " << num1 % num2 << '\n';

	return 0;
}