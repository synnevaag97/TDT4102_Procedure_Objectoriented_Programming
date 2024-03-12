#pragma once
#include "Car.h"
#include <string>
#include <iostream>

class Person
{
public:
	Person(const std::string& name, const std::string& email);
	Person(const std::string& name, const std::string&, Car* car);

	Person(const Person&) = delete;
	Person& operator=(const Person&) = delete;

	std::string getEmail() const;
	std::string getName() const;

	void setEmail(const std::string& email);

	bool hasAvailableSeats() const;

	friend std::ostream& operator<<(std::ostream& os, const Person& person);

private:
	std::string name;
	std::string email;

	Car* car;
};
