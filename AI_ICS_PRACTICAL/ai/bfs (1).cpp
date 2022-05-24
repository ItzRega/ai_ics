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

	void bfs(T src){
		map<T,int> visited;		//visited array 		
		queue<T> q;				//queue DS 

		q.push(src);
		visited[src] = true;	//as node enter it will sure come out
		// prevent getting node getting queued again by other node
		while(!q.empty()){
			T node = q.front();
			q.pop();

			cout << node << " ";

			for(int nbr:l[node]){	//finding neighbour
				// l[node] gives values of that node(value = adhacency list)
				if(!visited[nbr]){
					q.push(nbr);
					// mark that nbr visited
					visited[nbr] = true;
				}
			}
		}


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

	g.bfs(2);

	return 0;
}