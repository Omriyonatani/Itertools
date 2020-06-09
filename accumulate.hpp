#pragma once
#include "range.hpp"

namespace itertools{
template <template<typename> class Container, typename T>	class accumulate {
		public:
			Container<T> container;
            
			accumulate(Container<T> cont):container(cont){
				cout<<"container constructor\n"<<endl;
			}

            accumulate(range cont):container(cont){
				cout<<"simulator_container constructor\n"<<endl;
			}

	class iterator {

		private:
            T* curr;
            T sum;

		public:

			iterator(T* ptr = nullptr)
				: curr(ptr) {
                    if(ptr!=nullptr){
                        sum=*ptr;
                    }
			}

			T& operator*() const {
				return sum;
			}

			// ++i;
			iterator& operator++() {
                curr++;
				sum+=(*curr);// if sum was 5 - now 5+6
				return *this;
			}

			// i++;
			// Usually iterators are passed by value and not by const& as they are small.
			const iterator operator++(int) {
				iterator tmp= *this;
                curr++;
				sum+=(*curr);
				return tmp;
			}

			bool operator==(const iterator& rhs) const {
				return curr == rhs.curr;
			}

			bool operator!=(const iterator& rhs) const {
				return curr != rhs.curr;
			}
		};  // END OF CLASS ITERATOR

		iterator begin() {
			return iterator{&container[0]};
		}
		
		iterator end() {
			return iterator{nullptr};
		}


		

	};
}