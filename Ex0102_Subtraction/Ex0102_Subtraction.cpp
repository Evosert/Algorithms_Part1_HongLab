#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 항상 큰 수에서 작은 수를 빼는 경우(결과가 음수가 되지 않는 경우)를 가정
string Subtract(string str1, string str2)
{
	// 둘이 같을 경우 바로 "0" 반환
	if (str1 == str2)
		return "0"; // '0'은 char, "0"은 string

	int N = max(str1.size(), str2.size());
	str1 = string(N - str1.size(), '0') + str1; // 문자열끼리의 더하기도 가능
	str2 = string(N - str2.size(), '0') + str2;

	string result(N, '0');

	// TODO: 더하기와 거의 비슷합니다.
	int carry = 0;
	for (int i = N - 1; i >= 0; i--)
	{
		int n1 = str1[i] - '0';
		int n2 = str2[i] - '0';

		int sub = 0;

		if (n1 - n2 + carry >= 0)
		{
			sub = n1 - n2 + carry;
			carry = 0;
		}
		else
		{
			sub = n1 + 10 - n2 + carry;
			carry = -1;
		}
		result[i] = sub + '0';
	}

	// 불필요한 '0' 제거 (예: "078" -> "78")
	// TODO:
	int count = 0;
	for (string::iterator i = result.begin(); *i == '0'; i++)
	{
		count++;
	}
	result = result.substr(count, N - count);

	return result;
}

// 정답:
//string Subtract(string str1, string str2)
//{
//	// 같을 경우 바로 0 반환
//	if (str1 == str2)
//		return "0"; // '0'은 char, "0"은 string
//
//	int N = max(str1.size(), str2.size());
//	str1 = string(N - str1.size(), '0') + str1; // 문자열끼리의 더하기도 가능
//	str2 = string(N - str2.size(), '0') + str2;
//
//	string result(N, '0');
//	int carry = 0;
//	for (int i = N - 1; i >= 0; i--) // 역순
//	{
//		int n1 = str1[i] - '0';
//		int n2 = str2[i] - '0';
//
//		int sum = n1 - n2 + carry + 10; // 다음 자리에서 10을 미리 빌려옴
//		carry = sum / 10 - 1; // 미리 빌렸던 10을 -1로 반영
//		result[i] = char(sum % 10 + '0');
//
//		cout << n1 << " " << n2 << " " << carry << " " << result << endl;
//	}
//
//	// 불필요한 '0' 제거 (예: "078" -> "78")
//	int i = 0;
//	while (result[i] == '0') i += 1;
//	result = result.substr(i, N - i);
//
//	return result;
//}

int main()
{
	// 항상 큰 수에서 작은 수를 빼는 경우(결과가 음수가 되지 않는 경우)를 가정
	vector<vector<string>> tests = {
		{"34", "12", std::to_string(34 - 12)}
		, {"123", "45", std::to_string(123 - 45)}
		, {"54544", "44545", std::to_string(54544 - 44545)}
		, {"5555", "55", std::to_string(5555 - 55)}
		, {"5555", "5555", std::to_string(5555 - 5555)}
		, {"9823471235421415454545454545454544", "1714546546546545454544548544544545", "8108924688874870000000906000909999"}
	};

	for (const auto& t : tests)
	{
		const string str1 = t[0];
		const string str2 = t[1];
		const string expected = t[2];

		cout << str1 << " - " << str2 << " = " << expected << endl;

		const string result = Subtract(str1, str2);

		cout << result << " " << expected << " ";

		if (result == expected)
			cout << "OK";
		else {
			cout << "Not OK";
			exit(-1);
		}
		cout << endl << endl;
	}

	cout << "Congratulations. All OK!" << endl;

	return 0;
}
