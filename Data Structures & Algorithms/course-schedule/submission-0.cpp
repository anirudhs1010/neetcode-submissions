class Solution {
public:
    map<int, vector<int>> m;
    set<int> s;
    bool dfs(int crn) {
        if (m[crn].empty()) {
            return true;
        }
        if (s.count(crn) == 1)
            return false;
        s.insert(crn);
        vector<int> v = m[crn];
        for (int i = 0; i < v.size(); i++) {
            if (!dfs(v[i]))
                return false;
        }
        s.erase(crn);
        m[crn].clear();
        return true;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for (int i = 0; i < numCourses; i++) {
            m[i] = {};
        }
        for (int i = 0; i < prerequisites.size(); i++) {
            vector<int> c = prerequisites[i];
            m[c[0]].push_back(c[1]);
        }
        for (int i = 0; i < numCourses; i++) {
            if (!dfs(i))
                return false;
        }
        return true;
    }
};
