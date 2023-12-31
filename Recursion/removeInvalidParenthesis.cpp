class Solution {
public:
    pair<int,bool> isValid(string s){
        stack<char> st;
        pair<int,bool> res;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(')
                st.push(s[i]);
            else if(s[i] == ')'){
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    st.push(s[i]);
            }
        }
              
        if(st.empty()){
            res.second = true;
            res.first = 0;
        }
        else{
            res.second = false;
            res.first = st.size();
        }
        return res;
    }
    
    void solve(int idx,vector<string> &ans,string s,int k,string str){
        
        if(k == 0){
            if(idx < s.size()){
                str += s.substr(idx);
                idx = s.size()-1;
            }
            if(isValid(str).second)
                ans.push_back(str);
            return;
        }
        
        if(idx >= s.size())
            return;
        
        
        solve(idx+1,ans,s,k,str+s[idx]);
        solve(idx+1,ans,s,k-1,str);
                
    }
    
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        pair<int,bool> numOfInvalid = isValid(s);
        int k = numOfInvalid.first;
        solve(0,ans,s,k,"");
        map<string,int> st;
        for(auto it : ans)
            st[it]++;
        ans.clear();
        for(auto i : st)
            ans.push_back(i.first);
        
        return ans;
    }
};