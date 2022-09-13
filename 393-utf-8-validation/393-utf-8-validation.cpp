class Solution {
public:
    bool validUtf8(vector<int>& data) {
        bool started = false;
        int byte = 0;
        for(auto x: data){
            if(!started){
                if( (((1<<7) & x) == 0) ){
                    byte = 0;
                }
                else if( (((1<<7) & x) != 0) && (((1<<6) & x) != 0) && (((1<<5) & x) == 0) ){
                    started = true;
                    byte = 1;
                }
                else if( ((1<<7) & x) != 0 && ((1<<6) & x) != 0 && ((1<<5) & x) != 0 && ((1<<4) & x) == 0 ){
                    started = true;
                    byte = 2;
                }
                else if( ((1<<7) & x) != 0 && ((1<<6) & x) != 0 && ((1<<5) & x) != 0 && ((1<<4) & x) != 0 && ((1<<3) & x) == 0 ){
                    started = true;
                    byte = 3;
                }
                else{
                    return false;
                }
            }
            else{
                if(((1<<7) & x) != 0 && ((1<<6) & x) == 0 && byte > 0){
                    byte--;
                }
                else{
                    return false;
                }
                if(byte==0){
                    started = false;
                }
            }   
        }
        return byte==0;
    }
};