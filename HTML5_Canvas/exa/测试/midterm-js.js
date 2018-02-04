// Variables``````````````````````````````````````````
var canvas = document.getElementById('myCanvas'),
	ctx = canvas.getContext('2d'),
	BGimg = new Image(),
	parttern = {},
	gradient = ctx.createLinearGradient(-100, -200, 300, 400),
	heart = {};

// Functions``````````````````````````````````````````

// 绘制半透明背景图及图片填充样式的文字
function drawBackgournd() {
	ctx.globalAlpha = 0.5;
	ctx.clearRect(0, 0, canvas.width, canvas.height);
	ctx.drawImage(BGimg, 0, 0, canvas.width, canvas.height);
	ctx.globalAlpha = 1;
	
	parttern = ctx.createPattern(BGimg, 'repeat');
	ctx.font = canvas.width / 20 + 'px Consolas';
	ctx.fillStyle = parttern;
	ctx.clearRect(canvas.width / 4 / 1.2, canvas.height / 6 * 4.45, canvas.width / 2 * 1.12, canvas.height / 6 / 1.1);
	ctx.fillText('Designed by 陈文菲', canvas.width / 4, canvas.height / 6 * 5);
}

// 绘制圆形背景
function drawRoundBG(x, y) {
	
	ctx.globalAlpha = 0.8;
	ctx.fillStyle = 'antiquewhite';
	ctx.beginPath();
	ctx.arc(x, y, 100, 0, Math.PI * 2, true);
	ctx.fill();
	ctx.fillStyle = 'grey';
	ctx.fill();
	ctx.globalAlpha = 1;
	
}

// Initilizations`````````````````````````````````````

BGimg.src = 'img/Hindsight.jpg';
BGimg.onload = function () {
	
	drawBackgournd();
	drawRoundBG(canvas.width / 2, canvas.height / 2 / 1.16);
	
	// 心一 缩放心形大小及变换坐标系位置
	ctx.resetTransform();
	heart.color = 'antiquewhite';
	ctx.translate(canvas.width / 2, canvas.height / 9 * 3);
	ctx.scale(0.3, 0.3);
	drawFullHeart();
	
	// 心二 再次变换坐标系 用渐变图样填充爱心
	ctx.translate(0, canvas.height / 3 * 2);
	ctx.rotate(Math.PI);
	gradient.addColorStop(0, "black");
	gradient.addColorStop(1, "white");
	heart.color = gradient;
	drawFullHeart();
	
	// 心三 再次变换坐标系 改变心形绘制颜色
	ctx.translate(-canvas.width / 4, canvas.height / 3);
	ctx.rotate(-Math.PI / 2);
	heart.color = 'lightgreen';
	drawFullHeart();
	
	// 心四 再次变换坐标系 添加阴影
	ctx.translate(0, canvas.height / 9 * 7);
	ctx.rotate(Math.PI);
	heart.color = 'lightpink';
	ctx.shadowColor = 'rgba(100, 1, 1, 0.5)';
	ctx.shadowOffsetX = -10;
	ctx.shadowOffsetY = 5;
	drawFullHeart();
	
};
