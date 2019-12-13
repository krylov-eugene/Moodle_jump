#include "List.h"
#include <random>
#include "GraphicManager.h"

class List_of_platforms : public DrawableObject {
private:
	bool initialized = false;
	int previous_height = 0, speed = 1;

	void move_platforms(float height, float dt)
	{
		int dy = height - previous_height;
		
		previous_height = height;

		for (int i = list.length()-1; i >= 0; --i)
		{
			Platform& current_platform = list[i];

			current_platform.y += dy;
			current_platform.update(dt);

			if (current_platform.y > window_height)
			{
				delete &current_platform;
				list.pop(i);
			}
		}
	}

	
	void generate(float height)
	{
		while (height - revealed > -platform_height)
		{
			if (std::rand()%100 <= platforms_rate)
			{
				int x = std::rand() % (window_width - platform_width);
				int kind_randomizer = random() % 100;
				int kind;
				int v = speed*(random()%2 == 1 ? 1 : -1);

				if (kind_randomizer <= 10) kind = 1;
				else if (kind_randomizer <= 30) kind = 2;
				else kind = 0;

				Platform* new_platform = new Platform(x, height - revealed, kind, v, platform_sprites);
				list.push_front(new_platform);
			}
			revealed += platform_height;
		}
	}

public:
	List list;
	int revealed = -window_height;
	sf::Sprite* platform_sprites = new sf::Sprite[3];

	sf::Texture texture_0;
	sf::Texture texture_1;
	sf::Texture texture_2;
	
	List_of_platforms()
	{
		texture_0.loadFromFile("images/platform_0.png");
		texture_1.loadFromFile("images/platform_1.png");
		texture_2.loadFromFile("images/platform_2.png");

		platform_sprites[0].setTexture(texture_0);
		platform_sprites[1].setTexture(texture_1);
		platform_sprites[2].setTexture(texture_2);

		generate(0);
	}

	void update(float height, float dt)
	{
		move_platforms(height, dt);
		generate(height);
		std::cout << height<<std::endl;
	}

	void draw(sf::RenderWindow& window){

		int amount_of_objects = list.length();
		for(int i = 0;i < amount_of_objects ; i++){

			list[i].draw(window);

		}

	}
};
