#include <bits/stdc++.h>
using namespace std;
int cnt=0;
void helper(vector<vector<int>> &M, int i, int j, int rw, int cl)
{
    if(i<0 || j<0 || i==rw || j==cl){
        return;
    }
    if(M[i][j]==1){
        M[i][j]=0;
        helper(M, i+1,j,rw,cl);
        helper(M, i,j+1,rw,cl);
        helper(M, i+1,j+1,rw,cl);
        helper(M, i-1,j,rw,cl);
        helper(M, i,j-1,rw,cl);
        helper(M, i-1,j-1,rw,cl);
        helper(M, i+1,j-1,rw,cl);
        helper(M, i-1,j+1,rw,cl);
    }
}
void count_isl( vector<vector<int>>&M, int rw, int cl){
    
    for(int i=0;i<rw;i++){
        for(int j=0;j<cl;j++)   
        {
        if(M[i][j]==1)
        {
        cnt+=1;
        M[i][j]=0;
        helper(M, i+1,j,rw,cl);
        helper(M, i,j+1,rw,cl);
        helper(M, i+1,j+1,rw,cl);
        helper(M, i-1,j,rw,cl);
        helper(M, i,j-1,rw,cl);
        helper(M, i-1,j-1,rw,cl);
        helper(M, i+1,j-1,rw,cl);
        helper(M, i-1,j+1,rw,cl);
        }
    }
    }
}




int main()
{
    int n,m;
    cout<<"Enter dimension of matrix:"<<endl;
    cin>>n>>m;
    vector<vector<int>> M(n);
    cout<<"Enter matrix:"<<endl;
    for (int i=0;i<n;i++){
        for(int j=0;j<m;j++)
        {
            int x;
            cin>>x;
            M[i].push_back(x);
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++)
    //     cout<<M[i][j]<<' ';
    //     cout<<endl;
    // }
    count_isl(M,n,m);
    cout<<"Number of islands = "<<cnt<<endl;
}
