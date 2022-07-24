class FoodRatings {
public:
    unordered_map<string,multiset<pair<int,string>>> mp;
    unordered_map<string,int> rat; 
    unordered_map<string,string> cui;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            mp[cuisines[i]].insert({-ratings[i],foods[i]});
            rat[foods[i]] = ratings[i];
            cui[foods[i]]=cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        string c = cui[food];
        auto it = mp[c].erase({-rat[food],food});
        rat[food] = newRating;
        mp[c].insert({-newRating,food});
    }
    
    string highestRated(string cuisine) {
        return (*mp[cuisine].begin()).second;
    }
};
