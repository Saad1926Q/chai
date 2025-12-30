#include <cstddef>
#include <vector>
#include "search.hpp"

std::vector<int> createFailureLinks(const std::string& pattern){
    std::size_t m=pattern.size();
    std::vector<int>failureLinks;

    failureLinks.resize(m,0);

    failureLinks[0]=0;
    int x=0;


    for(std::size_t i=1;i<m;i++){
        failureLinks[i]=x;

        while(pattern[x]!=pattern[i]){
            if(x==0){
                x--;
                break;
            }else {
                x=failureLinks[x];
            }
        }

        x++;
    }

    return failureLinks;
}


int KMP(const std::string& str,const std::string& pattern){
    std::vector<int> fail=createFailureLinks(pattern);
    int n=str.size(); // Length of string
    int m=pattern.size(); // Length of pattern

    int i=0; // Current position in str
    int q=0; // Current state in KMP automaton

    while(i<n){
        if(str[i]==pattern[q]){
            i++;
            q++;

            if(q==m)
                return i-q;
        }else{
            if(q>0)
                q=fail[q];
            else
                i++;
        }
    }

    return -1;
}

namespace chai{
    int search(const std::string& str,const std::string& pattern){
        return KMP(str, pattern);
    }
}
