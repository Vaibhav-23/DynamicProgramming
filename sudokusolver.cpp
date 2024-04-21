#include<bits/stdc++.h>
using namespace std;
bool ispossible(vector<vector<char>>& board,char c,int row,int col){
    for(int i=0;i<9;i++){
        if(board[row][i]==c) return false;
        if(board[i][col]==c) return false;
        if(board[3*(row/3)+i/3][3*(col/3)+i%3]==c) return false;
    }
    return true;
}
bool solve(vector<vector<char>>& board){
    int m=board.size(),n=board[0].size();
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(board[i][j]=='.'){
                for(char c = '1';c<='9';c++){
                    if(ispossible(board,c,i,j)){
                        board[i][j]=c;
                        if(solve(board)==true)
                            return true;
                        else 
                            board[i][j]='.';
                    }
                }
                    return false;
            }
        }
    }
    return true;
}
void print(vector<vector<char>>& board){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cout<<board[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main(){
    vector<vector<char>>board(9,vector<char>(9,'.'));
    // taking input of the board
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++){
            cin>>board[i][j];
        }
    }
    print(board);
    cout<<endl;
    if(solve(board)) print(board);
    else cout<<"Not Possible"<<endl;
}