//Monika Wielgus
#ifndef VECTALG_H
#define VECTALG_H

#include <memory>
#include <iostream>
#include <cassert>
#include <vector>
#include <cmath>

template <typename T>
class vector_traits{
public:
    typedef T VectorType;
    typedef const VectorType&  VectorGetType;
    typedef const VectorType& VectorSetType;
    typedef T ScalarType;
    static T defaultValue(){
        return 0;
    }
    static auto multiplication(ScalarType s, VectorType v){
        return s*v;
    }
};
template <>
class vector_traits<int>{
public:
    typedef int VectorType;
    typedef VectorType  VectorGetType;
    typedef VectorType VectorSetType;
    typedef int ScalarType;
    static int defaultValue() {
        return 0;
    }
    static auto multiplication(ScalarType s, VectorType v){
        return s*v;
    }
};
template <>
class vector_traits<double>{
public:
    typedef double VectorType;
    typedef VectorType  VectorGetType;
    typedef VectorType VectorSetType;
    typedef double ScalarType;
    static double defaultValue(){
        return 0;
    }
    static auto multiplication(ScalarType s, VectorType v){
        return s*v;
    }
};
template<>
class vector_traits<std::string>{
public:
    typedef std::string VectorType;
    typedef const VectorType&  VectorGetType;
    typedef const VectorType& VectorSetType;
    typedef int ScalarType;
    static std::string defaultValue(){
        return "0";
    }
    static auto multiplication(ScalarType s, VectorType v){
        VectorType v2=v;
        for(int i=0; i<s-1; i++)
            v+=v2;
        return v;
    }
};
template <typename T, size_t N>
class Vector {
    typedef typename vector_traits<T>::VectorGetType VectorGetType;
    typedef typename vector_traits<T>::VectorSetType VectorSetType;
    typedef typename vector_traits<T>::ScalarType ScalarType;
    T data[N];
public:
    typedef T value_type;
    typedef std::size_t  size_type;
    typedef T* pointer;
    typedef T& reference;
    typedef const T& const_reference;

    Vector()=default;
    Vector(const Vector & v)=default;
    Vector &operator=(const Vector & m)=default;

    Vector(const std::initializer_list<T> &list){
        std::copy(list.begin(), list.end(), data);
    }
    size_type size() const {
        return N;
    }

    VectorGetType get(size_type index) const {
        return data[index];
    }

    void set(size_type index, VectorSetType value) {
        data[index] = value;
    }

    friend Vector operator*(const ScalarType & x, const Vector & v ){
        Vector result;
        for(int i=0; i < v.size(); ++i){
            result.set(i, vector_traits<T>::multiplication(x,v.get(i)));
        }
        return result;
    }

    friend std::ostream &operator<<(std::ostream &out, const Vector & v) {
        for(int i=0; i < v.size(); ++i){
            out << v.get(i) << " ";
        }
        return out;
    }

    friend std::istream &operator>>(std::istream &in, Vector & v) {
        Vector::value_type value;
        for(int i=0; i < v.size(); ++i){
            in >> value;
            if(in)
                v.set(i, value);
        }
        return in;
    }
};

#endif //GAUSS_VECTALG_H
