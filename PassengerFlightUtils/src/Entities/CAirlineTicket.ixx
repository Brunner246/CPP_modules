//
// Created by michael.brunner on 15/11/2023.
//

export module AirlineTicket;

import std.core;
import CDestination;


export struct CAirlineInfos
{
	std::string mAirlineName;
	std::string mSeatNumber;
	std::string mFlightNumber;

};

export class CAirlineTicket
{
private:
	std::string mAirlineName;
	std::string mSeatNumber;
	std::string mFlightNumber;
	std::string GUID;

public:
	explicit CAirlineTicket( CAirlineInfos&& airlineInfos, std::string&& aTicketGUID)
			: mAirlineName(std::move(airlineInfos.mAirlineName))
			  , mSeatNumber(std::move(airlineInfos.mSeatNumber))
			  , mFlightNumber(std::move(airlineInfos.mFlightNumber))
			  , GUID(std::move(aTicketGUID))
	{
	}

	[[nodiscard]] auto getAirlineName() const
	{
		return mAirlineName;
	}
	[[nodiscard]] auto getSeatNumber() const
	{
		return mSeatNumber;
	}
	[[nodiscard]] auto getFlightNumber() const
	{
		return mFlightNumber;
	}
	[[nodiscard]] auto getGUID() const
	{
		return GUID;
	}
};