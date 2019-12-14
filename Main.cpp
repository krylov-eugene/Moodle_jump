#include <SFML/Graphics.hpp>
#include "List_of_platforms.h"
#include "vector2I.h"
#include "Person.h"


bool is_mouse_position_in_district_of_button(const vector2I& mouse ,const vector2I& button , const int& button_height,const int& button_width){

	if(mouse.x >= button.x && mouse.x <= button.x + button_width &&
		mouse.y >= button.y && mouse.y <= button.y + button_height )
		{
			return true;
		}

	return false;	

}
void update_all_objects(List_of_platforms& platforms,Person& person,float& height,float dt){
	platforms.update(height,dt);
	person.update(platforms,dt,height,window_height);
}
void draw_all_objects(sf::RenderWindow& window,List_of_platforms& platforms,Person& person,sf::Sprite& background){

	window.clear(); 
			
	window.draw(background);
	platforms.draw(window);
	person.draw(window);
	
	window.display();

}

bool is_losing_game(float y_position_of_moodler){
	if(y_position_of_moodler >= window_height){
		return true;
	}

	return false;

}


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
				window.clear();
				window.draw(pressed_button);
				window.display();
			}
			else{
				window.clear();
				window.draw(not_pressed_button);
				window.display();
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

		double x_position_of_button = 100,y_position_of_button = 550 ,
				button_height = 50 ,button_widht = 200;

		sf::Texture for_pressed_button,for_not_pressed_button;
		sf::Sprite pressed_button , not_pressed_button;
};

void main_cycle(sf::RenderWindow& window, List_of_platforms& platforms,Person& person)
{
		float height = 0;
		sf::Clock clock;


		sf::Texture background_texture;
		background_texture.loadFromFile("images/background.png");
		sf::Sprite background;
		background.setTexture(background_texture);


		while (window.isOpen())
		{
			float dt = clock.getElapsedTime().asSeconds();
			clock.restart();

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed){
					window.close();
				}	   
			}

			if(is_losing_game(person.get_y_position())){
				break;
			}
			update_all_objects(platforms,person,height,dt);


			draw_all_objects(window,platforms,person,background);
		}
}	

int main(){


	Main_menu menu;
	

	Person person;
	List_of_platforms platforms;

	
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Moodle Jump");
	srand(time(nullptr));

	
	
	while (window.isOpen()){
		
		
		sf::Event event_of_released_button;
		sf::Event event_of_pressed_button;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){  

				window.close();
				
			}
			if(event.type == sf::Event::MouseButtonPressed){

				event_of_pressed_button = event;
				
			}
			if(event.type == sf::Event::MouseButtonReleased){

				event_of_released_button = event;

			}	
		}

		
		if(menu.is_restart_game_button_pressed_and_released(window,event_of_pressed_button,event_of_released_button)){
			main_cycle(window,platforms,person);
		}
	
	
	}

	return 0;
}#include <SFML/Graphics.hpp>
#include "List_of_platforms.h"
#include "vector2I.h"
#include "Person.h"


bool is_mouse_position_in_district_of_button(const vector2I& mouse ,const vector2I& button , const int& button_height,const int& button_width){

	if(mouse.x >= button.x && mouse.x <= button.x + button_width &&
		mouse.y >= button.y && mouse.y <= button.y + button_height )
		{
			return true;
		}

	return false;	

}
void update_all_objects(List_of_platforms& platforms,Person& person,float& height,float dt){
	platforms.update(height,dt);
	person.update(platforms,dt,height,window_height);
}
void draw_all_objects(sf::RenderWindow& window,List_of_platforms& platforms,Person& person,sf::Sprite& background){

	window.clear(); 
			
	window.draw(background);
	platforms.draw(window);
	person.draw(window);
	
	window.display();

}

bool is_losing_game(float y_position_of_moodler){
	if(y_position_of_moodler >= window_height){
		return true;
	}

	return false;

}


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
				window.clear();
				window.draw(pressed_button);
				window.display();
			}
			else{
				window.clear();
				window.draw(not_pressed_button);
				window.display();
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

		double x_position_of_button = 100,y_position_of_button = 550 ,
				button_height = 50 ,button_widht = 200;

		sf::Texture for_pressed_button,for_not_pressed_button;
		sf::Sprite pressed_button , not_pressed_button;
};

void main_cycle(sf::RenderWindow& window, List_of_platforms& platforms,Person& person)
{
		float height = 0;
		sf::Clock clock;


		sf::Texture background_texture;
		background_texture.loadFromFile("images/background.png");
		sf::Sprite background;
		background.setTexture(background_texture);


		while (window.isOpen())
		{
			float dt = clock.getElapsedTime().asSeconds();
			clock.restart();

			sf::Event event;
			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed){
					window.close();
				}	   
			}

			if(is_losing_game(person.get_y_position())){
				break;
			}
			update_all_objects(platforms,person,height,dt);


			draw_all_objects(window,platforms,person,background);
		}
}	

int main(){


	Main_menu menu;
	

	Person person;
	List_of_platforms platforms;

	
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Moodle Jump");
	srand(time(nullptr));

	
	
	while (window.isOpen()){
		
		
		sf::Event event_of_released_button;
		sf::Event event_of_pressed_button;
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){  

				window.close();
				
			}
			if(event.type == sf::Event::MouseButtonPressed){

				event_of_pressed_button = event;
				
			}
			if(event.type == sf::Event::MouseButtonReleased){

				event_of_released_button = event;

			}	
		}

		
		if(menu.is_restart_game_button_pressed_and_released(window,event_of_pressed_button,event_of_released_button)){
			main_cycle(window,platforms,person);
		}
	
	
	}

	return 0;
}
}
