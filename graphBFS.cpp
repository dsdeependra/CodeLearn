#include<iostream>
#include<list>

using namespace std;

class Graph{
	int V;
	list<int>*adj;
	public:
		Graph(int V);
		void addEdge(int v, int w);
		void BFS(int s);
};

Graph::Graph(int V){
	this->V = V;
	adj = new list<int>[V];
}

void Graph:: addEdge(int v, int w){
	adj[v].push_back(w);
}

void Graph:: BFS(int s){
	bool visited[V];
	for(int i=0;i<V;i++){
		visited[i] = false;
	}
	list<int>q; //queue to to BFS
	q.push_back(s);

	list<int>::iterator it;
	while(!q.empty()){
		s = q.front();
		cout<<s<<" ";
		q.pop_front();
		//all the adjacent element of s needs to be visited and pushed to queue
		for(it = adj[s].begin();it != adj[s].end();++it){
			if(visited[*it] == false){
				visited[*it] = true;
				q.push_back(*it);
			}
		}
	}

}



int main(){
	Graph g(5);
	g.addEdge(1,2);
	g.addEdge(1,3);
	g.addEdge(2,4);
	g.addEdge(2,3);
	g.addEdge(4,5);
	g.addEdge(5,3);

	cout<<"THE BFS traversal is"<<endl;

	g.BFS(1);
}