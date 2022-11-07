import sys
input = sys.stdin.readline

seq_size = int(input().rstrip())
seq = list(map(int, input().rstrip().split()))
answer = [ -1 ] * seq_size
stack = []

stack.append(0)  
for i in range(1, seq_size):
  while stack and seq[stack[len(stack) - 1]] < seq[i]:
    answer[stack.pop()] = seq[i]
  stack.append(i)

print(*answer)