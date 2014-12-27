#ifndef MENU_HPP
#define MENU_HPP

#include <string>
#include <functional>
#include <list>

namespace common {

struct Command {
	Command(std::string name, std::string description, std::function<void()> callback);
	std::string m_name;
	std::string m_description;
	std::function<void()> m_callback;
};

class Menu {
public:
	Menu(std::string headline);
	void add(common::Command command);
	void add(std::string name, std::string description, std::function<void()> callback);
	void open();
	void show_back(bool flag);
	void show_quit(bool flag);
private:
	void draw();
	const common::Command *input();

	std::string m_headline;
	std::list<Command> m_commands;
	bool m_has_back = true;
	bool m_has_quit = true;
	static const int COLUMN_WIDTH;
};

} // namespace common

#endif
