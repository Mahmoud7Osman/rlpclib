let togglebackground  = document.getElementById("bg-toggle");
let background        = document.getElementById("background");
let backgroundvideo   = document.getElementById("bg-video");
let changebackground  = document.getElementById("bg-change");

let connectionbutton  = document.getElementById("connectionbtn");
let connectionsetting = document.getElementById("connection");
let connect           = document.getElementById("connect");
let cntstat           = document.getElementById("cntstat");


let term              = document.querySelector("#terminal");
let terminal          = document.querySelector("#terminaldata");
let terminalbtn       = document.getElementById("terminalbtn");
let terminalinput     = document.getElementById("inputdata");

let backgrounds = ["1.mp4", "2.mp4", "3.mp4", "4.mp4", "5.mp4", "6.mp4", "7.mp4", "8.mp4"];

let i = 1;



terminalbtn.onclick = function(){
    if (term.style.display == 'none'){
        term.style.display = 'block';
        return;
    }
    term.style.display = 'none';
}

connect.onclick = function(){
    cntstat.style.color = "#00ff00";
    cntstat.innerHTML   = "Connected";
}
disconnect.onclick = function(){
    cntstat.style.color = "#ff0000";
    cntstat.innerHTML   = "Not Connected";
}
togglebackground.onclick = function(){

    if (background.paused){
        background.play();
        return;
    }

    background.pause();
}

changebackground.onclick = function(){
        backgroundvideo.setAttribute("src", "/backgrounds/"+backgrounds[i]);

        background.load();
        background.play();
    
        if (i==7){
            i=0;
            return;
        }

        i++;
}
connectionbutton.onclick = function(){
        if (connectionsetting.style.display == 'block'){ 
            connectionsetting.style.display = 'none';
            return;
        }
        connectionsetting.style.display = 'block';
}






Draggable(document.getElementById("connection"));
Draggable(document.getElementById("terminal"));



function cmdexec(){
    if (inputdata.value == "clear"){
        terminal.innerHTML = '';
        inputdata.value = '';
        return;
    }

    terminal.innerHTML += inputdata.value+"<br>";
    inputdata.value = '';
    terminal.scrollTop = terminal.scrollHeight;
}

function Draggable(elmnt) {
  var pos1 = 0, pos2 = 0, pos3 = 0, pos4 = 0;
  if (document.getElementById(elmnt.id + "topbar")) {
    // if present, the header is where you move the DIV from:
    document.getElementById(elmnt.id + "topbar").onmousedown = dragMouseDown;
  } else {
    // otherwise, move the DIV from anywhere inside the DIV:
    elmnt.onmousedown = dragMouseDown;
  }

  function dragMouseDown(e) {
    e = e || window.event;
    e.preventDefault();
    // get the mouse cursor position at startup:
    pos3 = e.clientX;
    pos4 = e.clientY;
    document.onmouseup = closeDragElement;
    // call a function whenever the cursor moves:
    document.onmousemove = elementDrag;
  }

  function elementDrag(e) {
    e = e || window.event;
    e.preventDefault();
    // calculate the new cursor position:
    pos1 = pos3 - e.clientX;
    pos2 = pos4 - e.clientY;
    pos3 = e.clientX;
    pos4 = e.clientY;
    // set the element's new position:
    elmnt.style.top = (elmnt.offsetTop - pos2) + "px";
    elmnt.style.left = (elmnt.offsetLeft - pos1) + "px";
  }

  function closeDragElement() {
    // stop moving when mouse button is released:
    document.onmouseup = null;
    document.onmousemove = null;
  }
}