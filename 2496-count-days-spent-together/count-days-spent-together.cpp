class Solution {
public:

    int solve(string date, int days[]) {
        int month = stoi(date.substr(0,2));
        int day = stoi(date.substr(3));

        for(int i = 0; i < month - 1; i++) {
            day += days[i];
        }

        return day;
    }

    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

        string start = max(arriveAlice, arriveBob);
        string end = min(leaveAlice, leaveBob);

        if(start > end) return 0;

        return solve(end, days) - solve(start, days) + 1;
    }
};