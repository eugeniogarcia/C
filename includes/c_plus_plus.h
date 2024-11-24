#define LEN 45
class ClaseBase
{
protected:
    float numero;
    char donde[LEN];
    char nombre[LEN];

public:
    ClaseBase(const char *valor, float num);
    void donde_estoy(char *);
    virtual char *quien()=0;
    virtual float matematica() = 0;
    char alias[LEN];
};

class A : public ClaseBase
{
public:
    A(const char *valor, float num);
    char *quien();
    virtual float matematica();
};

class B : public A
{
public:
    B(const char *nombre, float num);
    float matematica();
};

class C : public B
{
public:
    C(const char *nombre, long num);
    float matematica();
    void donde_estoy(char *);
};

float calcula(ClaseBase *objeto);
void donde(ClaseBase *objeto, char *);
char *quien(ClaseBase *objeto);