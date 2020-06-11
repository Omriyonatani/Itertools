
// #pragma once
#ifndef ACCU_H
#define ACCU_H
#include <iostream>
#include <vector>
#include <typeinfo>

#include <iterator>

using namespace std;


namespace itertools{

	typedef struct {
		template<typename T>
		T operator ()(T a,T b)const{
			return a+b;
		}
	}plus;

	template <typename Container,typename Function = plus>
	class accumulate{
		
		private:
			Container container;
			Function func;

		public:
			accumulate( Container cont, Function func = plus()):container(cont),func(func){}

		class iterator {

			private:
				decltype(*(container.begin())) sum;

				typename Container::iterator pos;
				typename Container::iterator end;
				Function func;

			public:

				iterator(typename Container::iterator p,typename Container::iterator end,Function func): 
					pos(p),end(end),func(func),sum(*p) {}


				auto operator*() {
					return sum;
				}

				// ++i;
				iterator& operator++() {
					++pos;
					if(pos!=end){
						sum=func(sum,*(pos));
					}
					return *this;
				}

				// i++;
				// Usually iterators are passed by value and not by const& as they are small.
				iterator operator++(int) {
					iterator tmp= *this;
					pos++;
					sum=func(sum,*(pos));
					return tmp;
				}

				bool operator==(const iterator& rhs)  {
					return pos == rhs.pos;
				}

				bool operator!=(const iterator& rhs)  {
					return pos != rhs.pos;
				}
			};  // END OF CLASS ITERATOR

			iterator begin() {
				return iterator(container.begin(),container.end(),func);
				
			}

			iterator end() {
				return iterator(container.end(),container.end(),func);
			}


	};
}

#endif

