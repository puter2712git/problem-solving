#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(int a, int b)
{
    return a > b;
}

vector<int> custom_sort(int num)
{
    string num_str = to_string(num);
    int len = num_str.length();

    vector<int> nums;
    for (int i = 0; i < len; i++)
    {
        nums.push_back(num_str[i] - '0');
    }

    sort(nums.begin(), nums.end(), compare);

    return nums;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N;

    cin >> N;

    vector<int> sorted = custom_sort(N);

    for (int i = 0; i < sorted.size(); i++)
    {
        cout << sorted[i];
    }
    cout << "\n";

    return 0;
}