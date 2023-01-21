#include <iostream>
#include <map>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

ll s[200005];

int main(void)
{
  ll n, m, a, sum = 0; 
  map<ll, ll> mp;
  
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    cin >> a;
    mp[a]++;
    sum += a;
  }  
  vector<pair<ll, ll>> vec;
  for(auto p : mp) vec.push_back(p);
  int k = vec.size();
  
  if(k == m){
    cout << 0 << endl;
    return 0;
  }
  
  int p;
  for(int i = 0; i < k; i++){
    if(vec[(i+1)%k].first != (vec[i].first+1)%m){
      p = i;
      break;
    }
  }
  
  for(int i = 0; i < k; i++){
    int j = (p-i+k)%k;
    s[j] = sum;
    if(vec[(j+1)%k].first == (vec[j].first+1)%m) s[j] = s[(j+1)%k];
    s[j] -= vec[j].first * vec[j].second;
  }
  
  ll ans = sum;
  for(int i = 0; i < k; i++) ans = min(ans, s[i]);
  cout << ans << endl;
  
  return 0;
}
