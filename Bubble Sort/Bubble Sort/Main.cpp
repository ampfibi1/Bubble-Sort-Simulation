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
                    if (bars[j].getSize().y > bars[j + 1].getSize().y) {
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
