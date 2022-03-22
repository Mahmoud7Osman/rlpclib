# CVenom      (Core is Under Development)
<pre>
Where The Simplicity Become Dangerous ...
         A True Cross-Platform Malware Development Kit
</pre>
<ul>
         <li><a href="#documentation">Documentation</a></li>
         <li><a href="https://www.youtube.com/c/TheDoctorMLT">Learn CVenom By Watching 4 Minutes Videos</a></li>
         <li><a href="https://t.me/MahmoudOsman0">Wanna Collaborate To CVenom To Create A New API For Malware Development (For MacOS, Android Or IOS)?</li>
</ul>
<h4>Right Now I Am Making The Networking And Remote Data Transfer API, After That, The Kit's Core will be ready to develop malwares.</h4>
<p>C/C++ Are Absolutely The Best Languages To Develop Malwares, Advanced, And Undetectable, Hardware I/O Access, As You Know, C/C++ Codes, API Calls, Library Calls, System Calls Differ Between Linux And Windows, So, <strong>That's Why We Created CVenom</strong></p>

<h1>Before Everything</h1>
We've All Heard About, Or Even Used Software Development Kits, Like JDK (Java Development Kit), QT (Desktop Apps Development Kit), [...], But, Have You Ever Heard About A Malware Development Kit?! Firstly You Should Understand That You Can't Code a Malware Using Python, Java, Golang, C#, [...], There Is a Huge Amount Of Python Modules Used in Hacking, Like The Keylogger Module, Scapy, [...], But Unfortunately, All Of Those Modules Will Not Help in malware Development, Even if you compiled the python code (Including Java, C#, Go...)
<br><br>
<h3>When I Said Malware, I Didn't Meant A Simple Reverse Shell That You Can Code it with 3 Lines of Python Code, I Meant Malware With Hardware Access, Low-Level Kernel-Level And Hardware-Level Input/Output Control And Manipulation API, Evading in The Dark Corner Of the Operating System, Working Far Away From User-Level API, High-Speed Data Processing Encryption And Decryption, Intelligent Execution-Flow Redirection (Supports Redirecting Execution Into the Stack), Custom Evasion Functionality, Hardware Bombing, Intelligent Process Injector, Customized Compilation Process And A Lot More[...], All Of Those Stuffs, Can Be Used Under The OOP Concept, As Follow</h3>

````

#include <CVenom.h>
         
#include <RuntimeTools.h>
#include <EvasionTools.h>

int main(MALWARE_ENTRY){


         cvinit(MALWARE_INIT);                                   // Initializing CVenom, Should Be Always Inserted in The Start of the Main Function With MALWARE_INIT

         RuntimeTools      Runner;
         EvasionTools      Evador;
         
         Runner.Background();                                  // Used To Move Execution Into Background;
         Evador.HandleAllSignals( Evador.ChangePID );          // Used To Change Current Procces PID If Any Signal Was Invoked By The User Or The Kernel
         Evador.MoveIntoMemory();                              // Used To Move The Malware From The Hard Disk To The RAM (Used To Create Fileless Malwares).
         Runner.Sleep(5);                                      // Pause The Malware For 5 Seconds
         Evador.MoveBackToDisk();                              // Move The Malware From Memory Back To Disk (Not Required Because The cvexit() Function is going to Check if the malware is On the disk Or Not, Then Move It Back From Memory Into Disk.
         
         cvexit(MALWARE_EXIT);                                            // Freeing CVenom's Memory, Should Be Always Inserted in the end of the main function with the exit code.


}
````
<br><br>
<p>C/C++ Are Absolutely The Best Languages To Develop Malwares, Advanced, And Undetectable, Scary Hardware And L2 I/O Access, As You Know, C/C++ Codes, API Calls, Library Calls, System Calls Differ Between Linux And Windows, So, <strong>Welcome To CVenom</strong>.</p>
<h1>Introducing, CVenom</h1>
<h3>Cross-Platform OOP Based Malware Development</h3>
Malware Development Made Easy With CVenom, All Resources Are Objects, You Access The Hard Disk By Using The DiskTools Class, `Disk.FileCorrupt("file.txt")` as an Example will corrupt the file.txt And So On...Read The <a href="#documentation">Documentation</a> To Learn How To Start Developing Malwares With CVenom Or Watch Short Vidoes <a href="https://www.youtube.com/c/TheDoctorMLT">Right There</a>.
<h1>Making Malwares With CVenom</h1>
<img src="/Images/CVenom.png">
<h1>Making Malwares Without CVenom</h1>

<p>As You See The Difference Is Big, Using CVenom You Write Lesser Code, Cross-Platform, Super Simple And Readable Code, With It's Own Compiler That Compile Your Malware To An Obfuscated And Stripped Binary!, But, Without Using CVenom, You're Forced To Learn The Full System API With Syscalls, For Windows And Linux, Because Every OS Has it's Own System API And Syscalls, Then You're Gonna Write A 300 Lines Of Complicated Code To Make A Simple Malware (Maybe It is Gonna Be Buggy Haha)</p>
<h3>That's Why CVenom Exists!</h3>
<h1 id="documentation">CVenom's Offical Documentation</h1>
