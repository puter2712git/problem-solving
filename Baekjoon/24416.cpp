#include <iostream>

using namespace std;

int n;
int recursion_count;
int dynamic_count;

int fibonacci_recursion(int num)
{
	if (num == 1 || num == 2) {
		recursion_count++;
		return 1;
	}

	return fibonacci_recursion(num - 1) + fibonacci_recursion(num - 2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n;

	fibonacci_recursion(n);
	dynamic_count = n < 3 ? 1 : n - 2;

	cout << recursion_count << " " << dynamic_count << "\n";
	
	return 0;
}