#ifndef STAGE__HH__
#define STAGE__HH__

#include <ft2build.h>
#include FT_FREETYPE_H
class Stage
{
public:
    Stage();
    ~Stage();

    void Display();
    void Reshape(int w, int h);
    void Init();
};


#endif //STAGE__HH__
