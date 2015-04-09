#ifndef DRAWABLE_H
#define DRAWABLE_H
#include "base.h"

class Drawable
{
public:
	virtual void Draw(FrameBuffer& fb) = 0;
};

#endif