#include <iostream>
#include <SFML/Graphics.hpp>
#include <time.h>
#include "MoveTile.h"
#include <windows.h>


int main()
{
	srand(time(0));
	sf::RenderWindow window(sf::VideoMode(WIDTH - 8, HEIGHT - 8), "2048",sf::Style::Close);



	sf::Texture tblank, t2, t4, t8, t16, t32, t64, t128, t256, t512, t1024, t2048, tnothing;

	tblank.loadFromFile("images/blank.png");
	t2.loadFromFile("images/2.png");
	t4.loadFromFile("images/4.png");
	t8.loadFromFile("images/8.png");
	t16.loadFromFile("images/16.png");
	t32.loadFromFile("images/32.png");
	t64.loadFromFile("images/64.png");
	t128.loadFromFile("images/128.png");
	t256.loadFromFile("images/256.png");
	t512.loadFromFile("images/512.png");
	t1024.loadFromFile("images/1024.png");
	t2048.loadFromFile("images/2048.png");
	tnothing.loadFromFile("images/test.png");


	sf::Sprite sprite_blank(tblank);
	sf::Sprite sprite_2(t2);
	sf::Sprite sprite_4(t4);
	sf::Sprite sprite_8(t8);
	sf::Sprite sprite_16(t16);
	sf::Sprite sprite_32(t32);
	sf::Sprite sprite_64(t64);
	sf::Sprite sprite_128(t128);
	sf::Sprite sprite_256(t256);
	sf::Sprite sprite_512(t512);
	sf::Sprite sprite_1024(t1024);
	sf::Sprite sprite_2048(t2048);
	sf::Sprite sprite_nothing(tnothing);

	addNewTile();
	addNewTile();

	while (window.isOpen()){
		
		sf::Event event;
		while (window.pollEvent(event)){


			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::KeyPressed && !gWin){
				if (event.key.code == sf::Keyboard::Left)
					move(Left);
				else if (event.key.code == sf::Keyboard::Right)
					move(Right);
				else if (event.key.code == sf::Keyboard::Up)
					move(Up);
				else if (event.key.code == sf::Keyboard::Down)
					move(Down);
			}
		}

		//Check win
		if (!gWin)
			for (int i = 0; i<N; i++)
				for (int j = 0; j<M; j++)
					if (MAP[i][j] == 2048)
					{
						gWin = 1;
						std::cout << "You win";
						break;
					}

		////check lose
		//bool temp = true;
		//if (!gLose) {
		//	std::cout << gLose;
		//	for (int i = 0; i < N; i++)
		//		for (int j = 0; j < M; j++)
		//			if (MAP[i][j] == 0)
		//			{
		//				temp = false;
		//				break;
		//			}
		//	if (temp == true) {
		//		gLose = true;
		//		std::cout << "You lose";
		//	}
		//
		//}

		window.clear();
		for (int i = 0; i<M; i++)
			for (int j = 0; j<N; j++){
				if (MAP[i][j] == 0){
					sprite_blank.setPosition(j*TILESIZE, i*TILESIZE);
					window.draw(sprite_blank);
				}
				else if (MAP[i][j] == 2){
					sprite_2.setPosition(j*TILESIZE, i*TILESIZE);
					window.draw(sprite_2);
				}
				else if (MAP[i][j] == 4){
					sprite_4.setPosition(j*TILESIZE, i*TILESIZE);
					window.draw(sprite_4);
				}
				else if (MAP[i][j] == 16) {
					sprite_nothing.setPosition(j*TILESIZE, i*TILESIZE);
					window.draw(sprite_nothing);
				}
				else if (MAP[i][j] == 256){
					sprite_nothing.setPosition(j*TILESIZE, i*TILESIZE);
					window.draw(sprite_nothing);
				}
				else if (MAP[i][j] == 32){
					sprite_32.setPosition(j*TILESIZE, i*TILESIZE);
					window.draw(sprite_32);
				}
				else if (MAP[i][j] == 64){
					sprite_64.setPosition(j*TILESIZE, i*TILESIZE);
					window.draw(sprite_64);
				}
				else if (MAP[i][j] == 128){
					sprite_128.setPosition(j*TILESIZE, i*TILESIZE);
					window.draw(sprite_128);
				}
				else if (MAP[i][j] == 256){
					sprite_256.setPosition(j*TILESIZE, i*TILESIZE);
					window.draw(sprite_256);
				}
				else if (MAP[i][j] == 512){
					sprite_512.setPosition(j*TILESIZE, i*TILESIZE);
					window.draw(sprite_512);
				}
				else if (MAP[i][j] == 1024){
					sprite_1024.setPosition(j*TILESIZE, i*TILESIZE);
					window.draw(sprite_1024);
				}
				else if (MAP[i][j] == 2048){
					sprite_2048.setPosition(j*TILESIZE, i*TILESIZE);
					window.draw(sprite_2048);
				}
			}
		window.display();
		
	}

	return 0;
}