#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <math.h>

using namespace std;
using ll = long long int;

int main()
{
  ll l;
  cin >> l;
  vector<ll> a(l, 0);
  ll maximam = 0;
  for(int i = 0; i < l; i++)
  {
    cin >> a[i];
    maximam += a[i];
  } 
  vector<vector<ll>> dp(l, vector<ll>(5, maximam));
  const int DMINUS = 0; //D以下
  const int SMINUS = 1; //S以下
  const int TMINUS = 2; //T以下
  const int UMINUS = 3; //U以下
  const int UPLUS = 4;  //Uより大きい

  //UMINUS用の更新関数
  auto calcUminus = [&](int index)
  {
    ll result = 0;
    if(a[index] % 2ll == 0)
    {
      if(a[index] == 0)
      {
        result = 2;
      }else{
        result = 0;
      }
    }else{
      result = 1;
    }
    return result;
  };
  //TMINUS用の更新関数
  auto calcTminus = [&](int index)
  {
    ll result = 0;
    if(a[index] % 2ll == 0)
    {
      result = 1;
    }else{
      result = 0;
    }
    return result;
  };

  //l - 1番目の耳について
  dp[l - 1][UPLUS] = a[l - 1];
  dp[l - 1][UMINUS] = calcUminus(l - 1);
  dp[l - 1][TMINUS] = calcTminus(l - 1);
  //dp[l - 1][SMINUS] = calcUminus(l - 1);
  //dp[l - 1][DMINUS] = a[l - 1];
  //l - 2から0までdp配列の更新
  for(int i = l - 2; i >= 0; i--)
  {
    dp[i][UPLUS] = a[i] + dp[i + 1][UPLUS];
    dp[i][UMINUS] = calcUminus(i) + min(dp[i + 1][UPLUS], dp[i + 1][UMINUS]);
    dp[i][TMINUS] = calcTminus(i) + min({dp[i + 1][TMINUS], 
                                        dp[i + 1][UMINUS],
                                        dp[i + 1][UPLUS]});
    dp[i][SMINUS] = calcUminus(i) + min({dp[i + 1][SMINUS], 
                                        dp[i + 1][TMINUS],
                                        dp[i + 1][UMINUS],
                                        dp[i + 1][UPLUS]});
    dp[i][DMINUS] = a[i] + min( {dp[i + 1][DMINUS], 
                                dp[i + 1][SMINUS], 
                                dp[i + 1][TMINUS],
                                dp[i + 1][UMINUS],
                                dp[i + 1][UPLUS]});
  }
  /*for(auto e : dp)
  {
    for(int i = 0; i < 5; i++)
    {
      cout << e[i] << " ";
    }
    cout << endl;
  }*/
  ll result = maximam;
  for(int i = 0; i < 5; i++)
  {
    result = min(result, dp[0][i]);
  }
  cout << result << endl;
}
