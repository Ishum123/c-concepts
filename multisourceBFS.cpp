//Approach use din question: https://practice.geeksforgeeks.org/problems/distance-of-nearest-cell-having-1-1587115620/1#

//Traversing in four directions.
    vector<vector<int>> dir={{0,1},{1,0},{0,-1},{-1,0}};
    
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    //Multisource BFS
	    int m=grid.size();
	    int n=grid[0].size();
	    
	    vector<vector<int>> res(m,vector<int>(n,INT_MAX));
	    
	    queue<pair<int,int>> q;
	    
	    for(int i=0;i<m;i++){
	        for(int j=0;j<n;j++){
	            if(grid[i][j]){
	                res[i][j]=0;
	                q.push({i,j});
	            }
	        }
	    }
	    
	    while(!q.empty()){
	        int x=q.front().first;
	        int y=q.front().second;
	        
	        q.pop();
	        
	        for(auto d:dir){
	            int i=x+d[0];
	            int j=y+d[1];
	            
	            if(i>=0 and j>=0 and i<m and j<n){
	                if(res[i][j]> res[x][y]+1){
	                    res[i][j]=res[x][y]+1;
	                    q.push({i,j});
	                }
	            }
	        }
	    }
	    return res;
	}

