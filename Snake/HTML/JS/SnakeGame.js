var c = document.getElementById("GameWindow");
var cxt = c.getContext("2d");
cxt.fillStyle = "#fff";
cxt.fillRect(0, 0, 8, 8 * 8); //Left
cxt.fillRect(0, 0, 8 * 15, 8); //Top
cxt.fillRect(8 * 14, 0, 8, 8 * 8); //Right
cxt.fillRect(0, 8 * 7, 8 * 15, 8); //Button