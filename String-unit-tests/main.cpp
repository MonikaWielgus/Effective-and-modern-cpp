//Monika Wielgus
#include <iostream>
#include "s.h"
int main(){
    String a("hi");
    String b;
    const String c=a;
    String d=a+b;
    a[0]='l';
    a[1]='l';
    d=c+a;
    cout << c << " " << d << endl;
    cout << c[0] << endl;

    return 0;
}
