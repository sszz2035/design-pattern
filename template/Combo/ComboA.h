#ifndef _COMBOA_H_
#define _COMBOA_H_
#include "Trip.h"
namespace temp {
	class ComboA :public Trip
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