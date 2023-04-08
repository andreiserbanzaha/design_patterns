#include "touragent.h"
#include "tourbuilder.h"

TourAgent::TourAgent(TourBuilder* aBuilder)
	: mbuilder{aBuilder}
{
}

void TourAgent::buildTour()
{
	mbuilder->bookHotel();
	mbuilder->bookRestaurant();
	mbuilder->bookTickets();
	mbuilder->bookExtras();
}
