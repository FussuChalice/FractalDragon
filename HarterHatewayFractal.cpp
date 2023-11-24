// HarterHatewayFractal.cpp : Defines the entry point for the application.
//


#include "HarterHatewayFractal.h"

const int WINDOW_HEIGHT = 960;
const int WINDOW_WIDTH = 540;
const int FRAMERATE_LIMIT = 60;
const char* WINDOW_TITLE = "Dragon fractal visualization";
const int MAX_DEPTH = 24; // See on your RAM Gb count

std::string getDirectoryPath(char *executableFilePath);
void drawFractalDragon(sf::RenderWindow& window, int depth, sf::Vector2f startPoint, sf::Vector2f endPoint, sf::Color color);

int main(int argc, char* argv[])
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(WINDOW_HEIGHT, WINDOW_WIDTH), WINDOW_TITLE);
    window.setFramerateLimit(FRAMERATE_LIMIT);

    sf::Clock clock;
    float timeElapsed = 0.0f;
    float animationDuration = 2.0f; // Duration for the animation in seconds

    int maxDepth = 1; // Maximum depth of recursion
    int currentDepth = 0; // Current depth of recursion

    std::string executeDirectoryPath = getDirectoryPath(argv[0]);

    std::cout << "Executable File Directory: " << executeDirectoryPath << std::endl;

    bool isRunning = true; // Flag to control the animation

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            else if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space)
            {
                isRunning = !isRunning; // Toggle the animation on Space key press
            }
        }

        // if don't stop app will have lags
        if (currentDepth >= MAX_DEPTH)
        {
            isRunning = false;
        }

        if (isRunning)
        {
            // clear the window with black color
            window.clear(sf::Color::Black);

            // Set the position where you want to place the Fractal Dragon
            sf::Vector2f position(500.0f, 200.0f);

            // Calculate the initial size of the Fractal Dragon
            float initialSize = std::min(WINDOW_WIDTH, WINDOW_HEIGHT) * 0.75f;

            // Calculate the initial starting and ending points for the Fractal Dragon
            sf::Vector2f startPoint = position - sf::Vector2f(initialSize / 2.0f, 0.0f);
            sf::Vector2f endPoint = position + sf::Vector2f(initialSize / 2.0f, 0.0f);

            // Calculate the depth based on the elapsed time
            timeElapsed = clock.getElapsedTime().asSeconds();
            currentDepth = static_cast<int>((timeElapsed / animationDuration) * maxDepth);

            drawFractalDragon(window, currentDepth, startPoint, endPoint, sf::Color::Green);

            window.display();
        }
    }

    return 0;
}

std::string getDirectoryPath(char *executableFilePath)
{
    std::string charToStringPathConverted(executableFilePath);

    std::size_t lastSeparator = charToStringPathConverted.find_last_of("\\/");
    std::string directoryPath = charToStringPathConverted.substr(0, lastSeparator);

    for (size_t i = 0; i < directoryPath.size(); i++) {
        if (directoryPath[i] == '\\') {
            directoryPath.replace(i, 1, "//");
            i++;
        }
    }

    return directoryPath;
}


void drawFractalDragon(sf::RenderWindow& window, int depth, sf::Vector2f startPoint, sf::Vector2f endPoint, sf::Color color) 
{
    if (depth == 0) {
        sf::Vertex line[] = {
            sf::Vertex(startPoint, color),
            sf::Vertex(endPoint, color)
        };
        window.draw(line, 2, sf::Lines);
    }
    else {
        sf::Vector2f midPoint = (startPoint + endPoint) / 2.0f;

        sf::Vector2f diffVector = endPoint - startPoint;
        sf::Vector2f perpendicularVector(-diffVector.y, diffVector.x);
        sf::Vector2f newEndPoint = midPoint + perpendicularVector / 2.0f;

        drawFractalDragon(window, depth - 1, startPoint, newEndPoint, color);
        drawFractalDragon(window, depth - 1, endPoint, newEndPoint, color);
    }
}
