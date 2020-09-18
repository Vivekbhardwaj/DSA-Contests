/* 
** Author : Vivek Bhardwaj
** There are many ways , but here is an implementation using std::set
** which can provide a insertion and deletion in O(logN) time
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    
    int n, m;
    cin>>n>>m;

    set<int> s;
    //inserting all the knights indexes into the set
    for(int i=1;i<=n;i++){
        s.insert(i);
    }

    vector<int> ans(n+1,0);       //n+1 because knights are indexed 1-based

    for(int i=0;i<m;i++){

        int l,r,winner;
        cin>>l>>r>>winner;
        
        //consider iterator as ptr , lower_bound helps iterator point to the minimum element that is greater than or equal to r
        set<int> :: iterator left_iter = s.lower_bound(l);
        set<int> :: iterator right_iter = s.lower_bound(r);

        //if there is no element greater than or equal to r
        if(right_iter == s.end())   right_iter--;
        //if right iter points to element greater than r , since we require elements less than or equal to r only so decrement by 1
        else if(*right_iter != r)   right_iter--;

        vector<int> participants;   //this will store indexes of knights who took part in current tournament

        while(true){
            int curr = *left_iter;  // * before any iterator deferences it like pointers and gives its value

            participants.push_back(curr);

            if(left_iter == right_iter) break;  //if left iterator has reached right there are no more index left which took part in current tournament
            else left_iter++;           //else increment the left ptr
        }

        for(int i=0;i<participants.size();i++){
            if(participants[i] != winner){  //if participant is not the winner then this means it lost to the winner so we mark its answer and erase it from set
                ans[participants[i]] = winner;
                s.erase(participants[i]);
            }
        }
    }

    for(int i=1;i<=n;i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;

    return 0;
}

/*
NOTE : Its important to know how set works to understand this solution 
Some important things : 
1. You can only increment or decrement the iterator by 1 /
2. you cannot use  >= or <= or other comparison operators for iterators (that is why i had to use left_iter!=right_iter
  instead of simply using left_iter < right_iter)

Further Read : https://www.geeksforgeeks.org/set-in-cpp-stl/
            : http://www.cplusplus.com/reference/set/set/
*/