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
  int a1, a2, a3, b1, b2, b3;
  cin >> a1 >> a2 >> a3 >> b1 >> b2 >> b3;
  vector<int> town(4, 0);
  town[a1 - 1]++;
  town[a2 - 1]++;
  town[a3 - 1]++;
  town[b1 - 1]++;
  town[b2 - 1]++;
  town[b3 - 1]++;
  bool can = true;
  for(auto e : town)
  {
    if(e >= 3)
    {
      can = false;
    }
  }
  if(can)
  {
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
