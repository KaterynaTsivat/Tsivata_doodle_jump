#include <SFML/Graphics.hpp>
#include <iostream>
#include <cstdlib> 
#include <time.h>  
#include "C_Doodle.h"
#include "Window.h"



int main()
{
	Window* window = new Window(532, 850);
	window->show();
	delete window;
	return 0;
}