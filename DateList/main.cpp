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

	std::cin >> date1Year;
	std::cin.ignore();
	std::cin >> date1Month;
	std::cin.ignore();
	std::cin >> date1Day;

	std::cin >> date2Year;
	std::cin.ignore();
	std::cin >> date2Month;
	std::cin.ignore(); 
	std::cin >> date2Day;

	int startYear{};
	int startMonth{};
	int startDay{};
	int endYear{};
	int endMonth{};
	int endDay{};

	// The range of the input year will be between the years 1901 and 2099. 
	
	if (date1Year != date2Year)
	{
		// find which year is older
		if (date1Year > date2Year) {
			startYear = date2Year;
			startMonth = date2Year;
			startDay = date2Day;
			endYear = date1Year;
			endMonth = date1Month;
			endDay = date1Day;
		}
		else {
			startYear = date1Year;
			startMonth = date1Month;
			startDay = date1Day;
			endYear = date2Year;
			endMonth = date2Month;
			endDay = date2Day;
		}
	}
	else if (date1Month != date2Month)
	{
		// Years are the same, find which month is older
		if (date1Month > date2Month) {
			startYear = date2Year;
			startMonth = date2Year;
			startDay = date2Day;
			endYear = date1Year;
			endMonth = date1Month;
			endDay = date1Day;
		}
		else {
			startYear = date1Year;
			startMonth = date1Month;
			startDay = date1Day;
			endYear = date2Year;
			endMonth = date2Month;
			endDay = date2Day;
		}
	}
	else if (date1Day != date2Day)
	{
		// Year and Month are the same, fund which day is older
		if (date1Day > date2Day) {
			startYear = date2Year;
			startMonth = date2Year;
			startDay = date2Day;
			endYear = date1Year;
			endMonth = date1Month;
			endDay = date1Day;
		}
		else {
			startYear = date1Year;
			startMonth = date1Month;
			startDay = date1Day;
			endYear = date2Year;
			endMonth = date2Month;
			endDay = date2Day;
		}
	}
	else {
		// dates are the same
		startYear = date1Year;
		startMonth = date1Month;
		startDay = date1Day;
		endYear = date2Year;
		endMonth = date2Month;
		endDay = date2Day;
	}

	bool validDates = true;
	// start date checks
	// range check
	if (startYear < 1901 || endYear > 2099 || startMonth > 12 || startMonth < 1 || endMonth > 12 || endMonth < 1 || startDay < 1 || endDay < 1)	{
		validDates = false;
	}
	// 31 day months check
	if ((startMonth == 1 || startMonth == 3 || startMonth == 7 || startMonth == 8 || startMonth == 10 || startMonth == 12) && startDay > 31) {
		validDates = false;
	}
	// 30 day months check
	if ((startMonth == 4 || startMonth == 6 || startMonth == 9 || startMonth == 11) && startDay > 30) {
		validDates = false;
	}
	// February check
	if (startMonth == 2 && (((startYear % 4) == 0 && startDay > 29) || ((startYear % 4) != 0 && startDay > 28))) {
		validDates = false;
	}

	// end date checks
	// 31 day months check
	if ((endMonth == 1 || endMonth == 3 || endMonth == 7 || endMonth == 8 || endMonth == 10 || endMonth == 12) && endDay > 31) {
		validDates = false;
	}
	// 30 day months check
	if ((endMonth == 4 || endMonth == 6 || endMonth == 9 || endMonth == 11) && endDay > 30) {
		validDates = false;
	}
	// February check
	if (endMonth == 2 && (((endYear % 4) == 0 && endDay > 29) || ((endYear % 4) != 0 && endDay > 28))) {
		validDates = false;
	}

	if (validDates)
	{
		// Loop through the years
		for (; startYear <= endYear; startYear++)
		{
			// exclude the newest date
			if (startYear == endYear && startMonth == endMonth && startDay == endDay)
			{
				break;
			}
			// Loop through the months
			for (; startMonth <= 12; startMonth++)
			{
				// exclude the newest date
				if (startYear == endYear && startMonth == endMonth && startDay == endDay)
				{
					break;
				}
				int daysInMonth{ 31 };
				if (startMonth == 4 || startMonth == 6 || startMonth == 9 || startMonth == 11)
				{
					daysInMonth = 30;
				}
				else if (startMonth == 2 && (startYear % 4) == 0)
				{
					// account for leap years
					daysInMonth = 29;
				}
				else if (startMonth == 2 && (startYear % 4) != 0)
				{
					daysInMonth = 28;
				}

				// loop through the days
				for (; startDay <= daysInMonth; startDay++)
				{
					// exclude the newest date
					if (startYear == endYear && startMonth == endMonth && startDay == endDay)
					{
						break;
					}
					// std::setfill to zero fill dates
					std::cout << std::setfill('0');
					std::cout << startYear << "-" << std::setw(2) << startMonth << "-" << std::setw(2) << startDay << std::endl;
				}
				startDay = 1;
			}
			startMonth = 1;
		}
	}
	else {
		std::cout << "Invalid date entered" << std::endl;
	}
    return 0;
}

