#include "PhoneBook.hpp"

//	Constructor and destructor
PhoneBook::PhoneBook()
{
	this->oldest = 0;
	this->listlen = 0;
	this->index = 0;
}
PhoneBook::~PhoneBook(){}

//	Getters
int		PhoneBook::get_oldest_contact()
{
	return (this->oldest);
}
int		PhoneBook::get_listlen()
{
	return (this->listlen);
}
Contact*	PhoneBook::get_contactlist()
{
	return (this->list);
}

//	Setters
void	PhoneBook::set_listlen()
{
	if (this->listlen < 8)
		this->listlen++;
}
void	PhoneBook::set_oldest_contact(void)
{
	if (index < 8)
		this->oldest++;
	else
		this->oldest = 0;
}

static int	is_digit(std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
		if (!std::isdigit(str[i]))
			return (0);
	return (1);
}

//	Methods
void	PhoneBook::add_contact(void)
{
	Contact		newContact;
	std::string	input;

	draw_message("Enter first name: ");
	if (!std::getline(std::cin, input))
		return ;
	newContact.set_first_name(input);

	draw_message("Enter last name: ");
	if (!std::getline(std::cin, input))
		return ;
	newContact.set_last_name(input);
	
	draw_message("Enter the nickname: ");
	if (!std::getline(std::cin, input))
		return ;
	newContact.set_nickname(input);

	draw_message("Enter the phone number: ");
	if (!std::getline(std::cin, input))
		return ;
	while (!is_digit(input))
	{
		draw_message(RED "Invalid input!(ONLY NUMBERS)\n" RESET);
		draw_message("Enter the phone number: ");
		if (!std::getline(std::cin, input))
		return ;
	}
	newContact.set_phone_number(input);

	draw_message("Enter the darkest secret: ");
	if (!std::getline(std::cin, input))
		return ;
	newContact.set_darkest_secret(input);

	this->list[this->index] = newContact;
	this->index = (this->index + 1) % 8;
	this->set_listlen();
	this->set_oldest_contact();
}
static void	show_contact(Contact &contact)
{
	/*
		tamanho maximo 10 char
		texto alinhado a direita
		se o texto for maior que a coluna deve ser truncado e substituido por (.)
		ex: tralalalalalalallalaala
			tralala.| 
		lista
		----------------------------------------------
		 index|   first name|  last name|  nickname
		----------------------------------------------
	 	 0(10)|	   lala (10)|  silva(10)|  sdffsff(10) 
	*/
}

void	PhoneBook::search_contact(void)
{
	std::string	input;
	int			index;

	draw_message(ORANGE "Are you looking for an especific contact(YES/NO): " RESET);
	if (!std::getline(std::cin, input))
		return ;
	if (input == "YES" || input == "yes" || input == "Yes")
	{
		draw_message("Enter the contact index: ");
		if (!std::getline(std::cin, input))
			return ;
		std::istringstream str (input);
		if (!(str >> index))
			return ;
		if (index <= this->get_oldest_contact() && index >= 0 && index < 8)
			show_contact(this->list[index]);
		else
			draw_message("Contact doesn't exist.\n");
	}
	else if (input == "NO" || input == "no" || input == "No")
		this->show_contacts();
}
void	PhoneBook::show_contacts(void)
{
	int	i = 0;

	while (i < this->get_listlen())
		show_contact(this->list[i++]);
}
