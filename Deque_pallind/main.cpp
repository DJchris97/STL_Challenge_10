#include <iostream>
#include <cctype>
#include <string>
#include <deque>
#include <vector>
#include <iomanip>
#include <fstream>

//function prototype
bool is_pallindrome ( const std::string &s);


int main()
{
    
    
    std::vector<std::string> test_strings{ "a", "aa", "aba", "abba", "abbcbba", "ab", "abc", "radar", "bob", "ana",
        "avid diva", "Amore, Roma", "A Toyota's a toyota", "A Santa at NASA", "C++",
        "A man, a plan, a cat, a ham, a yak, a yam, a hat, a canal-Panama!", "This is a palindrome", "palindrome" };
   
    std::cout << std::boolalpha;
    
    std::fstream out_file {"pallin_rep.txt", std::ios::out};
    
    if(!out_file){
            std::cerr<<"pallin_rep.txt did not open successfully";
            
    } else{
        
            std::cout << std::setw(8) << std::left << "Result" << "String" << std::endl;
            out_file<< "Result" <<"   "<< "String" <<"\n";
    
                for(const auto& s : test_strings) {
                    std::cout << std::setw(8) << std::left << is_pallindrome(s)  << s << std::endl;
                    out_file<< is_pallindrome(s) <<"        "<< s <<"\n";
                    
                }
            std::cout << std::endl;
        
    }
    
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