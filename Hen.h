#ifndef HEN_H
#define HEN_H
#include "Chicken.h"

class Hen : public Chicken
{
public:
    explicit Hen(int row);

public slots:
    virtual void motionWings();

};

#endif // HEN_H
