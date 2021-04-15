#include <iostream>
#include <boost/asio.hpp>

void read_information_while(boost::asio::ip::tcp::socket& socket);

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