#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string convert_to_notation(int num, int notation)
{
    string ret;

    while (num)
    {
        int remain = num % notation;
        if (remain < 10)
        {
            ret += remain + '0';
        }
        else
        {
            ret += remain - 10 + 'A';
        }

        num /= notation;
    }

    reverse(ret.begin(), ret.end());

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, B;

    cin >> N >> B;

    cout << convert_to_notation(N, B) << "\n";

    return 0;
}