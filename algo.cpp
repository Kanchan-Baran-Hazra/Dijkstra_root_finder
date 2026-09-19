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
    vector<vector<pair<int,float>>> edge;

    Graph(int n){
        this->V=n;
        this->edge.resize(n);
    }

    void addEdge(int u,int v,float dist){
        edge[u].push_back({v,dist});
        edge[v].push_back({u,dist});
    }

    void dijkstra(vector<int>& dist,vector<int>& parent,int src){
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
                pair<int,float> node=edge[s_val][i];

                int node_wt=node.second;
                int node_val=node.first;

                if(dist[node_val]>dist[s_val]+node_wt){   // edge relaxation stape
                    dist[node_val]=dist[s_val]+node_wt;
                    parent[node_val]=s_val;
                    q.push({dist[s_val]+node_wt,node_val});
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
    Graph g(88);                        // 88 node ->>88
    vector<int> dist(g.V,INT_MAX);
    // dist[stations[src]]=0;           //sourse to source distance is 0
    vector<int> parent(g.V,-1);
    unordered_map<string,int> stations;

    string st_name="";

    // stations["kelogoda"]=0;
    // stations["panchgechia"]=1;
    // stations["barasot"]=2;
    // stations["kachari"]=3;
    // stations["gochhati"]=4;
    // stations["sonakhali"]=5;

    stations["Airport_(CCU)"]=0;
    stations["Alipore"]=1;
    stations["Alipurduar"]=2;
    stations["Asansol"]=3;
    stations["BBD_Bagh"]=4;
    stations["Bakkhali"]=5;
    stations["Bally"]=6;
    stations["Ballygunge"]=7;
    stations["Balurghat"]=8;
    stations["Bandel"]=9;
    stations["Bankura"]=10;
    stations["Barasat"]=11;
    stations["Bardhaman"]=12;
    stations["Barrackpore"]=13;
    stations["Basirhat"]=14;
    stations["Behala"]=15;
    stations["Belur_Math"]=16;
    stations["Berhampore"]=17;
    stations["Bhowanipore"]=18;
    stations["Bishnupur"]=19;
    stations["Bolpur_Santiniketan"]=20;
    stations["Canning"]=21;
    stations["Chandannagar"]=22;
    stations["Chinsurah"]=23;
    stations["College_Street"]=24;
    stations["Cooch_Behar"]=25;
    stations["Dankuni"]=26;
    stations["Darjeeling"]=27;
    stations["Dhakuria"]=28;
    stations["Diamond_Harbour"]=29;
    stations["Digha"]=30;
    stations["Dum_Dum"]=31;
    stations["Durgapur"]=32;
    stations["Esplanade"]=33;
    stations["Farakka"]=34;
    stations["Garden_Reach"]=35;
    stations["Garia"]=36;
    stations["Gariahat"]=37;
    stations["Girish_Park"]=38;
    stations["Habra"]=39;
    stations["Haldia"]=40;
    stations["Hazra"]=41;
    stations["Howrah_Station"]=42;
    stations["Islampur"]=43;
    stations["Jadavpur"]=44;
    stations["Jalpaiguri"]=45;
    stations["Jhargram"]=46;
    stations["Kakdwip"]=47;
    stations["Kalighat"]=48;
    stations["Kalimpong"]=49;
    stations["Kalyani"]=50;
    stations["Kharagpur"]=51;
    stations["Khidirpur"]=52;
    stations["Krishnanagar"]=53;
    stations["Kurseong"]=54;
    stations["MG_Road_Kolkata"]=55;
    stations["Madhyamgram"]=56;
    stations["Malda_Town"]=57;
    stations["Mandarmani"]=58;
    stations["Midnapore"]=59;
    stations["Mirik"]=60;
    stations["Murshidabad"]=61;
    stations["Nabadwip"]=62;
    stations["Naihati"]=63;
    stations["New_Alipore"]=64;
    stations["New_Town_Action_Area_1"]=65;
    stations["New_Town_Action_Area_2"]=66;
    stations["Park_Street"]=67;
    stations["Purulia"]=68;
    stations["Rabindra_Sadan"]=69;
    stations["Raghunathpur"]=70;
    stations["Raiganj"]=71;
    stations["Rajarhat"]=72;
    stations["Rampurhat"]=73;
    stations["Raniganj"]=74;
    stations["Ruby_Crossing"]=75;
    stations["Salt_Lake_Karunamoyee"]=76;
    stations["Salt_Lake_Sector_5"]=77;
    stations["Science_City"]=78;
    stations["Sealdah_Station"]=79;
    stations["Serampore"]=80;
    stations["Shambazar"]=81;
    stations["Siliguri"]=82;
    stations["Sodepur"]=83;
    stations["Suri"]=84;
    stations["Taratala"]=85;
    stations["Tollygunge"]=86;
    stations["Ultadanga"]=87;
    
    
    dist[stations[src]]=0;


    // g.addEdge(0,1,2);    //  0 --> 1(2)
    // g.addEdge(0,2,4);    //  0 --> 2(4)
    // g.addEdge(1,2,1);    //  1 --> 2(1)
    // g.addEdge(1,3,7);    //  1 --> 3(7)
    // g.addEdge(2,4,3);    //  2 --> 4(3)
    // g.addEdge(4,3,2);    //  4 --> 3(2)
    // g.addEdge(3,5,1);    //  3 --> 5(1)
    // g.addEdge(4,5,5);    //  4 --> 5(5)

    // g.addEdge(0,1,2.2);    //  0 --> 1(2)
    // g.addEdge(0,2,4.1);    //  0 --> 2(4)
    // g.addEdge(1,2,1.1);    //  1 --> 2(1)
    // g.addEdge(1,3,7.5);    //  1 --> 3(7)
    // g.addEdge(2,4,3.6);    //  2 --> 4(3)
    // g.addEdge(4,3,2.1);    //  4 --> 3(2)
    // g.addEdge(3,5,1.1);    //  3 --> 5(1)
    // g.addEdge(4,5,5.1);    //  4 --> 5(5)

    g.addEdge(0,11,11.23);
    g.addEdge(0,31,8.58);
    g.addEdge(0,56,6.3);
    g.addEdge(0,65,11.39);
    g.addEdge(0,87,12.46);
    g.addEdge(1,15,5.38);
    g.addEdge(1,69,2.44);
    g.addEdge(2,25,24.58);
    g.addEdge(2,45,93.75);
    g.addEdge(3,68,86.78);
    g.addEdge(3,70,41.42);
    g.addEdge(3,74,22.42);
    g.addEdge(4,33,1.4);
    g.addEdge(4,42,1.76);
    g.addEdge(4,52,5.94);
    g.addEdge(4,55,1.76);
    g.addEdge(4,67,2.98);
    g.addEdge(5,47,43.97);
    g.addEdge(6,16,3.73);
    g.addEdge(6,26,7.24);
    g.addEdge(6,42,10.26);
    g.addEdge(6,81,8.33);
    g.addEdge(7,28,3.12);
    g.addEdge(7,37,1.41);
    g.addEdge(7,67,4.22);
    g.addEdge(7,79,5.99);
    g.addEdge(8,57,79.64);
    g.addEdge(9,23,5.16);
    g.addEdge(9,50,11.27);
    g.addEdge(10,19,39.63);
    g.addEdge(10,59,109.82);
    g.addEdge(10,68,87.54);
    g.addEdge(11,0,11.23);
    g.addEdge(11,13,16.71);
    g.addEdge(11,39,25.17);
    g.addEdge(11,53,88.65);
    g.addEdge(11,56,5.34);
    g.addEdge(12,20,65.79);
    g.addEdge(12,26,91.6);
    g.addEdge(12,32,77.17);
    g.addEdge(13,11,16.71);
    g.addEdge(13,63,19.5);
    g.addEdge(13,80,4.36);
    g.addEdge(13,83,10.8);
    g.addEdge(14,39,40.02);
    g.addEdge(15,1,5.38);
    g.addEdge(15,29,47.36);
    g.addEdge(15,85,1.34);
    g.addEdge(15,86,4.14);
    g.addEdge(16,6,3.73);
    g.addEdge(17,34,100.88);
    g.addEdge(17,53,98.42);
    g.addEdge(17,61,12.73);
    g.addEdge(18,41,1.28);
    g.addEdge(18,69,1.19);
    g.addEdge(19,10,39.63);
    g.addEdge(19,32,60.92);
    g.addEdge(20,12,65.79);
    g.addEdge(20,84,38.15);
    g.addEdge(21,36,41.13);
    g.addEdge(22,23,5.75);
    g.addEdge(22,80,17.47);
    g.addEdge(23,9,5.16);
    g.addEdge(23,22,5.75);
    g.addEdge(23,26,33.14);
    g.addEdge(24,38,1.8);
    g.addEdge(24,55,1.3);
    g.addEdge(24,79,1.51);
    g.addEdge(25,2,24.58);
    g.addEdge(25,45,90.2);
    g.addEdge(25,82,136.92);
    g.addEdge(26,6,7.24);
    g.addEdge(26,12,91.6);
    g.addEdge(26,23,33.14);
    g.addEdge(26,80,12.26);
    g.addEdge(27,49,31.38);
    g.addEdge(27,54,26.62);
    g.addEdge(27,60,29.22);
    g.addEdge(28,7,3.12);
    g.addEdge(28,37,1.68);
    g.addEdge(28,44,1.41);
    g.addEdge(28,75,4.2);
    g.addEdge(29,15,47.36);
    g.addEdge(29,40,23.43);
    g.addEdge(29,47,45.25);
    g.addEdge(30,51,97.8);
    g.addEdge(30,58,21.85);
    g.addEdge(31,0,8.58);
    g.addEdge(31,83,10.06);
    g.addEdge(31,87,4.31);
    g.addEdge(32,12,77.17);
    g.addEdge(32,19,60.92);
    g.addEdge(32,74,27.7);
    g.addEdge(33,4,1.4);
    g.addEdge(33,42,3.1);
    g.addEdge(33,67,1.55);
    g.addEdge(33,79,2.76);
    g.addEdge(34,17,100.88);
    g.addEdge(34,57,41.98);
    g.addEdge(35,52,3.58);
    g.addEdge(36,21,41.13);
    g.addEdge(36,44,5.34);
    g.addEdge(36,75,7.35);
    g.addEdge(37,7,1.41);
    g.addEdge(37,28,1.68);
    g.addEdge(37,48,3.18);
    g.addEdge(37,75,4.15);
    g.addEdge(38,24,1.8);
    g.addEdge(38,81,2.87);
    g.addEdge(39,11,25.17);
    g.addEdge(39,14,40.02);
    g.addEdge(40,29,23.43);
    g.addEdge(40,51,96.32);
    g.addEdge(41,18,1.28);
    g.addEdge(41,48,0.95);
    g.addEdge(41,69,2.59);
    g.addEdge(42,4,1.76);
    g.addEdge(42,6,10.26);
    g.addEdge(42,33,3.1);
    g.addEdge(42,81,4.53);
    g.addEdge(42,85,11.97);
    g.addEdge(43,71,88.26);
    g.addEdge(43,82,67.43);
    g.addEdge(44,28,1.41);
    g.addEdge(44,36,5.34);
    g.addEdge(44,86,3.38);
    g.addEdge(45,2,93.75);
    g.addEdge(45,25,90.2);
    g.addEdge(45,82,50.51);
    g.addEdge(46,51,48.58);
    g.addEdge(46,59,45.04);
    g.addEdge(47,5,43.97);
    g.addEdge(47,29,45.25);
    g.addEdge(48,37,3.18);
    g.addEdge(48,41,0.95);
    g.addEdge(48,64,2.19);
    g.addEdge(49,27,31.38);
    g.addEdge(49,54,41.15);
    g.addEdge(49,82,58.19);
    g.addEdge(50,9,11.27);
    g.addEdge(50,53,61.16);
    g.addEdge(50,63,12.84);
    g.addEdge(51,30,97.8);
    g.addEdge(51,40,96.32);
    g.addEdge(51,46,48.58);
    g.addEdge(51,59,14.13);
    g.addEdge(52,4,5.94);
    g.addEdge(52,35,3.58);
    g.addEdge(52,85,4.66);
    g.addEdge(53,11,88.65);
    g.addEdge(53,17,98.42);
    g.addEdge(53,50,61.16);
    g.addEdge(53,62,17.69);
    g.addEdge(54,27,26.62);
    g.addEdge(54,49,41.15);
    g.addEdge(54,82,30.9);
    g.addEdge(55,4,1.76);
    g.addEdge(55,24,1.3);
    g.addEdge(56,0,6.3);
    g.addEdge(56,11,5.34);
    g.addEdge(57,8,79.64);
    g.addEdge(57,34,41.98);
    g.addEdge(57,71,83.62);
    g.addEdge(58,30,21.85);
    g.addEdge(59,10,109.82);
    g.addEdge(59,46,45.04);
    g.addEdge(59,51,14.13);
    g.addEdge(60,27,29.22);
    g.addEdge(60,82,42.53);
    g.addEdge(61,17,12.73);
    g.addEdge(61,73,62.95);
    g.addEdge(62,53,17.69);
    g.addEdge(63,13,19.5);
    g.addEdge(63,50,12.84);
    g.addEdge(64,48,2.19);
    g.addEdge(64,85,1.82);
    g.addEdge(65,0,11.39);
    g.addEdge(65,66,6.01);
    g.addEdge(65,77,3.68);
    g.addEdge(65,78,10.88);
    g.addEdge(66,65,6.01);
    g.addEdge(66,72,4.98);
    g.addEdge(67,4,2.98);
    g.addEdge(67,7,4.22);
    g.addEdge(67,33,1.55);
    g.addEdge(67,69,2.0);
    g.addEdge(67,78,6.49);
    g.addEdge(68,3,86.78);
    g.addEdge(68,10,87.54);
    g.addEdge(68,70,48.55);
    g.addEdge(69,1,2.44);
    g.addEdge(69,18,1.19);
    g.addEdge(69,41,2.59);
    g.addEdge(69,67,2.0);
    g.addEdge(70,3,41.42);
    g.addEdge(70,68,48.55);
    g.addEdge(71,43,88.26);
    g.addEdge(71,57,83.62);
    g.addEdge(72,66,4.98);
    g.addEdge(72,77,13.15);
    g.addEdge(73,61,62.95);
    g.addEdge(73,84,47.91);
    g.addEdge(74,3,22.42);
    g.addEdge(74,32,27.7);
    g.addEdge(75,28,4.2);
    g.addEdge(75,36,7.35);
    g.addEdge(75,37,4.15);
    g.addEdge(75,78,3.97);
    g.addEdge(75,79,8.59);
    g.addEdge(76,77,3.1);
    g.addEdge(76,87,4.72);
    g.addEdge(77,65,3.68);
    g.addEdge(77,72,13.15);
    g.addEdge(77,76,3.1);
    g.addEdge(77,78,6.97);
    g.addEdge(78,65,10.88);
    g.addEdge(78,67,6.49);
    g.addEdge(78,75,3.97);
    g.addEdge(78,77,6.97);
    g.addEdge(79,7,5.99);
    g.addEdge(79,24,1.51);
    g.addEdge(79,33,2.76);
    g.addEdge(79,75,8.59);
    g.addEdge(79,87,4.45);
    g.addEdge(80,13,4.36);
    g.addEdge(80,22,17.47);
    g.addEdge(80,26,12.26);
    g.addEdge(81,6,8.33);
    g.addEdge(81,38,2.87);
    g.addEdge(81,42,4.53);
    g.addEdge(81,87,2.1);
    g.addEdge(82,25,136.92);
    g.addEdge(82,43,67.43);
    g.addEdge(82,45,50.51);
    g.addEdge(82,49,58.19);
    g.addEdge(82,54,30.9);
    g.addEdge(82,60,42.53);
    g.addEdge(83,13,10.8);
    g.addEdge(83,31,10.06);
    g.addEdge(84,20,38.15);
    g.addEdge(84,73,47.91);
    g.addEdge(85,15,1.34);
    g.addEdge(85,42,11.97);
    g.addEdge(85,52,4.66);
    g.addEdge(85,64,1.82);
    g.addEdge(86,15,4.14);
    g.addEdge(86,44,3.38);
    g.addEdge(87,0,12.46);
    g.addEdge(87,31,4.31);
    g.addEdge(87,76,4.72);
    g.addEdge(87,79,4.45);
    g.addEdge(87,81,2.1);
    

    g.dijkstra(dist,parent,stations[src]);

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

        g.constract_path(parent,stations[st_name],stations);
    }
    return 0;
}