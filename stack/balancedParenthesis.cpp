  bool ispar(string x)
    {
        stack<char> st;
        for(int i = 0; i < x.length(); i++){
            if(x[i] == '[')
                st.push('[');
            if(x[i] == '(')
                st.push('(');
            if(x[i] == '{')
                st.push('{');
            if(x[i] == ']'){
                if(!st.empty() && st.top() == '[')
                    st.pop();
                else
                    return false;
            }
            if(x[i] == ')'){
                if(!st.empty() && st.top() == '(')
                    st.pop();
                else
                    return false;
            }
              if(x[i] == '}'){
                if(!st.empty() && st.top() == '{')
                    st.pop();
                else
                    return false;
            }
        }
        return st.empty();
    }