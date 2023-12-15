#include <iostream>
#include "input.h"
using namespace std;


Input::Input() {
	button.left = button.right = button.up = button.down = false;
}

Input::Button Input::GetButton(void) {
	return button;
}

void Input::InputHandler(Event event, RenderWindow &window) {


	if (event.type == Event::Closed) {
		window.close();
	}

	if (event.type == Event::KeyPressed) 
	{
		switch (event.key.code) 
		{
		case Keyboard::Left:
			button.left = true;
			break;
		case Keyboard::Right:
			button.right = true;
			break;
		case Keyboard::Up:
			button.up = true;
			break;
		case Keyboard::Down:
			button.down = true;
			break;
		case Keyboard::Z:
			button.z = true;
			break;
		case Keyboard::Q:
			button.q = true;
			break;
		case Keyboard::S:
			button.s = true;
			break;
		case Keyboard::D:
			button.d = true;
			break;
		default:
			break;

		}
		

			
	}
	if (event.type == Event::KeyReleased)
	{
		switch (event.key.code)
		{
		case Keyboard::Left:
			button.left = false;
			break;
		case Keyboard::Right:
			button.right = false;
			break;
		case Keyboard::Up:
			button.up = false;
			break;
		case Keyboard::Down:
			button.down = false;
			break;
		case Keyboard::Z:
			button.z = false;
			break;
		case Keyboard::Q:
			button.q = false;
			break;
		case Keyboard::S:
			button.s = false;
			break;
		case Keyboard::D:
			button.d = false;
			break;
		default:
			break;
		}


	}

}