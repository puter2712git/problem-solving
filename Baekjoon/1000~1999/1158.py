import sys
input = sys.stdin.readline

n, k = map(int, input().rstrip().split())
index = k - 1
people = list(range(1, n + 1))
sequence = []

for _ in range(n):
  sequence.append(people[index])
  people = people[:index] + people[index + 1:]
  
  if people:
    index = (index + k - 1) % len(people)

print('<{}>'.format(str(sequence)[1:-1]))