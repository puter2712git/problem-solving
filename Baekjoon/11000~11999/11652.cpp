#include <iostream>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cardLength;
    map<long long, int> cardMap;
    long long maxCard = 0;
    int maxLength = 0;

    cin >> cardLength;

    for (int i = 0; i < cardLength; i++)
    {
        long long card;
        cin >> card;

        if (cardMap.find(card) == cardMap.end())
        {
            cardMap.insert({card, 1});
            if (maxLength < 1)
            {
                maxCard = card;
                maxLength = 1;
            }
            else if (maxLength == 1 && maxCard > card)
            {
                maxCard = card;
            }
        }
        else
        {
            cardMap[card]++;
            if (maxLength < cardMap[card])
            {
                maxCard = card;
                maxLength = cardMap[card];
            }
            else if (maxLength == cardMap[card] && maxCard > card)
            {
                maxCard = card;
            }
        }
    }

    cout << maxCard << "\n";

    return 0;
}