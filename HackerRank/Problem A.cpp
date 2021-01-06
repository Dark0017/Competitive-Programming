#include <iostream>

void printSteps(int n, int k) {
	int steps{ 0 }, i{ 0 };
	if (n == 1 && k == 0)
		steps++;
	else
	{
		while (((n - k) < 0))
		{
			n++;
			steps++;
		}
	}


	std::cout << steps << '\n';
}



int main()
{
	int nArr[6000], kArr[6000];
	int t{ 0 }, i{ 0 };

	std::cin >> t;
	
	for ( i = 0; i < t; i++)
	{
		std::cin >> nArr[i];
		std::cin >> kArr[i];
	}

	for( i = 0; i < t; i++)
	{
		printSteps(nArr[i], kArr[i]);
	}
	return 0;
}