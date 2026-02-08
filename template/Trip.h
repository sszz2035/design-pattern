#ifndef _TRIP_H_
#define _TRIP_H_

namespace temp {

	class Trip
	{
	protected:
		virtual void goTransport() = 0;
		virtual void day1() = 0;
		virtual void day2() = 0;
		virtual void day3() = 0;
		virtual void backTransport() = 0;
	public:
		virtual void performTrip()final {
			goTransport();
			day1();
			day2();
			day3();
			backTransport();	
		}
	};

}


#endif 