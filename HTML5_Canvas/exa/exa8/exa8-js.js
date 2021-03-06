// Variables`````````````````
var canvas = document.getElementById('myCanvas'),
	context = canvas.getContext('2d'),
	offscreencanvas = document.createElement('canvas'),
	offcontext = offscreencanvas.getContext('2d'),
	
	dragging = false,
	mousedown = {},
	rubberbandRect = {},
	drawingSurfaceImageData,
	
	BGimg = new Image();
	

// Functions`````````````````

// 之前实现的鼠标坐标比例转化函数
function windowToCanvas(canvas, x, y) {
    // 通过传入的在窗口中的鼠标坐标计算出x与y在canvas元素中应有的坐标并返回对象
	// 通用版，适用于所有情况。

    var bbox = canvas.getBoundingClientRect(),
		mystyle = window.getComputedStyle(canvas);
	
	x -= bbox.left;
	y -= bbox.top;
	
	x -= parseFloat(mystyle.borderLeftWidth);
	y -= parseFloat(mystyle.borderTopWidth);
	x -= parseFloat(mystyle.paddingLeft);
	y -= parseFloat(mystyle.paddingTop);
	
	x *= (parseFloat(mystyle.width) / canvas.width);
	y *= (parseFloat(mystyle.height) / canvas.height);
	
    return {
        x: x,
        y: y
    };
}

function saveDrawingSurface() {
    drawingSurfaceImageData = context.getImageData(0, 0,
        canvas.width, canvas.height);
}

function restoreDrawingSurface() {
    context.putImageData(drawingSurfaceImageData, 0, 0);
}

/*
function drawRect(x, y, width, height, lineWidth, fillColor, strokeColor) {
	var wid = context.lineWidth;
	context.fillStyle = fillColor;
	context.strokeStyle = strokeColor;
	context.lineWidth = lineWidth;
	
	context.strokeRect(x, y, width, height);
	context.fillRect(x, y, width, height);
	context.lineWidth = wid;
}
*/

function updateRubberbandRectangle(loc) {
    rubberbandRect.width = Math.abs(loc.x - mousedown.x);
    rubberbandRect.height = Math.abs(loc.y - mousedown.y);

    if (loc.x > mousedown.x) {
		rubberbandRect.left = mousedown.x;
	} else {
		rubberbandRect.left = loc.x;
	}

    if (loc.y > mousedown.y) {
		rubberbandRect.top = mousedown.y;
	} else {
		rubberbandRect.top = loc.y;
	}
}

function drawRubberbandShape(loc) {
	//drawImage(offcontext, offscreencanvas, loc);
	//drawRect(rubberbandRect.left, rubberbandRect.top, rubberbandRect.width, rubberbandRect.height, context.lineWidth, context.fillStyle, context.strokeStyle);
	var imageData,
		imageDataCopy,
		numPiexel,
		i,
		wid = Math.abs(rubberbandRect.left - loc.x),
		hei = Math.abs(rubberbandRect.top - loc.y);
	
	imageData = context.getImageData(rubberbandRect.left, rubberbandRect.top, wid, hei);
	imageDataCopy = context.createImageData(imageData);
	
	numPiexel = imageData.data.length;
	for (i = 0; i < numPiexel; i += 4) {
		imageDataCopy.data[i] = imageData.data[i];
		imageDataCopy.data[i + 1] = imageData.data[i + 1];
		imageDataCopy.data[i + 2] = imageData.data[i + 2];
		imageDataCopy.data[i + 3] = imageData.data[i + 3] / 2;
		
	}
	context.clearRect(0, 0, canvas.width, canvas.height);
	context.putImageData(imageDataCopy, rubberbandRect.left, rubberbandRect.top);
	
	context.save();

	context.rect(rubberbandRect.left, rubberbandRect.top, loc.x - rubberbandRect.left, loc.y - rubberbandRect.top);
	context.clip();
	context.drawImage(BGimg, 0, 0, canvas.width, canvas.height);
	
	context.restore();
}

function updateRubberband(loc) {
    updateRubberbandRectangle(loc);
    drawRubberbandShape(loc);
}

function drawImage(ctx, cvs, loc) {
	ctx.drawImage(canvas, 0, 0, canvas.width, canvas.height);
	context.clearRect(0, 0, canvas.width, canvas.height);
	context.drawImage(cvs, rubberbandRect.left, rubberbandRect.top, loc.x - rubberbandRect.left, loc.y - rubberbandRect.top, 0, 0, cvs.width, cvs.height);
	
}

// Handlers``````````````````

/*
scaleSlider.onchange = function(e) {
	scale = e.target.value,
	scaleText = parseFloat(scale).toFixed(2);
	scaleOutput.innerHTML = scaleText;
	drawImage(offcontext, offscreencanvas);
}
*/

canvas.onmousedown = function (e) {
    var loc = windowToCanvas(canvas, e.clientX, e.clientY);

    e.preventDefault(); // prevent cursor change

    mousedown.x = loc.x;
    mousedown.y = loc.y;
	dragging = true;
	saveDrawingSurface();
};

canvas.onmousemove = function (e) {
    var loc;

    if (dragging) {
		e.preventDefault(); // prevent selections

        loc = windowToCanvas(canvas, e.clientX, e.clientY);
		restoreDrawingSurface();
        updateRubberband(loc); // -- 请随鼠标移动显示当前的rubber band

		if ((loc.x + 2) >= (canvas.width) || (loc.y + 2) >= (canvas.height) || (loc.x - 2) <= 0 || (loc.y - 2) <= 0) {
			restoreDrawingSurface();
			updateRubberband(loc);
			dragging = false;
		}
    }
};

canvas.onmouseup = function (e) {
    var loc = windowToCanvas(canvas, e.clientX, e.clientY);
	restoreDrawingSurface();
    updateRubberband(loc);
	//drawImage(offcontext, offscreencanvas, loc);
	dragging = false;
};

// Initiation```````````````

offscreencanvas.width = 600;
offscreencanvas.height = 400;
//jpgimg.src = 'static/img/blue_flower.jpg';
BGimg.src = 'static/img/November.jpg';
BGimg.onload = function () {
	context.drawImage(BGimg, 0, 0, canvas.width, canvas.height);
	offcontext.drawImage(canvas, 0, 0);
};