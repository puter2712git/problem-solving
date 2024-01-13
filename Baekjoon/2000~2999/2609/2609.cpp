#include <cstdio>

using namespace std;


int get_GCD(int _num1, int _num2)
{
	int remainder = _num1 % _num2;

	if (!remainder) {
		return _num2;
	}
	
	return get_GCD(_num2, remainder);
}


int get_LCM(int _num1, int _num2, int _GCD)
{
	return _num1 / _GCD * _num2;
}


int main()
{
	int num1, num2;
	int GCD, LCM;
	scanf("%d %d", &num1, &num2);

	GCD = get_GCD(num1, num2);
	LCM = get_LCM(num1, num2, GCD);

	printf("%d\n", GCD);
	printf("%d\n", LCM);

	return 0;
}