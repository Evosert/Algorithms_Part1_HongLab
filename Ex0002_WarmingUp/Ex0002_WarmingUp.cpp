#include <iostream>
#include <string>
using namespace std;

int main()
{
	// 문제 1. 10진수 -> 2진수
	{
		int decimal = 105;
		string binary;

		//TODO:
		while (decimal > 0)
		{
			int i = decimal % 2;
			auto s = string(1, '0');
			s[0] = s[0] + i;
			binary.insert(0, s);
			decimal = decimal / 2;
		}

		// 정답
		/*while (decimal > 0)
		{
			int r = decimal % 2;
			binary = string(1, r + '0') + binary;
			decimal /= 2;
		}*/

		cout << binary << endl; // 1101001
	}

	// 문제 2. 문자열 뒤집기
	{
		string input = "Hello, World!";

		// TODO:

		cout << input << endl; // !dlroW ,olleH
	}

	// 문제 3. 모든 자리 다 더하기
	{
		string n = "789789";

		// TODO:

		cout << n << endl;
	}

	return 0;
}
