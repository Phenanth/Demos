// Variables`````````````````````````````

// Canvas
var canvas = document.getElementById('canvas'),
	context = canvas.getContext('2d');

// DOM结构
var	loading = document.getElementById('loading'),
	wrapper = document.getElementById('wrapper'),
	
	weatherBar = document.getElementById('weatherBar'),
	controlSetting = document.getElementById('control-setting'),
	temputure = document.getElementById('tempu'),
	presentDate = document.getElementById('date'),
	
	clocker = document.getElementById('clocker'),
	temputure2 = document.getElementById('tempu2'),
	humidity = document.getElementById('humidity'),
	airState = document.getElementById('airState'),
	
	controlBar = document.getElementById('controlBar'),
	centiInput = document.getElementById('centiInput'),
	centiOutput = document.getElementById('centiOutput'),
	humiInput = document.getElementById('humiInput'),
	humiOutput = document.getElementById('humiOutput'),
	pmInput = document.getElementById('pmInput'),
	pmOutput = document.getElementById('pmOutput'),
	
	changeLights = document.getElementById('changeLights'),
	weatherScreen = document.getElementById('screen');

// Img
var lamp = new Image(),
	pure = new Image(),
	air = new Image(),
	hum = new Image(),
	
	flat = new Image(),
	arrow = new Image(),
	living = new Image(),
	asist = new Image(),
	mrest = new Image(),
	srest = new Image(),
	func = new Image();

// 判断电器状态、空气指标及房间的变量
var lightsOn = false,
	pureOn = false,
	humOn = false,
	airOn = false,
	centi,
	humi,
	pm,
	centi_t,
	humi_t,
	pm_t,
	lightInTheRoom = 0,
	presentRoom,
	
// 各个房间的电灯
	lightsForLiving = {
		number: 1,
		one: {
			x: canvas.width / 2.18,
			y: canvas.height / 19,
		},
		width: canvas.width / 6,
		height: canvas.height / 4.5
	},
	
	lightsForAsist = {
		number: 1,
		one: {
			x: canvas.width / 5,
			y: canvas.height / 1.6,
		},
		width: canvas.width / 6,
		height: canvas.height / 4.5
	},

	lightsForMRest = {
		number: 1,
		one: {
			x: canvas.width / 3.2,
			y: canvas.height / 1.4,
		},
		width: canvas.width / 6,
		height: canvas.height / 4.5
	},
	
	lightsForSRest = {
		number: 1,
		one: {
			x: canvas.width / 1.7,
			y: canvas.height / 34,
		},
		width: canvas.width / 6,
		height: canvas.height / 4.5
	},
	
	lightsForFunc = {
		number: 1,
		one: {
			x: canvas.width / 2.4,
			y: canvas.height / 1.33,
		},
		width: canvas.width / 6,
		height: canvas.height / 4.5
	},

// 各个房间的空调
    airForLiving = {
		number: 1,
		one: {
			x: canvas.width / 6,
			y: canvas.height / 25,
		},
		width: canvas.width / 7,
		height: canvas.height / 5
	},

	airForMRest = {
		number: 1,
		one: {
			x: canvas.width / 1.63,
			y: canvas.height / 1.3,
		},
		width: canvas.width / 7,
		height: canvas.height / 5
	},

	airForSRest = {
		number: 1,
		one: {
			x: canvas.width / 4.5,
			y: canvas.height / 1.28,
		},
		width: canvas.width / 7,
		height: canvas.height / 5
	},

	airForFunc = {
		number: 1,
		one: {
			x: canvas.width / 3.6,
			y: canvas.height / 1.3,
		},
		width: canvas.width / 7,
		height: canvas.height / 5
	},

// 各个房间的加湿器
	humForMRest = {
		number: 1,
		one: {
			x: canvas.width / 2.9,
			y: canvas.height / 14
		},
		width: canvas.width / 16,
		height: canvas.height / 10
	},

	humForSRest = {
		number: 1,
		one: {
			x: canvas.width / 5.8,
			y: canvas.height / 2.2
		},
		width: canvas.width / 16,
		height: canvas.height / 10
	},

// 各个房间的空气净化器
	pureForLiving = {
		number: 1,
		one: {
			x: canvas.width / 2.5,
			y: canvas.height / 1.45,
		},
		width: canvas.width / 8,
		height: canvas.height / 4
	};

// 刷新时间
var loop;


// Functions`````````````````````````````

// 已有函数 - 坐标转换
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


// 浏览器大小限制显示

// 通过判断浏览器大小决定是否展现天气模块
function displayWeather() {
	
	var width = document.body.clientWidth,
		height = document.body.clientHeight;
	
	if (width > 1400 && height > 500) {
		weatherBar.style.display = 'flex';
	} else {
		weatherBar.style.display = 'none';
	}
	
}

// 通过判断浏览器大小决定是否展现控制模块
function displayControl() {
	
	var width = document.body.clientWidth,
		height = document.body.clientHeight;
	
	if (width > 1400 && height > 500) {
		weatherScreen.style.display = 'flex';
		controlBar.style.display = 'block';
	} else {
		weatherScreen.style.display = 'none';
		controlBar.style.display = 'none';
	}
	
}


// 改变预设方案

// 改变当前预设天气指标 - 复用
function changeWeather(wth, centigrade, humid, pmtdf, date, d, m) {
	
	/*
	改变当前预设天气指标的函数：centigrade温度，humid湿度，pmtdfPM2.5，date日期字符串，d日，m月。
	改变后调整电器开关效果并对当前房间重绘。
	*/
	
	temputure.innerHTML = centigrade.toString();
	presentDate.innerHTML = date;
	weather.day = d;
	weather.month = m;
	weather.temp = centigrade;
	weather.type = wth;
	temputure2.innerHTML = '温度： ' + centigrade.toString() + '℃';
	airState.innerHTML = 'PM2.5： ' + pmtdf.toString();
	humidity.innerHTML = '湿度： ' + humid.toString() + '%';
	
	centi = centigrade;
	humi = humid;
	pm = pmtdf;
	
	updateUnits();
	jumpPresent();
	
}

// 雪天预设方案
function weatherSnow() {
	
	changeWeather('snow', -1, 91, 76, 'Monday 1 January', 1, 1);
	
}

// 大风天预设方案
function weatherWind() {
	
	changeWeather('windy', 14, 55, 45, 'Friday 9 March', 9, 3);
	
}

// 雨天预设方案
function weatherRain() {
	
	changeWeather('rain', 5, 95, 76, 'Sunday 31 December', 31, 12);
	
}

// 雷雨天预设方案
function weatherThunder() {
	
	changeWeather('thunder', 28, 97, 55, 'Tuesday 22 September', 22, 9);
	
}

// 晴天预设方案
function weatherSunny() {
	
	changeWeather('sunny', 35, 30, 38, 'Wednesday 22 August', 22, 8);

}

// 更改显示器时间
function changeTime() {
	
	var time = new Date(),
		month = time.getMonth() + 1,
		day = time.getDate(),
		hour = time.getHours(),
		minute = time.getMinutes();
	clocker.innerHTML = month + '-' + day + ' ' + hour.toString() + ':' + minute.toString();
	
}


// 绘制函数

// 清空画布
function clearRect() {
	
	context.fillStyle = '#6C5B7B';
	context.fillRect(0, 0, canvas.width, canvas.height);
	
}

// 绘制图片（电器发光）
function drawImage(img, x, y, wid, hei, shadow, color) {
	
	/*
	实现电器发光效果的主要逻辑：在图片周围添加一层亮色阴影。
	*/
	
	context.save();
	
	if (shadow) {
		context.shadowColor = color;
		context.shadowOffsetX = 0;
		context.shadowOffsetY = 0;
		context.shadowBlur = 50;
	}
	
	if (img) {
		context.drawImage(img, x, y, wid, hei);
	}
	context.fill();
	
	context.restore();
}

// 绘制带旋转及文字说明的图片
function drawRotatedImage(img, tx, ty, lenx, leny, angle, shadow, msg, mx, my) {
	
	context.save();
    context.resetTransform();
    context.translate(tx, ty);
    context.rotate(angle);
    drawImage(img, 0, 0, lenx, leny, shadow);
    context.restore();
	
    context.fillText(msg, mx, my);
	
}


// 导航跳转页面

// 跳转至主页
function jumpHome() {
	
	clearRect();
	drawImage(flat, 0, 0, canvas.width, canvas.height, false);
	
}

// 跳转至功能介绍
function jumpIntro() {
	
	clearRect();
	presentRoom = '';
	
	context.fillStyle = '#E84A5F';
	context.fillStyle = '#F8B195';
	context.font = 20 + 'px Lato';

	drawRotatedImage(arrow, 500, 230, canvas.width / 6, canvas.height / 6, 15*Math.PI / 180, false, '自定义温度，湿度，PM2.5', canvas.width / 2, canvas.height / 1.4);

	drawRotatedImage(arrow, 500, 70, canvas.width / 6, canvas.height / 6, 315*Math.PI / 180, false, '显示当前温度，湿度，PM2.5', canvas.width / 2, canvas.height / 2.9);
	
	drawRotatedImage(arrow, 100, 110, canvas.width / 6, canvas.height / 6, 225*Math.PI / 180, false, '预定天气方案', canvas.width / 6, canvas.height / 2.9);

	drawRotatedImage(arrow, 150, 275, canvas.width / 6, canvas.height / 6, 150*Math.PI / 180, false, '区间转换按钮', canvas.width / 6, canvas.height / 1.4);
	
	drawRotatedImage(arrow, 340, 230, canvas.width / 6, canvas.height / 6, 80*Math.PI / 180, false, '预定天气的改变', canvas.width / 3, canvas.height / 1.8);

}

// 跳转至元件介绍
function jumpUnit() {
	
	clearRect();
	presentRoom = '';
	
	// 对比电灯开关效果
	drawImage(lamp, canvas.width / 24, canvas.height / 7, canvas.width / 5, canvas.height / 4, false);
	drawImage(lamp, canvas.width / 24, canvas.height / 2, canvas.width / 5, canvas.height / 4, true, 'orange');
	
	// 对比净化器开关效果
    drawImage(pure, canvas.width / 3.5, canvas.height / 8, canvas.width / 8, canvas.height / 4,false);
    drawImage(pure, canvas.width / 3.5, canvas.height / 2.05, canvas.width / 8, canvas.height / 4,true, '#FF69B4');
	
	// 对比加湿器开关效果
    drawImage(hum,canvas.width / 2,canvas.height / 5,canvas.width / 16,canvas.height / 10,false);
    drawImage(hum,canvas.width / 2,canvas.height / 1.7,canvas.width / 16,canvas.height / 10,true, '#7B68EE');

	// 对比空调开关效果
    drawImage(air,canvas.width / 1.5,canvas.height / 6,canvas.width / 7,canvas.height / 5,false);
    drawImage(air,canvas.width / 1.5,canvas.height / 1.9,canvas.width / 7,canvas.height / 5,true, '#8DB6CD');
	
}

// 跳转至客厅
function jumpLiving() {
	
	clearRect();
	presentRoom = 'Living';
	lightInTheRoom = lightsForLiving.number;
	
	// 绘制背景
	drawImage(living, 0, 0, canvas.width, canvas.height, false);

	//绘制各类电器
	drawImage(lamp, lightsForLiving.one.x, lightsForLiving.one.y, lightsForLiving.width, lightsForLiving.height, lightsOn, 'orange');
	drawImage(pure, pureForLiving.one.x, pureForLiving.one.y, pureForLiving.width, pureForLiving.height, pureOn, '#FF69B4');
	drawImage(air, airForLiving.one.x, airForLiving.one.y, airForLiving.width, airForLiving.height, airOn, '#8DB6CD');

}

// 跳转至主卧
function jumpMainRest() {
	
	clearRect();
	presentRoom = 'MRest';
	lightInTheRoom = lightsForMRest.number;
	
	// 绘制背景
	drawImage(mrest, 60, 0, canvas.width / 1.2, canvas.height, false);
	
	// 绘制各类电器
	drawImage(lamp, lightsForMRest.one.x, lightsForMRest.one.y, lightsForMRest.width, lightsForMRest.height, lightsOn, 'orange');
	drawImage(hum, humForMRest.one.x, humForMRest.one.y, humForMRest.width, humForMRest.height, humOn, '#7B68EE');
	drawImage(air, airForMRest.one.x, airForMRest.one.y, airForMRest.width, airForMRest.height, airOn, '#8DB6CD');
	
}

// 跳转至次卧
function jumpSideRest() {
	
	clearRect();
	presentRoom = 'SRest';
	lightInTheRoom = lightsForSRest.number;
	
	// 绘制背景
	drawImage(srest, 60, 0, canvas.width / 1.2, canvas.height, false);
	
	// 绘制各类电器
	drawImage(lamp, lightsForSRest.one.x, lightsForSRest.one.y, lightsForSRest.width, lightsForSRest.height, lightsOn, 'orange');
	drawImage(hum, humForSRest.one.x, humForSRest.one.y, humForSRest.width, humForSRest.height, humOn, '#7B68EE');
	drawImage(air, airForSRest.one.x, airForSRest.one.y, airForSRest.width, airForSRest.height, airOn, '#8DB6CD');
	
}

// 跳转至功能室
function jumpFunction() {
	
	clearRect();
	presentRoom = 'Func';
	lightInTheRoom = lightsForFunc.number;
	
	// 绘制背景
	drawImage(func, 100, 0, canvas.width / 1.5, canvas.height, false);
	
	// 绘制各类电器
	drawImage(lamp, lightsForFunc.one.x, lightsForFunc.one.y, lightsForFunc.width, lightsForFunc.height, lightsOn, 'orange');
	drawImage(air, airForFunc.one.x, airForFunc.one.y, airForFunc.width, airForFunc.height, airOn, '#8DB6CD');
	
}

// 跳转至厨卫
function jumpAsist() {
	
	clearRect();
	presentRoom = 'Asist';
	lightInTheRoom = lightsForAsist.number;
	
	// 绘制背景
	drawImage(asist, canvas.width / 4.4, 30, canvas.width / 1.8, canvas.height / 1.2, false);
	
	// 绘制电器
	drawImage(lamp, lightsForAsist.one.x, lightsForAsist.one.y, lightsForAsist.width, lightsForAsist.height, lightsOn, 'orange');
	
}

// 重绘当前房间
function jumpPresent() {
	
	switch (presentRoom) {
	case 'Living':
		jumpLiving();
		break;
	case 'Asist':
		jumpAsist();
		break;
	case 'MRest':
		jumpMainRest();
		break;
	case 'SRest':
		jumpSideRest();
		break;
	case 'Func':
		jumpFunction();
		break;
	}
	
}


// 控制函数

// 交互用电灯控制函数 - 转换开关状态
function Lights() {
	
	if (lightsOn) {
		turnLights(1);
	} else {
		turnLights(0);
	}
	
}

// 交互用空气净化器控制函数 - 转换开关状态
function Pure() {
	
	if (pureOn) {
		turnPure(1);
	} else {
		turnPure(0);
	}
	
}

// 交互用空调控制函数 - 转换开关状态
function Air() {
	
	if (airOn) {
		turnAir(1);
	} else {
		turnAir(0);
	}
	
}

// 交互用加湿器控制函数 - 转换开关状态
function Hum() {
	
	if (humOn) {
		turnHum(1);
	} else {
		turnHum(0);
	}
	
}

// 关闭房间内全部电器
function clearUnits() {
	
	turnLights(1);
	turnPure(1);
	turnAir(1);
	turnHum(1);
	
}

// 更新电器状态
function updateUnits() {
	
	/*
	目前天气指标超出阈值时开启电器，否则关掉电器。
	pm为当前天气PM2.5值，pm_t为开启电器阈值。
	其他的以此类推。
	*/
	
	if (pm >= pm_t) {
		turnPure(0);
	} else {
		turnPure(1);
	}
	if (centi_t <= centi) {
		turnAir(0);
	} else {
		turnAir(1);
	}
	if (humi_t >= humi) {
		turnHum(0);
	} else {
		turnHum(1);
	}
	
	jumpPresent();
	
}

// 判断元件类型
function judgeUnits(room, x, y) {

	/*
	主要逻辑是判断房间类型，对比各个电器位置与点击位置，如果是电器就返回电器类型，如果点击位置不属于任何类型电器就break;
	*/
	
	switch (room) {
		case 'Living': {
			if (x >= lightsForLiving.one.x && x <= (lightsForLiving.one.x + lightsForLiving.width) && y >= lightsForLiving.one.y && y <= (lightsForLiving.one.y + lightsForLiving.height)) {
				return 'lights';
			}
			if (x >= pureForLiving.one.x && x <= (pureForLiving.one.x + pureForLiving.width) && y >= pureForLiving.one.y && y <= (pureForLiving.one.y + pureForLiving.height)) {
				return 'pure';
			}
			if (x >= airForLiving.one.x && x <= (airForLiving.one.x + airForLiving.width) && y >= airForLiving.one.y && y <= (airForLiving.one.y + airForLiving.height)) {
				return 'air';
			}
			break;
		};
		case 'MRest': {
			if(x >= lightsForMRest.one.x && x <= (lightsForMRest.one.x + lightsForMRest.width) && y >= lightsForMRest.one.y && y <= (lightsForMRest.one.y + lightsForMRest.height)) {
				return 'lights';
			}
			if(x >= humForMRest.one.x && x <= (humForMRest.one.x + humForMRest.width) && y >= humForMRest.one.y && y <= (humForMRest.one.y + humForMRest.height)) {
				return 'hum';
			}
			if(x >= airForMRest.one.x && x <= (airForMRest.one.x + airForMRest.width) && y >= airForMRest.one.y && y <= (airForMRest.one.y + airForMRest.height)) {
				return 'air';
			}
			break;
		};
		case 'SRest': {
			if(x >= lightsForSRest.one.x && x <= (lightsForSRest.one.x + lightsForSRest.width) && y >= lightsForSRest.one.y && y <= (lightsForSRest.one.y + lightsForSRest.height)) {
				return 'lights';
			}
			if(x >= humForSRest.one.x && x <= (humForSRest.one.x + humForSRest.width) && y >= humForSRest.one.y && y <= (humForSRest.one.y + humForSRest.height)) {
				return 'hum';
			}
			if(x >= airForSRest.one.x && x <= (airForSRest.one.x + airForSRest.width) && y >= airForSRest.one.y && y <= (airForSRest.one.y + airForSRest.height)) {
				return 'air';
			}
			break;
		};
		case 'Asist': {
			if(x >= lightsForAsist.one.x && x <= (lightsForAsist.one.x + lightsForAsist.width) && y >= lightsForAsist.one.y && y <= (lightsForAsist.one.y + lightsForAsist.height)) {
				return 'lights';
			}
			break;
		};
		case 'Func': {
			if(x >= lightsForFunc.one.x && x <= (lightsForFunc.one.x + lightsForFunc.width) && y >= lightsForFunc.one.y && y <= (lightsForFunc.one.y + lightsForFunc.height)) {
				return 'lights';
			}
			if(x >= airForFunc.one.x && x <= (airForFunc.one.x + airForFunc.width) && y >= airForFunc.one.y && y <= (airForFunc.one.y + airForFunc.height)) {
				return 'air';
			}
			break;
		};
	}

}

// 开/关灯 - 通过传入参数指定开或关
function turnLights(clear) {
	
	if (clear) {
		lightsOn = false;
	} else {
		lightsOn = true;
	}
	
	jumpPresent();
	
}

// 开/关空气净化器 - 通过传入参数指定开或关
function turnPure(clear) {
	
	if (clear) {
		pureOn = false;
	} else {
		pureOn = true;
	}
	
	jumpPresent();
	
}

// 开/关空调 - 通过传入参数指定开或关
function turnAir(clear) {
	
	if (clear) {
		airOn = false;
	} else {
		airOn = true;
	}
	
	jumpPresent();
	
}

// 开/关加湿器 - 通过传入参数指定开或关
function turnHum(clear) {
	
	if (clear) {
		humOn = false;
	} else {
		humOn = true;
	}
	
	jumpPresent();
	
}


// Handlers`````````````````````````````

// 监听初始化
window.onload = function (e) {
	
	displayWeather();
	displayControl();
	changeTime();
	jumpHome();
	
};

// 监听浏览器窗口大小
window.onresize = function (e) {
	
	displayWeather();
	displayControl();
	
};

// 按下鼠标
document.onmousedown = function(e) {

	/*
	按下鼠标后判断点击范围是否为某房间元件所在位置，对其进行开关效果的切换。
	*/
	
	var loc = windowToCanvas(canvas, e.clientX, e.clientY),
		unitType;

	unitType = judgeUnits(presentRoom, loc.x, loc.y);

	switch (unitType) {
		case 'lights':
			Lights();
			break;
		case 'air':
			Air();
			break;
		case 'hum':
			Hum();
			break;
		case 'pure':
			Pure();
			break;
	}

};

// 更新室温阈值
centiInput.onchange = function (e) {
	
	/*
	对输入值进行合法判断后，刷新电器开关状态，重绘当前房间
	以下三个函数原理相同。
	*/
	
	if (centiInput.value < 100 && centiInput.value > -100) {
		centi_t = centiInput.value;
		centiOutput.innerHTML = '室温高于' + centiInput.value + '°C时';
	} else {
		alert('温度范围：-100 - 100 摄氏度。（请填写数字）');
	}
	
	updateUnits();
	jumpPresent();
	
}

// 更新湿度阈值
humiInput.onchange = function (e) {
	
	if (humiInput.value <= 100 && humiInput.value >= 0) {
		humi_t = humiInput.value;
		humiOutput.innerHTML = '湿度低于' + humiInput.value + '%时';
	} else {
		alert('湿度范围：0 - 100 百分比。（请填写数字）');
	}
	
	updateUnits();
	jumpPresent();
	
}

// 更新PM2.5阈值
pmInput.onchange = function (e) {
	
	if (pmInput.value <= 350 && pmInput.value >= 0) {
		pm_t = pmInput.value;
		pmOutput.innerHTML = 'PM2.5大于' + pmInput.value + '时';
	} else {
		alert('PM2.5范围：0 - 350 。（请填写数字）');
	}
	
	updateUnits();
	jumpPresent();
	
}


// Initialization`````````````````````````````

lamp.src = 'static/img/lamp.png';
pure.src = 'static/img/pure.png';
hum.src = 'static/img/hum.png';
air.src = 'static/img/air.png';
arrow.src = 'static/img/arrow.png';

flat.src = 'static/img/flat.png';
living.src = 'static/img/living_psed.png';
asist.src = 'static/img/asist_psed.png';
mrest.src = 'static/img/mrest.png';
srest.src = 'static/img/srest.png';
func.src = 'static/img/func.png';

// 初始化当前天气状态
centi = -1;
pm = 76;
humi = 91;

// 初始化阈值
centi_t = 25;
pm_t = 50;
humi_t = 58;

// 初始化电器开关状态
updateUnits();

// 加载形式：三秒后进入正式内容页面。
window.setTimeout(function () {
	
	loading.style.display = 'none';
	wrapper.style.display = 'flex';
	
	loop = setInterval(changeTime, 1000);
	
}, 3000);
