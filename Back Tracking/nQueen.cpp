#include<bits/stdc++.h>
using namespace std;

char board[10][10];
int n;

bool isSafe(int r, int c)
{
    /// checking Queen in Same column
    for (int i = 0; i < r; i++)
        if (board[i][c] == 'Q')
            return false;

    /// checking Queen in Same \ diagonal
    for(int i=r,j=c;i>=0&&j>=0;i--,j--)
        if(board[i][j]=='Q')
            return false;

    /// checking Queen in Same / diagonal
    for(int i=r,j=c;i>=0&&j<n;i--,j++)
        if(board[i][j]=='Q')
            return false;

    return true;
}

void Nqueen(int r)
{
    if(r==n)
    {
        cout<<"\nSolution:\n\n";
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                cout<<board[i][j]<<"  ";
            cout<<endl;
        }
        cout<<endl;
        return;
    }
    for(int i=0;i<n;i++)
    {
        if(isSafe(r,i))
        {
            board[r][i] = 'Q'; // valid position
            Nqueen(r+1);       // Recursive call
            board[r][i] = '.'; // removing Queen while backtracking
        }
    }
}

int main()
{
    memset(board,'.',sizeof(board));
    printf("N = ");
    cin>>n;
    Nqueen(0);
    return 0;
}
