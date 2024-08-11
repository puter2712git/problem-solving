#include <iostream>

using namespace std;

string mbti;
int N;
int answer;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> mbti;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string tmp;
		cin >> tmp;

		if (mbti == tmp)
			answer++;
	}

	cout << answer << "\n";

	return 0;
}