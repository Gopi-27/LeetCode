/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int GetPeakIdx(MountainArray &Mount){
        int low = 1;
        int high = Mount.length() - 2;
        while(low <= high){
            int mid = (low + high) >> 1;
            int prev = Mount.get(mid - 1);
            int curr = Mount.get(mid);
            int nxt = Mount.get(mid + 1);
            if(prev < curr && curr < nxt)low = mid + 1;
            else if(prev > curr && curr > nxt)high = mid - 1;
            else return mid;
        }
        return low;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int Pidx = GetPeakIdx(mountainArr);
        int low = 0;
        int high = Pidx;
        while(low <= high){
            int mid = (low + high) >> 1;
            int curr = mountainArr.get(mid);
            if(curr == target)return mid;
            else if(curr < target)low = mid + 1;
            else high = mid - 1;
        }
        low = Pidx;
        high = mountainArr.length() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            int curr = mountainArr.get(mid);
            if(curr == target)return mid;
            else if(target > curr)high = mid - 1;
            else low = mid + 1;
        }
        return -1;
    }
};