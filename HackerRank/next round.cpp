#include <iostream>

int main()
{
	int scores[50];
	int n{ 0 }, k{ 0 }, nNextRound{ 0 }, i{ 0 };
	
	std::cin >> n >> k;
	
	while (i < n)
	{
		std::cin >> scores[i];
		i++;
	}
	
	//for (i = k + 1; (scores[i] >= scores[k]) && (i<n); i++){ nNextRound++; }
	
	i = 0;
	while (scores[i] >= scores[k-1] && i<n)
	{
		if (scores[i] > 0)
			nNextRound++;
		i++;
	}

	std::cout << nNextRound;
}