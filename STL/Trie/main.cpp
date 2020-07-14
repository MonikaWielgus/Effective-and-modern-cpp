//Monika Wielgus
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
using namespace std;

class Trie{
    bool lastWord;
    map<std::string, Trie*> map;
public:
    Trie* getNewTrieNode(){
        Trie* node=new Trie;
        node->lastWord=false;
        return node;
    }
    void insert(Trie*& root, const std::vector<std::string> &str){
        if(root==nullptr)
            root=getNewTrieNode();

        Trie* temp=root;
        for(auto it: str){
            Trie *node=temp->map[it];
            if(!node){
                node=getNewTrieNode();
                temp->map[it]=node;
            }
            temp=node;
        }
        temp->lastWord=true;
    }
    static void printSentence(const std::vector<std::string> &sentence){
        for(const auto & w : sentence)
            cout << w << " ";
    }
    void add(const std::vector<std::string> &sentence){
        cout << "Adding : ";
        printSentence(sentence);
        cout << "\n";
        Trie* root=this;
        insert(root,sentence);

    }
    void printPossibleEndings(const std::vector<std::string> &beginningOfSentence){
        cout << "Endings for \"";
        printSentence(beginningOfSentence);
        cout << "\" are :\n";
        Trie* temp=this;
        for(auto it: beginningOfSentence){
            Trie *node=temp->map[it];
            if(!node)
                return;
            temp=node;
        }
        vector<std::string> e;
        go(temp,e);
        cout<<endl;

    }
    void go(Trie* trie, vector<std::string> end){
        if(trie==nullptr)
            return;

        for(auto i: trie->map){
            if(i.second->lastWord){
                end.push_back(i.first);
                for(int i=0; i<end.size(); i++){
                    cout << end[i] << " ";
                }
                cout << endl;
                end.pop_back();

            }
            else{
                end.push_back(i.first);
                go(i.second, end);
                end.pop_back();
            }
        }
    }

    void load(const std::string & fileName){
        ifstream file(fileName);
        if(!file){
            cerr << "Error when openning file " << fileName << endl;
            return;
        }
        string word;
        vector<string> sentence;
        while( file >> word) {
            sentence.push_back(word);
            // is it lastWord of the sentence?
            if(word.find_last_of('.') != string::npos) {
                add(sentence);
                sentence.clear();
            }
        }
    }
};


int main(){
    Trie dictionary;
    dictionary.load("../sample.txt");

    dictionary.printPossibleEndings({"Curiosity"});
    dictionary.printPossibleEndings({"Curiosity", "killed"});
    dictionary.printPossibleEndings({"The", "mouse","was","killed"});

    return 0;
}

