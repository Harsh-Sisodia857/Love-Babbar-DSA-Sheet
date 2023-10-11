
#include <iostream>
#include <string>

    using namespace std;

// Function to extract the value of a query parameter from a URL
string getQueryParamValue(string &url, string &key)
{
    // Find the position of the key in the URL
    size_t keyPos = url.find(key + '=');
    cout << "KEY POS : " << keyPos << endl;
    if (keyPos == string::npos)
    {
        return "-1"; // Key not found
    }

    // Find the position of the next '&' after the key
    size_t ampPos = url.find('&', keyPos);

    // Extract the value of the query parameter
    string value;
    if (ampPos != string::npos)
    {
        value = url.substr(keyPos, ampPos - keyPos - key.length() - 1);
        cout << "keyPos + key.length() + 1 : " << keyPos + key.length() + 1<<endl;
        cout << "ampPos - keyPos - key.length() - 1 : " << ampPos - keyPos - key.length() - 1 << endl;
    }
    else
    {
        value = url.substr(keyPos);
    }

    return value;
}

int main()
{
    string url = "https://localhost:3000?text=harsh&age=21&y=85";

    int N = 3;

    for (int i = 0; i < N; i++)
    {
        string key;
        cin >> key;

        string value = getQueryParamValue(url, key);
        cout << value << endl;
    }

    return 0;
}