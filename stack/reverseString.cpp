
// return the address of the string
char *reverse(char *S, int len)
{
    stack<char> st;
    string ans = "";
    for (int i = 0; i < len; i++)
    {
        st.push(S[i]);
    }
    while (!st.empty())
    {
        char topEle = st.top();
        ans += topEle;
        st.pop();
    }
    char *myAns = new char[len + 1];
    strcpy(myAns, ans.c_str());
    return myAns;
}