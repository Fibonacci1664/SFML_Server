#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>

char dataBuffer[100];
std::size_t received;
sf::IpAddress SERVERIP = "127.0.0.1";
unsigned short SERVERPORT = 4444;

void createTCPListener();
void createUDP();
void testApp();

int main()
{
	//testApp();
	//createTCPListener();
	createUDP();

	return 0;
}

void createTCPListener()
{
	sf::TcpListener tcpListener;

	// Bind the listener to a port
	if (tcpListener.listen(SERVERPORT) != sf::Socket::Done)
	{
		std::cout << "Bind failed!\n";
	}
	else
	{
		std::cout << "Bind worked\n";
		std::cout << "Listening for messages on TCP...\n";
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

	if (clientSocket.receive(dataBuffer, 100, received) != sf::Socket::Done)
	{
		std::cout << "Error receiving using TCP!\n";
	}

	std::cout << "Received " << received << " bytes\n";
}

void createUDP()
{
	sf::UdpSocket udpServerSocket;

	if (udpServerSocket.bind(SERVERPORT) != sf::Socket::Done)
	{
		std::cout << "UDP bind failed!\n";
	}

	sf::IpAddress clientIP;
	unsigned short clientPort;

	if (udpServerSocket.receive(dataBuffer, 100, received, clientIP, clientPort) != sf::Socket::Done)
	{
		std::cout << "Error receiving using UDP!\n";
	}

	std::cout << "Received " << received << " bytes from " << SERVERIP << " on port num " << SERVERPORT << '\n';

	// Send data to echo
	if (udpServerSocket.send(dataBuffer, 100, SERVERIP, SERVERPORT) != sf::Socket::Done)
	{
		std::cout << "Error sending echo data by UDP!\n";
	}
	else
	{
		std::cout << "Msg sent!\n";
	}
}

void testApp()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
}