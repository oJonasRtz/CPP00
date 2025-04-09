#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact
{
	private:
		std::string	first_name;
		std::string	last_name;
		std::string	nickname;
		std::string	phone_number;
		std::string	darkest_secret;
	public:
		//Getters
		std::string	get_first_name(void);
		std::string	get_last_name(void);
		std::string	get_nickname(void);
		std::string	get_phone_number(void);
		std::string	get_darkest_secret(void);

		//Setters
		void	set_first_name(const std::string &name);
		void	set_last_name(const std::string &name);
		void	set_nickname(const std::string &nick);
		void	set_phone_number(const std::string &number);
		void	set_darkest_secret(const std::string &secret);
	
	//Constructor
	Contact();
	//Destructor
	~Contact();
};

# include "PhoneBook.hpp"

#endif
