#include <bits/stdc++.h>
using namespace std;

class Solution {
private:

    /* Function call to add the shortest 
    transformation using backtracking */
    void dfs(string word, string &beginWord, vector<string> &seq,
             unordered_map <string,int> &mpp, vector<vector<string>> &ans) {
        
        // If the sequence is complete
        if(word == beginWord) {
            
            // Reverse the sequence
            reverse(seq.begin(), seq.end());
            
            // Store in the result
            ans.push_back(seq);
            
            // Reverse again for other possible sequences
            reverse(seq.begin(), seq.end());
            
            // Return
            return;
        }
        
        // Steps to reach the word
        int val = mpp[word];
        
        // Try all possible transformations
        for(int i=0; i < word.length(); i++) {
            char original = word[i];
            
            for(char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                
                // If a possible transformations is found
                if(mpp.find(word) != mpp.end() && 
                   mpp[word] + 1 == val) {
                       
                    // Update the sequence
                    seq.push_back(word);
                    
                    // Make recursive DFS call
                    dfs(word, beginWord, seq, mpp, ans);
                    
                    // Pop back for backtracking
                    seq.pop_back();
                }
            }
            word[i] = original;
        }
    }

public:

    /* Function to determine number of steps
    to reach from start ward to target word */
    vector<vector<string>> findSequences(string beginWord, string endWord, 
                                         vector<string>& wordList) {
 
        // Length of words
        int len = beginWord.length();
        
        // Add all the words to a hashset
        unordered_set <string> st(wordList.begin(), 
                                  wordList.end());
                                  
        /* Hash map to store the minimum 
        steps needed to reach a word */
        unordered_map <string,int> mpp;
        
        // Queue for BFS traversal
        queue <string> q;
        
        // Pushing intial word in the queue
        q.push(beginWord);
        
        /* Erasing the initial word from 
        the set if it exists */
        st.erase(beginWord);
        
        // Step count
        int steps = 1;
        
        // Storing the intial pair in map
        mpp[beginWord] = steps;
        
        // Until the queue is empty
        while(!q.empty()) {
            
            // Get the word and steps
            string word = q.front();
            steps = mpp[word];
            q.pop();

            // Check for every possible transformation
            for(int i = 0; i < len; i++) {
                char original = word[i];
                
                for(char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    
                    // If a possible transformation is found
                    if(st.find(word) != st.end()) {
                        
                        // Store it in map
                        mpp[word] = steps+1;
                        
                        // Push in the queue
                        q.push(word);
                        
                        // Erase word from list
                        st.erase(word);
                    }
                }
                word[i] = original;
            }
        }

        /* Return an empty list if reaching the 
        target word is not possible */
        if(mpp.find(endWord) == mpp.end()) 
            return {};

        // To store the answer
        vector<vector<string>> ans;
        
        // To store the possible sequence of transformations
        vector <string> seq = {endWord};
        
        // Backtracking step
        dfs(endWord, beginWord, seq, mpp, ans);
        
        // Return the computed result
        return ans;

    }
};

int main() {
    
    string beginWord = "der", endWord = "dfs";
    vector<string> wordList = 
        {"des","der","dfr","dgt","dfs"};
    
    /* Creating an instance of 
    Solution class */
    Solution sol; 
    
    /* Function call to determine number of 
    steps to reach from start ward to target word */
    vector<vector<string>> ans = 
        sol.findSequences(beginWord, endWord, wordList);
    
    // Output
    cout << "The different sequences are:\n";
    for(int i=0; i < ans.size(); i++) {
        for(int j=0; j < ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}