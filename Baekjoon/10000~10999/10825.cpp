#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Student {
    string name;
    int korScore;
    int engScore;
    int mathScore;

    bool operator<(const Student& s) const
    {
        if (korScore != s.korScore) {
            return korScore > s.korScore;
        }

        if (engScore != s.engScore) {
            return engScore < s.engScore;
        }

        if (mathScore != s.mathScore) {
            return mathScore > s.mathScore;
        }

        return name < s.name;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int studentLength;
    cin >> studentLength;

    vector<Student> students;

    for (int i = 0; i < studentLength; i++) {
        string name;
        int korScore;
        int engScore;
        int mathScore;

        cin >> name >> korScore >> engScore >> mathScore;
        students.push_back({
            name,
            korScore,
            engScore,
            mathScore,
        });
    }

    sort(students.begin(), students.end());

    for (int i = 0; i < studentLength; i++) {
        cout << students[i].name << "\n";
    }

    return 0;
}