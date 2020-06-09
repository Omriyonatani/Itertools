
#pragma once

template<typename T>
class simulator_container{
    public:
        int cont_size;

        simulator_container():cont_size(0){}

        virtual T& operator [](int i)=0;
        virtual int size()=0;
};