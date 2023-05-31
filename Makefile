# 변수 설정
CC = g++
CFLAGS = -std=c++17 -g

# 소스 파일 리스트 생성
SRCS := $(shell find . -type f -name "*.cpp")

# 실행 파일 리스트 생성
BINS := $(patsubst %.cpp,%.exe,$(SRCS))

# 기본 타겟 설정
all: $(BINS)

# 실행 파일 생성 타겟
%.exe: %.cpp
	$(CC) $(CFLAGS) $< -o $@

# clean 타겟
clean:
	$(RM) $(BINS) $(SRCS)