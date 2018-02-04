var canvas = document.getElementById('myCanvas'),
    context = canvas.getContext('2d');


// rgb()0-255 rbga()0-255 hsl() hsla()
// #ffffff(RGB16进制类型) #642（R分量都是6 G都是4 B都是2）
// 默认颜色名称

//context.fillStyle = 'antiquewhite';
context.fillStyle = 'rgba(5,10,100,1)';
context.fillRect(0, 0, 300, 200);


context.globalAlpha = 0.5;
context.fillStyle = 'antiquewhite';
context.fillRect(150, 100, 300, 200);


context.globalAlpha = 0.25;
context.fillStyle = 'red';
context.fillRect(300, 200, 300, 200);