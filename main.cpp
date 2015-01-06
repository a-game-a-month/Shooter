
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>




int main(int argc, char *argv[]) { 

  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML window");

  sf::Texture texture;
  if(!texture.loadFromFile("bin/cute_image.jpg"))
    return EXIT_FAILURE;
  sf::Sprite sprite(texture);
  sprite.scale(800.f / sprite.getTexture()->getSize().x,
               600.f / sprite.getTexture()->getSize().y);

  sf::Font font;
  if(!font.loadFromFile("bin/arial.ttf"))
    return EXIT_FAILURE;
  sf::Text text("Hello SFML", font, 50);

  sf::Music music;
  if(!music.openFromFile("bin/nice_music.ogg"))
    return EXIT_FAILURE;

  music.play();

  while(window.isOpen()) {
    sf::Event event;
    while(window.pollEvent(event)) {
      if(event.type == sf::Event::Closed)
        window.close();
    }

    window.clear();
    window.draw(sprite);
    window.draw(text);
    window.display();
  }


  return EXIT_SUCCESS;
}
