#pragma once
#include "simulator_container.hpp"

namespace itertools{
	template<typename T>
	class range: public simulator_container<T> {
		public:
			int Start;
			int End;

			range(int s,int e):Start(s),End(e),
				simulator_container<T>::cont_size(e-s){
			}

			//dont important in this class
			T& operator[](int i){
				T a;
				return T; 
			}

			int size(){
				return simulator_container<T>::cont_size;
			}

	class iterator {

		private:
			int* curr;

		public:

			iterator(int* ptr = nullptr)
				: curr(ptr) {
			}

			int& operator*() const {
				return *curr;
			}

			// ++i;
			iterator& operator++() {
				(*curr)++;// if was 5 - now 6
				return *this;
			}

			// i++;
			// Usually iterators are passed by value and not by const& as they are small.
			const iterator operator++(int) {
				iterator tmp= *this;
				(*curr)++;
				return tmp;
			}

			bool operator==(const iterator& rhs) const {
				return (*curr) == (*rhs.curr);
			}

			bool operator!=(const iterator& rhs) const {
				return (*curr) != (*rhs.curr);
			}
		};  // END OF CLASS ITERATOR

		iterator begin() {
			return iterator{&Start};
		}
		
		iterator end() {
			return iterator{&End};
		}


	};
}