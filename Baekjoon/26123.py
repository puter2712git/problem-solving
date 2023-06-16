import sys
input = sys.stdin.readline

N, D = map(int, input().rstrip().split())
heights = list(map(int, input().rstrip().split()))
max_height = max(heights)

count = 0

for i in range(N):
	sub = max_height - heights[i]

	if (sub >= D):
		continue

	sub = D - sub

	if (sub > heights[i]):
		count += heights[i]
	else:
		count += sub

print(count)