#include <string>
#include <vector>
#include <iostream>

using namespace std;

string Add(string str1, string str2)
{
	// TODO:
	int size = 0;
	int gap = 0;
	int carry = 0;

	str1.size() > str2.size() ? size = str1.size() : size = str2.size();
	str1.size() > str2.size() ? gap = str1.size() - str2.size() : gap = str2.size() - str1.size();
	string str3 = string(size, '0');
	string zero = string(gap, '0');

	str2.insert(0, zero);

	for (int i = size; i != 0; i--)
	{
		int temp = (str1[i - 1] - '0') + (str2[i - 1] - '0');
		if (carry == 1)
		{
			if (temp + 1 >= 10)
			{
				carry = 1;
				str3[i - 1] = (temp + 1) % 10 + '0';
			}
			else
			{
				carry = 0;
				str3[i - 1] = (temp + 1) + '0';
			}
		}
		else
		{
			if (temp >= 10)
			{
				carry = 1;
				str3[i - 1] = temp % 10 + '0';
			}
			else
			{
				carry = 0;
				str3[i - 1] = temp + '0';
			}
		}
	}

	if (carry == 1)
	{
		str3.insert(0, "1");
	}

	return str3;
}

int main()
{
	vector<vector<string>> tests = {
		{"12", "34", to_string(12 + 34)}
		, {"123", "45", to_string(123 + 45)}
		, {"54544", "44545", to_string(54544 + 44545)}
		, {"5555", "55", to_string(5555 + 55)}
		, {"5555", "5555", to_string(5555 + 5555)}
		, {"9823471235421415454545454545454544", "1714546546546545454544548544544545", "11538017781967960909090003089999089"}
	};

	for (const auto& t : tests)
	{
		const string str1 = t[0];     // "12"
		const string str2 = t[1];     // "34"
		const string expected = t[2]; // "46"

		cout << str1 << " + " << str2 << " = " << expected << endl;

		const string result = Add(str1, str2);

		cout << result << " " << expected << " ";

		if (result == expected)
			cout << "OK" << endl;
		else {
			cout << "Not OK" << endl;
			exit(-1);
		}
		cout << endl << endl;
	}

	cout << "Congratulations. All OK!" << endl;

	return 0;
}
