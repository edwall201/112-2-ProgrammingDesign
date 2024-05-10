#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
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
    shape_t *shapes[num];

    for (int i = 0; i < num; i++){
        char name[10];
        scanf("%s", name);
        shapes[i] = CreateShape(name);
        if(shapes[i])
        {
            if(strcmp(name, "C") == 0 )
            {
                circle_t *c = (circle_t*)shapes[i];
                scanf("%lf", &c->radius);
            }else if(strcmp(name, "R") == 0)
            {
                rectangle_t *r = (rectangle_t*)shapes[i];
                scanf("%lf %lf", &r->length, &r->weight);
            }else if(strcmp(name, "S") == 0)
            {
                square_t *s = (square_t*)shapes[i];
                scanf("%lf", &s->edge); 
            }else if(strcmp(name, "T") == 0)
            {
                triangle_t *t = (triangle_t*)shapes[i];
                scanf("%lf %lf %lf", &t->edge1, &t->edge2, &t->edge3);
            }
            
        }
        printf("%.2f %.2f\n", shapes[i]->perimeter(shapes[i]), shapes[i]->area(shapes[i]));
        perimeter_sum += shapes[i]->perimeter(shapes[i]);
        area_sum += shapes[i]->area(shapes[i]);
        
    }
    printf("%.2f ", perimeter_sum);
    printf("%.2f \n",area_sum);
    return 0;

}