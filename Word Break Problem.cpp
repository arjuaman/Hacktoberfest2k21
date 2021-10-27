#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;
bool wordBreak(unordered_set<string> const &dict, string word, vector<int> &lookup)
{
    int n = word.size();
    if (n == 0) {
        return true;
    }
    if (lookup[n] == -1)
    {
        lookup[n] = 0;
        for (int i = 1; i <= n; i++)
        {
            string prefix = word.substr(0, i);
            if (find(dict.begin(), dict.end(), prefix) != dict.end() &&
                wordBreak(dict, word.substr(i), lookup))
            {
                return lookup[n] = 1;
            }
        }
    }
    return lookup[n];
}
int main()
{
    unordered_set<string> dict = { "this", "th", "is", "famous", "Word", "break", "b", "r", "e", "a", "k", "br", "bre", "brea", "ak", "problem" };
    string word = "Wordbreakproblem";
    vector<int> lookup(word.length() + 1, -1);
    if (wordBreak(dict, word, lookup)) {
        cout << "The string can be segmented";
    }
    else {
        cout << "The string can't be segmented";
    }
    return 0;
}
