#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Student {
    string name;
    int day;
    int month;
    int year;

    bool operator<(const Student& s) const
    {
        if (year != s.year) {
            return year > s.year;
        }

        if (month != s.month) {
            return month > s.month;
        }

        return day > s.day;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int studentCount;
    vector<Student> students;

    cin >> studentCount;
    for (int i = 0; i < studentCount; i++) {
        string name;
        int day, month, year;

        cin >> name >> day >> month >> year;

        students.push_back({
            name,
            day,
            month,
            year,
        });
    }

    sort(students.begin(), students.end(), less<Student>());

    cout << students.front().name << "\n";
    cout << students.back().name << "\n";

    return 0;
}