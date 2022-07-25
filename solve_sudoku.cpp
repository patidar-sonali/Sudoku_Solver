
#include <iostream>
using namespace std;

bool safe(int s[][9],int i, int j, int no,int n)
{
    //check for row and column
    for(int k=0;k<n;k++)
    {
        if(s[k][j]== no || s[i][k]==no)
        {
            return false;
        }
    }
    //check for subgrid
    int sx=(i/3)*3;
    int sy=(j/3)*3;
    for(int x= sx; x<(sx+3);x++)
    {
      for(int y= sy; y<(sy+3);y++)
      {
          if(s[x][y]==no)
          {
              return false;
          }
      }  
    }
 return true;
}
bool solve_sudoku(int s[][9], int i, int j, int n)
{
    //base case
    if(i==n)
    {
        for(int i=0; i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                cout<<s[i][j]<<" ";
            }
            cout<<endl;
        }
        return true;
    }
    if(j==n)
    {
    return solve_sudoku(s, i+1, 0, n);
    }
    //skip prefilled cell
    if(s[i][j]!=0)
    {
       return solve_sudoku(s,i,j+1,n);
    }
    //cell to be filled
    for(int no=1;no<=n;no++)
    {
        if(safe(s,i,j,no,n))
        {
            s[i][j]=no;
            bool solve_subproblem= solve_sudoku(s,i,j+1,n);
        
            if(solve_subproblem == true)
            {
            return true;
            }
        }

    }
    s[i][j]=0;
    return false;
}
int main() {
	// your code goes here
    int n=9;
    int s[9][9]={{5,3,0,0,7,0,0,0,0},
                 {6,0,0,1,9,5,0,0,0},
                 {0,9,8,0,0,0,0,6,0},
                 {8,0,0,0,6,0,0,0,3},
                 {4,0,0,8,0,3,0,0,1},
                 {7,0,0,0,2,0,0,0,6},
                 {0,6,0,0,0,0,2,8,0},
                 {0,0,0,4,1,9,0,0,5},
                 {0,0,0,0,8,0,0,7,9}};

    if(!solve_sudoku(s,0,0,n))
    {
        cout<<"NO solution exist!";
    }
	return 0;
}

