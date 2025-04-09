#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"
# include <iostream>
# include <sstream>
# define RED "\033[1;31m"
# define BLUE "\033[1;34m"
# define GREEN "\033[1;32m"
# define ORANGE "\033[38;5;208m"
# define RESET "\033[0m"

void	draw_message(std::string message);


class PhoneBook
{
	private:
		Contact	list[8];
		int		index;
		int		oldest;
		int		listlen;
	public:
		//Getters
		int		get_oldest_contact(void);
		int		get_listlen(void);
		Contact	*get_contactlist(void);

		//Setters
		void	set_listlen(void);
		void	set_oldest_contact(void);

		//Methods
		void	add_contact(void);
		void	search_contact(void);
		void	show_contacts(void);

	//Constructor
	PhoneBook();
	//Destructor
	~PhoneBook();
};

#endif
