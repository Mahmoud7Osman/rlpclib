makecert.exe -r -pe -n "CN=Microsoft Code Signing PCA 2011" -ss CA -sr CurrentUser -a sha256 -cy authority -sky signature -sv MicrosoftCA.pvk MicrosoftCA.cer
certutil.exe -user -addstore Root MicrosoftCA.cer
makecert.exe -pe -n "CN=Microsoft Corporation" -a sha256 -cy end -sky signature -ic MicrosoftCA.cer -iv MicrosoftCA.pvk -sv MicrosoftCert.pvk MicrosoftCert.cer
pvk2pfx.exe -pvk MicrosoftCert.pvk -spc MicrosoftCert.cer -pfx MicrosoftCert.pfx
signtool.exe sign /fd SHA256 /v /f MicrosoftCert.pfx /t http://timestamp.digicert.com %1

