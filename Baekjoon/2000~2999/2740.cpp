#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> MultiplyMat(vector<vector<int>>& a, vector<vector<int>>& b)
{
    int row = a.size();
    int col = b[0].size();
    int overlap = a[0].size();
    vector<vector<int>> ret = vector<vector<int>>(row, vector<int>(col, 0));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            for (int k = 0; k < overlap; k++) {
                ret[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int matARow, matACol;
    vector<vector<int>> matA;

    cin >> matARow >> matACol;
    for (int i = 0; i < matARow; i++) {
        matA.push_back(vector<int>());
        for (int j = 0; j < matACol; j++) {
            int tmp;
            cin >> tmp;
            matA[i].push_back(tmp);
        }
    }

    int matBRow, matBCol;
    vector<vector<int>> matB;

    cin >> matBRow >> matBCol;
    for (int i = 0; i < matBRow; i++) {
        matB.push_back(vector<int>());
        for (int j = 0; j < matBCol; j++) {
            int tmp;
            cin >> tmp;
            matB[i].push_back(tmp);
        }
    }

    vector<vector<int>> mat = MultiplyMat(matA, matB);
    for (int i = 0; i < mat.size(); i++) {
        for (int j = 0; j < mat[0].size(); j++) {
            cout << mat[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}