#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

void InsertionSort(vector<int>& arr) {
	int j{ 0 }, i{ 0 }, key{ 0 };
	for (j = 1; j < arr.size(); j++)
	{
		key = arr[j];

		i = j - 1;
		while (i >= 0 && arr[i] > key)
		{
			arr[i + 1] = arr[i];
			i--;
		}

		arr[i + 1] = key;
	}
}
//a are factors of x
//x is factor of all b

int getTotalX(vector<int>& a, vector<int>& b){
	InsertionSort(a);
	InsertionSort(b);
	int ans{ 0 };
	bool isFactor{true};

	for (int i = a[0]; i <= max(a[a.size()-1], b[b.size()-1] ); i++)
	{
		isFactor = true;
		for (int j = 0; j < a.size(); j++)
		{
			if (i % a[j] != 0)
				isFactor = false;
		}

		for (int k = 0; k < b.size(); k++)
		{
			if (b[k] % i != 0)
				isFactor = false;
		}

		if (isFactor)
			ans++;

	}
	return ans;
}


int main()
{
	int m{ 0 }, n{ 0 };
	vector<int> a;
	vector<int> b;

	cin >> m >> n;
	a.resize(m);
	b.resize(n);

	while (m)
	{
		cin >> a[a.size() - m];
		m--;
	}
	while (n)
	{
		cin >> b[b.size() - n];
		n--;
	}

	int x = getTotalX(a, b);
	cout << x;
	return 0;
}