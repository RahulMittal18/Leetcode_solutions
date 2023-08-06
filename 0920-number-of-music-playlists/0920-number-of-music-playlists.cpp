class Solution {
public:
    const int mod = 1e9+7;
    int dp[101][101];
    int solve(int playlistSize, int n, int goal, int k, int uniqueSongsPlayed){
        if(playlistSize==goal){
            return uniqueSongsPlayed==n;
        }
        if(dp[playlistSize][uniqueSongsPlayed]!=-1) return dp[playlistSize][uniqueSongsPlayed];
        
        int pickUnique = (1ll*solve(playlistSize+1,n,goal,k,uniqueSongsPlayed+1)*(n-uniqueSongsPlayed))%mod;
        int pickAgain =  (1ll*solve(playlistSize+1,n,goal,k,uniqueSongsPlayed)*(max(0,uniqueSongsPlayed-k)))%mod;
        
        return dp[playlistSize][uniqueSongsPlayed]=(pickUnique+pickAgain)%mod;
    }
    
    int numMusicPlaylists(int n, int goal, int k) {
        memset(dp,-1,sizeof dp);
        return solve(0,n,goal,k,0);
    }
};