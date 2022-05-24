#include<iostream>
#include<map>
#include<queue>
#include<list>
using namespace std;

template<typename T>
class Graph{

	map<T,list<T> > l;			// 2->(1,3) 2=key & (1,3)=value 
	//adjacency list

public:
	void addEdge(int x, int y){
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void dfs_helper(T src, map<T, bool> &visited){	// since this map should remain same in all the function calls we use &visited(using reference)
		// func to traverse the graph

		cout << src << " ";
		visited[src] = true;

		for(T nbr : l[src]){
			if(!visited[nbr]){
				dfs_helper(nbr, visited);
			}
		}
		return;
	}

	void dfs(T src){
		map<T,bool> visited;

		// mark all node as not visited
		for(auto p : l){
			T node = p.first;
			visited[node] = false;
		}

		// call the helper function
		dfs_helper(src,visited);

	}

};

int main(){
	Graph<int> g;

	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);

	g.dfs(2);

	return 0;
}