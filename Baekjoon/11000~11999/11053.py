import sys

input = sys.stdin.readline

seq_size = int(input().rstrip())
seq = list(map(int, input().rstrip().split()))
dp_sub_len = [ 0 for _ in range(seq_size) ]
dp_sub_len[0] = 1

for i in range(1, seq_size):
  for j in range(0, i):
    if dp_sub_len[i] <= dp_sub_len[j] and seq[i] > seq[j]:
      dp_sub_len[i] = dp_sub_len[j]
  dp_sub_len[i] += 1

print(max(dp_sub_len))