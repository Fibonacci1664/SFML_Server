#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

//void testApp()
//{
//    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
//    sf::CircleShape shape(100.f);
//    shape.setFillColor(sf::Color::Green);
//
//    while (window.isOpen())
//    {
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed)
//                window.close();
//        }
//
//        window.clear();
//        window.draw(shape);
//        window.display();
//    }
//}


int main()
{
	//testApp();

	sf::TcpListener tcpListener;

	// Bind the listener to a port
	if (tcpListener.listen(53000) != sf::Socket::Done)
	{
		std::cout << "Bind failed!\n";
	}
	else
	{
		std::cout << "Bind worked!\n";
	}

	// Accept a new connection
	sf::TcpSocket clientSocket;
	if (tcpListener.accept(clientSocket) != sf::Socket::Done)
	{
		std::cout << "Accept failed!\n";
	}
	else
	{
		std::cout << "Accept worked!\n";
	}

	return 0;
}