#include "doctest.h"
#include "accumulate.hpp"
#include "compress.hpp"
#include "filterfalse.hpp"
#include "range.hpp"

using namespace std;

struct divide4{
    bool operator()(int i){
        return i%4!=0;
    }
};

struct lessThan3 {
    bool operator()(int i) const { return i < 3; }
};

TEST_CASE("Everything"){

}



