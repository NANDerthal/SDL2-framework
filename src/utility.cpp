#include "utility.hpp"

namespace utility {

	int roundNotZero( double num ) {
		if ( num > 0 ) {
			return ceil(num);
		}
		else {
			return floor(num);
		}
	}

}
