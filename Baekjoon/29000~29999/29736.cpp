#include <iostream>

using namespace std;

int A, B;
int K, X;
int friendCount;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> A >> B;
	cin >> K >> X;

	for (int i = K - X; i <= K + X; i++) {
		if (i >= A && i <= B) {
			friendCount++;
		}
	}

	if (friendCount == 0)
		cout << "IMPOSSIBLE\n";
	else
		cout << friendCount << "\n";

	return 0;
}