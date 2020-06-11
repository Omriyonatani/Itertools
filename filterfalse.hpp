
#pragma once

#include <iostream>
#include <vector>
#include <typeinfo>

#include <iterator>

using namespace std;


namespace itertools{


	template <typename Function,typename Container>
	class filterfalse{
		
		private:
            Function func;
			Container container;
			

		public:
			filterfalse(Function func, Container cont ):container(cont),func(func){}

		class iterator {

			private:

				typename Container::iterator pos;
				typename Container::iterator end;
				Function func;

			public:

				iterator(typename Container::iterator p,typename Container::iterator end,Function func): 
					pos(p),end(end),func(func) {}


				

				// ++i;
				iterator& operator++() {
                    ++pos;
                    while(func(*pos)&& pos!=end){
                        ++pos;
                    }
                    if(pos==end){
                        return end;
                    }
					return *this;
				}

				// i++;
				// Usually iterators are passed by value and not by const& as they are small.
				iterator operator++(int) {
					iterator tmp= *this;
					pos++;
                    while(func(*pos)&& pos!=end){
                        pos++;
                    }
                    if(pos==end){
                        return end;
                    }
					return tmp;
				}

                auto operator*() {
                    if(func(*pos)&& pos!=end){
                        (*this)++;
                    }
                    return *pos;
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


