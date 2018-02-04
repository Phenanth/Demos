var canvas = document.getElementById('myCanvas'),
	ctx = canvas.getContext('2d');

function fillRectWithColor(color, x, y, width, height) {
	ctx.fillStyle = color;
	ctx.fillRect(x, y, width, height);
}

function drawTriangle(x, y, innerSide, lineWidth, fillColor, strokeColor) {
	var context = canvas.getContext('2d');
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
}

fillRectWithColor("black", 0, 0, 150, 75);

ctx.resetTransform();
ctx.rotate(Math.PI / 6);
fillRectWithColor("blue", 0, 0, 150, 75);

ctx.translate(250, 0);
fillRectWithColor('yellow', 0, 0, 150, 75);
ctx.scale(0.75, 0.5);
fillRectWithColor('purple', 0, 0, 150, 75);


ctx.resetTransform();
ctx.translate(canvas.width / 10, canvas.height / 2);
drawTriangle(0, 0, 20, 1, 'lightblue', 'black');

ctx.rotate(Math.PI);
ctx.translate(0, -canvas.height / 5);
drawTriangle(0, 0, 20, 1, 'lightgreen', 'black')


ctx.resetTransform();