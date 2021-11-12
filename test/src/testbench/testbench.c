/*
 * gcc -pg testbench.c -o testbench
 * ./testbench
 * gprof testbench gmon.out > testbench_analysis

 * arrays_in_structure
  %   cumulative   self              self     total
 time   seconds   seconds    calls  ms/call  ms/call  name
 61.90      0.37     0.37      100     3.71     3.71  access_from_two_objects_in_arrays_in_structre
 23.42      0.51     0.14      100     1.41     1.41  access_arrays_in_structre_by_value
 10.04      0.57     0.06      100     0.60     0.60  access_arrays_in_structre_object
  1.67      0.58     0.01      200     0.05     0.05  init_arrays_in_structure_by_object
  0.00      0.58     0.00      100     0.00     0.00  init_arrays_in_structure_by_value
  0.00      0.58     0.00        2     0.00     0.00  create_arrays_in_structure
  0.00      0.58     0.00        2     0.00     0.00  destroy_array_in_structure
  0.00      0.58     0.00        1     0.00   582.18  arrays_in_structure

 * array_of_structures
  %   cumulative   self              self     total
 time   seconds   seconds    calls  ms/call  ms/call  name
 62.74      0.30     0.30      100     3.01     3.01  access_from_two_objects_in_arrays_of_structres
 29.28      0.44     0.14      100     1.41     1.41  access_array_of_structures_by_value
  6.27      0.47     0.03      100     0.30     0.30  access_array_of_structures_object
  2.09      0.48     0.01      100     0.10     0.10  init_array_of_structures_by_value
  0.00      0.48     0.00      200     0.00     0.00  init_array_of_structures_by_objects
  0.00      0.48     0.00        2     0.00     0.00  create_array_of_structures
  0.00      0.48     0.00        2     0.00     0.00  destroy_array_of_structures
  0.00      0.48     0.00        1     0.00   481.81  array_of_structures
 */

#include <stdio.h>
#include <stdlib.h>


#define AMNT 10000
#define AMNT2 10
#define cycles 100


// structures in an array
typedef struct {
    int i;
    float f;
    double d;
} Enemy;


typedef struct {
    int n;
    Enemy* obj;
} Enemies;


Enemy* create_array_of_structures (int nobj)
{
    Enemy* obj = (Enemy*) malloc (sizeof(Enemy) * nobj);

    return obj;
}


void init_array_of_structures_by_value (Enemies *obj)
{
    int i = 0;
    float f = 0;
    double d = 0;

    while (i < obj->n)
    {
        obj->obj[i].i = i;
        i++;
    }

    i = 0;

    while (i < obj->n)
    {
        obj->obj[i].f = f;
        f += .01;
        i++;
    }

    i = 0;

    while (i < obj->n)
    {
        obj->obj[i].d = d;
        d += .0001;
        i++;
    }
}

void init_array_of_structures_by_objects (Enemies *obj)
{
    int i = 0;
    float f = 0;
    double d = 0;

    while (i < obj->n)
    {
        obj->obj[i].i = i;
        obj->obj[i].f = f;
        obj->obj[i].d = d;

        f += .01;
        d += .0001;
        i++;
    }
}


void access_array_of_structures_object (Enemies* obj)
{
    int i = 0;

    while (i < obj->n)
    {
        printf ("%10d, %10f, %10f\n", obj->obj[i].i, obj->obj[i].f, obj->obj[i].d);
        i++;
    }

}


void access_array_of_structures_by_value (Enemies* obj)
{
    int i = 0;

    while (i < obj->n)
    {
        printf ("%10d\n", obj->obj[i].i);
        i++;
    }

    i = 0;

    while (i < obj->n)
    {
        printf ("%10f\n", obj->obj[i].f);
        i++;
    }

    i = 0;

    while (i < obj->n)
    {
        printf ("%10f\n", obj->obj[i].d);
        i++;
    }
}


void access_from_two_objects_in_arrays_of_structres (Enemies* obj, Enemies* obj2)
{
    /* register int n = obj->n; ----> low speed
     * const Enemy* ob = obj->obj; ----> low speed
     */


    for (int i = 0; i < obj->n; i++)
    {
        for (int j = 0; j < obj2->n; j++)
        {
            printf ("%d %d\n", obj->obj[i].i, obj2->obj[j].i);
        }
    }
}


void destroy_array_of_structures (Enemies *obj)
{
    free (obj->obj);
    free (obj);
}


void array_of_structures ()
{
    int i = 0;

    Enemies* enemy = (Enemies*) malloc (sizeof(Enemies));
    Enemies* enemy2 = (Enemies*) malloc (sizeof(Enemies));

    enemy->n = AMNT;
    enemy->obj = create_array_of_structures (enemy->n);

    enemy2->n = AMNT2;
    enemy2->obj = create_array_of_structures (enemy2->n);

    while (i < cycles)
    {
        init_array_of_structures_by_value (enemy);
        init_array_of_structures_by_objects (enemy);
        init_array_of_structures_by_objects (enemy2);

        access_array_of_structures_object (enemy);
        access_array_of_structures_by_value (enemy);
        access_from_two_objects_in_arrays_of_structres (enemy, enemy2);

        i++;
    }

    destroy_array_of_structures (enemy);
    destroy_array_of_structures (enemy2);
}


/**************Arrays_in_structure*********************/
typedef struct {
    int     n;
    int*    i;
    float*  f;
    double* d;
} arraystruct;


arraystruct* create_arrays_in_structure (int nobj)
{
    arraystruct* obj = (arraystruct*) malloc (sizeof(arraystruct));
    obj->n = nobj;
    obj->i = (int*) malloc (sizeof(int) * nobj);
    obj->f = (float*) malloc (sizeof(float) * nobj);
    obj->d = (double*) malloc (sizeof(double) * nobj);

    return obj;
}


void init_arrays_in_structure_by_value (arraystruct* obj)
{
    int i = 0;
    float f = 0;
    double d = 0;

    while (i < obj->n)
    {
        obj->i[i] = i;
        i++;
    }

    i = 0;

    while (i < obj->n)
    {
        obj->f[i] = f;
        f += .01;
        i++;
    }

    i = 0;

    while (i < obj->n)
    {
        obj->d[i] = d;
        d += .0001;
        i++;
    }
}


void init_arrays_in_structure_by_object (arraystruct* obj)
{
    int i = 0;
    float f = 0;
    double d = 0;

    while (i < obj->n)
    {
        obj->i[i] = i;
        obj->f[i] = f;
        obj->d[i] = d;

        f += .01;
        d += .0001;
        i++;
    }
}


void access_arrays_in_structre_object (arraystruct* obj)
{
    int i = 0;

    while (i < obj->n)
    {
        printf ("%10d, %10f, %10f\n", obj->i[i], obj->f[i], obj->d[i]);
        i++;
    }
}


void access_arrays_in_structre_by_value (arraystruct* obj)
{
    int i = 0;

    while (i < obj->n)
    {
        printf ("%10d\n", obj->i[i]);
        i++;
    }

    i = 0;

    while (i < obj->n)
    {
        printf ("%10f\n", obj->f[i]);
        i++;
    }

    i = 0;

    while (i < obj->n)
    {
        printf ("%10f\n", obj->d[i]);
        i++;
    }
}


void access_from_two_objects_in_arrays_in_structre (arraystruct* obj, arraystruct* obj2)
{
    /*register int n = obj->n; slow
     *
     */

    for (int i = 0; i < obj->n; i++)
    {
        for (int j = 0; j < obj2->n; j++)
        {
            printf ("%d %d\n", obj->i[i], obj2->i[j]);
        }
    }
}


void destroy_array_in_structure (arraystruct* obj)
{
    free (obj->i);
    free (obj->f);
    free (obj->d);
    free (obj);
}


void arrays_in_structure ()
{
    int i = 0;

    arraystruct* obj = create_arrays_in_structure (AMNT);
    arraystruct* obj2 = create_arrays_in_structure (AMNT2);

    while (i < cycles)
    {
        init_arrays_in_structure_by_value (obj);
        init_arrays_in_structure_by_object (obj);
        init_arrays_in_structure_by_object (obj2);

        access_arrays_in_structre_object (obj);
        access_arrays_in_structre_by_value (obj);
        access_from_two_objects_in_arrays_in_structre (obj, obj2);

        i++;
    }

    destroy_array_in_structure (obj);
    destroy_array_in_structure (obj2);
}


int main()
{
    array_of_structures ();
    //arrays_in_structure ();

    return 0;
}
