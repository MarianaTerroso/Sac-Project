// the setup routine runs once when you press reset:

float Sp = 1.5;
float Pv = 1.2;
float CA = 1.4;
float P = 1.1;
float I = 1.2;
float D = 1.3;
float PV_before = 30;
float derivative;
float integral = 0;
float error = 0;
float time_diff = 500; 
  

void setup() {
  // initialize serial communication at 9600 bits per second:
 
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input:
 if  (Serial.available()>0) {
   Sp = Serial.parseFloat();
   P = Serial.parseFloat();
   I = Serial.parseFloat();
   D = Serial.parseFloat();
   Pv = Serial.parseFloat();
 }
 error = Pv-Sp;
 derivative = (error-(Sp-PV_before))/time_diff;
 integral = (error+(Sp-PV_before))*(time_diff/2);

 CA = P*error + I*integral + D*derivative;

 PV_before = Pv;
  
  // print out the value:
  Serial.print(P,2);
  Serial.print (' ');
  Serial.print(I,2);
  Serial.print (' ');
  Serial.print(D,2);
  Serial.print (' ');
  Serial.print(CA,2);
  Serial.print (' ');
  Serial.println(Sp,2);
 
  delay(500);

}
