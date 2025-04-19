#include <SFML/Graphics.hpp>
#include <deque>
#include <cstdlib>
#include <ctime>
#include <sstream>  // for stringstream

class SnakeGame {
public:
    SnakeGame()
        : window(sf::VideoMode(800, 600), "Snake Game"), 
          snakeDirection(sf::Vector2i(1, 0)), 
          snakeSize(20), 
          gameOver(false), 
          score(0) {
        srand(static_cast<unsigned int>(time(0)));
        snake.push_back(sf::Vector2i(10, 10));  // Starting position of the snake
        spawnFood();
    }

    void run() {
        while (window.isOpen()) {
            handleEvents();
            if (!gameOver) {
                update();
            }
            render();
        }
    }

private:
    sf::RenderWindow window;
    std::deque<sf::Vector2i> snake;
    sf::Vector2i snakeDirection;
    int snakeSize;
    bool gameOver;
    sf::Vector2i food;
    int score;

    void handleEvents() {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Up && snakeDirection != sf::Vector2i(0, 1)) {
                    snakeDirection = sf::Vector2i(0, -1);
                }
                if (event.key.code == sf::Keyboard::Down && snakeDirection != sf::Vector2i(0, -1)) {
                    snakeDirection = sf::Vector2i(0, 1);
                }
                if (event.key.code == sf::Keyboard::Left && snakeDirection != sf::Vector2i(1, 0)) {
                    snakeDirection = sf::Vector2i(-1, 0);
                }
                if (event.key.code == sf::Keyboard::Right && snakeDirection != sf::Vector2i(-1, 0)) {
                    snakeDirection = sf::Vector2i(1, 0);
                }
            }
        }
    }

    void update() {
        // Move the snake
        sf::Vector2i newHead = snake.front() + snakeDirection;
        if (newHead.x < 0 || newHead.x >= 800 / snakeSize || newHead.y < 0 || newHead.y >= 600 / snakeSize || collisionWithSelf(newHead)) {
            gameOver = true;
            return;
        }

        snake.push_front(newHead);

        // Check if snake eats food
        if (newHead == food) {
            score++;
            spawnFood();  // Generate new food
        } else {
            snake.pop_back();  // Remove last part of the snake if no food was eaten
        }
    }

    void render() {
        window.clear();
        
        // Draw the snake
        for (int i = 0; i < snake.size(); i++) {
            sf::RectangleShape rectangle(sf::Vector2f(snakeSize, snakeSize));
            rectangle.setPosition(snake[i].x * snakeSize, snake[i].y * snakeSize);
            rectangle.setFillColor(sf::Color::Green);
            window.draw(rectangle);
        }

        // Draw the food
        sf::RectangleShape foodShape(sf::Vector2f(snakeSize, snakeSize));
        foodShape.setPosition(food.x * snakeSize, food.y * snakeSize);
        foodShape.setFillColor(sf::Color::Red);
        window.draw(foodShape);

        // Display score and game over message
        if (gameOver) {
            sf::Font font;
            font.loadFromFile("arial.ttf");  // Ensure the font file is present
            std::stringstream ss;
            ss << score;
            sf::Text text("Game Over! Score: " + ss.str(), font, 30);
            text.setFillColor(sf::Color::White);
            text.setPosition(250, 300);
            window.draw(text);
        }

        window.display();
    }

    void spawnFood() {
        food.x = rand() % (800 / snakeSize);
        food.y = rand() % (600 / snakeSize);
    }

    bool collisionWithSelf(const sf::Vector2i& newHead) {
        for (int i = 0; i < snake.size(); i++) {
            if (snake[i] == newHead) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    SnakeGame game;
    game.run();
    return 0;
}
