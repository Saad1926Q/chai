#include <cstddef>
#include <string>
#include <array>
#include <iostream>
#include <vector>

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

std::array<std::vector<int>, 128> create_dfa(const std::string &pattern){
    int m=pattern.size();

    std::array<std::vector<int>, 128> transition_fn; // Here each rows represents input character and column represnets the state

    for(std::size_t i=0;i<128;i++){
        transition_fn[i].resize(m,0);
    }

    transition_fn[static_cast<int>(pattern[0])][0]=1;

    int x=0;

    for(std::size_t j=1;j<m;j++){
        for(std::size_t i=0;i<128;i++){
            transition_fn[i][j]=transition_fn[i][x];
        }
        transition_fn[static_cast<int>(pattern[j])][j]=j+1;
        x=transition_fn[static_cast<int>(pattern[j])][x];
    }


    return transition_fn;
}

int search_dfa(const std::string &str,std::array<std::vector<int>, 128>transition_fn){
    int m=transition_fn[0].size();
    int l=str.size();

    int curr_state=0;
    for(std::size_t i=0;i<l;i++){
        curr_state=transition_fn[static_cast<int>(str[i])][curr_state];

        if(curr_state==m)
            return (i-m+1);

    }

    return -1;
}




int main(){
    std::string my_str="hello world";
    std::string pattern="ld";

    std::cout<<brute_force(my_str,pattern)<<"\n\n";

    std::array<std::vector<int>, 128> transition_fn=create_dfa(pattern);

    std::cout<<search_dfa(my_str,transition_fn)<<"\n\n";

}
