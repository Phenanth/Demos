var canvas = document.getElementById('myCanvas'),
	ctx = canvas.getContext('2d'),
	strokeSelectSheet = document.getElementById('strokeSelectSheet'),
	guidewireCheckBox = document.getElementById('guidewireCheckBox'),
	eraseAllButton = document.getElementById('eraseAllButton');

var dragging = false,
	guidewires;


// ```````````````````````````````

function windowToCanavs(x, y) {
	var bbox = canvas.getBoundingClientRect();
	return {
		x: x - bbox.left * (canvas.width / bbox.width) - 20,
		y: y - bbox.top * (canvas.height / bbox.height) - 20
	};
}

function drawBackground() {
	var VERTICAL_LINE_SPACING = 12,
		HORIZONTAL_LINE_SPACING = 12;
		
    i = ctx.canvas.height;

    ctx.clearRect(20, 20, canvas.width, canvas.height); 
    ctx.strokeStyle = 'lightgray';
    ctx.lineWidth = 0.5;

    // 在画布上从下往上每隔12px画一条线，留出上方48px的空白
    while (i > 20) {
        ctx.beginPath();
        ctx.moveTo(0, i);
        ctx.lineTo(ctx.canvas.width, i);
        ctx.stroke();
        i -= VERTICAL_LINE_SPACING;
    }
	i = ctx.canvas.width;
	while(i > 0) {
		ctx.beginPath();
		ctx.moveTo(i, 20);
		ctx.lineTo(i, ctx.canvas.height);
		ctx.stroke();
		i -= HORIZONTAL_LINE_SPACING;
	}
	
}

function drawRubberband(loc) {
	
}

function saveDrawingSurface() {
	
}

function restoreDrawingSurface() {
	
}



// ```````````````````````````````

canvas.onmousedown = function(e) {
	var loc = windowToCanavs(e.clientX, e.clientY);
	mousedown.x = loc.x;
	mousedown.y = loc.y;
	dragging = true;
	saveDrawingSurface();
}

canvas.onmousemove = function(e) {
	if (dragging) {
		var loc = windowToCanavs(e.clientX, e.clientY);
		restoreDrawingSurface();
		drawRubberband(loc);
	}
}

canvas.onmouseup = function(e) {
	loc = windowToCanavs(e.clientX, e.clientY);
	restoreDrawingSurface();
	drawRubberband(loc);
	dragging = false;
}

strokeSelectSheet.onchange = function(e) {
	ctx.strokeStyle = strokeSelectSheet.value;
}

eraseAllButton.onclick = function(e) {
	ctx.clearRect(0, 0, canvas.width, canvas.height);
	drawBackground();
}


// ```````````````````````````````

ctx.strokeStyle = strokeSelectSheet.value;
guidewires = guidewireCheckBox.value;
drawBackground();