#include <stdio.h>
#include <graphics.h>
#include <conio.h>

void drawCalculator();
void performCalculation(int choice);

int main() {
    int gd = DETECT, gm;
    int choice;

    initgraph(&gd, &gm, "C:\\Turboc3\\BGI"); // Set path to BGI folder

    drawCalculator();

    setcolor(WHITE);
    outtextxy(100, 220, "Enter your choice: ");
    scanf("%d", &choice);

    cleardevice();
    performCalculation(choice);

    getch();
    closegraph();
    return 0;
}

void drawCalculator() {
    setbkcolor(RED);
    cleardevice();

    setcolor(YELLOW);
    rectangle(50, 50, 400, 200);

    setcolor(GREEN);
    outtextxy(100, 60, "SIMPLE GUI CALCULATOR");
    outtextxy(100, 100, "1. Addition");
    outtextxy(100, 120, "2. Subtraction");
    outtextxy(100, 140, "3. Multiplication");
    outtextxy(100, 160, "4. Division");
}

void performCalculation(int choice) {
    float a, b, result;
    char resStr[50];

    setcolor(WHITE);
    outtextxy(100, 60, "Enter two numbers: ");
    gotoxy(15, 6);
    scanf("%f %f", &a, &b);

    switch (choice) {
	case 1:
	    result = a + b;
	    sprintf(resStr, "Addition: %.2f + %.2f = %.2f", a, b, result);
	    break;
	case 2:
	    result = a - b;
	    sprintf(resStr, "Subtraction: %.2f - %.2f = %.2f", a, b, result);
	    break;
	case 3:
	    result = a * b;
	    sprintf(resStr, "Multiplication: %.2f * %.2f = %.2f", a, b, result);
	    break;
	case 4:
	    if (b == 0) {
		sprintf(resStr, "Division by zero not allowed.");
	    } else {
		result = a / b;
		sprintf(resStr, "Division: %.2f / %.2f = %.2f", a, b, result);
	    }
	    break;
	default:
	    sprintf(resStr, "Invalid choice.");
    }

    setcolor(YELLOW);
    outtextxy(50, 120, resStr);
}