    int p[105];
    string s[105];
bool cmp(int x,int y)
    {
        if(s[x][0]>='a'&&s[x][0]<='z'&&s[y][0]>='a'&&s[y][0]<='z')return s[x]<s[y];
        if(s[x][0]>='0'&&s[x][0]<='9'&&s[y][0]>='0'&&s[y][0]<='9')return x<y;
        return s[x][0]>='a'&&s[x][0]<='z';
    }
class Solution {
public:
    
    vector<string> reorderLogFiles(vector<string>& logs) {
        vector<string> ans;
        ans.clear();
        int n=logs.size(),m,i,j;
        for(i=0;i<n;i++)
        {
            m=logs[i].size();
            p[i]=i;
            s[i]="";
            for(j=0;j<m;j++)if(logs[i][j]==' ')break;
            for(j++;j<m;j++)s[i]+=logs[i][j];
        }
        sort(p,p+n,cmp);
        for(i=0;i<n;i++)ans.push_back(logs[p[i]]);
        return ans;
    }
};