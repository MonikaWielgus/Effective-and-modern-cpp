//Monika Wielgus
#ifndef FILRER_H
#define FILTER_H
#include <utility>
#include <type_traits>

template<typename Container, typename Predicate>
class Filter{
    Container c;
    Predicate p;

public:
    Filter(Container cArg, Predicate pArg):c(cArg),p(pArg){}

    friend class iterator;

    class iterator{
    public:
        Filter &f;
        typename std::decay_t<Container>::iterator current;
        using T=decltype(*current); //type of *current
        iterator(Filter &f, bool end=false): f(f), current(end? f.c.end() : f.c.begin()){}
        const iterator& operator++(){
            while(true){
                current++;
                if(current==f.c.end())
                    break;
                if(f.p(*current))
                    break;
            }
            return *this;
        }
        iterator operator++(int){
            iterator it(*this);
            ++(*this);
            return it;
        }
        T& operator*(){
            return *current;
        }
        T operator*()const{
            return *current;
        }
        bool operator==(const iterator &it2){
            return current==it2.current;
        }
        bool operator!=(const iterator &it2){
            return current!=it2.current;
        }
    };

    iterator begin(){
        return iterator(*this);
    }
    iterator end(){
        return iterator(*this,true);
    }
};

template<typename Container, typename Predicate>
Filter<Container, Predicate> make_filter(Container && c, Predicate && p){
    return {std::forward<Container &&>(c), std::forward<Predicate &&>(p)};
};

#endif // FILRER_H
