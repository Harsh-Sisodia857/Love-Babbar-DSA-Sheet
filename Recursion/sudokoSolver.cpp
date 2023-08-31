//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


// } Driver Code Ends
class Solution 
{
    public:
    bool isValid(int row,int col,int num,int grid[N][N]){
        for(int i = 0; i <N;i++){
            if(grid[i][col] == num)
                return false;
        
            if(grid[row][i] == num)
                return false;
        
            if(grid[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == num)
                return false;
        }
        return true;
    }
    //Function to find a solved Sudoku. 
    bool SolveSudoku(int grid[N][N])  
    { 
        for(int i = 0; i < N;i++){
            for(int j = 0; j < N; j++){
                if(grid[i][j] == 0){
                    for(int c = 1; c <=9; c++){
                        if(isValid(i,j,c,grid)){
                            grid[i][j] = c;
                            if(SolveSudoku(grid))
                                return true;
                            grid[i][j] = 0;
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    
    //Function to print grids of the Sudoku.
    void print(int grid[N][N]){
        
        for(int i = 0; i < N; i++){
                for(int j =0; j < N; j++){
                    cout<<grid[i][j]<<" ";
                }
            }
        return;
    }
    void printGrid (int grid[N][N]) 
    {
        print(grid);
        
    }
};

//{ Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}
// } Driver Code Ends