class Solution {
public:
    int countLatticePoints(vector<vector<int>>& circles) {
        int res = 0;
        for (int i = 0; i <= 200; i++)
            for (int j = 0; j <= 200; j++) {
                for (auto& c : circles) {
                    if ((c[0] - i) * (c[0] - i) + (c[1] - j) * (c[1] - j) <= c[2] * c[2]) {
                        res++;
                        break;
                    }
                }
            }
        return res;
    }
};