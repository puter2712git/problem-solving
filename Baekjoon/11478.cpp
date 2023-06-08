#include <iostream>
#include <string>
#include <map>

using namespace std;

void insert_sub_strs(string &str, map<string, int> &out)
{
	int len = str.length();

	for (int i = 0; i < len; i++) {
		for (int j = 1; j < len - i + 1; j++) {
			out.insert({ str.substr(i, j), 0 });
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string S;
	map<string, int> sub_strs;

	cin >> S;

	insert_sub_strs(S, sub_strs);

	cout << sub_strs.size() << "\n";

	return 0;
}