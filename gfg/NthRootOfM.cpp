// problem link: https://practice.geeksforgeeks.org/problems/nth-root-of-m5849/1
class Solution {
public:
    int checkIfBig(int mid, int N, int M) {
        long long result = 1;

        for (int i = 0; i < N; i++) {
            result *= mid;

            if (result > M) {
                return 1;
            }
            else if (result == M && i == N - 1) {
                return -1;
            }
        }

        return 0;
    }

    int nthRoot(int N, int M) {
        // Code here
        if (M == 0) {
            return 0;
        }

        int start = 1;
        int end = M;
        int mid = -1;

        while (start <= end) {
            mid = start + (end - start) / 2;

            int num = checkIfBig(mid, N, M);

            // cout << start << " " << mid << " " << end << " " << num << endl;

            if (num == -1) {
                return mid;
            }
            else if (num == 1) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }

        return -1;
    }
};