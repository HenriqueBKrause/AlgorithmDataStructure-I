

class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) {
            return {};
        }
        
        // Ordenar os intervalos com base no início
        std::sort(intervals.begin(), intervals.end(), [](const std::vector<int>& a, const std::vector<int>& b) {
            return a[0] < b[0];
        });
        
        std::vector<std::vector<int>> merged;
        merged.push_back(intervals[0]);
        
        for (int i = 1; i < intervals.size(); ++i) {
            std::vector<int>& current = intervals[i];
            std::vector<int>& lastMerged = merged.back();
            
            if (current[0] <= lastMerged[1]) {
                // Os intervalos se sobrepõem, mesclar
                lastMerged[1] = std::max(lastMerged[1], current[1]);
            } else {
                // Os intervalos não se sobrepõem, adicionar o atual à lista mesclada
                merged.push_back(current);
            }
        }
        
        return merged;
    }
};
