#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ipair;
#define INF 0x3f3f3f3f
class graph{
	int V;
	list<ipair> *adj;
	public:
		graph(int V);
		void addedge(int v,int u,int w);
		void primmst();	
};
graph::graph(int V){
	this->V=V;
	adj=new list<ipair>[V];
}
void graph::addedge(int v,int u,int w){
	adj[v].push_back(make_pair(u,w));
	adj[u].push_back(make_pair(v,w));
}
void graph::primmst(){
	
	int cnt=0;
	priority_queue<ipair,vector<ipair>,greater<ipair> > pq;
	int src=0;
	vector<int>key(V,INF);
	vector<int>parent(V,-1);
	vector<bool>inmst(V,false);
	pq.push(make_pair(src,0));
	
	key[src]=0;
	while(cnt<V){cnt++;
			
		int u=pq.top().first;
		pq.pop();
		inmst[u]=true;
		list<ipair>::iterator i;
		for(i=adj[u].begin();i!=adj[u].end();i++){ 
			
			int v=(*i).first;
			int w=(*i).second;
			if(inmst[v]==false&&key[v]>w){
				key[v]=w;
				pq.push(make_pair(v,key[v]));
				parent[v]=u;
			}
		}
	}
	
	for(int j=1;j<V;j++)
	printf("%d-%d\n",parent[j],j);
}
int main(){
	int n,u,v,w,i,e;
	cout<<"enter the number of vertices and edges ";
	cin>>n>>e;
	graph g(n);
	cout<<"enter th edge and weighet :\n";
	for(i=0;i<e;i++){
		cin>>u>>v>>w;
		g.addedge(u,v,w);		
	}
	g.primmst();
	return 0;
}
