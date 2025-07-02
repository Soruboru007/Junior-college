// *****************************************************
// ”¼Œa‚©‚ç‰~‚Ì–ÊÏ‚ğ‹‚ß‚éƒvƒƒOƒ‰ƒ€
// *****************************************************
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

// ‰~‚Ì–ÊÏ‚ğ‹‚ß‚éB-------------------------------
// –ß‚è’l@double    : ”¼Œaradius‚Ì‰~‚Ì–ÊÏ
// ˆø”@@radius @ : ‰~‚Ì”¼Œa
double  circleArea(double radius) {
	const double PI = 3.1415926535;
	double area;		//–ÊÏ

	area = PI * radius * radius;
	area = PI * pow(radius, 2);	//math.hg‚¤ê‡‚Í‚±‚ê‚Å‚àOK
	
	return area;
}

//ƒƒCƒ“--------------------------------------------
int main(void) {
	// •Ï”éŒ¾
	double radius;	//‰~‚Ì”¼Œa
	double area;	//‰~‚Ì–ÊÏ
	
	//“ü—Í
	printf("‰~‚Ì–ÊÏ‚ğ‹‚ß‚Ü‚·B\n");
	printf("”¼Œa‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢");
	fflush(stdout);
	scanf("%lf", &radius);

	// ŒvZ
	area = circleArea(radius);

	// o—Í
	printf("”¼Œa %.2lf‚Ì‰~‚Ì–ÊÏ‚Í %.2lf ‚Å‚·B\n", radius, area);

	return 0;
}