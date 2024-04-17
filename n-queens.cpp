#include<iostream>
using namespace std;
int cnt=0;
void print(bool board[][20],int n){
    cnt++;
    cout << "solution" << cnt << endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<board[i][j]<<" ";
        cout<<endl;
    }
    cout<<endl;
}
bool canplace(bool board[][20],int n,int x,int y){
    for(int i=0;i<x;i++)
        if(board[i][y]==1)
            return 0;


    int i=x,j=y;
    while(i>=0&&j>=0){
        if(board[i][j]==1)
            return 0;
        i--;j--;
    }


    i=x;j=y;
    while(i>=0&&j<n){
        if(board[i][j]==1)
            return 0;
        i--;j++;
    }


    return 1;
}
void solve(bool board[][20],int n,int i){
    if(i==n){
        print(board,n);
        return;
    }
    for(int j=0;j<n;j++){
        if(canplace(board,n,i,j)){
            board[i][j]=1;
            solve(board,n,i+1);
            board[i][j]=0;
        }
    }
}
int main(){
    int n;
    cin>>n;
    bool board[20][20];
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            board[i][j]=0;
    solve(board,n,0);
    return 0;
}
