class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // O(N*log(N))
        priority_queue<int,vector<int>,greater<int>> pq;
        unordered_map<int,vector<vector<int>>> map;
        for(int i=0;i<points.size();i++)
        {
            int sum=0;
            for(int j=0;j<points[i].size();j++)
            {
                sum+=pow(points[i][j],2);
            }
            pq.push(sum);
            map[sum].push_back(points[i]);
        }
        vector<vector<int>> ans;
        while(k)
        {
            int dist=pq.top();
            pq.pop();
            for(auto point : map[dist])
            {
                ans.push_back(point);
                k--;
                if(k == 0) break;
            }
        }
        return ans;
    }
};

// quickSelect algorithm
class Solution {
public:

    int squareDistance(vector<int> point)
    {
        return point[0] * point[0] + point[1] * point[1];
    }

    void quickselect(vector<vector<int>> &points,int left,int right,int k)
    {
        if(left >= right)   return;

        int pivotIndex=left + rand() % (right-left+1);
        int pivotDistance=squareDistance(points[pivotIndex]);

        swap(points[right],points[pivotIndex]);
        int storeIndex=left;

        for(int i=left;i<right;i++)
        {
            if(squareDistance(points[i]) <= pivotDistance)
            {
                swap(points[i],points[storeIndex]);
                storeIndex++;
            }
        }
        swap(points[right],points[storeIndex]);

        int leftCount=storeIndex-left+1;
        if(leftCount == k)
        {
            return;
        }
        else if(leftCount < k)
        {
            quickselect(points,storeIndex+1,right,k-leftCount);
        }
        else
        {
            quickselect(points,left,storeIndex-1,k);
        }

    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        quickselect(points,0,points.size()-1,k);
        return vector<vector<int>>(points.begin(),points.begin()+k);
    }
};
