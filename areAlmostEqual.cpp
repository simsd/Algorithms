class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int count = 0;
        int switch_index = -1;
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i] && switch_index == -1){
                count++;   
                switch_index = i;
            }
            else if(s1[i] != s2[i]){ 
                if(count > 2)
                    return false;
                else if(!(s1[switch_index] == s2[i] && s1[i] == s2[switch_index]))
                    return false;
                
                count++;
            }
            
        }
        
        if(count == 1)
            return false;
        
        return true;
    }
};
