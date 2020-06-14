
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
            const Function& func;
			const Container& container;
			
		public:
			filterfalse(const Function& func,const Container& cont ):container(cont),func(func){}

		class iterator {
			
			private:
				decltype(container.begin()) pos;
				decltype(container.end()) end;
				Function func;

			public:
				iterator(decltype(container.begin()) p,decltype(container.end()) end,Function func): 
					pos(p),end(end),func(func) {}

				// ++i;
				iterator& operator++() {
                    ++pos;
                    while(func(*pos) && pos!=end){
                        ++pos;
                    }
					return *this;
				}

				// i++;
				// Usually iterators are passed by value and not by const& as they are small.
				iterator operator++(int) {
					iterator tmp= *this;
					pos++;
                    while(func(*pos) && pos!=end){
                        pos++;
                    }
					return tmp;
				}

                auto operator*() {
                    if(func(*pos)&& pos!=end){
                        (*this)++;
                    }
                    return *pos;
				}

				bool operator==(const iterator& rhs) const {
					return pos == rhs.pos;
				}

				bool operator!=(const iterator& rhs) const {
					return pos != rhs.pos;
				}
			};  // END OF CLASS ITERATOR

			iterator begin()const{
				return iterator(container.begin(),container.end(),func);
			}

			iterator end() const{
				return iterator(container.end(),container.end(),func);
			}
	};
}


