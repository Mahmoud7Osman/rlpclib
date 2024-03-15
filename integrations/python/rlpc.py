import ctypes

class rlpc:
    def __init__(self, dll_path, functions):
        try:
            self.dll = ctypes.CDLL(dll_path)
        except:
            print(f"Fatal Error: Cannot Open {self.dll_path}")
            exit(3)

        if type(functions) is not type({}):
            print(f"Fatal Error: No Functions To Serve")
            exit(4)

        self.functions = functions
        self.initBridge = self.dll.init_bridge
        self.Call = self.dll.function_call
        self.Listen = self.dll.fcall_receiver
        self.Return = self.dll.fcall_return
        self.closeBridge = self.dll.close_bridge

        self.initBridge.restype = ctypes.c_void_p
        self.initBridge.argtypes = [ctypes.c_char_p, ctypes.c_int, ctypes.c_char_p, ctypes.c_int]

        self.Call.restype = ctypes.c_char_p
        self.Call.argtypes = [ctypes.c_void_p, ctypes.c_char_p, ctypes.c_char_p]

        self.Listen.restype = ctypes.c_char_p
        self.Listen.argtypes = [ctypes.c_void_p]

        self.Return.argtypes = [ctypes.c_void_p, ctypes.c_void_p, ctypes.c_int32]

        self.closeBridge.argtypes = [ctypes.c_void_p]
    def OpenBridge(self, ip, port, ipe, porte):
        ip = ctypes.c_char_p(ip.encode("utf-8"))
        ipe = ctypes.c_char_p(ipe.encode("utf-8"))

        self.bridge = self.initBridge(ip, port, ipe, porte)

    def Listen4Call(self):
        return self.Listen(self.bridge).decode("utf-8")
    
    def ReturnValue(self, value):
        self.Return(self.bridge, ctypes.c_char_p(value.encode("ascii")), ctypes.c_int32(len(value)))

    def ServerStart(self):
        while True:
            functionCall = self.Listen(self.bridge).decode("ascii")
            self.ReturnValue(str(eval(functionCall)))

    def CallFunction(self, fname, args):
        return self.Call(self.bridge, ctypes.c_char_p(fname.encode("ascii")), ctypes.c_char_p(args.encode("ascii"))).decode("ascii", errors="ignore")

    def Close(self):
        self.Close(self.bridge)
