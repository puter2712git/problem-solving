import sys
input = sys.stdin.readline

work_count, time = map(int, input().rstrip().split())
works = list(map(int, input().rstrip().split()))
count = 0

for work in works:
  if time < work:
    break
  else:
    time -= work
    count += 1

print(count)