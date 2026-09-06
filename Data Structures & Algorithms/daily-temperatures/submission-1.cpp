class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> a;
        for (int i = 0; i < temperatures.size(); i++) {
            while (!a.empty() && temperatures[a.top()] < temperatures[i]) {
                res[a.top()] = abs(a.top()-i);
                a.pop();
            }
            a.push(i);
        }
        return res;
    }
};
