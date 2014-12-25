#include "menu.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include "io.hpp"

namespace common {

Command::Command(std::string name, std::string description, std::function<void()> callback) :
	m_name(name), m_description(description), m_callback(callback) {}

const int Menu::COLUMN_WIDTH = 8;

Menu::Menu(std::string headline) : m_headline(headline) {}

void Menu::add(Command command)
{
	// Exit name is reserved for closing the menu
	if (command.m_name == "exit")
		throw std::exception();
	// Check if name already exists
	for (auto const &current : m_commands)
		if (current.m_name == command.m_name)
			throw std::exception();
	// Add to menu
	m_commands.push_back(command);
}

void Menu::add(std::string name, std::string description, std::function<void()> callback)
{
	Command command(name, description, callback);
	add(command);
}

void Menu::open()
{
	for (;;) {
		draw();
		const Command *command = input();
		// Null pointer means exit
		if (!command)
			return;
		// Clear console and execute command
		common::clear();
		try {
			command->m_callback();
		} catch (...) {
			std::cout << "Caught an exception." << std::endl;
			common::pause();
		}
	}
}

void Menu::draw()
{
	common::clear();
	std::cout << common::underline(m_headline, '=') << std::endl;
	for (auto const &command : m_commands) {
		std::cout << std::setw(COLUMN_WIDTH) << std::left << command.m_name << " ";
		std::cout << command.m_description << std::endl;
	}
	std::cout << std::setw(COLUMN_WIDTH) << std::left << "exit" << " ";
	std::cout << "Close this menu" << std::endl;
	std::cout << std::endl;
}

const Command *Menu::input()
{
	for (;;) {
		// Ask user to input a command name
		std::string name;
		std::cout << ">> ";
		std::cin.clear();
		std::cin >> name;
		// Check for valid input
		if (std::cin.good()) {
			// Exit by returning a null pointer
			if (name == "exit")
				return nullptr;
			// Find and return command
			for (auto const &command : m_commands)
				if (command.m_name == name)
					return &command;
		}
		// If function has not returned, there was an error
		std::cout << "Invalid input." << std::endl;
	}
}

} // namespace common
