#include <iostream>

void printSum(int arrA[], int arrB[]) {
	int x1{ arrA[0] }, y1{ arrA[1] }, z1{ arrA[2] }, x2{ arrB[0] }, y2{ arrB[1] }, z2{ arrB[2] };
	int sum{ 0 }, i{ 0 };
	
	if (z1 < y2) 
	{
		for (i = 0; i < z1; i++)
		{
			sum += 2;
		}
	}

	else
	{
		for (i = 0; i < y2; i++)
		{
			sum += 2;
		}
	}

	if( y2 > z1 && z2 > x1)
	{
		for (i = 0; i < (y1 - y2 + z1 - x1); i++)
		{
			sum -= 2;
		}
	}
	else if (y2 <= z1 && z2 > x1)
	{
		for (i = 0; i < y1 - x1; i++)
		{
			sum -= 2;
		}
	}

	std::cout << sum << '\n';
}


int main()
{
	int arrOfA[1000][3], arrOfB[10000][3];
	int t{ 0 }, i{ 0 };

	std::cin >> t;
	
	for ( i = 0; i < t; i++)
	{
		std::cin >> arrOfA[i][0] >> arrOfA[i][1] >> arrOfA[i][2];
		std::cin >> arrOfB[i][0] >> arrOfB[i][1] >> arrOfB[i][2];

	}

	for( i = 0; i < t; i++)
	{
		printSum(arrOfA[i], arrOfB[i]);
	}
	return 0;
}