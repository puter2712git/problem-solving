#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

bool is_prime(int num)
{
    if (num == 1) return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int M, N;
    vector<int> prime_nums;

    cin >> M;
    cin >> N;

    for (int i = M; i <= N; i++)
    {
        if (is_prime(i))
        {
            prime_nums.push_back(i);
        }
    }

    if (prime_nums.empty())
    {
        cout << "-1" << "\n";
        return 0;
    }

    cout << accumulate(prime_nums.begin(), prime_nums.end(), 0) << "\n";
    cout << *min_element(prime_nums.begin(), prime_nums.end()) << "\n";

    return 0;
}