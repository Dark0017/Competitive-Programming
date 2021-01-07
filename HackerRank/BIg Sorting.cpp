#include <iostream>
#include <vector>
#include <string>

using namespace std;

void swap(string* a, string* b)
{
	string t = *a;
	*a = *b;
	*b = t;
}

bool checkIfBigger(string a, string b) {
	if (a.length() < b.length())
		return true;
	if (a.length() > b.length())
		return false;
	else
	{
		for (int i = 0; i < a.length(); i++)
		{
			if (static_cast<int>(a[i]) < static_cast<int>(b[i]))
				return true;
		}
		return false;
	}

}

int partition(std::vector<string>& arr, int low, int high)
{
	string pivot = arr[high]; 
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{
		
		if (checkIfBigger(arr[j], pivot))
		{
			i++; // increment index of smaller element  
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}

void quickSort(std::vector<string>& arr, int low, int high)
{
	if (low < high)
	{
		
		int pi = partition(arr, low, high);

		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}

/*void InsertionSort(std::vector<string>& arr) {
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
}*/


int main()
{
	
	int n{ 0 };
	vector<string> arr;
	string temp{ "" };
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	arr.resize(n);

	for (int i = 0; i < n; i++)
	{
		getline(cin, arr[i]);
	}

	quickSort(arr,0, arr.size() -1 );

	for(int i{0}; i < n; i++)
	{
		cout << arr[i];
		if (i != n - 1)
			cout << "\n";
	}

}