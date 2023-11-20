
import ModulesIntro.ModuleOne;
import Person;
import Passenger;
import Passport;
import std.memory;
import std.core;
import TicketPassengerCollection;
import AirlineTicket;
import Character;
import RandomTests;

struct WeatherData final
{
	int mTemperature{};
	int mHumidity{};
	int mAirPressure{};

	auto operator<=>(const WeatherData &aOther) const
	{
		if (mTemperature < aOther.mTemperature) {
			return std::strong_ordering::less;
		} else if (mTemperature > aOther.mTemperature) {
			return std::strong_ordering::greater;
		} else {
			return std::strong_ordering::equivalent;
		}
	}
};

constexpr auto CountValues(auto container, auto cmp)
{
	return std::count_if(begin(container), end(container), cmp);
}


int main()
{
	{
		auto lResult = recursiveExponentiation(2, 3);
		std::cout << lResult << std::endl;

		auto lMultiplicationResult = multiply(2, 3);
		std::cout << "Result is : " << lMultiplicationResult << std::endl;
	}
	constexpr auto minVal = CountValues(std::array{-10, 6, 8, 4, -5, 2, 4, 6},
	                                    [](auto a) { return a >= 0; }
	);
	std::cout << "Integers >= = : " << minVal << std::endl;


	{
		std::vector <WeatherData> lWeatherDataList{
				{30,  60, 1200},
				{20,  50, 1100},
				{10,  40, 1000},
				{0,   30, 900},
				{-10, 20, 800},
				{-20, 10, 700},
		};
		auto lVar = lWeatherDataList | std::views::transform([](const WeatherData &wd) { return wd.mTemperature; });

		for (auto il: lVar) {
			std::cout << il << std::endl;
		}

		std::map<std::string, int> cpp_standards
				{
						{"C++98", 1988},
						{"C++03", 2003},
						{"C++11", 2011},
						{"C++14", 2014},
						{"C++17", 2017},
						{"c++20", 2020}
				};

		for (int const year: std::views::elements<1>(cpp_standards)) {
			std::cout << year << ' '; // 2003 2011 2014 2017 1988 2020
		}

		std::cout << '\n';

		std::vector<std::pair<std::string, int>> windows
				{
						{"Windows 1.0", 1985},
						{"Windows 2.0", 1987},
						{"Windows 3.0", 1990},
						{"Windows 3.1", 1992},
						{"Windows NT 3.1", 1993},
						{"Windows 95", 1995},
						{"Windows NT 4.0", 1996},
						{"Windows 98", 1998},
						{"Windows 2000", 2000}
				};

		for (int year : std::views::elements<1>(windows))
		{
			std::cout << year << ' ';
		}
		std::cout << '\n';
	}


	auto lCharacter = Character("Michael");
	lCharacter.SayHello();
	std::cout << "Hello, World!" << std::endl;
	Hello::hello();

	std::ranges::filter_view lFilterView{std::array{-10, 6, 8, 4, -5, 2, 4, 6}, [](auto a) { return a > 0; }};
	std::cout << std::ranges::count(lFilterView, 4) << std::endl;

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
	const char* (* lToFuncPtr)(std::string &&) = +[](std::string &&aText) {
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
