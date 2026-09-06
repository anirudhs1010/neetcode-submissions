class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> s;
        vector<int> res(temperatures.size(), 0);
        stack<int> a;
        for (int i = 0; i < temperatures.size(); i++) {
            int ind = 1;
            while (!s.empty() && s.top() < temperatures[i]) {
                if (i - ind >= 0)
                    res[a.top()] = abs(a.top()-i);
                s.pop();
                a.pop();
                ind++;
            }
            s.push(temperatures[i]);
            a.push(i);
        }
        return res;
    }
};
