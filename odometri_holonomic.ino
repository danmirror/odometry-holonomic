
double a,b,c,d,e,f,g,h,i;
double a_inverse,b_inverse,c_inverse,
      d_inverse,e_inverse,f_inverse,
      g_inverse,h_inverse,i_inverse;
double det;

double deg2rad(double d)
{
   return d * PI / 180.0 ;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {

  set_speeds(0,80,0);
  delay(3000);
//  set_speeds(1,,0);
//  delay(3000);
//  set_speeds(0,0,70);
//  delay(3000);

}
void set_speeds(float x_speed,float y_speed,float w_speed){
  //  not using it
//  a = cos(240); b = cos(120); c = cos(0);
//  d = sin(240); e = sin(120); f = sin(0);
//  g = 1;        h = 1;        i = 1;

//   matrik
//  | a  b  c |
//  | d  e  f |
//  | g  h  i |

//    matrix 
//  |cos(30+90), cos(150+90), cos(270+90)|, 
//  |sin(30+90), sin(150+90), sin(270+90)|, 
//  |1,         1,            1          |
//    

    a = cos(deg2rad(120)); b = cos(deg2rad(240)); c = cos(deg2rad(360));
    d = sin(deg2rad(120)); e = sin(deg2rad(240)); f = sin(deg2rad(360));
    g = 1;        h = 1;        i=1;
//
//    Serial.print("a = ");
//    Serial.println(a);
//    Serial.print("b = ");
//    Serial.println(b);
//    Serial.print("c = ");
//    Serial.println(c);
//    Serial.print("d = ");
//    Serial.println(d);
//    Serial.print("e = ");
//    Serial.println(e);
//    Serial.print("f = ");
//    Serial.println(f);
 
  
//  
  //calculate determint
//  det = a*e*i + b*f*g + c*d*h - c*e*g - a*f*h - b*d*i;

//  Serial.print("det = ");
//  Serial.println(det);
  
// matrik
//| a  b  c |
//| d  e  f |
//| g  h  i |

//  
  a_inverse = (e*i - f*h)/det;  b_inverse = (h*c - i*b)/det;  c_inverse = (b*f - c*e)/det;
  d_inverse = (g*f - d*i)/det;  e_inverse = (a*i - g*c)/det;  f_inverse = (d*c - a*f)/det;
  g_inverse = (d*h - g*e)/det;  h_inverse = (g*b - a*h)/det;  i_inverse = (a*e - d*b)/det;

//  a_inverse = (e*i - f*h)/det;  b_inverse = (d*i - f*g)/det;  c_inverse = (d*h - g*e)/det;
//  d_inverse = (b*i - h*c)/det;  e_inverse = (a*i - g*c)/det;  f_inverse = (a*h - g*b)/det;
//  g_inverse = (b*f - e*c)/det;  h_inverse = (a*f - d*c)/det;  i_inverse = (a*e - d*b)/det;

//  a_inverse = -0.33;  b_inverse = 0.58;  c_inverse = 0.33;
//  d_inverse = -0.33;  e_inverse = -0.58;  f_inverse = 0.33;
//  g_inverse = 0.67;  h_inverse = 0;  i_inverse = 0.33;

 
  Serial.print(a_inverse*det);
  Serial.print(b_inverse*det);
  Serial.print(c_inverse*det);
  Serial.println("");
  Serial.print(d_inverse*det);
  Serial.print(e_inverse*det);
  Serial.print(f_inverse*det);
  Serial.println("");
  Serial.print(g_inverse*det);
  Serial.print(h_inverse*det);
  Serial.print(i_inverse*det);
  Serial.println("");


  float pwm_mtr1 = a_inverse*x_speed + b_inverse*y_speed + c_inverse*w_speed;
  float pwm_mtr2 = d_inverse*x_speed + e_inverse*y_speed + f_inverse*w_speed;
  float pwm_mtr3 = g_inverse*x_speed + h_inverse*y_speed + i_inverse*w_speed; 
  
  Serial.println(pwm_mtr1);
  Serial.println(pwm_mtr2);
  Serial.println(pwm_mtr3);
  Serial.println(" ");
}
