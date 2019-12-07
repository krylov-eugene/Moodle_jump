#include <SFML/Graphics.hpp>
#include "List_of_platforms.h"


class Person {

    public:

        void update(){

            jump;
            refresh_x_position_if_button_of_moving_is_pressed;
            fly;
            recalculate_screen_position;

        }
    private:

        double x_position = 0, y_position = 0,
               Vy = 0;

        const double person_width = 20 , person_height = 40;

        void recalculate_screen_position(int& heghth,const int& window_heghth){

            if(y_position >= window_heghth/2 ){

               heghth+=4;    

            }            

        }

        void jump(){

            if(is_collide_with_platform && Vy >= 0){
                Vy *= (-1);
            }
        }

        bool is_collide_with_platform(List_of_platforms& platforms){

            int len_of_list = platforms.length();

            for(int i = 0 ; i < len_of_list ; ++i){

                if(x_position + person_width >= platforms[i].x && x_position <= platforms[i].x + platform_width &&
                  y_position + person_height <= platforms[i].y && platforms[i].y - y_position <= person_height)
                  {
                        return true;
                        break;
                  }
                
                return false;
            }
        }
        
        void refresh_x_position_if_button_of_moving_is_pressed(){

            sf::Event event;
            if(event.type == sf::Event::KeyPressed){

                if(event.key.code == sf::Keyboard::Right){
                    
                    this->x_position += 4;

                }
                else if(event.key.code == sf::Keyboard::Left){

                    this->x_position -= 4;

                }
            }   
        }

        void fly(const float& dt){
            
            Vy += 3;

            y_position += Vy*dt;

        }
};
