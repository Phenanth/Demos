// ..................变量声明...................


var canvas = document.getElementById('canvas'),
	context = canvas.getContext('2d'),
	offscreencanvas = document.createElement('canvas'),
	offcontext = offscreencanvas.getContext('2d'),
	
	sliderValue = document.getElementById('sliderValue'),
	scaleSlider = document.getElementById('scaleSlider'),
	scaleType = document.getElementById('scaleTypeRadios'),
	resetButton = document.getElementById('resetButton'),
	
	drawingSurfaceImageData,
	mousedown = {},
	rubberbandRect = {},
	loc = {},
	
	type = 'topleft',
	scale = 1.0,
	dragging = false,
	
	imageData,
	img = new Image();
	

// ..................函数定义...................

// .....借用已有函数.....

function saveDrawingSurface() {
    drawingSurfaceImageData = context.getImageData(0, 0,
        canvas.width,
        canvas.height);
}

function restoreDrawingSurface() {
    context.putImageData(drawingSurfaceImageData, 0, 0);
}


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
	
	x *= (canvas.width / parseFloat(mystyle.width)); // canvas.width实际上是drawing surface的大小
	y *= (canvas.height / parseFloat(mystyle.height)); // canvas.height实际上是drawing surface的大小
	
    return {
        x: x,
        y: y
    };
}

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
}

function updateRubberband(loc) {
    updateRubberbandRectangle(loc);
    drawRubberbandShape(loc);
}

// .....自定义函数.....

// 通过调整缩放参数进行绘制
function drawImage(alignType) {
	
	var center = {},
		value = {};
	
	context.clearRect(0, 0, canvas.width, canvas.height);
	
	// 通过绘制中心不同改变绘制参数
	value.sx = 0;
	value.sy = 0;
	value.swid = img.width;
	value.shei = img.height;
	value.wid = img.width * scale;
	value.hei = img.height * scale;
	
	if (alignType === 'topleft') {
		center.x = value.wid / 2;
		center.y = value.hei / 2;
	} else {
		center.x = canvas.width / 2;
		center.y = canvas.height / 2;
		
	}
	
	value.x = center.x - (value.wid / 2);
	value.y = center.y - (value.hei / 2);
	
	context.clearRect(0, 0, canvas.width, canvas.height);
	context.drawImage(img, value.sx, value.sy, value.swid, value.shei, value.x, value.y, value.wid, value.hei);

	
	if (type === 'semi-trans' || type === 'emboss') {
		drawScaleOutput(value);
	}
	
}

// 像素处理
function drawScaleOutput(value) {
	
	var imageData,
		imageDataCopy,
		numPiexel,
		i;
		
	context.save();
	imageData = context.getImageData(rubberbandRect.left, rubberbandRect.top, rubberbandRect.width, rubberbandRect.height);
	imageDataCopy = context.createImageData(imageData);

	length = imageData.data.length;
	width = imageData.width;
	for (i = 0; i < length; i += 4) {
		imageDataCopy.data[i] = imageData.data[i];
		imageDataCopy.data[i + 1] = imageData.data[i + 1];
		imageDataCopy.data[i + 2] = imageData.data[i + 2];
		imageDataCopy.data[i + 3] = imageData.data[i + 3] / 2;

	}
	if (type === 'emboss') {
		for (i = 0; i < length; i += 4) {
			imageDataCopy.data[i] = imageData.data[i];
			imageDataCopy.data[i + 1] = imageData.data[i + 1];
			imageDataCopy.data[i + 2] = imageData.data[i + 2];
			imageDataCopy.data[i + 3] = imageData.data[i + 3];

		}
		for (i = 0; i < length; i += 1) {
			
			if (i <= (length - 4 * width)) {
				if ((i + 1) % 4 !== 0) {
					
					if ((i + 4) % (width * 4) === 0) {
						imageDataCopy.data[i] = imageDataCopy.data[i - 4];
						imageDataCopy.data[i + 1] = imageDataCopy.data[i - 3];
						imageDataCopy.data[i + 2] = imageDataCopy.data[i - 2];
						imageDataCopy.data[i + 3] = imageDataCopy.data[i - 1];
						i += 4;
					} else {
						imageDataCopy.data[i] = 128 + imageDataCopy.data[i] - imageDataCopy.data[i + 4];
					}
				}
			} else {
				if ((i + 1) % 4 !== 0) {
					imageDataCopy.data[i] = imageDataCopy.data[i - width * 4];
				}
			}
			
		}
	}
	context.clearRect(0, 0, canvas.width, canvas.height);
	context.putImageData(imageDataCopy, rubberbandRect.left, rubberbandRect.top);
	context.restore();
	
}

// 橡皮筋交互用 offscreen 绘制
function drawOffscreen(ctx, cvs, loc) {
	
	ctx.drawImage(canvas, 0, 0, canvas.width, canvas.height);
	context.clearRect(0, 0, canvas.width, canvas.height);
	context.drawImage(cvs, rubberbandRect.left, rubberbandRect.top, rubberbandRect.width, rubberbandRect.height, 0, 0, cvs.width, cvs.height);
	
}


// .....事件响应：控件.....


scaleSlider.onchange = function (e) {
	sliderValue.innerHTML = scaleSlider.value.toString();
	scale = scaleSlider.value;
	drawImage(type);
};

scaleType.onchange = function (e) {
	
	type = e.target.value;
	rubberbandRect = {};
	drawImage(type);
	
};

resetButton.onclick = function (e) {
	
	var scaleRadio = document.getElementsByName('scaleType');
	scaleRadio[0].checked = true;
	
	type = 'topleft';
	scaleSlider.value = '1.0';
	sliderValue.innerHTML = '1.00';
	rubberbandRect = {};
	
	context.clearRect(0, 0, canvas.width, canvas.height);
	context.drawImage(img, 0, 0);
	offcontext.drawImage(canvas, 0, 0);
	
};

canvas.onmousedown = function (e) {
	
    loc = windowToCanvas(canvas, e.clientX, e.clientY);
	
	if (type === 'rubberband' || type === 'semi-trans' || type === 'emboss') {
	
		e.preventDefault(); // prevent cursor change
		mousedown.x = loc.x;
		mousedown.y = loc.y;
		dragging = true;
		saveDrawingSurface();
		
	}
	
};

canvas.onmousemove = function (e) {

    if (dragging && (type === 'rubberband' || type === 'semi-trans' || type === 'emboss')) {
		
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
	
    loc = windowToCanvas(canvas, e.clientX, e.clientY);
	
	if (type === 'rubberband' || type === 'semi-trans' || type === 'emboss') {
		
		restoreDrawingSurface();
		updateRubberband(loc);
		if (type === 'semi-trans' || type === 'emboss') {
			drawImage(type);
		}
		if (type === 'rubberband') {
			drawOffscreen(offcontext, offscreencanvas, loc);
		}
		dragging = false;
		
	}
	
};


// ..................初始化...................


offscreencanvas.width = 600;
offscreencanvas.height = 400;
rubberbandRect.x = 0;
rubberbandRect.y = 0;
rubberbandRect.width = canvas.width;
rubberbandRect.height = canvas.height;

img.src = "blue_flower.jpg";
img.onload = function (e) {
	context.drawImage(img, 0, 0);
	offcontext.drawImage(canvas, 0, 0);
};
