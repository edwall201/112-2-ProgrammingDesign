#include <stdio.h>
#include <string.h>
#include <math.h>
#define ShapeText(TYPE) char name[10];\
double (*perimeter)(struct TYPE*);\
double (*area)(struct TYPE*);\

typedef struct shape_s{
    ShapeText(shape_s);
}shape_t;

typedef struct circle_s{
    ShapeText(circle_s);
    double radius;
}circle_t;

typedef struct rectangle_s{
    ShapeText(rectangle_s);
    double length;
    double weight;
}rectangle_t;

typedef struct squre_s{
    ShapeText(squre_s);
    double edge;
}square_t;

typedef struct triangle_s{
    ShapeText(triangle_s);
    double edge1;
    double edge2;
    double edge3;
}triangle_t;

double circle_perimeter(circle_t *c)
{
    return 2 * 3.14 * c->radius;
}

double circle_area(circle_t *c)
{
    return 3.14 * c->radius * c->radius;
}

double retangle_perimeter(rectangle_t *r)
{
    return 2 * (r->length + r->weight);
}

double retangle_area(rectangle_t *r)
{
    return r->length * r->weight;
}

double square_perimeter(square_t *s)
{
    return 4 * s->edge;
}

double squre_area (square_t *s)
{
    return s->edge * s->edge;
}

double tranigle_perimeter(triangle_t *t)
{
    return t->edge1 + t->edge2 + t->edge3;
}

double tranigle_area (triangle_t *t)
{
    double p = (t->edge1 + t->edge2 + t->edge3) / 2;
    return sqrt(p * (p - t->edge1) * (p - t->edge2) * (p - t->edge3));
}

shape_t * CreateShape(char *type)
{
    if(strcmp(type, "C") == 0)
    {
        circle_t *c = (circle_t*)malloc(sizeof(circle_t));
        c->perimeter = circle_perimeter;
        c->area = circle_area;
        return (shape_t*)c;
    }
    else if(strcmp(type, "R") == 0)
    {
        rectangle_t *r = (rectangle_t*)malloc(sizeof(rectangle_t));
        r->perimeter = retangle_perimeter;
        r->area = retangle_area;
        return (shape_t*)r;
    }
    else if(strcmp(type, "S") == 0)
    {
        square_t *s = (square_t*)malloc(sizeof(square_t));
        s->perimeter = square_perimeter;
        s->area = squre_area;
        return (shape_t*)s;
    }
    else if(strcmp(type, "T") == 0)
    {
        triangle_t *t = (triangle_t*)malloc(sizeof(triangle_t));
        t->perimeter = tranigle_perimeter;
        t->area = tranigle_area;
        return (shape_t*)t;
    }else return NULL;
}

int main()
{
    int num;
    scanf("%d", &num);
    double perimeter_sum, area_sum;
    for (int i = 0; i < num; i++){
        char name[10];
        scanf("%s", name);
        if (strcmp(name, "C") == 0){
            circle_t c;
            scanf("%lf", &c.radius);
            c.perimeter = circle_perimeter;
            c.area = circle_area;
            printf("%.2f ", c.perimeter(&c));
            printf("%.2f\n", c.area(&c));
            perimeter_sum += c.perimeter(&c);
            area_sum += c.area(&c);
        }else if(strcmp(name, "R") == 0){
            rectangle_t r;
            scanf("%lf", &r.length);
            scanf("%lf", &r.weight);
            r.perimeter = retangle_perimeter;
            r.area = retangle_area;
            printf("%.2f ", r.perimeter(&r));
            printf("%.2f\n", r.area(&r));
            perimeter_sum += r.perimeter(&r);
            area_sum += r.area(&r);
        }else if(strcmp(name, "S") == 0){
            square_t s;
            scanf("%lf", &s.edge);
            s.perimeter = square_perimeter;
            s.area = squre_area;
            printf("%.2f ", s.perimeter(&s));
            printf("%.2f\n", s.area(&s));
            perimeter_sum += s.perimeter(&s);
            area_sum += s.area(&s);
        }else if(strcmp(name, "T") == 0){
            triangle_t t;
            scanf("%lf", &t.edge1);
            scanf("%lf", &t.edge2);
            scanf("%lf", &t.edge3);
            t.perimeter = tranigle_perimeter;
            t.area = tranigle_area;
            printf("%.2f ", t.perimeter(&t));
            printf("%.2f\n", t.area(&t));
            perimeter_sum += t.perimeter(&t);
            area_sum += t.area(&t);
        }
    }
    printf("%.2f ", perimeter_sum);
    printf("%.2f \n", area_sum);
    return 0;

}