queue<int> q;
	    vector<int> indegree(V,0);
	    for(int i = 0; i < V; i++){
	        for(int j = 0; j < adj[i].size(); j++){
	            indegree[adj[i][j]]++;
	        }
	    }
	    for(int i = 0; i < V; i++){
	        if(indegree[i] == 0){
	            q.push(i);
	        }
	    }
	    vector<int> res;
	    while(!q.empty()){
	        int a = q.front();
	        res.push_back(a);
	        q.pop();
	        for(auto &i : adj[a]){
	            indegree[i]--;
	            if(indegree[i] == 0){
	                q.push(i);
	            }
	        }
	    }
	    return res;
