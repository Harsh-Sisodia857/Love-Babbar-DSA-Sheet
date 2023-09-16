string reorganizeString(string s) {
        // store the frequency of character
        int len = s.length();
        unordered_map<char,int> m;
        for(int i = 0; i < len; i++){
            m[s[i]]++;
        }
        // creating max heap
        priority_queue<pair<int,char>> pq;
        //pushing char with frequency in max heap
        for(auto &[ch,freq] : m){
            // max heap will be created based on freq
            pq.push({freq,ch});
        }
        string ans = "";
        while(pq.size() > 1){
            // pop two element from max heap
            auto [freq1,ch1] = pq.top();
            pq.pop();
            auto [freq2,ch2] = pq.top();
            pq.pop();
            ans += ch1;
            ans += ch2;
            if(--freq1 > 0){
                pq.push({freq1,ch1});
            }
            if(--freq2 > 0){
                pq.push({freq2,ch2});
            }
        }
        if(pq.size() == 1){
            auto [freq,ch] = pq.top();
            if(freq > 1)
                return "";
            ans += ch;
        }
        return ans;
    }