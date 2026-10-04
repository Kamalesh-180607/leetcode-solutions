class Solution {
public:
    int distMoney(int money, int children) {
        if(money<children)return -1;
        int ans=0;
        money-=children;
        while(children>0 && money>=7)
        {
            children--;
            money-=7;
            ans++;
        }
        if(children==0 && money>0)
        ans--;
        if(children==1 && money==3)
        ans--;
        return ans;
    }
};