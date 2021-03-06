var cols,rows;
var w = 40;

var cells = [];
var current ;

function setup(){
    createCanvas(400,400);
    cols = floor(width/w);
    rows = floor(height/w);
    frameRate(5);

    for(var j = 0;j<cols;j++){
        for(var i = 0;i<rows;i++){
            var cell = new Cell(i,j);
            cells.push(cell);
        }
    }
    current =cells[0];
}

function draw(){
    background(51);
    for (var i = 0;i< cells.length;i++){
        cells[i].show();
    }
    current.visited = true;
    var next = current.chackNeighbors();
    if(next){
        next.visited = true;
        current = next; 
    }
}

function index(i,j){
    if(i<0 || j<0 || i>cols-1 || j>rows-1){
        return -1;
    }
    return i+j*cols;
}

function Cell(i,j){ 
    this.i = i;
    this.j = j;
   
    this.walls = [true,true,true,true];
    this.visited  = false;

    this.chackNeighbors = function(){
        var neighbors = [];
        var top = cells[index(i,j-1)];
        var right = cells[index(i+1,j)];
        var bottom = cells[index(i,j+1)];
        var left = cells[index(i-1,j)];

        if(top && !top.visited){
            neighbors.push(top);
        }
        if(right && !right.visited){
            neighbors.push(right);
        }
        if(bottom && !bottom.visited){
            neighbors.push(bottom);
        }
        if(left && !left.visited){
            neighbors.push(left);
        }
        if(neighbors.length > 0){
            var r = floor(random(0,neighbors.length));
            return neighbors[r];
        }else {
            return undefined;
        }
    }

    this.show = function(){
        var x = this.i*w;
        var y = this.j*w;
        stroke(255);
        if(this.walls[0]) {
            line(x  ,y  ,x+w,y  ); 
        }//top
        if(this.walls[1]) {
            line(x+w,y  ,x+w,y+w);    
        }//right
        if(this.walls[2]) {
            line(x  ,y+w,x+w,y+w);
        } //bottom
        if(this.walls[3]) {
            line(x  ,y  ,x  ,y+w);
        } //left
        
        if(this.visited){
            fill(255,0,255,100);
            rect(x,y,w,w);
        }
    }

}