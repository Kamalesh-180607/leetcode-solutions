class Solution {
public:
 void merge(vector<vector<int>>& intervals, int left, int mid, int right) {
        vector<vector<int>> temp;
        int i = left, j = mid + 1;

        while (i <= mid && j <= right) {
            if (intervals[i][0] <= intervals[j][0]) {
                temp.push_back(intervals[i++]);
            } else {
                temp.push_back(intervals[j++]);
            }
        }

        while (i <= mid) temp.push_back(intervals[i++]);
        while (j <= right) temp.push_back(intervals[j++]);

        for (int k = left; k <= right; k++) {
            intervals[k] = temp[k - left];
        }
    }

    void mergeSort(vector<vector<int>>& intervals, int left, int right) {
        if (left >= right) return;

        int mid = left + (right - left) / 2;
        mergeSort(intervals, left, mid);
        mergeSort(intervals, mid + 1, right);
        merge(intervals, left, mid, right);
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        // mergeSort(intervals, 0, intervals.size() - 1);
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        for(int i=0;i<n;i++)
        {
            int start=intervals[i][0];int end=intervals[i][1];
            for(int j=i+1;j<n && intervals[j][0]<=end;j++)
            {
                end=max(end,intervals[j][1]);i++;
            }
            res.push_back({start,end});
        }
        return res;
    }
};