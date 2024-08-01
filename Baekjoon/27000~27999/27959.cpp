#include <iostream>

using namespace std;

int N, M;

bool CanBuy() { return N * 100 >= M; }

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N >> M;

	if (CanBuy()) {
		cout << "Yes\n";
	} else {
		cout << "No\n";
	}

	return 0;
}