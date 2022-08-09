#include <stdio.h>
#include <math.h>
#define f float
#define o void
#define n return
#define k for
#define Q(a) ((a) * (a))
#define E(a, b) (((a) / ((f)(b))) * 2 - 1)
#define I(a, b) ((a < b) ? (a) : (b))
#define P(a, b, c) I(c, (a > b) ? (a) : (b))
typedef struct
{
    f x, y, z;
} V;

o A(V *d, V v)
{
    d->x += v.x;
    d->y += v.y;
    d->z += v.z;
}
o S(V *d, V v)
{
    d->x -= v.x;
    d->y -= v.y;
    d->z -= v.z;
}
o M(V *d, f s)
{
    d->x *= s;
    d->y *= s;
    d->z *= s;
}

f D(V a, V b)
{
    n (a.x * b.x) + (a.y * b.y) + (a.z * b.z);
}
f L(V v)
{
    n sqrt(Q(v.x) + Q(v.y) + Q(v.z));
}

o N(V *v)
{
    f l = 1.0 / L(*v);
    M(v, l);
}
o T(V *d, f x, f y, f z)
{
    d->x = x;
    d->y = y;
    d->z = z;
}
o C(V *d, V v)
{
    T(d, v.x, v.y, v.z);
}

main()
{
    int w = 128;
    int h = 64;

    char *i = " .:-=+*#%@";

    int x, y, z;
    f t;
    V a;
    V d;
    V c;
    V p = {0, 0, 3};
    V u = {-1, 1, -1};
    N(&u);
    f r;
    char b;
    k (y = 0; y < h; y++)
    {
        k (x = 0; x < w; x++)
        {
            b = i[0];
            T(&a, 0, 0, 0);
            T(&d, E(x, w), -E(y, h), 1);
            r = 1.0;
            k (z = 0; z < 100; z++)
            {
                C(&c, a);
                S(&c, p);

                t = I(a.y + 1, L(c) - 1);
                if (t < 0.1)
                {
                    if (a.y < -0.9)
                    {
                        d.y *= -1;
                        r = 0.75;
                    }
                    else
                    {
                        C(&c, a);
                        S(&c, p);
                        N(&c);
                        b = i[(int)(P((r * (D(c, u) + 1) * 0.5), 0.0, 1.0) * 10)];
                        break;
                    }
                }
                N(&d);
                M(&d, t);
                A(&a, d);
            }
            putchar(b);
        }
        putchar(10);
    }
}