class NetworkTools{
	private:
		int   sfd;
		int   cfd;
		int  port;
		int rcv=1;
		int i_tmp;

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
		void UDPStart(){
			return;
		}
		void UDPSend(){
			return;
		}
		void UDPReceive(){
			return;
		}
		~NetworkTools(){
			close(sfd);
		}
};

