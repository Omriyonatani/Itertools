struct divide4{
    bool operator()(int i){
        return i%4!=0;
    }
};