import sys
input = sys.stdin.readline

a, i = map(int, input().rstrip().split())

print(a * (i - 1) + 1)