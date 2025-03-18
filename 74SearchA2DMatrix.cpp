// problem link
// https://leetcode.com/problems/search-a-2d-matrix/description/
class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int n = matrix.size(),m = matrix[0].size();
            int start = 0,end = n * m - 1;
            while(start <= end)
            {
                int mid = (end - start)/2 + start;
                int row = mid/m,col = mid%m;
                if(matrix[row][col] == target)
                {
                    return true;
                }
                else if(target < matrix[row][col])
                {
                    end = mid - 1;
                }
                else
                {
                    start = mid + 1;
                }
            }
            return false;
        }
    };