import sys
input = sys.stdin.readline

t = int(input().rstrip())

for i in range(t):
  n = int(input().rstrip())
  univ_dict = {}
  
  for j in range(n):
    univ, alcohol = input().rstrip().split()
    alcohol = int(alcohol)
    
    univ_dict[univ] = alcohol
  
  print(max(univ_dict, key = univ_dict.get))