#include <iostream>
#include <stack>

using namespace std;

string str;

int Calculate()
{
	int ret = 0;
	int tmp = 1;
	stack<char> s;

	for (int i = 0; i < str.length(); i++) {
		char curr = str[i];

		if (curr == '(' || curr == '[') {
			s.push(curr);

			if (curr == '(') {
				tmp *= 2;
			} else {
				tmp *= 3;
			}
		} else {
			if (curr == ')') {
				if (s.empty() || s.top() != '(') {
					return 0;
				}

				if (str[i - 1] == '(') {
					ret += tmp;
				}
				tmp /= 2;
				s.pop();
			} else {
				if (s.empty() || s.top() != '[') {
					return 0;
				}

				if (str[i - 1] == '[') {
					ret += tmp;
				}
				tmp /= 3;
				s.pop();
			}
		}
	}

	if (!s.empty())
		return 0;

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> str;
	cout << Calculate() << "\n";

	return 0;
}