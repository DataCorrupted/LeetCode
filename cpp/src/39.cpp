class Solution {
public:
    map<int, vector<vector<int> > > combo_map;
    const vector<vector<int> > recursiveCombSum(const vector<int>& candidates, const int target){
        if (combo_map[target].size() != 0){
            return combo_map[target];
        }
        for (int i=0; i<candidates.size(); i++){
            if (target - candidates[i] >= 0){
                auto temp = recursiveCombSum(candidates, target-candidates[i]);
                for (int j=0; j<temp.size(); j++){
                    auto vec = temp[j];
                    if (vec.size() == 0 || candidates[i] <= vec[0]){
                        vec.insert(vec.begin(), candidates[i]);
                        combo_map[target].push_back(vec);
                    }
                }
            }
        }
        return combo_map[target];
    }
        
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        combo_map[0] = vector<vector<int> >();
        combo_map[0].push_back(vector<int>());
        sort(candidates.begin(), candidates.end());
        return recursiveCombSum(candidates, target);
    }
};

int main(){
	int arr[] = {5,10,8,4,3,12,9};
	vector<int> v = vector<int>(arr, arr + 7);
	Solution s;
	auto vec = s.combinationSum(v, 27);
	for (int i=0; i<vec.size(); i++){
		for (int j=0; j<vec[i].size(); j++){
			cout << vec[i][j] << " ";
		}
		cout << "\n";
	}
}