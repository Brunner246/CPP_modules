//
// Created by michael.brunner on 15/11/2023.
//
module ;

#include <cassert>

export module CDestination;

import std.core;

export class Destination
{
	std::string mCountry;
	std::string mCity;
	uint32_t mZipCode;

public:
	explicit Destination(std::string country, std::string city, uint32_t zipCode)
			: mCountry(std::move(country))
			  , mCity(std::move(city))
			  , mZipCode(zipCode)
	{
#ifdef _DEBUG
		assert(!mCountry.empty());
		assert(!mCity.empty());
		assert(mZipCode < 5);
#endif
	}

	[[nodiscard]] auto getCountry() const
	{
		return mCountry;
	}
	[[nodiscard]] auto getCity() const
	{
		return mCity;
	}
	[[nodiscard]] auto getZipCode() const
	{
		return mZipCode;
	}
};
