#include <bits/stdc++.h>
using namespace std;
#define v vector
#define ll long long
#define fast_io ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define f(arr, n) for(ll i = 0; i < n; i++) cin >> arr[i];
 
 
 
vector<ll> sieve(ll sieve_size)
{
    vector<ll> s(sieve_size + 1, 1);
    s[0] = s[1] = 0;  
 
    for (ll i = 2; i * i <= sieve_size; i++)
    {
        if (s[i] == 1)
        {
            for (ll j = i * i; j <= sieve_size; j += i)  
            {
                s[j] = 0;
            }
        }
    }
    return s;
}
long long MCMDP(vector<ll>&arr,ll n,ll i,ll j)
{
    vector<vector<ll>>dp(n,vector<ll>(n,-1));
    if(dp[i][j]!=-1)
    return dp[i][j];
    if(i>=j)
    return 0;
    ll minops=LLONG_MAX;
    for(ll k=i;k<j;k++)
    {
        ll steps=MCMDP(arr,n,i,k)+MCMDP(arr,n,k+1,j)+arr[i-1]*arr[k]*arr[j];
        minops=min(minops,steps);
        
    }
    return dp[i][j]=minops;
}
int main()
{   
    fast_io;
ll n;
cin>>n;
v<ll>a(n);
f(a,n);
ll i=1;
ll j=n-1;
cout<<MCMDP(a,n,i,j)<<endl;

}