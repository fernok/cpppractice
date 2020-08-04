const STEPS = 0.0005;
const X_MIN = 0;
const X_MAX = 8;
const Y_MIN = 0;
const Y_MAX = 6;
const PIXELS_PER_UNIT = 100;
const dots = [];

const createNewDot = (x, y) => {
    const newDot = document.createElement('div');
    newDot.classList.add('dot');
    newDot.style.left = x * PIXELS_PER_UNIT + 'px';
    newDot.style.bottom = y * PIXELS_PER_UNIT + 'px';
    document.getElementById('graph-sheet').appendChild(newDot);
    return newDot;
};

const getGraphFunction = keyCode => {
    let result;
    switch (keyCode) {
        case 81:
            result = x => x;
            break;
        case 87:
            result = x => x * x; 
            break;
        case 69:
            result = x => (x - 1) * (x - 3) * (x - 7);
            break;
        case 82:
            result = x => 5 * Math.exp(-1 * x);
            break;
        case 84:
            result = x => 2 * Math.log(x);
            break;
        case 89:
            result = x => Math.tan(x);
            break;
    }
    return result;
};

const isDotInRange = (x, y) => {
    return (X_MIN <= x) && (X_MAX >= x) && (Y_MIN <= y) && (y <= Y_MAX);
}

const removeDots = () => {
    const graphSheet = document.getElementById('graph-sheet');
    dots.forEach(dot => {
        graphSheet.removeChild(dot);
    });
    while (dots.length > 0) dots.pop();
};

document.addEventListener('keydown', event => {
    const func = getGraphFunction(event.keyCode);
    // if(!func)
    if(func == undefined) return;

    removeDots();

    for (let x = X_MIN; x <= X_MAX; x += STEPS) {
        const y = func(x);
        if(!isDotInRange(x, y)) {
            const newDot = createNewDot(x, y);
            document.getElementById('graph-sheet').appendChild(newDot);
            dots.push(newDot);
        }
    }
});