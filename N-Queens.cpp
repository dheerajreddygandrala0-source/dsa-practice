#include<iostream>
#include<vector>
using namespace std;
bool issafe(vector<string>&board,int row,int col,int n){
    for(int i = row - 1; i >= 0; i--) {
        if(board[i][col] == '1')
            return false;
    }

    
    for(int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if(board[i][j] == '1')
            return false;
    }

    
    for(int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
        if(board[i][j] == '1')
            return false;
    }

    return true;
}
void nqueen(vector<string>&board,int row,  vector<vector<string>>&ans,int n){
    if(row==n){
        ans.push_back(board);
        return;
    }
    
    
    for(int j=0;j<n;j++){
        if(issafe(board,row,j,n)){
            board[row][j]='1';
            nqueen(board,row+1,ans,n);
            board[row][j]='0';
        }
    }
}
int main(){
    int n;
    cin >> n;
    vector<vector<string>>ans;
    vector<string> board(n, string(n, '0'));
    // vector<string>board(n,board(n,'0'));
    nqueen(board,0,ans,n);
    for(int k = 0; k < ans.size(); k++) {
    for(int i = 0; i < ans[k].size(); i++) {
        cout << ans[k][i] << endl;
    }
    cout << endl;   // blank line between solutions
}
    return 0;
    
}
