#pragma once
#include <iostream>
#include <stdexcept>

using namespace std;

namespace itertools{
	class range {
		public:
			int Start;
			int End;

			range(int s,int e):Start(s),End(e){
				if(s>e){
					throw new std::logic_error("there is no range\n");
				}
			}

	class iterator {

		private:
			int curr;

		public:
			
			iterator(int num)
				: curr(num) {}

			int operator*() const {
				return curr;
			}

			// ++i;
			iterator& operator++() {
				(curr)++;// if was 5 - now 6
				return *this;
			}

			// i++;
			// Usually iterators are passed by value and not by const& as they are small.
			const iterator operator++(int) {
				iterator tmp= *this;
				curr++;
				return tmp;
			}

			bool operator==(const iterator& rhs) const {
				return curr == rhs.curr;
			}

			bool operator!=(const iterator& rhs) const {
				return curr!= rhs.curr;
			}
		};  // END OF CLASS ITERATOR

		iterator begin() const{
			return iterator{Start};
		}
		
		iterator end() const{
			return iterator{End};
		}


	};
}