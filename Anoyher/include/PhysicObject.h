#ifndef PHYSICOBJECT_H
#define PHYSICOBJECT_H

#define __USE_LARGEFILE64
#include <sys/types.h>
#include <unistd.h>


#include <stdint.h>
#include <cstddef>
#include <math.h>
#include <random>

#define PI 3.14159265

class Position
{
    float x = 0;
    float y = 0;
public:
    Position(float,float);
    Position(const Position&);
    float GetX();
    float GetY();
    void Set(float,float);
    void SetX(float);
    void SetY(float);
    void operator =(const float&);

    float distance(Position);
    float angle(Position);
    Position GMP(float,float);
};

class PhysicShape;

class PhysicObject
{
    public:
        PhysicObject(Position);

        virtual ~PhysicObject();

        void Collide(PhysicObject*);

        bool CollideV2(PhysicObject*);

        bool InArea(Position);

        void ApplyStoredForces();

        void Push(Position);

        Position GetPosition();
        void SetPosition(float,float);

        Position GetClosestEdge(Position,float);

        uint32_t GetMask();
        void SetMask(uint32_t);

        float GetMass();

        PhysicShape * GetShape();

        bool ToClear();

        uint32_t VectorID;
    protected:
        void SetMass(float);
        void SetMaxSpeed(float);

        Position position;

        uint32_t mask;

        PhysicShape * physicshape;

        bool toClear;

        float stopping;

    private:
        Position Force;
        Position AditionalForce;

        float speed;
        float mass;
        float braking;
};

class PhysicShape
{
protected:
    int32_t shape;
public:
    virtual ~PhysicShape();
    virtual void Collide(PhysicObject*,Position)=0;
    virtual bool CollideV2(PhysicObject*,Position)=0;
    virtual bool InArea(Position,Position)=0;
    virtual Position GetSize()=0;
    virtual int32_t GetShape();
    virtual Position GetClosestEdge(Position,Position,float);
};

class CollideAll:public PhysicShape
{
public:
    CollideAll();
    ~CollideAll();

    virtual void Collide(PhysicObject*,Position);
    virtual bool CollideV2(PhysicObject*,Position);
    virtual bool InArea(Position,Position);

    Position GetSize();
private:

};

class Circle:public PhysicShape
{
    public:
        Circle();
        Circle(float);
        virtual ~Circle();

        virtual void Collide(PhysicObject*,Position);
        virtual bool CollideV2(PhysicObject*,Position);
        virtual bool InArea(Position,Position);
        virtual Position GetClosestEdge(Position,Position,float);

        void SetRadius(float);
        Position GetSize();

    protected:
    private:
    float radius;

    Position CollideCircle(Circle*,Position,Position);
    bool CollideCircleV2(Circle*,Position,Position);
    bool CollideAllV2(CollideAll*,Position,Position);
};

class NRR:public PhysicShape
{
    public:
        NRR();
        NRR(Position);
        virtual ~NRR();

        virtual void Collide(PhysicObject*,Position);
        virtual bool CollideV2(PhysicObject*,Position);
        virtual bool InArea(Position,Position);

        void SetSize(Position);
        Position GetSize();

    protected:
    private:
    Position dimensions;

    Position CollideCircle(Circle*,Position,Position);
    bool CollideCircleV2(Circle*,Position,Position);
};

#endif // PHYSICOBJECT_H
