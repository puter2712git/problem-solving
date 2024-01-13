import sys

input = sys.stdin.readline

size = int(input().rstrip())
seq = list(map(int, input().rstrip().split()))
subseq_sum = [ 0 ] * size
subseq_sum[0] = seq[0]

for i in range(1, size):
  for j in range(i):
    if seq[i] > seq[j]:
      subseq_sum[i] = max(subseq_sum[i], subseq_sum[j] + seq[i])
    else:
      subseq_sum[i] = max(subseq_sum[i], seq[i])

print(max(subseq_sum))