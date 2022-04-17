//https://practice.geeksforgeeks.org/problems/steps-by-knight5927/1

int minStepToReachTarget(vector<int>&pos,vector<int>&tar,int n)
	{
	    // Code here
	    int mat[n+1][n+1]={0};
	    
	    queue<pair<int, int>> q;
	    
	    q.push({pos[0], pos[1]});
	    int sum= 0;
	    while(!q.empty()){
	        int a = q.front().first;
	        int b = q.front().second;
	        q.pop();
	        sum = mat[a][b] + 1;
	        if(a == tar[0] && b == tar[1])
	            break;
	        if(a+1<=n && b-2>0 && mat[a+1][b-2]==0){
	            q.push({a+1, b-2});
	            mat[a+1][b-2] = sum;
	        }
	        if(a-1>0 && b-2>0 && mat[a-1][b-2]==0){
	            q.push({a-1, b-2});
	            mat[a-1][b-2] = sum;
	        }
	        
	        if(a+1<=n && b+2<=n && mat[a+1][b+2]==0){
	            q.push({a+1, b+2});
	            mat[a+1][b+2] = sum;
	        }
	        if(a-1>0 && b+2<=n && mat[a-1][b+2]==0){
	            q.push({a-1, b+2});
	            mat[a-1][b+2] = sum;
	        }
	        
	        
	        if(a-2>0 && b-1>0 && mat[a-2][b-1]==0){
	            q.push({a-2, b-1});
	            mat[a-2][b-1] = sum;
	        }
	        if(a-2>0 && b+1<=n && mat[a-2][b+1]==0){
	            q.push({a-2, b+1});
	            mat[a-2][b+1] = sum;
	        }
	        if(a+2<=n && b-1>0 && mat[a+2][b-1]==0){
	            q.push({a+2, b-1});
	            mat[a+2][b-1] = sum;
	        }
	        if(a+2<=n && b+1<=n && mat[a+2][b+1]==0){
	            q.push({a+2, b+1});
	            mat[a+2][b+1] = sum;
	        }   
	    }
	    
	    return sum-1;
	}
