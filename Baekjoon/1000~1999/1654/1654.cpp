#include <iostream>
#include <vector>

using namespace std;

int main() {
  long long int haveLAN, needLAN;
  cin >> haveLAN >> needLAN;

  long long int maxLANLength = 0;

  vector<long long int> LANs(haveLAN);
  for (int i = 0; i < haveLAN; i++) {
    cin >> LANs[i];
    maxLANLength = max(maxLANLength, LANs[i]);
  }

  /**
   * Binary Search
   * 
   * @high : 랜선들 중 가장 긴 길이로 초기화
   * @low : 1로 초기화
   * @mid : @high와 @low의 중간값
   * @seperated : @mid로 랜선들을 나누었을 때 나오는 랜선의 개수
  */
  long long int high = maxLANLength;
  long long int low = 1;
  long long int mid;
  long long int seperated;
  long long int answer = 0;

  /* @low가 @high보다 커지는 순간 반복문 종료 */
  while (low <= high) {
    seperated = 0;
    mid = (high + low) / 2;

    for (int i = 0; i < haveLAN; i++) {
      seperated += LANs[i] / mid;
    }

    /* 잘려서 나온 랜선의 개수가 필요한 랜선의 개수보다 적은 경우 @high에 @mid - 1을 대입 */
    if (seperated < needLAN) {
      high = mid - 1;
    }
    /* 잘려서 나온 랜선의 개수가 필요한 랜선의 개수보다 크거나 같을 경우 @low에 @mid + 1을 대입 */
    else if (seperated >= needLAN) {
      low = mid + 1;
      if (answer < mid) answer = mid;
    }
  }

  cout << answer << endl;
  
  return 0;
}