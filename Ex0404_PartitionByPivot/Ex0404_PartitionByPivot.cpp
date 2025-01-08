#include <vector>
#include <iostream>
using namespace std;

void Print(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	vector<int> arr = { 5, 2, 7, 3, 8, 5, 6, 4 };
	//vector<int> arr = { 2, 8, 7, 1, 3, 5, 6, 4 };
	//vector<int> arr = { 9, 8, 7, 6, 4, 3, 2, 1, 5 };
	//vector<int> arr = { 5, 2, 7, 3, 4, 4, 6, 4 };

	int lo = 0;  // 첫 인덱스
	int hi = arr.size() - 1;  // 마지막 인덱스
	int x = arr[hi]; // 분할 기준으로 사용하는 pivot 4

	int i = lo - 1; // pivot보다 것들중 가장 큰 인덱스

	Print(arr);

	// TODO:
	for (int j = lo; j < hi; j++)
	{
		if (arr[j] <= x)
		{
			i += 1;
			swap(arr[i], arr[j]);
		}

		cout << "i = " << i << ", j = " << j << endl;
		Print(arr);
	}

	swap(arr[i + 1], arr[hi]);
	Print(arr);

	cout << i + 1 << endl; // 피벗 이하인 값들의 마지막 인덱스

	// 참고
	// 1. CLRS p.184 에서는 i를 -1에서 시작하는데, i = 0에서 시작하는 방식으로 구현하면 더하기를 줄일 수 있다.

	/*int i = lo;
	for (int j = lo; j < hi; j++)
		if (arr[j] <= x)
		{
			swap(arr[i], arr[j]);
			i += 1;
		}
	swap(arr[i], arr[hi]);
	cout << i << endl;*/

	// CLRS 교재에서는 1-based index를 사용한다는 점 주의.

	// 2. 스탠퍼드 CS161에서 제공하는 파이썬 구현에서는 분할된 리스트 두 개를 반환하는 방식으로 구현되어 있다.
	// 알고리듬의 개념을 이해할 때는 더 직관적일 수도 있는데, 실무에 쓰기에는 비효율적이다.
}
