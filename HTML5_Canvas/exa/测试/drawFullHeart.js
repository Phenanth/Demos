function drawHeart() {
    ctx.beginPath();

    ctx.moveTo(heart.x, heart.y);
    ctx.quadraticCurveTo(heart.x - heart.deltX, heart.y - heart.deltY,
        heart.x - 2 * heart.deltX, heart.y);

    ctx.quadraticCurveTo(heart.x - heart.w / 2, heart.y + heart.h / 2,
        heart.x, heart.y + heart.h);

    ctx.quadraticCurveTo(heart.x + heart.w / 2, heart.y + heart.h / 2,
        heart.x + 2 * heart.deltX, heart.y);

    ctx.quadraticCurveTo(heart.x + heart.deltX, heart.y - heart.deltY,
        heart.x, heart.y);


    ctx.closePath();
    ctx.save();
    ctx.fillStyle = heart.color;
    ctx.fill();
    ctx.stroke();
    ctx.restore();
}

function drawFullHeart() {
    heart.deltX = 50;
    heart.deltY = 50;
    heart.w = heart.deltX * 6.5;
    heart.h = canvas.height / 2;
    heart.x = 0;
    heart.y = -heart.h / 2;
    drawHeart();
}