#include <iostream>
#include <cmath>
#include <cstdlib>

int main(void)
{
	using namespace std;

	double area;
	cout << "Enter the floor area, in square feet, of your home: ";
	cin >> area;
	double side;
	side = sqrt(area);
	cout << "That's the equivalent of a square " << side
		 << " feet to the side" << endl;
	cout << "How fascinating!" << endl;

	system("pause");
	return 0;
}