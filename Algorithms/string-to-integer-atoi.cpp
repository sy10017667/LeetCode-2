// 8. String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/

/*
Implement atoi to convert a string to an integer.

Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.

Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.

Update (2015-02-10):
The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.

spoilers alert... click to show requirements for atoi.

Requirements for atoi:
The function first discards as many whitespace characters as necessary until the first non-whitespace character is found. Then, starting from this character, takes an optional initial plus or minus sign followed by as many numerical digits as possible, and interprets them as a numerical value.

The string can contain additional characters after those that form the integral number, which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters in str is not a valid integral number, or if no such sequence exists because either str is empty or it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned. If the correct value is out of the range of representable values, INT_MAX (2147483647) or INT_MIN (-2147483648) is returned.
*/

#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		long long a = 1, b = 0;
		int sz = str.size(), i = 0;
		while (i < sz and str[i] == ' ') {
			++i;
		}
		if (str[i] == '+' or str[i] == '-') {
			a = str[i] == '+' ? 1 : -1;
			++i;
		}
		while (i < sz and isdigit(str[i])) {
			b = 10 * b + str[i] - '0';
			if (a * b < INT_MIN) {
				return INT_MIN;
			}
			else if (a * b > INT_MAX) {
				return INT_MAX;
			}
			++i;
		}
		return a * b;
	}
};

int main(void) {
	Solution solution;
	string str;
	int result;

	str = "+-2";
	result = solution.myAtoi(str);
	cout << result << '\n';

	str = "1";
	result = solution.myAtoi(str);
	cout << result << '\n';

	str = "-1";
	result = solution.myAtoi(str);
	cout << result << '\n';

	return 0;
}