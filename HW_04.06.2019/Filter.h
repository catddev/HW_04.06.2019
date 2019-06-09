#pragma once
#include"Train.h"

class filter {
	string prop;
	train t;
public:

	filter(string prop, train t) {
		this->prop = prop;
		this->t = t;
	}
	void operator()(train t) {
		if (prop == "number") {
			if (this->t.getNumber() == t.getNumber())
				cout << t;
		}
		else if (prop == "dep_time") {
			if (this->t.getDepartureTime() == t.getDepartureTime())
				cout << t;
		}
		else if (prop == "destination") {
			if (this->t.getDestination() == t.getDestination())
				cout << t;
		}
	}
};