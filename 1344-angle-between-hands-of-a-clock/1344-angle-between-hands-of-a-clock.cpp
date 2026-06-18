class Solution {
public:
    double angleClock(int hour, int minutes) {
        // Hours Hand
        // 180 m -> 90
        // 1 m   -> ?
        // => 90/180

        // Min Hand
        // 15m -> 90
        // 1m  -> ?
        // => 90/15
        hour = hour % 12;
        double hdir = (hour * 60 + minutes) * 0.5;
        double mdir = (minutes) * 6;
        return min(abs(hdir - mdir), abs(360 - abs(hdir - mdir)));
    }
};