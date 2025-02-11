//Cycle Detection in undirected graphs using BFS...
#include<unordered_map>
#include<queue>
#include<list>

bool isCyclicBFS(int src,unordered_map<int, bool>&visited,
unorderd_map<int, list<int> >&adj, unordered_map<int,int> parent) 
{
	parent[src] = -1;
	visited[src] = 1;
	queue<int> q;
	q.push(src);
	
	while(!q.empty) {
		int front = q.front();
		q.pop();
		
		for(auto neighbour: adj[front]) {
			if(visited[neighbour] == true && neighbour != parent[front]) 
			{
				return true;
			}
			else if(!visited[neigbour]) 
			{
				q.push(neighbour);
				visited[neibhour] = 1;
				parent[neighbour] = front;
			}
		}
	}
	return false;
}



string cycleDetection (vector<vector<int>& edges, int n, int m) {
	//create adjacency list
	unorderd_map<int, list<int> >adj;
	for(int i=0; i<m; i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	//to handle disconnected components
	for( int i=0; i<n; i++) {
		if(!visited[i]) 
		{
			bool ans = isCyclicBFS(i, visited, adj);
			if(ans == 1)
			return "Yes";
		}
	}
	return "No";
}
//t.c: linear

//Cycle Detection in undirected graphs using DFS...

bool isCyclicDFS(int node, int parent, unordered_map<int,bool>&visited,
unoredered_map<int, list<int> >&adj){
	visited[node] = true;
	
	for(auto neighbour: adj[node]) {
		if(!visited[neighbour]) {
		
		bool cycleDetected = isCyclicDFS(neihbour, node, visited, adj);//rec call
		if(cycleDetected) 
		return true;
	}
	else if(neighbour!=parent) {
		//cycle present
		return true;
	}
}
return false;
}


string cycleDetection (vector<vector<int>& edges, int n, int m) {
	//create adjacency list
	unorderd_map<int, list<int> >adj;
	for(int i=0; i<m; i++) {
		int u = edges[i][0];
		int v = edges[i][1];
		
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	//to handle disconnected components
	for( int i=0; i<n; i++) {
		if(!visited[i]) 
		{
			bool ans = isCyclicDFS(i, -1, visited, adj);
			if(ans == 1)
			return "Yes";
		}
	}
	return "No";
}
