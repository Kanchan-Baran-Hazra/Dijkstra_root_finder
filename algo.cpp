#include <bits/stdc++.h>
using namespace std;

// Main logic of the dijkstra algorithm
// 1. Learn / Build Graph
// 2. Implement Dijkstra 
// 3. Reconstruct Path(parent)
// 4. Real Station Names
// 6. C++ CSV Loader

// create graph
class Graph{
    public:
    int V;
    vector<vector<pair<int,pair<float,float>>>> edge;

    Graph(int n){
        this->V=n;
        this->edge.resize(n);
    }

    void addEdge(int u,int v,float dist,float time){
        edge[u].push_back({v,{dist,time}});
        edge[v].push_back({u,{dist,time}});
    }

    void dijkstra(vector<float>& dist,vector<int>& parent,int src,vector<float>& time_t){
        // distance,time,node
        priority_queue<pair<float,pair<float,int>>,vector<pair<float,pair<float,int>>>,greater<pair<float,pair<float,int>>>> q;
        

        for(int i=0;i<dist.size();i++){
            if(dist[i]==0){
                q.push({0,{0,i}});
            }
        }

        while (q.size()!=0){
            pair<float,pair<float,int>> el=q.top();
            q.pop();

            float s_wt=el.first;
            pair<float,int> sec=el.second;
            int s_val=sec.second;
            int time=sec.first;

            for(int i=0;i<edge[s_val].size();i++){
                pair<int,pair<float,float>> node=edge[s_val][i];

                pair<float,float> costs=node.second;
                float node_wt=costs.first;
                float node_time=costs.second;
                int node_val=node.first;

                if(dist[node_val]>dist[s_val]+node_wt){   // edge relaxation stape
                    dist[node_val]=dist[s_val]+node_wt;
                    time_t[node_val]=time_t[s_val]+node_time;
                    parent[node_val]=s_val;
                    q.push({dist[s_val]+node_wt,{node_time,node_val}});
                }
            }
        }
        
    }

    void helper_constract_path(vector<int>& parent,int dist,stack<int>& st){
        if(parent[dist]==-1) return;
        st.push(parent[dist]);
        helper_constract_path(parent,parent[dist],st);
    }

    void constract_path(vector<int>& parent,int dist,unordered_map<string,int>& stations){
        stack<int> st;
        st.push(dist);
        helper_constract_path(parent,dist,st);

        while (st.size()!=0){
            // cout<<st.top();
            for(auto x:stations){
                if(x.second==st.top())
                cout<<x.first;
            }
            st.pop();
            if(st.size()!=0) cout<<"-->";
        }
    }
};

int main(){
    // cout<<"hello"<<endl;
    string src="kelogoda";
    cout<<"Enter src:";
    cin>>src;

    Graph g(6);                        // 88 node ->>88
    vector<float> dist(g.V,INT_MAX);
    vector<float> time_t(g.V,INT_MAX);
    // dist[stations[src]]=0;           //sourse to source distance is 0
    vector<int> parent(g.V,-1);
    unordered_map<string,int> stations;

    string st_name="";

    stations["kelogoda"]=0;
    stations["panchgechia"]=1;
    stations["barasot"]=2;
    stations["kachari"]=3;
    stations["gochhati"]=4;
    stations["sonakhali"]=5;
    
    
    dist[stations[src]]=0;
    time_t[stations[src]]=0;

    g.addEdge(0,1,2.2,5);    //  0 --> 1(2)
    g.addEdge(0,2,4.1,7);    //  0 --> 2(4)
    g.addEdge(1,2,1.1,3);    //  1 --> 2(1)
    g.addEdge(1,3,7.5,10);    //  1 --> 3(7)
    g.addEdge(2,4,3.6,5.5);    //  2 --> 4(3)
    g.addEdge(4,3,2.1,7);    //  4 --> 3(2)
    g.addEdge(3,5,1.1,9);    //  3 --> 5(1)
    g.addEdge(4,5,5.1,4.9);    //  4 --> 5(5)

    
    g.dijkstra(dist,parent,stations[src],time_t);

    cout<<"Distances:"<<endl;
    for(int i=0;i<dist.size();i++){
        cout<<dist[i]<<" ";
    }

    cout<<"\nTimes:"<<endl;
    for(int i=0;i<time_t.size();i++){
        cout<<time_t[i]<<" ";
    }
    
    cout<<endl;

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
        cout<<"Cost:"<<dist[stations[st_name]]<<endl;

        g.constract_path(parent,stations[st_name],stations);
    }
    return 0;
}