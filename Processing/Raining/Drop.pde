class Drop{
  float x=random(width);
  float y=random(-500,-50);
  
  float z = random(0,20);
  float len = map(z,0,20,10,20);
  float yspeed=map(z,0,20,3,10);
  void fall(){
    y=y+yspeed;
    float gravity = map(z,0,20,0,.2);
    yspeed = yspeed + gravity;
    if(y>height){
     y = random(-200,-100); 
      yspeed=map(z,0,20,3,10);
    }
  }
  void show(){
    float thick = map(z,0,20,1,3);
    strokeWeight(thick);
    stroke(130,43,226);
    line(x,y,x,y+len);
  }
}
