#include <stdio.h>
void skipInputError() {
	char c = getchar();
	while (c != '\n')
		c = getchar();
}
double readDouble(char* prefix) {
	double out;
	printf("%s", prefix);
	while (scanf("%lf", &out) != 1) {
		printf("Chybne zadane cislo!\n");
		skipInputError();
		printf("%s", prefix);
	}
	return out;
}
void calcSerial(double r1,double r2,double u) {
	double r = r1 + r2;
	double u1 = u / (r1 + r2) * r1;
	double u2 = u / (r1 + r2) * r2;
	double i = u / r * 1000;
	printf("Seriove zapojeni:\nR = %.3lf Ohm\nU1 = %.3lf V\nU2 = %.3lf V\nI1 = %.3lf mA\nI2 = %.3lf mA\n", r, u1, u2, i,i);
}
void calcParalel(double r1, double r2, double u) {
	double r = r1 + r2 / (r1 * r2);
	double i1 = u / r1 * 1000;
	double i2 = u / r2 * 1000;
	printf("Paralelni zapojeni:\nR = %.3lf Ohm\nU1 = %.3lf V\nU2 = %.3lf V\nI1 = %.3lf mA\nI2 = %.3lf mA\n", r, u, u, i1, i2);
}

int main() {
	double r1 = readDouble("Zadejte R1 = ");
	double r2 = readDouble("Zadejte R2 = ");
	double u = readDouble("Zadejte U = ");
	calcSerial(r1, r2, u);
	calcParalel(r1, r2, u);
}