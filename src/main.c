#include <stdio.h>
#include <math.h>

#define MAX_DEVIATION 0.000001

struct point_floats{
    float x1;
    float x2;
};
struct point_doubles{
    double x1;
    double x2;
};

struct point_floats solve_system_equations_floats(float delta){
    struct point_floats solves;
    solves.x2 = (0.0001 + delta)/0.0001;
    solves.x1 = 2 - solves.x2;
    return solves;
}
struct point_doubles solve_system_equations_doubles(double delta){
    struct point_doubles solves;
    solves.x2 = (0.0001 + delta)/0.0001;
    solves.x1 = 2 - solves.x2;
    return solves;
}

void solve_as_float(){
    float difference_points = 1;
    float delta = 0;
    float first_x1, second_x1, first_x2, second_x2;

    struct point_floats solves;
    solves = solve_system_equations_floats(delta);

    first_x1 = solves.x1;
    first_x2 = solves.x2;
    delta = 0.0001;

    int count = 0;
    while (difference_points > MAX_DEVIATION){

        solves = solve_system_equations_floats(delta);

        delta /= 2.0;
        second_x1 = solves.x1;
        second_x2 = solves.x2;
        difference_points = sqrt((first_x1 - second_x1)*(first_x1 - second_x1) + (first_x2 - second_x2)*(first_x2 -
                                                                                                         second_x2));
        printf("In floats (delta = %.16f):\n", delta);
        printf("x1: %.11f", first_x1); printf("\tx1 with delta: %.11f", second_x1);
        printf("\n");
        printf("x2: %.11f", first_x2); printf("\tx2 with delta: %.11f", second_x2);
        printf("\n");
        printf("Distance: %.16f\n", difference_points);
        printf("\n");

        count ++;
    }
    printf("%d раз(а) поделили delta = 0.0001 на 2 (на 2^%d)", count, count);
}
void solve_as_double(){
    double difference_points = 1;
    double delta = 0;
    double first_x1, second_x1, first_x2, second_x2;

    struct point_doubles solves;
    solves = solve_system_equations_doubles(delta);

    first_x1 = solves.x1;
    first_x2 = solves.x2;
    delta = 0.0001;

    int count = 0;
    while (difference_points > MAX_DEVIATION){

        solves = solve_system_equations_doubles(delta);

        delta /= 2.0;
        second_x1 = solves.x1;
        second_x2 = solves.x2;
        difference_points = sqrt((first_x1 - second_x1)*(first_x1 - second_x1) + (first_x2 - second_x2)*(first_x2 -
                                                                                                         second_x2));
        printf("In doubles (delta = %.16lf):\n", delta);
        printf("x1: %.16lf", first_x1); printf("\tx1 with delta: %.16lf", second_x1);
        printf("\n");
        printf("x2: %.16lf", first_x2); printf("\tx2 with delta: %.16lf", second_x2);
        printf("\n");
        printf("Distance: %.20lf\n", difference_points);
        printf("\n");

        count ++;
    }
    printf("%d раз(а) поделили delta = 0.0001 на 2 (на 2^%d)", count, count);
}

int main() {
    solve_as_float();
    printf("\n//////////////////////////////////////////////\n");
    solve_as_double();
    return 0;
}
