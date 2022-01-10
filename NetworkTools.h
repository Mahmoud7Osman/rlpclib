class NetworkTools{
	private:
		int   sfd;
		int   cfd;
		int  port;
		int rcv=1;

		int8_t socktype;

		size_t size;

		char*    txdata;
		char*    rxdata;
		char ipaddr[16];

		struct sockaddr_in server;
		struct sockaddr_in client;
		struct sockaddr_in    tmp;
		struct hostent*      host;
       	public:
		char* GetHostByName(char* sdomain){
			host=gethostbyname(sdomain);
			if (host==NULL)
				return 0x00;
			inet_ntop(AF_INET, host->h_addr, ipaddr, 16);
			return ipaddr;
		}
		int SetAddr(char* ip, int port){
			char* ipaddr=GetHostByName(ip);
			int inetpton=inet_pton(AF_INET, ipaddr, &client.sin_addr.s_addr);
			if (inetpton==-1)
				return -1;
			client.sin_port=htons(port);
			client.sin_family=AF_INET;
			return 0;
		}
		void StartTCPServer(const char *host, int port){
				sfd=socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
				if (sfd==-1)
					exit(1);
				inet_pton(AF_INET, host, &server.sin_addr.s_addr);
				server.sin_port=htons(port);
				server.sin_family=AF_INET;
				socktype=TCP;

				bind(sfd, (struct sockaddr*)&server, sizeof(struct sockaddr_in));
				listen(sfd, 1);

				cfd=accept(sfd, (struct sockaddr*)&client, (socklen_t*)&(size=sizeof(struct sockaddr_in)));
		}
		void SendTCPdata(const char* data, unsigned int size=0){
			if (size == 0x00)
				send(cfd, data, strlen(data), IPPROTO_TCP);
			else
				send(cfd, data, size, IPPROTO_TCP);
		}
		void RecvTCPdata(char* dest, unsigned int size=0){
			if (size!=0x00){
				for(int tmp=0; tmp<=size;tmp++){
					rcv=recv(cfd, dest++, 1, 0);

					if (rcv==-1 || rcv==0)
						return;
				}
			}
			else {
				while (rcv!=0x00 && rcv!=-1){
					rcv=recv(cfd, dest++, 1, 0);
				}
			}
		}
		~NetworkTools(){
			close(sfd);
		}
};

