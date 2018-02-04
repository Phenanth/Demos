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
