/*
BFS OF A GRAPH
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        vis[0] = 1;
        queue<int> q;
        vector<int> BFS;
        q.push(0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            BFS.push_back(node);
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it] = 1;
                    q.push(it);
                }
            }
            
        }
        return BFS;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >>

            E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            // 		adj[v].push_back(u);
        }
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int> ans = obj.bfsOfGraph(V, adj);
        for (int i = 0; i < ans.size(); i++) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends




// DFS OF A GRAPH
class Solution {
private:
    void dfs(int node, vector<int> adj[], int vis[], vector<int> &ls){
        vis[node] = 1;
        ls.push_back(node);
        // traverse all its neighbours
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis, ls);
            }
        }
    }
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        int vis[V] = {0};
        int start = 0;
        vector<int> ls;
        dfs(start, adj, vis, ls);
        return ls;
    }
};



NUMBER OF PROVINCES
class Solution {
    private:
    void dfs(int node,vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it, adj, vis);

            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n, vector<int>());
        int cnt = 0;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
             

        }
        vector<int> vis(n, 0);
        for(int i = 0; i<n; i++){
            if(!vis[i]){
                cnt++;
                dfs(i, adj, vis);
            }
        }
        return cnt;
        
    }
};



NUMBER OF ISLANDS {4 DIRECTION}
class Solution {
public:
    void bfs(int row, int col, vector<vector<int>> &vis, vector<vector<char>>&grid){
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        q.push({row, col});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            // traversal in the neighbours and mark them
            if(row-1 >= 0 && col >= 0 && row-1 < n && col < m && !vis[row-1][col] && grid[row-1][col] == '1'){
                vis[row-1][col] = 1;
                q.push({row-1, col});
            }
            if(col + 1 < m && col + 1 >= 0 && row < n && row >= 0 && !vis[row][col+1] && grid[row][col+1] == '1'){
                vis[row][col+1] = 1;
                q.push({row, col+1});
            }
            if(row + 1 < n && row +1 >= 0 && col < m && col >= 0 && !vis[row+1][col] && grid[row+1][col] == '1'){
                vis[row+1][col] = 1;
                q.push({row+1, col});
            }
            if(col -1 >= 0 && col < m && row < n && row >= 0 && !vis[row][col-1] && grid[row][col-1] == '1'){
                vis[row][col-1] = 1;
                q.push({row, col-1});
            }
            

        } 
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        int cnt = 0;
        for(int row = 0; row < n; row++){
            for(int col = 0; col < m; col++){
                if(!vis[row][col] && grid[row][col] == '1'){
                    cnt++;
                    bfs(row, col, vis, grid);
                }
            }
        }
        return cnt;

        
    }
};


FLOOD FILL ALGORITHM
class Solution {
public:
    void dfs(int row, int col, vector<vector<int>> &ans, vector<vector<int>> &image, int color, vector<int>&delRow, vector<int> &delCol, int iniColor){
        ans[row][col] = color;
        int n = image.size();
        int m = image[0].size();
        for(int i = 0; i<4; i++){
            for(int j  = 0; j<4; j++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow >= 0 & ncol >= 0 && nrow < n && ncol < m && image[nrow][ncol] == iniColor && ans[nrow][ncol] != color){
                    dfs(nrow, ncol, ans, image, color, delRow, delCol, iniColor);
                }
            }
        }    
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>> ans = image;
        int iniColor = image[sr][sc];
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, +1, 0, -1};
        dfs(sr, sc, ans, image,color, delRow, delCol, iniColor);
        return ans;
        
    }
};



ROTTEN EGGES
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int, int>, int>> q;  //{{r,c}, t}
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                    vis[i][j] = 2;
                }
            }
        }
        int time = 0;
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t = q.front().second;
            time = max(time, t);
            q.pop();
            for(int i = 0; i<4; i++){
                int nrow =  r + delRow[i];
                int ncol = c + delCol[i];
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
                    && vis[nrow][ncol]  == 0 && grid[nrow][ncol] == 1){
                        q.push({{nrow, ncol}, time + 1});
                        vis[nrow][ncol] = 2;    

                    }

            }
        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(vis[i][j] != 2 && grid[i][j] == 1){
                    return -1;
                }
            }
        }
        return time;




        
    }
};




DETECT A CYCLE IN AN UNDIRECTED GRAPH using BFS   TC -> O(N + 2E)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  bool detect(int src, vector<int> adj[], vector<int> &vis){
      vis[src] = 1;
      queue<pair<int, int>> q;
      q.push({src, -1});
      while(!q.empty()){
          int node = q.front().first;
          int parent = q.front().second;
          q.pop();
          
          for(auto it:adj[node]){
              if(!vis[it]){
                  vis[it] = 1;
                  q.push({it,node});
              }
              else if(parent != it){
                  return true;
              }
          }
      }
      return false;  
      
  }
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        vector<int> vis(V, 0);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(detect(i, adj, vis)) return true;
            }
        }
        return false;
    }
    
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends



DISTANCE OF NEAREST CELL HAVING 1
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n = grid.size();
	    int m = grid[0].size();
	    queue<pair<pair<int, int>, int>> q;
	    vector<vector<int>> dis(n, vector<int>(m, 0));
	    vector<vector<int>> vis(n, vector<int>(m, 0));
	    for(int i =0; i<n; i++){
	        for(int j = 0; j<m; j++){
	            if(grid[i][j] == 1){
	                q.push({{i, j}, 0});
	                vis[i][j] = 1;
	            }
	            else{
	                vis[i][j] = 0;
	            }
	        }
	    }
	    vector<int> delRow = {-1,0,1,0};
	    vector<int> delCol = {0,1,0,-1};
	    while(!q.empty()){
	        int row = q.front().first.first;
	        int col = q.front().first.second;
	        int steps = q.front().second;
	        q.pop();
	        dis[row][col] = steps;
	        
	        for(int i = 0; i<4; i++){
	            int nrow =  row + delRow[i];
	            int ncol = col + delCol[i];
	            if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m
	                && vis[nrow][ncol] == 0 ){
	                    vis[nrow][ncol] = 1;
	                    q.push({{nrow, ncol}, steps+1});
	                }
	        }
	    }
	    return dis;

	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends



SURROUNDED REGION (CONVERS ALL O's to x's)
class Solution {
public:
    void dfs(int row, int col, vector<vector<char>> &mat, vector<vector<int>> &vis){
        // chack for top, right, bottom, left;
        vector<int> delRow = {-1, 0, 1, 0};
        vector<int> delCol = {0, 1, 0, -1};
        vis[row][col] =1;
        int n = mat.size();
        int m = mat[0].size();
        
         for(int i = 0; i<4; i++){
             int nrow = row + delRow[i];
             int ncol = col + delCol[i];
             if(nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol] == 'O'){
                 dfs(nrow, ncol, mat, vis);
             }


         }
    }
    void solve(vector<vector<char>>& board) {
        int n = board.size(), m = board[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        //vector<int> delRow = {-1,0, 1, 0};
        //vector<int> delCol = {0, 1, 0, -1};
        // row travers;
        for(int j = 0; j < m; j++){
            // first row
            if(!vis[0][j] && board[0][j] == 'O'){
                dfs(0, j, board, vis);
            }
            // last row
            if(!vis[n-1][j] && board[n-1][j] == 'O'){
                dfs(n-1, j, board, vis);
            }
        }

        // col traverse;
        for(int i = 0; i<n; i++){
            // first col
            if(!vis[i][0] && board[i][0] == 'O'){
                dfs(i, 0, board, vis);
            }

            // last col
            if(!vis[i][m-1] && board[i][m-1] == 'O'){
                dfs(i, m-1, board, vis);
            }

        }
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        
        
    }
};


NUMBER OF ENCLAVES
class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(i == 0 || j == 0 || i == n-1 || j == m-1){
                    if(grid[i][j] == 1){
                        q.push({i, j});
                        vis[i][j] = 1;


                    }
                }
            }
        }
        int delrow[] = {-1,0,1,0};
        int delcol[] = {0, 1, 0, -1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            for(int i = 0; i<4; i++){
                int nrow = r + delrow[i];
                int ncol = c + delcol[i];
                if(nrow >= 0 && ncol >= 0 && ncol < m && nrow < n && vis[nrow][ncol] == 0 && grid[nrow][ncol] == 1){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }

        }
        int cnt = 0;
        for(int i =0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(grid[i][j] == 1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        return cnt;
        
    }
};



NUMBER OF DISTINCT ISLANDS     TC -> N*M + (N * M * 4)  
//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  void dfs(int row, int col, vector<vector<int>> &vis, vector<vector<int>> &grid, vector<pair<int, int>> &vec, int row0, int col0){
      vis[row][col] = 1;
      int n = grid.size();
      int m = grid[0].size();
      int delRow[] = {-1, 0, 1, 0};
      int delCol[] = {0, -1, 0, 1};
      vec.push_back({row - row0 , col - col0}); // row - baserow, col - basecol
      
      for(int i = 0; i<4; i++){
          int nrow = row + delRow[i];
          int ncol = col + delCol[i];
         if(nrow >= 0 && ncol >= 0 && nrow < n && ncol  < m
            && !vis[nrow][ncol] && grid[nrow][ncol] == 1){
                dfs(nrow, ncol, vis, grid, vec,row0, col0);
            }
      }
  }
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n, vector<int>(m, 0));
        set<vector<pair<int, int>>> st;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    vector<pair<int, int>> vec;
                    dfs(i, j, vis, grid, vec, i, j);
                    st.insert(vec);
                }
            }
        }
        return st.size();
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.countDistinctIslands(grid) << endl;
    }
}
// } Driver Code Ends



IS GRAPH BIPARTITE
class Solution {
    bool check(int start, vector<vector<int>> &graph, vector<int> &color){
        queue<int> q;
        q.push(start);
       
        int n = graph.size();
        
        color[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();

            for(auto it:graph[node]){
                // if the adjacent color is not uyet coloured 
                if(color[it] == -1){
                    color[it] = !color[node];
                    q.push(it);

                }
                else if(color[it] == color[node]){
                    return false;
                    
                }
            }


            
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        
        vector<int> color(n, -1);
        for(int i = 0; i<n; i++){
            if(color[i] == -1){
                if(check(i, graph, color) == false)return false; 
            }
        }
        return true;

        
        
        
    }
};



CHECK CYCLE IN BIPARTITE GRAPH
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool dfs(int i, vector<int> adj[], vector<int> &vis, vector<int> &pathvis){
        vis[i] = 1;
        pathvis[i] = 1;
        // traverse
        for(auto it:adj[i]){
            // if the node has not been visited
            if(!vis[it]){
                if(dfs(it, adj, vis, pathvis) == true) return true;
            }
            // if the node has been previously vissited
            else if(pathvis[it]){
                return true;
                
            }
        }
        
        pathvis[i] = 0;
        return false;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathvis) == true) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends



EVENTUAL SAFE STATE
class Solution {
public:
    bool dfs(int i, vector<vector<int>> &adj, vector<int> &vis, vector<int> &pathvis, vector<int> &check){
        vis[i] = 1;
        pathvis[i] = 1;
        // traverse
        for(auto it:adj[i]){
            // if the node has not been visited
            if(!vis[it]){
                if(dfs(it, adj, vis, pathvis, check) == true){
                    return true;
                }
            }
            // if the node has been previously visited
            else if(pathvis[it]){
                return true;
                
            }
        }
        check[i] = 1;
        pathvis[i] = 0;
        return false;
         x  x   
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V =graph.size();
        vector<int> vis(V, 0);
        vector<int> pathvis(V, 0);
        vector<int> check(V, 0);
        vector<int> safenode;
        for(int i = 0; i<V; i++){
            if(!vis[i]){
                dfs(i,graph, vis, pathvis, check);
            }
        }
        for(int i = 0; i<V; i++){
            if(check[i] == 1){
                safenode.push_back(i);
            }
        }
        return safenode;
        
        
    }
};



TOPOLLOGICAL SORT
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    
	public:
	void dfs(int node, int vis[], stack<int> &st, vector<int> adj[]){
	    vis[node] = 1;
	    for(auto it:adj[node]){
	        if(!vis[it]){
	            dfs(it, vis,  st,adj);
	        }
	    }
	    st.push(node); 
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int vis[V] = {0};
	    stack<int> st;
	    for(int i = 0; i<V; i++){
	        if(!vis[i]){
	            dfs(i, vis, st, adj);
	        }
	    }
	    vector<int> ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	}
};

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}
// } Driver Code Ends



KAHN'S ALGORITHM

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	    int indegree[V]= {0};
	    for(int i = 0; i<V; i++){
	        for(auto j:adj[i]){
	            indegree[j]++;
	        }
	    }
	    queue<int> q;
	    for(int i = 0; i<V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        // node is  in your topo sort;
	        //so please remove it from indegree
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    return topo;
	}
};


DETECT A CYCLE IN DIRECTED GRAPH  (USING TOPOLOGICAL SORT)
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    bool isCyclic(int V, vector<int> adj[]) {
       int indegree[V]= {0};
	    for(int i = 0; i<V; i++){
	        for(auto j:adj[i]){
	            indegree[j]++;
	        }
	    }
	    queue<int> q;
	    for(int i = 0; i<V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        // node is  in your topo sort;
	        //so please remove it from indegree
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    if(topo.size() == V) return false;
	    return true;
    }
};


COURSE SCHEDULE 1 USING TOPOLOGICAL SORT
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
				for(vector<int> &pre:prerequisites){
					adj[pre[1]].push_back(pre[0]);
				}
       
      vector<int> indegree(n, 0);
		// int indegree[numCourses] = {0};
	    for(int i = 0; i<n; i++){
	        for(auto j:adj[i]){
	            indegree[j]++;
	        }
	    }
	    queue<int> q;
	    for(int i = 0; i<n; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int> topo;
	    while(!q.empty()){
	        int node = q.front();
	        q.pop();
	        topo.push_back(node);
	        // node is  in your topo sort;
	        //so please remove it from indegree
	        for(auto it:adj[node]){
	            indegree[it]--;
	            if(indegree[it] == 0) q.push(it);
	        }
	    }
	    if(topo.size() == n) return true;
	    return false;

        
    }
};

 FIND EVENTUAL SAFE STATE USING TOPOLOGICAL SORT
 class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0), safenode;
        for(int i = 0; i<n; i++){
            for(auto &x:graph[i]){
                adj[x].push_back(i);
            }
        }
        for(int i = 0; i<n; i++){
            for(auto &x:adj[i]){
                indegree[x]++;
            }
        }
        queue<int> q;
        // for(auto &x : indegree){
        //     if(!x) q.push(x);
        // }
        for(int i = 0; i < n; i++) if(!indegree[i]) q.push(i);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safenode.push_back(node);
            for(auto &adjnode: adj[node]){
                indegree[adjnode]--;
                if(!indegree[adjnode]) q.push(adjnode);
            }
        }
        sort(safenode.begin(),safenode.end());
        return safenode;

        
    }
}


ALIEN DICTIONARY (TOPOLOGICAL SORT)


class Solution {
	// works for multiple components
private:
	vector<int> topoSort(int V, vector<int> adj[])
	{
		int indegree[V] = {0};
		for (int i = 0; i < V; i++) {
			for (auto it : adj[i]) {
				indegree[it]++;
			}
		}

		queue<int> q;
		for (int i = 0; i < V; i++) {
			if (indegree[i] == 0) {
				q.push(i);
			}
		}
		vector<int> topo;
		while (!q.empty()) {
			int node = q.front();
			q.pop();
			topo.push_back(node);
			// node is in your topo sort
			// so please remove it from the indegree

			for (auto it : adj[node]) {
				indegree[it]--;
				if (indegree[it] == 0) q.push(it);
			}
		}

		return topo;
	}
public:
	string findOrder(string dict[], int N, int K) {
		vector<int>adj[K];
		for (int i = 0; i < N - 1; i++) {
			string s1 = dict[i];
			string s2 = dict[i + 1];
			int len = min(s1.size(), s2.size());
			for (int ptr = 0; ptr < len; ptr++) {
				if (s1[ptr] != s2[ptr]) {
					adj[s1[ptr] - 'a'].push_back(s2[ptr] - 'a');
					break;
				}
			}
		}

		vector<int> topo = topoSort(K, adj);
		string ans = "";
		for (auto it : topo) {
			ans = ans + char(it + 'a');
		}
		return ans;
	}
};


// } Driver Code Ends



SHORTEST DISTANCE IN DIRECTED ACYCLIC GRAPH
class Solution {
  public:
    void toposort(int node, vector<pair<int, int>> adj[], int vis[], stack<int> &st){
        vis[node] = 1;
        for(auto it:adj[node]){
            int v = it.first;
            if(!vis[v]){
                toposort(v, adj, vis, st);
            }
        }
        st.push(node);
    }  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
       vector<pair<int, int>> adj[N];
        for(int i = 0; i<M;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            adj[u].push_back({v, wt});
        }
        // find the topo sort
        int vis[N]=  {0};
        stack<int> st;
        for(int i = 0; i<N; i++){
            if(!vis[i]){
                toposort(i, adj,vis, st);
            }
        }
        //step 2  do the ditstance thing
        vector<int> dist(N, 1e9);
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            for(auto it:adj[node]){
                int v = it.first;
                int wt = it.second;
                if(dist[node] + wt < dist[v]){
                    dist[v] = dist[node] + wt;
                }
            }
        }
        for (int i = 0; i < N; i++) {
        if (dist[i] == 1e9) dist[i] = -1;
      }
        return dist;
    }
};

SHORTEST PATH IN AN UNDIRECTED GRAPH WITH UNIT EDGES WEIGHT 
// User function Template for C++
class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        // code here
        vector<int> adj[N];
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            
        }
        vector<int> dist(N, 1e9);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto it:adj[node]){
                if(dist[node] + 1 < dist[it]){
                    dist[it] = dist[node] + 1;
                    q.push(it);
                }
            }
        }
       // vector<int> ans(N, -1);
        for(int i = 0; i<N;i++){
            if(dist[i] == 1e9){
                dist[i] = -1;
            }
        }
        return dist;
        
    }
};

LADDER WORD
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> q;
        unordered_set<string> st(wordList.begin(), wordList.end());
        st.erase(beginWord);
        q.push({beginWord, 1});
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            if(word == endWord) return steps;
            for(int i = 0; i< word.size(); i++){
                char original = word[i];
                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch;
                    if(st.find(word) != st.end()){
                        st.erase(word);
                        q.push({word, steps+1});
                    }
                }
                word[i] = original;
            }
        }
        return 0;
        
    }
};


WORD LADDER 2
class Solution
{
public:
    vector<vector<string>> findSequences(string beginWord, string endWord,
                                         vector<string> &wordList)
    {
        // Push all values of wordList into a set
        // to make deletion from it easier and in less time complexity.
        unordered_set<string> st(wordList.begin(), wordList.end());
        
        // Creating a queue ds which stores the words in a sequence which is
        // required to reach the targetWord after successive transformations.
        queue<vector<string>> q;

        // BFS traversal with pushing the new formed sequence in queue 
        // when after a transformation, a word is found in wordList.

        q.push({beginWord});

        // A vector defined to store the words being currently used
        // on a level during BFS.
        vector<string> usedOnLevel;
        usedOnLevel.push_back(beginWord);
        int level = 0;
       
        // A vector to store the resultant transformation sequence.
        vector<vector<string>> ans;
        while (!q.empty())
        {
            vector<string> vec = q.front();
            q.pop();

            // Now, erase all words that have been
            // used in the previous levels to transform
            if (vec.size() > level)
            {
                level++;
                for (auto it : usedOnLevel)
                {
                    st.erase(it);
                }
            }

            string word = vec.back();

            // store the answers if the end word matches with targetWord.
            if (word == endWord)
            {
                // the first sequence where we reached end
                if (ans.size() == 0)
                {
                    ans.push_back(vec);
                }
                else if (ans[0].size() == vec.size())
                {
                    ans.push_back(vec);
                }
            }
            for (int i = 0; i < word.size(); i++)
            {   
                // Now, replace each character of ‘word’ with char
                // from a-z then check if ‘word’ exists in wordList.
                char original = word[i];
                for (char c = 'a'; c <= 'z'; c++)
                {
                    word[i] = c;
                    if (st.count(word) > 0)
                    { 
                        // Check if the word is present in the wordList and
                        // push the word along with the new sequence in the queue.
                        vec.push_back(word);
                        q.push(vec);
                        // mark as visited on the level
                        usedOnLevel.push_back(word);
                        vec.pop_back();
                    }
                }
                word[i] = original;
            }
        }
        return ans;
    }
};



DIJKSTRA ALGORITHM USING PRIORITY QUEUE
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(V);
        for(int i = 0; i<V; i++){
            dist[i] = 1e9;
            
        }
        dist[S] = 0;
        pq.push({0, S});
        while(!pq.empty()){
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adj[node]){
                int edgeWt = it[1];
                int adjNode = it[0];
                
                if(dis + edgeWt < dist[adjNode]){
                    dist[adjNode] = dis + edgeWt;
                    pq.push({dist[adjNode], adjNode});
                }
                
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends


DIJKSTRA USING SET
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        set<pair<int, int>> st;
        vector<int> dist(V, 1e9);
        dist[S] = 0;
        st.insert({0, S});
        while(!st.empty()){
            auto it = *(st.begin());
            int node = it.second;
            int dis = it.first;
            st.erase(it);
            
            for(auto it:adj[node]){
                int adjNode = it[0];
                int edgeWt = it[1];
                
                if(dis + edgeWt < dist[adjNode]){
                    if(dist[adjNode] != 1e9){
                        st.erase({dist[adjNode], adjNode});
                    }
                    dist[adjNode] = dis + edgeWt;
                st.insert({dist[adjNode], adjNode});
                }
                
            }
        }
        return dist;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends




SHORTEST PATH IN WEIGHTED UNDIRECTED GRAPH
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int, int>> adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
            
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
        pq.push({0, 1});
        vector<int> dist(n+1, 1e9), parent(n+1);
        dist[1] = 0;
        for(int i = 1; i<= n; i++){
            parent[i] = i;
        }
        while(!pq.empty()){
            // pq me {dist, node} store h
            auto it = pq.top();
            pq.pop();
            int node = it.second;
            int dis = it.first;
            
            for(auto it:adj[node]){
                int adjnode = it.first;
                int edgewt = it.second;
                if(dis + edgewt < dist[adjnode]){
                    dist[adjnode] = dis + edgewt;
                    pq.push({dis + edgewt, adjnode});
                    parent[adjnode] = node;
                }
            }
        }
        if(dist[n] == 1e9) return {-1};
        vector<int> path;
        int node = n;
        while(parent[node] != node){
            path.push_back(node);
            node = parent[node];
            
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends




SHORTEST SOURCE TO DESTINATION PATH IN A BINARY MAZE
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> A, int X, int Y) {
        // code here
        if(A[0][0] == 0 || A[X][Y] == 0) return -1;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        int n = A.size();
        int m = A[0].size();
        vector<int> delrow = {-1, 0, 1, 0};
        vector<int> delcol = {0,1,0,-1};
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        while(!q.empty()){
            // q me {distance, {row, col}} is form me h
            auto it = q.front();
            int row = it.second.first;
            int col = it.second.second;
            int dis = it.first;
            q.pop();
            
            for(int i = 0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];
                
                if(nrow >= 0 && ncol >= 0 && ncol < m && nrow < n && dist[nrow][ncol] == 1e9 && A[nrow][ncol] == 1){
                    dist[nrow][ncol] = 1 + dis;
                    if(nrow == X && ncol == Y) return 1 + dis;
                    q.push({1 + dis, {nrow, ncol}});
                    
                }
            }
            
            
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    }
}
// } Driver Code Ends



PATH WITH MINIMUM EFFORT
class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>>
            pq;
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int>(m, 1e9));
        dist[0][0] = 0;
        pq.push({0, {0, 0}});
        vector<int> delrow = {-1, 0 ,1, 0};
        vector<int> delcol = {0, 1, 0, -1};
        while(!pq.empty()){
            // pq is of the form ({difference}, {row, col});
            auto it = pq.top();
            pq.pop();
            int row = it.second.first;
            int col = it.second.second;
            int diff = it.first;

            if(row == n-1 && col == m-1) return diff;
            for(int i = 0; i<4; i++){
                int nrow = row + delrow[i];
                int ncol = col + delcol[i];

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m){
                    int neweffort = max(diff, abs(heights[nrow][ncol] - heights[row][col]));
                    if(neweffort < dist[nrow][ncol]){
                        dist[nrow][ncol] = neweffort;
                        pq.push({neweffort, {nrow, ncol}});
                    }
                }

            }
        }
        return 0;
        
    }
};



CHEAPEST FLIGHTS WITHIN K STOPS
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>> adj[n];
        for(auto it:flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        queue<pair<int, pair<int, int>>> q;
        // q is of the form {stops, {node, dist}}
        q.push({0, {src, 0}});
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        while(!q.empty()){
            // q is of the form {stops, {node, dist}}
            auto it = q.front();
            q.pop();
            int stops = it.first;
            int node = it.second.first;
            int cost = it.second.second;


            if(stops > k){
                continue;
            }
            for(auto it : adj[node]){
                int adjnode = it.first;
                int edgewt = it.second;
                if(cost + edgewt < dist[adjnode] && stops <= k){
                    dist[adjnode] = cost + edgewt;
                    q.push({stops + 1, {adjnode, cost + edgewt}});
                }
            }
        }
        if(dist[dst] == 1e9) return -1;
        return dist[dst];
        
    }
};


BOMB DETONATION
#define ll long long int
class Solution {
public:
    void dfs(vector<vector<int>> &graph, vector<bool>&visited, int &cnt, int &node){
        visited[node] = true;
        cnt++;
        for(int j = 0; j<graph[node].size(); j++){
            if(!visited[graph[node][j]]){
                dfs(graph, visited, cnt, graph[node][j]);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);
        for(int i = 0; i<n; i++){
            ll x1 = bombs[i][0];
            ll y1 = bombs[i][1];
            ll r1 = bombs[i][2];
            for(int j = 0; j<n; j++){
                if(i != j){
                    ll x = abs(x1 - bombs[j][0]);
                    ll y = abs(y1 - bombs[j][1]);
                    if(x*x + y*y <= r1*r1){
                        graph[i].push_back(j);
                    }
                }
            }
        }
        int ans = 0;
        for(int i =0; i<n; i++){
            int cnt = 0;
            vector<bool> visited(n, false);
            dfs(graph, visited, cnt, i);
            ans = max(ans, cnt);
        }
        return ans;
        
    }
};


MINIMUM STEPS TO REACH END
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        queue<pair<int, int>> q;
        q.push({start, 0});
        vector<int> dist(100000, 1e9);
        dist[start] = 0;
        int mod = 100000;
        while(!q.empty()){
            auto it = q.front();
            int node = it.first;
            int steps = it.second;
            q.pop();
            
            
            for(auto i : arr){
                int num = (i * node) % mod;
                if(steps + 1 < dist[num]){
                    dist[num] = steps + 1;
                    if(num == end) return steps+1;
                    q.push({num, steps+1});
                }
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        int start, end;
        cin >> start >> end;
        Solution obj;
        cout << obj.minimumMultiplications(arr, start, end) << endl;
    }
}

// } Driver Code Ends



BELLMAN FORD ALGORITHM
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++


    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        // Code here
        vector<int> dist(V, 1e8);
        dist[S] = 0;
        for(int i = 0; i<V; i++){
            for(auto it:edges){
                int u = it[0];
                int v = it[1];
                int wt = it[2];
                
                if(dist[u] !=  1e8 && dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        // nth relaxation to chekc negative cycle
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int wt = it[2];
                
            if(dist[u] !=  1e8 && dist[u] + wt < dist[v]){
                dist[v] = dist[u] = wt;
                return {-1};
            }
        }
        
        return dist;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, m;
        cin >> N >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src;
        cin >> src;

        Solution obj;
        vector<int> res = obj.bellman_ford(N, edges, src);

        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends


FLOYDWARSHALL ALGORITHM
//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    // Code here
	    int n = matrix.size();
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<n; j++){
	            if(matrix[i][j] == -1){
	                matrix[i][j] = 1e9;
	            }
	        }
	    }
	    for(int i = 0; i<n; i++){
	        matrix[i][i] = 0;
	    }
	    for(int via = 0; via < n; via++){
	        for(int i = 0; i<n; i++){
	            for(int j = 0; j<n; j++){
	                matrix[i][j] = min(matrix[i][j] , matrix[i][via] + matrix[via][j]);
	            }
	        }
	    }
	    for(int i = 0; i<n; i++){
	        for(int j = 0; j<n; j++){
	            if(matrix[i][j] == 1e9){
	                matrix[i][j] = -1;
	            }
	        }
	    }
        // just add these lines if we have been asked to detect negative cycles;
        //for(int i = 0 ;  i<n; i++){
           // if(mat[i][i] < 0){
               // return cycle hai 
            //}
        //}
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<vector<int>>matrix(n, vector<int>(n, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cin >> matrix[i][j];
			}
		}
		Solution obj;
		obj.shortest_distance(matrix);
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << matrix[i][j] << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends

 FIND THE CITY WITH THE SMALLEST NUMBER  OF THRESHOLD
 class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int m = edges[0].size();
        vector<vector<int>> dist(n, vector<int>(n, 1e8));
        for(auto it:edges){
            dist[it[0]][it[1]] = it[2];
            dist[it[1]][it[0]] = it[2];

        }
        for(int i = 0; i<n; i++) dist[i][i] = 0;
        for(int via=0; via < n; via++){
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    if(dist[i][via] == 1e8 || dist[via][j] == 1e8){
                        continue;
                    }
                    dist[i][j] = min(dist[i][j], dist[i][via] + dist[via][j]);
                }
            }

        }
        int cntcity = n;
        int cityno = -1;
        for(int city = 0; city < n; city++){
            int cnt = 0;
            for (int adjCity = 0; adjCity < n; adjCity++) {
				if (dist[city][adjCity] <= distanceThreshold)
					cnt++;
			}

			if (cnt <= cntcity) {
				cntcity = cnt;
				cityno = city;
			}
        }
        return cityno;
        
    }
};


*/