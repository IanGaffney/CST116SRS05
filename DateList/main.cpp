// main.cpp : DateList main.
//

#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <cassert>

int main()
{
	int date1Year{};
	int date1Month{};
	int date1Day{};
	int date2Year{};
	int date2Month{};
	int date2Day{};
	char dash{};

	std::cin >> date1Year >> dash >> date1Month >> dash >> date1Day >> date2Year >> dash >> date2Month >> dash >> date2Day;
	// The range of the input year will be between the years 1901 and 2099. 
	assert(date1Year >= 1901);
	assert(date1Year <= 2099);
	assert(date1Month > 0);
	assert(date1Month < 12);
	assert(date1Day > 0);
	assert(date1Day < 31);


	
	// account for leap years



	// std::setfill to zero fill dates
    return 0;
}

