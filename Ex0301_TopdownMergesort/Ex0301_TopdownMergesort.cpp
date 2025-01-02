#include <vector>
#include <iostream>
#include <iomanip> // setfill(), setw()
#include <numeric> // iota

using namespace std;

void Print(vector<int>& arr, int lo, int hi)
{
	// setfill(), setw()는 줄맞춤에 사용

	for (int i = 0; i < lo; i++)
		cout << "   ";
	for (int i = lo; i <= hi; i++)
		cout << setfill(' ') << setw(3) << arr[i];
	cout << endl;
}

bool CheckSorted(vector<int>& a)
{
	for (int i = 0; i < a.size() - 1; i++)
	{
		if (a[i] > a[i + 1])
			return false;
	}

	return true;
}

// Sedgewick p. 273
class TopDownMerge
{
public:
	void Sort(vector<int>& a)
	{
		count = 0; // 분석용
		aux.resize(a.size());

		SortHelper(a, 0, a.size() - 1);
	}

private:
	void Merge(vector<int>& a, int lo, int mid, int hi)
	{
		cout << "Before: ";
		Print(a, lo, hi);

		int i = lo, j = mid + 1;

		if (a[mid] <= a[j]) // 병합(Merge) - 최선의 경우 // 이미 정렬이 된 상태라는 것을 상수 시간 O(1)으로 판단할 수 있다.
			return;

		for (int k = lo; k <= hi; k++)
			aux[k] = a[k];

		for (int k = lo; k <= hi; k++) // 병합(Merge) - 일반적인 경우 // O(n)
		{
			if (i > mid) a[k] = aux[j++];
			else if (j > hi) a[k] = aux[i++];
			else if (aux[j] < aux[i]) a[k] = aux[j++];
			else a[k] = aux[i++];
		}
		// for문의 루프변수 k 관점에서 n 개를 "복사해온다"라고 생각하면 더 직관적으로 이해할 수 있다.
		// 이미 정렬이 되어 있는 상태이기 때문에 그 다음으로 가장 작은 값을 찾을 때는 상수 시간으로 빠르게 찾을 수 있다.
		// k 위치로 복사해 넣는 작업을 n번 하는데 i하고 j가 이동하는 것은 상수 시간이기 때문에 결과적으로 O(n)으로 분석할 수 있다.

		cout << "After : ";
		Print(a, lo, hi);

		//count += hi - lo + 1;
		//cout << "Count : " << hi - lo + 1 << ", " << count << endl; // 누적 카운트 (디버깅용)
	}

	void SortHelper(vector<int>& a, int lo, int hi)
	{
		if (hi <= lo) return;

		int mid = lo + (hi - lo) / 2;

		//TODO:
		SortHelper(a, lo, mid);
		//TODO:
		SortHelper(a, mid + 1, hi);
		// 단순히 쪼개기만 한다고 해서 좋아지는 것은 아니다. 쪼개는 작업때문에 오히려 여러가지 오버헤드가 추가된다. 
		// 배열의 영역을 반반씩 나눠서 재귀호출을 하는 것이 절대 공짜는 아니다.
		// 바꿔말하면 이정도 오버헤더는 아깝지 않을 정도로 더 빠르게 해줄 수 있는 뭔가가 있어야 한다는 의미이다. 
		// 병합정렬의 특별한 점은 합치는 과정에서 찾을 수 있다.

		Merge(a, lo, mid, hi);
	}

	// 재귀트리 분석

	// 일반적인 경우 - O(n * log(n))
	// 각 레벨의 시간 복잡도는 O(n)이다.
	// 이런 레벨들이 전부 log(n) + 1 개가 있기 때문에 병합정렬 전체의 시간 복잡도는 O(n * log(n))으로 분석할 수 있다.

	// 최선의 경우 - Theta(n)
	// 일반적인 경우와 비교했을 때 최선의 경우에는 각 문제의 크기가 모두 상수가 되어버린다는 것이 가장 큰 차이이다.
	// 각 레벨의 연산량은 문제의 개수에 비례하는 구조이기 때문에 전체 복잡도를 구하기 위해서는 "2의 거듭제곱들의 합" 공식을 적용하면 된다.
	// 인터넷을 찾아보면 병합정렬이 최선의 경우에도 nlogn 이라고 분석해놓은 것들을 볼 수 있다. 이것은 구현 방식에 따른 차이이다.
	// 최선의 경우를 특별하게 처리하는 부분이 없는 경우에는 최선의 경우를 포함한 모든 경우에 대해 Theta(nlogn)으로 분석할 수 있다.

	vector<int> aux; // 추가 메모리 필요
	int count = 0;   // 연산 횟수 세보기용
};

int main()
{
	vector<int> my_vector(16);
	std::iota(my_vector.begin(), my_vector.end(), 0);
	std::reverse(my_vector.begin(), my_vector.end());

	cout << "        ";
	Print(my_vector, 0, my_vector.size() - 1);

	TopDownMerge merge;
	merge.Sort(my_vector);

	cout << "        ";
	Print(my_vector, 0, my_vector.size() - 1);
}
