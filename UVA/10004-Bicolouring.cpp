#include <stdio.h>
#include <vector>
#define MAXNODES 20;
int[MAXNODES] visited;
int[MAXNODES] coloured;
bool dfs(vector<vector<int>> graph, int node) {

	visited[node] = 1;
	for(int i=0;i<graph[node].size();i++) {
		int neighbour;
		neighbour = graph[node][i];
		if(visited[neighbour] == 0) {
			dfs(graph,neighbour);
		}else if(coloured[neighbour] == coloured[node]) {
			return false;
		}
	}
	return true;

}

int main(void) {

	while(1) {
	vector<vector<int>> graph;
	int nodes,edges;
	scanf("%d\n%d",&nodes,&edges);
	if(nodes == 0) break;

	graph = vector<vector<int>>(nodes);
	for(int i=0;i<edges;i++) {

		int a,b;
		scanf("%d %d",&a,&b);
		graph[a].push_back(b);
		graph[b].push_back(a);

	}
	bool isBicolourable = dfs(graph, 0);
	if(isBicolourable) {
		printf("BICOLOURABLE");
	}else {
		printf("NOT BICOLOURABLE");
	}
	
	}
	return 0;

}
