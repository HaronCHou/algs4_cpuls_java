
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "Percolation.h"  // Assuming the Percolation class exists

void draw(Percolation& perc, int N, sf::RenderWindow& window) {
    window.clear();

    // Draw the N-by-N grid
    for (int row = 1; row <= N; ++row) {
        for (int col = 1; col <= N; ++col) {
            sf::RectangleShape square(sf::Vector2f(600.0f / N, 600.0f / N));
            square.setPosition((col - 1) * (600.0f / N), (N - row) * (600.0f / N));

            if (perc.isFull(row, col)) {
                square.setFillColor(sf::Color(173, 216, 230));  // Light blue
            }
            else if (perc.isOpen(row, col)) {
                square.setFillColor(sf::Color::White);
            }
            else {
                square.setFillColor(sf::Color::Black);
            }
            window.draw(square);
        }
    }

    window.display();
}

#define DEBUG_READ_FROM_INFILE
int main(int argc, char** argv) {
    int N;
#ifdef DEBUG_READ_FROM_INFILE
    std::ifstream infile(argv[1]); // xx.txt
    infile >> N;
#else
    std::cin >> N;
#endif  
    sf::RenderWindow window(sf::VideoMode(600, 600), "Percolation Visualizer");

    Percolation perc(N);
    draw(perc, N, window);

    int i, j;
#ifdef DEBUG_READ_FROM_INFILE
    while (infile >> i >> j) 
#else
    while (std::cin >> i >> j) 
#endif    
    {
        perc.open(i, j);
        draw(perc, N, window);
        sf::sleep(sf::milliseconds(50));  // Animation delay
    }
    // Event loop to handle window events such as closing
    sf::Event event;
    while (window.isOpen()) {
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();  // Close the window if the user clicks the close button
            }
        }
    }
    return 0;
}
