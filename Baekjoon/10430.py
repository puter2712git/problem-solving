import sys
input = sys.stdin.readline

a, b, c = map(int, input().rstrip().split())

print((a + b) % c)
print(((a % c) + (b % c)) % c)
print((a * b) % c)
print((a % c) * (b % c) % c)