class Solution {
public:
    int minSetSize(vector<int>& arr) {
        map<int,int>mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
       priority_queue<int>q;
        int c=0,count=0;
        for(auto x:mp)
        {
            q.push(x.second);
            
            
        }
        while(!q.empty())
        {
            c+=q.top();
            q.pop();
            ++count;
            if(c>=arr.size()/2)
                return count;
        }
        return -1;
    }
};