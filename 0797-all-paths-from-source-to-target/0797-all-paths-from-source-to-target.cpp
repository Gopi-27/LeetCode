class Solution {
public:
    void DFS(vector<vector<int>>& graph,int start,int target,vector<vector<int>>& Ans,vector<int> cur){
        cur.push_back(start);
        if(start == target){
            Ans.push_back(cur);
            return;
        }
        for(int i = 0; i < graph[start].size(); i++){
                DFS(graph,graph[start][i],target,Ans,cur);
            
        }
        return;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>Ans;
        vector<int>cur;
        DFS(graph,0,n - 1,Ans,cur);
        return Ans;
    }
};