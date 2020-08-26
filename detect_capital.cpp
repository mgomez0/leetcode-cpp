#include <stdio.h>
#include <ctype.h>
#include <string>

class Solution {
public:
    bool result = false;
    bool not_all_caps_flag = false;
    bool all_caps_flag = false;
    bool error_flag = false;
    bool detectCapitalUse(std::string word) {
        if(islower(*word.begin())){
            for (auto it = word.cbegin(); it!= word.cend(); ++it){
                if(isupper(*it)){
                    return false;
                }
            }
            return true;
        }   else{
                    for (auto it = word.cbegin(); it!= word.cend(); ++it){
                        if(islower(*it) && not_all_caps_flag == false){
                            not_all_caps_flag = true;
                        } 
                        if(isupper(*it) && not_all_caps_flag == true ||
                            islower(*it) && all_caps_flag == true){
                            error_flag = true;
                        }

                        if(isupper(*it) && not_all_caps_flag == false){
                            all_caps_flag = true;
                        }
                    }
                    
                    if(not_all_caps_flag == true && error_flag == false ||
                        all_caps_flag == true && error_flag == false)
                    {
                        return true;
                    }

                }
            return false;
        }    
        
                
       
};

int main(){
    Solution sol;
    sol.detectCapitalUse("FFFFFFFFFFFFFFFFFFFFf");
}