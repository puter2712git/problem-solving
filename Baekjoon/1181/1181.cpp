#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


// 두 문자열의 길이 우선 비교, 길이가 같다면 사전순
bool compare(string s1, string s2) {
  if (s1.length() != s2.length()) {
    return s1.length() < s2.length();
  }
  else {
    return s1 < s2;
  }
}


int main() {
  int wordCount = 0;
  cin >> wordCount;

  vector<string> words(wordCount);
  for (int i = 0; i < wordCount; i++) {
    cin >> words[i];
  }

  // algorithm 라이브러리의 sort() 이용
  sort(words.begin(), words.end(), compare);

  // 문자열들 중 중복되는 것 제거
  words.erase(unique(words.begin(), words.end()), words.end());

  for (int i = 0; i < words.size(); i++) {
    cout << words[i] << endl;
  }

  return 0;
}