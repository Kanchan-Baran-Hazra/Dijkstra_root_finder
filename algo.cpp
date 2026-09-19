#include <bits/stdc++.h>
using namespace std;

// Main logic of the dijkstra algorithm
// 1. Learn / Build Graph
// 2. Implement Dijkstra 
// 3. Reconstruct Path(parent)

// create graph
class Graph{
    public:
    int V;
    vector<vector<pair<int,int>>> edge;

    Graph(int n){
        this->V=n;
        this->edge.resize(n);
    }

    void addEdge(int u,int v,int dist){
        edge[u].push_back({v,dist});
    }

    void dijkstra(vector<int>& dist,vector<int>& parent){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
        

        for(int i=0;i<dist.size();i++){
            if(dist[i]==0) q.push({0,i});
        }

        while (q.size()!=0){
            pair<int,int> el=q.top();
            q.pop();

            int s_wt=el.first;
            int s_val=el.second;

            for(int i=0;i<edge[s_val].size();i++){
                pair<int,int> node=edge[s_val][i];

                int node_wt=node.second;
                int node_val=node.first;

                if(dist[node_val]>dist[s_val]+node_wt){   // edge relaxation stape
                    dist[node_val]=dist[s_val]+node_wt;
                }
                q.push({dist[s_val]+node_wt,node_val});
            }
        }
        
    }
};

int main(){
    // cout<<"hello"<<endl;
    Graph g(6);
    vector<int> dist(g.V,INT_MAX);
    dist[0]=0;           //sourse to source distance is 0
    vector<int> parent(g.V,-1);


    g.addEdge(0,1,2);    //  0 --> 1(2)
    g.addEdge(0,2,4);    //  0 --> 2(4)
    g.addEdge(1,2,1);    //  1 --> 2(1)
    g.addEdge(1,3,7);    //  1 --> 3(7)
    g.addEdge(2,4,3);    //  2 --> 4(3)
    g.addEdge(4,3,2);    //  4 --> 3(2)
    g.addEdge(3,5,1);    //  3 --> 5(1)
    g.addEdge(4,5,5);    //  4 --> 5(5)

    g.dijkstra(dist,parent);

    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    return 0;
}