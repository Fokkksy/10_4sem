#include <iostream>
#include <boost/asio.hpp>

void read_information_while(boost::asio::ip::tcp::socket& socket);
void write_information(boost::asio::ip::tcp::socket& socket, const std::string& user_name);

int main()
{

}

void read_information_while(boost::asio::ip::tcp::socket& socket)
{
    boost::asio::streambuf buffer;
    std::string message;

    do
    {
        boost::asio::read_until(socket, buffer, '\n');

        std::istream input_stream(&buffer);
        std::getline(input_stream, message, '\n');

        std::cout << message << std::endl;
    } while (message != "The conversation is ended");

}

void write_information(boost::asio::ip::tcp::socket& socket, const std::string& user_name)
{

    std::string message;

    std::getline(std::cin, message);
    while (message != "exit")
    {
        boost::asio::write(socket, boost::asio::buffer(user_name + " says: " + message + "\n"));
        std::getline(std::cin, message);
    }

    message = "The conversation is ended\n";

    boost::asio::write(socket, boost::asio::buffer(message));

}
