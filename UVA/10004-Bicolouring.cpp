#include <stdio.h>
#include <vector>
const int MAXNODES = 201;
int visited [MAXNODES];
int coloured [MAXNODES];
bool dfs(std::vector<std::vector<int> > graph, int node) {

	visited[node] = 1;
	for(int i=0;i<graph[node].size();i++) {
		int neighbour;
		neighbour = graph[node][i];
		if(visited[neighbour] == -1) {
			coloured[neighbour] = (coloured[node]+1)%2;
			dfs(graph,neighbour);
		}

		if(coloured[neighbour] == coloured[node]) {
			return false;
		} 
	}
	return true;

}

int main(void) {

	while(1) {
	std::vector<std::vector<int> > graph;
	int nodes,edges;
	scanf("%d",&nodes);
	if(nodes == 0) break;
	scanf("%d",&edges);

	graph = std::vector<std::vector<int> >(nodes);
	for(int i=0;i<edges;i++) {

		int a,b;
		scanf("%d %d",&a,&b);
		
		if(a < nodes && 0 <= a && b < nodes && 0 <= b) {
			graph[a].push_back(b);
			graph[b].push_back(a);

		}
		
	}

	for(int i=0;i<nodes;i++) {
		coloured[i] = -1;
		visited[i] = -1;
	}
	
	int startNode = graph.front().front();
	coloured[startNode] = 0;
	bool isBicolourable = dfs(graph, startNode);
	if(isBicolourable) {
		printf("BICOLORABLE.\n");
	}else{
		printf("NOT BICOLORABLE.\n");
	}
	
	
	}
	
	return 0;

}
