#include "doctest.h"
#include "accumulate.hpp"
#include "compress.hpp"
#include "filterfalse.hpp"
#include "range.hpp"
#include <vector>
#include <iostream>
#include <deque>
#include <list>


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
// TEST_CASE("Everything"){
//     CHECK(range(5,9) == (5,6,7,8));
// }


TEST_CASE("range checks"){
    int num=5;
    for(auto i:range(5,9)){
        CHECK(i==num);
        num++;
    }

    num=-7;
    for(auto i:range(-7,3)){
        CHECK(i==num);
        num++;
    }

    range t(5,5);
    CHECK(t.begin()==t.end());
    CHECK_NOTHROW(range(2,10));
    CHECK_NOTHROW(range(2,2));
    CHECK_THROWS(range(2,1));
    CHECK_THROWS(range(5,-5));
}

TEST_CASE("accumulate checks"){
    vector<int> vecInt = {1,2,3,4};
    vector<string> vecString = {"Hello", "Bye", "Adam"};
    vector<float> vecFloat = {-1, 0.3, 5.2, -8.3};


    
    int num=0;
	for (int i: accumulate(range(5,9))){
        num+=i-num;
        CHECK(i==num); // 5 11 18 26   
    }
       
		
         
    string s="";
    int len=0;
    for (auto i: accumulate(vecString) ){
        len=i.length();
        s+=i.substr(s.length(),len);
        CHECK(i==s);// Hello HelloBye HelloByeAdam
    }
        

    num=1;
	for (int i: accumulate(range(5,9), [](int x, int y){return x*y;})){
        num*=i/num;
		CHECK(i==num);      // 5 30 210 1680
    }



    for (int i: accumulate(deque,[](int x,int y){return x*y;})){
        cout <<"i="<<i<<endl;      // 5 30 210 1680
    }


        

}





