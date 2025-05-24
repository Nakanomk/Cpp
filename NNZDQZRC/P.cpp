#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

typedef struct P
{
	/* data */
	string dic;
	string num;
} Word;

int main(void)
{
	Word n[5000];
	char m[20][50000];
	int ni, mi;
	int a;
	cin >> ni >> mi;
	for (int i = 0; i < ni; i++)
	{
		cin >> n[i].dic >> n[i].num;
	}
	for (int i = 0; i < mi; i++)
	{
		while (getchar() != '\n')
			;
		gets(m[i]);

		cout << m[i];
	}
	system("pause");
	return 0;
}