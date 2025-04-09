#include "Contact.hpp"

//	Getters
std::string	Contact::get_first_name(void)
{
	return (this->first_name);
}

std::string	Contact::get_last_name(void)
{
	return (this->last_name);
}

std::string	Contact::get_nickname(void)
{
	return (this->nickname);
}

std::string	Contact::get_phone_number(void)
{
	return (this->phone_number);
}

std::string	Contact::get_darkest_secret(void)
{
	return (this->darkest_secret);
}

//	Setters
void	Contact::set_first_name(const std::string &name)
{
	this->first_name = name;
}

void	Contact::set_last_name(const std::string &name)
{
	this->last_name = name;
}

void	Contact::set_nickname(const std::string &nick)
{
	this->nickname = nick;
}

void	Contact::set_phone_number(const std::string &number)
{
	this->phone_number = number;
}

void	Contact::set_darkest_secret(const std::string &secret)
{
	this->darkest_secret = secret;
}

//	Constructor and destructor
Contact::Contact(){}
Contact::~Contact(){}
