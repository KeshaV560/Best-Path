#include <bits/stdc++.h>

using namespace std;


int main(){
    int n;
    cout<<"ENTER THE NUMBER OF CITIES"<<endl;
    cin>>n;
    int a;
    int b;
    int time;
    vector<vector<pair<int,int>>> adj(n);
    cout<<"ENTER THE LIST CONTAINING A LIST OF TWO CITIES WHICH ARE DIRECTLY CONECTED AND THERE TIME TO COVER THE JOURNEY (CITY1, CITY2, TIME)"<<endl;
    while(true){
        int t=1;
        cout<<"ENTER 0 TO STOP ENTERING"<<endl;
        cin>>t;
        if(!t){
            break;
        }
        cin>>a;
        cin>>b;
        cin>>time;
        adj[a].push_back({b, time});
        adj[b].push_back({a, time});
    }
    // THE DIJKSTRA'S ALGORITHM.
    vector<int> dist(n, 1e9);
    int start;
    int final;
    cout<<"ENTER THE CITY YOU ARE IN AND THE CITY YOU WANT TO REACH"<<endl;
    cin>>start;
    cin>>final;
    if(start==final){
        cout<<"THE TIME TAKEN TO COMPLETE IS 0"<<endl;
    }
    set<pair<int, int>> fast;
    unordered_map<int, int> par;        // FOR RETRIEVING THE PART.
    par[start] = -1;
    fast.insert({0, start});
    while(!fast.empty()){
        auto it = *(fast.begin());
        int h = it.second;
        int k = it.first;
        fast.erase(it);
        for(auto ti : adj[h]){
            if(dist[ti.first]>k+ti.second){
                par[ti.first] = h;
                fast.erase({dist[ti.first], ti.first});
                dist[ti.first] = k+ti.second;
                fast.insert({k+ti.second, ti.first});
            }
        }
    }
    if(dist[final]==1e9){
        cout<<"OOPS NO SUCH PATH EXIST TO COMPLETE THE TRAVEL"<<endl;
        return 0;
    }
    stack<int> ans;
    int f;
    f = final;
    ans.push(final);
    while(par[f]!=-1 && f!=start){
        ans.push(par[f]);
        f = par[f];
    }
    cout<<"THE LEAST TIME FOR THE JOURNEY IS "<<dist[final]<<endl;
    cout<<"THE PATH YOU SHOULD TAKE IS ";
    while(!ans.empty()){
        cout<<ans.top();
        ans.pop();
        if(ans.empty()){
            break;
        }
        cout<<" -> ";
    }
    cout<<endl;
    cout<<"THANK YOU FOR USING"<<endl;
    return 0;
}