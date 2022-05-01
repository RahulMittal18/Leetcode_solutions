class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = A.size();
        vector<int> result(n);
        int i = 0, j = n - 1;
        for (int p = n - 1; p >= 0; p--) {
            if (abs(A[i]) > abs(A[j])) {
                result[p] = A[i] * A[i];
                i++;
            } else {
                result[p] = A[j] * A[j];
                j--;
            }
        }
        return result;
    }
};