var canvas = document.getElementById('myCanvas'),
	context = canvas.getContext('2d');

//```````````````````````````
function roundedRect(cornerX, cornerY, width, height, cornerRadius) {
	// 四个圆弧+四条边
	var wd = width - cornerRadius * 2,
		ht = height - cornerRadius * 2;
	context.beginPath();
	context.moveTo(cornerX, cornerY);
	context.arcTo(cornerX - cornerRadius, cornerY - cornerRadius, cornerX + cornerRadius, cornerY + cornerRadius);
	context.lineTo(cornerX - cornerRadius, cornerY);
	context.moveTo(cornerX + width, cornerY);
	context.arcTo(cornerX + width - cornerRadius, cornerY, cornerX + width, cornerY + cornerRadius);
	context.lineTo(cornerX + width, cornerY + height - cornerRadius);
	// 缺两条边
}

//```````````````````````````
// 绘制折线
context.strokeStyle = "black";
//context.lineCap = "round";
//context.lineJoin = "round";
context.lineWidth = 5;
context.beginPath();
context.moveTo(10, 10);
context.lineTo(110, 10);
context.stroke();
//context.lineJoin = "round";
context.strokeStyle = "antiquewhite";
context.lineWidth = 2;

//注释掉这两行即可得到白色折线
context.beginPath();
context.moveTo(110, 10);

context.lineTo(110, 110);
context.stroke();
	

// 绘制矩形
//参考 http://www.aspku.com/kaifa/html/124177.html
context.fillStyle = "antiquewhite";
context.strokeStyle = "black";
//context.lineJoin = "round";
context.lineWidth = 5;

context.beginPath();
context.rect(160, 40, 110, 45);
context.moveTo(300, 10);
context.lineTo(130, 10);
context.lineTo(130, 110);
context.lineTo(300, 110);
context.lineTo(300, 10);
context.closePath();
context.stroke();
context.fill();


// 绘制圆弧 - arc()
context.beginPath();
context.arc(330, 60, 50, -Math.PI / 2, Math.PI / 2);
context.closePath();
context.stroke();
context.fill();

// 绘制圆弧 - arcTo()
context.beginPath();
context.moveTo(20, 130);
context.arcTo(70, 130, 70, 180, 50);
context.stroke();
