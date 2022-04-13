class NetworkTools{
	private:
		int   sfd;
		int   cfd;
		int  port;
		int rcv=1;
		int i_tmp=1;

		size_t size;


		char ipaddr[16];

		struct sockaddr_in server;
		struct sockaddr_in client;
		struct sockaddr_in    tmp;
		struct hostent*      host;

		socklen_t sai_size=sizeof(server);




		int SetAddr(const char* ip, int port){
			char* ipaddr=GetHostByName(ip);
			int inetpton=inet_pton(AF_INET, ipaddr, &client.sin_addr.s_addr);
			if (inetpton==-1)
				return 1;
			client.sin_port=htons(port);
			client.sin_family=AF_INET;
			return 0;
		}

       	public:
		int Socket(){
			return cfd;
		}
		char* GetHostByName(const char* sdomain){
			host=gethostbyname(sdomain);
			if (host==NULL)
				return 0x00;
			inet_ntop(AF_INET, host->h_addr, ipaddr, 16);
			return ipaddr;
		}
		int  TCPStart(const char *host, int port){
				sfd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if (sfd==-1)
					return 1;
				setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &i_tmp, sizeof(int));
				inet_pton(AF_INET, host, &server.sin_addr.s_addr);
				server.sin_port=htons(port);
				server.sin_family=AF_INET;

				bind(sfd, (struct sockaddr*)&server, sizeof(struct sockaddr_in));
				listen(sfd, 1);

				cfd=accept(sfd, (struct sockaddr*)&client, (socklen_t*)&(size=sizeof(struct sockaddr_in)));
				return 0;
		}
		int  TCPConnect(const char* ip, int port){
			sfd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
			if (sfd == -1)
				return 1;
			i_tmp=SetAddr(ip, port);
			if (i_tmp == 1)
				return 1;

			i_tmp=connect(sfd, (struct sockaddr*)&client, sai_size);

			if (i_tmp == -1)
				return 1;
			cfd=sfd;
			return 0;
		}
		void TCPSend(const char* data, unsigned int size=0){
			if (size == 0x00)
				send(cfd, data, strlen(data), IPPROTO_TCP);
			else
				send(cfd, data, size, IPPROTO_TCP);
		}
		void TCPSend(MemoryBuffer src, unsigned int size=0){
			if (size==0)size=src.size;
			send(cfd, src.data, src.size, 0);
		}
		void TCPReceive(char* dest, unsigned int size=0){
			if (size!=0x00){
				for(unsigned int tmp=0; tmp<size;tmp++){
					rcv=recv(cfd, dest++, 1, 0);

					if (rcv==-1 || rcv==0){
						memset(--dest, 0x00, 1);
						return;
					}
				}
				memset(dest, 0x00, 1);
			}
			else {
				while (rcv!=0x00 && rcv!=-1){
					rcv=recv(cfd, dest++, 1, 0);
				}
				memset(--dest, 0x00, 1);
			}
		}
		void TCPReceive(MemoryBuffer dst, unsigned int size=0){
			if (size==0)size=dst.size;
			recv(cfd, dst.data, dst.size, 0);
		}
		int UDPStart(const char* addr, int port){
			sfd=socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
			if (sfd==-1)
				return 1;
			cfd=sfd;
			setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &i_tmp, sizeof(int));

			server.sin_addr.s_addr=inet_addr(GetHostByName(addr));
			server.sin_port = htons(port);
			server.sin_family=AF_INET;

			if (i_tmp == 1)
				return i_tmp;
			i_tmp=bind(sfd, (struct sockaddr*)&server, sizeof(struct sockaddr_in));
			if (i_tmp == -1)
				return 1;
			return 0;
		}
		int UDPSetEndpoint(const char* addr, int port){
			return SetAddr(addr, port);
		}

		int UDPSend(const char* msg, unsigned int size=0){
			if (size==0)
				size=strlen(msg);
			printf ("%d Bytes Sent\n", sendto(sfd, msg, size, 0, (struct sockaddr*) &client, sizeof(struct sockaddr_in)));
			return 0;
		}

		int UDPSend(MemoryBuffer src, unsigned int size=0){
			if (size==0) size=src.size;

			sendto(sfd, src.data, size, 0, (struct sockaddr*) &client, sizeof(struct sockaddr_in));

			return 0;
		}

                int UDPReceive(MemoryBuffer msg, unsigned int size=0){
                        if (size==0) size=msg.size;

                        recvfrom(sfd, msg.data, size, 0, (struct sockaddr*)&client, &sai_size);

                        return 0;
                }

		~NetworkTools(){
			close(sfd);
		}
};

