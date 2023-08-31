//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
public:
    // Function to determine if graph can be coloured with at most M colours such
    // that no two adjacent vertices of graph are coloured with same colour.
    
    bool isValid(int node,bool graph[101][101],int n,int color[],int currColor){
        if(node == 0)
            return true;
        
        for(int i = 0; i < n;i++){
            if(i != node && graph[i][node] == 1 && color[i] == currColor)
                return false;
        }
        return true;
    }
    
    bool isPossible(int node,bool graph[101][101], int n,int color[],int m){
        
        if(node == n)
            return true;
        
    
            for(int j = 1; j <= m; j++){
            if(color[node] == 0){
                if(isValid(node,graph,n,color,j)){
                    color[node] = j;
                    if(isPossible(node+1,graph,n,color,m))
                        return true;
                    color[node] = 0;
                }
            }
          }
        return false;
    }
    
    bool graphColoring(bool graph[101][101], int m, int n) {
        int color[n] = {0};
        return isPossible(0,graph,n,color,m);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        Solution ob;
        cout << ob.graphColoring(graph, m, n) << endl;
    }
    return 0;
}

// } Driver Code Ends