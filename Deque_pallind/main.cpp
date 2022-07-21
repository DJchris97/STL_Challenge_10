#include <iostream>
#include <cctype>
#include <string>
#include <deque>



//function prototype
bool is_pallindrome ( const std::string &s);


int main() {
    std::cout <<is_pallindrome("quy.12yu0q")<< std::endl;
    
	return 0;
}


bool is_pallindrome ( const std::string &s){
    
    int n{0};
    std::deque <char> pall;
    
    for (const auto &i: s ){
        
        if (isalpha(i) != 0 ){
            
            pall.push_back (std::toupper(i));
        }
    }
    
    if (pall.size() == 1) {
        return true;
        
    }else{
        int length = pall.size()/2 ;
    
    while ( (n < length) & (pall.at(n) == pall.at(pall.size()-n-1)) ){
        ++n;   
        } 
        
        if(n == length)
            return true;
        else
            return false;
    }
}