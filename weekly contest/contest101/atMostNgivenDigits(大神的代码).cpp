typedef long long ll;
typedef vector<int> VI;
typedef pair<int,int> PII;

#define REP(i,s,t) for(int i=(s);i<(t);i++)
#define FILL(x,v) memset(x,v,sizeof(x))

const int INF = (int)1E9;
#define MAXN 100005


int sz, dp[15][2][2];
VI ds;

class Solution {
public:
  int atMostNGivenDigitSet(vector<string>& D, int N) {
    ds.clear();
    int n = N;
    while (n > 0) {
      ds.push_back(n % 10);
      n /= 10;
    }
    reverse(ds.begin(), ds.end());
    sz = ds.size();
    FILL(dp, 0);
    dp[0][0][0] = 1;
    D.push_back("0");
    REP(i,1,sz+1) {
      int d = ds[i - 1];
      REP(pt,0,2) {
        REP(pnz,0,2) {
          REP(j,0,D.size()) {
            int c = D[j][0] - '0', nt = pt;
            if (c == 0 && pnz) continue;
            if (pt == 0) {
              if (c > d) continue;
              nt = c < d;
            }
            int nz = pnz;
            if (c > 0) nz = 1;
            dp[i][nt][nz] += dp[i-1][pt][pnz];
          }
        }
      }
    }
    return dp[sz][0][1] + dp[sz][1][1];
  }
};