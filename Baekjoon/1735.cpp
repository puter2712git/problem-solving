#include <iostream>

using namespace std;

struct fraction {
	long long denominator;
	long long numerator;
};

struct fraction get_added_fraction(struct fraction &a, struct fraction &b)
{
	struct fraction ret;

	ret.denominator = a.denominator * b.denominator;
	ret.numerator = a.numerator * ret.denominator / a.denominator + b.numerator * ret.denominator / b.denominator;

	return ret;
}

long long get_GCD(long long a, long long b)
{
	if (a % b == 0) {
		return b;
	}

	return get_GCD(b, a % b);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	struct fraction a, b;

	cin >> a.numerator >> a.denominator;
	cin >> b.numerator >> b.denominator;

	struct fraction added = get_added_fraction(a, b);

	long long GCD = get_GCD(added.numerator, added.denominator);

	cout << added.numerator / GCD << " " << added.denominator / GCD << "\n";

	return 0;
}