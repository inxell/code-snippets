
class RangeModule {
public:
    set<pair<int, int>> intervals;

    void print(){
        for(auto p : intervals){
            cout << '[' << p.first << ',' << p.second << ']' << ',';
        }
    }


    void addRange(int left, int right) {
        if(intervals.empty() || intervals.begin()->first > right || intervals.rbegin()->second < left){
            intervals.insert({left, right});
            return;
        }
        auto lit = intervals.upper_bound({left, left});
        auto rit = intervals.upper_bound({right, INT_MAX});
        // rit != intervals.begin() due to first if statement.
        right = max(prev(rit)->second, right);
        if(lit != intervals.begin() && prev(lit)->second >= left){
            --lit;
        }
        left = min(left, lit->first);
        intervals.erase(lit, rit);
        intervals.insert({left, right});
    }

    bool queryRange(int left, int right) {
        auto it = intervals.lower_bound({left, right});
        if(it != intervals.end() && it->first == left) return true;
        if(it == intervals.begin()) return false;
        --it;
        return it->first <= left && it->second >= right;

    }

    void removeRange(int left, int right) {
        if(intervals.empty() || intervals.begin()->first >= right || intervals.rbegin()->second <= left){
            return;
        }
        auto lit = intervals.upper_bound({left, left});
        auto rit = intervals.upper_bound({right, right});
        int l = left, r = right;
        if(lit != intervals.begin() && prev(lit)->second > left){
            --lit;
        }
        if(lit->first < left){
            l = lit->first;
        }
        r = max(right, prev(rit)->second);
        intervals.erase(lit, rit);
        if(l != left) intervals.insert({l, left});
        if(r != right) intervals.insert({right, r});


    }
};

/**
 * Your RangeModule object will be instantiated and called as such:
 * RangeModule obj = new RangeModule();
 * obj.addRange(left,right);
 * bool param_2 = obj.queryRange(left,right);
 * obj.removeRange(left,right);
 */