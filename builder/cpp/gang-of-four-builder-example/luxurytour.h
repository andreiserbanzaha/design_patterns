#pragma once

#include "tourbuilder.h"

class LuxuryTour : public TourBuilder
{
public:
	virtual void bookHotel() override;
	virtual void bookRestaurant() override;
	virtual void bookTickets() override;
	virtual void bookExtras() override;
};
