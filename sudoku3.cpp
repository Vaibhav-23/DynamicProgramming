#include<bits/stdc++.h>
using namespace std;
using pii = pair<int,int>;
const int N = 9;
//Initializing sudoku
vector<vector<int>> sudoku = {
    {0, 0, 5, 3, 0, 0, 0, 0, 0},
    {8, 0, 0, 0, 0, 0, 0, 2, 0},
    {0, 7, 0, 0, 1, 0, 5, 0, 0},
    {4, 0, 0, 0, 0, 5, 3, 0, 0},
    {0, 1, 0, 0, 7, 0, 0, 0, 6},
    {0, 0, 3, 2, 0, 0, 0, 8, 0},
    {0, 6, 0, 5, 0, 0, 0, 0, 9},
    {0, 0, 4, 0, 0, 0, 0, 3, 0},
    {0, 0, 0, 0, 0, 9, 7, 0, 0}
};

vector<vector<vector<bool>>> domain(N,vector<vector<bool>>(N, vector<bool>(9, 1))); // Initial domains

queue<pii> q;

bool isPossible(int row, int col, int num) {
    for(int i=0;i<9;i++){
        if(sudoku[row][i]==num) return false;
        if(sudoku[i][col]==num) return false;
        if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3]==num) return false;
    }
    return true;
}

void arcConsistency() {
    while (!q.empty()) {
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0; i < N; ++i) {
            if (i != col && sudoku[row][i] == 0) {
                for (int num = 1; num <= N; ++num) {
                    if (!domain[row][i][num - 1]) continue;
                    if (!isPossible(row, i, num)) {
                        domain[row][i][num - 1] = 0;
                        q.push({row, i});
                    }
                }
            }
        }
        for (int i = 0; i < N; ++i) {
            if (i != row && sudoku[i][col] == 0) {
                for (int num = 1; num <= N; ++num) {
                    if (!domain[i][col][num - 1])
                        continue;
                    if (!isPossible(i, col, num)) {
                        domain[i][col][num - 1] = 0;
                        q.push({i, col});
                    }
                }
            }
        }
        int startRow = row - row % 3;
        int startCol = col - col % 3;
        for (int i = startRow; i < startRow + 3; ++i) {
            for (int j = startCol; j < startCol + 3; ++j) {
                if (i != row && j != col && sudoku[i][j] == 0) {
                    for (int num = 1; num <= N; ++num) {
                        if (!domain[i][j][num - 1])
                            continue;
                        if (!isPossible(i, j, num)) {
                            domain[i][j][num - 1] = 0;
                            q.push({i, j});
                        }
                    }
                }
            }
        }
    }
}

bool solve(int row, int col) {
    if (row == N - 1 && col == N) return true;
    if (col == N) {
        col = 0;
        ++row;
    }
    if (sudoku[row][col] != 0)
        return solve(row, col + 1);

    for (int num = 1; num <= N; ++num) {
        if (domain[row][col][num - 1] && isPossible(row, col, num)) {
            sudoku[row][col] = num;
            if (solve(row, col + 1))
                return true;
            sudoku[row][col] = 0;
        }
    }
    return false;
}

void printSudoku() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << sudoku[i][j] << " ";
        }
        cout << endl;
    }
}
void printDomain() {
  for(int i=0; i<N; i++) {
    for(int j=0; j<N; j++) {
        int count=0;
      for(int k=0; k<N; k++) {
        if(domain[i][j][k]) count++;
      }
      cout<<count<<" ";
    }
    cout<<endl;
  }
}
void getInput(vector<vector<int>> &sudoku){
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin>>sudoku[i][j];
        }
    }
}
int main() {
    //getInput(sudoku);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (sudoku[i][j] != 0)
                q.push({i, j});
        }
    }
    cout<<"Initial Configuration"<<endl;
    printSudoku();
    cout<<endl;
    cout<<"Initial Domain"<<endl;
    printDomain();
    cout<<"Domain values After arcConsistency"<<endl;
    arcConsistency();
    printDomain();
    if (solve(0, 0)){
        cout<<endl;
        cout<<"Sudoku Solution:"<<endl;
        printSudoku();
    }
    else cout << "No solution exists." << endl;
    return 0;
}
