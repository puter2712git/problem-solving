import sys

input = sys.stdin.readline

seq_size = int(input().rstrip())
seq = list(map(int, input().rstrip().split()))
subseq_sum = [ [ 0 for _ in range(2) ] for _ in range(seq_size) ]
maximum = -99999999

subseq_sum[0][0] = seq[0]

for i in range(1, seq_size):
  subseq_sum[i][0] = max(subseq_sum[i - 1][0] + seq[i], seq[i])
  subseq_sum[i][1] = max(subseq_sum[i - 1][0], subseq_sum[i - 1][1] + seq[i])
  
  maximum = max(maximum, subseq_sum[i][0], subseq_sum[i][1])

if seq_size > 1:
  print(maximum)
else:
  print(subseq_sum[0][0])