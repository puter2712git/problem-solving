import sys

input = sys.stdin.readline

n = int(input().rstrip())
dp_lion = [ [ 0 for _ in range(3) ] for _ in range(n + 1) ]
# dp_lion[n][0]은 n째 줄에 사자가 없는 경우의 수
dp_lion[1][0] = 1
# dp_lion[n][1]은 n째 줄의 왼쪽에 사자가 있는 경우의 수
dp_lion[1][1] = 1
# dp_lion[n][2]은 n째 줄의 오른쪽에 사자가 있는 경우의 수
dp_lion[1][2] = 1

for i in range(2, n + 1):
  dp_lion[i][0] = (dp_lion[i - 1][0] + dp_lion[i - 1][1] + dp_lion[i - 1][2]) % 9901
  dp_lion[i][1] = (dp_lion[i - 1][0] + dp_lion[i - 1][2]) % 9901
  dp_lion[i][2] = (dp_lion[i - 1][0] + dp_lion[i - 1][1]) % 9901
  
print(sum(dp_lion[n]) % 9901)