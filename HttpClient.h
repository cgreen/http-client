#pragma once
#include <boost/asio.hpp>

using namespace boost::asio;
using namespace std;

class HttpClient
{
	bool connected;
	string host_address;
	string host_port;
	ip::tcp::iostream tcp_stream;

	void Connect(void);
	void Disconnect(void);
public:
	HttpClient(string address, string port);
	~HttpClient(void);
	string Get(string uri);
};

