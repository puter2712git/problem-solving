import sys
input = sys.stdin.readline

testcase = int(input().rstrip())

for i in range(testcase):
  parallel_develop_time, program_count, serial_runtime, parallel_runtime = map(int, input().rstrip().split())
  
  serial = program_count * serial_runtime
  parallel = parallel_develop_time + program_count * parallel_runtime
  
  if serial < parallel:
    print('do not parallelize')
  elif serial > parallel:
    print('parallelize')
  else:
    print('does not matter')