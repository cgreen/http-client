#include "HttpClient.h"


HttpClient::HttpClient(string address, string port)
{
	connected = false;
	host_address = address;
	host_port = port;
}


HttpClient::~HttpClient(void)
{
	Disconnect();
}


void HttpClient::Connect(void)
{
	if (!connected)
	{
		tcp_stream.connect(host_address, host_port);
		connected = true;
	}
}


void HttpClient::Disconnect(void)
{
	if (connected)
	{
		tcp_stream.close();
		connected = false;
	}
}


string HttpClient::Get(string uri)
{
	Connect();

	tcp_stream << "GET ";
	tcp_stream << uri;
	tcp_stream << " HTTP/1.0";
	tcp_stream << "\n\nHOST: " << host_address;
	tcp_stream.flush();

	istream_iterator<char> it(tcp_stream);
	istream_iterator<char> end;
	string results(it, end);

	Disconnect();

	return results;
}