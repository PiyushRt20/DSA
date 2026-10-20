class Solution {
public:
    // Build the LPS array for KMP
    void computeLPS(vector<int>& pattern, vector<int>& lps) {
        int len = 0;

        for (int i = 1; i < pattern.size();) {
            if (pattern[i] == pattern[len]) {
                lps[i++] = ++len;
            } 
            else if (len > 0) {
                len = lps[len - 1];
            } 
            else {
                lps[i++] = 0;
            }
        }
    }

    // Check whether pattern exists in text
    bool search(vector<int>& pattern, vector<int>& text) {
        int n = text.size(), m = pattern.size();

        if (m == 0) return true;
        if (m > n) return false;

        vector<int> lps(m, 0);
        computeLPS(pattern, lps);

        int i = 0, j = 0;

        while (i < n) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
            }

            if (j == m) return true;

            if (i < n && text[i] != pattern[j]) {
                if (j > 0)
                    j = lps[j - 1];
                else
                    i++;
            }
        }

        return false;
    }

    // A rotation of a vector appears in vec + vec
    bool isRotation(vector<int>& vec, vector<int>& target) {
        vector<int> doubled = vec;
        doubled.insert(doubled.end(), vec.begin(), vec.end());

        return search(target, doubled);
    }

    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();

        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        int answer = 0;

        for (int k = 1; k <= n; k++) {
            if (n % k != 0) continue;

            bool valid = true;

            for (int start = 0; start < n; start += k) {
                vector<int> originalBlock(
                    nums.begin() + start,
                    nums.begin() + start + k
                );

                vector<int> sortedBlock(
                    sorted.begin() + start,
                    sorted.begin() + start + k
                );

                if (!isRotation(originalBlock, sortedBlock)) {
                    valid = false;
                    break;
                }
            }

            if (valid) answer += k;
        }

        return answer;
    }
};