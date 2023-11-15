
import ModulesIntro.ModuleOne;
import Person;
import Passenger;
import Passport;
import std.memory;
import std.core;
import TicketPassengerCollection;
import AirlineTicket;

int main()
{
	std::cout << "Hello, World!" << std::endl;
	Hello::hello();

	std::cout << Hello::add(1.0f, 2.5f) << std::endl;

	auto lPerson = createPerson("Hans", "Muster", Person::Gender::Male);
	std::cout << lPerson->getFirstName() << std::endl;
	std::cout << lPerson->getLastName() << std::endl;

	std::vector <std::unique_ptr<Person::IPerson>> lPersons{};
	{
		lPersons.push_back(createPerson("John", "Doe", Person::Gender::Male));
		lPersons.push_back(createPerson("Foo", "Bar", Person::Gender::Male));
	}
	using namespace std::literals;
	auto lSearchName = "John"s;
	auto lResult = std::ranges::any_of(lPersons, [&lSearchName](auto const &aPerson) {
		return aPerson->getFirstName() == lSearchName;
	});
	lResult ? std::cout << "Found John" << std::endl : std::cout << "Not found John" << std::endl;

	// decltype(auto)
	const char* (*lToFuncPtr)(std::string&&)  = +[](std::string&& aText) {
		return "hello world";
	};
	std::cout << lToFuncPtr("hello world") << std::endl;

	auto lSum = Hello::sum(1, 2, 3, 4, 5);
	std::cout << lSum << std::endl;

	auto lPassenger = CPassenger("Hans", "Muster", CPassport("CH", 1234));
	auto lPassport = lPassenger.getPassport();
	std::cout << lPassport.getPassportNumber() << std::endl;
	std::cout << lPassport.getCountryCode() << std::endl;

	auto lTicketPassengerCollection = CTicketPassengerCollection();
	auto lAirlineTicketInfo = CAirlineInfos();
	{
		lAirlineTicketInfo.mAirlineName = "Swiss";
		lAirlineTicketInfo.mSeatNumber = "A1";
		lAirlineTicketInfo.mFlightNumber = "LX1234";
	}
	lTicketPassengerCollection.add(lPassenger, CAirlineTicket(std::move(lAirlineTicketInfo), "7efd65e5-8ebe-4861-8918-1cfb0a3877d2"));

	return 0;
}



/*
 * #include <QLibrary>
#include <QDebug>

typedef void (*HelloFunction)();

int main() {
    QLibrary library("ModuleOne");

    if (!library.load()) {
        qDebug() << "Could not load the library!";
        return 1;
    }

    HelloFunction hello = (HelloFunction) library.resolve("hello");
    if (!hello) {
        qDebug() << "Could not locate the function!";
        return 1;
    }

    hello();

    library.unload();
    return 0;
}
 */
