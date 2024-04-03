#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int guitarStringLength;
    int brandLength;

    int minPackagePrice = 123456789;
    int minStringPrice = 123456789;

    cin >> guitarStringLength >> brandLength;
    for (int i = 0; i < brandLength; i++) {
        int packagePrice;
        int stringPrice;

        cin >> packagePrice >> stringPrice;

        if (minPackagePrice > packagePrice) {
            minPackagePrice = packagePrice;
        }

        if (minStringPrice > stringPrice) {
            minStringPrice = stringPrice;
        }
    }

    int money = 0;

    if (minPackagePrice < minStringPrice * 6) {
        while (guitarStringLength >= 6) {
            guitarStringLength -= 6;
            money += minPackagePrice;
        }

        if (minPackagePrice < guitarStringLength * minStringPrice) {
            money += minPackagePrice;
        } else {
            money += guitarStringLength * minStringPrice;
        }
    } else {
        money += guitarStringLength * minStringPrice;
    }

    cout << money << "\n";

    return 0;
}