#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countHours(vector<int> &piles, int mid) {
        cout << "new mid : " << endl;
        int ans = 0;
        for (int i = 0; i < piles.size(); i++) {
            cout << ceil((double)piles[i] / mid) << " ";
            ans += ceil((double)piles[i] / mid);
        }
        cout << " hours " << ans << endl;  // Ensure this prints properly
        return ans;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1, end = *max_element(piles.begin(), piles.end());
        int mid;
        
        while (start <= end) {
            mid = (end - start) / 2 + start;
            cout << "Start: " << start << ", End: " << end << ", Mid: " << mid << endl;

            int hours = countHours(piles, mid);
            cout << "Hours required: " << hours << endl;

            if (hours <= h) {
                cout << "Updating End to " << mid - 1 << endl;
                end = mid - 1;
            } else {
                cout << "Updating Start to " << mid + 1 << endl;
                start = mid + 1;
            }
        }
        return start;
    }
};

int main() {
    Solution sol;
    vector<int> piles = {3, 6, 7, 11};  // Example test case based on your given output
    int h = 8;
    int result = sol.minEatingSpeed(piles, h);
    cout << "Final Result: " << result << endl;
    return 0;
}
