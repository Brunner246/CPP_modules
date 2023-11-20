//
// Created by michael.brunner on 16/11/2023.
//

// character.cpp
module Character;

Character::Character(std::string&& Name)
		: Name{std::move(Name)} {}

void Character::SayHello() {
	std::cout << "Hello there!  The name is "
	          << Name;
}

std::string Character::GetName() {
	return Name;
}