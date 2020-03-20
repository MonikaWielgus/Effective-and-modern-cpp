//Monika Wielgus
#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

class String{
    shared_ptr<string> str;
public:
    String(size_t=0);// creates an empty string
    String(const char *); // copy C-string
    String(const String & ); // no copy
    String operator=(const String &); // no copy
    char & operator[](int i); // makes a copy of a string if it has more than one reference.
    char operator[](int i) const; // no copy
    friend String operator+(String a, String b); // concatenation creates a new string only if both strings are non empty
    friend std::ostream & operator<< (std::ostream & out, const String &); // no copy

};

String::String(size_t size) : str(new string(size, ' ')){}
String::String(const char * s){
    str=std::make_shared<string>(s);
}
String::String(const String & s) : str(s.str){}

String String::operator=(const String & s){
    if(this!=&s){
        str=s.str;
    }
    return *this;
};


char &String::operator[](int i){ //copy
    if(str.use_count()>1){
        String n;
        *n.str=*str;
        *this=n;
        return (*str)[i];
    }
    else{
        return (*str)[i];
    }

}

char String::operator[](int i) const{ //no copy
        return (*str)[i];
}

String operator+(String a, String b){
    if(a.str->length()!=0&&b.str->length()!=0){
        String c(a.str->length()+b.str->length());
        *(c.str)=*(a.str)+*(b.str);
        return c;
    }
    if(a.str->length()!=0)
        return a;
    else
        return b;


}

std::ostream &operator<<(std::ostream &out, const String &s){
    out << *(s.str);
    return out;
}

int main(){
    String a("hi");
    String b;
    const String c = a; // no copy
    String d = a+b; // no copy
    a[0] = 'l'; // copy
    a[1] = 'l'; // no copy
    d = c+a; // copy elision
    cout << c << " " << d << endl; // hi hill (no copy)
    cout << c[0] << endl; // l (no copy)
    return 0;

}
