#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;

void Print(vector<int>& arr, int lo, int hi, string sep = "")
{
	//cout << "Index: ";
	//for (int i = 0; i < arr.size(); i++)
	//	cout << setfill(' ') << setw(3) << i;
	//cout << endl;

	cout << "Value: ";
	for (int i = 0; i < arr.size(); i++) {

		if (lo <= i && i <= hi)
			cout << setfill(' ') << setw(3) << arr[i] << sep;
		else
			cout << "   ";
	}
	cout << endl;
}

// Quicksort with 3-way partitioning, Sedgewick p299
// (Dijkstra's Dutch national flag problem)
void Quick3way(vector<int>& arr, int lo, int hi)
{
	if (hi <= lo) return;

	int lt = lo, i = lo + 1, gt = hi;
	int key = arr[lo];

	cout << "Key = " << key << endl;

	while (i <= gt)
	{
		// TODO:
		if (arr[i] < key)
		{
			swap(arr[lt++], arr[i]);
		}
		else if (arr[i] > key)
		{
			while (true)
			{
				if (arr[gt] > key)
				{
					gt--;
				}
				else if (arr[gt] < key)
				{
					swap(arr[i], arr[gt--]);
					swap(arr[lt++], arr[i]);
					break;
				}
				else if (arr[gt] == key)
				{
					swap(arr[i], arr[gt--]);
					break;
				}
			}
		}
		i++;
	}

	Print(arr, lo, hi);

	Quick3way(arr, lo, lt - 1);
	Quick3way(arr, gt + 1, hi);
}

//정답: 
//void Quick3way(vector<int>& arr, int lo, int hi)
//{
//	if (hi <= lo) return;
//
//	int lt = lo, i = lo + 1, gt = hi;
//	int key = arr[lo];
//
//	cout << "Key = " << key << endl;
//
//	while (i <= gt)
//	{
//		if (arr[i] < key) {
//			swap(arr[lt], arr[i]);
//			lt += 1;
//			i += 1;
//		}
//		else if (arr[i] > key) {
//			swap(arr[i], arr[gt]);
//			gt -= 1;
//		}
//		else i += 1;
//	}
//
//	Print(arr, lo, hi);
//
//	Quick3way(arr, lo, lt - 1);
//	Quick3way(arr, gt + 1, hi);
//}

int main()
{
	srand(0);

	vector<int> arr = { 3, 2, 3, 4, 5, 1, 2, 3, 4, 5, 1, 2, 3, 2, 3, 4, 5, 1, 3, 5 };

	Print(arr, 0, arr.size() - 1);

	Quick3way(arr, 0, arr.size() - 1);

	Print(arr, 0, arr.size() - 1);

	return 0;
}
