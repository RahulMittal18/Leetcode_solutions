class FoodRatings {
public:
    map<string,map<int,set<string>>> mp;
    unordered_map<string,int> rat; 
    unordered_map<string,string> cui;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            mp[cuisines[i]][ratings[i]].insert(foods[i]);
            rat[foods[i]] = ratings[i];
            cui[foods[i]]=cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        int old = rat[food];
        rat[food] = newRating;
        string c = cui[food];
        auto it = mp[c][old].find(food);

        mp[c][old].erase(it);
        if(mp[c][old].size()==0) mp[c].erase(old);
        mp[c][newRating].insert(food);
    }
    
    string highestRated(string cuisine) {
        auto it2 = mp[cuisine].rbegin()->second; 
        return *it2.begin();
    }
};

