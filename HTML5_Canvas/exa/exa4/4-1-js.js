var canvas = document.getElementById('myCanvas'),
    context = canvas.getContext('2d');


// 绘制阴影
context.shadowColor = "rgba(100, 1, 1, 0.5)";
context.shadowBlur = 10;
context.shadowOffsetX = -8;
context.shadowOffsetY = 10;


// 线性渐变
var gradient = context.createLinearGradient(300, 300, 595, 395);
context.strokeRect(300, 300, 295, 95);

gradient.addColorStop(0, "#CCCCFF"); // 设置渐变起点颜色
gradient.addColorStop(0.5, "pink");
gradient.addColorStop(0.6, "#FFCCCC");
gradient.addColorStop(0.85, "antiquewhite");
gradient.addColorStop(1, "white");// 设置渐变终点颜色

context.fillStyle = gradient;
context.fillRect(300, 300, 295, 95);
//context.fillRect(0, 0, canvas.width, canvas.height); //  超出起点/终点的部分都会是0/1点的颜色


// 放射渐变
var gradient = context.createRadialGradient(200, 100, 50, 200, 200, 200);

gradient.addColorStop(0, "#CCCCFF"); // 设置渐变起点颜色
gradient.addColorStop(0.4, "pink");
gradient.addColorStop(0.6, "#FFCCCC");
gradient.addColorStop(1, "antiquewhite");// 设置渐变终点颜色

context.fillStyle = gradient;
context.fillRect(230, 30, 200, 200);


// 图案填充
var img = new Image();
img.src = "img.jpg";
img.onload = function () { // 等待图片加载成功后再进行函数内操作。然鹅我的电脑不需要这一步也能显示图片。
	var pattern = context.createPattern(img, "repeat");
	context.fillStyle = pattern;
	context.fillRect(30, 110, 105, 240);
}

// 四条不同的

context.beginPath();
context.lineWidth = "2";
context.moveTo(5, 5);
context.lineTo(5 ,50);
context.strokeStyle = "orange";
context.stroke();

context.beginPath();
context.lineWidth = "5";
context.moveTo(5, 50);
context.lineTo(50, 50);
context.strokeStyle = "antiquewhite";
context.stroke();

context.beginPath();
context.lineWidth = "4";
context.moveTo(50, 50);
context.lineTo(50, 5);
context.strokeStyle = "#CCCCFF";
context.stroke();

context.beginPath();
context.lineWidth = "3";
context.moveTo(50, 5);
context.lineTo(5, 5);
context.strokeStyle = "#FFCCCC";
context.stroke();


// 四条相同的

context.strokeStyle = "#FFCCCC";
context.fillStyle = "antiquewhite";
context.lineWidth = "5";

context.moveTo(100, 5);
context.lineTo(200 ,5);
context.lineTo(200, 100);
context.lineTo(100, 100);
context.lineTo(100, 5);

context.stroke();
context.fill();
