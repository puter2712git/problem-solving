import sys

input = sys.stdin.readline

seq_size = int(input().rstrip())
seq = list(map(int, input().rstrip().split()))
reversed_seq = seq[::-1]

increasing = [ 1 ] * seq_size
decreasing = [ 1 ] * seq_size
bitonic = [ None ] * seq_size

for i in range(1, seq_size):
  for j in range(i):
    if seq[i] > seq[j]:
      increasing[i] = max(increasing[i], increasing[j] + 1)
    if reversed_seq[i] > reversed_seq[j]:
      decreasing[i] = max(decreasing[i], decreasing[j] + 1)

for i in range(seq_size):
  bitonic[i] = increasing[i] + decreasing[seq_size - i - 1] - 1
  
print(max(bitonic))