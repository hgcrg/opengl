#ifndef STAGE__HH__
#define STAGE__HH__
#include <GL/glew.h>
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

    GLuint m_tex;
};


#endif //STAGE__HH__
