class Solution {
public:
 
    long long distinctNames(vector<string>& ideas) {
        int n = ideas.size();
        long long ans = 0;
        unordered_set<string> groups[26];
        for(auto x : ideas)
        {
            groups[x[0]-'a'].insert(x.substr(1));
        }
        for(int i =0;i<25;i++)
        {
            for(int j = i+1;j<26;j++)
            {
                int common = 0;
                for(auto x : groups[i])
                {
                    if(groups[j].find(x) != groups[j].end())
                        common++;
                }
                ans += (groups[i].size()-common) * (groups[j].size()-common);
            }
        }
        return 2*ans;
    }
};