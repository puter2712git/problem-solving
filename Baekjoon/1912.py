import sys

input = sys.stdin.readline

n = int(input().rstrip())
seq = list(map(int, input().rstrip().split()))

dp_sum = [ None ] * n
dp_sum[0] = seq[0]

for i in range(1, n):
  dp_sum[i] = max(dp_sum[i - 1] + seq[i], seq[i])
  
print(max(dp_sum))