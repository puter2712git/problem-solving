import sys
from collections import Counter

input = sys.stdin.readline

n = int(input().rstrip())
seq = list(map(int, input().rstrip().split()))

num_count = Counter(seq)

answer = [-1] * n
stack = []

stack.append(0)
for i in range(1, n):
  while stack and num_count[seq[stack[-1]]] < num_count[seq[i]]:
    answer[stack.pop()] = seq[i]
  stack.append(i)

print(*answer)