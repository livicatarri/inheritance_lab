#include <iostream.h>
#include <dos.h>
#include <math.h>
#include<conio.h>
#include<graphics.h>

class point{
protected:
	int X;
	int Y;
	int Color;
public:
	point(int X, int Y, int Color);
	void Show0();
	void Hide0();
	void Move0(int DX,int DY);
	int GetX();
	int GetY();
	int GetColor();
	void PutX(int X);
	void PutY(int Y);
	void PutColor(int Color );
};
class cut:public point{
protected:
	int Len;
	double Fi;
public:
	cut(int X,int Y, int Color, int Len, double Fi);
	void Show1();
	void Hide1();
	void Move1(int DX,int DY);
	void Rotate1 (double DFi);
	void Resize1(double DLen);
	int GetLen();
	double GetFi();
	void PutLen(int Len);
	void PutFi(double Fi);
};
class kvadrat:public cut{

public:
	kvadrat (int X,int Y, int Color, int Len, double Fi);
	void Show2();
	void Hide2();
	void Move2(int DX,int DY);
	void Rotate2 (double DFi);
	void Resize2(double DLen);
	long GetSqrt2();

};
class cube:public kvadrat{

public:
	cube (int X,int Y, int Color, int Len, double Fi);
	void Show3();
	void Hide3();
	void Move3(int DX,int DY);
	void Rotate3 (double DFi);
	void Resize3(double DLen);
	long GetSqrt3();
	long GetVolume3();
};
point::point(int X, int Y, int Color){
 this -> X=X;
 this ->Y=Y;
 this ->Color=Color;

}
void point:: Show0(){
	putpixel(X,Y, Color);

}
void point:: Hide0(){
	int tmp=Color;
	Color=getbkcolor();
	Show0();
	Color=tmp;
}
void point::Move0(int DX, int DY){
    Hide0();
    X+=DX;
    Y+=DY;
    Show0();
}
int point:: GetX(){return X;}
int point:: GetY(){return Y;}
int point:: GetColor(){return Color;}
void point:: PutX(int X){
    this-> X=X;
}
void point:: PutY(int Y){
	this->Y=Y;
}
void point:: PutColor(int Color){
	this->Color=Color;
}

 cut:: cut(int X, int Y, int Color, int Len, double Fi):point (X, Y, Color){
 this-> Len=Len;
 this->Fi=Fi;

}
void cut:: Show1(){
	int X1, Y1, X2, Y2;
	setcolor(Color);
	X1=X+Len*sin(Fi)*0.5;
	Y1= Y-Len*cos(Fi)*0.5;
	X2=X+Len*sin(Fi+M_PI)*0.5;
    Y2=Y-Len*cos(Fi+M_PI)*0.5;
    line(X1, Y1, X2, Y2);
}
void cut:: Hide1(){
	int tmp=Color;
	Color=getbkcolor();
	Show1();
	Color=tmp;
}
void cut::Move1(int DX, int DY){
    Hide1();
    X+=DX;
    Y+=DY;
    Show1();
}
void cut:: Rotate1(double DFi){
	Hide1();
	Fi+=DFi;
	Show1();
}
void cut:: Resize1(double DLen){
	Hide1();
	Len*=DLen;
	Show1();
}


int cut:: GetLen(){return Len;}
double cut:: GetFi(){return Fi;}

void cut:: PutLen(int Len){
	this->Len=Len;
}
void cut:: PutFi(double Fi){
	this->Fi=Fi;
}
 kvadrat:: kvadrat(int X, int Y, int Color, int Len, double Fi): cut(X, Y, Color,Len, Fi){
 

}
void kvadrat:: Show2(){
	int X1,X2, Y1, Y2, X3, X4, Y3, Y4;
	setcolor(Color);
	X1=X+(Len*cos(Fi)-Len*sin(Fi))/2;//нижний правый угол
	Y1=Y+(Len*sin(Fi)+Len*cos(Fi))/2;//нижний правый угол
	X2=X-(Len*cos(-Fi)-Len*sin(-Fi))/2;
	Y2=Y+(Len*sin(-Fi)+Len*cos(-Fi))/2;
	X3=X-(Len*cos(Fi)-Len*sin(Fi))/2;
	Y3=Y-(Len*sin(Fi)+Len*cos(Fi))/2;
	X4=X+(Len*cos(-Fi)-Len*sin(-Fi))/2;
	Y4=Y-(Len*sin(-Fi)+Len*cos(-Fi))/2;
	line(X1,Y1,X2,Y2);
	line(X2, Y2, X3, Y3);
	line (X3, Y3, X4, Y4);
	line (X4, Y4, X1, Y1);
}
void kvadrat:: Hide2(){
	int tmp=Color;
	Color=getbkcolor();
	Show2();
	Color=tmp;
}
void kvadrat::Move2(int DX, int DY){
    Hide2();
    X+=DX;
    Y+=DY;
    Show2();
}
void kvadrat:: Rotate2(double DFi){
	Hide2();
	Fi+=DFi;
	Show2();
}
void kvadrat:: Resize2(double DLen){
	Hide2();
	Len*=DLen;
	Show2();
}



long kvadrat::GetSqrt2(){
	return long(Len)*long(Len);
}
 cube:: cube(int X, int Y, int Color, int Len, double Fi) : kvadrat(X, Y, Color, Len, Fi){


}
void cube:: Show3(){
	int X1, X2, Y1, Y2, X3, X4, Y3, Y4, X5, X6, Y5, Y6, X7, X8, Y7, Y8 ;
	setcolor(Color);
	X1=X+(Len*cos(Fi)-Len*sin(Fi))/2;//нижний правый угол
	Y1=Y+(Len*sin(Fi)+Len*cos(Fi))/2;//нижний правый угол
	X2=X-(Len*cos(-Fi)-Len*sin(-Fi))/2;
	Y2=Y+(Len*sin(-Fi)+Len*cos(-Fi))/2;
	X3=X-(Len*cos(Fi)-Len*sin(Fi))/2;
	Y3=Y-(Len*sin(Fi)+Len*cos(Fi))/2;
	X4=X+(Len*cos(-Fi)-Len*sin(-Fi))/2;
	Y4=Y-(Len*sin(-Fi)+Len*cos(-Fi))/2;
	X5=X+((Len/2+Len/6)*cos(Fi)-(Len/2+Len/6)*sin(Fi));//нижний правый угол
	Y5=Y+((Len/2+Len/6)*sin(Fi)+(Len/2+Len/6)*cos(Fi));//нижний правый угол
	X6=X-((Len/2-Len/6)*cos(-Fi)-(Len/2+Len/6)*sin(-Fi));
	Y6=Y+((Len/2-Len/6)*sin(-Fi)+(Len/2+Len/6)*cos(-Fi));
	X7=X-((Len/2-Len/6)*cos(Fi)-(Len/2-Len/6)*sin(Fi));
	Y7=Y-((Len/2-Len/6)*sin(Fi)+(Len/2-Len/6)*cos(Fi));
	X8=X+((Len/2+Len/6)*cos(-Fi)-(Len/2-Len/6)*sin(-Fi));
	Y8=Y-((Len/2+Len/6)*sin(-Fi)+(Len/2-Len/6)*cos(-Fi));
    line(X1,Y1,X2,Y2);
	line(X2, Y2, X3, Y3);
	line (X3, Y3, X4, Y4);
	line (X4, Y4, X1, Y1);
	line (X5, Y5, X6, Y6);
	line (X6, Y6, X7, Y7);
	line (X7, Y7, X8, Y8);
	line (X8, Y8, X5, Y5);
	line (X1, Y1, X5, Y5);
	line (X2, Y2, X6, Y6);
	line (X3, Y3, X7, Y7);
	line (X4, Y4, X8, Y8);
}
void cube:: Hide3(){
	int tmp=Color;
	Color=getbkcolor();
	Show3();
	Color=tmp;
}
void cube::Move3(int DX, int DY){
    Hide3();
    X+=DX;
    Y+=DY;
    Show3();
}
void cube:: Rotate3(double DFi){
	Hide3();
	Fi+=DFi;
	Show3();
}
void cube:: Resize3(double DLen){
	Hide3();
	Len*=DLen;
	Show3();
}


long cube::GetVolume3(){
	return long(Len)*long(Len)*long(Len);
}
long cube::GetSqrt3(){
	return 6*long(Len)*long(Len);
}
int main()
{
int gdriver = DETECT, gmode, errorcode; 
  initgraph(&gdriver, &gmode, "");  
  errorcode = graphresult();
  if (errorcode != grOk) {
      cout<<"Ошибка графики: "<<grapherrormsg(errorcode)<<endl;     
      cout<<"Нажмите любую клавишу для прерывания:"<<endl;     
      getch();
      return(1); 
          }
  setbkcolor(15);
  point P1(128,100, 8);
  P1.Show0();
  cut C1(256,100, 8, 50, 0 );
  C1.Show1();
  kvadrat K1(384,100, 8, 50, 0 );
  K1.Show2();
  cube M1(512,100, 8, 50, 0);
  M1.Show3();
  getch();
  for (int i=0; i<61; i++){
  	if ((i>15)&&(i<=30)){
  		C1.Rotate1(3.14/20);
  		K1.Rotate2(3.14/20);
  		M1.Rotate3(3.14/20);
}
else  if ((i>30) &&(i<45))
{
	C1.Resize1(1.05);
	K1.Resize2(1.05);
	M1.Resize3(1.05);
}
else if (i>45)
{
	C1.Move1(0,5);
	C1.Rotate1(-3.14/20);
	P1.Move0(0,5);
	C1.Resize1(0.95);
	K1.Move2(0,5);
	K1.Rotate2(-3.14/20);
	K1.Resize2(0.95);
	M1.Move3(0,5);
	M1.Rotate3(-3.14/20);
	M1.Resize3(0.95);
  }
  else
  {
  	C1.Move1(0,5);
  	P1.Move0(0,5);
  	K1.Move2(0,5);
  	M1.Move3(0,5);
  }
  delay(100);

}
closegraph();
cout<<"kvadrat: "<<K1.GetSqrt2()<<endl;
cout<<"cube: "<<M1.GetSqrt3()<<" "<<M1.GetVolume3()<<endl;
return 0;
}
