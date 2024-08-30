#include <iostream>
#include <string>
#include <vector>

using namespace std;

string sentence;
vector<int> alphabets(26, 0);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	while (getline(cin, sentence)) {
		for (int i = 0; i < sentence.length(); i++) {
			if (sentence[i] == ' ')
				continue;

			alphabets[sentence[i] - 'a']++;
		}
	}

	string maxAlphabet = "";
	int maxCount = -1;

	for (int i = 0; i < alphabets.size(); i++) {
		if (alphabets[i] >= maxCount) {
			maxCount = alphabets[i];
		}
	}
	for (int i = 0; i < alphabets.size(); i++) {
		if (alphabets[i] == maxCount) {
			maxAlphabet.push_back(i + 'a');
		}
	}

	cout << maxAlphabet << "\n";

	return 0;
}