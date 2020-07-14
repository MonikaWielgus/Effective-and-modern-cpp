//Monika Wielgus
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <numeric>
#include <cctype>

template <typename Container>
void print(const Container & c){
    std::copy ( c.begin(), c.end(), std::ostream_iterator<int> (std::cout,", "));
    std::cout << std::endl;
}

void toLowerAlpha(std::string & s1){
    s1.erase(std::remove_if(s1.begin(),s1.end(),[](unsigned char c){return !std::isalpha(c);}),s1.end());
    std::transform(s1.begin(), s1.end(), s1.begin(),[](unsigned char c) -> unsigned char{ return std::tolower(c);});
}

bool isAnagram(std::string word1, std::string word2){
    toLowerAlpha(word1);
    toLowerAlpha(word2);
    if(std::equal (word1.begin(), word1.end(), word2.begin()))
        return false;
    std::sort(word1.begin(),word1.end());
    std::sort(word2.begin(),word2.end());
    return std::equal(word1.begin(), word1.end(), word2.begin());
}
void isAnagramTest(const std::string & s1, const std::string & s2){
    std::cout << "isAnagram(\"" << s1 << "\", \""<< s2 << "\") = ";
    std::cout << std::boolalpha << isAnagram(s1, s2) << std::endl;
}
int main(){

    constexpr int N = 10;
    std::vector<int> v(N);
    std::iota(v.begin(),v.end(),-5);
    print(v);

    std::vector<int> odd;
    std::copy_if(v.begin(),v.end(),std::back_inserter(odd), [](int x){return x%2!=0;});
    print(odd);

    std::transform(v.begin(), v.end(), v.begin(),[](int x){return x*x-1;});
    print(v);

    std::vector<int> intersect;

    std::sort(v.begin(),v.end());
    std::set_intersection(v.begin(),v.end(),odd.begin(),odd.end(),std::back_inserter(intersect));

    print(intersect);

    isAnagramTest("male", "lame");
    isAnagramTest(" Ala $%", "%%Ala%%ska%");
    isAnagramTest(" Ala $%", "%%la%%a%");
    isAnagramTest("A l a", "ALA");
}

