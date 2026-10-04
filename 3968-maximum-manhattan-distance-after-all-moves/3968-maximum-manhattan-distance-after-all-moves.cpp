class Solution {
public:
    int maxDistance(string moves) {
        int x=0;
        int y=0;
        int wild=0;
        for(char ch:moves)
        {
            if(ch=='U')
            x--;
            else if(ch=='D')
            x++;
            else if(ch=='L')
            y--;
            else if(ch=='R')
            y++;
            else
            wild++;
        }
        return abs(x)+abs(y)+wild;
    }
};