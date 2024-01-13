import sys
input = sys.stdin.readline

num_list = list(map(int, input().rstrip().split()))
count = 0

for element in num_list:
  if element > 0:
    count += 1

print(count)