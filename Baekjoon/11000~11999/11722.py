import sys

input = sys.stdin.readline

seq_size = int(input().rstrip())
seq = list(map(int, input().rstrip().split()))
subseq_len = [ 1 ] * seq_size

for i in range(1, seq_size):
  for j in range(0, i):
    if seq[i] < seq[j]:
      subseq_len[i] = max(subseq_len[j] + 1, subseq_len[i])

print(max(subseq_len))