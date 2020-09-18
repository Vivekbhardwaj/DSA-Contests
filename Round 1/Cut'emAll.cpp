/* 
** Author : Vivek Bhardwaj
** Introduction to DFS (with some toggeling)
** As soon as while dfs we find a node whose subtree is having even nodes we will cut the edge joining the node to 
** its parent and return 0 else we will return the size itself
*/
#include<bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> tree[MAXN];     //adjacency list implementation of tree

int ans = 0;        //stores the total no of components as a result of deletion of edges

int dfs(int curr,int parent){

    int curr_size = 1;  //curr node adds 1 to side

    for(int i : tree[curr]){
        if( i != parent){
            curr_size += dfs(i,curr);       //add the no of nodes we get from its children
        }
    }

    if(curr_size%2 == 0){      //if current size is even break the edge joining it to its parent
        ans++;                  //increment ans
        return 0;               //and now this subrtee will contribute 0 to its parent
    } else {
        return curr_size;   //else this subtree will contribute its total size to parent
    }
}

int main(){

    int n;
    cin>>n;

    for(int i=0;i<n-1;i++){
        int u,v;
        cin>>u>>v;
        //adding bi-directional edge
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    if(n%2 == 1){      //if n is odd we cannot make all the components even atleast one will be odd
        cout<<-1<<endl;
        exit(0);
    }

    //root the tree arbitarily at 1 , so we say its parent is -1 (which doesn't actually exist)
    dfs(1,-1);

    cout<<ans-1<<endl;      //edges deleted is no of components - 1
    return 0;
}