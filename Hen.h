#ifndef HEN_H
#define HEN_H
#include "Chicken.h"

class Hen : public Chicken
{
public:
    explicit Hen(int row);

public slots:
    virtual void motionWings();
    virtual void moveDown();

};

#endif // HEN_H
