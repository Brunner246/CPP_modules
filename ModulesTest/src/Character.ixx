//
// Created by michael.brunner on 16/11/2023.
//

// Character.ixx

export module Character;

import std.core;


// Definition
export class Character {
public:
	explicit Character(std::string&& Name);
	void SayHello();
	[[nodiscard]] std::string GetName();

private:
	std::string Name;
};


//
//export module Character;
//import <string>;
//import <iostream>;
//
//// Definition
//export class Character {
//public:
//	explicit Character(std::string Name);
//	void SayHello();
//	std::string GetName();
//private:
//	std::string Name;
//};
//
//// Implementation
//Character::Character(std::string Name): Name{std::move(Name)} {}
//void Character::SayHello() {
//	std::cout << "Hello there!  The name is " << Name;}
//std::string Character::GetName() {return Name;}


