#include <iostream>

using namespace std;

int N;
string S;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> S;

	cout << S.substr(N - 5) << "\n";

	return 0;
}