#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> countList;

void FillUp()
{
	countList = vector<int>(n + 1);
	countList[1] = 1;

	for (int i = 2; i <= n; i++) {
		countList[i] = countList[i - 1] + 1;

		for (int j = 1; j * j <= i; j++) {
			countList[i] = min(countList[i], countList[i - j * j] + 1);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	FillUp();

	cout << countList[n] << "\n";

	return 0;
}