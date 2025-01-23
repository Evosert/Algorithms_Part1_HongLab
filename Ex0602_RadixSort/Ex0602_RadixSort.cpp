#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <fstream>
#include <chrono>
#include <numeric>
#include <iomanip>
using namespace std;

void Print(vector<int>& arr)
{
	for (auto& a : arr)
		cout << a << " ";
	cout << endl;
}

// 편의상 결과가 arr에 저장되도록 바꿨습니다.
void CountingSort(vector<int>& arr, int k, int exp)
{
	vector<int> temp = arr; // 복사

	vector<int> count(k + 1, 0);
	// TODO:
	for (auto a : temp)
	{
		count[a / exp % 10] += 1;
	}
	for (int i = 1; i < count.size(); i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		// TODO:
		arr[count[temp[i] / exp % 10] - 1] = temp[i];
		count[temp[i] / exp % 10]--;

		cout << "Count: ";
		Print(count);

		cout << "Output: ";
		Print(arr);
	}
}

void RadixSort(vector<int>& arr)
{
	int k = 9; // 0 이상 9 이하
	int m = *max_element(arr.begin(), arr.end());

	for (int exp = 1; m / exp > 0; exp *= 10)
	{
		cout << "exp = " << exp << endl;
		CountingSort(arr, k, exp);
	}
}

int main()
{
	vector<int> arr = { 170, 45, 75, 90, 802, 24, 2, 66 };
	//vector<int> arr = { 2, 5, 3, 0, 2, 3, 0, 3 };

	Print(arr);

	RadixSort(arr);

	return 0;
}