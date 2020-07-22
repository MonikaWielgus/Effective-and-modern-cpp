//Monika Wielgus
#include <iostream>
#include <fstream>
#include <future>
#include <thread>

std::promise<long long int>* sum(std::string filename,std::promise<long long int> *prom){
    long long int sum=0;
    std::ifstream read(filename);
    if(read.is_open()){
        std::string word;
        while(read>>word){
            for(int i=0;i<word.length();i++)
                sum+=word[i];
        }
    }
    else
        std::cout<<"Problem with opening the file";

    read.close();
    prom->set_value(sum);
    return prom;
}
int main(){
    std::cout<<"How many filenames will you give?"<<std::endl;
    int N;
    std::cin>>N;
    std::string w[N];
    long long int sums[N];
    for(int i=0;i<N;i++)
        std::cin>>w[i];
    std::promise<long long int> prom[N];
    std::future<long long int> fut[N];
    std::thread th[N];
    for(int i=0;i<N;i++){
        prom[i]=std::promise<long long int>();
        fut[i]=prom[i].get_future();
    }
    for(int i=0;i<N;i++){
        th[i]=std::thread(sum,w[i],&prom[i]);
        sums[i]=fut[i].get();
        std::cout<<sums[i]<<std::endl;
        th[i].join();
    }
    for(int i=0;i<N;i++){
        for(int j=i+1;j<N;j++){
            if(sums[i]==sums[j])
                std::cout <<i+1<<" and "<<j+1<<" have the same sum"<< std::endl;
        }
    }
    return 0;
}
