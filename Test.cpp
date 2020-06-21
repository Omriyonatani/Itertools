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

struct divide4 {
    bool operator()(int i) {
        return i % 4 != 0;
    }
};

typedef struct {
	template<typename T>
	T operator ()(T a,T b)const{
		return a-b;
	}
}Minus;

struct lessThan3 {
    bool operator()(int i) const { return i < 3; }
};

struct lessThan2 {
    bool operator()(int i) const { return i < 2; }
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


TEST_CASE ("range checks") {
    int num = 5;
    for (auto i:range(5, 9)) {
                CHECK(i == num);
        num++;
    }

    num = -7;
    for (auto i:range(-7, 3)) {
                CHECK(i == num);
        num++;
    }

    range t(5, 5);
    CHECK(t.begin() == t.end());
    CHECK_NOTHROW(range(2, 10));
    CHECK_NOTHROW(range(2, 2));
    CHECK_THROWS(range(2, 1));
    CHECK_THROWS(range(5, -5));
}

TEST_CASE ("accumulate checks") {
    vector<int> vecInt = {1, 2, 3, 4};
    vector <string> vecString = {"Hello", "Bye", "Adam"};
    vector<float> vecFloat = {-1, 0.3, 5.2, -8.3};


    int num = 0;
    for (int i: accumulate(range(5, 9))) {
        num += i - num;
                CHECK(i == num); // 5 11 18 26
    }


    string s = "";
    int len = 0;
    for (auto i: accumulate(vecString)) {
        len = i.length();
        s += i.substr(s.length(), len);
                CHECK(i == s);// Hello HelloBye HelloByeAdam
    }


    num = 1;
    for (int i: accumulate(range(5, 9), [](int x, int y) { return x * y; })) {
        num *= i / num;
                CHECK(i == num);      // 5 30 210 1680
    }


//    for (int i: accumulate(deque, [](int x, int y) { return x * y; })) {
//        cout << "i=" << i << endl;      // 5 30 210 1680
//    }

}

TEST_CASE ("filterfalse checks") {
    vector<int> vecInt = {1, 2, 2, 0};
    vector<int> vecInt2 = {5, 6, 7, 8};

    for(auto i: filterfalse([](int x){return x<3;}, range(-10,10))){
        CHECK(i>=3);
    }
    for(auto i: filterfalse([](int x){return x>3;}, vecInt)){
                CHECK(i<=3);
    }
    for(auto i: filterfalse([](int x){return x%2==0;}, range(-10,10))){
                CHECK(i%1==0);
    }
    for(auto i: filterfalse([](int x){return x<4;}, vecInt2)){
                CHECK(i>=4);
    }
}

TEST_CASE ("compress checks") {

    vector<bool> Booli = {true,true,true,true,false,true,true,true,true,false,true,true,true,true,false,true,true,true,true,false};
    for(auto i: compress(range(1,21),Booli)){
        CHECK(i%5!=0);
    }

}

TEST_CASE("Ron's range "){
    // chars container
    char t='a';
    for(char c: range('a','e')){
        CHECK(c == t);
        t++;
    }

    // negative to positive container
    int i=-3;
    for(int j: range(-3,3)){
        CHECK(i==j);
        i++;
    }

    // big container
    int a=0;
    for(int b: range(0,1000000000)){
        CHECK(a==b);
        a++;
        if(a==5){
            break;
        }
    }
}

TEST_CASE("Ron's acumulate "){
    int i = -4;
    int sum = 0;
    for(int j: accumulate(range(-4,3))){
        sum+=i;
        i++;
        CHECK(sum==j);
    }

    int a = -4;
    int sum2 = 0;
    for(int b: accumulate(range(-4,3),Minus())){//{-4,-3,-2,-1,0,1,2,3}
        if(a==-4){
            sum2=a;
            CHECK(sum2==b);
            a++;
            continue;
        }
        sum2-=a;
        a++;
        CHECK(sum2==b);
    }

    // // -4 -3 -2 -1 0 1 2 
    // // -4 -7 -9 -10 -10 -9 -7
    // // -4 -11 -20 -30 -40 -49 -56
    // int d = -4;
    // int sum3 = 0;
    // int sum4 = 0;
    // for(int f: accumulate(accumulate(range(-4,3)))){
    //     sum3+=d;
    //     sum4+=sum3;
    //     d++;
    //     CHECK(sum4==f);
    //     cout<<f<<endl;
    // }
    
}




