//Monika Wielgus
#ifndef NAZWAPROJEKTU_S_H
#define NAZWAPROJEKTU_S_H
#include <iostream>
#include <algorithm>
#include <memory>

using namespace std;

class String{
public:
    shared_ptr<string> str;
    String(size_t=0);
    String(const char *);
    String(const String & );
    String operator=(const String &);
    char & operator[](int i);
    char operator[](int i) const;
    friend String operator+(String a, String b);
    friend std::ostream & operator<< (std::ostream & out, const String &);

};
#endif //NAZWAPROJEKTU_S_H
