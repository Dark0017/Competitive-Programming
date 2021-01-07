#include <iostream>
#include <vector>
#include <string>
#include <cmath>
using namespace std;

vector<int> getPair(vector<int>& arr){
	int nAns{ 0 };//keep track of number of elements in answer

	int lowest{ abs(arr[0] - arr[1]) };
	vector<int> answer;
	
	for (int i = 0; i < static_cast<int>(arr.size()); i++)
	{
		for (int j = i+1; j < static_cast<int>(arr.size()); j++)
		{
			if (abs(arr[i] - arr[j]) == lowest)
			{
				nAns += 2;
				answer.resize(nAns);
				answer[nAns - 2] = arr[i];
				answer[nAns - 1] = arr[j];
			}
			if (abs(arr[i] - arr[j]) < lowest)
			{
				nAns = 2;
				lowest = abs(arr[i] - arr[j]);
				answer.resize(nAns);
				answer[nAns - 2] = arr[i];
				answer[nAns - 1] = arr[j];
			}
		}
	}
	return answer;
}


int main()
{
	vector<int> str{ -5, 15, 25, 71, 63 };
	vector<int> ans = getPair(str);
	
	cout << ans[0] << " " << ans[1];

	return 0;
}