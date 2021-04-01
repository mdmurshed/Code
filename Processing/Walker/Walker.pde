
Person w;

void setup(){
  // walker object 
  size(800,600);
  w = new Person();
  background(255);
}

void draw(){
  // run the walker object
   w.step();
   w.render();
}
