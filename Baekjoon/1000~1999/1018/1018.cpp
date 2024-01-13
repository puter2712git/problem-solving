#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<string> blackChessBoard = {
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
};


vector<string> whiteChessBoard = {
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
  "WBWBWBWB",
  "BWBWBWBW",
};


// @blackChessBoard와 비교
int compareWithBlack(vector<string> _board, int startX, int startY) {
  int recolored = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (blackChessBoard[i][j] != _board[startX + i][startY + j]) {
        recolored++;
      }
    }
  }

  return recolored;
}


// @whiteChessBoard와 비교
int compareWithWhite(vector<string> _board, int startX, int startY) {
  int recolored = 0;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (whiteChessBoard[i][j] != _board[startX + i][startY + j]) {
        recolored++;
      }
    }
  }

  return recolored;
}


int main() {
  int minValue, answer = INT32_MAX;
  int width, height;
  cin >> height >> width;

  vector<string> board(height);
  for (int i = 0; i < height; i++) {
    cin >> board[i];
  }

  // 8 x 8 크기를 비교해야 하므로 반복문의 범위 주의
  for (int i = 0; i < height - 8 + 1; i++) {
    for (int j = 0; j < width - 8 + 1; j++) {
      // 최솟값 저장
      minValue = min(compareWithBlack(board, i, j), compareWithWhite(board, i, j));
      answer = min(answer, minValue);
    }
  }

  cout << answer << endl;

  return 0;
}