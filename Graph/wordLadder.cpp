int ladderLength(string beginWord, string endWord, vector<string> &wordList)
{
    set<string> words(wordList.begin(), wordList.end());
    int len = beginWord.length();
    words.erase(beginWord);
    queue<pair<string, int>> q;
    q.push({beginWord, 1});
    while (!q.empty())
    {
        string frontWord = q.front().first;
        int steps = q.front().second;
        q.pop();
        if (frontWord == endWord)
            return steps;
        for (int i = 0; i < frontWord.size(); i++)
        {
            char orignalChar = frontWord[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                frontWord[i] = ch;
                if (words.find(frontWord) != words.end())
                {
                    words.erase(frontWord);
                    q.push({frontWord, steps + 1});
                }
            }
            frontWord[i] = orignalChar;
        }
    }
    return 0;
}