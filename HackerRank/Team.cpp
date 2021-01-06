#include <iostream>

int main()
{
	int nProbs{ 0 }, nSolv{ 0 };
	
	std::cin >> nProbs;
	
	while (nProbs--)
	{
		int n1, n2, n3;
		std::cin >> n1 >> n2 >> n3;
		if ((n1 + n2 + n3) >= 2)
			nSolv++;
	}

	std::cout << nSolv;
}