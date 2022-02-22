#include <SFML/Graphics.hpp>
#include <SFML/Window/Export.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <iostream> 
#include <vector>


#include "input.h"
//#include "Casesar.h"

FocusController fc;

int main()
{
    std::vector<char> input;
    std::string stri;

    sf::RenderWindow window(sf::VideoMode(1024, 622), "caesar cipher", sf::Style::Default);

    sf::Texture background;
    sf::Sprite backgroundImage;

    if (!background.loadFromFile("background.jpg"))
        std::cout << "Error: Could not display background.jpg" << std::endl;

    backgroundImage.setTexture(background);

    sf::Font font;
    if (!font.loadFromFile("font.otf"))
        std::cout << "Can't find the font file" << std::endl;

    sf::Texture encryptButton;
    sf::Sprite encryptButtonImage;
    if (!encryptButton.loadFromFile("Button.png"))
        std::cout << "Can't find the image" << std::endl;
    encryptButtonImage.setPosition(40.0f, 490.0f);
    encryptButtonImage.setScale(0.2, 0.2);

    float encryptButtonWidth = encryptButtonImage.getLocalBounds().width;
    float encryptButtonHeight = encryptButtonImage.getLocalBounds().height;

    encryptButtonImage.setTexture(encryptButton);

    sf::Texture decryptButton;
    sf::Sprite decryptButtonImage;
    if (!decryptButton.loadFromFile("Button.png"))
        std::cout << "Can't find the image" << std::endl;
    decryptButtonImage.setPosition(340.0f, 490.0f);
    decryptButtonImage.setScale(0.2, 0.2);

    float decryptButtonWidth = decryptButtonImage.getLocalBounds().width;
    float decryptButtonHeight = decryptButtonImage.getLocalBounds().height;

    decryptButtonImage.setTexture(encryptButton);

    sf::Text encryptText;
    encryptText.setFont(font);
    encryptText.setStyle(sf::Text::Bold);
    encryptText.setString("encrypt");
    encryptText.setFillColor(sf::Color::Black);
    encryptText.setCharacterSize(25);
    encryptText.setPosition(50.0f, 500.0f);

    sf::Text decryptText;
    decryptText.setFont(font);
    decryptText.setStyle(sf::Text::Bold);
    decryptText.setString("decrypt");
    decryptText.setFillColor(sf::Color::Black);
    decryptText.setCharacterSize(25);
    decryptText.setPosition(350.0f, 500.0f);

    sf::Text inputText;
    inputText.setFont(font);
    inputText.setStyle(sf::Text::Bold);
    inputText.setString(stri);
    inputText.setFillColor(sf::Color::Black);
    inputText.setCharacterSize(25);
    inputText.setPosition(5.0f, 5.0f);



    sf::Text txt;
    txt.setFont(font);
    txt.setString(L" ");
    txt.setFillColor(sf::Color::Black);
    txt.setCharacterSize(25);
    txt.setPosition(5.0f, 5.0f);

    int x = 0;
    TextBox tb(txt);
    fc.setFocusObject(&tb);

    sf::Text ces;
    ces.setFont(font);
    ces.setString(txt.getString());
    ces.setFillColor(sf::Color::Black);
    ces.setCharacterSize(25);
    ces.setPosition(25.0f, 5.0f);

    while (window.isOpen())
    {
                sf::Event Event;
        while (window.pollEvent(Event))
        {
            switch (Event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::MouseMoved:
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (decryptButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    decryptButtonImage.setColor(sf::Color(250, 20, 20));
                }
                else
                {
                    decryptButtonImage.setColor(sf::Color(255, 255, 255));
                }
            }
            break;
            case sf::Event::MouseButtonPressed:
            {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                sf::Vector2f mousePosF(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
                if (decryptButtonImage.getGlobalBounds().contains(mousePosF))
                {
                    std::cout << "Clicked, yay!" << std::endl;
                }
            }
            
            break;
            }
            
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::MouseButtonPressed) {}
                FocusObject* fo = fc.getFocusObject();
                if (fo != 0) { fo->event(event); }
                
            }
        }
        
        
        window.clear();
        window.draw(backgroundImage);
        window.draw(decryptButtonImage);
        window.draw(encryptButtonImage);
        window.draw(encryptButtonImage);
        window.draw(encryptText);
        window.draw(decryptText);
        window.draw(tb);


        window.draw(ces);
        window.draw(inputText);
        window.display();

    }

   
    return 0;
    
}