#pragma once

#include "tourbuilder.h"

class BudgetTour : public TourBuilder
{
public:
	virtual void bookHotel() override;
	virtual void bookRestaurant() override;
	virtual void bookTickets() override;
	virtual void bookExtras() override;
};
