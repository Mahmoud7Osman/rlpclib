# CVenom      (Core is Under Development)
<pre>
Where The Simplicity Become Dangerous ...
         A True Cross-Platform Malware Development Kit
</pre>
<ul>
         <li><a href="#documentation">Documentation</a></li>
         <li><a href="https://www.youtube.com/c/TheDoctorMLT">Learn CVenom By Watching 4 Minutes Videos</a></li>
         <li><a href="https://t.me/MahmoudOsman0">Wanna Collaborate To CVenom ?</li>
</ul>
<h4>Right Now I Am Making The Networking And Remote Data Transfer API, After That, The Kit's Core will be ready to develop malwares.</h4>
<p>C/C++ Are Absolutely The Best Languages To Develop Malwares, Advanced, And Undetectable, Hardware I/O Access, As You Know, C/C++ Codes, API Calls, Library Calls, System Calls Differ Between Linux And Windows, So, <strong>That's Why We Created CVenom</strong></p>

<h3>Cross-Platform OOP Based Malware Development</h3>
Malware Development Made Easy With CVenom, All Resources Are Objects, You Access The Hard Disk By Using The DiskTools Class, `Disk.FileCorrupt("file.txt")` as an Example will corrupt the file.txt And So On...Read The <a href="#documentation">Documentation</a> To Learn How To Start Developing Malwares With CVenom Or Watch Short Videos <a href="https://www.youtube.com/c/TheDoctorMLT">Right There</a>. (Although, CVenom Don't Needs A Documentation, It's Easier Than Python!.)
<h1>Making Malwares With CVenom</h1>

<h1>Making Malwares Without CVenom</h1>

<p>As You See The Difference Is Big, Using CVenom You Write Lesser Code, Cross-Platform, Super Simple And Readable Code, With It's Own Compiler That Compile Your Malware To An Obfuscated And Stripped Binary!, But, Without Using CVenom, You're Forced To Learn The Full System API With Syscalls, For Windows And Linux, Because Every OS Has it's Own System API And Syscalls, Then You're Gonna Write A 300 Lines Of Complicated Code To Make A Simple Malware That's Gonna be So Buggy.</p>
<h3>That's Why CVenom Exists!</h3>
<h1 id="documentation">CVenom's Offical Documentation</h1>
<p>When Malware Development Become Available For Everyone, <em><b>No System Is Secure With The Existence Of CVenom</b></em></p>
<ul>
         <h2>All CVenom's APIs (Up To 50+ API For Malware Development)</h2>
         <li><a href="#smip">Malware Initialization Before Using CVenom's APIs</a></li>
         <li><a href="#disktoolsapi">DiskTools API</a></li>
         <li><a href="#evasiontoolsapi">EvasionTools API</a></li>
         <li><a href="#networktoolsapi">NetworkTools API</a></li>
         <li><a href="#uitoolsapi">UITools API</a></li>
         <li><a href="#redirectiontoolsapi">RedirectionTools API</a></li>
         <li><a href="#dominationtoolsapi">DominationTools API</a></li>
         <li><a href="#systemtoolsapi">SystemTools API</a></li>
         <li><a href="#keyboardtoolsapi">KeyboardTools API</a></li>
         <li><a href="#runtimetoolsapi">RuntimeTools API</a></li>
         <li><a href="#usbtoolsapi">USBTools API</a></li>
         <li><a href="#infectiontoolsapi">InfectionTools API</a></li>
</ul>
<h1>Initializing Malware</h1>
<pre>
#include <CVenom.h>
int main(MALWARE_ENTRY){
    cvinit(MALWARE_INIT);
         
      // Your Malware Source Code Goes Here
         
    cvexit(MALWARE_EXIT);
}
</pre>
