var cells = [];
function setup(){
    createCanvas(1900,1000);
    cells.push(new Cell());
    cells.push(new Cell());
}
function draw(){
    background(51);
    for(var i = 0;i<cells.length;i++){
        cells[i].move();
        cells[i].show();
    }
}

function mousePressed(){
    for(var i =cells.length-1;i>=0;i--){
        if(cells[i].clicked(mouseX,mouseY)){
            // console.log("clicked");
            var cellA = cells[i].mitosis();
            var cellB = cells[i].mitosis();
            cells.push(cellA);
            cells.push(cellB);
            cells.splice(i,1);
        }
    }
}

function Cell(pos,r,c){
    if(pos){
        this.pos = pos.copy();
    }else{
        this.pos = pos || createVector(random(width),random(height));
    }
    this.r = r || 100;
    this.c = c || color(random(100,255),0,random(100,255),100);

    this.move = function(){
        var velocity = p5.Vector.random2D();
        this.pos.add(velocity);
    }
    this.mitosis = function(){
        var offset = random(-10,10);
        this.pos.x +=offset;
        this.pos.y +=offset;
        var cell = new Cell(this.pos,this.r*.8,this.c);
        // var cellB = new Cell(this.pos,this.r/2,this.c);
        return cell;

    }
    this.clicked = function(x,y){
        var d = dist(this.pos.x,this.pos.y,x,y);
        if(d<this.r){
            return true;
        }else return false;
    }
    this.show =  function(){
        fill(this.c);
        ellipse(this.pos.x,this.pos.y,this.r,this.r);
    }
}
