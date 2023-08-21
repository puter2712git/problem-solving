#include <iostream>
#include <cmath>

using namespace std;

void hanoi(int num, int src, int dest, int aux)
{
	if (num == 0) return;

	hanoi(num - 1, src, aux, dest);
	cout << src << " " << dest << "\n";
	hanoi(num - 1, aux, dest, src);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	int N;
	cin >> N;

	cout << (long long)pow(2, N) - 1 << "\n";
	hanoi(N, 1, 3, 2);

	return 0;
}