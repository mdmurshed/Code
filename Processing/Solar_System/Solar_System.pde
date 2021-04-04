import peasy.*;

Planet sun;
PeasyCam cam;

void setup(){
  size(1000,1000,P3D);
  cam = new PeasyCam(this,100);
  sun = new Planet(50,0,0);
  sun.spawnMoons(3,1);
}

void draw(){
  background(0);  
  lights();
  //translate(width/2,height/2);
  sun.show();
  sun.orbit();
}
