/*
 * Copyright (C) 2012 David Geary. This code is from the book
 * Core HTML5 Canvas, published by Prentice-Hall in 2012.
 *
 * License:
 *
 * Permission is hereby granted, free of charge, to any person 
 * obtaining a copy of this software and associated documentation files
 * (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, sublicense, and/or sell copies of the Software,
 * and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * The Software may not be used to create training material of any sort,
 * including courses, books, instructional videos, presentations, etc.
 * without the express written consent of David Geary.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES
 * OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT
 * HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 * WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 * FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 * OTHER DEALINGS IN THE SOFTWARE.
 */

var canvas = document.querySelector('#canvas'),
    readout = document.querySelector('#readout'),
    context = canvas.getContext('2d'),
    spritesheet = new Image();

// Functions.....................................................

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

function drawBackground() {
    // 绘制背景

    var VERTICAL_LINE_SPACING = 12,
        i = context.canvas.height;

    context.clearRect(0, 0, canvas.width, canvas.height); // 清空canvas画布
    context.strokeStyle = 'lightgray'; // 横线颜色
    context.lineWidth = 0.5; // 横线粗细

    // 在画布上从下往上每隔12px画一条线，留出上方48px的空白
    while (i > VERTICAL_LINE_SPACING * 4) {
        context.beginPath();
        context.moveTo(0, i);
        context.lineTo(context.canvas.width, i);
        context.stroke();
        i -= VERTICAL_LINE_SPACING;
    }
}

function drawSpritesheet() {
    // 在画布上绘制图像
	
    context.drawImage(spritesheet, 0, 0);
}

function drawGuidelines(x, y) {
    // 绘制鼠标坐标轴

    context.strokeStyle = 'rgba(0,0,230,0.8)';
    context.lineWidth = 0.5;
    drawVerticalLine(x);
    drawHorizontalLine(y);
}

function updateReadout(x, y) {
    // 显示坐标
	
	// 修改：针对鼠标范围不同，显示的坐标的字体颜色也会发生变化。
    if(x >= 0 && y >= 0 && x <= 500 && y <= 250){
        readout.style.color = 'blue';
        readout.innerHTML = '(' + x.toFixed(0) + ', ' + y.toFixed(0) + ')'; 
    }
    else {
        readout.style.color = 'red';
        readout.innerHTML = '(' + x.toFixed(0) + ', ' + y.toFixed(0) + ')'; 
    }
}

function drawHorizontalLine(y) {
    // 绘制y坐标轴

    context.beginPath();
    context.moveTo(0, y + 0.5);
    context.lineTo(context.canvas.width, y + 0.5);
    context.stroke();
}

function drawVerticalLine(x) {
    // 绘制x坐标轴
	
    context.beginPath();
    context.moveTo(x + 0.5, 0);
    context.lineTo(x + 0.5, context.canvas.height);
    context.stroke();
}

// Event handlers.....................................................

canvas.onmousemove = function (e) {
    // 鼠标移动时的事件监听器

    var loc = windowToCanvas(canvas, e.clientX, e.clientY);
    drawBackground();
    drawSpritesheet();
    drawGuidelines(loc.x, loc.y);
    updateReadout(loc.x, loc.y);
    console.log('loc.x: ' + loc.x.toFixed(0) + ', ' + 'loc.y: ' + loc.y.toFixed(0)); // 修改： 在控制台实时输出鼠标坐标。
};

// Initialization.....................................................

spritesheet.src = 'shared/images/running-sprite-sheet.png'; // 修改：改变图片路径以便在HTML页面中显示。
spritesheet.onload = function (e) {
    drawSpritesheet();
};

drawBackground();