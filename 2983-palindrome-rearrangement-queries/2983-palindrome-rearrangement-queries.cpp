class Solution {
public:
    const static int N = 1e5 + 5;
    int fs[N][26], ft[N][26];
    vector<int> equalPre;
    
    int getEqual(int l,int r){
        if(l>r) return 0;
        return l==0 ? equalPre[r] : equalPre[r]-equalPre[l-1];
    }
    
    int charFreq(int f[N][26], int c, int l, int r){
        if(l>r) return 0;
        return l==0 ? f[r][c] : f[r][c]-f[l-1][c];
    }
    
    
    bool canMakeEqual(int l,int r){
        bool ok = true;
        for(int i=0;i<26;i++){
            ok &= charFreq(fs,i,l,r)==charFreq(ft,i,l,r);
        }
        return ok;
    }
    
    bool isEqualLeft(int a[26], int b[26]){
        bool ok = true;
        for(int i=0;i<26;i++) {ok &= (a[i]==b[i]);}
        return ok;
    }
    
    vector<bool> canMakePalindromeQueries(string str, vector<vector<int>>& queries) {
        int n = str.size()/2;
        int q = queries.size();
        vector<bool> ans(q,false);
        
        string s,t;
        for(int i=0;i<n;i++){
            s.push_back(str[i]);
            t.push_back(str[2*n-i-1]);
        }
        equalPre.resize(n,0);
        for(int i=0;i<n;i++){
            if(s[i]==t[i]) equalPre[i] = 1;
            if(i) equalPre[i]+=equalPre[i-1];
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                fs[i][j] = ft[i][j] = 0;
            }
        }
        
        for(int i=0;i<n;i++){
            fs[i][s[i]-'a'] = 1;
            ft[i][t[i]-'a'] = 1;
            for(int j=0;j<26;j++){
                if(i) {
                    fs[i][j] += fs[i-1][j];
                    ft[i][j] += ft[i-1][j];
                } 
            }
        }
        
        for(int i=0;i<queries.size();i++){
            vector<int> query = queries[i];
            int l1 = query[0];
            int r1 = query[1];
            int l2 = 2*n - query[3] - 1;
            int r2 = 2*n - query[2] - 1;
            int L = min(l1,l2);
            int R = max(r1,r2);
            
            
            /* non-overlapping */
            
            //     ---l1..r1--------
            //     ----------l2..r2-  
            
            if(r1<l2){
                int nop1 = getEqual(0,l1-1);
                int nop2 = getEqual(r1+1,l2-1);
                int nop3 = getEqual(r2+1,n-1);
                
                if(nop1!=l1 || nop2!=l2-r1-1 || nop3!=n-r2-1){
                    ans[i] = false;
                    continue;
                }

                
                if(!canMakeEqual(l1,r1) || !canMakeEqual(l2,r2)){
                    ans[i] = false;
                    continue;
                }

                ans[i] = true;
                continue;
                
            }

            //     ----------l1..r1- 
            //     ---l2..r2--------
            
            if(r2<l1){
                int nop1 = getEqual(0,l2-1);
                int nop2 = getEqual(r2+1,l1-1);
                int nop3 = getEqual(r1+1,n-1);

                if(nop1!=l2 || nop2!=l1-r2-1 || nop3!=n-r1-1){
                    ans[i] = false;
                    continue;
                }
                
                if(!canMakeEqual(l1,r1) || !canMakeEqual(l2,r2)){
                    ans[i] = false;
                    continue;
                }
                
                ans[i] = true;
                continue;    
            }
            
            
            /* containing */
            
            //     ---l1.......r1-----
            //     ------l2..r2-------
            
            
            //     ------l1..r1-------
            //     ---l2.......r2-----
            
            if((l1<=l2 && r1>=r2) || (l2<=l1 && r2>=r1) ){
                int nop1 = getEqual(0,L-1);
                int nop2 = getEqual(R+1,n-1);
                
                if(nop1!=L || nop2!=n-R-1){
                    ans[i] = false;
                    continue;
                }
                
                if(!canMakeEqual(L,R)){
                    ans[i] = false;
                    continue;
                }
                
                ans[i] = true;
                continue;  
            }

            
            /* partial overlap */
            
            int ofs[26],oft[26];
            
            for(int kk=0;kk<26;kk++){
                ofs[kk] = charFreq(fs,kk,L,R);
                oft[kk] = charFreq(ft,kk,L,R);
            }
            
            
            //     ---l1...r1------
            //     ------l2....r2--
            
            if(l1<l2){
                int nop1 = getEqual(0,l1-1);
                int nop3 = getEqual(r2+1,n-1);
                
                if(nop1!=l1 || nop3!=n-r2-1){
                    ans[i] = false;
                    continue;
                }
                
                bool ok = true;
                
                for(int j=0;j<26;j++){
                    int reqd = charFreq(ft,j,l1,l2-1);
                    ok &= ofs[j]>=reqd;
                    ofs[j]-=reqd;
                    oft[j]-=reqd;
                }
                
                for(int j=0;j<26;j++){
                    int reqd = charFreq(fs,j,r1+1,r2);
                    ok &= oft[j]>=reqd;
                    oft[j]-=reqd;
                    ofs[j]-=reqd;
                }
                
                ok &= isEqualLeft(ofs,oft);
                
                ans[i] = ok;
                continue;
            }
            

            //     ------l1....r1--
            //     ---l2...r2------
                        
            if(l1>l2){
                int nop1 = getEqual(0,l2-1);
                int nop3 = getEqual(r1+1,n-1);
                
                if(nop1!=l2 || nop3!=n-r1-1){
                    ans[i] = false;
                    continue;
                }
                
                bool ok = true;

                for(int j=0;j<26;j++){
                    int reqd = charFreq(fs,j,l2,l1-1);
                    ok &= oft[j]>=reqd;
                    oft[j]-=reqd;
                    ofs[j]-=reqd;
                }

                for(int j=0;j<26;j++){
                    int reqd = charFreq(ft,j,r2+1,r1);
                    ok &= ofs[j]>=reqd;
                    ofs[j]-=reqd;
                    oft[j]-=reqd;
                }

                ok &= isEqualLeft(ofs,oft);

                ans[i] = ok;
                continue;
            }         
        }    
        
        
        return ans;
    }
};