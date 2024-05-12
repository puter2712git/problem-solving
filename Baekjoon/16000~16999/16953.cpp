#include <iostream>

using namespace std;

long long A, B;
int convertCount = -1;

void Convert(long long curr, int cnt)
{
	if (curr == B) {
		convertCount = cnt + 1;
		return;
	}

	if (curr > B || curr < 0)
		return;

	Convert(curr * 2, cnt + 1);
	Convert(curr * 10 + 1, cnt + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> A >> B;

	Convert(A, 0);

	cout << convertCount << "\n";

	return 0;
}