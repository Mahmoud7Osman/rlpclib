class NetworkTools{
	private:
		SOCKET 	sh, ch;
		SOCKET 	connection;
		WSADATA	wsadata;

		int  wsv=2;
		int  i_tmp=1;

		char tmp_c;
		char *ipaddr;

		struct sockaddr_in  address;
		struct sockaddr_in  client;
		struct hostent*     host;
		struct in_addr	    inaddr;

		socklen_t sai_size=sizeof(struct sockaddr_in);

		int SetAddr(char* addr, int port){
			ipaddr=GetHostByName(addr);
			address.sin_addr.s_addr=inet_addr(ipaddr);
			address.sin_family=AF_INET;
			address.sin_port=htons(port);
			return 0;
		}
	public:
		NetworkTools(){
			WSAStartup(MAKEWORD(wsv, 0), &wsadata);
		}
		SOCKET Socket(){
			return ch;
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
			sh=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

			if (sh == INVALID_SOCKET)
				return 1;

			setsockopt(sh, SOL_SOCKET, SO_REUSEADDR, &i_tmp, sizeof(int));

			address.sin_family=AF_INET;
			address.sin_port=htons(port);
			address.sin_addr.s_addr = inet_addr(GetHostByName(addr));

			bind(sh, (struct sockaddr*)&address, sizeof(struct sockaddr_in));

			ch=accept(sh, (struct sockaddr*)&client, &sai_size);
			if (ch == INVALID_SOCKET)
				return 1;

			return 0;
		}
		int TCPConnect(const char* addr, int port){


			return 0;
		}
		void TCPSend(const char* data, unsigned int size=0){


			return 0;
		}
		void TCPReceive(char* dest, unsigned int size=0){


			return 0;
		}

		int UDPStart(const char* addr, int port){


			return 0;
		}
		void UDPSetEndpoint(const char* addr, int port){


			return 0;
		}

		~NetworkTools(){
			closesocket(sock);
			closesocket(connection);
			WSACleanup();
		}
};
