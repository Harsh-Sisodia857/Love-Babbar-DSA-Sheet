//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{   
    public: 
    void spiral(vector<vector<int> > matrix,int left,int right,int top,int bottom,vector<int> &ans){
         if (left > right || top > bottom)
            return;
        
        // left to right
        for(int i = left; i <= right; i++){
            ans.push_back(matrix[top][i]);
        }
        top++;
        
        // top to bottom
        for(int i = top; i <= bottom;i++){
            ans.push_back(matrix[i][right]);
        }
        right--;
    
        // right to left (check if there's still a row)
        if (top <= bottom) {
            for (int i = right; i >= left; i--) {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
          }

        // bottom to top (check if there's still a column)
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
        spiral(matrix,left,right,top,bottom,ans);
    }
    
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        int left = 0;
        int right = c - 1;
        int top = 0;
        int bottom = r - 1;
        vector<int> ans;
        spiral(matrix,left,right,top,bottom,ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends