var canvas = document.getElementById("myCanvas"),
	context = canvas.getContext('2d');

context.font = '45px Arial';
context.fillText('Hello Canvas!', canvas.width / 25, canvas.height / 1.8);


// 分别打印出元素大小和drawing surface的大小 
var style = window.getComputedStyle(canvas),
    cssWidth = style.width,
    cssHeight = style.height;

console.log(canvas.width, canvas.height);
console.log(parseFloat(cssWidth), parseFloat(cssHeight));

//  打印出在drawing surface中鼠标的坐标 (事件监听)
var bbox = canvas.getBoundingClientRect(),
    bboxLeft = bbox.left,
    bboxTop = bbox.top;


canvas.onmousedown = function(e){
    console.log(e.clientX - bboxLeft - 15, e.clientY - bboxTop - 15);
}


/*
canvas.onmousemove = function(e){
    console.log(e.clientX - bboxLeft, e.clientY - bboxTop);
    var x = e.clientX - bboxLeft, y = e.clientY - bboxTop;
    var message = x.toString() + ' ' + y.toString();
    // alert(message);
}
*/

/*
// 添加事件监听器方法
canvas.addEventListener('onomousemove', function(e){
    // Sample Code Here.
});
*/