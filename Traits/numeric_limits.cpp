//Monika Wielgus
#include <iostream>
#include <limits>
using  namespace std;
template <typename T>
void info(T x){
    if(std::numeric_limits<T>::is_signed)
        cout << "signed ";
    else
        cout << "unsigned ";
    if(std::numeric_limits<T>::is_integer)
        cout << "integer ";
    else
        cout << "not integer ";
    cout << "min: " << std::numeric_limits<T>::min();
    cout << " max: " << std::numeric_limits<T>::max() << endl;
}
int main() {
    info(1);
    info(2.0f);
    info(3U);
    return 0;
}
