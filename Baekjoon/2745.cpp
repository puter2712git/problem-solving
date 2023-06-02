#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

int convert_to_decimal(string &num, int notation)
{
    int ret = 0;
    reverse(num.begin(), num.end());
    int len = num.length();

    for (int i = 0; i < len; i++)
    {
        int tmp;
        if (isdigit(num[i]))
        {
            tmp = num[i] - '0';
        }
        else
        {
            tmp = num[i] - 'A' + 10;
        }

        ret += tmp * pow(notation, i);
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    string N;
    int B;

    cin >> N >> B;

    cout << convert_to_decimal(N, B) << "\n";

    return 0;
}