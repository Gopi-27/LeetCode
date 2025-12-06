/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/
bool comp(Employee* a,Employee* b){
    return a->id < b->id;
}
class Solution {
public:
    int rec(vector<Employee*>&emp,int id){
        int low = 0;
        int high = emp.size() - 1;
        while(low <= high){
            int mid = (low + high) >> 1;
            if(emp[mid]->id == id){
                int sum = emp[mid]->importance;
                for(auto i : emp[mid]->subordinates){
                    sum += rec(emp,i);
                }
                return sum;
            }else if(emp[mid]->id < id){
                low = mid + 1;
            }else {
                high = mid - 1;
            }
        }
        return 0;
    }
    int getImportance(vector<Employee*> emp, int id) {
        sort(emp.begin(),emp.end(),comp);
        return rec(emp,id);
        return 0;
    }
};