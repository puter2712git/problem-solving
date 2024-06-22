#include <iostream>

using namespace std;

int N;
int S, M, L, XL, XXL, XXXL;
int T, P;

int GetCount(int target, int bundle)
{
	int ret = 0;

	ret += target / bundle;
	if (target % bundle != 0) {
		ret++;
	}

	return ret;
}

int GetTBundleCount()
{
	int ret = 0;

	ret += GetCount(S, T);
	ret += GetCount(M, T);
	ret += GetCount(L, T);
	ret += GetCount(XL, T);
	ret += GetCount(XXL, T);
	ret += GetCount(XXXL, T);

	return ret;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> N;
	cin >> S >> M >> L >> XL >> XXL >> XXXL;
	cin >> T >> P;

	cout << GetTBundleCount() << "\n";
	cout << N / P << " " << N % P << "\n";

	return 0;
}