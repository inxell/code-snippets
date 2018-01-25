using namespace std;
typedef set<pair<int, int>>::iterator iiter;

class Intervals {
public:
    void add(const pair<int, int> & p){
        /// add interval p into member pset and merge overlapping intervals.
        if(p.first > p.second){
            throw runtime_error("Invalid Interval!");
        }
        auto piter = equalrange(p);
        if(piter.first != piter.second){
            int b = min(piter.first->first, p.first);
            int e = max((--piter.second)->second, p.second);
            pset.erase(piter.first, ++piter.second);
            pset.insert({b, e});
        }
        else{
            pset.insert(p);
        }
        return;
    }

    vector<pair<int, int>> intersect(const pair<int, int>& p) const{
        /// return intersection of p with intervals in pset.
        /// only intervals with posive width are returned.
        if(p.first > p.second){
            throw runtime_error("Invalid Interval!");
        }
        auto piter = equalrange(p);
        vector<pair<int,int>> res;
        for(auto iter = piter.first; iter != piter.second; ++iter){
            int b = max(p.first, iter->first);
            int e = min(p.second, iter->second);
            if(b < e) {
                res.push_back({b, e});
            }
        }
        return res;
    };


private:
    set<pair<int, int>> pset;
    pair<iiter, iiter> equalrange(const pair<int, int>& p) const{
        ''' 
        return a pair of iterators of pset,  (lit, rit), such that for any it within 
        [lit, rit), the interval *it intersets with p.
        '''
        auto lit = pset.lower_bound({p.first, p.first});
        auto rit = pset.lower_bound({p.second, p.second});
        if(lit != pset.begin() && (--lit)->second < p.first){
            ++lit;
        }
        if(rit != pset.end() && rit->first == p.second){
            ++rit;
        }
        return make_pair(lit, rit);
    }

};