#ifndef INPUT_H
#define INPUT_H
#include "SFML/Graphics.hpp"
using namespace sf;

class Input {
	
	struct Button { bool left, right, up, down, z, q, s,d ; };


public:
	Input();

	Button GetButton(void);
	void InputHandler(Event event, RenderWindow &window);

private:
	Button button;

  
};



#endif
