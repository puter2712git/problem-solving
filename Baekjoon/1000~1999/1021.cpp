#include <iostream>
#include <deque>

using namespace std;

void ShiftLeft(deque<int> &deq)
{
    int element = deq.front();
    deq.pop_front();
    deq.push_back(element);
}

void ShiftRight(deque<int> &deq)
{
    int element = deq.back();
    deq.pop_back();
    deq.push_front(element);
}

int GetMinShiftCount(deque<int> &deq, int target)
{
    int count = 0;
    int element = deq.front();
    int deqSize = deq.size();

    // Get count when shift it to left direction.
    while (element != target)
    {
        ShiftLeft(deq);
        count++;
        element = deq.front();
    }

    if (count > deqSize / 2)
    {
        count = deqSize - count;
    }

    deq.pop_front();

    return count;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    deque<int> deq;
    int queueSize;
    int numberLength;
    int count = 0;

    cin >> queueSize >> numberLength;

    for (int i = 0; i < queueSize; i++)
    {
        deq.push_back(i + 1);
    }

    for (int i = 0; i < numberLength; i++)
    {
        int number;
        cin >> number;
        count += GetMinShiftCount(deq, number);
    }

    cout << count << "\n";

    return 0;
}