#pragma once
#include"Train.h"

class SortBy {
	string prop;
public:
	SortBy(string prop) {
		this->prop = prop;
	}
	bool operator()(train t1, train t2) {
		if (prop == "number")
			return (t1.getNumber() < t2.getNumber());
		else if (prop == "departure")
			return (t1.getDepartureTime() < t2.getDepartureTime());
		else if (prop == "destination")
			return(t1.getDestination() < t2.getDestination());
	}
};
