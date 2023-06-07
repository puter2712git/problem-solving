#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

int get_included_count(vector<string> &target, map<string, int> &check)
{
	int ret = 0;

	for (int i = 0; i < target.size(); i++) {
		if (check.find(target[i]) != check.end()) {
			ret++;
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	vector<string> strs;
	map<string, int> S;

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		S.insert({ str, 0 });
	}
	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;
		strs.push_back(str);
	}

	cout << get_included_count(strs, S) << "\n";

	return 0;
}