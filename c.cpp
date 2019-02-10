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
  ll k, a, b;
  cin >> k >> a >> b;
  ll result = 1;
  if(b - a > 2)
  {
    ll x = (k - (a - 1)) / 2;
    result += x * (b - a);
    result += k - (x * 2);
  }else{
    result += k;
  }
  cout << result << endl;
}
