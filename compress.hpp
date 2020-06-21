
#pragma once

#include <iostream>
#include <vector>
#include <typeinfo>
#include <cassert>
#include <iterator>

using namespace std;

namespace itertools{

	template<typename T> struct is_bool {
		static const bool value = false;
	};

	template<> struct is_bool<bool> {
		static const bool value = true;
	};


	template <typename Container,typename ContainerBool>
	class compress{
		
		private:
            const ContainerBool& cbool;
			const Container& container;
			
		public:
			compress(const Container& cont,const ContainerBool& cb ):container(cont),cbool(cb){
				// static_assert(is_bool<decltype(cb[0])>::value,"Can be only boolean type\n");
			}

		class iterator {
			
			private:
				decltype(container.begin()) pos;
				decltype(container.end()) end;
                decltype(cbool.begin()) pos_bool;
				decltype(cbool.end()) end_bool;

			public:
				iterator(decltype(container.begin()) p,decltype(container.end()) end,
                decltype(cbool.begin()) p_bool,decltype(cbool.end()) end_bool): 
					pos(p),end(end),pos_bool(p_bool),end_bool(end_bool) {
//						cout<<"iterator compress ctor\n"<<endl;
					}

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

				bool operator==(const iterator& rhs) const {
					return pos == rhs.pos;
				}

				bool operator!=(const iterator& rhs)  const{
					return pos != rhs.pos;
				}
			};  // END OF CLASS ITERATOR

			iterator begin() const{
				return iterator(container.begin(),container.end(),cbool.begin(),cbool.end());
			}

			iterator end() const{
				return iterator(container.end(),container.end(),cbool.end(),cbool.end());
			}
	};
}


