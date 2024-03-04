#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int useCounts[10] = { 0 };
    string roomId;
    cin >> roomId;

    // 숫자마다 사용된 횟수 저장
    for (char num : roomId) {
        useCounts[num - '0']++;
    }

    // 가장 많이 사용된 숫자 찾기
    int maxCountIndex = 0;
    int maxTmp = useCounts[0];
    for (int i = 1; i < 10; i++) {
        if (maxTmp < useCounts[i]) {
            maxCountIndex = i;
            maxTmp = useCounts[i];
        }
    }

    // 만약 가장 많이 사용된 숫자가 6 또는 9라면, 예외 처리
    if (maxCountIndex == 6 || maxCountIndex == 9) {
        int sixAndNineUsedCount = useCounts[6] + useCounts[9];

        if (sixAndNineUsedCount % 2 == 0) {
            useCounts[6] = sixAndNineUsedCount / 2;
            useCounts[9] = sixAndNineUsedCount / 2;
        } else {
            useCounts[6] = sixAndNineUsedCount / 2 + 1;
            useCounts[9] = sixAndNineUsedCount / 2 + 1;
        }

        maxCountIndex = 0;
        maxTmp = useCounts[0];

        for (int i = 1; i < 10; i++) {
            if (maxTmp < useCounts[i]) {
                maxCountIndex = i;
                maxTmp = useCounts[i];
            }
        }
    }

    cout << maxTmp << "\n";

    return 0;
}