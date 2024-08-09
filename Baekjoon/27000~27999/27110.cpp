#include <iostream>

using namespace std;

int N;
int A, B, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> A >> B >> C;

	cout << min(N, A) + min(N, B) + min(N, C) << "\n";

	return 0;
}