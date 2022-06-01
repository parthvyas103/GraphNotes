class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordlist) {
        queue<string> q;
        unordered_set<string> dict(wordlist.begin(), wordlist.end());
        
        q.push(beginWord);
        int res = 1;
        
        while(!q.empty()){
            int n = q.size();
            for(int i = 0; i < n; i++){
                string word = q.front();
                q.pop();
                if(word == endWord)
                    return res;
                dict.erase(word);
                for(int j = 0; j < word.size(); j++){
                    char c = word[j];
                    for(int k = 0; k < 26; k++){
                        word[j] = 'a' + k;
                        if(dict.find(word) != dict.end()){
                            q.push(word);
                            dict.erase(word);
                        }
                    }
                    word[j] = c;
                }
            }
            res++;
        }
        
        return 0;
    }
};
