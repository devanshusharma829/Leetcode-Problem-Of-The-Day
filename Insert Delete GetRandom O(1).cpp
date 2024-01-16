class RandomizedSet {
public:
    vector<int> nums;
    unordered_map<int, int> idxMap;
    RandomizedSet() { }

    bool insert(int val) {
        if (idxMap.find(val) != idxMap.end()) return false;
        nums.push_back(val);
        idxMap[val] = nums.size() - 1;
        return true;
    }

    bool remove(int val) {
        if (idxMap.find(val) == idxMap.end()) return false;
        int last = nums.back();
        idxMap[last] = idxMap[val];
        nums[idxMap[last]] = last;
        nums.pop_back();
        idxMap.erase(val);
        return true;
    }

    int getRandom() {
        return nums[rand() % nums.size()];
    }
};