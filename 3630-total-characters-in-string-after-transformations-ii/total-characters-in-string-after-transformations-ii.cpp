class Solution {
public:
    const long long M = 1e9+7;
    typedef vector<vector<int>> Matrix;
    Matrix matrixMul(Matrix &A, Matrix &B){
        Matrix C(26, vector<int> (26,0));
        for(int i =0; i<26; i++){
            for(int j =0; j<26; j++){
                for(int k =0; k<26; k++){
                    C[i][j] = (C[i][j] + (1LL * A[i][k] * B[k][j]) % M) % M;
                }
            }
        }
        return C;
    }
    //Matrix exponentiation
    Matrix matrixExpo(Matrix &base, int expo){
        if(expo == 0){
            Matrix I(26, vector<int>(26,0));        //identity matrix
            for(int i =0; i<26; i++){
                I[i][i] = 1;
            }
            return I;
        }
        Matrix half = matrixExpo(base, expo/2);
        Matrix result = matrixMul(half, half);
        if(expo % 2 == 1){
            result = matrixMul(result, base);
        } 
        return result;
    }
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int> freq(26, 0);
        for(auto ch : s){
            freq[ch - 'a']++;
        }

        //forming T
        Matrix T(26, vector<int>(26, 0));
        for(int i =0; i<26; i++){
            for(int add = 1; add<=nums[i]; add++){
                T[(i + add) % 26][i]++;
            }
        }

        Matrix result = matrixExpo(T, t);

        //multi T and initial freq
        vector<int> updated_freq(26, 0);
        for(int i = 0; i < 26; i++) {
            for(int j = 0; j < 26; j++){
                updated_freq[i] = (updated_freq[i] + (1LL * result[i][j] * freq[j]) % M) % M;
            }    
        }
        int resultLen = 0;
        for(int i=0; i<26; i++){
            resultLen = (resultLen + updated_freq[i]) % M;
        }
        return resultLen;
    }
};