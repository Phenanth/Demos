var canvas = document.getElementById('canvas'),
    context = canvas.getContext('2d'),
	conCanvas = document.getElementById('conCanvas'),
	conContext = conCanvas.getContext('2d'),
// 修改：添加变量	
	patternBoutton1 = document.getElementById('pb1'),
	patternBoutton2 = document.getElementById('pb2'),
	patternBoutton3 = document.getElementById('pb3'),
	patternBoutton4 = document.getElementById('pb4'),
	patternBoutton5 = document.getElementById('pb5'),
	patternBoutton6 = document.getElementById('pb6'),
	patternBoutton7 = document.getElementById('pb7'),
	patternBoutton8 = document.getElementById('pb8'),
	patternBoutton9 = document.getElementById('pb9'),
	
    eraseAllButton = document.getElementById('eraseAllButton'),
    strokeStyleSelect = document.getElementById('strokeStyleSelect'),
	fillStyleSelect = document.getElementById('fillStyleSelect'),
    guidewireCheckbox = document.getElementById('guidewireCheckbox'),
    drawingSurfaceImageData,
	lineWid = document.getElementById('lineWidth'),
	
    mousedown = {},
    rubberbandRect = {},
	patternDraw = {},
    dragging = false,
    guidewires = guidewireCheckbox.checked;

// Functions.........................................................

// 之前实现的鼠标坐标比例转化函数
function windowToCanvas(canvas, x, y) {
    // 通过传入的在窗口中的鼠标坐标计算出x与y在canvas元素中应有的坐标并返回对象
	// 通用版，适用于所有情况。

    var bbox = canvas.getBoundingClientRect();
	var mystyle = window.getComputedStyle(canvas);
	
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

// 绘制背景网格与绘制图形函数示例代码
function drawGrid(color, stepx, stepy) {
    var VERTICAL_LINE_SPACING = stepx,
		HORIZONTAL_LINE_SPACING = stepy,
		i = context.canvas.height,
		mystyle = window.getComputedStyle(canvas);
	
	// 绘制圆角背景
	drawRect(0, 0, canvas.width, canvas.height, 0.5, 'lightgrey', 'lightgrey');
	context.beginPath();
    drawRoundedRect(0, 0, canvas.width, canvas.height, 10, 0.5, 'white', 'lightgrey');
	context.clip();
	
    context.strokeStyle = color;
    context.lineWidth = 0.5;

    while (i > 0) {
        drawHorizontalLine(i);
        i -= VERTICAL_LINE_SPACING;
    }
	i = context.canvas.width;
	while (i > 0) {
		drawVerticalLine(i);
		i -= HORIZONTAL_LINE_SPACING;
	}
	
	
	// 绘制图形演示部分
	/*
	drawRoundedRect(10, 40, 100, 60, 15, 10, 'grey', strokeStyleSelect.value);
	drawRect(130, 40, 100, 60, 3, 'grey', strokeStyleSelect.value);
	drawCircle(280, 70, 30, 0, Math.PI * 2, true, 6, 'grey', strokeStyleSelect.value);
	drawLine(350, 40, 350, 100, 3, strokeStyleSelect.value);
	drawTriangle(60, 115, 50, 5, 'grey', strokeStyleSelect.value);
	drawQuadraticCurve(140, 150, 150, 200, 200, 150, 3, 'grey', strokeStyleSelect.value);
	drawBezierCurve(220, 150, 230, 240, 250, 110, 300, 150, 2, 'grey', strokeStyleSelect.value);
	*/
	
}
/*
function drawTools() {
	conContext.clearRect(0, 0, 100, 600);
}
*/

// 用法说明：绘制矩形
// 参数说明：x, y为矩形左上角坐标，width, height为矩形长、宽，lineWidth, fillColor, strokeColor为矩形描边线条宽度，填充颜色，描边颜色。
function drawRect(x, y, width, height, lineWidth, fillColor, strokeColor) {
	var wid = context.lineWidth;
	context.fillStyle = fillColor;
	context.strokeStyle = strokeColor;
	context.lineWidth = lineWidth;
	
	context.strokeRect(x, y, width, height);
	context.fillRect(x, y, width, height);
	context.lineWidth = wid;
}

// 用法说明：绘制正三角形
// 参数说明：x, y为正三角形几何中心，innerSide为几何中心到各顶点距离，lineWidth, fillColor, strokeColor为三角形描边线条宽度，填充颜色与描边颜色。
function drawTriangle(x, y, innerSide, lineWidth, fillColor, strokeColor) {
	var wid = context.lineWidth;
	context.fillStyle = fillColor;
	context.strokeStyle = strokeColor;
	context.lineWidth = lineWidth;
	
	context.beginPath();
	context.moveTo(x, y);
	context.lineTo(x + (1.732050808 / 2 * innerSide), y + 1.5 * innerSide);
	context.lineTo(x - (1.732050808 / 2 * innerSide), y + 1.5 * innerSide);
	context.closePath();
	context.stroke();
	context.fill();
	context.lineWidth = wid;
}

// 用法说明：绘制圆形
// 参数说明：x, y为圆心坐标，radius, theta1, theta2, bool为圆形半径，开始角度，结束角度，是否逆时针，lineWidth, fillColor, strokeColor为圆形描边线条宽度，填充颜色与描边颜色。
function drawCircle(x, y, radius, theta1, theta2, bool, lineWidth, fillColor, strokeColor) {
	var wid = context.lineWidth;
	context.fillStyle = fillColor;
	context.strokeStyle = strokeColor;
	context.lineWidth = lineWidth;
	
	context.beginPath();
	context.arc(x, y, radius, theta1, theta2, bool);
	context.stroke();
	context.fill();
	context.lineWidth = wid;
}

// 用法说明：绘制圆角矩形函数
// 参数说明：cornerX、cornerY为矩形左上角端点坐标，width、height为矩形长、宽，cornerRadius为矩形圆角的半径，lineWidth、fillColor、strokeColor为图形描边线段宽度、描边颜色与填充颜色。
function drawRoundedRect(cornerX, cornerY, width, height, cornerRadius, lineWidth, fillColor, strokeColor) {
	var wd = width - cornerRadius,
		ht = height - cornerRadius,
		wid = context.lineWidth;
	context.fillStyle = fillColor;
	context.strokeStyle = strokeColor;
	context.lineWidth = lineWidth;
	
	context.beginPath();
	context.moveTo(cornerX, cornerY + cornerRadius);
	context.arcTo(cornerX, cornerY, cornerX + cornerRadius, cornerY, cornerRadius);
	
	context.lineTo(cornerX + wd, cornerY);
	context.arcTo(cornerX + width, cornerY, cornerX + width, cornerY + cornerRadius, cornerRadius);
	
	context.lineTo(cornerX + width, cornerY + ht);
	context.arcTo(cornerX + width, cornerY + height, cornerX + wd, cornerY + height, cornerRadius);
	
	context.lineTo(cornerX + cornerRadius, cornerY + height);
	context.arcTo(cornerX, cornerY + height, cornerX, cornerY + ht, cornerRadius);
	context.closePath();
	context.stroke();
	context.fill();
	context.lineWidth = wid;
}

// 用法说明：绘制线段
// 参数说明：x1, y1, x2, y2为线段起始点与结束点，lineWidth, strokeColor为线条描边线条宽度，描边颜色。
function drawLine(x1, y1, x2, y2, lineWidth, strokeColor) {
	var wid = context.lineWidth;
	context.strokeStyle = strokeColor;
	context.lineWidth = lineWidth;
	
	context.beginPath();
	context.moveTo(x1, y1);
	context.lineTo(x2, y2);
	context.stroke();
	context.lineWidth = wid;
}

// 用法说明：绘制二次贝塞尔曲线
// 参数说明：x0, y0为开始点坐标，x, y为结束点坐标，x1, y1为控制点坐标，lineWidth为绘制线宽度，后两个参数是描边颜色以及填充颜色。
function drawQuadraticCurve(x0, y0, x1, y1, x, y, lineWidth, fillColor, strokeColor) {
	var wid = context.lineWidth;
	context.lineWidth = lineWidth;
	context.strokeStyle = strokeColor;
	context.fillStyle = fillColor;
	
	context.beginPath();
	context.moveTo(x0, y0);
	context.quadraticCurveTo(x1, y1, x, y);
	context.stroke();
	context.lineWidth = wid;
}

// 用法说明：绘制三次贝塞尔曲线
// 参数说明：x0, y0为开始点坐标，x, y为结束点坐标，x1, y1, x2, y2为控制点1、点2坐标，lineWidth为绘制线宽度，后两个参数是描边颜色以及填充颜色。
function drawBezierCurve(x0, y0, x1, y1, x2, y2, x, y, lineWidth, fillColor, strokeColor) {
	var wid = context.lineWidth;
	context.lineWidth = lineWidth;
	context.fillStyle = fillColor;
	context.strokeStyle = strokeColor;
	
	context.beginPath();
	context.moveTo(x0, y0);
	context.bezierCurveTo(x1, y1, x2, y2, x, y);
	context.stroke();
	context.lineWidth = wid;
}

// Save and restore drawing surface...................................

function saveDrawingSurface() {
    drawingSurfaceImageData = context.getImageData(0, 0,
        canvas.width,
        canvas.height);
}

function restoreDrawingSurface() {
    context.putImageData(drawingSurfaceImageData, 0, 0);
}

// Rubberbands.......................................................

// 调整拖动状态中参数
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
	
    context.save();
    context.strokeStyle = 'red';
    context.restore();
}

// 绘制橡皮筋式响应的图形 默认是直线
function drawRubberbandShape(loc) {
	// 修改：通过判断patternDraw变量判断绘制什么图形。
	
	if (patternDraw.value === 'line') {
		context.beginPath();
		context.moveTo(mousedown.x, mousedown.y);
		context.lineTo(loc.x, loc.y);
		context.stroke();
	} else if (patternDraw.value === 'rect') {
		drawRect(rubberbandRect.left, rubberbandRect.top, rubberbandRect.width, rubberbandRect.height, context.lineWidth, context.fillStyle, context.strokeStyle);
	} else if (patternDraw.value === 'circle') {
		var radius = Math.sqrt((loc.x - mousedown.x) * (loc.x - mousedown.x) + (loc.y - mousedown.y) * (loc.y - mousedown.y));
		drawCircle(mousedown.x, mousedown.y, radius, 0, Math.PI * 2, true, canvas.lineWidth, canvas.fillStyle, canvas.strokeStyle);
	} else if (patternDraw.value === 'tri') {
		var side = Math.sqrt((loc.x - mousedown.x) * (loc.x - mousedown.x) + (loc.y - mousedown.y) * (loc.y - mousedown.y));
		drawTriangle(rubberbandRect.left, rubberbandRect.top, side, context.lineWidth, context.fillStyle, context.strokeStyle);
	} else if (patternDraw.value === 'rounded') {
		drawRoundedRect(rubberbandRect.left, rubberbandRect.top, rubberbandRect.width, rubberbandRect.height, 5, context.lineWidth, context.fillStyle, context.strokeStyle);
	} else if (patternDraw.value === 'quadra') {
		drawQuadraticCurve(200, 200, loc.x, loc.y, mousedown.x, mousedown.y, context.lineWidth, context.fillStyle, context.strokeStyle);
	} else if (patternDraw.value === 'bezier') {
		drawBezierCurve(200, 200, 400, 400, loc.x, loc.y, mousedown.x, mousedown.y, context.lineWidth, context.fillStyle, context.strokeStyle);
	} else if (patternDraw.value === 'text') {
		var fontSize = Math.sqrt((loc.x - mousedown.x) * (loc.x - mousedown.x) + (loc.y - mousedown.y) * (loc.y - mousedown.y)) + 'px Consolas',
			temp = context.font;
		context.font = fontSize;
		context.fillText('Sample Text', mousedown.x, mousedown.y);
		context.font = temp;
	} else if (patternDraw.value === 'caution') {
		alert('页面待完善！');
		dragging = false;
	}
}

function updateRubberband(loc) {
    updateRubberbandRectangle(loc);
    drawRubberbandShape(loc);
}

// Guidewires........................................................

function drawHorizontalLine(y) {

	context.beginPath();
	context.moveTo(0, y + 0.5);
	context.lineTo(context.canvas.width, y + 0.5);
	context.stroke();
	
}

function drawVerticalLine(x) {
    context.beginPath();
    context.moveTo(x + 0.5, 0);
    context.lineTo(x + 0.5, context.canvas.height);
    context.stroke();
}

function drawGuidewires(x, y) {
    context.save();
    context.strokeStyle = 'rgba(0,0,230,0.4)';
    context.lineWidth = 0.5;
    drawVerticalLine(x);
    drawHorizontalLine(y);
    context.restore();
}

// Canvas event handlers..............................................

canvas.onmousedown = function (e) {
    var loc = windowToCanvas(canvas, e.clientX, e.clientY);

    e.preventDefault(); // prevent cursor change
	
    mousedown.x = loc.x;
    mousedown.y = loc.y;
	
	/*
	 // 对于每个判断位置都创建路径并判断点击的位置是否为某个图形的路径内部。
	conContext.rect('')
	if (conContext.isPointInPath(loc.x, loc.y)) {
		patternDraw.value = 'line';
	}
	*/
	dragging = true;
	saveDrawingSurface();
};

canvas.onmousemove = function (e) {
    var loc;
	
    if (dragging) {
		loc = windowToCanvas(canvas, e.clientX, e.clientY);
		e.preventDefault(); // prevent selections

		restoreDrawingSurface();
        updateRubberband(loc); // -- 请随鼠标移动显示当前的rubber band

        if (guidewires) {
            drawGuidewires(loc.x, loc.y);
			// 当鼠标在拖拉时超出了drawing surface范围，当作onmouseup处理。
        }
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
	dragging = false;
};

// Controls event handlers.......................................

patternBoutton1.onclick = function (e) {
	patternDraw.value = 'line';
}

patternBoutton2.onclick = function (e) {
	patternDraw.value = 'rect';
}

patternBoutton3.onclick = function (e) {
	patternDraw.value = 'circle';
}

patternBoutton4.onclick = function (e) {
	patternDraw.value = 'tri';
}

patternBoutton5.onclick = function (e) {
	patternDraw.value = 'rounded';
}

patternBoutton6.onclick = function (e) {
	patternDraw.value = 'quadra';
}

patternBoutton7.onclick = function (e) {
	patternDraw.value = 'bezier';
}

patternBoutton8.onclick = function (e) {
	patternDraw.value = 'text';
}

patternBoutton9.onclick = function (e) {
	patternDraw.value = 'caution';
}

eraseAllButton.onclick = function (e) {
    context.clearRect(0, 0, canvas.width, canvas.height);
    drawGrid('lightgray', 10, 10);
	context.fillStyle = fillStyleSelect.value;
	context.strokeStyle = strokeStyleSelect.value;
	context.lineWidth = lineWid.value;
    saveDrawingSurface();
};

strokeStyleSelect.onchange = function (e) {
    context.strokeStyle = strokeStyleSelect.value;
};

guidewireCheckbox.onchange = function (e) {
    guidewires = guidewireCheckbox.checked;
	console.log(guidewires);
};

fillStyleSelect.onchange = function (e) {
	context.fillStyle = fillStyleSelect.value;
};

lineWid.onchange = function (e) {
	context.lineWidth = lineWid.value;
};

// Initialization................................................
// 修改：修改初始化方式
context.clearRect(0, 0, canvas.width, canvas.height);
drawGrid('lightgray', 10, 10);
context.strokeStyle = strokeStyleSelect.value;
context.fillStyle = fillStyleSelect.value;
patternDraw.value = 'line';
context.lineWidth = lineWid;
