#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool checkIfBigger(string a, string b) {
	if (a.length() > b.length())
		return true;
	if (a.length() < b.length())
		return false;
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (static_cast<int>(a[i]) > static_cast<int>(b[i]))
				return true;
		}
		return false;
	}

}

void InsertionSort(std::vector<string>& arr) {
	int j{ 0 }, i{ 0 };
	string key{ "" };

	for (j = 1; j < arr.size(); j++)
	{
		key = arr[j];

		i = j - 1;
		while (i >= 0 && checkIfBigger(arr[i], key))
		{
			arr[i + 1] = arr[i];
			i--;
		}

		arr[i + 1] = key;
	}
}


int main()
{
	
	int n{ 0 };
	vector<string> arr;
	string temp{ "" };
	cin >> n;
	arr.resize(n);

	for (int i = 0; i < n; i++)
	{
		getline(cin, arr[i]);
	}

	InsertionSort(arr);

	for(int i{0}; i < n; i++)
	{
		cout << arr[i];
		if (i != n - 1)
			cout << "\n";
	}

}