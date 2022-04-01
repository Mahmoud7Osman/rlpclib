class NetworkTools{
	private:
		SOCKET 	sock;
		SOCKET 	connection;
		WSADATA	wsadata;

		int  wsv=2;
		int  tmp_i;

		char tmp_c;
		char *ipaddr;

		struct sockaddr_in  address;
		struct sockaddr_in  tmp_sin;
		struct hostent*     host;
		struct in_addr	    inaddr;

		int SetAddr(char* addr, int port){
			ipaddr=GetHostByName(addr);
			address.sin_addr.s_addr=inet_addr(addr);
			return 0;
		}
	public:
		NetworkTools(){
			WSAStartup(MAKEWORD(wsv, 0), &wsadata);
		}

		char* GetHostByName(const char* addr){
			host=gethostbyname(addr);
			memcpy(&inaddr, host->h_addr, sizeof(struct in_addr));

			if (host == NULL)
			return NULL;

			ipaddr=inet_ntoa(inaddr);
			memset(&inaddr, 0x00 ,sizeof(struct in_addr));
			return ipaddr;
		}

		int TCPListen(char* addr, int port){
			sock=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if (sock == INVALID_SOCKET)
				return 1;
			return 0;
		}
		int TCPSend(){
			return 0;
		}
		int TCPReceive(){
			return 0;
		}


		~NetworkTools(){
			closesocket(sock);
			closesocket(connection);
			WSACleanup();
		}
};
