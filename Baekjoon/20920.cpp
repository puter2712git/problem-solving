#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(string a, string b, map<string, int> &dict)
{
	if (a.length() == b.length() && dict[a] == dict[b]) return a < b;
	if (dict[a] == dict[b]) return a.length() > b.length();
	return dict[a] > dict[b];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;
	vector<string> words;
	map<string, int> dictionary;

	cin >> N >> M;
	cin.ignore();

	for (int i = 0; i < N; i++) {
		string word;
		cin >> word;

		if (word.length() < M) continue;

		if (dictionary.find(word) == dictionary.end()) {
			words.push_back(word);
			dictionary.insert({ word, 1 });
			continue;
		}

		dictionary[word]++;
	}

	sort(words.begin(), words.end(), [&dictionary](const string &a, const string &b) {
		return compare(a, b, dictionary);
	});

	for (const string &word : words) {
		cout << word << '\n';
	}

	return 0;
}