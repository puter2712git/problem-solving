#include <iostream>

using namespace std;

long long sum_of_naturals(long long top_num)
{
    long long ret = 0;

    for (int i = 1; i <= top_num; i++)
    {
        ret += i;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    long long int n;
    
    cin >> n;

    cout << sum_of_naturals(n - 1) << "\n";
    cout << 2 << "\n";

    return 0;
}