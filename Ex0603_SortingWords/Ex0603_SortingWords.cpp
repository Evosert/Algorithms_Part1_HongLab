#include <iostream>
#include <vector>
#include <random>
#include <limits>
#include <fstream>
#include <chrono>
#include <numeric>
#include <iomanip>
#include <string>
using namespace std;

template<typename T>
void Print(vector<T>& arr)
{
	for (auto& a : arr)
		cout << a << " ";
	cout << endl;
}

void CountingSort(vector<string>& arr, int k, int d)
{
	vector<string> temp = arr; // 복사
	std::fill(arr.begin(), arr.end(), "   "); // 디버깅 편의

	// TODO:
	vector<int> count(k + 1, 0);
	for (auto a : temp)
	{
		count[a[d] - 'A']++;
	}
	for (int i = 1; i < count.size(); i++)
	{
		count[i] += count[i - 1];
	}

	for (int i = arr.size() - 1; i >= 0; i--)
	{
		arr[count[temp[i][d] - 'A'] - 1] = temp[i];
		count[temp[i][d] - 'A']--;

		cout << "Count: ";
		Print(count);

		cout << "Output: ";
		Print(arr);
	}
}

void RadixSort(vector<string>& arr)
{
	// TODO:
	int k = 25;

	for (int d = 2; d >= 0; d--)
	{
		cout << "Digit = " << d << endl;
		CountingSort(arr, k, d);
	}
}

// 정답:
//void CountingSort(vector<string>& arr, int k, int d)
//{
//	vector<string> temp = arr; // 복사
//
//	vector<int> count(k + 1, 0);
//	for (auto a : temp) count[a[d] - 'A'] += 1;
//	for (int i = 1; i < count.size(); i++)
//		count[i] += count[i - 1];
//
//	for (int i = arr.size() - 1; i >= 0; i--)
//	{
//		arr[count[temp[i][d] - 'A'] - 1] = temp[i];
//		count[temp[i][d] - 'A']--;
//
//		cout << "Count: ";
//		Print(count);
//
//		cout << "Output: ";
//		Print(arr);
//	}
//}
//
//void RadixSort(vector<string>& arr)
//{
//	int k = 'Z' - 'A';
//	// 아래 CountingSort()에서 사용할 가장 작은 인덱스(arr에서 가장 작은 값)은 0
//	// 가장 큰 인덱스(arr에서 가장 큰 값)이 k
//	// 비교: 알파벳 개수는 'Z' - 'A' + 1
//
//	int m = 3; // 전부 3글자라고 가정
//
//	for (int d = m - 1; d >= 0; d--)
//	{
//		cout << "Digit = " << d << endl;
//		CountingSort(arr, k, d);
//	}
//}

int main()
{
	// CLRS 8.3-1
	vector<string> arr = { "COW", "DOG", "SEA", "RUG",
		"ROW", "MOB", "BOX", "TAB", "BAR", "EAR", "TAR",
		"DIG", "BIG", "TEA", "NOW", "FOX" };

	Print(arr);

	RadixSort(arr);

	Print(arr);

	return 0;
}