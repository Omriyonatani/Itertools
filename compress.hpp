
#pragma once

#include <iostream>
#include <vector>
#include <typeinfo>
#include <iterator>

using namespace std;

namespace itertools{

	template <typename Container,typename ContainerBool>
	class compress{
		
		private:
            ContainerBool cbool;
			Container container;
			
		public:
			compress(Container cont, ContainerBool cbool ):container(cont),cbool(cbool){}

		class iterator {
			
			private:
				typename Container::iterator pos;
				typename Container::iterator end;
                typename ContainerBool::iterator pos_bool;
				typename ContainerBool::iterator end_bool;

			public:
				iterator(typename Container::iterator p,typename Container::iterator end,
                typename ContainerBool::iterator p_bool,typename ContainerBool::iterator end_bool): 
					pos(p),end(end),pos_bool(p_bool),end_bool(end_bool) {}

				// ++i;
				iterator& operator++() {
                    ++pos;
                    ++pos_bool;
                    while(!*pos_bool && pos_bool!=end_bool){
                        ++pos;
                        ++pos_bool;
                    }
					return *this;
				}

				// i++;
				// Usually iterators are passed by value and not by const& as they are small.
				iterator operator++(int) {
					iterator tmp= *this;
					pos++;
                    pos_bool++;
                    while(!*pos_bool && pos_bool!=end_bool){
                        ++pos;
                        ++pos_bool;
                    }
					return tmp;
				}

                auto operator*() {
                    if(!*pos_bool && pos!=end){
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
				return iterator(container.begin(),container.end(),cbool.begin(),cbool.end());
			}

			iterator end() {
				return iterator(container.end(),container.end(),cbool.end(),cbool.end());
			}
	};
}


