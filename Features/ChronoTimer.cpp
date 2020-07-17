//Monika Wielgus
#include <iostream>
#include <chrono>
#include <string>
#include <iomanip>
using namespace std::chrono;
class Timer{
    std::string name;
    time_point<steady_clock> start;
    time_point<steady_clock> end;
public:
    Timer(const std::string & name) : name(name){
        start=steady_clock::now();
    }
    ~Timer(){
        auto end=steady_clock::now();
        duration<double> diff = end-start;
        std::cout << name << " : " << duration_cast<milliseconds>(diff).count() << " ms. " << std::endl;
    }
    auto durationInNanoseconds(){
        auto n=steady_clock::now();
        duration<double> diff2 = n-start;
        return duration_cast<nanoseconds>(diff2).count();
    }
};

long fibonacci(unsigned n){
    if(n<2) return n;
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    Timer total("Total time");
    for(auto n :{1, 5, 15, 20, 25, 40, 45}){
        Timer t("fibonacci("+std::to_string(n)+")");
        fibonacci(n);
    }
    std::cout << "Elapsed " << total.durationInNanoseconds() << " ns.\n";
}

