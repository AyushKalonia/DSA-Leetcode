class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parents;

    void dfs(string word, string& beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (auto& par : parents[word]) {
            path.push_back(par);
            dfs(par, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> words(wordList.begin(), wordList.end());

        if (!words.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        words.erase(beginWord);

        bool found = false;

        while (!q.empty() && !found) {

            int sz = q.size();
            unordered_set<string> usedOnLevel;

            while (sz--) {

                string parent = q.front();
                q.pop();

                string word = parent;

                for (int i = 0; i < word.size(); i++) {

                    char orig = word[i];

                    for (char ch = 'a'; ch <= 'z'; ch++) {

                        if (ch == orig)
                            continue;

                        word[i] = ch;

                        if (!words.count(word))
                            continue;

                        if (!usedOnLevel.count(word)) {
                            q.push(word);
                            usedOnLevel.insert(word);
                        }

                        parents[word].push_back(parent);
                    }

                    word[i] = orig;
                }
            }

            for (auto& w : usedOnLevel) {
                if (w == endWord)
                    found = true;
                words.erase(w);
            }
        }

        if (!parents.count(endWord))
            return {};

        vector<string> path = {endWord};
        dfs(endWord, beginWord, path);

        return ans;
    }
};