#include <iostream>
#include <vector>

using namespace std;

vector<int> get_fibonacci_vector(int range)
{
    vector<int> ret;

    ret.push_back(0);
    ret.push_back(1);

    for (int i = 2; i <= range; i++) {
        ret.push_back(((ret[i - 1] % 1000000007) + (ret[i - 2] % 1000000007)) % 1000000007);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n;

    cin >> n;
    vector<int> fibonacci = get_fibonacci_vector(n);

    cout << fibonacci[n] << "\n";

    return 0;
}