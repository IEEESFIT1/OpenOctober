// Code by Kartikey Sharma
// Works in Turbo C++
// Contributed to OpenOctober

#include<iostream.h>
#include<conio.h>
#include<stdio.h>
#include<ctype.h>
#include<process.h>
#include<string.h>
#include<fstream.h>

void element(int,int);
int i,j,g;

void frame()
    {
    gotoxy(19,9);
    cout<<"É";
    for(i=20;i<=60;i++)
     {
     gotoxy(i,9);
     cout<<"Í";
     }
    cout<<"»";
    gotoxy(19,16);
    cout<<"È";
    for(i=20;i<=60;i++)
     {
     gotoxy(i,16);
     cout<<"Í";
     }
    cout<<"¼";
    for(i=10;i<=15;i++)
     {
     gotoxy(19,i);
     cout<<"º";
     }
    for(i=10;i<=15;i++)
     {
     gotoxy(61,i);
     cout<<"º";
     }
    gotoxy(5,24);
    cout<<"Press Esc to Exit";
    }

void display()
{
 gotoxy(33,2);
 cout<<"PERIODIC TABLE";
 gotoxy(1,1);
 cout<<"É";
 for(i=2;i<=79;i++)
  {
  gotoxy(i,1);
  cout<<"Í";
  }
 cout<<"»";
 for(i=2;i<=23;i++)
  {
  gotoxy(80,i);
  cout<<"º";
  }
 gotoxy(80,24);
 cout<<"¼";
 for(i=2;i<=11;i++)
  {
  gotoxy(i,24);
  cout<<"Í";
  }
 gotoxy(1,24);
 cout<<"È";
 for(i=2;i<=23;i++)
  {
  gotoxy(1,i);
  cout<<"º";
  }
 gotoxy(12,4);
 cout<<"Ú"<<"Ä"<<"Ä"<<"¿";
 gotoxy(63,4);
 cout<<"Ú"<<"Ä"<<"Ä"<<"¿";
 gotoxy(12,5);cout<<"³";
 gotoxy(15,5);cout<<"³";
 gotoxy(63,5);cout<<"³";
 gotoxy(66,5);cout<<"³";
 gotoxy(12,6);cout<<"Ã"<<"Ä"<<"Ä"<<"´";
 gotoxy(48,6);cout<<"Ú";
 for(i=51;i<=60;i++)
  if(i%3==0)
   {
   gotoxy(i,6);
   cout<<char(194);
   }
 for(i=48;i<=66;i++)
  if(i%3!=0)
   {
   gotoxy(i,6);
   cout<<"Ä";
   }
 gotoxy(63,6);
 cout<<"Å";
 for(i=48;i<=66;i++)
  if(i%3==0)
   {
   gotoxy(i,7);
   cout<<"³";
   }
 gotoxy(12,7);cout<<"³";
 gotoxy(12,8);cout<<"Ã"<<"Ä"<<"Ä"<<"´";
 gotoxy(12,9);cout<<"³";
 gotoxy(15,9);cout<<"³";
 gotoxy(15,6);cout<<"Å"<<"Ä"<<"Ä"<<"¿";
 gotoxy(15,8);cout<<"Å"<<"Ä"<<"Ä"<<"´";
 gotoxy(18,7);cout<<"³";
 gotoxy(18,9);cout<<"³";
 gotoxy(48,8);cout<<"Ã";
 for(i=51;i<=63;i++)
  if(i%3==0)
   {
   gotoxy(i,8);
   cout<<"Å";
   }
 for(i=48;i<=66;i++)
  if(i%3!=0)
   {
   gotoxy(i,8);
   cout<<"Ä";
   }
 for(i=48;i<=66;i++)
  if(i%3==0)
   {
   gotoxy(i,9);
   cout<<"³";
   }
 gotoxy(12,10);
 cout<<"Ã";gotoxy(15,10);
 cout<<"Å";
 for(i=13;i<=66;i++)
  if(i%3!=0)
     {  gotoxy(i,10);
 cout<<"Ä";
      }for(i=18;i<=45;i++)
  if(i%3==0)
     {  gotoxy(i,10);
 cout<<char(194);
      }for(i=46;i<=63;i++)
  if(i%3==0)
     {  gotoxy(i,10);
 cout<<"Å";
      }gotoxy(18,10);
cout<<"Å";
for(i=12;i<=66;i++)
 if(i%3==0)
  for(j=10;j<=16;j++)
   if(j%2!=0)
    {  gotoxy(i,j);
      cout<<"³";
     }for(i=15;i<=63;i++)
 if(i%3==0)
  for(j=12;j<=14;j++)
   if(j%2==0)
    { gotoxy(i,j);
      cout<<"Å";
     }for(i=15;i<=63;i++)
 if(i%3==0)
  for(j=12;j<=14;j++)
   if(j%2==0)
    { gotoxy(i,j);
      cout<<"Å";
     }for(i=12;i<=66;i++)
 if(i%3==0)
  for(j=12;j<=66;j++)
   if(j%2==0)
    { gotoxy(i,j);
      cout<<"Ä";
     }for(i=15;i<=42;i++)
 if(i%3==0)
  {gotoxy(i,16);
    cout<<"Å";
   }for(i=45;i<=63;i++)
 if(i%3==0)
  { gotoxy(i,16);
    cout<<"Á";
   }for(i=12;i<=42;i++)
 if(i%3==0)
  {  gotoxy(i,17);
    cout<<"³";
   } gotoxy(12,18);
cout<<"À";
for(i=12;i<=42;i++)
 if(i%3!=0)
  {  gotoxy(i,18);
   cout<<"Ä";
  }  cout<<"Ù";
for(i=15;i<=40;i++)
 if(i%3==0)
  {  gotoxy(i,18);
   cout<<"Á";
   } for(i=6;i<=16;i++)
 if(i%2==0)
  {   gotoxy(12,i);
   cout<<"Ã";
  } for(i=6;i<=14;i++)
 if(i%2==0)
  { gotoxy(66,i);
   cout<<"´";
   }gotoxy(66,16);
cout<<"Ù";
gotoxy(12,20);
cout<<"Ú";
for(i=13;i<=23;i++)
 {gotoxy(i,20);
   cout<<"Ä";
 }for(i=24;i<=63;i++)
 if(i%3==0)
  {gotoxy(i,20);
   cout<<char(194);
  }for(i=24;i<=66;i++)
 if(i%3!=0)
  { gotoxy(i,20);
   cout<<"Ä";
   cout<<"¿";
    gotoxy(12,21);
cout<<"³";
 }
 for(i=24;i<=66;i++)
{ if(i%3==0)
  { gotoxy(i,21);
  // cout<<char(194);
  cout<<"³";
   }
}
  for(i=24;i<=66;i++)
{ if(i%3==0)
  { gotoxy(i,20);
   cout<<"Ä";
  }cout<<"¿";
  gotoxy(i,21);
cout<<"³";
}
for(i=24;i<=66;i++)
{ if(i%3==0)
  {gotoxy(i,21);
   cout<<"³";
  }gotoxy(i,22);
cout<<"Ã";
}
for(i=13;i<=23;i++)
  { gotoxy(i,22);
   cout<<"Ä";
  }
  for(i=24;i<=63;i++)
{ if(i%3==0)
  { gotoxy(i,22);
   cout<<"Å";
  }
  }
  for(i=24;i<=66;i++)
{ if(i%3!=0)
  {  gotoxy(i,22);
   cout<<"Ä";
  }  cout<<"´";
      gotoxy(12,23);
cout<<"³";}
for(i=24;i<=66;i++)
  if(i%3==0)
   {  gotoxy(i,23);
     cout<<"³";
  }   gotoxy(12,24);
cout<<"À";
for(i=13;i<=23;i++)
  {    gotoxy(i,24);
    cout<<"À";
  }    for(i=24;i<=63;i++)
 if(i%3==0)
   {  gotoxy(i,24);
     cout<<"Á";
   } for(i=24;i<=66;i++)
  if(i%3!=0)
    { gotoxy(i,24);
      cout<<"Ä";
    }cout<<"Ù";
gotoxy(15,25);
cout<<"ARROWS TO SCROLL.ENTER TO SELECT.ESC TO EXIT.";
gotoxy(13,5);
cout<<"H";
gotoxy(13,7);
cout<<"Li";
gotoxy(13,9);
cout<<"Na";
gotoxy(13,11);
cout<<"K";

gotoxy(15,7); cout<<"³";
for (i=13;i<66;i++)
 {
 gotoxy(i,14);cout<<"Ä";
 gotoxy(i,12);cout<<"Ä";
 gotoxy(i,16);cout<<"Ä";
 if(i>42) {gotoxy(i,18);cout<<"  ";}
 if(i%3==0)
  {
  gotoxy(i,14);cout<<"Å";
  gotoxy(i,12);cout<<"Å";
  gotoxy(i,16);cout<<"Å";
  if(i>42) gotoxy(i,16);cout<<"Á";
  }
 }

for (i=23;i<66;i++)
 {
 gotoxy(i,20);cout<<"Ä";
 gotoxy(i,22);cout<<"Ä";
 gotoxy(i-11,24);cout<<"Ä";
 gotoxy(i,24);cout<<"Ä";
 if(i%3==0)
  {
  gotoxy(i,20);cout<<"Â";
  gotoxy(i,22);cout<<"Å";
  gotoxy(i,24);cout<<"Á";
  }
 }
 for (i=23;i<66;i++)
 {
 if(i%3==0)
  if(i>10)
   {
   gotoxy(i,24);
   cout<<"Á";
   }
 }

for(i=67;i<=80;i++) {gotoxy(i,24);cout<<"Í";}
for(i=0;i<=10;i++) {gotoxy(i,25);cout<<" ";}
for(i=19;i<=47;i++) {gotoxy(i,9);cout<<" ";}
for(i=2;i<=5;i++) {gotoxy(61,i);cout<<" ";}

gotoxy(12,22);cout<<"Ã";
gotoxy(66,20);cout<<"¿ ";
gotoxy(12,24);cout<<"ÀÄ";
gotoxy(80,24);cout<<"¼";
gotoxy(59,9);cout<<" ";
gotoxy(56,9);cout<<" ";


gotoxy(13,13);
cout<<"Rb";
gotoxy(13,15);
cout<<"Cs";
gotoxy(13,17);
cout<<"Fr";
gotoxy(16,7);
cout<<"Be";
gotoxy(16,9);
cout<<"Mg";
gotoxy(16,11);
cout<<"Ca";
gotoxy(16,13);
cout<<"Sr";
gotoxy(16,15);
cout<<"Ba";
gotoxy(16,17);
cout<<"Ra";
gotoxy(19,11);
cout<<"Sc";
gotoxy(19,13);
cout<<"Y";
gotoxy(19,15);
cout<<"La";
gotoxy(19,17);
cout<<"Ac";
gotoxy(22,11);
cout<<"Ti";
gotoxy(22,13);
cout<<"Zr";
gotoxy(22,15);
cout<<"Hf";
gotoxy(22,17);
cout<<"Rf";
gotoxy(25,11);
cout<<"V";
gotoxy(25,13);
cout<<"Nb";
gotoxy(25,15);
cout<<"Ta";
gotoxy(25,17);
cout<<"Ha";
gotoxy(28,11);
cout<<"Cr";
gotoxy(28,13);
cout<<"Mo";
gotoxy(28,15);
cout<<"W";
gotoxy(28,17);
cout<<"Un";
gotoxy(31,11);
cout<<"Mn";
gotoxy(31,13);
cout<<"Tc";
gotoxy(31,15);
cout<<"Re";
gotoxy(31,17);
cout<<"Ns";
gotoxy(34,11);
cout<<"Fe";
gotoxy(34,13);
cout<<"Ru";
gotoxy(34,15);
cout<<"Os";
gotoxy(34,17);
cout<<"Hs";
gotoxy(37,11);
cout<<"Co";
gotoxy(37,13);
cout<<"Rh";
gotoxy(37,15);
cout<<"Ir";
gotoxy(37,17);
cout<<"Mt";
gotoxy(40,11);
cout<<"Ni";
gotoxy(40,13);
cout<<"Pd";
gotoxy(40,15);
cout<<"Pt";
gotoxy(40,17);
cout<<"Uu";
gotoxy(43,11);
cout<<"Cu";
gotoxy(43,13);
cout<<"Ag";
gotoxy(43,15);
cout<<"Au";
gotoxy(46,11);
cout<<"Zn";
gotoxy(46,13);
cout<<"Cd";
gotoxy(46,15);
cout<<"Hg";
gotoxy(49,7);
cout<<"B";
gotoxy(49,9);
cout<<"Al";
gotoxy(49,11);
cout<<"Ga";
gotoxy(49,13);
cout<<"In";
gotoxy(49,15);
cout<<"Tl";
gotoxy(52,7);
cout<<"C";
gotoxy(52,9);
cout<<"Si";
gotoxy(52,11);
cout<<"Ge";
gotoxy(52,13);
cout<<"Sn";
gotoxy(52,15);
cout<<"Pb";
gotoxy(55,7);
cout<<"N";
gotoxy(55,9);
cout<<"P";
gotoxy(55,11);
cout<<"As";
gotoxy(55,13);
cout<<"Sb";
gotoxy(55,15);
cout<<"Bi";
gotoxy(58,7);
cout<<"O";
gotoxy(58,9);
cout<<"S";
gotoxy(58,11);
cout<<"Se";
gotoxy(58,13);
cout<<"Te";
gotoxy(58,15);
cout<<"Po";
gotoxy(61,7);
cout<<"F";
gotoxy(61,9);
cout<<"Cl";
gotoxy(61,11);
cout<<"Br";
gotoxy(61,13);
cout<<"I";
gotoxy(61,15);
cout<<"At";
gotoxy(64,5);
cout<<"He";
gotoxy(64,7);
cout<<"Ne";
gotoxy(64,9);
cout<<"Ar";
gotoxy(64,11);
cout<<"Kr";
gotoxy(64,13);
cout<<"Xe";
gotoxy(64,15);
cout<<"Rn";
gotoxy(13,21);
cout<<"Lanthanides";
gotoxy(25,21);
cout<<"Ce";
gotoxy(28,21);
cout<<"Pr";
gotoxy(31,21);
cout<<"Nd";
gotoxy(34,21);
cout<<"Pm";
gotoxy(37,21);
cout<<"Sm";
gotoxy(40,21);
cout<<"Eu";
gotoxy(43,21);
cout<<"Gd";
gotoxy(46,21);
cout<<"Tb";
gotoxy(49,21);
cout<<"Dy";
gotoxy(52,21);
cout<<"Ho";
gotoxy(55,21);
cout<<"Er";
gotoxy(58,21);
cout<<"Tm";
gotoxy(61,21);
cout<<"Yb";
gotoxy(64,21);
cout<<"Lu";
gotoxy(13,23);
cout<<"Actinides";
gotoxy(25,23);
cout<<"Th";
gotoxy(28,23);
cout<<"Pa";
gotoxy(31,23);
cout<<"U";
gotoxy(34,23);
cout<<"Np";
gotoxy(37,23);
cout<<"Pu";
gotoxy(40,23);
cout<<"Am";
gotoxy(43,23);
cout<<"Cm";
gotoxy(46,23);
cout<<"Bk";
gotoxy(49,23);
cout<<"Cf";
gotoxy(52,23);
cout<<"Ea";
gotoxy(55,23);
cout<<"Fm";
gotoxy(58,23);
cout<<"Md";
gotoxy(61,23);
cout<<"No";
gotoxy(64,23);
cout<<"Lr";
gotoxy(2,2);
i=2;j=2;
gotoxy(i,j);

 do
  {
  g=getch();
  if(g==80)
   {
   if(j==23) j=1;
   gotoxy(i,++j);
   }
  else if(g==77)
   {
   if(i==79) i=1;
   gotoxy(++i,j);
   }
  else if(g==75)
   {
   if(i==2) i=80;
   gotoxy(--i,j);
   }
  else if(g==72)
   {
   if(j==2)
   j=24;
   gotoxy(i,--j);
   }
  if(g==13)
   element(i,j);
  }while(g!=27);
}

void main()
 {
      clrscr();
     display();
 }

void element(int i,int j)
 {
 if(((i==13)||(i==14))&&(j==5))
     {
     clrscr();
      frame();
      gotoxy(21,10);
      cout<<"Atomic No                :1"<<"\n";
      gotoxy(21,11);
      cout<<"Symbol                   :H"<<"\n";
      gotoxy(21,12);
      cout<<"Name                     :Hydrogen"<<"\n";
      gotoxy(21,13);
      cout<<"Atomic Radius            :0.37"<<"\n";
      gotoxy(21,15);
      cout<<"Electronegetivity        :2.20"<<"\n";
      gotoxy(30,20);
      cout<<"Press Any Key To Return.....";
     }

 else if(((i==64)||(i==65))&&(j==5))
 {
  clrscr();
  frame();
  gotoxy(21,10);
  cout<<"Atomic No:               :2"<<"\n";
  gotoxy(21,11);
  cout<<"Symbol                   :He"<<"\n";
  gotoxy(21,12);
  cout<<"Name                     :Helium"<<"\n";
  gotoxy(21,13);
  cout<<"Atomic Radius            :1.2"<<"\n";
  gotoxy(21,14);
  cout<<"1st Ionisation potential :24.58"<<"\n";
  gotoxy(21,15);
  cout<<"Electronegativity        :------"<<"\n";
  gotoxy(30,20);
  cout<<"Press Any Key To Return......";
 }

 else if(((i==13)||(i==14))&&(j==7))
       {
 clrscr();
 frame();
 gotoxy(21,10);
 cout<<"Atomic No:               :3"<<"\n";
 gotoxy(21,11);
 cout<<"Symbol                   :Li"<<"\n";
 gotoxy(21,12);
 cout<<"Name                     :Lithium"<<"\n";
 gotoxy(21,13);
 cout<<"Atomic Radius            :1.23"<<"\n";
 gotoxy(21,15);
 cout<<"Electronegativity        :0.97"<<"\n";
 gotoxy(30,20);
 cout<<"Press Any Key To Return......";
 }

 else if(((i==16)||(i==17))&&(j==7))
       {
 clrscr();
 frame();
 gotoxy(21,10);
 cout<<"Atomic No:               :4"<<"\n";
 gotoxy(21,11);
 cout<<"Symbol                   :Be"<<"\n";
 gotoxy(21,12);
 cout<<"Name                     :Berryllium"<<"\n";
 gotoxy(21,13);
 cout<<"Atomic Radius            :0.89"<<"\n";
 gotoxy(21,15);
 cout<<"Electronegativity        :1.47"<<"\n";
 gotoxy(30,20);
 cout<<"Press Any Key To Return......";
 }

 else if(((i==49)||(i==50))&&(j==7))
 {
  clrscr();
  frame();
  gotoxy(21,10);
  cout<<"Atomic No:               :5"<<"\n";
  gotoxy(21,11);
  cout<<"Symbol                   :B"<<"\n";
  gotoxy(21,12);
  cout<<"Name                     :Boron"<<"\n";
  gotoxy(21,13);
  cout<<"Atomic Radius            :0.80"<<"\n";
  gotoxy(21,14);
  cout<<"1st Ionisation potential :8.3"<<"\n";
  gotoxy(21,15);
  cout<<"Electronegativity        :2.01"<<"\n";
  gotoxy(30,20);
  cout<<"Press Any Key To Return......";
 }

 else if(((i==52)||(i==53))&&(j==7))
 {
  clrscr();
  frame();
  gotoxy(21,10);
  cout<<"Atomic No:               :6"<<"\n";
  gotoxy(21,11);
  cout<<"Symbol                   :C"<<"\n";
  gotoxy(21,12);
  cout<<"Name                     :Carbon"<<"\n";
  gotoxy(21,13);
  cout<<"Atomic Radius            :0.77"<<"\n";
  gotoxy(21,14);
  cout<<"1st Ionisation potential :11.26"<<"\n";
  gotoxy(21,15);
  cout<<"Electronegativity        :2.50"<<"\n";
  gotoxy(30,20);
  cout<<"Press Any Key To Return......";
 }

 else if(((i==55)||(i==56))&&(j==7))
 {
  clrscr();
  frame();
  gotoxy(21,10);
  cout<<"Atomic No:               :7"<<"\n";
  gotoxy(21,11);
  cout<<"Symbol                   :N"<<"\n";
  gotoxy(21,12);
  cout<<"Name                     :Nitrogen"<<"\n";
  gotoxy(21,13);
  cout<<"Atomic Radius            :0.74"<<"\n";
  gotoxy(21,14);
  cout<<"1st Ionisation potential :14.54"<<"\n";
  gotoxy(21,15);
  cout<<"Electronegativity        :3.07"<<"\n";
  gotoxy(30,20);
  cout<<"Press Any Key To Return......";
 }

 else if(((i==58)||(i==59))&&(j==7))
 {
  clrscr();
  frame();
  gotoxy(21,10);
  cout<<"Atomic No:               :8"<<"\n";
  gotoxy(21,11);
  cout<<"Symbol                   :O"<<"\n";
  gotoxy(21,12);
  cout<<"Name                     :Oxygen"<<"\n";
  gotoxy(21,13);
  cout<<"Atomic Radius            :0.74"<<"\n";
  gotoxy(21,14);
  cout<<"1st Ionisation potential :13.61"<<"\n";
  gotoxy(21,15);
  cout<<"Electronegativity        :3.50"<<"\n";
  gotoxy(30,20);
  cout<<"Press Any Key To Return......";
 }

 else if(((i==61)||(i==62))&&(j==7))
 {
  clrscr();
  frame();
  gotoxy(21,10);
  cout<<"Atomic No:               :9"<<"\n";
  gotoxy(21,11);
  cout<<"Symbol                   :F"<<"\n";
  gotoxy(21,12);
  cout<<"Name                     :Fluorine"<<"\n";
  gotoxy(21,13);
  cout<<"Atomic Radius            :0.72"<<"\n";
  gotoxy(21,14);
  cout<<"1st Ionisation potential :17.42"<<"\n";
  gotoxy(21,15);
  cout<<"Electronegativity        :4.10"<<"\n";
  gotoxy(30,20);
  cout<<"Press Any Key To Return......";
 }

 else if(((i==64)||(i==65))&&(j==7))
 {
  clrscr();
  frame();
  gotoxy(21,10);
  cout<<"Atomic No:               :10"<<"\n";
  gotoxy(21,11);
  cout<<"Symbol                   :Ne"<<"\n";
  gotoxy(21,12);
  cout<<"Name                     :Neon"<<"\n";
  gotoxy(21,13);
  cout<<"Atomic Radius            :1.60"<<"\n";
  gotoxy(21,14);
  cout<<"1st Ionisation potential :21.56"<<"\n";
  gotoxy(21,15);
  cout<<"Electronegativity        :-"<<"\n";
  gotoxy(30,20);
  cout<<"Press Any Key To Return......";
 }

 else if(((i==13)||(i==14))&&(j==9))
       {
 clrscr();
 frame();
 gotoxy(21,10);
 cout<<"Atomic No:               :11"<<"\n";
 gotoxy(21,11);
 cout<<"Symbol                   :Na"<<"\n";
 gotoxy(21,12);
 cout<<"Name                     :Sodium"<<"\n";
 gotoxy(21,13);
 cout<<"Atomic Radius            :1.57"<<"\n";
 gotoxy(21,15);
 cout<<"Electronegativity        :1.01"<<"\n";
 gotoxy(30,20);
 cout<<"Press Any Key To Return......";
 }

 else if(((i==16)||(i==17))&&(j==9))
       {
 clrscr();
 frame();
 gotoxy(21,10);
 cout<<"Atomic No:               :12"<<"\n";
 gotoxy(21,11);
 cout<<"Symbol                   :Mg"<<"\n";
 gotoxy(21,12);
 cout<<"Name                :Magnesium"<<"\n";
 gotoxy(21,13);
 cout<<"Atomic Radius            :1.36"<<"\n";
 gotoxy(21,15);
 cout<<"Electonegativity         :1.23"<<"\n";
 gotoxy(30,20);
 cout<<"Press Any Key To Return.....   ";
     }

 else if(((i==49)||(i==50))&&(j==9))
 {
  clrscr();
  frame();
  gotoxy(21,10);
  cout<<"Atomic No:               :13"<<"\n";
  gotoxy(21,11);
  cout<<"Symbol                   :Al"<<"\n";
  gotoxy(21,12);
  cout<<"Name                     :Aluminium"<<"\n";
  gotoxy(21,13);
  cout<<"Atomic Radius            :1.25"<<"\n";
  gotoxy(21,14);
  cout<<"1st Ionisation potential :6.0"<<"\n";
  gotoxy(21,15);
  cout<<"Electronegativity        :1.47"<<"\n";
  gotoxy(30,20);
  cout<<"Press Any Key To Return......";
 }

 else if(((i==52)||(i==53))&&(j==9))
 {
  clrscr();
  frame();
  gotoxy(21,10);
  cout<<"Atomic No:               :14"<<"\n";
  gotoxy(21,11);
  cout<<"Symbol                   :Si"<<"\n";
  gotoxy(21,12);
  cout<<"Name                     :Silicon"<<"\n";
  gotoxy(21,13);
  cout<<"Atomic Radius            :1.17"<<"\n";
  gotoxy(21,14);
  cout<<"1st Ionisation potential :8.15"<<"\n";
  gotoxy(21,15);
  cout<<"Electronegativity        :1.74"<<"\n";
  gotoxy(30,20);
  cout<<"Press Any Key To Return......";
 }

 else if(((i==55)||(i==56))&&(j==9))
 {
  clrscr();
  frame();
  gotoxy(21,10);
  cout<<"Atomic No:               :15"<<"\n";
  gotoxy(21,11);
  cout<<"Symbol                   :P"<<"\n";
  gotoxy(21,12);
  cout<<"Name                     :Phosphorus"<<"\n";
  gotoxy(21,13);
  cout<<"Atomic Radius            :1.10"<<"\n";
  gotoxy(21,14);
  cout<<"1st Ionisation potential :11.0"<<"\n";
  gotoxy(21,15);
  cout<<"Electronegativity        :2.06"<<"\n";
  gotoxy(30,20);
  cout<<"Press Any Key To Return......";
 }

 else if(((i==58)||(i==59))&&(j==9))
 {
  clrscr();
  frame();
  gotoxy(21,10);
  cout<<"Atomic No:               :16"<<"\n";
  gotoxy(21,11);
  cout<<"Symbol                   :S"<<"\n";
  gotoxy(21,12);
  cout<<"Name                     :Sulphur"<<"\n";
  gotoxy(21,13);
  cout<<"Atomic Radius            :1.04"<<"\n";
  gotoxy(21,14);
  cout<<"1st Ionisation potential :10.36"<<"\n";
  gotoxy(21,15);
  cout<<"Electronegativity        :2.44"<<"\n";
  gotoxy(30,20);
  cout<<"Press Any Key To Return......";
 }



 else  if(((i==61)||(i==62))&&(j==9))
 {
  clrscr();
  frame();
  gotoxy(21,10);
  cout<<"Atomic No:               :17"<<"\n";
  gotoxy(21,11);
  cout<<"Symbol                   :Cl"<<"\n";
  gotoxy(21,12);
  cout<<"Name                     :Chlorine"<<"\n";
  gotoxy(21,13);
  cout<<"Atomic Radius            :0.99"<<"\n";
  gotoxy(21,14);
  cout<<"1st Ionisation potential :13.0"<<"\n";
  gotoxy(21,15);
  cout<<"Electronegativity        :2.83"<<"\n";
  gotoxy(30,20);
  cout<<"Press Any Key To Return......";
 }



 else if(((i==64)||(i==65))&&(j==9))
 {
  clrscr();
  frame();
  gotoxy(21,10);
  cout<<"Atomic No:               :18"<<"\n";
  gotoxy(21,11);
  cout<<"Symbol                   :Ar"<<"\n";
  gotoxy(21,12);
  cout<<"Name                     :Argon"<<"\n";
  gotoxy(21,13);
  cout<<"Atomic Radius            :1.90"<<"\n";
  gotoxy(21,14);
  cout<<"1st Ionisation potential :15.76"<<"\n";
  gotoxy(21,15);
  cout<<"Electronegativity        :-"<<"\n";
  gotoxy(30,20);
  cout<<"Press Any Key To Return......";
 }

 else if(((i==13)||(i==14))&&(j==11))
       {
 clrscr();
 frame();
 gotoxy(21,10);
 cout<<"Atomic No:               :19"<<"\n";
 gotoxy(21,11);
 cout<<"Symbol                   :K"<<"\n";
 gotoxy(21,12);
 cout<<"Name                     :Potassium"<<"\n";
 gotoxy(21,13);
 cout<<"Atomic Radius            :2.03"<<"\n";
 gotoxy(21,15);
 cout<<"Electronegativity        :0.91"<<"\n";
 gotoxy(30,20);
 cout<<"Press Any Key To Return......";
 }

 else if(((i==16)||(i==17))&&(j==11))
 {
  clrscr();
  frame();
  gotoxy(21,10);
  cout<<"Atomic No               :20"<<"\n";
  gotoxy(21,11);
  cout<<"Symbol                  :ca"<<"\n";
  gotoxy(21,12);
  cout<<"Name                :Calcium"<<"\n";
  gotoxy(21,13);
  cout<<"Atomic Radius           :1.74"<<"\n";
  gotoxy(21,15);
  cout<<"Electonegativity            :1.04"<<"\n";
  gotoxy(30,20);
  cout<<"Press Any Key To Return.....   ";
    }

 else if(((i==13)||(i==14))&&(j==13))
       {
 clrscr();
 frame();
 gotoxy(21,10);
 cout<<"Atomic No:               :37"<<"\n";
 gotoxy(21,11);
 cout<<"Symbol                   :Rb"<<"\n";
 gotoxy(21,12);
 cout<<"Name                     :Rubidium"<<"\n";
 gotoxy(21,13);
 cout<<"Atomic Radius            :2.16"<<"\n";
 gotoxy(21,15);
 cout<<"Electronegativity        :0.89"<<"\n";
 gotoxy(30,20);
 cout<<"Press Any Key To Return......";
 }

 else if(((i==13)||(i==14))&&(j==15))
       {
 clrscr();
 frame();
 gotoxy(21,10);
 cout<<"Atomic No:               :55"<<"\n";
 gotoxy(21,11);
 cout<<"Symbol                   :Cs"<<"\n";
 gotoxy(21,12);
 cout<<"Name                     :Cesium"<<"\n";
 gotoxy(21,13);
 cout<<"Atomic Radius            :2.35"<<"\n";
 gotoxy(21,15);
 cout<<"Electronegativity        :0.86"<<"\n";
 gotoxy(30,20);
 cout<<"Press Any Key To Return......";
 }

 else if(((i==13)||(i==14))&&(j==17))
       {
 clrscr();
 frame();
 gotoxy(21,10);
 cout<<"Atomic No:               :87"<<"\n";
 gotoxy(21,11);
 cout<<"Symbol                   :Fr"<<"\n";
 gotoxy(21,12);
 cout<<"Name                     :Francium"<<"\n";
 gotoxy(21,13);
 cout<<"Atomic Radius            :-"<<"\n";
 gotoxy(21,15);
 cout<<"Electronegativity        :0.86"<<"\n";
 gotoxy(30,20);
 cout<<"Press Any Key To Return......";
 }

 else if(((i==64)||(i==65))&&(j==23))
      {
       clrscr();
       frame();
       gotoxy(21,10);
       cout<<"Atomic No.              :103"<<"\n";
       gotoxy(21,11);
       cout<<"Symbol                  :Lr"<<"\n";
       gotoxy(21,12);
       cout<<"Name                    :Lawencium"<<" \n";
       gotoxy(21,13);
       cout<<"Atomic Radius           :---"<<"\n";
       gotoxy(21,14);
       cout<<"1st Ionisation Potential:---"<<"\n";
       gotoxy(21,15);
       cout<<"Electonegativity        :1.2"<<"\n";
       gotoxy(30,20);
       cout<<"Press Any Key To Return.....";
      }
char key;
key=getch();
if(key==27) exit(0);
else display();
}
