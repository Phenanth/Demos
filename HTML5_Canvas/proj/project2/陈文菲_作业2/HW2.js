// 新增了函数drawBackground(), drawDay(), drawIndigator()。
// 修改了原始代码
// 定义变量
var canvas = document.getElementById('myCanvas'),
	context = canvas.getContext('2d'),
	MARGIN = 50;

var FONT_HEIGHT = 20,
    HAND_TRUNCATION = canvas.width / 25,
    HOUR_HAND_TRUNCATION = canvas.width / 6,
    NUMERAL_SPACING = 20,
    RADIUS = canvas.width / 2 - MARGIN,
    HAND_RADIUS = RADIUS + NUMERAL_SPACING;

//  --定义其他所需变量
var	BGImg = new Image(),
	img = new Image(),
	day_arr=["Sunday", "Monday", "Tuesday","Wednesday","Thursday","Friday","Saturday"];

// Functions.....................................................

function drawBackground() {
	// !!!! 新增代码
	// 绘制背景图片与时钟图案
	var pattern = context.createPattern(img, "repeat");
	
	context.globalAlpha = 0.3;
	context.drawImage(BGImg, 0, 0, canvas.width, canvas.height);
	
	// 剪裁
	//context.beginPath();
	//context.arc(canvas.width / 2, canvas.height / 2, RADIUS+34, 0, Math.PI * 2, true);
	//context.closePath();
	//context.clip();
	
	context.globalAlpha = 1;
	context.fillStyle = "white";
	context.beginPath();
	context.arc(canvas.width / 2, canvas.height / 2, canvas.width / 2 - 20, 0, Math.PI * 2);
	context.closePath();
	context.fill();
	
	context.fillStyle = pattern;
	context.beginPath();
	context.globalAlpha = 0.8;
	context.arc(canvas.width/2, canvas.height/2, 50, 0, Math.PI * 2);
	context.closePath();
	context.fill();
	context.globalAlpha = 1;
	
}

function drawCircle() {
	
    //   --画钟面的圆
	context.strokeStyle = "#000";
	context.beginPath();
	context.lineWidth = 5;
	context.arc(canvas.width / 2, canvas.height / 2, RADIUS+33, 0, Math.PI * 2);
	context.closePath();
	context.stroke();
	
}

function drawCenter() {
	
    //    --画钟面正中的圆点
	context.beginPath();
	context.arc(canvas.width / 2, canvas.height / 2, 3, 0, Math.PI * 2, true);
	context.closePath();
	context.strokeStyle = "#000";
	context.stroke();
	
}

function drawHand(loc, isHour, width) {
	
	// 画单个指针
	context.strokeStyle = "#81812e"
    var angle = loc / 360 * (Math.PI * 2),
        handRadius = isHour ? RADIUS - HAND_TRUNCATION - HOUR_HAND_TRUNCATION : RADIUS - HAND_TRUNCATION,
		lwidth = context.lineWidth;
	
	context.lineWidth = lwidth * width;
	context.lineCap = "round";
	
    context.moveTo(canvas.width / 2, canvas.height / 2);
    context.lineTo(canvas.width / 2 + Math.cos(angle) * handRadius,
        canvas.height / 2 + Math.sin(angle) * handRadius);
    context.stroke();
	
	context.lineWidth = lwidth;

}

function drawHands() {
	
	// 画三条指针
	var date = new Date(),
        hour = date.getHours();
    hour = (hour - 3 > 12 ) ? (hour - 3 - 12) : (hour - 3);
	
    drawHand((hour + date.getMinutes() / 60) * (360 / 12), true, 0.5);
    drawHand((date.getMinutes() - 15) * (360 / 60) + date.getSeconds() * (360 / 60 / 60), false, 0.5);
    drawHand((date.getSeconds() - 15) * (360 / 60), false, 0.3);

}

function drawNumerals() {
    var numerals = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12],
        angle = 0,
        numeralWidth = 0;
	context.fillStyle = "#666600";
	context.shadowColor = "#2F4F4F";
	context.shadowBlur = 10;
	context.shadowOffsetX = -2;
	context.shadowOffsetY = 3;
    numerals.forEach(function (numeral) {
        angle = Math.PI / 6 * (numeral - 3);
        numeralWidth = context.measureText(numeral).width;
        context.fillText(numeral,
            canvas.width / 2 + Math.cos(angle) * (HAND_RADIUS - 8) - numeralWidth / 2,
            canvas.height / 2 + Math.sin(angle) * (HAND_RADIUS - 8) + FONT_HEIGHT / 3);
    });
	context.shadowColor = "rgba(0, 0, 0, 0)";
}

function drawDay(x, y, size, cns) {
	// !!!! 新增代码
	// 画礼拜几
	var now = new Date();
	now.setTime(now.getTime());
	var day = now.getDate();
	var month = now.getMonth() + 1;

	if ((month) < 10) {
		month = "0" + (month);
	}
	if (day < 10) {
		day = "0" + day;
	}

	day = now.getDay();
	cns.fillText(day_arr[day], x, y);

}

function drawIndigator(size, cns) {
	// !!!! 新增代码
	// 画时钟分割线
	cns.lineWidth=2.5;
	cns.lineCap = "round";
	cns.strokeStyle = "#000";

	for(var a = 0; a < 12; a++) {
		var r = parseInt(a) * 0.523;
		var calc = Math.cos(r - 1.57);
		var y = Math.sin(r - 1.57);

		if(a % 3 == 0) {
			var ekstra = size / 50;
		} else {
			var ekstra = 0;
		}
		cns.beginPath();
		cns.moveTo( calc * (size / 3 + ekstra) + (size / 2), y * (size / 3 + ekstra) + (size / 2));
		cns.lineTo(calc * size / 3.25 + (size / 2), y * size / 3.25 + (size / 2));
		cns.stroke();
		cns.fill();
		cns.closePath();
 	}
	
}

function drawClock() {
	// 绘制钟面
    context.clearRect(0, 0, canvas.width, canvas.height);
	var cns = canvas.getContext('2d'),
		size = canvas.width;

	// 新增代码：
	drawBackground();
	drawIndigator(size, cns);
	drawDay((size / 7 * 3), size / 5 * 1.3 + size / 2.3, size, cns);
	
	// 修改代码：
    drawCircle();
    drawHands();
	drawCenter();
    drawNumerals();
	
  
}



// Initialization................................................

context.font = FONT_HEIGHT + 'px Consolas';
// 对初始化工作进行修改：
window.onload = function () {
	BGImg.src = "zm3.jpg";
	BGImg.onload = function () {
	img.src = "zm1.jpg";
	img.onload = function () {
		loop = setInterval(drawClock, 1000);
		}
	}
};