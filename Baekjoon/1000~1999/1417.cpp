#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int candidateCount;
    int targetVote;
    priority_queue<int> candidateVotes;

    int count = 0;

    cin >> candidateCount;
    cin >> targetVote;
    for (int i = 0; i < candidateCount - 1; i++) {
        int tmp;
        cin >> tmp;
        candidateVotes.push(tmp);
    }

    while (candidateVotes.size() > 0 && targetVote <= candidateVotes.top()) {
        targetVote++;

        int vote = candidateVotes.top();
        candidateVotes.pop();
        vote--;
        candidateVotes.push(vote);

        count++;
    }

    cout << count << "\n";

    return 0;
}