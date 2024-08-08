#include <iostream>

using namespace std;

int A, B;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> A >> B;
	cout << min(A / 2, B) << "\n";

	return 0;
}