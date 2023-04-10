/*
#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <math.h>

// An implementation of gotoxy() function for smoother animation
// without scrolling or clearing screen.
void gotoxy(SHORT x, SHORT y)
{
  static HANDLE h = NULL;  
  if(!h)
    h = GetStdHandle(STD_OUTPUT_HANDLE);
  COORD c = { x, y };  
  SetConsoleCursorPosition(h,c);
}

//              k;double sin()
//          ,cos();main(){float A=
//        0,B=0,i,j,z[1760];char b[
//      1760];printf("\x1b[2J");for(;;
//   ){memset(b,32,1760);memset(z,0,7040)
//   ;for(j=0;6.28>j;j+=0.07)for(i=0;6.28
//  >i;i+=0.02){float c=sin(i),d=cos(j),e=
//  sin(A),f=sin(j),g=cos(A),h=d+2,D=1/(c*
//  h*e+f*g+5),l=cos      (i),m=cos(B),n=s\
// in(B),t=c*h*g-f*        e;int x=40+30*D*
// (l*h*m-t*n),y=            12+15*D*(l*h*n
// +t*m),o=x+80*y,          N=8*((f*e-c*d*g
//  )*m-c*d*e-f*g-l        *d*n);if(22>y&&
//  y>0&&x>0&&80>x&&D>z[o]){z[o]=D;;;b[o]=
//  ".,-~:;=!*#$@"[N>0?N:0];}}/*#****!!-*/
//   printf("\x1b[H");for(k=0;1761>k;k++)
//    putchar(k%80?b[k]:10);A+=0.04;B+=
//      0.02;}}/*****####*******!!=;:~
//        ~::==!!!**********!!!==::-
//          .,~~;;;========;;;:~-.
//              ..,--------,*/
/*
int main()
{
    // R1 is taken as 1, since it is only multiplied with terms,
    // we can neglect it in this program.

    // A, B
    float A = 0, B = 0;

    //phi, theta
    float i, j;
    
    //K1
    int k;

    //z-buffer
    float z[1760];
    char b[1760];
    std::cout << "\x1b[2J";
    while (true)
    {
        memset(b, 32, 1760);
        memset(z, 0, 7040);
        for (j = 0; j < 6.28; j += 0.07)
        {
            for (i = 0; i < 6.28; i += 0.02)
            {
                // We will calculate the position and luminance of each point.
                float c = sin(i); // sin(phi)
                float d = cos(j); // cos(theta)
                float e = sin(A); // sin(A)
                float f = sin(j); // sin(theta)
                float g = cos(A); // cos(A)
                float h = d + 2;  // (R2 + R1cos(theta)) //R2 is taken as 2 here
                float D = 1 / (c * h * e + f * g + 5); // 1/(z + K2) //K2 is taken as 5
                float l = cos(i); // cos(phi)
                float m = cos(B); // cos(B)
                float n = sin(B); // sin(B)
              
                float t = c * h * g - f * e;

                // Calculating x (x' since we are multiplting by D) (K1 is 1)
                int x = 40 + 30 * D * (l * h * m - t * n);

                // Calculating y (y' specifically since we are multiplying by D)
                int y = 12 + 15 * D * (l * h * n + t * m);
                
                // Varible to store rendered ASCII character in the buffer.
                // We are using a 1D array.
                int o = x + 80 * y;

                // Luminance
                int N = 8 * ((f * e - c * d * g) * m - c * d * e - f * g - l * d * n);
                if (22 > y && y > 0 && x > 0 && 80 > x && D > z[o])
                {
                    // String D in z-buffer
                    z[o] = D;

                    // Choosing ASCII character based on Luminance and storing it in buffer
                    b[o] = ".,-~:;=!*#$@"[N > 0 ? N : 0];
                }
            }
        }
        std::cout << "\x1b[H";
        for (k = 0; k < 1761; k++)
        {
            putchar(k % 80 ? b[k] : 10);
            A += 0.00004;
            B += 0.00002;
        }
        //Sleep(10);
        gotoxy(0,0);
    }


    return 0;
}
*/

#include <stdint.h>
#include <stdio.h>
int main()
{
    //the following code should be self-explanatory
    int format = 684837;
    uint64_t freqs[16] = { 4557704611105873944,6293041952211349568,7232032755832676440,9836271091686599272,11342418091143829394,7666925796986299039,8289648 };
    uint64_t phases[16] = { 2745812699376323861,4477710776532278558,4107622644641439798,4062343665106426382,4257685111635071841,2598073413584315427,1713226 };
    uint64_t composite[32] = { 0 };
    int i = 0;
    unsigned char frequency = i[(char*)(freqs)];
    unsigned char phase = i[(char*)(phases)];
    while (frequency > 0) {
        for (int j = phase; j < 2048; j += frequency) {
            (j / 64)[composite] |= ((uint64_t)1 << j % 64);
        }
        frequency = (i % 64)[(char*)(freqs + i / 64)];
        phase = (i % 64)[(char*)(phases + i / 64)];
        i++;
    }
    printf((char*)&format, composite);
    return 0;
}