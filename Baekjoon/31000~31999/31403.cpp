#include <iostream>
#include <string>

using namespace std;

int A, B, C;

int GetJSSum()
{
	string a = to_string(A);
	string b = to_string(B);

	int ab = stoi(a + b);
	return ab - C;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> A;
	cin >> B;
	cin >> C;

	cout << A + B - C << "\n";
	cout << GetJSSum() << "\n";

	return 0;
}