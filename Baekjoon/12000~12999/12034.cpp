#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int testcase_count;
    cin >> testcase_count;

    for (int i = 0; i < testcase_count; i++) {
        int product_count;
        queue<long long> origin_prices;
        vector<long long> discount_prices;

        cin >> product_count;
        for (int j = 0; j < product_count * 2; j++) {
            long long price;
            cin >> price;

            if (origin_prices.size() > 0 && origin_prices.front() == price) {
                origin_prices.pop();
            } else {
                discount_prices.push_back(price);
                origin_prices.push(price * 4 / 3);
            }
        }

        cout << "Case #" << i + 1 << ": ";
        for (long long price : discount_prices) {
            cout << price << " ";
        }
        cout << "\n";
    }

    return 0;
}