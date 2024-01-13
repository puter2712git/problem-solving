#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>

#define MAX_NAME_LENGTH 101

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
  return a.first < b.first;
}

int main()
{
  int nr_member;
  vector<pair<int, string>> members;

  scanf("%d", &nr_member);

  for (int i = 0; i < nr_member; i++) {
    int age;
    char name[MAX_NAME_LENGTH];

    scanf("%d %s", &age, name);

    members.push_back({age, name});
  }

  stable_sort(members.begin(), members.end(), compare);

  for (int i = 0; i < nr_member; i++) {
    printf("%d %s\n", members[i].first, members[i].second.c_str());
  }

  return 0;
}