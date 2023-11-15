//
// Created by michael.brunner on 14/11/2023.
//
export module Person:interface;

import std.core;

export namespace Person {

	enum class Gender
	{
		Male,
		Female,
		NonBinary,
	};

	class IPerson
	{
	public:

		virtual ~IPerson() noexcept = default;

		virtual void setGender(Gender aGender) = 0;

		[[nodiscard]] virtual std::optional<Person::Gender> getGender() const = 0;

		virtual void setFirstName(const std::string &aFirstName) = 0;

		[[nodiscard]] virtual std::string getFirstName() const = 0;

		virtual void setLastName(const std::string &aLastName) = 0;

		[[nodiscard]] virtual std::string getLastName() const = 0;

	};
}
