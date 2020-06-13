#include "doctest.h"
#include "accumulate.hpp"
#include "compress.hpp"
#include "filterfalse.hpp"
#include "range.hpp"

using namespace itertools;
using namespace std;

struct divide4{
    bool operator()(int i){
        return i%4!=0;
    }
};

struct lessThan3 {
    bool operator()(int i) const { return i < 3; }
};
/*
range(5,9)
accumulate(range(5,9))
accumulate(vecString)
accumulate(range(5,9), [](int x, int y){return x*y;})
filterfalse(lessThan3{}, vecInt)
filterfalse([](int i){return i%2==0;}, range(5,9))
compress(string("abcd"), vector<bool>({true,true,false,true}))
compress(range(5,9), vector<bool>({true,true,false,true}))
*/
TEST_CASE("Everything"){
    CHECK(range(5,9) == (5,6,7,8));
}



