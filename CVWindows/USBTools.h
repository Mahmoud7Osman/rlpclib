class USBTools{
	private:
		BOOL Fe(LPCTSTR szPath){
                        DWORD dwAttrib = GetFileAttributes(szPath);

                        return(dwAttrib != INVALID_FILE_ATTRIBUTES &&
                        !(dwAttrib & FILE_ATTRIBUTE_DIRECTORY));

                }
	public:
		char* GetDeviceContaining(const char* name){
			short ua=0;

			static 		char dev[501];
			static		char usb[4+PAMAX];

			memset(usb, 0x00, 4+PAMAX);
			memset(dev, 0x00, 501);

			GetLogicalDriveStrings(500, dev);


			for(int i=0; i<=500; i++){
				if (*(dev+i) == 0x00){
					if (*(dev+i+1) == 0x00)
						break;
					strcat(usb, name);
					if (Fe(usb) == FILE_EXIST){
						*(usb+3)=0x00;
						return usb;
					}
					memset(usb, 0x00, PAMAX+4);
					ua=0;
					continue;
				}
				if (ua==4)ua==0;

				usb[ua++] = *(dev+i);
			}
			return NULL;

		}
};
