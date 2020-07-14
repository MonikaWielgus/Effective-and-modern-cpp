//Monika Wielgus
#include <iostream>
#include <algorithm>
#include <cctype>
#include <map>

using namespace std;

void toLowerAlpha(std::string & s1){
    s1.erase(std::remove_if(s1.begin(),s1.end(),[](unsigned char c){return !std::isalpha(c);}),s1.end());
    std::transform(s1.begin(), s1.end(), s1.begin(),[](unsigned char c) -> unsigned char{ return std::tolower(c);});
}
int main(){
    int count=1;
    std::string word;
    std::map<std::string,int> mapOfWords;
    while(cin>>word&&word!="0"){ //0 needs to be add at the end of the input because it doesn't stop without it
       toLowerAlpha(word);
       auto index=mapOfWords.find(word);
       if(!word.empty() && index==mapOfWords.end()){
           mapOfWords.insert(std::pair<std::string,int>(word,1));
       }
       else{
           index->second++;
           count++;
       }

    }
    auto it = mapOfWords.begin();
    std::multimap<int,std::string> multi;
    while(it!= mapOfWords.end()){
        std::string w=it->first;
        int number=it->second;
        it++;
        multi.insert(std::pair<int,std::string>(number,w));
    }
    cout << "Number of distinct words : " << mapOfWords.size() << endl;
    cout << "\nThe top 20 most popular words: \n";
    auto iter = multi.end();
    for(int i=0; i<=20; i++){
        iter--;
        cout << iter->second << ": " << iter->first << endl;
    }
    return 0;
}

