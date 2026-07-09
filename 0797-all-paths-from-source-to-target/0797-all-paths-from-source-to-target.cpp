class Solution {
public:
    vector<int> temp;
    vector<vector<int>> result;

    void dfs(vector<vector<int>>& graph, int u, int target) {
        temp.push_back(u);

        if (u == target) {
            result.push_back(temp);
        } else {
            for (int v : graph[u]) {
                dfs(graph, v, target);
            }
        }

        temp.pop_back();   
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(graph, 0, graph.size() - 1);
        return result;
    }
};