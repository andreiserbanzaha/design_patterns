#pragma once

class TourBuilder;

class TourAgent
{
public:
	TourAgent(TourBuilder* aBuilder);

	void buildTour();

private:
	TourBuilder* mbuilder;
};
