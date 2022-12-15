#include <cstdio>

using namespace std;


/* 기존 값이 변형되면 안되므로 call by value */
int get_sum_of_digits(int _num)
{
	int sum = _num;

	/* @_num이 일의 자리가 될 때까지 반복 */
	while (_num >= 10) {
		/* @_num의 최하위 숫자 @sum에 더하기 */
		sum += (_num % 10);
		/* @_num의 최하위 숫자 없애기 */
		_num /= 10;
	}
	sum += _num;

	return sum;
}


int find_min_constructor(int &_num)
{
	for (int i = 1; i <= _num; i++) {
		if (_num == get_sum_of_digits(i)) {
			return i;
		}
	}
	
	return 0;
}


int main()
{
	int num;
	scanf("%d", &num);

	printf("%d\n", find_min_constructor(num));

	return 0;
}