#include <iostream>
#include <map>

using namespace std;

const int SUBJECT_COUNT = 20;

map<string, float> score_map = {
    { "A+", 4.5 },
    { "A0", 4.0 },
    { "B+", 3.5 },
    { "B0", 3.0 },
    { "C+", 2.5 },
    { "C0", 2.0 },
    { "D+", 1.5 },
    { "D0", 1.0 },
    { "F" , 0.0 },
};

string subj;
float credit;
string score;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    float credit_sum = 0;
    float score_sum = 0;

    for (int i = 0; i < SUBJECT_COUNT; i++) {
        cin >> subj >> credit >> score;

        if (score == "P") continue;

        credit_sum += credit;
        score_sum += score_map[score] * credit;
    }

    cout << score_sum / credit_sum << "\n";

    return 0;
}