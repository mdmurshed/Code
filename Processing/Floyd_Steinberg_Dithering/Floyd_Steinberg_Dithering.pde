PImage img;

void setup(){
 size(1280,1136);
 img = loadImage("C:\\Users\\Sky\\Downloads\\img\\image.jpg");
 img.filter(GRAY);
 image(img,0,0);
}

int index(int x,int y){
  return x+y*img.width;
}



void draw(){
  img.loadPixels();
   for(int y = 0;y<img.height-1;y++){
      for (int x = 1;x<img.width-1; x++){
        // get the old pixel
        color pix = img.pixels[index(x,y)];
        float oldR = red(pix);
        float oldG = green(pix);
        float oldB = blue(pix);
        
        float fector = 1;
        // set the closest palette color
        float newR = round(fector*oldR/255) * (255/fector);
        float newG = round(fector*oldG/255) * (255/fector);
        float newB = round(fector*oldB/255) * (255/fector);
        // set the image of the pixel
        img.pixels[index(x,y)] = color(newR,newG,newB);
         
        float errR = oldR - newR;
        float errG = oldG - newG;
        float errB = oldB - newB;
        
        int index = index(x+1,y);
        color c = img.pixels[index];
        float r = red(c);
        float g = green(c);
        float b = blue(c);
        r = r + errR * 7/16.0;
        g = g + errG * 7/16.0;
        b = b + errB * 7/16.0;
        img.pixels[index] = color(r,g,b);
        
        index = index(x-1,y+1);
        c = img.pixels[index];
        r = red(c);
        g = green(c);
        b = blue(c);
        r = r + errR * 3/16.0;
        g = g + errG * 3/16.0;
        b = b + errB * 3/16.0;
        img.pixels[index] = color(r,g,b);
        
        index = index(x,y+1);
        c = img.pixels[index];
        r = red(c);
        g = green(c);
        b = blue(c);
        r = r + errR * 5/16.0;
        g = g + errG * 5/16.0;
        b = b + errB * 5/16.0;
        img.pixels[index] = color(r,g,b);
        
        index = index(x+1,y+1);
        c = img.pixels[index];
        r = red(c);
        g = green(c);
        b = blue(c);
        r = r + errR * 1/16.0;
        g = g + errG * 1/16.0;
        b = b + errB * 1/16.0;
        img.pixels[index] = color(r,g,b);
         //<>//
        
        //pixel[x + 1][y    ] := pixel[x + 1][y    ] + quant_error × 7 / 16
        //pixel[x - 1][y + 1] := pixel[x - 1][y + 1] + quant_error × 3 / 16
        //pixel[x    ][y + 1] := pixel[x    ][y + 1] + quant_error × 5 / 16
        //pixel[x + 1][y + 1] := pixel[x + 1][y + 1] + quant_error × 1 / 16
        
        
      }
    }
    img.updatePixels();
    image(img,640,0);
}
