class Solution {
public:
    int bs(vector<int> &arr, int x){
        int start = 0;
        int end = arr.size()-1;
        int ans = -1;
        while (start <= end)
        {
            int mid = (start + end) / 2;

            if (arr[mid] <= x)
                start = mid + 1;
            else
            {
                ans = mid;
                end = mid - 1;
            }
        }
        return ans==-1 ? ans : arr[ans];
    }
    

    int numMatchingSubseq(string s, vector<string>& words) {
	
		// First , we are mapping index of characters of given string to respective characters
        unordered_map<char,vector<int>> mp;
        for(int i=0;i<s.length();i++){
            mp[s[i]].push_back(i);
        }
          
        int count = words.size(); // initializing ans 
		
        for(auto w : words){
            int prev = -1;
            for(int j=0;j<w.size();j++){
				// Searching for strictly greater element than prev using binary search
                // int x = bs(mp[w[j]],prev);
                auto x = upper_bound(mp[w[j]].begin(),mp[w[j]].end(),prev);
				// If strictly greater element not found, the current subsequence cannot be formed.
                if(x == mp[w[j]].end()){
                    count--;
                    break;
                }
				// Else, updating the prev
                else{
                    prev = *x;
                }
            }
        }
        return count;
    }
};
