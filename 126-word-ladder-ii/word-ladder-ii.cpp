class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string beginWord, vector<string>& path) {
        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (string& p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {

        unordered_set<string> dict(wordList.begin(), wordList.end());

        if (!dict.count(endWord))
            return {};

        unordered_map<string, int> level;

        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        while (!q.empty()) {

            string word = q.front();
            q.pop();

            int currLevel = level[word];

            string temp = word;

            for (int i = 0; i < temp.size(); i++) {

                char orig = temp[i];

                for (char ch = 'a'; ch <= 'z'; ch++) {

                    if (ch == orig)
                        continue;

                    temp[i] = ch;

                    if (!dict.count(temp))
                        continue;

                    if (!level.count(temp)) {

                        level[temp] = currLevel + 1;
                        parent[temp].push_back(word);
                        q.push(temp);
                    } else if (level[temp] == currLevel + 1) {

                        parent[temp].push_back(word);
                    }
                }

                temp[i] = orig;
            }
        }

        if (!level.count(endWord))
            return {};

        vector<string> path = {endWord};

        dfs(endWord, beginWord, path);

        return ans;
    }
};