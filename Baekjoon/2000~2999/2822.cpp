#include <algorithm>
#include <iostream>

using namespace std;

struct Participant {
    int index;
    int score;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    Participant participants[8];
    for (int i = 0; i < 8; i++) {
        int tmp;
        cin >> tmp;
        participants[i] = {
            i + 1,
            tmp,
        };
    }

    sort(participants, participants + 8, [](Participant p1, Participant p2) -> bool {
        return p1.score > p2.score;
    });
    sort(participants, participants + 5, [](Participant p1, Participant p2) -> bool {
        return p1.index < p2.index;
    });

    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += participants[i].score;
    }

    cout << sum << "\n";
    for (int i = 0; i < 5; i++) {
        cout << participants[i].index << " ";
    }
    cout << "\n";

    return 0;
}