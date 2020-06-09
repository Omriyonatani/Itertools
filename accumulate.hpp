#pragma once
#include "range.hpp"
#include "simulator_container.hpp"

namespace itertools{
template <template<typename> class Container, typename T>	class accumulate {
		public:
			Container<T> container;
            
			accumulate(Container<T> cont):container(cont){
				cout<<"container constructor\n"<<endl;
			}

            accumulate(simulator_container<T> cont):container(cont){
				cout<<"simulator_container constructor\n"<<endl;
			}

			T& operator [](int i){
				if(i==0){
					if(type(container)==type(Container<T>)){
						return container[0];
					}
					else{
						return *(container.begin());
					}
				}

				return nullptr;
				
			}

			int size(){
				return container.size();
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
            if(container.size()==0){
                return iterator{nullptr};
            }
			return iterator{&container[0]};
		}
		
		iterator end() {
			return iterator{nullptr};
		}


		

	};
}