//
// Created by michael.brunner on 11/11/2023.
//
module;

#include <cassert>

export module ModulesIntro.ModuleOne;

import std.core;

// TODO: force global fragment import header error
// #include <utility>

namespace Hello {
	export void hello()
	{
		std::cout << "Hello Amigos from ModulesTest =)" << std::endl;
	}

	export template<std::floating_point T>
	auto add(const T a, const T b)
	{
		return a + b;
	}

	class Passport
	{
	private:
		int mPassportNumber{0};

	public:
		Passport() = default;

		explicit Passport(const int passportNumber)
				: mPassportNumber(passportNumber)
		{
#ifdef _DEBUG
			assert(passportNumber > 9);
#endif
		}

		Passport(const Passport &passport) = default;

		Passport(Passport &&passport) noexcept = default;

		Passport &operator=(const Passport &passport) = default;

		Passport &operator=(Passport &&passport) = default;

		~Passport() noexcept = default;

		[[nodiscard]] int getPassportNumber() const
		{
			return mPassportNumber;
		}

		void setPassportNumber(const int passportNumber)
		{
			mPassportNumber = passportNumber;
		}

		explicit operator std::string() const
		{
			return std::to_string(mPassportNumber);
		}
	};

	class Passenger
	{
	private:
		std::string mFirstName;
		std::string mLastName;
		Passport mPassport;

	public:
		explicit Passenger(
				std::string firstName, std::string lastName,
				const Passport &passport)
				: mFirstName(std::move(firstName))
				, mLastName(std::move(lastName))
				, mPassport(passport)
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
	};

	class Destination
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

	class CAirlineTicket
	{
	private:
		std::string mAirlineName;
		bool mIsPremium{false};
	};
}



