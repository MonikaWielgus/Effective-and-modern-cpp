//Monika Wielgus
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>

using namespace std;

template<typename Container>
using IteratorCategoryOf=typename std::iterator_traits<typename Container::iterator>::iterator_category;

template<typename Container>
double median(Container &c, std::forward_iterator_tag){
    c.sort();
    int count=0;
    double sum=0;
    if(c.size()%2==0){
        for(auto &x: c){
            if(count==(c.size()/2)-1)
                sum+=x;
            else if(count==c.size()/2)
                return (sum+x)/2;
            count++;
        }
    }
    else{
        for(auto &x: c){
            if(count==c.size()/2)
                return x;
            count++;
        }
    }
}

template<typename Container>
double median(Container &c, std::random_access_iterator_tag){
    std::sort(c.begin(), c.end());
    if (c.size()%2==0)
        return (double)(c[c.size()/2-1]+c[c.size()/2])/2;
    else
        return c[c.size()/2];
}

template<typename Container>
double median(Container &c){
   median(c,IteratorCategoryOf<Container>());
}

int main() {
    std::list<int> a{3,2,5,1,4};
    cout << median(a) << endl;
    std::vector<int> v{3,1,4,2};
    cout << median(v) << endl;
}
