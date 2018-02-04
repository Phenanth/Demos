// Variables``````````````````````````````````

var canvas = document.getElementById('canvas'),
	context = canvas.getContext('2d');
	
var	startButton = document.getElementById('startButton'),
	readout = document.getElementById('readout'),
	start = false,
	loading = false;

var loop,
	now,
	lastTime,
	pps_for_BGimg = 20,
	pps_for_obj = 50;
	
var	Timer_start = new Date(),
	ANIMATION_DURATION = 5000,
	Timer = new AnimationTimer(ANIMATION_DURATION);
	
var	img = new Image();


// Sprites``````````````````````````````````

var moveRightToLeft_BGimg = {
	lastMove: 0,
	execute: function (sprite, context, now) {
		if (start == true) {
			if (this.lastMove !== 0) {
				var now = new Date();
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
		if (start == true) {
			if (this.lastMove !== 0) {
				var now = new Date();
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
		if(Timer.isRunning()) {
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


// Functions``````````````````````````````````

// 计算fps
function calculateFps() {
	
	now = new Date();
	
	fps = 1000 / (now - lastTime);
	fps = fps.toFixed(0);
	lastTime = now;
	return fps;
	
}

// 计算ppf
function calculatePpf(pps, fps) {
	
	return pps / fps;
	
}

// 绘制加载途中背景
function drawBackground () {
	context.drawImage(img, 0, 0, canvas.width, canvas.height);
}

// 绘制加载条
function drawLoading () {
	
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
		context.drawImage(img, 0, 0, canvas.width, canvas.height);
		context.fillRect(canvas.width / 2 - i / 2, canvas.height / 2.5, i, 100);
		context.fillStyle = 'grey';
		context.font = 40 + 'px Georgia';
		startButton.value = 'Start!';
		context.fillText('Press Start!', canvas.width / 3, canvas.height / 2 + 18);
		loading = false;
	}, 5000);
	
}

// 动画框架
function anime () {
	
	var now = new Date(),
		fps = calculateFps(),
		ppf = calculatePpf(pps_for_obj, fps).toFixed(2);
	
	context.fillStyle = 'rgba(241, 240, 235, 1)';
	context.fillRect(0, 0, canvas.width, canvas.height);
	
	train.update(context, now);
	train.paint(context);
	stone.update(context, now);
	stone.paint(context);
	if (start) {
		if (fps >= Infinity) {
			fps = 59;
		}
		readout.innerHTML = 'FPS: ' + fps + ', ' + 'PPF: ' + ppf;
	}
	
	loop = requestAnimationFrame(anime);
	
}

// Handlers``````````````````````````````````

window.onload = function () {
	
	alert('视差动画：背景淡入效果不是很明显，但系选图颜色原因。请耐心等待至按钮变为“Start!”');
	
	drawLoading();
	
	drawBackground();
	
};

startButton.onclick = function (e) {
	
	if (startButton.value !== 'Wait...') {
		start = !start;

		if (start) {
			loop = requestAnimationFrame(anime);
			startButton.value = 'Pause';
		} else {
			//window.cancelAnimationFrame(loop);
			readout.innerHTML = 'FPS: 0, PPF: 0';
			startButton.value = 'Start';
		}
	}
}

// Initiatives``````````````````````````````````

img.src = "static/img/3.jpg"
img.onload = function (e) {
	train.left = canvas.width ;
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
}
