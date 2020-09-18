/* 
** Author : Vivek Bhardwaj
** Difference Array (Basic range updates (without queries))
** Reference : https://www.geeksforgeeks.org/difference-array-range-update-query-o1/
** Prefix Sums (Basic Range queries (without updates))
** Reference : https://www.geeksforgeeks.org/prefix-sum-array-implementation-applications-competitive-programming/
** Thus the above concept works when you have to update first and then do queries afterwards
** it won't work if you have to do things randomly like updates then queries then updates
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,k,q;
    cin>>n>>k>>q;

    const int MAXN = 200002;       //because l,r is in range 0-200000

    vector<int> difference_array(MAXN);
    fill(difference_array.begin(),difference_array.end(),0);        //fill the whole array with 0's

    for(int i=0;i<n;i++){

        int l,r;
        cin>>l>>r;

        difference_array[l]++;
        difference_array[r+1]--;

    }

    vector<int> no_of_recommendations(200001);
    no_of_recommendations[0] = 0;

    for(int i=1;i<200001;i++){
        //Why this works ?
        no_of_recommendations[i] = no_of_recommendations[i-1] + difference_array[i];
    }

    //now you would be given queries for no. of admissible temperatures in a given range

    vector<int> prefix(200001);
    prefix[0] = 0;

    for(int i=1;i<200001;i++){
        if(no_of_recommendations[i] >= k)
            prefix[i] = prefix[i-1] + 1;    //1 because i-th index will contribute to ans
        else 
            prefix[i] = prefix[i-1] + 0;    //0 because i-th index will not contribute to ans
    }

    while(q--){

        int a,b;
        cin>>a>>b;
        //this is the way how prefix array helps in answering queries
        cout<<prefix[b] - prefix[a-1]<<"\n";

    }


    return 0;
}