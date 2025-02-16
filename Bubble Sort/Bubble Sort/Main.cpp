//help from youtube
//#include<iostream>
//#include<vector>
//#include<SFML/Graphics.hpp>
//#include<ctime>
//using namespace std; 
//const int weight = 1000; 
//const int height = 800; 
//
//struct Rectangle {
//	int height = 0; 
//	int weight = 3; 
//
//	int x_location = 0; 
//	int y_location = 0; 
//	
//	sf::Color color = sf::Color(177, 237, 232); 
//};
//
//void fillVector( vector<Rectangle>& recHolder, sf::Image image) {
//	Rectangle rec; 
//	int xOffset = 0; 
//
//	while (xOffset < image.getSize().x) {
//		rec.height = rand() % image.getSize().y - 50; 
//		if (rec.height < 5) { rec.height = 5;  }
//		rec.x_location = xOffset; 
//		rec.y_location = image.getSize().y - rec.height;
//		recHolder.push_back(rec);
//		xOffset += 5; 
//	}
//	cout << recHolder.size() << endl; 
//}
//
//void printImage(sf::Image &img, vector<Rectangle> rectHolder) {
//	for (int i = 0; i < rectHolder.size(); i++) {
//		for (int x = 0; x < rectHolder[i].weight; ++x) {
//			for (int y = 0; y < rectHolder[i].height; ++y) {
//				img.setPixel(
//					rectHolder[i].x_location + x,
//					rectHolder[i].y_location + y, 
//					rectHolder[i].color);
//			}
//		}
//	}
//}
//
//void bubbleSort(vector<Rectangle>& rectHolder,sf::Image& img,sf::RenderWindow &window) {
//	sf::Texture texture;
//	sf::Sprite sprite;
//	for (int i = 0; i < rectHolder.size(); i++) {
//		for (int j = 0; j < rectHolder.size() - 1; j++) {
//			if (rectHolder[j].height > rectHolder[j + 1].height) {
//				window.clear();
//					for (int x = 0; x < rectHolder[j].weight; ++x) {
//						for (int y = 0; y < rectHolder[j].height; ++y) {
//							img.setPixel(
//								rectHolder[j+1].x_location + x,
//								rectHolder[j].y_location + y,
//								rectHolder[j].color);
//						}
//					}
//					
//					for (int x = 0; x < rectHolder[j].weight; ++x) {
//						for (int y = 0; y < rectHolder[j].height; ++y) {
//							img.setPixel(
//								rectHolder[j].x_location + x,
//								rectHolder[j].y_location + y,
//								sf::Color(255,255,255));
//						}
//					}
//
//					for (int x = 0; x < rectHolder[j+1].weight; ++x) {
//						for (int y = 0; y < rectHolder[j+1].height; ++y) {
//							img.setPixel(
//								rectHolder[j].x_location + x,
//								rectHolder[j+1].y_location + y,
//								rectHolder[j].color);
//						}
//					}
//				
//				swap(rectHolder[j].x_location, rectHolder[j + 1].x_location);
//				swap(rectHolder[j], rectHolder[j + 1]);
//				texture.loadFromImage(img);
//				sprite.setTexture(texture);
//				window.draw(sprite);
//				window.display();
//			}
//		}
//	}
//}
//
//int main()  {
//	srand(time(NULL));
//
//	sf::RenderWindow window(sf::VideoMode(weight, height), "Bubble Sort");
//	sf::Event event; 
//	bool spaceOn = false;
//
//	sf::Image image;
//	image.create(weight, height);
//
//	for (int i = 0; i < weight; ++i) {
//		for (int j = 0; j < height; ++j) {
//			image.setPixel(i, j, sf::Color(255, 255, 255));
//		}
//	}
//
//	sf::Texture texture; 
//	sf::Sprite sprite; 
//
//	Rectangle rectangle; 
//	vector<Rectangle> rectangleVector; 
//
//	fillVector(rectangleVector, image);
//	printImage(image, rectangleVector);
//
//	texture.loadFromImage(image);
//	sprite.setTexture(texture);
//
//
//	while (window.isOpen()) {
//		while (window.pollEvent(event)) {
//			if (event.type == sf::Event::Closed) window.close();
//			if (event.type == sf::Event::KeyReleased) {
//				if (event.key.code == sf::Keyboard::Space) {
//					cout << "Space Work" << endl; 
//					spaceOn = true;
//				}
//			}
//			if (event.type == sf::Event::KeyReleased) {
//				if (event.key.code == sf::Keyboard::Escape) {
//					window.close();
//				}
//			}
//		}
//		
//		texture.loadFromImage(image);
//		sprite.setTexture(texture);
//
//		window.clear();
//		
//		if (spaceOn) {
//			bubbleSort(rectangleVector,image,window);
//			spaceOn = false;
//		}
//		window.draw(sprite);
//
//		window.display(); 
//	}
//	return 0; 
//}

//my own way
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

const int width = 1000;
const int height = 800;
const int rectWidth = 3;

void fillBar(vector<sf::RectangleShape>& bars) {
    int xOffset = 0;
    while (xOffset < width) {
        int rectHeight = rand() % (height - 50) + 5; 
        sf::RectangleShape rect(sf::Vector2f(rectWidth, rectHeight));
        rect.setFillColor(sf::Color::Blue);
        rect.setPosition(sf::Vector2f(xOffset, height - rectHeight));
        xOffset += rectWidth + 2; 
        bars.push_back(rect);
    }
    cout << "Bars generated: " << bars.size() << endl;
}

int main() {
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(width, height), "Bubble Sort Visualization");
    sf::Event event;

    vector<sf::RectangleShape> bars;
    fillBar(bars);

    sf::Clock clock;
    bool isSorting = false; 

    static int i = 0, j = 0;

    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) window.close();
            if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
                cout << "Sorting Started\n";
                isSorting = true; 
            }
        }

        if (isSorting && clock.getElapsedTime().asMilliseconds() >= 1.f) {
            if (i < bars.size() - 1) {
                if (j < bars.size() - i - 1) {
                    if (bars[j].getSize().y < bars[j + 1].getSize().y) {
                        float tempX = bars[j].getPosition().x;
                        bars[j].setPosition(bars[j + 1].getPosition().x, bars[j].getPosition().y);
                        bars[j + 1].setPosition(tempX, bars[j + 1].getPosition().y);

                        swap(bars[j], bars[j + 1]);
                    }
                    j++; 
                }
                else {
                    j = 0; 
                    i++;  
                }
            }
            else {
                isSorting = false; 
                cout << "Sorting Done!\n";
            }
            clock.restart();
        }

        
        window.clear(sf::Color::White);
        for (auto& bar : bars) window.draw(bar);
        window.display();
    }
}
