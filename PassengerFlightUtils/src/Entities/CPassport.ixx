//
// Created by michael.brunner on 15/11/2023.
//
module;

#include <cassert>

export module Passport;

import std.core;

export class CPassport
{
private:
	std::string mCountryCode;
	int mPassportNumber{0};

public:
	CPassport() = default;

	explicit CPassport(std::string &&aCountryCode, const int passportNumber)
			: mCountryCode(std::move(aCountryCode))
			  , mPassportNumber(passportNumber)
	{
#ifdef _DEBUG
		assert(!(passportNumber < 1000 || passportNumber > 9999));
#endif
	}

	CPassport(const CPassport &passport) = default;

	CPassport(CPassport &&passport) noexcept = default;

	CPassport &operator=(const CPassport &passport) = default;

	CPassport &operator=(CPassport &&passport) = default;

	~CPassport() noexcept = default;

	[[nodiscard]] int getPassportNumber() const
	{
		return mPassportNumber;
	}
	[[nodiscard]] std::string getCountryCode() const
	{
		return mCountryCode;
	}

	[[nodiscard]] auto toString() const
	{
		return  std::format("{}-{}", mCountryCode, mPassportNumber);
	}

	explicit operator std::string() const
	{
		return toString();
	}

	auto operator <=>(const CPassport& passport) const
	{
		if (mPassportNumber < passport.mPassportNumber)
		{
			return std::strong_ordering::less;
		}
		if (mPassportNumber > passport.mPassportNumber)
		{
			return std::strong_ordering::greater;
		}
		return std::strong_ordering::equal;
	}
};