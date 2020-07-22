//Monika Wielgus
#include "s.h"

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

char &String::operator[](int i){
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

char String::operator[](int i) const{
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
