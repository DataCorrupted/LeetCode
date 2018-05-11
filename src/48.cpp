class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n  = matrix.size();
        for (int i=0; i<n/2; i++){
            for (int j=0; j<n/2; j++){
                swap(matrix[i][j], matrix[n-j-1][i]);
                swap(matrix[n-j-1][i], matrix[n-i-1][n-j-1]);
                swap(matrix[n-i-1][n-j-1], matrix[j][n-i-1]);
            }
        }
        if (n & 1 == 1){
            int mid = n/2;
            for (int k=0; k<n/2; k++){
                swap(matrix[k][mid], matrix[mid][k]);
                swap(matrix[mid][k], matrix[n-k-1][mid]);
                swap(matrix[n-k-1][mid], matrix[mid][n-k-1]);
            }
        }
    }
};