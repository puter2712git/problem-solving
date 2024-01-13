import sys
input = sys.stdin.readline

t = int(input().rstrip())

for i in range(t):
    a, b = map(int, input().rstrip().split())
    print('Case #{0}: {1}'.format(str(i + 1), str(a + b)))