#ifndef MY_RANDOM_GEN_HPP
#define MY_RANDOM_GEN_HPP

#include <cstddef>
#include <random>
#include <iostream>

class MyRandomGen{

    public:
        MyRandomGen(): generator{r_disp()} {};
        
        int generate (){
            std::uniform_int_distribution<int> int_distr = *distr;
            return int_distr(generator);
        }

        void change_interval(int start, int end){
            if (distr != nullptr){
                delete distr;
            }
            distr = new std::uniform_int_distribution<int>(start, end);
        }

        static MyRandomGen * instance(){
            if (instance_ == nullptr) {
                instance_ = new MyRandomGen();
            }
            return instance_;
        }

    private:
        std::random_device r_disp;
        std::mt19937 generator;
        std::uniform_int_distribution<int> *distr = nullptr;
        static MyRandomGen *instance_;       
};

MyRandomGen* MyRandomGen::instance_ = nullptr;

#endif