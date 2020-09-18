/* 
** Author : Vivek Bhardwaj
** Basic Implementation to find cycles (called as dfs sometimes as its similar to that)
** There are many approaches to do this question on other of them being finding all connected components using DSU
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int q;
    cin>>q;

    while(q--){

        int n;
        cin>>n;

        vector<int> p(n+1);

        for(int i=1;i<=n;i++) cin>>p[i];

        vector<int> ans(n+1);

        vector<bool> visited(n);      //visited[i] will tell us if i has been visited or not
        fill(visited.begin(),visited.end(),false);      //in starting none is visited

        for(int i=1;i<=n;i++){

            if(visited[i] == false){

                vector<int> elements_in_current_cycle;  //will store all elements that are in current cycle
                int cycle_length = 0;       //the no of elements in cycle from i--->i / how long will it take to reach i again

                int curr = i;

                while(true){
                    cycle_length++;
                    curr = p[curr];
                    visited[curr] = true;
                    elements_in_current_cycle.push_back(curr);
                    if(curr == i) break;    //we reached i again so break
                }

                //all the elements present in current cycle will get their books after cycle_length days
                for(int i=0;i<elements_in_current_cycle.size();i++){
                    ans[elements_in_current_cycle[i]] = cycle_length;
                }

            }
        }

        for(int i=1;i<=n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
    
    return 0;
}


// TIP : Many times a permutation array (array having all elements from 1...n shuffled randomly) can be seen as a graph
