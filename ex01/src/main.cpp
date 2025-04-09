#include "PhoneBook.hpp"

void	draw_message(std::string message)
{
	std::cout << message << std::flush;
}

int	main(void)
{
	PhoneBook	myPhoneBook;
	std::string	input;

	while (1)
	{
		draw_message(RED "*\tPhoneBook\t*\n" RESET);
		draw_message(BLUE "* ADD - add a new contact in the list.\n" RESET);
		draw_message(BLUE "* SEARCH - display especific contact.\n" RESET);
		draw_message(BLUE "* EXIT - end the program.\n" RESET);
		draw_message(GREEN "Enter input: " RESET);
		if (!std::getline(std::cin, input))
			break;
		if (input == "ADD" || input == "add" || input == "Add")
			myPhoneBook.add_contact();
		else if (input == "SEARCH" || input == "search" || input == "Search")
			myPhoneBook.search_contact();
		else if (input == "exit" || input == "EXIT" || input == "Exit")
			break ;
		else
			draw_message("Invalid input.\n");
	}
	return (0);
}
