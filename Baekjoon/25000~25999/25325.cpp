#include <algorithm>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int n;

vector<string> Split(string &str, char delimeter)
{
	istringstream iss(str);
	string buffer;

	vector<string> ret;

	while (getline(iss, buffer, delimeter)) {
		ret.push_back(buffer);
	}

	return ret;
}

bool Compare(const pair<string, int> &a, const pair<string, int> &b)
{
	if (a.second != b.second)
		return a.second > b.second;
	return a.first < b.first;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	map<string, int> friendMap;

	cin >> n;

	for (int i = 0; i < n; i++) {
		string student;
		cin >> student;

		friendMap[student] = 0;
	}

	cin.ignore();

	for (int i = 0; i < n; i++) {
		string studentList;
		getline(cin, studentList);

		vector<string> students = Split(studentList, ' ');

		for (string &student : students) {
			friendMap[student]++;
		}
	}

	vector<pair<string, int>> friends(friendMap.begin(), friendMap.end());
	sort(friends.begin(), friends.end(), Compare);

	for (int i = 0; i < friends.size(); i++) {
		cout << friends[i].first << " " << friends[i].second << "\n";
	}

	return 0;
}