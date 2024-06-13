#include <iostream>

using namespace std;

int H, I, A, R, C;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> H >> I >> A >> R >> C;
	cout << H * I - A * R * C << "\n";

	return 0;
}