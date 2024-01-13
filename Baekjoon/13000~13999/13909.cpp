#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	int count = 0;

	cin >> N;

	for (int i = 1; i * i <= N; i++) {
		count++;
	}

	cout << count << "\n";

	return 0;
}