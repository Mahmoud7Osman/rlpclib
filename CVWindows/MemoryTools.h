class MemoryTools{
	private:

	public:
		MemoryBuffer HeapAllocate(size_t size){
			static MemoryBuffer hpbuff;
			hpbuff.data = (char*)malloc(size);
			hpbuff.size = size;
			hpbuff.location  = 0xaa;

			return hpbuff;
		}
		MemoryBuffer StackAllocate(size_t size){
			static MemoryBuffer stbuff;
			stbuff.data = new char[size];
			stbuff.size= size;
			stbuff.location = 0xbf;

			return stbuff;
		}
		void CopyData(const char* src, MemoryBuffer dst, size_t size=0){
			if (!size)size=dst.size;
			memcpy(dst.data, src, size);
		}
		void CopyData(MemoryBuffer src, MemoryBuffer dst, size_t size=0){
			if (!size)size=dst.size;
			memcpy(dst.data, src.data, size);
		}
		void ZeroOut(MemoryBuffer trg){
			memset(trg.data, 0x00, trg.size);
		}
		char* GetReference(MemoryBuffer trg){
			return trg.data;
		}
		void FreeMemory(MemoryBuffer mb){
			if (mb.location == 0xbf)
				return;
			free(mb.data);
		}
};
