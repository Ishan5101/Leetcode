class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<int> last(m, -1);

        int word2Index = m - 1;
        for (int word1Index = n - 1;
             word1Index >= 0 && word2Index >= 0;
             word1Index--) {

            if (word1[word1Index] == word2[word2Index]) {
                last[word2Index] = word1Index;
                word2Index--;
            }
        }

        vector<int> result(m);
        bool usedChange = false;

        word2Index = 0;
        for (int word1Index = 0;
             word1Index < n && word2Index < m;
             word1Index++) {

            char currentChar = word1[word1Index];
            char requiredChar = word2[word2Index];

       
            bool charactersMatch = (currentChar == requiredChar);

            bool canUseChange =
                !usedChange &&
                (word2Index == m - 1 ||
                 word1Index < last[word2Index + 1]);

            if (charactersMatch || canUseChange) {
                result[word2Index] = word1Index;

            
                if (!charactersMatch) {
                    usedChange = true;
                }

                word2Index++;
            }
        }
        if (word2Index < m) {
            return {};
        }

        return result;
    }
};