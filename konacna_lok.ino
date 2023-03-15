const int n = 50;//broj uzoraka
long long povecaj=100000;
int d0=122,d1=80;//sirina i duzina
double k0=-0.02688*povecaj,ns0=3.087 ;
double k1=-0.02797 *povecaj,ns1= 2.919;
double k2= -0.03074*povecaj,ns2=  2.822 ;
double k3=- 0.03423*povecaj,ns3=2.822;
int i,lastCal;
double otp0[n], otp1[n], otp2[n], otp3[n];
int index = 0;

double total0 = 0, total1 = 0, total2 = 0, total3 = 0;
double average0 = 0, average1 = 0, average2= 0, average3 = 0;
double R0 = 0, R1 = 0, R2= 0, R3 = 0;




float g0=0,g1=0,g2=0,g3=0, G=0,Gmin=100000,x=0,y=0;

int sensorValue = 0;         // the sensor value

void setup() {
  Serial.begin(9600);
  for (i = 0; i < n; i++) {
    otp0[i] = 0;
    otp1[i] = 0;
    otp2[i] = 0;
    otp3[i] = 0;
  }
}

void loop() {
  /*Serial.print(analogRead(A0));
    Serial.print(" ");
    Serial.print(analogRead(A1));
    Serial.print(" ");
    Serial.print(analogRead(A2));
    Serial.print(" ");
    Serial.println(analogRead(A3));*/
  total0 -= otp0[index];
  total1 -= otp1[index];
  total2 -= otp2[index];
  total3 -= otp3[index];
  otp0[index] = analogRead(A0);
  otp1[index] = analogRead(A1);
  otp2[index] = analogRead(A2);
  otp3[index] = analogRead(A3);
  total0 += otp0[index];
  total1 += otp1[index];
  total2 += otp2[index];
  total3 += otp3[index];
  index++;
  if (index >= n)index = 0;//kad predje broj uzoraka, krece novo usrednjavanje
  average0=(total0 / n)*(5.0/1023.0);
  average1=(total1 / n)*(5.0/1023.0);
  average2=(total2 / n)*(5.0/1023.0);
  average3=(total3 / n)*(5.0/1023.0);
 average0=((average0-ns0)*povecaj)/k0;
  average1=((average1-ns1)*povecaj)/k1;
  average2=((average2-ns2)*povecaj)/k2;
  average3=((average3-ns3)*povecaj)/k3; //rastojanje
//  Serial.print(average0);
//  Serial.print(" ");
//  Serial.print(average1);
//  Serial.print(" ");
//  Serial.print(average2);
//  Serial.print(" ");
//  Serial.println(average3); 


Gmin = 1000000;
 for (i=0;i<=23;i++){
  for (int j=0;j<=15;j++){
    int pi=5*i;
    int pj=5*j;
    R0=sqrt(pi*pi+pj*pj);
    R1=sqrt((pi-115)*(pi-115)+pj*pj);
    R3=sqrt(pi*pi+(pj-75)*(pj-75));
    R2=sqrt((pi-115)*(pi-115)+(pj-75)*(pj-75));//proveravamo za svako polje gde je greska izmedju pravog rastojanja i dobijenog najmanja
    g0=abs(R0-average0);
    g1=abs(R1-average1);
    g2=abs(R2-average2);
    g3=abs(R3-average3);
    G=g0+g1+g2+g3;
    if (G<Gmin){
    Gmin=G;
    x=i*5;
    y=j*5;
    }
  }
 }
 String s=String(x)+" " + String(y);
Serial.println(s);
 Serial.print(x*5);
 Serial.print(" ");
 Serial.println(y*5);
 
}
