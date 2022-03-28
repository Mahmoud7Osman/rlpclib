# CVenom      (Core is Under Development)
<pre>
Where The Simplicity Become Dangerous ...
         A True Cross-Platform Malware Development Kit
</pre>
<ul>
         <li><a href="/Setup/README.md">Installation</a></li>
         <li><a href="#documentation">Documentation</a></li>
         <li><a href="https://www.youtube.com/c/TheDoctorMLT">Learn CVenom By Watching 4 Minutes Videos</a></li>
         <li><a href="https://t.me/MahmoudOsman0">Wanna Collaborate To CVenom ?</li>
</ul>
<h4>Right Now I Am Making The Networking And Remote Data Transfer API, After That, The Kit's Core will be ready to develop malwares.</h4>
<p>C/C++ Are Absolutely The Best Languages To Develop Malwares, Advanced, And Undetectable, Hardware I/O Access, As You Know, C/C++ Codes, API Calls, Library Calls, System Calls Differ Between Linux And Windows, So, <strong>That's Why We Created CVenom</strong></p>

<h3>Cross-Platform OOP Based Malware Development</h3>
Malware Development Made Easy With CVenom, All Resources Are Objects, You Access The Hard Disk By Using The DiskTools Class, `Disk.FileCorrupt("file.txt")` as an Example will corrupt the file.txt And So On...Read The <a href="#documentation">Documentation</a> To Learn How To Start Developing Malwares With CVenom Or Watch Short Videos <a href="https://www.youtube.com/c/TheDoctorMLT">Right There</a>. (Although, CVenom Don't Needs A Documentation, It's Easier Than Python!.)

<h1 id="documentation">CVenom's Official Documentation</h1>
<p>When Malware Development Become Available For Everyone, <em><b>No System Is Secure With The Existence Of CVenom</b></em></p>
<ul>
         <li><a href="#smip">Malware Initialization And Compilation</a></li>
         <li><a href="#current">Malware Information Data Structure</a></li>
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
<h1 id="smip">Initializing And Compiling A Malware</h1>

<pre>#include &ltCVenom.h&gt

int main(MALWARE_ENTRY){

    cvinit(MALWARE_INIT);  // Initialize Malware Data.
         
         
    cvexit(MALWARE_EXIT);  // Free Malware Data Then Exit.

}</pre>
<p>This Is How You Initialize A Malware For Further Malware Development</p>
<p><strong>Info: </strong>Please Always Use <strong>cvexit(MALWARE_EXIT)</strong> When You Want To Exit, Please Don't Use <strong>return</strong> Or <strong>exit()</strong></p>
<h3>Compiling Malware</h3>
<p>Using CVenom's Compiler <strong>cvg++</strong> To Compile Malwares, This Compiler Will Automate Malware Cross-Compilation For You With Binary Strip And The Like </p>
<h5>Compiling Malware For Linux</h5>
<pre>$ cvg++ malware.cpp target=linux</pre>
<h5>Compiling Malware For Windows</h5>
<pre>$ cvg++ malware.cpp target=windows</pre>
<h1 id="current">Getting/Setting Malware Information</h1>
<p>Informations Like Malware Path, Size, Privileges, Fake Service And Fake Description About The Malware.</p>
<ul>
         <li><a href="#ctsize">Getting Malware File Size</a></li>
         <li><a href="#ctpath">Getting Malware File Path</a></li>
         <li><a href="#ctpriv">Getting Malware Current Privileges</a></li>
         <li><a href="#ctserv">Getting And Setting Malware Fake Service Name</a></li>
         <li><a href="#ctdesc">Getting And Setting Malware Fake Description</a></li>
</ul>
<h2 id="ctsize">Getting Malware File Size</h2>
<p>Using The <strong>Current.size</strong> or <strong>MALWARE->size</strong></p>
<pre>#include &ltCVenom.h&gt
int main(MAlWARE_ENTRY){
         cvinit(MALWARE_INIT);
         
         printf("%d\n", Current.size);    // This Is Gonna Print The Current Malware File Size
         
         cvexit(MALWARE_EXIT);
}
</pre>
