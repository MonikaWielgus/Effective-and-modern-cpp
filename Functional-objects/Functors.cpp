//Monika Wielgus
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

class Printer{
    string first;
    string last;
    ostream &x;
public:
    Printer(ostream &os, string one, string two) : x(os), first(one), last(two){}

    template <typename T>
    ostream& operator()(T text){
        return x << first << text << last;
    }
};

int main(){
    Printer print(std::cout, "[ ", " ] ");
    print("hello");
    std::vector<int> v = {1, 2, 3, 4};
    std::for_each(v.begin(), v.end(), print);

    std::ofstream file("myFile.txt");
    Printer filePrinter(file, "- ", "\n");
    filePrinter(5);
    filePrinter("My text");
    return 0;
}

