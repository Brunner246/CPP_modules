//
// Created by michael.brunner on 15/11/2023.
//
module;

export module TicketPassengerCollection;

import std.core;
import Passenger;
import AirlineTicket;

export class CTicketPassengerCollection
{
private:
	std::multimap<CPassenger, CAirlineTicket> mTicketPassengerCollection;

public:
	CTicketPassengerCollection() = default;
	void add(CPassenger const& aPassenger, CAirlineTicket const& aTicket)
	{
		mTicketPassengerCollection.insert(std::make_pair(aPassenger, aTicket));
	}
};
