class Solution {
public:
    double angleClock(int hour, int minutes) {

        double mins = minutes * 6;
        double hrs = (hour * 30) + (minutes * 0.5);
        double ans = abs(mins - hrs);
        return min(ans, 360 - ans);
    }
};