
import processing.serial.*;
Serial myPort;
class Tacka{
public float x,y;
public Tacka(){
  this.x=0;
  this.y=0;
}
public Tacka(float x,float y)
{
  this.x=x;
  this.y=y;
}
}
void setup()
{
  //size(122,80);
  size(854,560);
  
 // printArray(Serial.list());
  String portname=Serial.list()[0];
  myPort=new Serial (this,portname,9600);
}
Tacka t=new Tacka();
Tacka tProslo=new Tacka(0,0);
void draw(){
  delay(100);
  if (myPort.available()>0)
  {
    String s=myPort.readString(),s1,s2;
    int p=s.indexOf(" ");
    s1=s.substring(0,p);
    s2=s.substring(p+1,s.length());
    //println("S2222:::::",s2);
    
    t.x=int(s1);//*8;
    
    
    //print(s);
    t.y=int(s2);//*8;
     scale(1,-1);
  translate(0,-height);
    background(0);
    fill(0);
  ellipse(tProslo.x*7,tProslo.y*7,5*7,5*7);
  fill(255);
  ellipse(t.x*7,t.y*7,5*7,5*7);
  tProslo=t;
  //fill(0);
  //ellipse(tProslo.x,tProslo.y,40,40);
  //fill(255);
  //ellipse(t.x,mouseY,40,40);
  tProslo.x=t.x*7;
  tProslo.y=t.y*7;
 
  delay(1000);
 
  }
  //print("OVO JE S1",t.x);
  //print(" ");
  //println("OVO JE S2",t.y);
  //println(' ');
  
  
  
}
