// Variables```````````````````````````````````
var canvas = document.getElementById('canvas'),
	context = canvas.getContext('2d'),
	
	flipxCheck = document.getElementById('flipxCheckBox'),
	flipyCheck = document.getElementById('flipyCheckBox'),
	flipx = flipxCheck.checked,
	flipy = flipyCheck.checked,
	
	angleSelect = document.getElementById('angleSelect'),
	rotateAngle = angleSelect.value;

// Functions```````````````````````````````````

// 画数字
function drawNumerals() {
	
	var numerals = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12],
		angle = Math.PI / 6,
		numeralWidth = 0;
	
	context.resetTransform();
	context.translate(canvas.width * 3 / 4, canvas.height * 3 / 4);
	context.rotate(rotateAngle);
	
	context.fillStyle = 'black';
	context.font = 20 + 'px consolas';
	context.save();
	
	numerals.forEach(function (numeral) {
		
		context.restore();
        numeralWidth = context.measureText(numeral).width;
		context.rotate(angle);
		
		context.fillText(numeral, -numeralWidth / 2, -100);
		
	});
	
}

// 绘制单个指针
function drawHand(tic, isHour, width) {
	
	var angle = tic / 360 * (Math.PI * 2),
		Radius = 80,
		handRadius = isHour ? Radius - 20 : Radius,
		wid = context.lineWidth;
	
	context.save();
	context.rotate(angle);
	context.lineWidth = wid * width;
	context.lineCap = 'round';
	context.strokeStyle = 'black';
	
	context.beginPath();
	context.moveTo(0, 0);
	context.lineTo(handRadius, 0);
	context.stroke();
	
	context.lineWidth = wid;
	context.restore();
	
}

// 绘制指针
function drawHands() {
	
	var date = new Date(),
		sec = date.getSeconds() - 15,
		min = date.getMinutes() - 15 + sec / 60,
		hour = date.getHours() - 3 + min / 60;
	hour = hour > 12 ? hour - 12 : hour;
	
	context.resetTransform();
	context.translate(canvas.width * 3 / 4, canvas.height * 3 / 4);
	context.rotate(rotateAngle);
	
	drawHand(hour * (360 / 12), true, 2);
	drawHand(min * (360 / 60), false, 2);
	drawHand(sec * (360 / 60), false, 1);

}

// 绘制时钟钟面
function drawClock() {
	
	var wid = context.lineWidth;
	context.lineWidth = 2;
	
	// 清除钟面
	context.resetTransform();
	context.fillStyle = 'antiquewhite';
	context.fillRect(canvas.width / 2 + wid, canvas.height / 2 + wid, canvas.width / 2, canvas.height / 2, 'antiquewhite');
	
	context.strokeStyle = 'black';
	context.fillStyle = 'white';
	
	// 画圆周
	context.beginPath();
	context.arc(canvas.width * 3 / 4, canvas.height * 3 / 4, 96, 0, Math.PI * 2);
	context.stroke();
	context.fill();
	
	// 画圆心
	context.beginPath();
	context.fillStyle = 'black';
	context.arc(canvas.width * 3 / 4, canvas.height * 3 / 4, 3, 0, Math.PI * 2);
	context.fill();
	
	
	// 画数字
	drawNumerals();
	
	// 画指针
	drawHands();
	
	context.lineWidth = wid;
	
}

// 通用型画虚线函数
function drawDashedLine(x1, y1, x2, y2, dashLength) {
	
	var ix,
		iy,
		lowx,
		lowy,
		n = Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)) / (dashLength * 2),
		deltax = Math.abs(x2 - x1) / (n * 2), // 修改计算间隔语句
		deltay = Math.abs(y2 - y1) / (n * 2);
	
	if (x2 > x1) {
		ix = x2;
		lowx = x1;
	} else {
		ix = x1;
		lowx = x2;
	}
	if (y2 > y1) {
		iy = y2;
		lowy = y1;
	} else {
		iy = y1;
		lowy = y2;
	}
	
	context.strokeStyle = 'grey';
	context.lineCap = 'round';
	
	while (ix >= lowx && iy >= lowy) {
		
		context.moveTo(ix, iy);
		context.lineTo(ix - deltax, iy - deltay); // 修改用错的变量
		context.stroke();
		
		ix -= 2 * deltax;
		iy -= 2 * deltay;
		
	}
	
}

// 绘制背景
function drawBackground() {
	
	context.clearRect(0, 0, canvas.width, canvas.height);
	context.fillStyle = 'antiquewhite';
	context.fillRect(0, 0, canvas.width, canvas.height);
	
	drawDashedLine(canvas.width / 2, 0, canvas.width / 2, canvas.height, 5);
	drawDashedLine(0, canvas.height / 2, canvas.width, canvas.height / 2, 5);
	
	drawClock();
}

// 绘制二次贝塞尔曲线
function drawQuadraticCurve(x0, y0, x1, y1, x, y) {
	
	var wid = context.lineWidth;
	context.lineWidth = 10;
	
	if (flipx) {
		
		context.resetTransform();
		context.translate(canvas.width, 0);
		context.scale(-1, 1);
		
		context.strokeStyle = 'red';
		context.beginPath();
		context.moveTo(x0, y0);
		context.quadraticCurveTo(x1, y1, x, y);
		context.stroke();
		
	}
	if (flipy) {
		
		context.resetTransform();
		context.translate(0, canvas.height);
		context.scale(1, -1);
		
		context.strokeStyle = 'green';
		context.beginPath();
		context.moveTo(x0, y0);
		context.quadraticCurveTo(x1, y1, x, y);
		context.stroke();
		
	}
	context.resetTransform();
	context.strokeStyle = 'blue';
	
	context.beginPath();
	context.moveTo(x0, y0);
	context.quadraticCurveTo(x1, y1, x, y);
	context.stroke();
	
	context.lineWidth = wid;
	
}

// Handlers`````````````````````````````````````

// Flipx改变的事件监听器
flipxCheck.onchange = function (e) {
	
	var wid = context.lineWidth;
	
	flipx = flipxCheck.checked;
	context.resetTransform();
	context.fillStyle = 'antiquewhite';
	
	
	if (flipx) {
		
		drawQuadraticCurve(30, 30, 40, 240, 230, 120);
		
	} else {
		
		context.fillRect(canvas.width / 2 + wid, 0, canvas.width / 2, canvas.height / 2 - wid, 'antiquewhite');
		
	}
	
};

// Flipy改变的事件监听器
flipyCheck.onchange = function (e) {
	
	var wid = context.lineWidth;
	
	flipy = flipyCheck.checked;
	context.resetTransform();
	
	if (flipy) {
		
		drawQuadraticCurve(30, 30, 40, 240, 230, 120);
		
	} else {
		
		context.fillStyle = 'antiquewhite';
		context.fillRect(0, canvas.height / 2 + wid, canvas.width / 2 - wid, canvas.height / 2, 'antiquewhite');
		
	}
	
};

// AngleSelect改变的事件监听器
angleSelect.onchange = function (e) {
	
	var wid = context.lineWidth;
	
	context.resetTransform();
	context.fillStyle = 'antiquewhite';
	
	context.fillRect(canvas.width / 2 + wid, canvas.height / 2 + wid, canvas.width / 2, canvas.height / 2, 'antiquewhite');
	
	rotateAngle = angleSelect.value / 180 * Math.PI;
	drawClock();
	
};

// Initialization``````````````````````````````

drawBackground();
drawQuadraticCurve(30, 30, 40, 240, 230, 120);
loop = setInterval(drawClock, 1000);
