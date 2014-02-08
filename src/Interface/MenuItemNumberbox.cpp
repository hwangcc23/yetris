#include <Interface/MenuItemNumberbox.hpp>
#include <Misc/Utils.hpp>
#include <Config/Globals.hpp>

MenuItemNumberbox::MenuItemNumberbox(std::string label, int value, int min, int max, int initial):
	MenuItem(label, value),
	min(min),
	max(max),
	initial(initial),
	current(initial)
{
	this->type = MenuItem::NUMBERBOX; // placing it above wont work
}
void MenuItemNumberbox::draw(Window* window, int x, int y, int width, bool hilite)
{
	MenuItem::draw(window, x, y, width, hilite);

	std::string number = Utils::intToString(this->current);

	window->print(number, (width + x - number.size()), y, Globals::Theme::hilite_text);
}
void MenuItemNumberbox::handleInput(int input)
{
	switch(input)
	{
	case KEY_LEFT:
		this->decrease();
		break;

	case KEY_RIGHT:
		this->increase();
		break;

	case 'r':
	case 'R':
	case ' ':
	case '\n':
	case KEY_ENTER:
		this->reset();
		break;
	}
}

void MenuItemNumberbox::increase()
{
	this->current++;

	if (this->current > this->max)
		this->current = this->max;
}

void MenuItemNumberbox::decrease()
{
	this->current--;

	if (this->current < this->min)
		this->current = this->min;
}
void MenuItemNumberbox::reset()
{
	this->current = this->initial;
}

