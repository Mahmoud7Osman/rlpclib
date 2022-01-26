#!/bin/bash
black="\033[0;30m"        # Black
red="\033[0;91m"          # Red
green="\033[0;92m"        # Green
yellow="\033[0;93m"       # Yellow
blue="\033[0;94m"         # Blue
purple="\033[0;95m"       # Purple
cyan="\033[0;36m"         # Cyan
white="\033[0;97m"        # White

# Blinking

blblack="\033[5;30m"        # Black
blred="\033[5;91m"          # Red
blgreen="\033[5;32m"        # Green
blyellow="\033[5;93m"       # Yellow
blblue="\033[5;34m"         # Blue
blpurple="\033[5;95m"       # Purple
blcyan="\033[5;36m"         # Cyan
blwhite="\033[5;97m"        # White

# Bold
BBlack="\033[1;30m"       # Black
BRed="\033[1;31m"         # Red
BGreen="\033[1;32m"       # Green
BYellow="\033[1;33m"      # Yellow
BBlue="\033[1;34m"        # Blue
BPurple="\033[1;35m"      # Purple
BCyan="\033[1;36m"        # Cyan
BWhite="\033[1;37m"       # White

sleep 0.5
echo
printf "$BBlue[+]$white Welcome To CVenom, The Number 1 Malware Development Kit, This Might Be Your Best Decision in This Year !\n"
if [ "$(whoami)" != "root" ];then printf "$BRed[-]$white This Script Must Run as Root in Order to install the library in your filesystem !\n"; exit 1; fi
printf "This Installation Script is Under Development, Include The Headers Using The \" Like #include \"CVenom.hpp\" Or \"../CVenom.hpp\"\n Have a Nice Experience With CVenom !\n"
# Start The Real Legit Setup Without Errors.
# printf "$BBlue[+]$white Done, You Can Start Developing Malwares, Visit ... For Full Documentation, See Examples/ For Example Malwares, Take This Course At ... In Order To Master The Malware Development With CVenom, The Future Of Malware Development\n"
