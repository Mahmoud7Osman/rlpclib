class NetworkTools{
	private:
		SOCKET 	sh, ch;
		WSADATA	wsadata;

		int  i_tmp=1;

		char tmp_c;
		char *ipaddr;
		char UDPType;
		char isConnected='n';

		struct sockaddr_in  address;
		struct sockaddr_in  client;
		struct hostent*     host;
		struct in_addr	    inaddr;

		int sai_size=sizeof(struct sockaddr_in);

		int SetAddr(const char* addr, int port){
			ipaddr=GetHostByName(addr);
			address.sin_addr.s_addr=inet_addr(ipaddr);
			address.sin_family=AF_INET;
			address.sin_port=htons(port);
			return 0;
		}
	public:
		NetworkTools(){
			WSAStartup(MAKEWORD(2, 2), &wsadata);
			memset(&client, 0x00, sizeof(client));
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

		int TCPServer(const char* addr, int port){
			sh=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

			if (sh == INVALID_SOCKET){
				return 1;
			}

			setsockopt(sh, SOL_SOCKET, SO_REUSEADDR,(const char*) &i_tmp, sizeof(int));

			address.sin_family=AF_INET;
			address.sin_port=htons(port);
			if (*addr == '*')
				address.sin_addr.s_addr=0;
			else
				address.sin_addr.s_addr = inet_addr(GetHostByName(addr));

			bind(sh, (struct sockaddr*)&address, sizeof(struct sockaddr_in));
			listen(sh, 10);
			ch=accept(sh, (struct sockaddr*)&client, &sai_size);
			if (ch == INVALID_SOCKET){
				return 1;
			}

			return 0;
		}
		int TCPConnect(const char* addr, int port){
			sh=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if (sh == INVALID_SOCKET)
				return 1;

			i_tmp=SetAddr(addr, port);
			if (i_tmp)
				return i_tmp;

			i_tmp=connect(sh, (struct sockaddr*)&client, sizeof(struct sockaddr_in));
			if (i_tmp)
				return i_tmp;

			ch=sh;
			return 0;
		}
		void TCPSend(const char* data, unsigned int size=0){
			if (size==0)
				size=strlen(data);
			send(ch, data, size, 0);

			return;
		}
		void TCPSend(MemoryBuffer data, unsigned int size=0){
			if (size==0)
				size=data.size;
			send(ch, data.data, size, 0);

			return;
		}
		void TCPReceive(MemoryBuffer dest, unsigned int size=0){
			memset(dest.data, 0x00, dest.size);
			if(size==0)
				size=dest.size;
			for(i_tmp=0; (unsigned int)i_tmp<=size; i_tmp++)
				if (0 >= recv(ch, dest.data++, 1, 0))
					break;

			return;
		}

		int UDPServer(const char* addr, int port){
			sh=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
			if (sh == INVALID_SOCKET)
				return 1;
			i_tmp=1;
			setsockopt(sh, SOL_SOCKET, SO_REUSEADDR, (const char*)&i_tmp, sizeof(int));

			memset(&address, 0x00, sizeof(struct sockaddr_in));
			if (*addr == '*')
				address.sin_addr.s_addr = 0;
			else
				address.sin_addr.s_addr = inet_addr(GetHostByName(addr));

			address.sin_port = htons(port);
			address.sin_family = AF_INET;

			i_tmp=bind(sh, (struct sockaddr*)&address, sizeof(struct sockaddr_in));
			if (i_tmp)
				return i_tmp;

			UDPType='s';
			return 0;
		}
		int UDPSetEndpoint(const char* addr, int port){
			if (UDPType != 's' && isConnected != 'y'){
				sh=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
				if (sh == INVALID_SOCKET)
					return 1;
				ch=sh;
				isConnected='y';
				UDPType='c';
			}
			return SetAddr(addr, port);
		}

		void UDPSend(const char* src, unsigned int size=0){
			if (!size)
				size=strlen(src);
			sendto(sh, src, size, 0, (struct sockaddr*)&client, sizeof(struct sockaddr_in));
		}
		void UDPSend(MemoryBuffer src, unsigned int size=0){
			if (!size)
				size=src.size;
			sendto(sh, src.data, size, 0, (struct sockaddr*)&client, sizeof(struct sockaddr_in));

		}
		void UDPReceive(MemoryBuffer dst, unsigned int size=0){
			memset(dst.data, 0x00, dst.size);
			if (!size)
				size=dst.size;
			recvfrom(sh, dst.data, size, 0, (struct sockaddr*)&client, (int*)&sai_size);
		}
		~NetworkTools(){
			closesocket(sh);
			closesocket(ch);
			WSACleanup();
		}
};
