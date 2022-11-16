import sys

input = sys.stdin.readline

n = int(input().rstrip())
dp_fibo = [ None ] * (n + 1)
dp_fibo[0] = 0
dp_fibo[1] = 1

for i in range(2, n + 1):
  dp_fibo[i] = dp_fibo[i - 1] + dp_fibo[i - 2]

print(dp_fibo[n])