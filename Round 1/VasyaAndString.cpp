/**
 * Author : Vivek Bhardwaj
 * A classical Binary Search + Sliding Window Trick  (MOST ASKED QUESTION)
 * Remember anytime you realize that you can convert a question to a logical monotonic form 
 * Binary Search is a way out.
 * Loosely , used usually when you want to maximize or minimize something
**/


#include<bits/stdc++.h>
using namespace std;
#define int long long


/*
In binary search questions where instead of searching element you need to find min or max
we usually create a 'check' function like this
*/

//passing string by reference using '&' before variable name
bool check(string &s , int len, int k, int n){

    int arr[2]; //arr[0] <- no of a's in current window , arr[1] <- no of b's in current window
    arr[0] = arr[1] = 0;


    //the part here is what we call sliding window it helps keep track of 'a' and 'b' in a particular
    //range of length l without iterating over all subarrays of lengyh l again and again
    for(int i=0;i<len;i++){
        arr[s[i]-'a']++;
    }

    /*
    if no of a's(arr[0] <=k) in current window is less than or equal to k then it we'd replace them with b and whole segment 
    will become b and thus it is possible to create a unified subsegment using at max k toggles
    same goes for b (arr[1]<=k)
    */
    if(arr[0]<=k || arr[1]<=k) return true;

    for(int i=len;i<n;i++){
        arr[s[i]-'a']++;
        arr[s[i-len]-'a']--;
        if(arr[0]<=k || arr[1]<=k) return true;

    }

    return false;
}



int32_t main(){

    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    int n,k;
    cin>>n>>k;
 
    string s;   //input string 
    cin>>s;
 
 
    //minimum length we can make is 1 , max length (maybe) we can make is n
    int l=1,r=n;
 
    while(l<r){
        int mid = (l+r+1)/2;
        //ask if it is possible to make a segment of length 'mid' using at max k toggles

        if(check(s,mid,k,n) == true){   //if yes we are sure that our answer will be >= mid lo we make l = mid
            l = mid;
        }  else {   //if no we cannot make answer even mid so our answer will be <mid so our r becomes mid-1 (search space decreases)
            r = mid-1;
        }
    }
 
    cout<<l<<endl;
 
    return 0;

}