#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int L, C;
vector<char> chars;

void PrintAllPasswords()
{
	vector<int> indices = vector<int>(C, 1);
	for (int i = 0; i < L; i++) {
		indices[i] = 0;
	}

	do {
		vector<char> selectedChars;
		int vowelCount = 0;
		for (int i = 0; i < C; i++) {
			if (indices[i] == 0) {
				selectedChars.push_back(chars[i]);
				if (chars[i] == 'a' || chars[i] == 'e' || chars[i] == 'i' || chars[i] == 'o' || chars[i] == 'u') {
					vowelCount++;
				}
			}
		}
		if (vowelCount > 0 && L - vowelCount > 1) {
			for (const auto &c : selectedChars) {
				cout << c;
			}
			cout << "\n";
		}
	} while (next_permutation(indices.begin(), indices.end()));
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> L >> C;
	chars = vector<char>(C);
	for (int i = 0; i < C; i++) {
		cin >> chars[i];
	}
	sort(chars.begin(), chars.end());

	PrintAllPasswords();

	return 0;
}