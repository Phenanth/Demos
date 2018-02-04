// Variables````````````````````````````

var canvas = document.getElementById('myCanvas'),
	context = canvas.getContext('2d'),
	BGimg = new Image(),
	step = 0.02,
	scale = 1,
	x,
	y,
	loop,
	lastTime;


// Functions````````````````````````````

// 绘制图像函数
function drawImage() {
	
	context.clearRect(0, 0, canvas.width, canvas.height);
	context.drawImage(BGimg, x, y, BGimg.width * scale, BGimg.height * scale);
	
}

// 刷新帧数方法调用函数
function drawFrame() {
	
//	scale += step;
	
	x = ((x + 5) > canvas.width) ? -BGimg.width : (x + 5);
	
	//scale += step;

	drawImage();
	
//	if (scale > 1.5) {
//		clearInterval(loop);
//	}

}

// requestAnimationFrame 方法调用函数
function anime() {
	
//	scale += step;
	
	x = ((x + 5) > canvas.width) ? -BGimg.width : (x + 5);

	drawImage();
	
	loop = requestAnimationFrame(anime);
	
//	if (scale > 1.5) {
//		cancelAnimationFrame(loop);
//	}

}

// 计算fps
function calculateFps() {
	var now = new Date();
	fps = 1000 / (now - lastTime);
	fps = fps.toFixed(0);
	lastTime = now;
	return fps;
}


// Initilizations```````````````````````

BGimg.src = 'blue_flower.png';
BGimg.onload = function () {
	
	var now = new Date();
	lastTime = now - 80;
	
	x = -BGimg.width;
	y = BGimg.height / 3;
	
	context.drawImage(BGimg, x, y);
	loop = requestAnimationFrame(anime);
	
//	loop = setInterval(drawFrame, calculateFps());
	
//	// 另一种停止帧数刷新的方法
//	setTimeout(function() {
//		clearInterval(loop);
//	}, 1500);
	
};
