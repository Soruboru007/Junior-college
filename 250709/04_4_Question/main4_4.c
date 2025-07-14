#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

// ”¼Œa‚©‚ç‰~‚Ì–ÊÏ‚ğ‹‚ß‚éB
// –ß‚è’l@double : ˆø”‚Åw’è‚³‚ê‚½”¼Œa‚Ì‰~‚Ì–ÊÏ
// ˆø”@@radius : ‰~‚Ì”¼Œa
double circleArea(double radius) {
	const double	PI = 3.1415926535897932384626;
	double area;
	area = PI * radius * radius;
	return area;
}


// ”¼Œa‚©‚ç‰~ü‚Ì’·‚³‚ğ‹‚ß‚éB
// –ß‚è’l@double : ˆø”‚Åw’è‚³‚ê‚½”¼Œa‚Ì‰~ü‚Ì’·‚³
// ˆø”@@radius : ‰~‚Ì”¼Œa
double circumference(double radius) {
	const double	PI = 3.1415926535897932384626;
	double length;
	length = 2 * PI * radius;
	return length;
}

// ”¼Œa‚©‚ç‰~ü‚Ì’·‚³‚Æ‰~‚Ì–ÊÏ‚ğ‹‚ß‚éB
// –ß‚è’l@‚È‚µ
// ˆø”@@radius : ‰~‚Ì”¼Œa
// @@@  length : ‰~ü‚Ì’·‚³
// @@@  area   : ‰~‚Ì–ÊÏ
void circleProperty(double radius, double* length, double* area) {
	*length = circumference(radius);
	*area = circleArea(radius);
}

int main(void) {
	double radius;			//‰~‚Ì”¼Œa
	double length, area;	//‰~ü‚Ì’·‚³A–ÊÏ

	printf("‰~‚Ì–ÊÏ‚ğ‹‚ß‚Ü‚·B\n");
	printf("”¼Œa‚ğ“ü—Í‚µ‚Ä‚­‚¾‚³‚¢B");
	fflush(stdout);
	scanf("%lf", &radius);

	circleProperty(radius, &length, &area);

	printf("”¼Œa %.3lf ‚Ì‰~ü‚Ì’·‚³‚Í %lf ‰~‚Ì–ÊÏ‚Í %lf ‚Å‚·B", radius, length, area);

	return 0;
}