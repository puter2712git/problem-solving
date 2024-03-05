#include <deque>
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int cardCount;
    deque<int> cards;
    vector<int> trashedCards;

    cin >> cardCount;
    for (int i = 1; i <= cardCount; i++) {
        cards.push_back(i);
    }

    bool isTrashing = true;
    while (cards.size()) {
        if (isTrashing) {
            trashedCards.push_back(cards.front());
            cards.pop_front();
        } else {
            cards.push_back(cards.front());
            cards.pop_front();
        }

        isTrashing = !isTrashing;
    }

    for (int i = 0; i < cardCount; i++) {
        cout << trashedCards[i] << " ";
    }
    cout << "\n";

    return 0;
}