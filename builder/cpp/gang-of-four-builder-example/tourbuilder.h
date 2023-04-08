#pragma once

class TourBuilder
{
public:
	virtual void bookHotel()      = 0;
	virtual void bookRestaurant() = 0;
	virtual void bookTickets()    = 0;
	virtual void bookExtras()     = 0;
};
