import sys
input = sys.stdin.readline

n = int(input().rstrip())
fibonacci = [None] * (n + 1)
fibonacci[0] = 0
if (n > 0):
    fibonacci[1] = 1

for i in range(2, n + 1):
    fibonacci[i] = fibonacci[i - 1] + fibonacci[i - 2]

print(fibonacci[n])