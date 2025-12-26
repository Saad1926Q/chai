#include <cstddef>
#include <string>
#include <iostream>


int brute_force(const std::string &str,const std::string &pattern){

    std::size_t l1=str.size();
    std::size_t l2=pattern.size();

    if(l2>l1)
        return -1;

    for(std::size_t i=0;i<=l1-l2;i++){
        std::size_t j;
        for(j=0;j<l2;j++){
            if(str[i+j]!=pattern[j])
                break;
        }

        if(j==l2)
            return i;
    }

    return -1;
}


int main(){
    std::string my_str="hello world";
    std::string pattern="or";

    std::cout<<brute_force(my_str,pattern)<<"\n";
}
