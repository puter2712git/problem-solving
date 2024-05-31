#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Score
{
	int paperRank;
	int talkRank;

	bool operator<(const Score &s) { return paperRank < s.paperRank; }
};

int T;
int N;
vector<Score> scores;

int GetPassCount()
{
	int ret = 1;
	int curr = scores[0].talkRank;

	for (int i = 1; i < N; i++) {
		if (scores[i].talkRank < curr) {
			curr = scores[i].talkRank;
			ret++;
		}
	}

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> T;
	while (T--) {
		cin >> N;
		scores = vector<Score>(N, Score{ 0, 0 });

		for (int i = 0; i < N; i++) {
			cin >> scores[i].paperRank >> scores[i].talkRank;
		}
		sort(scores.begin(), scores.end());

		cout << GetPassCount() << "\n";
	}

	return 0;
}