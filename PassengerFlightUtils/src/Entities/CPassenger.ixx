//
// Created by michael.brunner on 15/11/2023.
//

module;

#include <cassert>
#include <utility>

export module Passenger;

import Passport;
import std.core;

export class CPassenger
{
private:
	std::string mFirstName;
	std::string mLastName;
	CPassport mPassport{};

public:
	explicit CPassenger(
			std::string firstName, std::string lastName,
			CPassport passport)
			: mFirstName(std::move(firstName))
			  , mLastName(std::move(lastName))
			  , mPassport(std::move(passport))
	{
	}

	[[nodiscard]] auto getPassport() const
	{
		return mPassport;
	}
	[[nodiscard]] auto getFirstName() const
	{
		return mFirstName;
	}
	[[nodiscard]] auto getLastName() const
	{
		return mLastName;
	}

	auto operator <=>(const CPassenger& passenger) const
	{
		return mPassport <=> passenger.mPassport;
	};
};
