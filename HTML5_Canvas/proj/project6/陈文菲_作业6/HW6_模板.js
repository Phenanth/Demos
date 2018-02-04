// ..................变量声明...................

var canvas = document.getElementById('canvas'),
    context = canvas.getContext('2d'),
    image = new Image();

// 变量：开始/暂停按键
var startButton = document.getElementById('startButton'),
    start = false;

// 变量：动画帧
var animateFrame;

// ----- 添加变量：对背景和运动物体分别设置变化的参数
var loop,
	looping,
	now,
	lastTime,
// 背景的变化速度(像素/时间, pps)
	pps_for_BGimg = 20,
// 运动物体的变化速度(像素/时间, pps)
	pps_for_obj = 50;

// ----- 添加变量：计时器
var	Timer_start = new Date(),
	ANIMATION_DURATION = 5000,
	Timer = new AnimationTimer(ANIMATION_DURATION);

// ----- 添加变量：精灵

var moveRightToLeft_BGimg = {
	lastMove: 0,
	execute: function (sprite, context, now) {
		if (start === true) {
			if (this.lastMove !== 0) {
				now = new Date();
				if (sprite.left >= -canvas.width) {
					sprite.left = sprite.left - (now - this.lastMove) / 1000 * pps_for_BGimg;
				} else {
					sprite.left = canvas.width;
					context.fillStyle = 'rgba(241, 240, 235, 1)';
					context.fillRect(0, 0, canvas.width, canvas.height);
				}
			} else {
				sprite.left = canvas.width;
			}
		}
		this.lastMove = now;
	}
};

var moveRightToLeft_obj = {
	lastMove: 0,
	execute: function (sprite, context, now) {
		if (start === true) {
			if (this.lastMove !== 0) {
				now = new Date();
				if (sprite.left >= -canvas.width) {
					sprite.left = sprite.left - (now - this.lastMove) / 1000 * pps_for_obj;
				} else {
					sprite.left = canvas.width;
				}
			} else {
				sprite.left = canvas.width * 5 / 3;
			}
		}
		this.lastMove = now;
	}
};

var fadeIn = {
	lastChange: 0,
	alpha: 0.1,
	execute: function (sprite, context, now) {

		if (now - Timer_start > ANIMATION_DURATION && context.globalAlpha > 1) {
			Timer.stop();
		}
		if (Timer.isRunning()) {
			if (now - this.lastChange > 500) {
				context.globalAlpha = this.alpha;
				this.alpha += 0.1;
				this.lastChange = now;
			}
		}
	}
};

var trainPainter = new ImagePainter('static/img/2.png'),
	train = new Sprite('train', trainPainter, [moveRightToLeft_BGimg, fadeIn]);

var stonePainter = new ImagePainter('static/img/1.png'),
	stone = new Sprite('stone', stonePainter, [moveRightToLeft_obj]);


// ..................函数定义...................

// .....借用已有函数.....
// function：计算帧率fps
// 计算fps：
function calculateFps(fps) {
    var now = new Date();
    fps = 1000 / (now - lastTime); // f=1/T
    fps = Math.round(fps);
    lastTime = now;
    return fps;
}

// .....自定义函数.....

// ----- 添加代码：计算“基于时间的运动”所需的“像素/帧”数据，即ppf
// 提示：像素/帧 = (像素/时间) / (帧/时间)
function calculatePpf(pps, fps) {
	return pps / fps;
}

// ----- 添加代码：绘制背景
function drawBackground() {
	context.drawImage(image, 0, 0, canvas.width, canvas.height);
}

// ----- 添加代码：绘制加载条
function drawLoading() {
	
	var i = 0.2,
		wid = canvas.width / 2.2,
		now = new Date(),
		lastTime = now;
	
	context.fillStyle = 'rgba(241, 240, 235, 1)';
	context.fillRect(0, 0, canvas.width, canvas.height);
			
	context.font = 30 + 'px Georgia';
	
	while ((now - lastTime) < 50 && i < wid) {
		setTimeout(function () {
			context.fillStyle = 'grey';
			context.fillText('Loading...', canvas.width / 2.5, canvas.height / 2 - 14);
			context.fillRect(canvas.width / 2 - i / 2, canvas.height / 2, i, 20);
			i += 0.04;
		}, 200);
		now = new Date();
	}
	
	setTimeout(function () {
		context.fillStyle = 'rgba(241, 240, 235, 1)';
		context.fillRect(0, 0, canvas.width, canvas.height);
		context.globalAlpha = 0.9;
		context.drawImage(image, 0, 0, canvas.width, canvas.height);
		context.fillRect(canvas.width / 2 - i / 2, canvas.height / 2.5, i, 100);
		context.fillStyle = 'grey';
		context.font = 30 + 'px Georgia';
		startButton.value = 'Start!';
		context.fillText('Press Start!', canvas.width / 2.7, canvas.height / 2 + 18);
		loading = false;
	}, 5000);
	
}

// ----- 添加代码：绘制运动物体
function draw() {
	
}

// ----- 添加代码：绘制当前帧
function drawFrame() {
	
}

// ------ 添加代码：动画循环调用的function
function animate() {
	var now = new Date(),
		fps = calculateFps(),
		ppf = calculatePpf(pps_for_obj, fps).toFixed(2);
	
	context.fillStyle = 'rgba(241, 240, 235, 1)';
	context.fillRect(0, 0, canvas.width, canvas.height);
	
	// 绘制底板
	train.update(context, now);
	train.paint(context);
	// 绘制物体
	stone.update(context, now);
	stone.paint(context);
	
	if (start) {
		if (fps >= Infinity) {
			fps = 59;
		}
		readout.innerHTML = 'FPS: ' + fps + ', ' + 'PPF: ' + ppf;
	}
	
	loop = requestAnimationFrame(animate);
	
}


// .....事件响应.....

// ------ 添加代码：识别开始/暂停状态 
startButton.onclick = function (e) {
	
	if (startButton.value !== 'Wait...') {
		start = !start;

		if (start) {
			loop = requestAnimationFrame(animate);
			startButton.value = 'Pause';
		} else {
			//window.cancelAnimationFrame(loop);
			readout.innerHTML = 'FPS: 0, PPF: 0';
			startButton.value = 'Start';
		}
	}
};

// ----- 添加代码：进度条加载
window.onload = function () {
	
	alert('视差动画：背景淡入效果不是很明显，但系选图颜色原因。请耐心等待至按钮变为“Start!”');
	
	drawLoading();
	
	drawBackground();
	
};

// ..................初始化...................

// ----- 添加代码：加载图片
// 提示：image.src、image.onload
image.src = "static/img/3.jpg";
image.onload = function (e) {
	train.left = canvas.width;
	train.width = canvas.width;
	train.height = canvas.height;
	
	stone.left = canvas.width * 5 / 3;
	stone.top = canvas.height / 4;
	stone.width = canvas.width / 4 * 3;
	stone.height = canvas.height / 4 * 3;
	readout.innerHTML = 'FPS: 0, PPF: 0';
	startButton.value = 'Wait...';
	
	context.resetTransform();
	context.fillStyle = 'rgba(241, 240, 235, 1)';
	context.fillRect(0, 0, canvas.width, canvas.height);
	context.globalAlpha = 0.1;
	
	Timer.start();
};
