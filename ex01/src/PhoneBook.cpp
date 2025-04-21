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

static bool	check_error(std::string temp)
{
	if (temp.empty())
	{
		draw_message(RED "Invalid input.\n" RESET);
		return (true);
	}
	for (int i = 0; temp[i]; i++)
	{
		if (temp[i] < 32 || temp[i] > 126)
		{
			draw_message(RED "Only ASCII characters.\n" RESET);
			return (true);
		}
	}
	for (int i = 0; temp[i]; i++)
		if (!std::isspace(temp[i]))
			return (false);
	draw_message(RED "Only spaces is forbiden.\n" RESET);
	return (true);
}

//	Methods
void	PhoneBook::add_contact(void)
{
	Contact		newContact;
	std::string	input;

	draw_message("Enter first name: ");
	std::getline(std::cin, input);
	if (check_error(input))
		return ;
	newContact.set_first_name(input);

	draw_message("Enter last name: ");
	std::getline(std::cin, input);
	if (check_error(input))
		return ;
	newContact.set_last_name(input);
	
	draw_message("Enter the nickname: ");
	std::getline(std::cin, input);
	if (check_error(input))
		return ;
	newContact.set_nickname(input);

	draw_message("Enter the phone number: ");
	std::getline(std::cin, input);
	while (!is_digit(input))
	{
		draw_message(RED "Invalid input!(ONLY NUMBERS)\n" RESET);
		draw_message("Enter the phone number: ");
		if (!std::getline(std::cin, input))
			return ;
	}
	newContact.set_phone_number(input);

	draw_message("Enter the darkest secret: ");
	std::getline(std::cin, input);
	if (check_error(input))
		return ;
	newContact.set_darkest_secret(input);

	this->list[this->index] = newContact;
	this->index = (this->index + 1) % 8;
	this->set_listlen();
	this->set_oldest_contact();
}
static std::string	corrct_str(std::string temp)
{
	if (temp.length() > 10)
		temp = temp.substr(0, 9) + '.';
	return (temp);
}
static void	draw_phonebook(void)
{
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
	std::cout << std::setfill(' ') << std::setw(10) <<  "Index";
	draw_message("|");
	std::cout << std::setfill(' ') << std::setw(10) <<  "First name";
	draw_message("|");
	std::cout << std::setfill(' ') << std::setw(10) <<  "Last name";
	draw_message("|");
	std::cout << std::setfill(' ') << std::setw(10) <<  "Nickname";
	draw_message("|\n");
	std::cout << std::setfill('-') << std::setw(42) << "-" << std::endl;
}
static void	show_contact(Contact &contact, int index)
{
	std::cout << std::setfill(' ') << std::setw(10) << index << "|";
	std::cout << std::setfill(' ') << std::setw(10) << corrct_str(contact.get_first_name()) << "|";
	std::cout << std::setfill(' ') << std::setw(10) << corrct_str(contact.get_last_name()) << "|";
	std::cout << std::setfill(' ') << std::setw(10) << corrct_str(contact.get_nickname()) <<"|\n";
}

void	PhoneBook::search_contact(void)
{
	std::string	input;
	int			index;

	this->show_contacts();
	draw_message(ORANGE "Enter the contact index: " RESET);
	if (!std::getline(std::cin, input))
		return ;
	std::istringstream str (input);
	if (!(str >> index))
		return ;
	index--;
	if (index <= this->get_oldest_contact() && index >= 0 && index < 8)
	{
		draw_phonebook();
		show_contact(this->list[index], index + 1);
	}
	else
		draw_message("Contact doesn't exist.\n");
	std::cout << std::setfill('-') << std::setw(45) << "-" << std::endl;
}
void	PhoneBook::show_contacts(void)
{
	int	i = -1;

	draw_phonebook();
	while (++i < this->get_listlen())
		show_contact(this->list[i], i + 1);
}
