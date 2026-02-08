#ifndef _COMBOB_H_
#define _COMBOB_H_
#include "Trip.h"
namespace temp {
	class ComboB :public Trip
	{
	private:
		void goTransport()override;
		void day1()override;
		void day2()override;
		void day3()override;
		void backTransport()override;
	};
}

#endif