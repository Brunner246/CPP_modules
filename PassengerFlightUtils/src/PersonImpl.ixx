
//
// Created by michael.brunner on 14/11/2023.
//

// module Person: implementation;
module;

#include <cassert>
#include "RandomHeader.h"

export module Person:implementation;
export import :interface; // import the interface module partition
import std.core;
import std.memory;



class CPerson : public Person::IPerson
{
public:
	~CPerson() noexcept override = default;

	explicit CPerson(std::string &&aFirstName, std::string &&aLastName, const Person::Gender aGender)
			: mFirstName(std::move(aFirstName))
			  , mLastName(std::move(aLastName))
			  , mGender(aGender)
	{
#ifdef _DEBUG
		assert(!mFirstName.empty());
		assert(!mLastName.empty());
#endif
		printSomehting();
	}

	[[nodiscard]] std::string getFirstName() const override
	{
		return mFirstName;
	}

	void setFirstName(const std::string &aFirstName) override
	{
		mFirstName = aFirstName;
	}

	[[nodiscard]] std::string getLastName() const override
	{
		return mLastName;
	}

	void setLastName(const std::string &aLastName) override
	{
		mLastName = aLastName;
	}

	void setGender(const Person::Gender aGender) override
	{
		mGender = aGender;
	}

	[[nodiscard]] auto getGender() const -> std::optional <Person::Gender> override
	{
		return mGender;
	}

private:
	std::string mFirstName;
	std::string mLastName;
	std::optional <Person::Gender> mGender;
};


export auto createPerson(std::string &&aFirstName, std::string &&aLastName, const Person::Gender aGender) -> std::unique_ptr<Person::IPerson>
{
	return std::move(std::make_unique<CPerson>(std::move(aFirstName), std::move(aLastName), aGender));
}