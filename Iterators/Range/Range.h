//Monika Wielgus
#ifndef RANGE_H
#define RANGE_H
template <typename T>
class Range{
    T start=0;
    T stop;
    T step=1;
    T array[10];
    int lenght;
public:
    Range(T st, T sto, T s) : start(st),stop(sto),step(s){
        int i=0;
        for(T j=start; j<stop; j+=step){
            array[i]=j;
            i++;
        }
        lenght=i;
    };
    Range(T st, T sto) : start(st),stop(sto){
        int i=0;
        for(T j=start; j<stop; j+=step){
            array[i]=j;
            i++;
        }
        lenght=i;
    }
    Range(T sto) : stop(sto){
        int i=0;
        for(T j=start; j<stop; j+=step){
            array[i]=j;
            i++;
        }
        lenght=i;
    }

    class iterator;
    friend class iterator;

    class iterator{
        Range &r;
        unsigned int index;
    public:
        iterator(Range& rangeArg):r(rangeArg),index(0){}

        const iterator& operator++(){
            ++index;
            return *this;
        }
        iterator operator++(int){
            iterator it(*this);
            ++index;
            return it;
        }
        T& operator*() const{
            return r.array[index];
        }
        T* operator->() const{
            return &r.array[index];
        }
        bool operator<(const iterator* ite)const{
            return index<ite.index;
        }
        bool operator==(const iterator& ite){
            return index==ite.index;
        }
        bool operator!=(const iterator& ite){
            return index!=ite.index;
        }
        friend class Range;
    };

    iterator begin() {
        return iterator(*this);
    }
    iterator end(){
        iterator ite(*this);
        ite.index=lenght;
        return ite;
    }

};
template <typename T>
Range<T> make_range(T d, T d1, T d2){
    return Range<T>(d,d1,d2);
}

template <typename T>
Range<T> make_range(T d){
    return Range<T>(0,d,1);
}
#endif // RANGE_H
