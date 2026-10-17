
class Solution
{
public:
  int nthSuperUglyNumber(int n, vector<int> &primes)
  {
    vector<long long> ugly(n, 1);
    int k = primes.size();

    vector<int> idx(k, 0);
    vector<long long> next(k);

    for (int i = 0; i < k; i++)
    {
      next[i] = primes[i];
    }

    for (int i = 1; i < n; i++)
    {
      long long mn = LLONG_MAX;

      for (int j = 0; j < k; j++)
      {
        mn = min(mn, next[j]);
      }

      ugly[i] = mn;

      for (int j = 0; j < k; j++)
      {
        if (next[j] == mn)
        {
          idx[j]++;
          next[j] = ugly[idx[j]] * primes[j];
        }
      }
    }

    return ugly[n - 1];
  }
};
