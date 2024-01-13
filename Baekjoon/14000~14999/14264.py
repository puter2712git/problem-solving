import sys, math
input = sys.stdin.readline

length = int(input().rstrip())
print(length * length / 2 * math.sin(math.pi * 2 / 3))