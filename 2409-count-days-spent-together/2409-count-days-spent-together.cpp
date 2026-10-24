class Solution {
public:
 int days(string &str) {
    int month=stoi(str.substr(0,2));
    int day=stoi(str.substr(3,2));
    int days[] = {31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};

    int ans = day;

    for (int i = 0; i < month - 1; i++) {
        ans += days[i];
    }

    return ans;
}  
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int s1=days(arriveAlice);
        int e1=days(leaveAlice);
        int s2=days(arriveBob);
        int e2=days(leaveBob);

        int minStart=max(s1,s2);
        int minEnd=min(e1,e2);

        if(minStart<=minEnd)
        return minEnd-minStart+1;
        else
        return 0;
    }
};