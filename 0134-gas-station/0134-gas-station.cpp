class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n=gas.size();
        int currTank=0,totalTank=0,start=0;
        for(int i=0;i<n;i++)
        {
            int diff=gas[i]-cost[i];
            currTank+=diff;
            totalTank+=diff;
            if(currTank<0)
            {
                currTank=0;
                start=i+1;
            }
        }
        return totalTank>=0?start:-1;
        //TLE
        // int n=gas.size();
        // for(int i=0;i<n;i++)
        // {
        //     if(gas[i]<cost[i])
        //     continue;

        //     int j=(i+1)%n;
        //     int rem=gas[i]-cost[i];
        //     while(j!=i && gas[j]+rem>=cost[j])
        //     {
        //         rem+=gas[j];
        //         rem-=cost[j];
        //         j=(j+1)%n;
        //     }
        //     if(j==i)return i;
        // }
        // return -1;
    }
};