import sys
input = sys.stdin.readline

n = input().rstrip()
n = '0b' + n

dec = int(n, 2)
dec *= 17
dec = format(dec, 'b')

print(dec)