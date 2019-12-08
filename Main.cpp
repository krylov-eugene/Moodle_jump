#include <SFML/Graphics.hpp>
#include "List_of_platforms.h"
#include "GraphicManager_Test.h"
#include "vector2I.h"

#include <iostream>


/*const int window_heghth = 650, window_width = 400,
		platform_heghth = 10, platform_width = 30,
		platforms_rate = 100;*/


bool is_mouse_position_in_district_of_button(const vector2I& mouse ,const vector2I& button , const int& button_height,const int& button_width){

	if(mouse.x >= button.x && mouse.x <= button.x + button_width &&
		mouse.y >= button.y && mouse.y <= button.y + button_height )
		{
			return true;
		}

	return false;	

}	

class Images : public DrawableObject {

	public:

		sf::Sprite person,screen,platform_0;
		sf::Texture moodler,background,desk_0;

		Images(){

			

			moodler.loadFromFile("images/moodler.png");
			if(!background.loadFromFile("images/background.png")){
				
			}
			desk_0.loadFromFile("images/platform_0.png");

			
			platform_0.setTexture(desk_0);
			person.setTexture(moodler);
			screen.setTexture(background);

		}

		sf::Sprite get_person(){

			return person;
		}

		sf::Sprite& get_screen(){

			return screen;
		}

		sf::Sprite& get_platform(){

			return platform_0;
		}
		void Draw(sf::RenderWindow* window){

			(*window).draw(screen);
			(*window).draw(platform_0);
			(*window).draw(person);
			
		}
    private:

};

class Main_menu{

	public:


		Main_menu(){

			for_pressed_button.loadFromFile("images/menu_pressed.png");
			for_not_pressed_button.loadFromFile("images/menu.png");

			not_pressed_button.setTexture(for_not_pressed_button);
			pressed_button.setTexture(for_pressed_button);

		}

		void draw_main_menu_picture(sf::RenderWindow& window , bool is_restart_game_button_pressed){
			
			if(is_restart_game_button_pressed){
				window.draw(pressed_button);
			}
			else{
				window.draw(not_pressed_button);
			}

		}

		bool is_restart_game_button_pressed_and_released(sf::RenderWindow& window, sf::Event event_of_pressed_button ,sf::Event event_of_released_button ){

			bool is_mouse_button_pressed = false;
			bool is_mouse_button_released = false;
			bool is_restart_game_button_pressed = false;

			int x_position_of_mouse = 0,
				y_position_of_mouse = 0;

			

			if(event_of_pressed_button.type == sf::Event::MouseButtonPressed){

				is_mouse_button_pressed = true;

				x_position_of_mouse = event_of_pressed_button.mouseButton.x;
				y_position_of_mouse = event_of_pressed_button.mouseButton.y;
				
			}
			if(event_of_released_button.type == sf::Event::MouseButtonReleased){
				is_mouse_button_released = true;
			}

					
				

			if(is_mouse_position_in_district_of_button({x_position_of_mouse,y_position_of_mouse},{x_position_of_button,y_position_of_button},button_height,button_widht) 
			    && is_mouse_button_pressed)
			   {
				   is_restart_game_button_pressed = true;
			   }


			draw_main_menu_picture(window,is_restart_game_button_pressed);

			return is_restart_game_button_pressed && is_mouse_button_released;

		}




	private:

		double x_position_of_button = 50,y_position_of_button = 500 ,
				button_height = 100 ,button_widht = 200;

		sf::Texture for_pressed_button,for_not_pressed_button;
		sf::Sprite pressed_button , not_pressed_button;
};


void main_cycle(sf::RenderWindow& window, List_of_platforms& platforms,GraphicManager& manager)
{
	int height = 0;
	sf::Clock clock;

	while (window.isOpen())
	{
		float dt = clock.getElapsedTime().asSeconds();
		clock.restart();

		// --control--

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		// ...


		// --logics--

		// update objcts
		platforms.update(height);


		// --drawing--

        //testing

	

        // testing

		window.clear(sf::Color(255,255,255)); // or background
		// draw objects
		manager.DrawAll(&window);

		

		window.display();
	}
}


int main()
{   
	Main_menu menu;

	Images images;
    GraphicManager manager;
	manager.SetNumberOfObjectsAndDoArray(2);
    manager.Register(&images);

	List_of_platforms platforms;
   
	sf::RenderWindow window(sf::VideoMode(window_width, window_heghth), "Moodle Jump");
	window.setFramerateLimit(80);
	
	while (window.isOpen())
	{   
		sf::Event event_of_released_button;
		sf::Event event_of_pressed_button;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if(event.type == sf::Event::MouseButtonPressed){

				event_of_pressed_button = event;
				
			}
			if(event.type == sf::Event::MouseButtonReleased){

				event_of_released_button = event;
			}
			
		}

		window.clear(sf::Color(235,215,245)); // or background
		
		if(menu.is_restart_game_button_pressed_and_released(window,event_of_pressed_button,event_of_released_button)){
			main_cycle(window,platforms,manager);
		}

		window.display();
	}


	//main_cycle(window, platforms,manager);

	return 0;
}
