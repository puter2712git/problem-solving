import sys
input = sys.stdin.readline

length = list(map(int, input().rstrip().split()))
length.sort()

if length[2] >= length[1] + length[0]:
  length[2] = length[1] + length[0] - 1

print(sum(length))