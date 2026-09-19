#include <bits/stdc++.h>
using namespace std;

// Main logic of the dijkstra algorithm
// 1. Learn / Build Graph
// 2. Implement Dijkstra 
// 3. Reconstruct Path(parent)
// 4. Real Station Names

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
            if(dist[i]==0){
                q.push({0,i});
            }
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
                    parent[node_val]=s_val;
                }
                q.push({dist[s_val]+node_wt,node_val});
            }
        }
        
    }

    void helper_constract_path(vector<int>& parent,int dist,stack<int>& st){
        if(parent[dist]==-1) return;
        st.push(parent[dist]);
        helper_constract_path(parent,parent[dist],st);
    }

    void constract_path(vector<int>& parent,int dist){
        stack<int> st;
        st.push(dist);
        helper_constract_path(parent,dist,st);

        while (st.size()!=0){
            cout<<st.top();
            st.pop();
            if(st.size()!=0) cout<<"-->";
        }
    }
};

int main(){
    // cout<<"hello"<<endl;
    Graph g(6);
    vector<int> dist(g.V,INT_MAX);
    dist[0]=0;           //sourse to source distance is 0
    vector<int> parent(g.V,-1);
    unordered_map<string,int> stations;

    string st_name="";

    stations["kelogoda"]=0;
    stations["panchgechia"]=1;
    stations["barasot"]=2;
    stations["kachari"]=3;
    stations["gochhati"]=4;
    stations["sonakhali"]=5;


    g.addEdge(0,1,2);    //  0 --> 1(2)
    g.addEdge(0,2,4);    //  0 --> 2(4)
    g.addEdge(1,2,1);    //  1 --> 2(1)
    g.addEdge(1,3,7);    //  1 --> 3(7)
    g.addEdge(2,4,3);    //  2 --> 4(3)
    g.addEdge(4,3,2);    //  4 --> 3(2)
    g.addEdge(3,5,1);    //  3 --> 5(1)
    g.addEdge(4,5,5);    //  4 --> 5(5)

    g.dijkstra(dist,parent);

    cout<<"Distances:"<<endl;
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }
    
    cout<<endl;
    // cout<<"Parents:"<<endl;
    // for(int i=0;i<parent.size();i++){
    //     cout<<parent[i]<<" ";
    // }
    // cout<<endl;
    // for(int i=0;i<dist.size();i++){
    //     cout<<i<<" ";
    // }

    // g.constract_path(parent,3);

    while(true){
        cout<<"\nAvalable stations:"<<endl;
        cout<< "0. Kelegoda(src)"<<endl;
        cout<< "1. Panchgechia"<<endl;
        cout<< "2. Barosot"<<endl;
        cout<< "3. Kachari"<<endl;
        cout<< "4. Gochhati"<<endl;
        cout<< "5. Sonakhali"<<endl;

        cout<<"Chose one station name to see ditance:";
        cin>>st_name;

        g.constract_path(parent,stations[st_name]);
    }
    return 0;
}