#pragma once

namespace itertools{
	class range {
		public:
			int Start;
			int End;

			range(int s,int e):Start(s),End(e){
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