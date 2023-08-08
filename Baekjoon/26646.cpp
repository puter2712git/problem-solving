#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int getPrice(int a, int b)
{
	int width = a + b;
	int height = abs(a - b);

	int ret = pow(width, 2) + pow(height, 2);

	return ret;
}

int main()
{
	int N;
	vector<int> H;
	int answer = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		int height;
		cin >> height;
		H.push_back(height);
	}

	for (int i = 0; i < N - 1; i++) {
		answer += getPrice(H[i], H[i + 1]);
	}

	cout << answer << '\n';

	return 0;
}