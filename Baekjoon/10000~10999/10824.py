import sys
input = sys.stdin.readline

a, b, c, d = map(str, input().rstrip().split())
ab = int(a + b)
cd = int(c + d)

print(ab + cd)