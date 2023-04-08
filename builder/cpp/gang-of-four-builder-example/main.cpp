#include "touragent.h"
#include "budgettour.h"
#include "luxurytour.h"

int main()
{
	BudgetTour bt;
	TourAgent a1{&bt};
	a1.buildTour();

	LuxuryTour lt;
	TourAgent a2{&lt};
	a2.buildTour();

	return 0;
}
