#include <iostream>

using namespace std;

int coin_type_count;
int price;
int coins[10];

int get_needed_coins_count()
{
    int ret = 0;

    for (int i = coin_type_count - 1; i >= 0; i--) {
        if (price < coins[i]) continue;

        ret += price / coins[i];
        price %= coins[i];

        if (price == 0) break;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> coin_type_count >> price;
    for (int i = 0; i < coin_type_count; i++) {
        cin >> coins[i];
    }

    cout << get_needed_coins_count() << '\n';

    return 0;
}