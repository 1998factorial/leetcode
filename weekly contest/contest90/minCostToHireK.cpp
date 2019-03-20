pair<double,double> worker[10000];
double INF = 1000000000.0;
class Solution {
public:
    double mincostToHireWorkers(vector<int>& q, vector<int>& w, int K) {
        int n = q.size();
        for(int i = 0; i < n; i++)
            worker[i] = {(double)w[i]/(double)q[i],(double)q[i]};
        sort(worker,worker+n,cmp);
        priority_queue<double> pq;
        double sum = 0.0, ret = INF;
        for(int i = 0; i < n; i++){
            sum += worker[i].second, pq.push(worker[i].second);
            if(pq.size() > K)sum -= pq.top(), pq.pop();
            if(pq.size() == K)ret = min(ret,sum*worker[i].first);
        }
        return ret;
    }
    static bool cmp(pair<double,double> a, pair<double,double> b){
        return a.first < b.first;
    }
};