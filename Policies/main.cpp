//Monika Wielgus
#include <iostream>
#include "Vector.h"
using  namespace std;
int main(){
    int value=5;
    {  // sets coordinates to zero and checks indices
        using Vect=Vector<double,3,SafePolicy>;
        Vect a{};
        a.set(1,-1);
        cout << a << endl;
        a.set(-1, 1.);             // Exception
 //       cout << a.get(3) << endl;  // Exception
 //       Vect b{1, 2, 3, 4};        // Exception
    }
    { /// does not initialize by default and does not check indices
        using Vect=Vector<double,3,FastPolicy>;
        Vect a{};
        a.set(1,-1);
        cout << a << endl;
        a.set(-1, 1.);
        cout << value << endl;
        cout << a.get(3) << endl;
        Vect b{1,2,3,4};
    }
    { /// initializes to zero by default but does not check indices
        using Vect=Vector<double,3,InitFastPolicy>;
        Vect a{};
        a.set(1,-1);
        cout << a << endl;
        a.set(-1,1.);
        cout << value << endl;
        cout << a.get(3) << endl;
        Vect b{1,2,3,4};
    }
    return 0;
}
