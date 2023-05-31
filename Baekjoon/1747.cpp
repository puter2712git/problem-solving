#include <iostream>
#include <string>

using namespace std;

bool is_pallindrome(int num)
{
    string num_str = to_string(num);
    int len = num_str.length();

    bool ret = true;

    for (int i = 0; i < len / 2; i++) {
        if (num_str[i] != num_str[len - i - 1]) {
            ret = false;
            break;
        }
    }

    return ret;
}

bool is_prime(int num)
{
    if (num == 1) return false;

    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;
    cin >> N;

    while (!(is_pallindrome(N) && is_prime(N))) {
        N++;
    }

    cout << N << "\n";

    return 0;
}