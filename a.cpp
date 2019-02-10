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
  int n, k;
  cin >> n >> k;
  int temp = 0;
  if(n % 2 == 0)
  {
    temp = n / 2;
  }else{
    temp = (n / 2) + 1;
  }
  if(temp >= k)
  {
    cout << "YES" << endl;
  }else{
    cout << "NO" << endl;
  }
}
