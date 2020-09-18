/* 
** Author : Vivek Bhardwaj
** Difference Array (Basic range updates (without queries))
** Reference : https://www.geeksforgeeks.org/difference-array-range-update-query-o1/
*/

#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main(){

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,q;
    cin>>n>>q;

    vector<int> v(n+1);
    for(int i=1;i<=n;i++) cin>>v[i];


    vector<int> difference_array(n+2);  //arary is 1 indexed
    fill(difference_array.begin(),difference_array.end(),0);        //fill the whole array with 0's

    for(int i=0;i<q;i++){

        int l,r;
        cin>>l>>r;

        difference_array[l]++;
        difference_array[r+1]--;

    }

    //stores how many times i-th index is queried
    vector<int> queried(n+1);
    queried[0] = 0;

    for(int i=1;i<=n;i++){
        //Why this works ?
        queried[i] = queried[i-1] + difference_array[i];
    }

    /*
    now at the index which is queried maximum times we will put the element that is maximum
    and thus 
    greater the times an index is queried greater will be the value we assign to it
    */

   //A better way to implement above idea is
   //sort queried and sort the given array (v) in decending order and multiply corresponding elements

    sort(queried.begin(),queried.end(),greater<int>());
    sort(v.begin(),v.end(),greater<int>());

    int ans = 0;

    for(int i=0;i<n;i++){
        ans = ans + v[i]*queried[i];
    }

    cout<<ans<<endl;

    return 0;
}