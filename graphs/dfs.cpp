#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

int n, m;
vector<vector<int>> graph;
vector<int> vis;

vector<int> res;

void dfs(int i){
    res.push_back(i);
    vis[i] = 1;
    for(auto node:graph[i]){
        if(vis[node] == 0){
            dfs(node);
        }
    }
}

// below dfs function to find and store all the components of the graph
void dfsComponents(int i, vector<int> &comp){
    comp.push_back(i);
    vis[i] = 1;
    for(auto node:graph[i]){
        if(vis[node] == 0){
            dfs(node);
        }
    }
}

int main(){
    cin >> n >> m;
    graph.resize(n+1);
    vis.assign(n+1, 0);
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);

        // for undirected graph
        graph[b].push_back(a);
    }

    dfs(1);

    for(int i=1;i<=n;i++){
        cout << "node " << i << " isVisited:" << vis[i] << endl;
    }
    cout << "below is result of dfs:" << endl;
    for(int i=0;i<n;i++){
        cout << res[i] << " ";
    }

    // dfs for components amd their size
    vector<vector<int>> allComponents;
    for(int i=1;i<=n;i++){
        if(vis[i] == 0){
            vector<int> comp;
            dfsComponents(i, comp);
            allComponents.push_back(comp);
        }
    }

    cout << "number of components:" << allComponents.size() << endl;
    cout << "below are components description:" << endl;
    for(auto comp:allComponents){
        cout << "size of the component:" << comp.size() << endl;
        cout << "nodes in components are: ";
        for(auto node:comp){
            cout << node << " ";
        }
        cout << endl;
    }
    return 0;   
}