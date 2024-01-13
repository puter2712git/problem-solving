import sys
input = sys.stdin.readline

n, m = map(int, input().rstrip().split())
print(n // m)
print(n % m)